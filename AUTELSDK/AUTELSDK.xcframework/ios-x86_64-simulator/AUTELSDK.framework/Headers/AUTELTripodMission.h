//
//  AUTELTripodMission.h
//  AUTELSDK
//
//  Created by zhiganglet on 2019/7/25.
//  Copyright © 2019 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AUTELSDK/AUTELFoundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELNavigation.h>


NS_ASSUME_NONNULL_BEGIN


/**
 *  This class allowed user get real-time status of one Precision mission. The aircraft follows the coordinate sent by AUTELNavigation.updateUserCoordinate method.
 *
 *  精准飞行任务实时状态，当飞行器在执行精准飞行任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELTripodMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execute state of the one shot video mission.
 *
 *  一键短片任务执行状态
 *
 *  @see AUTELMissionExecuteState
 */
@property (nonatomic, readonly) AUTELMissionExecuteState execState;

@end

/**
 *  This class includes Precision mission related functions.
 *
 *  精准飞行任务
 
 */

@interface AUTELTripodMission : AUTELMission<NSCopying>

/**
 *  @brief Set the mode after mission finished.
 *
 *  任务结束模式，默认 AUTELNavigationMissionFinishModeGoHome。
 *
 *  @discussion If finishMode equals to AUTELNavigationMissionFinishModeGoHome, then the aircraft will fly back to the home point after mission completed.
 *  If finishMode equals to AUTELNavigationMissionFinishModeGoHotPoint, then the aircraft will fly to the hot point after mission completed.
 *  If finishMode equals AUTELNavigationMissionFinishModeHover, then the aircraft will hover in the air after mission completed.
 *
 *  如果 finishMode 等于 AUTELNavigationMissionFinishModeGoHome，飞行器执行完该任务后，会自动返航。
 *  如果 finishMode 等于 AUTELNavigationMissionFinishModeGoHotPoint，飞行器在完成该任务后，会自动飞行到兴趣点上方。
 *  如果 finishMode 等于 AUTELNavigationMissionFinishModeHover，飞行器在完成任务后原地悬停。
 *
 *  @see AUTELNavigationMissionFinishMode
 *  @see AUTELMissionHandler
 */
@property (nonatomic) AUTELNavigationMissionFinishMode finishMode;

//水平最大速度， 单位 m/s
@property (nonatomic, assign) int hSpeed;

//垂直最大速度, 单位 m/s
@property (nonatomic, assign) int vSpeed;

//航向解旋转最大速度, 单位 m/s
@property (nonatomic, assign) int rSpeed;

@property (nonatomic, assign) int missionId;//任务上报ID，APP用于上传下载识别

@end


NS_ASSUME_NONNULL_END



