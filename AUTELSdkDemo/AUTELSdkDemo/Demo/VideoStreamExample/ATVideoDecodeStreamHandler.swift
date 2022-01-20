//
//  VideoStreamHandler.swift
//  AutelGen2
//
//  Created by IOS on 2017/9/30.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation

protocol ATVideoDecodeStreamHandler {
    func insertFrame(_ frame: ATVideoFrameYUV);
    func decoderDisconnected();
}
