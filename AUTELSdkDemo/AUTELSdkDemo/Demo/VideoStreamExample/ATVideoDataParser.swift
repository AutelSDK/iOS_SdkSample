//
//  VideoDataParser.swift
//  AutelGen2
//
//  Created by IOS on 2017/10/8.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

let ATVideoStream_StartCode: [UInt8] = [0, 0, 0, 1]

struct ATVideoDataParser {
    private var videoPacket : AUTELVideoDataPacket
    private var cursor : UnsafeMutablePointer<UInt8>?
    private var bufferSize = 0
    
    init(VideoPacket videoPacket:AUTELVideoDataPacket) {
        self.videoPacket = videoPacket
        self.cursor = videoPacket.data;
        self.bufferSize = videoPacket.size
    }
    
    mutating func nextPacket() -> AUTELVideoDataPacket? {
        guard let tempCursor = self.cursor, self.bufferSize > 0 && memcmp(tempCursor, ATVideoStream_StartCode, 4) == 0 else {
            return nil
        }
        
        var vp : AUTELVideoDataPacket?
        if self.bufferSize >= 5 {
            var bufferBegin = tempCursor + 4
            let bufferEnd = tempCursor + self.bufferSize
            while bufferBegin != bufferEnd {
                if bufferBegin.pointee == 0x01 {
                    if 0 == memcmp(bufferBegin - 3, ATVideoStream_StartCode, 4) {
                        let packetSize = bufferBegin - tempCursor - 3
                        vp = AUTELVideoDataPacket(data: tempCursor,
                                                  withSize: packetSize,
                                                  withPts: videoPacket.pts)
                        
                        self.cursor = tempCursor + packetSize
                        self.bufferSize = self.bufferSize - packetSize
                        return vp
                    }
                }
                bufferBegin = bufferBegin + 1
            }
        }
        
        if self.bufferSize > 0 {
            vp = AUTELVideoDataPacket(data: tempCursor,
                                      withSize: self.bufferSize,
                                      withPts: videoPacket.pts)
            self.bufferSize = 0
            return vp
        }
        return vp
    }
}
