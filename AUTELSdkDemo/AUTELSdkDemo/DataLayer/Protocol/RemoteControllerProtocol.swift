//
//  RemoteControllerProtocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/14.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

protocol RemoteControllerProtocol: CheckProtocol {
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateRCState rcState: AUTELRCState) -> Void
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateConnecteState connected: Bool) -> Void
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateInterconnectionState state: AUTELRCInterconnectionState) -> Void
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateHardwareState hardwareState: AUTELRCHardwareState) -> Void
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateSpecialButtonState specialButtonState: AUTELSpecialButtonState) -> Void
}

extension RemoteControllerProtocol {
    func remoteController(_ rc: AUTELRemoteController!, didUpdateRCState rcState: AUTELRCState) -> Void {
        
    }
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateConnecteState connected: Bool) -> Void {
        
    }
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateInterconnectionState state: AUTELRCInterconnectionState) -> Void {
        
    }
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateHardwareState hardwareState: AUTELRCHardwareState) -> Void {
        
    }
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateSpecialButtonState specialButtonState: AUTELSpecialButtonState) -> Void {
        
    }
}

protocol WheelActionProtocol {
    func wheelDidScrollWithOffset(_ offset: Int8) -> Void
    func wheelDidPress() -> Void
}
