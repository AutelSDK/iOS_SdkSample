//
//  VideoStreamCommon.swift
//  AutelGen2
//
//  Created by IOS on 2017/9/28.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import CoreVideo
import VideoToolbox

var ATVideoStream_s_Pts: Int64 = 0
var ATVideoStream_s_lastCallbackPts: Int64 = -1

class ATVideoFrameYUV {
    var pixelBuffer : CVPixelBuffer? = nil
    var width = 0
    var height = 0
    var pts : Int64 = 0
    
    var createIndex = 0
    static var sIndex = 0
    
    init(PixcelBuffer buffer:CVPixelBuffer, PTS pts:Int64) {
        self.pixelBuffer = buffer
        self.pts = pts
        self.width = CVPixelBufferGetWidth(buffer)
        self.height = CVPixelBufferGetHeight(buffer)
        self.createIndex = ATVideoFrameYUV.sIndex;
        print("VideoFrameYUV init \(self.createIndex)")
    }
    deinit {
        print("VideoFrameYUV dinit \(self.createIndex)")
    }
    
    func aspectRatio() -> CGFloat {
        return CGFloat(width) / CGFloat(height)
    }
}

public struct AutelVideoDecodeInfo {
    var vps: UnsafeMutablePointer<UInt8>?
    var sps: UnsafeMutablePointer<UInt8>?
    // H265有前后两个pps(实际图传只有一个)
    var f_pps: UnsafeMutablePointer<UInt8>?
    var r_pps: UnsafeMutablePointer<UInt8>?
    
    var vps_size: Int = 0
    var sps_size: Int = 0
    var f_pps_size: Int = 0
    var r_pps_size: Int = 0
    
    var vps_length: Int = 2048
    var sps_length: Int = 2048
    var f_pps_length: Int = 2048
    var r_pps_length: Int = 2048
    var last_decode_pts: Float64?
    
    init() {
        self.vps = UnsafeMutablePointer<CUnsignedChar>.allocate(capacity: self.vps_size)
        self.vps!.initialize(to: 0)
        self.sps = UnsafeMutablePointer<CUnsignedChar>.allocate(capacity: self.sps_size)
        self.sps!.initialize(to: 0)
        self.f_pps = UnsafeMutablePointer<CUnsignedChar>.allocate(capacity: self.f_pps_size)
        self.f_pps!.initialize(to: 0)
    }
    
    mutating func clear() {
        sps?.deinitialize(count: sps_size)
        sps?.deallocate()
        sps = nil
        f_pps?.deinitialize(count: f_pps_size)
        f_pps?.deallocate()
        f_pps = nil
        r_pps?.deinitialize(count: r_pps_size)
        r_pps?.deallocate()
        r_pps = nil
        vps?.deinitialize(count: vps_size)
        vps?.deallocate()
        vps = nil
    }
}

func ATDidDecompress(_ outputRefCon: UnsafeMutableRawPointer?
                   , _ sourceRefCon: UnsafeMutableRawPointer?
                   , _ status: OSStatus
                   , _ infoFlags: VTDecodeInfoFlags
                   , _ imageBuffer: CVImageBuffer?
                   , _ timeStamp: CMTime
                   , _ duration: CMTime) {
    
    guard let hardwareDecoder = outputRefCon, let pixcelBuffer = imageBuffer else {
        return
    }
    ATVideoStream_s_lastCallbackPts = ATVideoStream_s_Pts
    let yuv = ATVideoFrameYUV(PixcelBuffer: pixcelBuffer, PTS: ATVideoStream_s_lastCallbackPts)
    print("decode callback pts: \(yuv.pts)")
    
    unsafeBitCast(hardwareDecoder, to: ATVideoStreamHardwareDecoder.self).streamDecodeHandler?.insertFrame(yuv)
}
