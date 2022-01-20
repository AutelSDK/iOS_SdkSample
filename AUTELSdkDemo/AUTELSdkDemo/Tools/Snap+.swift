//
//  Snp+.swift
//  AutelGen2
//
//  Created by Autel-iOS on 2019/4/19.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import Foundation
import SnapKit

extension UIView {
    var snpSafeAreaLeft: ConstraintItem {
        get {
            if #available(iOS 11.0, *) {
                return safeAreaLayoutGuide.snp.left
            } else {
                return snp.left
            }
        }
    }
    
    var snpSafeAreaRight: ConstraintItem {
        get {
            if #available(iOS 11.0, *) {
                return safeAreaLayoutGuide.snp.right
            } else {
                return snp.right
            }
        }
    }
    
    var snpSafeAreaTop: ConstraintItem {
        get {
            if #available(iOS 11.0, *) {
                return safeAreaLayoutGuide.snp.top
            } else {
                return snp.top
            }
        }
    }
    
    var snpSafeAreaBottom: ConstraintItem {
        get {
            if #available(iOS 11.0, *) {
                return safeAreaLayoutGuide.snp.bottom
            } else {
                return snp.bottom
            }
        }
    }
}
