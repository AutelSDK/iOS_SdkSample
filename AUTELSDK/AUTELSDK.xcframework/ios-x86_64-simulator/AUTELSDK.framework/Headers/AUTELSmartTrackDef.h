//
//  AUTELSmartTrackDef.h
//  AUTELSDK
//
//  Created by Devin on 2018/1/30.
//  Copyright © 2018年 Autel. All rights reserved.
//

#ifndef AUTELSmartTrackDef_h
#define AUTELSmartTrackDef_h

#import <Foundation/Foundation.h>



/**
 *  @brief  Gesture mode operation
 *
 *  进入、退出手势识别检测模式
 */
typedef NS_ENUM(uint8_t, AUTELGestureCheckAction) {
    /**
     *  @brief Exit Gesture mode
     *
     *  退出手势识别检测模式
     */
    AUTELGestureCheckActionExit = 0,
    
    /**
     *  @brief Enter Gesture mode
     *
     *  进入手势识别检测模式
     */
    AUTELGestureCheckActionEnter = 1,
    
    /**
     *  @brief Stop Gesture mode
     *
     *  停止手势识别回到检测模式
     */
    AUTELGestureCheckActionStop = 2,
};

/**
 *  @brief  Track operation action
 *
 *  进入、退出、停止追踪检测模式
 */
typedef NS_ENUM(uint8_t, AUTELSmartTrackCheckAction) {
    /**
     *  @brief Exit object Track
     *
     *  退出追踪检测模式
     */
    AUTELSmartTrackCheckActionExit = 0,
    
    /**
     *  @brief Enter object Track
     *
     *  进入追踪检测模式
     */
    AUTELSmartTrackCheckActionEnter = 1,
    
    /**
     *  @brief Stop object Track
     *
     *  停止追踪检测模式
     */
    AUTELSmartTrackCheckActionStop = 2,
};

#pragma mark - AUTELSmartTrackPattern
//-----------------------------------------------------------------

/**
 *  @brief  Tracking mode
 *
 *  追踪模式
 */
typedef NS_ENUM(uint8_t, AUTELSmartTrackPattern) {
    /**
     *  @brief Enter tracking mode
     *
     *  进入追踪模式
     */
    AUTELSmartTrackPatternEnter = 0,
    /**
     *  @brief Exit tracking mode
     *
     *  退出追踪模式
     */
    AUTELSmartTrackPatternExit,
};

/**
 *  @brief  Track target type
 *
 *  追踪目标类型
 */
typedef NS_ENUM(uint8_t, AUTELSmartTrackTargetType) {
    /**
     *  @brief Background
     *
     *  背景
     */
    AUTELSmartTrackTargetTypeBackground = 0,
    /**
     *  @brief Animal
     *
     *  动物
     */
    AUTELSmartTrackTargetTypeAnimal = 1,
    
    /**
     *  @brief Boat
     *
     *  船只
     */
    AUTELSmartTrackTargetTypeBoat = 2,
    
    /**
     *  @brief Car
     *
     *  小汽车
     */
    AUTELSmartTrackTargetTypeCar,
    
    /**
     *  @brief Person
     *
     *  人
     */
    
    AUTELSmartTrackTargetTypePerson = 4,
    /**
     *  @brief Rider
     *
     *  骑手
     */
    AUTELSmartTrackTargetTypeRider = 5,
    
    /**
     *  @brief LargeVehicle
     *
     *  大卡
     */
    AUTELSmartTrackTargetTypeLargeVehicle = 6,
    
    /**
     *  @brief DetectAndSelectPerson
     *
     *  大卡
     */
    AUTELSmartTrackTargetTypeDetectAndSelectPerson = 7,
    
    /**
     *  @brief Shot cmd
     *
     *  Shot
     */
    AUTELSmartTrackTargetTypeShot = 8,
    
    /**
     *  @brief StartOrStopRecording cmd
     *
     *  StartOrStopRecording
     */
    AUTELSmartTrackTargetTypeStartOrStopRecording = 9,
    
    /**
     *  @brief Other
     *
     *  其他
     */
    AUTELSmartTrackTargetTypeOther = AUTELSmartTrackTargetTypeStartOrStopRecording,
    
    /**
     *  @brief VehicleLP
     *
     *  车辆
     */
    AUTELSmartTrackTargetTypeVehicleLP = 10,
    
    /**
     *  @brief LP
     *
     *  车辆
     */
    AUTELSmartTrackTargetTypeLP = 11,
    
    /**
     *  @brief clear BBox
     *
     *  车辆
     */
    AUTELSmartTrackTargetTypeBBox = 99,
    
    /**
     *  @brief Bike
     *
     *  自行车
     */
    AUTELSmartTrackTargetTypeBike = AUTELSmartTrackTargetTypeRider,
    /**
     *  @brief Motorcycle
     *
     *  摩托车
     */
    AUTELSmartTrackTargetTypeMotorcycle = AUTELSmartTrackTargetTypeBike,
    /**
     *  @brief Quadricycle
     *
     *  四轮车
     */
    AUTELSmartTrackTargetTypeQuadricycle = AUTELSmartTrackTargetTypeLargeVehicle,
    
    /**
     *  @brief UAV
     *
     *  无人机
     */
    AUTELSmartTrackTargetTypeUAV,
    
};
/**
 *  @brief  Smart tracking parameter type
 *
 *  智能追踪的参数类型
 */
