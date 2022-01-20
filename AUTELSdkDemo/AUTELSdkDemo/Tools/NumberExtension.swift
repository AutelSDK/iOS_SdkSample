//
//  FloatingExtension.swift
//  AutelGen2
//
//  Created by Devin on 2017/9/5.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import CoreGraphics

extension Float {
    func format(format: String) -> String {
        return String(format: "%\(format)f", self)
    }
    func formatf(format: String) -> String {
        return String(format: format, self)
    }
}

extension Double {
    func format(format: String) -> String {
        return String(format: "%\(format)f", self)
    }
    func formatf(format: String) -> String {
        return String(format: format, self)
    }
}

extension CGFloat {
    func format(format: String) -> String {
        return String(format: "%\(format)f", self)
    }
    func formatf(format: String) -> String {
          return String(format: format, self)
    }
}

extension Int {
    func format(format: String) -> String {
        return String(format: "%\(format)d", self)
    }
    func formatf(format: String) -> String {
          return String(format: format, self)
    }
}

extension UInt8 {
    func format(format: String) -> String {
        return String(format: "%\(format)d", self)
    }
    func formatf(format: String) -> String {
          return String(format: format, self)
    }
}
