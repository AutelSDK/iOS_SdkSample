//
//  AUTELMainControllerDef.h
//  AUTELSDK
//
//  Created by IOS on 15/11/4.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 *  Define aircraft attitude
 *
 *  定义飞行器姿态
 */
typedef struct {
    /**
     *  @brief Aircraft's pitch angle (°)
     *
     *  飞机俯仰角（°）
     */
    float pitch;
    /**
     *  @brief Aircraft's roll angle (°)
     *
     *  飞机横滚角（°）
     */
    float roll;
    /**
     *  @brief Aircraft's yaw angle (°)
     *
     *  飞机偏航角（°）
     */
    float yaw;
} AUTELAttitude;

/**
 *  Define compass calibration state
 *
 *  定义磁力计校准状态
 */
typedef NS_ENUM(uint8_t, AUTELCompassCalibrationStatus) {
    /**
     *  @brief Compass is not calibrating.
     *
     *  磁力计没有在校准
     */
    AUTELCompassCalibrationNone,
    
    /**
     *  @brief Compass calibration step 1: Hold the aircraft horizontally by its arms and turn around until the 4 LEDs on the aircraft flash green light.
     *
     *  校准步骤1：水平握住飞行器机翼，并以自身为中心旋转，直到4盏LED灯闪烁绿灯。
     */
    AUTELCompassCalibrationStep1,
    
    /**
     *  @brief Compass calibration step 2: Hold the aircraft vertically by its arms with its nose facing downwards and turn around until the 4 LEDs on the aircraft turn solid green.
     *
     *  校准步骤2：使飞行器与地面垂直且机头朝下，双手握住机翼，并以自身为中心旋转，直到4盏LED灯变为绿色常亮。
     */
    AUTELCompassCalibrationStep2,
    
    /**
     *  @brief Compass calibration step 3: Rotate the aircraft sideways until the green light comes on..
     *
     *  校准步骤3：将飞机侧向旋转至绿灯亮起。
     */
    AUTELCompassCalibrationStep3,
    
    /**
     *  @brief Compass calibration step 3: calculate and save parameters.
     *
     *  @brief 校准步骤3: 计算并保存参数。
     */
    AUTELCompassCalibrationCalculating,
    
    /**
     *  @brief Compass calibration succeeded.
     *
     *  校准成功。
     */
    AUTELCompassCalibrationSucceeded,
    
    /**
     *  @brief Compass calibration failed.
     *
     *  校准失败。
     */
    AUTELCompassCalibrationFailed,
    
    /**
     *  @brief No GPS signal.Cannot calibrate now.
     *
     *  没有 GPS 信号,无法校准指南针
     */
    AUTELCompassCalibrationFailedNoGPS,
    
    /**
     *  @brief 指南针校准超时
     *
     *  指南针校准超时
     */
    AUTELCompassCalibrationTimeout,
    
    /**
     *  @brief Compass calibration status unknown.
     *
     *  未知状态。
     */
    AUTELCompassCalibrationUnknown,
};

/**
 *  Define IMU calibration state
 *
 *  定义IMU校准状态
 */
typedef NS_ENUM(uint8_t, AUTELIMUCalibrationStatus) {
    /**
     *  @brief IMU is not calibrating.
     *
     *  IMU没有在校准
     */
    AUTELIMUCalibrationStatusNone,
    /**
     *  @brief IMU calibration step 1: Level up.
     *
     *  校准步骤1：水平朝上。
     */
    AUTELIMUCalibrationStatusStep1,
    /**
     *  @brief IMU calibration step 2: Level down.
     *
     *  校准步骤2：水平朝下。
     */
    AUTELIMUCalibrationStatusStep2,
    /**
     *  @brief IMU calibration step 3: Right side up.
     *
     *  校准步骤3：右侧朝上侧放。
     */
    AUTELIMUCalibrationStatusStep3,
    /**
     *  @brief IMU calibration step 4: Left side up.
     *
     *  校准步骤4：左侧朝上侧放。
     */
    AUTELIMUCalibrationStatusStep4,
    
    /**
     *  @brief IMU calibration step 5: Upright and up.
     *
     *  校准步骤5：竖直朝上。
     */
    AUTELIMUCalibrationStatusStep5,
    
    /**
     *  @brief IMU calibration step 6: Straight down.
     *
     *  校准步骤6：竖直朝下。
     */
    AUTELIMUCalibrationStatusStep6,
    /**
     *  @brief IMU calibration succeeded.
     *
     *  校准成功。
     */
    AUTELIMUCalibrationStatusSucceeded,
    /**
     *  @brief IMU calibration failed.
     *
     *  校准失败。
     */
    AUTELIMUCalibrationStatusFailed,
    /**
     *  @brief IMU calibration status unknown.
     *
     *  未知状态。
     */
    AUTELIMUCalibrationStatusUnknown,
};

