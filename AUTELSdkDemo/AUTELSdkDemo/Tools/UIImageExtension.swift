//
//  UIImageExtension.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/8.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit

extension UIImage {

    //MARK:用颜色生成图片
    static func imageWithUIColor(color:UIColor) -> UIImage {
        let rect = CGRect.init(x: 0, y: 0, width: 1, height: 1)
        UIGraphicsBeginImageContext(rect.size)
        let context = UIGraphicsGetCurrentContext()
        context?.setFillColor(color.cgColor)
        context?.fill(rect)
        let image = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return image!
    }

}