typedef NS_ENUM(uint8_t, AUTELSmartTrackParamType) {
    /**
     *  @brief  Width
     *
     *  宽度
     */
    AUTELSmartTrackParamTypeWidth,
    /**
     *  @brief  height
     *
     *  高度
     */
    AUTELSmartTrackParamTypeHeight,
};
/**
 *  @brief  Smart track mode
 *
 *  智能追踪模式
 */
typedef NS_ENUM(uint8_t, AUTELSmartTrackMode) {
    /**
     *  @brief  Don't set follow mode
     *
     *  不设置追踪模式
     */
    AUTELSmartTrackModeNone = 0,
    /**
     *  @brief  Normal follow mode (you can use the joystick or APP to control the flight around the target, and the obstacle perception will not take effect when you surround)
     *
     *  普通追踪模式（可以使用摇杆或APP控制飞行环绕目标，环绕时障碍物感知将不生效）
     */
    AUTELSmartTrackModeNormal = 1,
    /**
     *  @brief  Parallel follow mode (the aircraft will remain in the same position, follow the target. Obstacle perception will not take effect)
     *
     *  平行追踪模式（飞行器将保持相对位置一致，追踪目标。障碍物感知将不生效）
     */
    AUTELSmartTrackModeParallel = 2,
    /**
     *  @brief  Lock the following mode (the aircraft lens will always be facing the target you selected, and the aircraft heading will be locked in the direction when entering the mode. Obstacle perception will not take effect.)
     *
     *  锁定追踪模式（飞行器镜头会一直朝向你选定的目标，同时，飞行器航向将被锁定为进入模式时的方向。障碍物感知将不生效。）
     */
    AUTELSmartTrackModeLocking = 3,
    /**
     *  @brief  unknow mode
     *
     *  未知模式
     */
    AUTELSmartTrackModeUnknow = 0xFF
};
/**
 *  @brief  Tracking Ambient Light State
 *
 *  智能追踪环境光照状态
 */
typedef NS_ENUM(NSUInteger, AUTELTrackingAmbientLightState) {
    /**
     *  @brief  normal
     *
     *  正常
     */
    AUTELTrackingAmbientLightStateNormal = 0,
    /**
     *  @brief  weak
     *
     *  光照弱
     */
    AUTELTrackingAmbientLightStateWeak,
    /**
     *  @brief  strong
     *
     *  光照强
     */
    AUTELTrackingAmbientLightStateStrong,
    /**
     *  @brief  unknow mode
     *
     *  光照未知
     */
    AUTELTrackingAmbientLightStateUnkown = -1
};

/**
 *  @brief  View point mode
 *
 *  指点飞行模式
 */
typedef NS_ENUM(uint8_t, AUTELSmartViewPointPattern) {
    /**
     *  @brief Exit tracking mode
     *
     *  退出指点飞行模式
     */
    AUTELSmartViewPointPatternExit = 0,
    /**
     *  @brief Enter tracking mode
     *
     *  进入指点飞行模式
     */
    AUTELSmartViewPointPatternEnter = 1,
    /**
     *  @brief Exit tracking mode
     *
     *  开始指点飞行任务
     */
    AUTELSmartViewPointPatternStart = 3,
};

#endif /* AUTELSmartTrackDef_h */
