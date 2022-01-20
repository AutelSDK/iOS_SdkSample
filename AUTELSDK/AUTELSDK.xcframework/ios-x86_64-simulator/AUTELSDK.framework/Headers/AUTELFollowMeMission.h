//
//  AUTELFollowMeMission.h
//  AUTELSDK
//
//  Created by IOS on 16/3/28.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELNavigation.h>

/**
 *  State of the Follow task
 *
 *  追踪飞行任务行动状态
 */
typedef NS_ENUM(uint8_t, AUTELFollowMeMissionExecuteState) {
    /**
     *  @brief Initializing Follow task
     *
     *  正在初始化追踪飞行任务
     */
    AUTELFollowMeMissionExecuteStateInitializing,
    /**
     *  @brief Performing Follow task
     *
     *  正在执行飞行任务
     */
    AUTELFollowMeMissionExecuteStateMoving,
    /**
     *  @brief Performing Follow task. The aircraft is hovering for GPS uploading.
     *
     *  追踪飞行任务执行中。飞行器正在悬停，等待GPS上传。
     */
    AUTELFollowMeMissionExecuteStateWaiting,
    /**
     *  @brief Follow task finished
     *
     *  追踪飞行任务完毕
     */
    AUTELFollowMeMissionExecuteStateFinish,
    /**
     *  @brief Follow task state unknown
     *
     *  追踪飞行任务状态未知
     */
    AUTELFollowMeMissionExecuteStateUnknown = 0xFF,
};

/**
 *  This class allowed user to get real-time status of follow me mission. Gets real-time status of mission by calling AUTELNavigationDelegate onNavigationMissionStatusChanged method during the mission.
 *
 *  追踪飞行任务的实时状态，当飞行器在执行追踪任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 */
@interface AUTELFollowMeMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execution state of the follow me mission.
 *
 *  返回任务执行状态
 *
 *  @see AUTELFollowMeMissionExecuteState
 */
@property(nonatomic, readonly) AUTELFollowMeMissionExecuteState execState;

@end

/**
 *  This class contains the properties of follow me mission. The aircraft follows the coordinate sent by AUTELNavigation.updateUserCoordinate method.
 *
 *  该类存储追踪飞行任务数据。当飞行器执行追踪任务时，App 通过 AUTELNavigation 的 updateUserCoordinate 方法
 *  向飞行器发送追踪位置，飞行器将随着追踪位置移动而移动。
 */
@interface AUTELFollowMeMission : AUTELMission<NSCopying>

/**
 *  @brief Return mode after mission finished. It’s default value is AUTELNavigationMissionFinishModeGoHome.
 *
 *  任务结束模式，默认 AUTELNavigationMissionFinishModeGoHome。
 *
 *  @discussion  After mission completed, aircraft returns to home point if finishMode equals to AUTELNavigationMissionFinishModeGoHome. 
 *  Else if finishMode equals to AUTELNavigationMissionFinishModeGoHotPoint, then aircraft hovers above the hot point after mission completed. 
 *  Hot point can be sent by [AUTELNavigation updateUserCoordinate] method. The finishMode can not be set to AUTELNavigationMissionFinishModeHover, or it will cause the failure of applying -prepareMission:withProgress:withCompletion method and -checkMission method.
 *
 *  finishMode 如果等于 AUTELNavigationMissionFinishModeGoHome，飞行器执行完该任务后，会自动返航。
 *  如果 finishMode 如果等于 AUTELNavigationMissionFinishModeGoHotPoint，飞行器在完成该任务后，会自动飞行追踪点上方，
 *  追踪点通过 AUTELNavigation 的 updateUserCoordinate 方法向飞行器发送追踪位置。
 *  不能将 finishMode 设置为 AUTELNavigationMissionFinishModeHover
 *  否则调用 -prepareMission:withProgress:withCompletion: 方法上传任务到飞行器时会失败，
 *  调用 -checkMission 方法检查任务数据是否合法时也将失败。
 *
 *  @see AUTELNavigationMissionFinishMode
 *  @see AUTELMissionHandler
 *  @see AUTELNavigation
 */
@property (nonatomic) AUTELNavigationMissionFinishMode finishMode;

/**
 *  @brief Go home altitude has a default value 30m. The value of go hom altitude is the relative altitude of the take off point.
 *
 *  返航高度，该高度是相对于起飞点的相对高度，默认30m。
 *
 *  @discussion After mission completed, If current altitude of aircraft is not highter than go home altitdue, aircraft will ascend to go home altitdue and then enter into finish mode.
 *
 *  飞行器执行完该任务后，如果此时飞行器的高度大于 goHomeAltitude，飞行器将按照 finishMode 执行结束动作，否则将先上升到 goHomeAltitude 高度,然后执行结束动作。
 */
@property (nonatomic) float goHomeAltitude;

@end
