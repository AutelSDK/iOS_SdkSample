//
//  AUTELDelayShotMission.h
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



/**
 *  DelayShot Mission Type
 *
 *  延时摄影类型
 */
typedef NS_ENUM(uint8_t, AUTELDelayShotMissionType ) {
    /**
     *  @brief free delay shot
     *
     *  自由延时摄影
     */
    AUTELDelayShotMissionTypeFree,
    
};

/**
*  Delay Shot Mission status
*
*  延时摄影状态
*/
typedef NS_ENUM(uint8_t, AUTELCameraDelayShotStatus ) {
    /**
    *  @brief Stop
    *
    *  停止
    */
    AUTELCameraDelayShotStatusStop = 0,
    
    /**
    *  @brief Pause
    *
    *  暂停
    */
    AUTELCameraDelayShotStatusPause = 1,
    
    /**
    *  @brief Taking Photo
    *
    *  正在拍照
    */
    AUTELCameraDelayShotStatusTakingPhoto = 2,
    
    /**
    *  @brief synthesis
    *
    *  合成中
    */
    AUTELCameraDelayShotStatusSynthesis = 3
    
};

/**
*  Cruise Mode
*
*  定速巡航模式
*/
typedef NS_ENUM(uint8_t, AUTELCameraCruiseMode ) {
    /**
    *  @brief exit
    *
    *  退出
    */
    AUTELCameraCruiseModeExit,
    
    /**
    *  @brief enter
    *
    *  进入
    */
    AUTELCameraCruiseModeEnter,
    
};

/**
*  Cruise state
*
*  定速巡航状态
*/
typedef NS_ENUM(uint8_t, AUTELCameraCruiseState ) {
    /**
    *  @brief exit
    *
    *  不可进入定速巡航
    */
    AUTELCameraCruiseStateCanNotEnter = 0,
    
    /**
    *  @brief enter
    *
    *  可以进入定速巡航
    */
    AUTELCameraCruiseStateCanEnter = 1,
    
    /**
    *  @brief enter
    *
    *  已进入定速巡航
    */
    AUTELCameraCruiseStateEntered = 2,
    
};
     
NS_ASSUME_NONNULL_BEGIN


/**
 *  The real-time status of the free time-lapse photography mission. When the aircraft is executing the time-lapse photography mission, the status is updated in real time by the -onNavigationMissionStatusChanged: method of AUTELNavigationDelegate.
 *
 *  自由延时摄影任务实时状态，当飞行器在执行延时摄影任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELDelayShotMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execute state of the one shot video mission.
 *
 *  延时摄影任务执行状态
 *
 *  @see AUTELMissionExecuteState
 */
@property (nonatomic) AUTELMissionExecuteState execState;

/**
*  延时摄影任务状态
*/
@property (nonatomic) AUTELCameraDelayShotStatus delayShotStatus;

/**
*  已拍照时长，单位秒
*/
@property (nonatomic) NSUInteger photoTime;

/**
*  总的需要拍照的时长，单位秒
*/
@property (nonatomic) NSUInteger totalPhotoTime;

/**
*  已拍照张数
*/
@property (nonatomic) NSUInteger photoNum;

/**
*  总的需要拍照的张数
*/
@property (nonatomic) NSUInteger totalPhotoNum;

/**
*  定速巡航状态
*/
@property (nonatomic) AUTELCameraCruiseState cruiseState;

@end

/**
 *  This class includes hot point mission related functions.
 *
 *  延时摄影任务
 
 */

@interface AUTELDelayShotMission : AUTELMission<NSCopying>

//延时摄影类型
@property (nonatomic, assign) AUTELDelayShotMissionType timelapseType;

//定速巡航模式
@property (nonatomic, assign) AUTELCameraCruiseMode cruiseMode;

//水平最大速度， 单位 m/s
@property (nonatomic, assign) int hSpeed;

//垂直最大速度, 单位 m/s
@property (nonatomic, assign) int vSpeed;

//航向解旋转最大速度, 单位 m/s
@property (nonatomic, assign) int rSpeed;

//延时拍照总时长, 单位 s
@property (nonatomic, assign) int totalTime;

@property (nonatomic, assign) int missionId;//任务上报ID，APP用于上传下载识别

@property (nonatomic, assign) AUTELMissionType missionType;//任务类型

@end


NS_ASSUME_NONNULL_END



