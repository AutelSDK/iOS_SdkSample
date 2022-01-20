//
//  ATVideoStreamDecoder.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/8/17.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation
import VideoToolbox



class ATVideoStreamHardwareDecoder: NSObject, AUTELVideoFeedListener {
    static var s_lastIDRFrame : AUTELVideoDataPacket?
    
    public var streamDecodeHandler : ATVideoDecodeStreamHandler? = nil
    var decoderSession : VTDecompressionSession? = nil
    var decoderFormatDescription : CMVideoFormatDescription? = nil
    var handleAfterDecodeGCD : DispatchQueue? = nil
    
    /// true: 已经请求了 IDR 帧, 但是还没有收到, false: 其他
    var waitingForIDRFrame = false
    /// 有过解析
    var hadIDRFrame = false
    
    var enableDecoder = false {
        didSet {
            // 当 enableDecoder 的值发送改变时, 将等待 IDR 帧的标志置为 false
            // 让 App 可以请求 IDR 帧
            if oldValue != self.enableDecoder {
                self.waitingForIDRFrame = false
            }
        }
    }
    
    var decodeInfo = AutelVideoDecodeInfo()
    var frameSpsWidth : Int32 = 0
    var frameSpsHeight : Int32 = 0
    
    var decodeFial = 0
    
    // MARK: - Core
    func initDecoder() -> Bool {
        if self.decoderSession != nil {
            return true
        }
        guard let sps = decodeInfo.sps, let f_pps = decodeInfo.f_pps else {
            return false
        }
        
        let parameterSetPointers : [UnsafePointer<CUnsignedChar>] = [UnsafePointer<CUnsignedChar>(sps), UnsafePointer<CUnsignedChar>(f_pps)]
        let parameterSetSize = [decodeInfo.sps_size, decodeInfo.f_pps_size]
        var status: OSStatus =
            withUnsafeMutablePointer(to: &self.decoderFormatDescription) { (ptrDescription) -> OSStatus in
                CMVideoFormatDescriptionCreateFromH264ParameterSets(allocator: kCFAllocatorDefault,
                                                                    parameterSetCount: 2,
                                                                    parameterSetPointers: parameterSetPointers,
                                                                    parameterSetSizes: parameterSetSize,
                                                                    nalUnitHeaderLength: 4,
                                                                    formatDescriptionOut: ptrDescription)
            }
        
        if status == noErr {
            let attrs = NSMutableDictionary()
            attrs.setValue(NSNumber(value: kCVPixelFormatType_420YpCbCr8BiPlanarFullRange), forKey: kCVPixelBufferPixelFormatTypeKey as String)
            
            var callBackRecord = VTDecompressionOutputCallbackRecord()
            callBackRecord.decompressionOutputCallback = ATDidDecompress;
            callBackRecord.decompressionOutputRefCon = UnsafeMutableRawPointer(mutating: Unmanaged.passUnretained(self).toOpaque())
            
            status = withUnsafePointer(to: &callBackRecord, { (ptrCallbackRecord) -> OSStatus in
                return withUnsafeMutablePointer(to: &self.decoderSession, { (ptrSession) -> OSStatus in
                    return VTDecompressionSessionCreate(allocator: kCFAllocatorDefault,
                                                        formatDescription: self.decoderFormatDescription!,
                                                        decoderSpecification: nil,
                                                        imageBufferAttributes: attrs,
                                                        outputCallback: ptrCallbackRecord,
                                                        decompressionSessionOut: ptrSession)
                })
            })
        } else {
            print("IOS8VT: reset decoder session failed status = \(status)")
        }
        return true
    }
    
