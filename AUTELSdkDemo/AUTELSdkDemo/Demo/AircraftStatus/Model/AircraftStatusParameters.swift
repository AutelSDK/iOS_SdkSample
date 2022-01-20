//
//  AircraftStatusParameters.swift
//  AutelGen2
//
//  Created by a15526 on 2017/10/11.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import UIKit
import AUTELSDK

enum SettingsRCMode: String {
    case mode1
    case mode2
    case mode3
}


class AircraftStatusParameters: NSObject {
    
    // 设备是否断开连接
    var isDeviceConnected = false
    var droneConnectedState: String {
        get {
            if isDeviceConnected {
                return "connected"
            } else {
                return "disconnected"
            }
        }
    }
    
    // 指南针状态 normal : abnormal
    var compassStatus: String = "N/A"
    
    // IMU 状态
    var IMUStatus: String = "N/A"
    // ESC
    var ESCStatus: String = "N/A"

    // DSP
    var radioSignalStatus: String = "N/A"
    // 遥控器剩余电量
    var remainRCBattery: Int = 0
    // 飞行器剩余电量
    var remainDroneBattery: Int = 0
    // 飞行器电池压差异常
    var droneBatteryVoltageDiff: Bool = false
    // 电池装填
    var droneBatteyState: String {
        get {
            if droneBatteryVoltageDiff {
                return "Damaged battery"
            } else {
                return "\(remainDroneBattery) %"
            }
        }
    }
    // 飞行器电池温度
    var batteryTem: Float = 0
    // GPS信号强度
    var gpsSignalStrength: AUTELGpsSignalLevel = .GpsSignalLevelNone
    
    var unitBatteryTem: String {
        return batteryTem.format(format: ".1") + " " + "°C"
    }
    
    // !! 因为设定的逻辑是数据变化了 UI 才变化（而不是定时刷新 UI），所以必须记录保留这些数据
    // 记录遥控器状态
    var RCMode: AUTELRCControlStyle = .RCControlStyleUnknown
    
    var rcControlMode: SettingsRCMode {
        get {
            switch RCMode {
            case .RCControlStyleJapanese:
                return .mode1
            case .RCControlStyleAmerican:
                return .mode2
            case .RCControlStyleChinese:
                return .mode3
            default:
                return .mode1
            }
        }
    }
    
    // 记录云台状态
    var isGimbalCalibrating: Bool = false
    var isGimbalRollReachMax: Bool = false
    var isGimbalSleepForNoAttitude: Bool = false
    var isGimbalSleepForRollReachMax: Bool = false
    var gimbalStatus: String {
        get {
            if isGimbalCalibrating {
                return "Calibrating"
            } else if isGimbalRollReachMax {
                return "Angle reached."
            } else if isGimbalSleepForNoAttitude {
                return "No attitude data"
            } else if isGimbalSleepForRollReachMax {
                return "The tilt angle is over-large！"
            } else {
                return "Normal"
            }
        }
    }
    
    // 记录飞行主模式
    var flightMode: AUTELMainControllerMainMode = .AUTELMCMainModeUnknown
    var mainModeStatus: String {
        get {
            switch flightMode {
            case .AUTELMCMainModeAttitude:
                return "ATTI"
            case .AUTELMCMainModeGPS:
                return "GPS"
            case .AUTELMCMainModeIOC:
                return "IOC"
            case .AUTELMCMainModeStarpoint:
                return "Starpoint"
            case .AUTELMCMainModeUnknown:
                return "N/A"
            @unknown default:
                fatalError()
            }
        }
    }

    // 记录 SD Card 相关状态
    var isSDInsert: Bool = false
    var isSDFull: Bool = false
    var isSDInitializing: Bool = false
    var SDhasError: Bool = false
    var isSDInvalidFormat: Bool = false
    var remainSDCapacity: Float = 0
    var SDCardStatus: String {
        get {
            if isSDInsert == false {
                remainSDCapacity = 0
                return "No SD card"
            } else if SDhasError {
                return "Error"
            } else if isSDInvalidFormat {
                return "Unknown File System"
            } else if isSDInitializing {
                return "Initializing"
            } else if isSDFull {
                return "full"
            } else {
                if remainSDCapacity < 1024 {
                    return "\(remainSDCapacity)M"
                } else if remainSDCapacity/1024 >= 1024 {
                    return "\((remainSDCapacity/(1024 * 1024)).format(format: ".1"))T"
                } else {
                    return "\((remainSDCapacity/1024).format(format: ".1"))GB"
                }
            }
        }
    }
    
