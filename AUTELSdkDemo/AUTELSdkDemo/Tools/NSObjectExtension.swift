//
//  NSObjectExtension.swift
//  AutelGen2
//
//  Created by Devin on 2017/9/5.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation

extension NSObject {
    static var identifier: String {
        get {
            return String(describing: self)
        }
    }
    
    var classIdentifier: String {
        get {
            return String(describing: type(of: self))
        }
    }
    
}
