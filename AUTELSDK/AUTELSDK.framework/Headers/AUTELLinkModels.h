//
//  AUTELLinkModels.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/6/18.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELWaypointMC.h"


/**
 *   Remote control physical button type
 *
 *   遥控器物理按键类型
 */
typedef NS_ENUM(NSInteger, AUTELRCButtonType) {
    /**
    *  @brief unknow
    *
    *  未知
    */
    AUTELRCButtonTypeUnknow = 0,
    /**
    *  @brief A button
    *
    *  A键
    */
    AUTELRCButtonTypeA = 1,
    /**
    *  @brief B button
    *
    *  B键
    */
    AUTELRCButtonTypeB = 2,
    

};


/**
 *   The remote control supports custom key function types
 *
 *   遥控器支持自定义按键功能类型
 */
typedef NS_ENUM(NSInteger, AUTELRCCustomButtonFuncType) {
    /**
    *  @brief Undefined
    *
    *  未定义
    */
    AUTELRCCustomButtonFuncTypeUndefined = 0,
    /**
    *  @brief Obstacle avoidance switch
    *
    *  避障开关
    */
    AUTELRCCustomButtonFuncTypeOAvoidanceSwitch = 1,
    /**
    *  @brief AE lock or unlock
    *
    *  AE锁定/解锁
    */
    AUTELRCCustomButtonFuncTypeAELockOrUnlock = 2,
    /**
    *  @brief One click to return to center or vertical
    *
    *  云台一键回中或垂直90度
    */
    AUTELRCCustomButtonFuncTypeGimbalCenterOrVertical = 3,
    /**
    *  @brief Map and FPV switch
    *
    *  地图和FPV切换
    */
    AUTELRCCustomButtonFuncTypeMapAndFPVSwitch = 4,
    /**
    *  @brief Speed mode switch
    *
    *  速度标准模式、狂暴模式切换
    */
    AUTELRCCustomButtonFuncTypeSpeedMode = 5,
};


/**
 *   The remote control supports custom key function types
 *
 *   遥控器支持自定义按键功能类型
 */
typedef NS_ENUM(NSInteger, AUTELRCvirtualJoystickControlCommand) {
    /**
    *  @brief Undefined
    *
    *  未定义
    */
    AUTELRCvirtualJoystickControlCommandUndefined = 0,
    /**
    *  @brief Obstacle avoidance switch
    *
    *  停止任务
    */
    AUTELRCvirtualJoystickControlCommandExit = 1,
    /**
    *  @brief AE lock or unlock
    *
    *  一键起飞降落
    */
    AUTELRCvirtualJoystickControlCommandTakeOffOrLand = 2,
    /**
    *  @brief One click to return to center or vertical
    *
    *  返航
    */
    AUTELRCvirtualJoystickControlCommandGoHome = 3,
    /**
    *  @brief Map and FPV switch
    *
    *  悬停
    */
    AUTELRCvirtualJoystickControlCommandHover = 4,
};

NS_ASSUME_NONNULL_BEGIN


/**
 *  @brief Remote control custom key function model
 *
 *  遥控器自定义按键模型
 */
@interface AUTELRCCustomKeyFuncModel: NSObject

/**
 *  @brief Custom button A long press function definition
 *
 *  物理按键类型
 */
@property (nonatomic, assign) AUTELRCButtonType buttonType;

/**
 *  @brief Custom button long press function
 *
 *  自定义按键长按功能
 */
@property (nonatomic, assign) AUTELRCCustomButtonFuncType buttonFuncType;


/// Init with param
/// 跟进参数初始化
/// @param param 参数
- (instancetype)initWithParam:(NSDictionary *)param;

- (NSDictionary *)transformToDic;

@end

/**
 *  @brief aircraft GPS recordInfo
 *
 *  遥控器记录的无人机GPS信息
 */
@interface AUTELAircraftGPSRecordInfo: NSObject


/// time boot Ms
/// 启动时间
@property (nonatomic, readonly, assign) long timeBootMs;

/**
 *  @brief aircraft coord
 *
 *  无人机坐标
 */
@property (nonatomic, readonly, strong) AUTELCoordinate3D *coord;


/// x方向速度
/// speed in x direction
@property (nonatomic, readonly, assign) float vx;

/// y方向速度
/// speed in y direction
@property (nonatomic, readonly, assign) float vy;

