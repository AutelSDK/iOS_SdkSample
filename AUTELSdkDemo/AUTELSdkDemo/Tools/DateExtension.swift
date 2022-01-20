//
//  DateExtension.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/6.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

extension Date {
    /// 获取当前 秒级 时间戳 - 10位(秒)
    var timeStamp : String {
        let timeInterval: TimeInterval = self.timeIntervalSince1970
        let timeStamp = Int(timeInterval)
        return "\(timeStamp)"
    }
}

