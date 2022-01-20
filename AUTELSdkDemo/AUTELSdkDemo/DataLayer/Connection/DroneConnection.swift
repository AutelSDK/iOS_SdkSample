//
//  DroneConnection.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/12.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

class DroneConnection: NSObject, AUTELDeviceDelegate {
    
    static let shared = DroneConnection()

    var currentDeviceSNNeedBind = false //缓存上次序列好查询的结果，因为连续查两次会失败
    
    /// 序列号
    var currentDeviceSN: String? {
        didSet {
            currentDeviceSNNeedBind = false
        }
    }
    
    var firmwareInfo:String = ""//存储固件版本信息字符串
    private var bindInfoRqIndex: Int = 0 //无效？
    private var currentDevice: AUTELDevice?
    
    private(set) var connectedDrone: AUTELDrone?
    
    var drone: AUTELDrone? {
        get {
            return currentDevice as? AUTELDrone
        }
    }
    
    private var queue: DispatchQueue = DispatchQueue(label: "com.autel.gen2.connection")
    
    private var protocols: [String: DroneProtocol] = [:]
    
    
    /// 私有初始化方法，防止外部调用
    private override init() {
        super.init()
    }
    
    /// 设置代理，强引用
    ///
    /// - Parameters:
    ///   - aProtocol: 实现DroneProtocol的对象
    ///   - key: 键值，默认为调用者文件名称
    func addProtocol(_ aProtocol: DroneProtocol, with key: String = #file) -> Void {
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
    
    func connect(_ device: AUTELDevice?) -> Void {
        if currentDevice == nil {
            currentDevice = device
            currentDevice?.delegate = self
        } else if currentDevice?.deviceType() == device?.deviceType() {
            
        } else {
            currentDevice?.delegate = nil
            currentDevice = nil
            currentDevice = device
            currentDevice?.delegate = self
        }
    }
    
    // MARK: - Internal Methods
    fileprivate func getDroneBindInfo() {
        guard let _ = currentDevice else { return }
        (currentDevice as? AUTELDrone)?.mainController.getDronBindInfo(completion: {[weak self] (bindState, sn, error) in
            guard let strongSelf = self else { return }
            if let _ = error {
                DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + 1.0, execute: {[weak strongSelf] in
                    guard let strongerSelf = strongSelf else { return }
                    strongerSelf.bindInfoRqIndex += 1
                    if strongerSelf.bindInfoRqIndex < 3 {
                        strongerSelf.getDroneBindInfo()
                    } else {
                        strongerSelf.bindInfoRqIndex = 0
                    }
                   
                })
            } else {
                strongSelf.bindInfoRqIndex = 0
                strongSelf.currentDeviceSN = sn
//                currentDeviceSerinum = sn
            }
        })
    }
    
    // MARK: - AUTELDeviceDelegate
    
    func device(_ device: AUTELDevice!, didConnectionStatusChanged status: AUTELDeviceConnectionStatus) {
        guard let drone = device as? AUTELDrone else {
            self.connectedDrone = nil
            return
        }
        CameraConnection.shared.connect(drone.camera)
        GimbalConnection.shared.connect(drone.gimbal)
        BatteryConnection.shared.connect(drone.battery)
        MainControllerConnection.shared.connect(drone.mainController)
        RemoteControllerConnection.shared.connect(drone.remoteController)
        AirLinkConnection.shared.connect(drone.airLink)
        AUTELNavigationDelegateConnection.shared.connect(drone.mainController.navigationManager)
        
        if status == .ConnectionSucceeded   {
            FlightAssistantConnection.shared.connect(drone.mainController.flightAssistant)
            
            print( "\ndrone connected");
            MainControllerConnection.shared.connectActionFlag = true
            
            connect(device)
        } else {
            FlightAssistantConnection.shared.disConnect()
        }
        
        if status == .ConnectionSucceeded {
            self.connectedDrone = drone
        } else {
            self.connectedDrone = nil
        }
        
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
//                guard aProtocol.isLoaded else { continue }
                aProtocol.device(device, didConnectionStatusChanged: status)
            }
        }

        
    }
}


extension DroneConnection {
    func isConnected() -> Bool {
        if DroneConnection.shared.drone == nil
            || DroneConnection.shared.drone?.isConnected() == false {
            return false
        }
        
        return true
    }

}