/// z方向速度
/// speed in z direction
@property (nonatomic, readonly, assign) float vz;

/// 偏航角
/// yaw
@property (nonatomic, readonly, assign) float yaw;

/// distance
/// 距离
@property (nonatomic, readonly, assign) float distance;

/// Remaining battery percentage
/// 剩余电量百分比
@property (nonatomic, readonly, assign) float rsocRemainPercent;

/// Init with param
/// 跟进参数初始化
/// @param param 参数
- (instancetype)initWithParam:(NSDictionary *)param;

@end






/**
 *  @brief Remote control  Virtual joystick control model
 *
 *  遥控器虚拟摇杆按键模型
 */
@interface AUTELRCVirtualJoystickControlModel: NSObject

/**
 *  @brief Right horizontal joystick, range: -100~100
 *
 *  右横向摇杆, 范围：-100~100
 */
@property (nonatomic, assign) int rightHorizonPole;

/**
 *  @brief Right vertical joystick, range: -100~100
 *
 *  右竖向摇杆, 范围：-100~100
 */
@property (nonatomic, assign) int rightVerticalPole;

/**
 *  @brief Left horizontal joystick, range: -100~100
 *
 *  左横向摇杆, 范围：-100~100
 */
@property (nonatomic, assign) int leftHorizonPole;

/**
 *  @brief Left vertical joystick, range: -100~100
 *
 *  左竖向摇杆, 范围：-100~100
 */
@property (nonatomic, assign) int leftVerticalPole;

/**
 *  @brief gimbal pitch wheel, range: -100~100
 *
 *  云台pitch拨轮, 范围：-100~100
 */
@property (nonatomic, assign) int gimbalPitch;

/**
 *  @brief General function keys
 *
 *  通用功能按键
 */
@property (nonatomic, assign) AUTELRCvirtualJoystickControlCommand generalKey;

/**
 *  @brief Combination keys
 *
 *  组合按键
 */
@property (nonatomic, assign) int combinedKey;


- (NSDictionary *)transformToDic;

@end





/**
 *   Remote control pairing status
 *
 *   遥控器对频状态
 */
typedef NS_ENUM(NSInteger, AUTELRCPairingStatus) {
    /**
    *  @brief unknow
    *
    *  未知
    */
    AUTELRCPairingStatusUnknow = 0,
    /**
    *  @brief Pairing
    *
    * 开始对频，对频中
    */
    AUTELRCPairingStatusPairing = 1,
    /**
    *  @brief B Pairing successfully
    *
    *  对频成功
    */
    AUTELRCPairingStatusSuccess = 2,
    /**
    *  @brief Pairing failed
    *
    *  对频超时或对频启动失败
    */
    AUTELRCPairingStatusFailed = 3,
    
};

/**
 *   Remote Control pairing Device Type
 *
 *   遥控器对频设备类型
 */
typedef NS_ENUM(NSInteger, AUTELRCPairingDeviceType) {
    /**
    *  @brief Normal
    *
    * 普通设备
    */
    AUTELRCPairingDeviceTypeNormal = 0,
    /**
    *  @brief Repeater
    *
    *  中继
    */
    AUTELRCPairingDeviceTypeRepeater = 1,
    
};

/**
 *   Remote Control pairing role
 *
 *   遥控器对频角色
 */
typedef NS_ENUM(NSInteger, AUTELRCPairingRole) {
    /**
    *  @brief unknow
    *
    *  未知
    */
    AUTELRCPairingRoleUnknow = 0,
    /**
    *  @brief A Master
    *
    * 主控
    */
    AUTELRCPairingRoleMaster = 1,
    /**
    *  @brief Slave
    *
    *  从机
    */
    AUTELRCPairingRoleSlave = 2,
    
};

/**
 *  @brief Remote control linking status update
 *
 *  遥控器对频状态上报信息
 */
@interface RemoteControlPairingState: NSObject

/**
 *   Remote Control pairing role
 *
 *   遥控器对频角色
 */
@property (nonatomic, readonly, assign) AUTELRCPairingRole role;

/**
 *   Remote control pairing status
 *
 *   遥控器对频状态
 */
@property (nonatomic, readonly, assign) AUTELRCPairingStatus status;

/// Init with param
/// 跟进参数初始化
/// @param param 参数
- (instancetype)initWithParam:(NSDictionary *)param;

@end


NS_ASSUME_NONNULL_END
