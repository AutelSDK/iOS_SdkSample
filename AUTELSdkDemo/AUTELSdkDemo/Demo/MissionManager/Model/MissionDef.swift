//
//  MissionDef.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet Argo on 2020/5/10.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation


enum MissionType: Int {
    case waypoint         = 1      //航点任务
    case rectangle                 //测绘任务，单矩形
    case doubleRectangle           //测绘任务，双矩形
    case polygon                   //测绘任务，多边形
    case reconnoiter               //侦察任务
    case homePoint                 //返航点，为了航点设置页面显示
    case emergencyLanding          //紧急降落点
    case pointOfInteresting
    case unkown = -1
}

enum MissionActionType: Int {
    case line       = 0             //飞越
    case point                      //悬停
    case orbit                      //兴趣点
    case unkown         = -1
    
    func upperCountLimit() -> Int? {
        switch self {
        case .line: return 1
        case .point: return 10
        case _: return nil
        }
    }
}

enum MappingScale: Int {
    case MAPPING_SCALE_1_500     = 0
    case MAPPING_SCALE_1_1000
    case MAPPING_SCALE_1_2000
    case MAPPING_SCALE_1_5000
    case UNKNOWN                 = -1
}

enum MissionHoverDirection: Int {
    case CLOCKWISE      = 0
    case ANTICLOCKWISE
    case UNKNOWN        = -1
}

enum MissionFinishActionType: Int {
    case GO_HOME        = 0
    case HOVER
    case UNKNOWN        = -1
}

enum CameraAction: Int {
    /// 无
    case none             = 0
    /// 拍照
    case takePhoto
    /// 定时拍照
    case timeTakePhoto
    /// 定距拍照
    case distanceTakePhoto
    /// 录像或开始录像
    case recordVideo
    /// 停止录像
    case stopRecordVideo
    case unkown
}

enum DroneHeadingControl: Int, Equatable{
    case FOLLOW_WAYLINE_DIRECTION = 0    //沿航线方向
    case MANUAL_CONTROL     //手动控制
    case CUSTOM     //自定义
    case combine //当各个航点的类型不一样的时候，航向的方向是COMBINE
    case UNKNOWN = -1
    
    case interestingPoint = 4
    
    var discription: String {
        switch self {
        case .FOLLOW_WAYLINE_DIRECTION:
            return "heading_route"
        case .MANUAL_CONTROL:
            return "heading_free"
        case .CUSTOM:
            return "heading_custon"
        case .combine:
            return "--"
        case .UNKNOWN:
            return "-"
        case .interestingPoint:
            return "poi_title"
        }
    }
    
    static func from(string: String) -> DroneHeadingControl{
        switch string {
        case "heading_route": return .FOLLOW_WAYLINE_DIRECTION
        case "heading_free": return .MANUAL_CONTROL
        case "heading_custon": return .CUSTOM
        case "poi_title": return .interestingPoint
        case "--": return .combine
        default: return .UNKNOWN
        }
    }
}

enum DroneType: Int {
    case modelB            = 0
    case modelC
    case unkown            = -1
}


enum MesuringUnit: String {
    case minute = "min"
    case second = "s"
    case hour = "h"
    case meter = "m"
    case kilometer = "km"
    case feet = "ft"
    case mile = "mile"
    case meterPerSecond = "m/s"
    case kilometerPerHour = "km/h"
    case milePerHour = "mph"
    case centigrade = "°C"
    case fahrenheit = "°F"
    case angle = "°"
    /// 返回是否使用缩写
    ///
    /// - Parameter abbreviation: Bool
    /// - Returns: String
    func use(_ abbreviation: Bool) -> String {
        if abbreviation {
            return self.rawValue
        } else {
            return self.funnSpell
        }
    }
    
