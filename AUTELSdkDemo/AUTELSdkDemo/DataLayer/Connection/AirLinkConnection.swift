//
//  AirLinkConnection.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/11/25.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

class AirLinkConnection: NSObject, AUTELLinkGen2Delegate {
    
    static let shared = AirLinkConnection()
    
    private var currentAirlink: AUTELAirLink?
    
    private var queue: DispatchQueue = DispatchQueue(label: "com.autel.gen2.connection")
    
    private var protocols: [String: AirLinkProtocol] = [:]
    
    var airlink: AUTELAirLink? {
        get {
            return currentAirlink
        }
    }
    
    /// 私有初始化方法，防止外部调用
    private override init() {
        super.init()
    }
    
    /// 设置代理，强引用
    ///
    /// - Parameters:
    ///   - aProtocol: 实现AirLinkProtocol的对象
    ///   - key: 键值，默认为调用者文件名称
    func addProtocol(_ aProtocol: AirLinkProtocol, with key: String = #file) -> Void {
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
    
    func connect(_ airlink: AUTELAirLink?) -> Void {
        currentAirlink?.linkGen2?.delegate = nil
        currentAirlink = airlink
        currentAirlink?.linkGen2?.delegate = self
    }
    
    // MARK: - AUTELBatteryDelegate
    
    func linkGen2(_ link: AUTELLinkGen2!, updataLinkState linkState: AUTELLinkGen2State!) {
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.linkGen2(link, updataLinkState: linkState)
            }
        }
    }
    
    
}



extension AirLinkConnection {
    
    func sendVirtualJoystickControlCommand(_ model: AUTELRCVirtualJoystickControlModel, _ complete:((Error?)->Void)?) -> Void {
        self.currentAirlink?.linkGen2?.sendVirtualJoystickControlCommand(model, withCompletion: { (error) in
            DispatchQueue.main.async {
                if error == nil {
                   
                }
                complete?(error)
            }
        })
    }

}
