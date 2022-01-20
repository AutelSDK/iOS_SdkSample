//
//  GimbalProtocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/14.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

protocol GimbalProtocol: CheckProtocol {
    
    func gimbalController(_ controller: AUTELDroneGimbal!, didUpdate gimbalState: AUTELDroneGimbalState!) -> Void
}

extension GimbalProtocol {
    func gimbalController(_ controller: AUTELDroneGimbal!, didUpdate gimbalState: AUTELDroneGimbalState!) -> Void {
        
    }
}