   static func getTempUnit() -> MesuringUnit {
        if UserSettings.shared.tempUint == "0" {
            return .centigrade
        } else {
            return .fahrenheit
        }
    }
    
    
    var funnSpell: String {
        switch self {
        case .minute:
            return local(text: "Settings_General_Minute")
        case .second:
            return local(text: "Settings_General_Second")
        case .hour:
            return local(text: "Settings_General_Hour")
        case .meter:
            return local(text: "Settings_General_Meter")
        case .feet:
            return local(text: "Settings_General_Feet")
        case .kilometer:
            return local(text: "Settings_General_Kilometer")
        case .mile:
            return local(text: "Settings_General_Mile")
        default:
            return self.rawValue
        }
    }
}

// 修改任务滑动条参数范围、类型
enum MissionSliderType: Equatable {
    case height,height1,height2, heightForTilt, speedForWP
    var dic: [String: String] {
        switch self {
        case .height, .height1, .height2, .heightForTilt:
            if true {
                return ["minValue": "10", "maxValue": "120", "curValue": "60", "unit": "m"]
            } else {
                //                return ["minValue": "30", "maxValue": "500", "curValue": "60", "unit": "m"]
            }
        case .speedForWP:
            return ["minValue": "1", "maxValue": "10", "curValue": "5", "unit": "m/s"]
        }
    }
}

/**
* WGS84坐标系    地球坐标系，国际通用坐标系
* GCJ02坐标系    火星坐标系，WGS84坐标系加密后的坐标系；Google国内地图、高德、QQ地图 使用
* BD09坐标系    百度坐标系，GCJ02坐标系加密后的坐标系
*/
enum CoordinateType: Int {
    /// 未知
    case unknown = 0
    /// WGS84坐标系    地球坐标系，国际通用坐标系
    case WGS84 = 1
    /// GCJ02坐标系    火星坐标系，WGS84坐标系加密后的坐标系；Google国内地图、高德、QQ地图 使用
    case GCJ02 = 2
    /// BD09坐标系    百度坐标系，GCJ02坐标系加密后的坐标系
    case BD09 = 3
}

enum MenuItemTpye: Equatable {
    case slider(type: MissionSliderType)            // 具体类型看: MissionSliderType
    case action
    case gimbalYaw
    case finishAction
    case coordinate
    case interestList
    case wayPointList
    case mappingSwitch
    case cameraSize
    case cameraFormat
    case longAndLatEditor
    case lostConnectAction
    case altitudePriority
    case headingDirection
}

/// 新增高度优先级设置：每个航点可以设置高度优先级（-1,0,1）。对应的是每个航点的高度优先级属性。WP_Info_strc. AltPrioUsr
enum AltitudePriority: Int {
    case low = -1
    case medium = 0
    case high = 1
    
    var discription: String {
        switch self {
        case .high: return "altitude_priority_high"
        case .low: return "altitude_priority_low"
        case .medium: return "altitude_priority_medium"
        }
    }
    
    static func from(string: String) -> AltitudePriority{
        switch string {
        case "altitude_priority_high": return .high
        case "altitude_priority_low": return .low
        default: return .medium
        }
    }
}

enum MCMissionStatus {
    case createProject
    case createWaypointProject // 航点任务-初始化
    case createRectangleProject
    case createPolygonProject

    case waypointInit //航点任务-航线init - 编辑航线
    case editAirline //all任务-编辑航线
    case mapViewInsertUnable//添加矩形或多边形
    
    case addWaypoint //航点任务-添加航点
    case addFlypoint //航点任务-用飞机当前位置作为航点,飞机在空中才有效
    case editWaypoint //航点任务 - 编辑航点
    case addPointOfInterest //航点任务 - 添加兴趣点
    case editPointOfInterest //航点任务 - 编辑兴趣点
        
    case preview //任务预览,历史任务进入或任务结束后
    
    case recordingMission //录制任务 - 录制中(地图界面UI类似任务预览)
    
    case readyToTakeOff // 任务准备完成（通过检查）即将起飞
    case flying
    case pause
    case missionGoHome //在任务中，未退出任务
    case goHome //退出任务,返航
    case missionFinish //任务结束
    
    // 暂时没有
    case tracking //新增追踪点
    case addPointOfEmergencyLanding //新增紧急降落点
    case editPointOfEmergencyLanding
    case addFastMission //新增快速任务
    case excuteFastMission
    
    case unknown
}
