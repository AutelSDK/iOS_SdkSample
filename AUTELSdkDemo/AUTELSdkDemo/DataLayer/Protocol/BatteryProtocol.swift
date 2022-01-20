//
//  BatteryProtocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/14.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

protocol BatteryProtocol: CheckProtocol {
    func battery(_ battery: AUTELBattery!, didUpdataState state: AUTELBatteryState!) -> Void
}

extension BatteryProtocol {
    func battery(_ battery: AUTELBattery!, didUpdataState state: AUTELBatteryState!) -> Void {
        
    }
}