    // 记录 EMMC 相关状态
    var isEMMCInsert: Bool = true//注意：MMC固定插入
    var isEMMCFull: Bool = false
    var isEMMCInitializing: Bool = false
    var EMMChasError: Bool = false
    var isEMMCInvalidFormat: Bool = false
    var remainEMMCCapacity: Float = 0
    var EMMCStatus: String {
        get {
                
            if EMMChasError {
                return "Error"
            } else if isEMMCInvalidFormat {
                return "Unknown File System"
            } else if isEMMCInitializing {
                return "Initializing"
            } else if isEMMCFull {
                return "full"
            } else {
                if remainEMMCCapacity < 1024 {
                    return "\(remainEMMCCapacity)M"
                } else if remainEMMCCapacity/1024 >= 1024 {
                    return "\((remainEMMCCapacity/(1024 * 1024)).format(format: ".1"))T"
                } else {
                    return "\((remainEMMCCapacity/1024).format(format: ".1"))GB"
                }
            }
        }
    }
    
    // Vision System States
    // 前视视觉模组状态异常
    var isForwardVisionModuleAbnormal = false
    // 下视视觉模组状态异常
    var isDownwardVisionModuleAbnormal = false
    
    // 前视左目传感器状态异常 status2 20
    var isFrontLeftVisualSensorAbnormal = false
    
    // 0 - 标定参数有效 1 - 标定参数过期 status2 5
    var isVisionCalibrationInvalid = false
    // 前视右目传感器状态异常 status2 21
    var isFrontRightVisualSensorAbnormal = false
    // 后视左目传感器状态异常 status2 22
    var isBackLeftVisualSensorAbnormal = false
    // 后视右目传感器状态异常 status2 23
    var isBackRightVisualSensorAbnormal = false
    // 下视左目传感器状态异常 status2 24
    var isDownLeftVisualSensorAbnormal = false
    // 下视右目传感器状态异常 status2 25
    var isDownRightVisualSensorAbnormal = false
    // 右视左目传感器状态异常 status2 26
    var isRightLeftVisualSensorAbnormal = false
    // 右视右目传感器状态异常 status2 27
    var isRightRightVisualSensorAbnormal = false
    // 左视左目传感器状态异常 status2 28
    var isLeftLeftVisualSensorAbnormal = false
    // 左视右目传感器状态异常 status2 29
    var isLeftRightVisualSensorAbnormal = false
    // 上视左目传感器状态异常 status2 30
    var isUpLeftVisualSensorAbnormal = false
    // 上视右目传感器状态异常 status2 31
    var isUpRightVisualSensorAbnormal = false
    
    var canNotPassOutOfSafeSpace = false
    
    
    // Vision
    var visionStatus: String {
        get {
            
            if canNotPassOutOfSafeSpace {
                return "Settings_AS_Status_Vision_canNotPassOutOfSafeSpace_Attention"
            }
            
            else if isVisionCalibrationInvalid {
                return "Settings_AS_Status_Vision_VisionCalibrationInvalid_Attention"
            }
                
            else if isFrontLeftVisualSensorAbnormal || isFrontRightVisualSensorAbnormal {
                return "Settings_AS_Status_ForwardVision_Attention"
            }
            
            else if isBackLeftVisualSensorAbnormal || isBackRightVisualSensorAbnormal {
                return "Settings_AS_Status_BackwardVision_Attention"
            }

            else if isDownLeftVisualSensorAbnormal || isDownRightVisualSensorAbnormal {
                return "Settings_AS_Status_DownwardVision_Attention"
            }

            else if isRightLeftVisualSensorAbnormal || isRightRightVisualSensorAbnormal {
                return "Settings_AS_Status_RightwardVision_Attention"
            }

            else if isLeftLeftVisualSensorAbnormal || isLeftRightVisualSensorAbnormal {
                return "Settings_AS_Status_LeftwardVision_Attention"
            }

            else if isUpLeftVisualSensorAbnormal || isUpRightVisualSensorAbnormal {
                return "Settings_AS_Status_UpwardVision_Attention"
            }
            
            else {
                return "Normal"
            }
                            
        }
    }
    
    deinit {
        print("\(self.classIdentifier) deinit")
    }
}


