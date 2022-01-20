//
//  RemoteControllerConnection.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/14.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

class RemoteControllerConnection: NSObject, AUTELRemoteControllerDelegate {

    static let shared = RemoteControllerConnection()
    
    private var RC: AUTELRemoteController?
    
    
    private var queue: DispatchQueue = DispatchQueue(label: "com.autel.gen2.connection")
    
    private var protocols: [String: RemoteControllerProtocol] = [:]
    
    var remoteController: AUTELRemoteController? {
        get {
            return RC
        }
    }
    

    
    /// 私有初始化方法，防止外部调用
    private override init() {
        super.init()
    }
    
    /// 设置代理，强引用
    ///
    /// - Parameters:
    ///   - aProtocol: 实现RemoteControllerProtocol的对象
    ///   - key: 键值，默认为调用者文件名称
    func addProtocol(_ aProtocol: RemoteControllerProtocol, with key: String = #file) -> Void {
        queue.async {
            guard let file = (key as NSString).lastPathComponent.components(separatedBy: ".").first else { return }
            self.protocols[file] = aProtocol
        }
    }
    
    /// 根据键值删除协议，不要在dinit中调用该方法，原因是这里面是强引用，dinit方法根本不会走
    ///
    /// - Parameter key: 键值，默认为调用者文件名称
    func removeProtocol(with key: String = #file) -> Void {
        queue.async {
            guard let file = (key as NSString).lastPathComponent.components(separatedBy: ".").first else { return }
            self.protocols[file] = nil
        }
    }
    
    func connect(_ remoteController: AUTELRemoteController?) -> Void {
        //不用判空，每次都更新，fix MOD-3991【V1.3.0】EVO飞机，进入首页指导中心显示：美国手 进入遥控器设置操控模式显示N/A，日本手高亮显示
        RC?.delegate = nil
        RC = remoteController
        RC?.delegate = self

//        let sec = #selector(remotecontr)
    }
    
    // MARK: - AUTELRemoteControllerDelegate
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateRCState rcState: AUTELRCState) {
  
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.remoteController(rc, didUpdateRCState: rcState)
            }
        }
    }
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateConnecteState connected: Bool) {
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.remoteController(rc, didUpdateConnecteState: connected)
            }
        }

        connect(rc)
    }
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateInterconnectionState state: AUTELRCInterconnectionState) {
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.remoteController(rc, didUpdateInterconnectionState: state)
            }
        }
    }
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateHardwareState hardwareState: AUTELRCHardwareState) {
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.remoteController(rc, didUpdateHardwareState: hardwareState)
            }
        }
    }
    
    func remoteController(_ rc: AUTELRemoteController!, didUpdateSpecialButtonState specialButtonState: AUTELSpecialButtonState) {
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.remoteController(rc, didUpdateSpecialButtonState: specialButtonState)
            }
        }
    }
}