    func decode(_ packet: AUTELVideoDataPacket, isIDR: Bool = false) -> Bool {
        if self.decoderSession == nil {
            return false
        }
        
        var outputPixelBuffer : CVPixelBuffer? = nil
        var blockBuffer : CMBlockBuffer? = nil
        
        var status = CMBlockBufferCreateWithMemoryBlock(allocator: kCFAllocatorDefault,
                                                        memoryBlock: UnsafeMutableRawPointer(packet.data),
                                                        blockLength: packet.size,
                                                        blockAllocator: kCFAllocatorNull,
                                                        customBlockSource: nil,
                                                        offsetToData: 0,
                                                        dataLength: packet.size,
                                                        flags: 0,
                                                        blockBufferOut: &blockBuffer)
        
        guard status == kCMBlockBufferNoErr else {
            return false
        }
        
        var sampleBuffer : CMSampleBuffer? = nil;
        let sampleSizeArray : [Int] = [packet.size]
        status = CMSampleBufferCreateReady(allocator: kCFAllocatorDefault,
                                           dataBuffer: blockBuffer,
                                           formatDescription: self.decoderFormatDescription,
                                           sampleCount: 1,
                                           sampleTimingEntryCount: 0,
                                           sampleTimingArray: nil,
                                           sampleSizeEntryCount: 1,
                                           sampleSizeArray: sampleSizeArray,
                                           sampleBufferOut: &sampleBuffer)
        guard sampleBuffer != nil else {
            return false
        }
        
        ATVideoStream_s_Pts = packet.pts
        let flags : VTDecodeFrameFlags = VTDecodeFrameFlags(rawValue:0)
        var flagOut : VTDecodeInfoFlags = VTDecodeInfoFlags(rawValue:0)
        let decodeStatus = VTDecompressionSessionDecodeFrame(self.decoderSession!,
                                                             sampleBuffer: sampleBuffer!,
                                                             flags: flags,
                                                             frameRefcon: &outputPixelBuffer,
                                                             infoFlagsOut: &flagOut)
        
        switch decodeStatus {
        case noErr:
            //解码是否成功的标准不是 VTDecompressionSessionDecodeFrame 是否返回成功
            //而是回调方法是否被调用, 如果 didDecompress 没有被调用 s_lastCallbackPts将不被刷新
            #if DEBUG
            guard ATVideoStream_s_Pts == ATVideoStream_s_lastCallbackPts else {
                print("IOSVT: decode failed")
                return false
            }
            return true
            #else
            return (ATVideoStream_s_Pts == ATVideoStream_s_lastCallbackPts)
            #endif
        case kVTInvalidSessionErr:
            self.clearDecoder()
        case kVTVideoDecoderBadDataErr:
            print("OSVT: decode failed status=\(decodeStatus)(Bad data)")
        default:
            print("IOSVT: decode failed status = \(decodeStatus) flagOut = \(flagOut.rawValue) size = \(packet.size) pts = \(packet.pts)")
        }
        return false
    }
    
    func decodeH264Nalu(packet videoPacket: AUTELVideoDataPacket) {
        let nalType = videoPacket.data[4] & 0x1F
        switch nalType {
        case 0x05: // I帧
            print("videoFeed decoder Nal type is IDR frame")
            if self.decodeInfo.sps_size > 0 && self.decodeInfo.f_pps_size > 0 && self.initDecoder() {
                if self.decode(videoPacket, isIDR: true) {
                    ATVideoStreamHardwareDecoder.s_lastIDRFrame = videoPacket
                    self.hadIDRFrame = true
                    print("videoFeed decoder IDR Frame Decode Success")
                }
            }
            self.waitingForIDRFrame = false
        case 0x07: // SPS
            if self.decodeInfo.sps_size == 0 {
                self.decodeInfo.sps_size = videoPacket.size - 4
                memcpy(self.decodeInfo.sps, videoPacket.data + 4, self.decodeInfo.sps_size)
                h264_sps_get_dimension(videoPacket.data, videoPacket.size, &self.frameSpsWidth, &self.frameSpsHeight)
                print("videoFeed decoder SPS frame:(\(self.frameSpsWidth) x \(self.frameSpsHeight)")
            }
            else if (videoPacket.size - 4) != self.decodeInfo.sps_size || 0 != memcmp(self.decodeInfo.sps!, videoPacket.data + 4, self.decodeInfo.sps_size) {
                var iFrameWidth : Int32 = 0
                var iFrameHeight : Int32 = 0
                h264_sps_get_dimension(videoPacket.data, videoPacket.size, &iFrameWidth, &iFrameHeight)
                if self.frameSpsWidth != iFrameWidth || self.frameSpsHeight != iFrameHeight {
                    print("SPS frame change:(\(frameSpsWidth) x \(frameSpsHeight)) to (\(iFrameWidth) x \(iFrameHeight))")
                    self.clearDecoder()
                    ATVideoStreamHardwareDecoder.s_lastIDRFrame = nil
                    self.waitingForIDRFrame = true
                    AUTELAppManager.requestIDRFrame(0)
                    print("videoFeed decoder request IDR 2 SPS frame didChange")
                }
            }
        case 0x08: // PPS
            if self.decodeInfo.f_pps_size == 0 {
                self.decodeInfo.f_pps_size = videoPacket.size - 4
                memcpy(self.decodeInfo.f_pps, videoPacket.data + 4, self.decodeInfo.f_pps_size)
            }
        case 0x06:
            break
        case 0x09:
            break
            
        default: // B帧或P帧
            print("Nal type is \(nalType)")
            if self.decodeInfo.sps_size > 0 && self.decodeInfo.f_pps_size > 0 && self.initDecoder() {
                if !self.decode(videoPacket) { //解码失败
                    self.decodeFial += 1
                    if self.decodeFial >= 30 { //解码失败30
                        self.decodeFial = 0
                        if ATVideoStreamHardwareDecoder.s_lastIDRFrame != nil {
                            print("re-render last IDR frame")
                            _ = self.decode(ATVideoStreamHardwareDecoder.s_lastIDRFrame!)
                            
                            if !self.waitingForIDRFrame {
                                self.waitingForIDRFrame = true
                                AUTELAppManager.requestIDRFrame(0)
                                print("videoFeed decoder request IDR 3 decodeFial30 had_i")
                            }
                        }
                        else {
                            if !self.waitingForIDRFrame {
                                self.waitingForIDRFrame = true
                                AUTELAppManager .requestIDRFrame(0)
                                print("videoFeed decoder request IDR 3 decodeFial30 nil_I")
                            }
                        }
                    }
                }
                else {
                    self.decodeFial = 0
                }
            }
        }
    }
    
