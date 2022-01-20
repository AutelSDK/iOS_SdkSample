//
//  UIColor+AUTLExtension.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/1.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation

extension UIColor {
    convenience init(fromHex hex: UInt32) {
        self.init(fromHex: hex, alpha: 1.0)
    }
    
    convenience init(fromHex hex: UInt32, alpha: CGFloat) {
        self.init(
            red: CGFloat((hex & 0xFF0000) >> 16) / 255.0 ,
            green: CGFloat((hex & 0xFF00) >> 8) / 255.0,
            blue: CGFloat(hex & 0xFF) / 255.0,
            alpha: alpha
        )
    }
    
    convenience init(hexFromString:String, alpha:CGFloat = 1.0) {
        var cString:String = hexFromString.trimmingCharacters(in: .whitespacesAndNewlines).uppercased()
        var rgbValue:UInt32 = 10066329 //color #999999 if string has wrong format

        if (cString.hasPrefix("#")) {
            cString.remove(at: cString.startIndex)
        }
        if ((cString.count) == 6) {
            Scanner(string: cString).scanHexInt32(&rgbValue)
        }
        self.init(
            red: CGFloat((rgbValue & 0xFF0000) >> 16) / 255.0,
            green: CGFloat((rgbValue & 0x00FF00) >> 8) / 255.0,
            blue: CGFloat(rgbValue & 0x0000FF) / 255.0,
            alpha: alpha
        )
    }
    
}

//
extension UIColor {
    
    class var autelBaseColor: UIColor {
        return UIColor(fromHex: 0x007AFF)
    }
    
    class var autelBackgroundColor: UIColor {
        return UIColor.black.withAlphaComponent(0.85)
    }
    
    class var autelWordColor: UIColor {
        return UIColor(fromHex: 0xffffff, alpha: 0.5)
    }
    
    class var autelTitleColor: UIColor {
        return UIColor(fromHex: 0xffffff, alpha: 0.5)
    }
    
    class var autelMsgColor: UIColor {
        return UIColor(fromHex: 0xffffff, alpha: 0.3)
    }
    
    class var autelSplitColor: UIColor {
        return UIColor(fromHex: 0x292C32)
    }
    
    class var autelCellSelectedColor: UIColor {
        return UIColor(fromHex: 0x292C32)
    }

}

