//
//  MainControllerProtocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/14.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

protocol MainControllerProtocol: CheckProtocol {
    
    func mainController(_ mc: AUTELDroneMainController!, didUpdate state: AUTELMCSystemState!) -> Void
}

extension MainControllerProtocol {
    func mainController(_ mc: AUTELDroneMainController!, didUpdate state: AUTELMCSystemState!) -> Void {
        
    }
}
