//
//  MainControllerConnection.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/14.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

class MainControllerConnection: NSObject, AUTELDroneMainControllerDelegate {
    
    static let shared = MainControllerConnection()
    
    var mainCtl: AUTELDroneMainController?
    
    var connectActionFlag = false
    
    
    private var queue: DispatchQueue = DispatchQueue(label: "com.autel.gen2.connection")
    
    private var protocols: [String: MainControllerProtocol] = [:]
    
    var mainController: AUTELDroneMainController? {
        get {
            return mainCtl
        }
    }
    
    /// 私有初始化方法，防止外部调用
    private override init() {
        super.init()
    }
    
    /// 设置代理，强引用
    ///
    /// - Parameters:
    ///   - aProtocol: 实现MainControllerProtocol的对象
    ///   - key: 键值，默认为调用者文件名称
    func addProtocol(_ aProtocol: MainControllerProtocol, with key: String = #file) -> Void {
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
    
    func connect(_ mainController: AUTELDroneMainController?) -> Void {
        //先移除原来的
        mainCtl?.mcDelegate = nil
        mainCtl?.stopUpdateMCSystemState()
        //再更新新的
        mainCtl = mainController
        mainCtl?.mcDelegate = self
        mainCtl?.startUpdateMCSystemState()
    }
    
    // MARK: - AUTELDroneMainControllerDelegate
    
    func mainController(_ mc: AUTELDroneMainController, didUpdateSystemState state: AUTELMCSystemState) {
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.mainController(mc, didUpdate: state)
            }
 
            if self.connectActionFlag {
                self.connectActionFlag = false
                print("\n飞机flightMode is： \(state.flightMode.rawValue)")
                print("飞机GPS信号强度 is： \(state.gpsSignalLevel.rawValue)")
                print("飞机卫星个数 is： \(state.satelliteCount)")
                print("飞机home点坐标 latitude：\(state.homeLocation.latitude)，longitude:\(state.homeLocation.longitude)")
            }
        }
    }
    
    func mainController(_ mc: AUTELDroneMainController, didUpdateRTKState state: AUTELRTKStatusInfoModel) {

    }
    
    func mainController(_ mc: AUTELDroneMainController, didUpdateRTKDiffData data: Data) {

     }
}