/**
 *  Define IMU calibration warn
 *
 *  定义IMU校准告警
 */
typedef NS_ENUM(uint8_t, AUTELIMUCalibrationWarn) {
    /**
     *  @brief No warn.
     *
     *  没有告警
     */
    AUTELIMUCalibrationWarnNone,
    /**
     *  @brief IMU calibration step 1: Level up.
     *
     *  开始校准。
     */
    AUTELIMUCalibrationWarnBeginCalculating,
    /**
     *  @brief IMU calibration step 2: Level down.
     *
     *  正在校准。
     */
    AUTELIMUCalibrationWarnCalculating,
    /**
     *  @brief Drone shaking.
     *
     *  飞机晃动。
     */
    AUTELIMUCalibrationWarnShaking,
    /**
     *  @brief Wrong direction.
     *
     *  朝向不对。
     */
    AUTELIMUCalibrationWarnWrongDirection,
};


/**
 *  Define the level of compass interference
 *
 *  定义磁力计受干扰级别
 */
typedef NS_ENUM(uint8_t, AUTELCompassInterferenceLevel) {
    /**
     *  @brief Interference not detected.
     *
     *  磁力计没有受到干扰。
     */
    AUTELCompassInterferenceLevel0,
    
    /**
     *  @brief The compass can keep the right course despite of slight interference.
     *
     *  磁力计收到轻微干扰,但还可以保持正确的航向。
     */
    AUTELCompassInterferenceLevel1,
    
    /**
     *  @brief The compass cannot keep its right course due to continuous interference.
     *
     *  磁力计持续受到干扰,无法保证正确的航向。
     */
    AUTELCompassInterferenceLevel2,
    
    /**
     *  @brief The compass cannot keep its right course due to continuous interference. ATTI mode will be activated soon.
     *
     *  磁力计持续受到干扰，无法保证正确航向，即将切换至姿态模式。
     */
    AUTELCompassInterferenceLevel3,
    
    /**
     *  @brief ATTI mode activated due to abnormal compass.
     *
     *  磁力计异常，已经切换至姿态模式。
     */
    AUTELCompassInterferenceLevel4,
};

/**
 *  Define the state of aircraft LED light
 *
 *  定义LED灯状态
 */
typedef NS_ENUM(uint8_t, AUTELAircraftLedState) {
    /**
     *  @brief LED 灯全关
     */
    AUTELAircraftLedStateAllOff = 0,
    /**
     *  @brief 前灯关后灯开
     */
    AUTELAircraftLedStateHeadOffTailOn = 1,
    /**
     *  @brief 前灯开后灯关
     */
    AUTELAircraftLedStateHeadOnTailOff = 2,
    /**
     *  @brief LED 灯全开
     */
    AUTELAircraftLedStateAllOn = 3,
    /**
     *  @brief 拍照闪灯
     */
    AUTELAircraftLedStatePhotographFlashing = 4,
    /**
     *  @brief 录像闪灯
     */
    AUTELAircraftLedStateRecordFlashing = 8,
};

/**
 *  Define the binding state between the aircraft and the user.
 *
 *  定义飞行器与用户绑定状态
 */
typedef NS_ENUM(uint8_t, AUTELDroneBindUserState) {
    /**
     *  @brief This aircraft has been bound to a user already.
     *
     *  该飞行器已经绑定用户
     */
    AUTELDroneBindStateBound,
    
    /**
     *  @brief This aircraft has not been bound to any user.
     *
     *  该飞行器未绑定用户
     */
    AUTELDroneBindStateNoBound,
    
    /**
     *  Firmware update is needed to enable binding of the aircraft
     *
     *  该飞行器不支持绑定，需要升级固件
     */
    AUTELDroneBindStateNoSupport,
    
    /**
     *  Unknow binding state between this aircraft and users.
     *
     *  飞行器与用户绑定状态未知
     */
    AUTELDroneBindStateUnknown = -1,
};

typedef struct {
    /**
     *  Velocity (m/s) along the y-axis or angle value (in degrees) for pitch.      
     */
    float pitch;
    /**
     *  Velocity (m/s) along the x-axis or angle value (in degrees) for roll.
     */
    float roll;
    /**
     *  Angular Velocity (degrees/s) or Angle (degrees) value for yaw.
     */
    float yaw;
    /**
     *  Velocity (m/s) or Alititude (m) value for verticalControl.
     */
    float verticalThrottle;
} AutelVirtualStickFlightControlData;

