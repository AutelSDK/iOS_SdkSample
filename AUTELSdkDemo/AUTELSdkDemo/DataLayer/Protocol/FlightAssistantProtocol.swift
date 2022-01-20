//
//  FlightAssistantProtocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2018/5/3.
//  Copyright © 2018年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

protocol FlightAssistantProtocol: CheckProtocol {
    
    func flightAssistant(_ assistant: AUTELFlightAssistant!, didUpdateVisionControlState state: AUTELVisionControlState!) -> Void
    
    func flightAssistant(_ assistant: AUTELFlightAssistant!, didUpdateVisionDetectionStates states: [AUTELVisionDetectionState]!) -> Void
    
    func flightAssistant(_ assistant: AUTELFlightAssistant!, didUpdateDetectionObject ObjectInfo: [AnyHashable: Any]!) -> Void
}

extension FlightAssistantProtocol {
    func flightAssistant(_ assistant: AUTELFlightAssistant!, didUpdateVisionControlState state: AUTELVisionControlState!) -> Void {
        
    }
    
    func flightAssistant(_ assistant: AUTELFlightAssistant!, didUpdateVisionDetectionStates states: [AUTELVisionDetectionState]!) -> Void {
        
    }
    
    func flightAssistant(_ assistant: AUTELFlightAssistant!, didUpdateDetectionObject ObjectInfo: [AnyHashable: Any]!) -> Void {
        
    }
}
