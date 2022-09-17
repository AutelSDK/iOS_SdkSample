//
//  AUTELVisionOrbitMissionHandler.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/5/12.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AUTELSDK/AUTELVisionOrbitMission.h>
#import <AUTELSDK/AUTELCameraDef.h>

@protocol AUTELVisionOrbitMissionHandler <NSObject>

@property (nonatomic, readonly) BOOL isRunning;

- (void)enterMissionModeWithCompletion:(AUTELCompletionBlock)block;

- (void)startMissionWithCompletion:(AUTELCompletionBlock)block;

- (void)stopMissionWithCompletion:(AUTELCompletionBlock)block;

- (void)exiteMissionWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Pauses the current mission being executed and the aircraft will hover in its current location. Current state
 *  will be saved until resumeMissionExecutionWithCompletion is called.
 *
 *  暂停当前飞行任务，无人机会在当前位置悬停。当前状态会被保存，直到调用 -resumeMissionExecutionWithCompletion:completion 恢复飞行任务。
 *
 *  @param completion Completion block. 命令结束回调
 */
- (void)pauseMissionWithCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Resumes the currently paused mission.
 *
 *  恢复当前被暂停的飞行任务。
 *
 *  @param completion Completion block.
 *
 *  命令结束回调。
 */
- (void)resumeMissionWithCompletion:(AUTELCompletionBlock)completion;

/**
*  @brief Set the target coordinates of the vision orbit frame selection.
*
*  设置视觉环绕框选目标坐标。
*
*  @param completion Completion block.
*
*  命令结束回调。
*/
- (void)setOrbitModeGoalArea:(CGRect)area withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Set the vision orbit parameters.
*
*  设置视觉环绕参数。
*
*  @param completion Completion block.
*
*  命令结束回调。
*/
- (void)setOrbitModeInfo:(AUTELVisionOrbitMission *)mission withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief aircraft and gimbal orientation reset.
*
*  飞机和云台的方向回中。
*
*  @param completion Completion block.
*
*  命令结束回调。
*/
- (void)resetOrientationCompletion:(AUTELCompletionBlock)block;

@end


