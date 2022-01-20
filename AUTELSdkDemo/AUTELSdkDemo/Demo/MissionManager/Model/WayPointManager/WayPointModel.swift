//
//  WayPointModel.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/6.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

class WayPointModel: NSObject {
    
    var coordinate: CLLocationCoordinate2D {
        didSet {
            markAnnotation.coordinate = coordinate
        }
    }
    
    var index: Int = 0
    
    var markAnnotation = MissionMarkPointAnnotation()
    
    var isSelected = false
    
    init(_ coordinate: CLLocationCoordinate2D) {
        self.coordinate = coordinate
        super.init()
        
        markAnnotation.coordinate = coordinate
    }
    
    var height: Float = 60 {
        didSet {
            markAnnotation.capValue = height
        }
    }
    var speed: Float = 5.0
    /// 任务动作集合: 航点动作
    var missionActionsPoint = [MissionAction]()
}

/// 相机动作
class MissionAction: NSObject, NSCopying {
    static let droneYawInValidValue:Float = -1.0 // -540.0
    
    func copy(with zone: NSZone? = nil) -> Any {
        let modelCopy = MissionAction()
        modelCopy.droneYaw = droneYaw
        modelCopy.gimbalPitch = gimbalPitch
        modelCopy.cameraActionType = cameraActionType
        modelCopy.cameraInterval = cameraInterval
        modelCopy.cameraZoom = cameraZoom
        modelCopy.actionTimeLen = actionTimeLen
        modelCopy.typeFor = typeFor
        return modelCopy
    }
    /** 偏航角(机头朝向) 0 - 360 */
    @objc dynamic var droneYaw: Float = 180.0
    
    /** 云台俯仰角 */
    @objc dynamic var gimbalPitch: Float = 0
    
    /** 云台横滚角 */
    @objc dynamic var gimbalRoll: Float = 0.0
    
    /** 云台偏航角 */
    @objc dynamic var gimbalYaw: Float = 0.0
    
    /** 相机动作类型 */
    @objc dynamic var cameraActionType: Int = CameraAction.none.rawValue
    
    /** 拍照间隔, 拍照间距 */
    @objc dynamic var cameraInterval: Float = 5.0
    
    /** 相机变焦 可选参数 默认 1 */
    @objc dynamic var cameraZoom: Float = 1
    
    /** 动作时长(拍照时长、录像时长、无效动作时长) */
    @objc dynamic var actionTimeLen: Int = 10
    
    /// 类型 0: line 1: point
    @objc dynamic var typeFor: Int = MissionActionType.line.rawValue
    
    func droneYawIsValid() -> Bool {
        return droneYaw >= 0
    }
    
}

