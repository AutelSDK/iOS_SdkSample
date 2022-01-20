//
//  AirLinkProtocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/11/25.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

protocol AirLinkProtocol: CheckProtocol {
    
    func linkGen2(_ link: AUTELLinkGen2!, updataLinkState linkState: AUTELLinkGen2State!) -> Void
}

extension AirLinkProtocol {
    func linkGen2(_ link: AUTELLinkGen2!, updataLinkState linkState: AUTELLinkGen2State!) -> Void {
        
    }
}
