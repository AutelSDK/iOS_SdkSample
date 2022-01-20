//
//  FlightAssistantConnection.swift
//  AUTELSdkDemo
//
//  Created by autel_ivan on 2018/4/28.
//  Copyright © 2018年 AUTEL. All rights reserved.
//

import UIKit
import AUTELSDK

class FlightAssistantConnection: NSObject,AUTELFlightAssistantDelegate {
    static let shared = FlightAssistantConnection()
    private var queue: DispatchQueue = DispatchQueue(label: "com.autel.gen2.connection")
    private var protocols: [String: FlightAssistantProtocol] = [:]
    
    
    var visionLimitWhenDark = false
    var visualSensorAbnormal = false
    
    
    /// 设置代理，强引用
    ///
    /// - Parameters:
    ///   - aProtocol: 实现AUTELNavigationDelegate的对象
    ///   - key: 键值，默认为调用者文件名称
    func addProtocol(_ aProtocol: FlightAssistantProtocol, with key: String = #file) -> Void {
        queue.async {
            guard let file = (key as NSString).lastPathComponent.components(separatedBy: ".").first else { return }
            self.protocols[file] = aProtocol
        }
    }
    
    /// 根据键值删除协议，不要在dinit中调用该方法，原因是这里面是强引用，dinit方法根本不会走
    /// - Parameter key: 键值，默认为调用者文件名称
    func removeProtocol(with key: String = #file) -> Void {
        queue.async {
            guard let file = (key as NSString).lastPathComponent.components(separatedBy: ".").first else { return }
            self.protocols[file] = nil
        }
    }
    
    func connect(_ navMan: AUTELFlightAssistant?) -> Void {
        navMan?.delegate = self
    }
    
    func disConnect() -> Void {
        visionLimitWhenDark = false
        visualSensorAbnormal = false
  
    }
    

    func flightAssistant(_ assistant: AUTELFlightAssistant, didUpdateVisionDetectionStates states: [AUTELVisionDetectionState]!) {
        
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.flightAssistant(assistant, didUpdateVisionDetectionStates: states)
            }
        }
    }
    
    func flightAssistant(_ assistant: AUTELFlightAssistant, didUpdateVisionControlState state: AUTELVisionControlState!) {
   
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.flightAssistant(assistant, didUpdateVisionControlState: state)

            }
        }
    }
    
    func flightAssistant(_ assistant: AUTELFlightAssistant, didUpdateDetectionObject ObjectInfo:  [AnyHashable: Any]!) {
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.flightAssistant(assistant, didUpdateDetectionObject: ObjectInfo)


            }
        }
    }
}

extension FlightAssistantConnection {

    
}
