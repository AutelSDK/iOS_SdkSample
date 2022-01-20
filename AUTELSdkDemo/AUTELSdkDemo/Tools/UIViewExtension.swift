//
//  UIViewExtension.swift
//  AutelGen2
//
//  Created by Devin on 2017/9/8.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import UIKit

extension UIView {
    
    var x: CGFloat {
        get {
            return origin.x
        }
        set {
            origin = CGPoint(x: newValue, y: y)
        }
    }
    
    var y: CGFloat {
        get {
            return origin.y
        }
        set {
            origin = CGPoint(x: x, y: newValue)
        }
    }
    
    var origin: CGPoint {
        get {
            return frame.origin
        }
        set {
            frame = CGRect(origin: newValue, size: size)
        }
    }
    
    @objc var width: CGFloat {
        get {
            return size.width
        }
        set {
            size = CGSize(width: newValue, height: height)
        }
    }
    
    @objc var height: CGFloat {
        get {
            return size.height
        }
        set {
            size = CGSize(width: width, height: newValue)
        }
    }
    
    var size: CGSize {
        get {
            return frame.size
        }
        set {
            frame = CGRect(origin: origin, size: newValue)
        }
    }
    
    /// 获取当前View所在的ViewController
    var controller: UIViewController? {
        get {
            var responder: UIResponder? = self.next;
            while responder != nil && !((responder?.isKind(of: UIViewController.self))!) {
                responder = responder?.next
            }
            return responder as? UIViewController
        }
    }
    
    /// 锚点
    var anchorPoint: CGPoint {
        get {
            return layer.anchorPoint
        }
        set {
            let oldOrigin = origin
            layer.anchorPoint = newValue
            let newOrigin = origin
            let transition = CGPoint(x: newOrigin.x - oldOrigin.x, y: newOrigin.y - oldOrigin.y)
            center = CGPoint(x: center.x - transition.x, y: center.y - transition.y)
        }
    }
    
    /// 半透明。当用作setter时，同时会改变视图的可点击状态
    var isTranslucent: Bool {
        get {
            return self.alpha > 0.5
        }
        set {
            UIView.animate(withDuration: 0.25, animations: {
                self.alpha = newValue ? 0.4 : 1.0
            }) { (finished) in
                if finished {
                    self.isUserInteractionEnabled = !newValue
                }
            }
        }
    }
    
}

/// 修正圆角定制
extension UIView {
    
    func roundCorners(corners: UIRectCorner, radius: CGFloat) {
        let path = UIBezierPath(roundedRect: bounds, byRoundingCorners: corners, cornerRadii: CGSize(width: radius, height: radius))
        let mask = CAShapeLayer()
        mask.path = path.cgPath
        layer.mask = mask
    }
    
    // 判断自己能否接收事件
    
    func shouldHandleEvens() -> Bool {
        return !(self.isUserInteractionEnabled == false || self.isHidden == true || self.alpha <= 0.01)
    }
}
