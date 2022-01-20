//
//  AutelEdgeInsetsLabel.swift
//  AutelGen2
//
//  Created by autel_ivan on 2018/7/18.
//  Copyright © 2018年 AUTEL. All rights reserved.
//

import UIKit

// 可设置内距的UILabel  TimeLPLabel

class AutelEdgeInsetsLabel: UILabel {

    var edgeInset:UIEdgeInsets = UIEdgeInsets.init(top: 0, left: 0, bottom: 0, right: 0)
    
//    override func drawText(in rect: CGRect) {
//        super.drawText(in: UIEdgeInsetsInsetRect(rect, edgeInset))
//    }
    
    override func textRect(forBounds bounds: CGRect, limitedToNumberOfLines numberOfLines: Int) -> CGRect {
        let edge = self.edgeInset
        var rect = super.textRect(forBounds: bounds.inset(by: edge), limitedToNumberOfLines: numberOfLines)

        rect.origin.x    -= edge.left;
        rect.origin.y    -= edge.top;
        rect.size.width  += (edge.left + edge.right);
        rect.size.height += (edge.top + edge.bottom);

        return rect
    }
}

class ATTextField: UITextField {
    var textInsets:UIEdgeInsets?
    
    override func textRect(forBounds bounds: CGRect) -> CGRect {
        if let textInset = textInsets{
            return bounds.inset(by: textInset)
        }
        return bounds
    }
}

class ATLabel: UILabel {
    var textInsets:UIEdgeInsets?
    
    override func textRect(forBounds bounds: CGRect, limitedToNumberOfLines numberOfLines: Int) -> CGRect {
        let rect = super.textRect(forBounds: bounds, limitedToNumberOfLines: numberOfLines)
        if let textInset = textInsets{
                  return rect.inset(by: textInset)
              }
        return rect
    }
}


class ATAutoInsetLabel: UIView {
   
    var textInsets:UIEdgeInsets = UIEdgeInsets.init(top: 0, left: 0, bottom: 0, right: 0) {
        didSet {
            if label.superview != nil {
                label.snp_updateConstraints { (make) in
                    make.edges.equalToSuperview().inset(textInsets)
                }
            }
        }
    }
    
   private(set) var label:UILabel = UILabel.init()
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.addSubview(label)
        
        label.snp_makeConstraints { (make) in
            make.edges.equalToSuperview().inset(textInsets)
        }
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
}
