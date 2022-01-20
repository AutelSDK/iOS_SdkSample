//
//  DroneProtocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/12.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

protocol DroneProtocol: CheckProtocol {
    
    func device(_ device: AUTELDevice!, didConnectionStatusChanged status: AUTELDeviceConnectionStatus) -> ()
}

extension DroneProtocol {
    func device(_ device: AUTELDevice!, didConnectionStatusChanged status: AUTELDeviceConnectionStatus) -> () {
        
    }
}