    // MARK: - Lift Cycle
    override init() {
        self.handleAfterDecodeGCD = DispatchQueue(label: "HandleAfterDecodeGCD")
    }
    
    deinit {
        self.closeDecoder()
        self.decodeInfo.clear()
    }
    
    func closeDecoder() {
        self.clearDecoder()
        self.waitingForIDRFrame = false
        self.hadIDRFrame = false
    }
    
    func clearDecoder() {
        if self.decoderSession != nil {
            VTDecompressionSessionInvalidate(self.decoderSession!)
            self.decoderSession = nil
        }
        if self.decoderFormatDescription != nil {
            self.decoderFormatDescription = nil
        }
        self.decodeInfo.vps_size = 0
        self.decodeInfo.sps_size = 0
        self.decodeInfo.r_pps_size = 0
        self.decodeInfo.f_pps_size = 0
        self.frameSpsWidth = 0
        self.frameSpsHeight = 0
    }
}

// MARK: - AUTELVideoFeedListener
extension ATVideoStreamHardwareDecoder {
    func videoFeed(_ feed: AUTELVideoFeed!, didUpdateVideoData packet: AUTELVideoDataPacket!) {
        if self.hadIDRFrame == false && !self.waitingForIDRFrame {
            self.waitingForIDRFrame = true
            AUTELAppManager.requestIDRFrame(0)
            print("videoFeed decoder request IDR 1 init")
        }
        
        if  packet.size > 0 && self.enableDecoder {
            var parser = ATVideoDataParser(VideoPacket: packet)
            let nalSize = UnsafeMutableRawPointer.allocate(byteCount: 4, alignment: 1)
            defer {
                nalSize.deallocate()
            }
            
            while let vp = parser.nextPacket() { //解包
                nalSize.storeBytes(of: UInt32(vp.size - 4), as: UInt32.self)
                vp.data[0] = (nalSize + 3).load(as: UInt8.self)
                vp.data[1] = (nalSize + 2).load(as: UInt8.self)
                vp.data[2] = (nalSize + 1).load(as: UInt8.self)
                vp.data[3] = nalSize.load(as: UInt8.self)
                
                decodeH264Nalu(packet: vp)
            }
        }
    }
    
    func videoFeed(_ feed: AUTELVideoFeed!, didUpdateConnecteState state: Bool) {
        self.streamDecodeHandler?.decoderDisconnected()
    }
}
