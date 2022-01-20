//
//  CheckPeotocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2018/3/15.
//  Copyright © 2018年 AUTEL. All rights reserved.
//

import Foundation

protocol CheckProtocol {
    
    /// 是否被加载
    var isLoaded: Bool { get }
}

extension CheckProtocol {
    var isLoaded: Bool {
        get {
            return true
        }
    }
}
