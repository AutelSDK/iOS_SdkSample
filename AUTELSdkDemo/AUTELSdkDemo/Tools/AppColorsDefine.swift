//
//  AppColorsDefine.swift
//  AutelGen2
//
//  Created by Autel-190215 on 2020/4/14.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation


let SettingsSliderGray = UIColor(fromHex: 0x979797)
let SettingsBlue = UIColor(fromHex: 0x007AFF)  //设置里，segement字颜色

extension UIColor {
    /// 蓝色
    class var mainTintColor : UIColor {
        return UIColor(fromHex: 0x007AFF) //0x0091FF
    }
    
    /// 亮蓝色
    class var lightBlueColor : UIColor {
        return UIColor(fromHex: 0x0091ff)
    }

    class var backgroundColor: UIColor {
        return UIColor.black.withAlphaComponent(0.85)
    }
    
    class var detailViewBackgroundColor: UIColor {
        return UIColor(fromHex: 0x292929)
    }
    
    class var wordColor : UIColor {
        return UIColor.white
    }
    
    class var separatorLineColor: UIColor {
        return UIColor(fromHex: 0x979797, alpha: 0.3)
    }
    class var separatorLineColor2: UIColor {
        return UIColor(fromHex: 0x979797, alpha: 0.8)
    }
}

