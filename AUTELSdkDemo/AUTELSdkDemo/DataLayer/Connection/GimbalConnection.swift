//
//  GimbalConnection.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/14.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

class GimbalConnection: NSObject, AUTELDroneGimbalDelegate {

    static let shared = GimbalConnection()
    
    private var currentGimbal: AUTELDroneGimbal?

    
    private var queue: DispatchQueue = DispatchQueue(label: "com.autel.gen2.connection")
    
    private var protocols: [String: GimbalProtocol] = [:]
    
    var gimbal: AUTELDroneGimbal? {
        get {
            return currentGimbal
        }
    }


    /// 私有初始化方法，防止外部调用
    private override init() {
        super.init()
    }
    
    /// 设置代理，强引用
    ///
    /// - Parameters:
    ///   - aProtocol: 实现GimbalProtocol的对象
    ///   - key: 键值，默认为调用者文件名称
    func addProtocol(_ aProtocol: GimbalProtocol, with key: String = #file) -> Void {
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
    
    func connect(_ gimbal: AUTELDroneGimbal?) -> Void {
        currentGimbal?.delegate = nil
        currentGimbal?.stopUpsataGimbalState()
        currentGimbal = gimbal
        currentGimbal?.delegate = self
        currentGimbal?.startUpdataGimbalState()
    }
    
    // MARK: - AUTELDroneGimbalDelegate
    
    func gimbalController(_ controller: AUTELDroneGimbal, didUpdateGimbalState gimbalState: AUTELDroneGimbalState) {
  
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.gimbalController(controller, didUpdate: gimbalState)
            }
        }
    }
}