/**
 * battery temperature warning
 */
typedef NS_ENUM(uint8_t, AUTELBatteryTemperatureWarning) {
    /**
     *  @brief 电池温度正常
     */
    AUTELBatteryTemperatureWarningNormal = 0,
    
    /**
     *  @brief 电池温度偏高
     */
    AUTELBatteryTemperatureWarningHigh,
    
    /**
     *  @brief 电池温度过高
     */
    AUTELBatteryTemperatureWarningOverheated,
    
    /**
     *  @brief 电池温度偏低
     */
    AUTELBatteryTemperatureWarningLow,
    
    /**
     *  @brief 电池温度偏低
     */
    AUTELBatteryTemperatureWarningCriticallyLow,
    
    /**
     *  @brief 电池温度过低
     */
    AUTELBatteryTemperatureWarningUnknown = -1,
};


/**
 *  Define the type of Stick Sensitivity
 *
 *  定义感应度类型
 */
typedef NS_ENUM(uint8_t, AUTELStickSensitivityType) {
    /**
     *  @brief Yaw
     */
    AUTELStickSensitivityTypeYaw = 0,
    /**
     *  @brief PitchAndRoll
     */
    AUTELStickSensitivityTypePitchAndRoll = 1,
    /**
     *  @brief Thrust
     */
    AUTELStickSensitivityTypeThrust = 2,
    /**
     *  @brief Attitude
     */
    AUTELStickSensitivityTypeAtti = 3,
    /**
     *  @brief Brake
     */
    AUTELStickSensitivityTypeBrake = 4,
    /**
     *  @brief Yaw Sch
     */
    AUTELStickSensitivityTypeYawSch = 5,
    /**
     *  @brief Pitch
     */
    AUTELStickSensitivityTypePitch = 6,
    /**
     *  @brief Roll
     */
    AUTELStickSensitivityTypeRoll = 7,
    /**
     *  @brief Unknown
     */
    AUTELStickSensitivityTypeUnknown = -1,
};

/**
 *  Define obstacle avoidance switch direction
 *
 *  定义避障开关方向
 */
typedef NS_ENUM(uint8_t, AUTELOADirection) {
    /**
     *  @brief front & rear
     */
    AUTELOADirectionFrontRear = 0,
    /**
     *  @brief left & right
     */
    AUTELOADirectionLeftRight = 1,
    /**
     *  @brief top
     */
    AUTELOADirectionTop = 2,

    /**
     *  @brief Unknown
     */
    AUTELOADirectionUnknown = -1,
};


/**
 *  Define Upload file type
 *
 *  上传文件类型定义
 */
typedef NS_ENUM(uint8_t, AUTELTransferFileType) {
    /**
     *  @brief 程序数据/升级文件
     */
    AUTELTransferFileTypeUpgrade = 0,
    /**
     *  @brief 高程数据文件
     */
    AUTELTransferFileTypeElevationData = 1,
    /**
     *  @brief 禁飞区文件
     */
    AUTELTransferFileTypeNoFlyZone = 2,
    /**
     *  @brief 保留
     */
    AUTELTransferFileTypereserve1 = 3,
    /**
     *  @brief 保留
     */
    AUTELTransferFileTypereserve2 = 4,
    /**
     *  @brief 任务数据文件
     */
    AUTELTransferFileTypeMissionData = 5,
    /**
     *  @brief 喊话器数据文件
     */
    AUTELTransferFileTypeAudioData = 6,
    /**
     *  @brief 授权区数据文件
     */
    AUTELTransferFileTypeAuthFlyZone = 7,

    /**
     *  @brief Unknown
     */
    AUTELTransferFileTypeUnknown = -1,
};


typedef NS_ENUM(uint8_t, AUTELAccessoryWorkMode) {
    AUTELAccessoryWorkModeNightLight = 0,
    AUTELAccessoryWorkModeSearchlight = 1,
    AUTELAccessoryWorkModeMegaphone = 2,
    AUTELAccessoryWorkModeUnknow = 255,
};


///当前接入图传类型，默认中兴图传
typedef NS_ENUM(NSInteger, AUTELAirLinkType){
    ///中兴图传
    AUTELAirLinkTypeZte  = 0x00,
    ///酷芯图传
    AUTELAirLinkTypeWimax     = 0x01,

};
