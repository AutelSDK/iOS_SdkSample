//
//  AUTELNavigationDelegateConnection.swift
//  AUTELSdkDemo
//
//  Created by autel on 2018/3/31.
//  Copyright © 2018年 AUTEL. All rights reserved.
//

import UIKit
import AUTELSDK

class AUTELNavigationDelegateConnection: NSObject,AUTELNavigationDelegate {
    static let shared = AUTELNavigationDelegateConnection()
    private var missionProgressStatus: AUTELMissionProgressStatus?
    private var continueFlyInfo: AUTELMCWaypointMission?
    
    
    private var queue: DispatchQueue = DispatchQueue(label: "com.autel.gen2.connection")
    private var protocols: [String: AUTELNavigationDelegate] = [:]
    
    
    /// 设置代理，强引用
    ///
    /// - Parameters:
    ///   - aProtocol: 实现AUTELNavigationDelegate的对象
    ///   - key: 键值，默认为调用者文件名称
    func addProtocol(_ aProtocol: AUTELNavigationDelegate, with key: String = #file) -> Void {
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
    
    func connect(_ navMan: AUTELNavigation?) -> Void {
        navMan?.delegate = self
    }
    
    //MARK:回调
    func onNavigationMissionStatusChanged(_ missionStatus: AUTELMissionProgressStatus) {
        
        missionProgressStatus = missionStatus
        
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.onNavigationMissionStatusChanged(missionStatus)
            }
  
        }
    }
    
    //MARK:推送任务执行状态信息
    func onMissionCurrentStatusUpdateNote(_ missionStatus: AUTELWaypointMissionStatus) {
        queue.async {
            for (_, aProtocol) in self.protocols {
                if let block = aProtocol.onMissionCurrentStatusUpdateNote {
                    block(missionStatus)
                }
            }
            
        }
    }
    
    //MARK:推送当前被中断的任务信从息
    func onMissionBreakPointContinueFlyInfoNote(_ continueFlyInfo: AUTELMCWaypointMission) {
        self.continueFlyInfo = continueFlyInfo
        queue.async {
            for (_, aProtocol) in self.protocols {
                if let block = aProtocol.onMissionBreakPointContinueFlyInfoNote {
                    block(continueFlyInfo)
                }
            }
            
        }
    }
    
    
    // MARK: - 工具方法
    
    func isInMisstionFlyStatus() -> Bool {
        if let runingMissionType = DroneConnection.shared.drone?.mainController.navigationManager.runningMissionType {
            if runingMissionType == .waypoint {
                return true
            }
        }
        
        return false
    }
    
    func isInTripodMisstion() -> Bool {
        if let runingMissionType = DroneConnection.shared.drone?.mainController.navigationManager.runningMissionType {
            if runingMissionType == .tripod {
                return true
            }
        }
        
        return false
    }
}
