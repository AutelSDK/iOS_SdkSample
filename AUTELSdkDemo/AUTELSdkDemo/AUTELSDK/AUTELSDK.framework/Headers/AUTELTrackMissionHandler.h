//
//  AUTELTrackMissionHandler.h
//  AUTELSDK
//
//  Created by ChenYuanliang on 2018/2/11.
//  Copyright © 2018年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELSmartTrackDef.h>

@class AUTELTrackMission;

typedef NS_ENUM(NSInteger, AUTELTrackMissionStep) {
    /**
    *  @brief Movidos waits to enter tracking mode.
    *
    *  Movidos 等待进入追踪模式
    */
    AUTELTrackMissionStepWaitEnterTrackMode,

    /**
    *  @brief Movidos enters tracking mode.
    *
    *  Movidos 进入追踪模式
    */
    AUTELTrackMissionStepEnterTrackMode,
    
    /**
    *  @brief Movidos enters tracking mode, ie the camera will rotate as the target moves, but the aircraft does not enter tracking mode.
    *
    *  Movidos 进入追踪模式, 即相机会随着目标的移动而转动，但飞机没有进入追踪模式
    */
    AUTELTrackMissionStepCameraTracking,
    
    /**
    *  @brief Movidos and aircraft have entered tracking mode.
    *
    *  Movidos 和飞行器都进入了追踪模式
    */
    AUTELTrackMissionStepEnterAircraftTracking,
    
    // 追踪暂停
    /**
    *  @brief Movidos and aircraft have entered tracking mode.
    *
    *  Movidos 和飞行器都进入了追踪模式
    */
    AUTELTrackMissionStepTrackPaused,
    
    /**
    *  @brief Has exited tracking.
    *
    *  已退出追踪
    */
    AUTELTrackMissionStepExitTrack,
    
    /**
    *  @brief Target lost, unique state of gesture recognition.
    *
    *  目标丢失，手势识别独有状态
    */
    AUTELTrackMissionStepLostTarget,
};

typedef NS_ENUM(NSInteger, AUTELTrackState) {
    AUTELTrackStateFaile = 0,
    AUTELTrackStateSuccess = 1,
    AUTELTrackStateCredibility = 2,
    AUTELTrackStateTargetFrameSmall,
    AUTELTrackStateTargetFrameBig,
    AUTELTrackStateNoTargetInFrame,
    AUTELTrackStateOther,
    AUTELTrackStateUnknown = -1,
};

@interface AUTELTrackMissionState: AUTELMissionProgressStatus {
    
}

//追踪模式
@property (nonatomic, assign) AUTELSmartTrackMode trackMode;

@property (nonatomic) AUTELTrackMissionStep missionState;
@property (nonatomic) CGRect targetRect;
@property (nonatomic) AUTELSmartTrackTargetType targetType;
@property (nonatomic) AUTELTrackState trackState;

// 光照状态
@property (nonatomic) AUTELTrackingAmbientLightState lightState;
// 正在绕行
@property (nonatomic) BOOL isBypassWhileTracking;

// 无法绕行
@property (nonatomic) BOOL isCanNotBypassWhileTracking;

@property (nonatomic) BOOL isNoFrontWayTurnAround;

// 飞行器高度过低
@property (nonatomic) BOOL isAltitudeTooLow;

// 飞行器到达最小距离
@property (nonatomic) BOOL isReachMinimumTrackingRadius;

// 飞行器到达最大距离
@property (nonatomic) BOOL isReachMaximumTrackingRadius;

// 飞行器到达最大高度
@property (nonatomic) BOOL isReachMinimumTrackingAltitude;

// 飞行器到达最小高度
@property (nonatomic) BOOL isReachMaximumTrackingAltitude;

// 追踪目标晃动
@property (nonatomic) BOOL isTrackingTargetShake;

// 追踪未知错误
@property (nonatomic) BOOL isTrackingUnknownError;

@property (nonatomic) BOOL isDymanicTrackPaused;

@property (nonatomic) BOOL isExitDymanicTrack;

@end


@interface AUTELGestureMissionState: AUTELMissionProgressStatus {
    
}

@property (nonatomic) AUTELTrackMissionStep missionState;
@property (nonatomic) CGRect targetRect;
@property (nonatomic) AUTELSmartTrackTargetType targetType;
@property (nonatomic) AUTELTrackState trackState;

// 光照状态
@property (nonatomic) AUTELTrackingAmbientLightState lightState;
// 正在绕行
@property (nonatomic) BOOL isBypassWhileTracking;

// 无法绕行
@property (nonatomic) BOOL isCanNotBypassWhileTracking;

@property (nonatomic) BOOL isNoFrontWayTurnAround;

// 飞行器高度过低
@property (nonatomic) BOOL isAltitudeTooLow;

// 飞行器到达最小距离
@property (nonatomic) BOOL isReachMinimumTrackingRadius;

// 飞行器到达最大距离
@property (nonatomic) BOOL isReachMaximumTrackingRadius;

// 飞行器到达最大高度
@property (nonatomic) BOOL isReachMinimumTrackingAltitude;

// 飞行器到达最小高度
@property (nonatomic) BOOL isReachMaximumTrackingAltitude;

// 追踪目标晃动
@property (nonatomic) BOOL isTrackingTargetShake;

// 追踪未知错误
@property (nonatomic) BOOL isTrackingUnknownError;

@property (nonatomic) BOOL isDymanicTrackPaused;

@property (nonatomic) BOOL isExitDymanicTrack;

@end

@protocol AUTELTrackMissionHandler <NSObject>

@property (nonatomic, readonly) BOOL isRunning;

/**
*  @brief Enter tracking mode.
*
*  进入追踪模式。
*
*  @param block Completion block. 命令结束回调
*/
- (void)enterTrackMissionModeWithCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Configure the tracking task parameters. After the interface succeeds, you need to call setSmartTrackMode to let the vision and aircraft start tracking.
*
*  配置追踪任务参数，该接口成功后，需要马上调用setSmartTrackMode让视觉、飞机开始追踪。
*
*  @param mission mission parameter. 任务参数
*  @param block Completion block. 命令结束回调
*  @see AUTELTrackMission
*/
- (void)startTrackMission:(AUTELTrackMission *)mission
           withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Stop tracking and return to detection target mode.
*
*  停止追踪，回到检测目标模式。
*
*  @param block Completion block. 命令结束回调
*/
- (void)stopTrackMissionWithCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Set the tracking mode, set the successful vision, and the aircraft will start tracking.
*
*  设置追踪模式，设置成功视觉、飞机都开始追踪。
*
*  @param block Completion block. 命令结束回调
*/
- (void)setSmartTrackMode:(AUTELSmartTrackMode)trackMode
           withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Exit tracking mode.
*
*  退出追踪模式。
*
*  @param block Completion block. 命令结束回调
*/
- (void)exiteTrackMissionWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Pauses the current mission being executed and the aircraft will hover in its current location. Current state
 *  will be saved until resumeMissionExecutionWithCompletion is called.
 *
 *  暂停当前飞行任务，无人机会在当前位置悬停。当前状态会被保存，直到调用 -resumeMissionExecutionWithCompletion:completion 恢复飞行任务。
 *
 *  @param completion Completion block. 命令结束回调
 */
- (void)pauseMissionExecutionWithCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Resumes the currently paused mission.
 *
 *  恢复当前被暂停的飞行任务。
 *
 *  @param completion Completion block.
 *
 *  命令结束回调。
 */
- (void)resumeMissionExecutionWithCompletion:(AUTELCompletionBlock)completion;

@end
