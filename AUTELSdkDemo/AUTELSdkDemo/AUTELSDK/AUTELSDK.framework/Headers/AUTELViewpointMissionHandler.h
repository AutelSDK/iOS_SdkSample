//
//  AUTELViewpointMissionHandler.h
//  AUTELSDK
//
//  Created by ChenYuanliang on 2018/4/7.
//  Copyright © 2018年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELMissionHandler.h>
#import <AUTELSDK/AUTELFlightAssistant.h>

/**
 *  The executing state of the Waypoint task
 *
 *  航点飞行任务执行状态
 */
typedef NS_ENUM(uint8_t, AUTELViewpointMissionExecuteState) {
    /**
     *  @brief enter the task
     *
     *  进入任务
     */
    AUTELViewpointMissionExecuteStateEnter,
    /**
     *  @brief Initializing the task
     *
     *  任务正在初始化
     */
    AUTELViewpointMissionExecuteStateInitializing,
    /**
     *  @brief Performing the Waypoint task.
     *
     *  航点飞行任务正在执行
     */
    AUTELViewpointMissionExecuteStateMoving,
    /**
     *  @brief Waypoint task paused. Aircraft hovering.
     *
     *  航点飞行任务暂停，无人机悬停中
     */
    AUTELViewpointMissionExecuteStatePause,
    /**
     *  @brief The Waypoint task is finished.
     *
     *  航点飞行任务执行完毕
     */
    AUTELViewpointMissionExecuteStateFinish,
    /**
     *  @brief Waypoint task state unknown.
     *
     *  航点飞行任务状态未知。
     */
    AUTELViewpointMissionExecuteStateUnknown = 0xFF,
};

@interface AUTELViewpointMissionState: AUTELMissionProgressStatus<NSCopying> {
    
}

//水平线索引比例
@property (nonatomic, assign) float pointflyHorizon;
//上禁止线索引比例
@property (nonatomic, assign) float pointflyLimitTop;
//下禁止线索引比例
@property (nonatomic, assign) float pointflyLimitBottom;

@property (nonatomic, assign) float flightAngle;

@property (nonatomic, assign) float flightSpeed;

@property (nonatomic, assign) float scaleX;

@property (nonatomic, assign) float scaleY;

// 正在绕行
@property (nonatomic, assign) BOOL isBypassingObstacles;

@property (nonatomic, assign) AUTELBypassState bypassState;

// 无法绕行
@property (nonatomic, assign) BOOL isCanNotBypassObstacles;

// 飞行器高度过低
@property (nonatomic, assign) BOOL isAltitudeTooLow;

@property (nonatomic, assign) AUTELViewpointMissionExecuteState execState;

@end

@protocol AUTELViewpointMissionHandler <AUTELMissionHandler>

- (void)setViewpointAutoFlightSpeed:(float)speed withCompletion:(AUTELCompletionBlock)block;

- (void)setViewpointAutoFlightAngle:(float)angle withCompletion:(AUTELCompletionBlock)block;

- (void)setViewpointHorizontalFOV:(float)hAngle
                  withVerticalFOV:(float)vAngle
                   withCompletion:(AUTELCompletionBlock)block;

- (void)setViewpointScaleX:(float)x
                withScaleY:(float)y
            withCompletion:(AUTELCompletionBlock)block;

- (void)setViewpointScaleX:(float)x
                withScaleY:(float)y
           withFlightAngle:(float)angle
            withCompletion:(AUTELCompletionBlock)block;

- (void)enterViewpointMissionModeWithCompletion:(AUTELCompletionBlock)completion;

- (void)setViewpointResolutionWithCompletion:(AUTELCompletionBlock)block;

@end
