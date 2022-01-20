//
//  ATVideoStreamManager.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/8/18.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

class ATVideoStreamManager: NSObject {
    static let shared = ATVideoStreamManager()
    
    ///< VideoStreamDeal0 视频流解码+播放
    private var hardwareDecoder : ATVideoStreamHardwareDecoder?
    private var decoderGCD : DispatchQueue = DispatchQueue(label: "ATVideoStream")
    
    
    public func startDecodeVideoStream() {
        hardwareDecoder = ATVideoStreamHardwareDecoder()
        hardwareDecoder?.enableDecoder = true
        AUTELVideoFeed.add(hardwareDecoder, with: self.decoderGCD)
        AUTELVideoFeed.open()
    }
}
