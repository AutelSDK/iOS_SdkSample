//
//  AUTELVisionOrbitMission.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/4/25.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AUTELSDK/AUTELFoundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELNavigation.h>
#import <UIKit/UIKit.h>

/**
 *  @brief  vision orbit mode status
 *
 *  视觉环绕模式状态
 */
typedef NS_ENUM(uint8_t, AUTELVisionOrbitModeStatus) {
    /**
     *  @brief Idle
     *
     *  未运行
     */
    AUTELVisionOrbitModeStatusIdle = 0,
    
    /**
     *  @brief target tracking
     *
     *  目标跟踪状态
     */
    AUTELVisionOrbitModeStatusTracking = 1,
    
    /**
     *  @brief stop  vision orbit mode
     *
     *  正在解算
     */
    AUTELVisionOrbitModeStatusCalculating = 2,
    
    /**
     *  @brief stop  vision orbit mode
     *
     *  解算暂停
     */
    AUTELVisionOrbitModeStatusCalculatPaused = 3,
    
    /**
     *  @brief start vision orbit mode
     *
     *  开始视觉环绕模式
     */
    AUTELVisionOrbitModeStatusRunning = 4,
    
    /**
     *  @brief pause  vision orbit mode
     *
     *  暂停视觉环绕模式
     */
    AUTELVisionOrbitModeStatusPaused = 5,
    
    //Unknow
    AUTELVisionOrbitModeStatusUnknow = 255,
    
};

/**
 *  @brief  vision orbit mode operation
 *
 *  视觉环绕模式操作
 */
typedef NS_ENUM(uint8_t, AUTELVisionOrbitModeOperation) {
    /**
     *  @brief exit vision orbit mode
     *
     *  退出视觉环绕模式
     */
    AUTELVisionOrbitModeOperationExit = 0,
    
    /**
     *  @brief enter  vision orbit mode
     *
     *  进入视觉环绕模式
     */
    AUTELVisionOrbitModeOperationEnter = 1,
    
    /**
     *  @brief stop  vision orbit mode
     *
     *  停止视觉环绕模式
     */
    AUTELVisionOrbitModeOperationStop = 2,
    
    /**
     *  @brief start vision orbit mode
     *
     *  开始视觉环绕模式
     */
    AUTELVisionOrbitModeOperationStart = 3,
    
    /**
     *  @brief exit  vision orbit  time-lapse photography mode.
     *
     *  退出环绕延时模式
     */
    AUTELVisionOrbitDelayShotModeOperationExit = 20,
    
    /**
     *  @brief enter  vision orbit  time-lapse photography mode.
     *
     *  进入环绕延时模式
     */
    AUTELVisionOrbitDelayShotModeOperationEnter = 21,
    
    /**
     *  @brief stop  vision orbit  time-lapse photography mode.
     *
     *  停止环绕延时模式
     */
    AUTELVisionOrbitDelayShotModeOperationStop = 22,
    
    /**
     *  @brief start vision orbit  time-lapse photography mode.
     *
     *  开始环绕延时模式
     */
    AUTELVisionOrbitDelayShotModeOperationStart = 23,
    
};

     
NS_ASSUME_NONNULL_BEGIN


/**
 *  The real-time status of the smart orbit mission. When the aircraft is performing the smart orbit mission, the status is updated in real time by the -onNavigationMissionStatusChanged: method of AUTELNavigationDelegate.
 *
 *  智能环绕任务实时状态，当飞行器在执行智能环绕任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELVisionOrbitMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execute state of the  smart orbit mission.
 *
 *  智能环绕任务实时状态
 *
 *  @see AUTELMissionExecuteState
 */
@property (nonatomic) AUTELVisionOrbitModeStatus execStatus;

/**
*  @brief Visibility of GPS satellite.
*
*  跟踪目标状态
*/
@property (nonatomic) int trackStatus;

/**
*  @brief Target coordinates.
*
*  目标坐标
*/
@property (nonatomic) CGRect targetRect;

/**
*  @brief Current orbit height.
*
*  当前的环绕高度， 单位 m
*/
@property (nonatomic, assign) int currentAltitude;

/**
*  @brief Current orbit radius.
*
*  当前的环绕半径, 单位 m
*/
@property (nonatomic, assign) int currentRadius;

/**
*  @brief Set orbit height.
*
*  设置的环绕高度， 单位 m
*/
@property (nonatomic, assign) int setAltitude;

/**
*  @brief Set the orbit radius.
*
*  设置的环绕半径, 单位 m
*/
@property (nonatomic, assign) int setRadius;

/**
*  @brief Flight speed, unit m / s.
*
*  飞行速度, 单位 m/s
*/
@property (nonatomic, assign) int speed;

/**
*  @brief Set orbit speed.
*
*  设置飞行速度
*/
@property (nonatomic, assign) int setSpeed;

/**
*  @brief Orbit direction, 0-clockwise, 1-counterclockwise.
*
*  环绕方向，0-顺时针，1-逆时针
*/
@property (nonatomic, assign) int direction;

/**
*  @brief Set orbit radius flag.
*
*  环绕半径标志位
*/
@property (nonatomic, assign) int radiusFlag;

/**
*  @brief Set orbit height flag.
*
*  环绕高度标志位
*/
@property (nonatomic, assign) int altitudeFlag;

/**
*  @brief Set Flight speed flag, 1-  valid, 0-  invalid.
*
*  飞行速度标志，1-为有效，0 - 为无效
*/
@property (nonatomic, assign) int speedFlag;

/**
*  @brief Set Orbit direction flag, 1-  valid, 0-  invalid.
*
*  环绕方向标志，1-为有效，0 - 为无效
*/
@property (nonatomic, assign) int directionFlag;

@end

/**
 *  This class includes hot point mission related functions.
 *
 *  延时摄影任务
 
 */

@interface AUTELVisionOrbitMission : AUTELMission<NSCopying>

//环绕高度， 单位 m
@property (nonatomic, assign) int altitude;

//环绕半径, 单位 m
@property (nonatomic, assign) int radius;

//飞行速度, 单位 m/s
@property (nonatomic, assign) int speed;

//环绕方向，0-顺时针，1-逆时针
@property (nonatomic, assign) int direction;

@end


NS_ASSUME_NONNULL_END



