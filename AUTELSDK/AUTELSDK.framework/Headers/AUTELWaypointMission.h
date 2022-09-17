//
//  AUTELWaypointMission.h
//  AUTELSDK
//
//  Created by IOS on 15/12/22.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELFoundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELNavigation.h>
#import <AUTELSDK/AUTELMission.h>

/**
 *  misstion status
 *
 *  任务执行状态
 */
typedef NS_ENUM(uint8_t, WaypointMissionStatus) {
    /**
     *  @brief pause
     *
     *  悬停
     */
    WaypointMissionStatusPause,
    /**
     *  @brief running
     *
     *  执行中
     */
    WaypointMissionStatusRunning,
    /**
     *  @brief completed
     *
     *  完成
     */
    WaypointMissionStatusCompleted,
    /**
     *  @brief other:as defiens latter
     *
     *  其他
     */
    WaypointMissionStatusOther,
};

/**
 *  Waypoint task finish action
 *
 *  航点飞行任务结束工作
 */
typedef NS_ENUM(uint8_t, WaypointMissionFinishAction) {
    /**
     *  @brief Hover
     *
     *  悬停
     */
    WaypointMissionFinishActionHover,
    /**
     *  @brief go home
     *
     *  返航
     */
    WaypointMissionFinishActionGoHome
};

/**
 *  The executing state of the Waypoint task
 *
 *  航点飞行任务执行状态
 */
typedef NS_ENUM(uint8_t, AUTELWaypointMissionExecuteState) {
    /**
     *  @brief Initializing the task
     *
     *  任务正在初始化
     */
    AUTELWaypointMissionExecuteStateInitializing = 0,
    /**
     *  @brief Performing the Waypoint task.
     *
     *  航点飞行任务正在执行
     */
    AUTELWaypointMissionExecuteStateMoving = 1,
    /**
     *  @brief Waypoint task paused. Aircraft hovering.
     *
     *  航点飞行任务暂停，无人机悬停中
     */
    AUTELWaypointMissionExecuteStatePause = 2,
    /**
    *  @brief Waypoint task finish,go home.
    *
    *  航点飞行任务结束返航
    */
    AUTELWaypointMissionExecuteStateGoHome = 3,
    /**
    *  @brief Waypoint task finish,langding.
    *
    *  航点飞行任务结束，降落
    */
    AUTELWaypointMissionExecuteStateLanding = 4,
    
    /**
     *  @brief The Waypoint task is finished.
     *
     *  航点飞行任务执行完毕
     */
    AUTELWaypointMissionExecuteStateFinish = 5,
    /**
     *  @brief Waypoint task state unknown.
     *
     *  航点飞行任务状态未知。
     */
    AUTELWaypointMissionExecuteStateUnknown = 0xFF,
};

@class AUTELWaypoint;

/**
 *  Provides current waypoint mission status. 
 *
 *  当前航点飞行任务状态。
 */
@interface AUTELWaypointMissionStatus : AUTELMissionProgressStatus

///way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
@property (nonatomic, readonly) WaypointMissionStatus misstionStatus;

/**
*  @brief Remaining task time.
*
*  剩余任务时间。
*/
@property (nonatomic, readonly) NSInteger residualTime;

/**
*  @brief Length of remaining mission route.
*
*  剩余任务路线长度。
*/
@property (nonatomic, readonly) NSInteger residualDistance;

/**
*  @brief Current number of photos taken.
*
*  当前已拍照片张数。
*/
@property (nonatomic, readonly) NSInteger photoCount;
/**
 *  @brief Index of the waypoint which the aircraft is flying to.
 *
 *  无人机正在飞往的航点的下标。
 */
@property(nonatomic, readonly) NSInteger targetWaypointIndex;

/**
 *  @brief Current execution state of the aircraft.
 *
 *  无人机航点飞行任务的当前状态
 */
@property(nonatomic, readonly) AUTELWaypointMissionExecuteState execState;


/**
 *  @brief Whether or not the aircraft has reached a waypoint. Will return
 *  true if a waypoint has been reached.
 *
 *  无人机是否到达某一个航点，是的话返回 YES，否则返回 NO。
 */
@property(nonatomic, readonly) BOOL isWaypointReached;

/**
 *  @brief The speed of auto pilotion.
 *
 *  自动速度。
 */
@property (nonatomic, assign) float autoSpeed;

/**
 *  @brief Returns a boolean value indicates whether the aircraft is facing to the hot point.
 *
 *  返回飞行器机头方向是否朝向兴趣点
 *
 *  @discussion User can control the direction of aircraft head by calling AUTELNavigation.hotpointMissionHandler.facePOIWithCompletion: during the mission.
 *
 *  在飞行器执行环绕兴趣点任务过程中，用户可以用遥控器改变飞行器机头方向，你可以调用 AUTELNavigation.waypointMissionHandler 的 -facePOIWithCompletion: 方法让飞行器的机头朝向兴趣点。
 *
 *  @see AUTELNavigation
 *  @see AUTELWaypointMissionHandler
 */
@property (nonatomic, assign) BOOL isFaceToHead;



@end

/**
 *  @brief Waypoint mission
 *
 *  航点飞行任务
 */
@interface AUTELWaypointMission : AUTELMission<NSCopying>

/**
 *  @brief Number of waypoints in the waypoint mission, max number is 500.
 *
 *  航点飞行任务的航点数目，航点数目最大为500
 */
@property(nonatomic, readonly) int waypointCount;

/**
 *  @brief The horizontal speed of aircraft during the mission. It must be no more than 15m/s and smaller  than current maxFlightSpeed. Invoke AUTELFlightLimitation.getMaxFlightHorizontalSpeedWithCompletion and  setMaxFlightHorizontalSpeed:withCompletion methods to read and write maxFlightSpeed.
 *
 *  飞行器执行任务时的水平飞行速度，autoFlightSpeed 不能大于 15m/s，且不能大于飞行器的最大飞行速度。可通过 AUTELFlightLimitation
 *  的 -getMaxFlightHorizontalSpeedWithCompletion: 和 -setMaxFlightHorizontalSpeed:withCompletion: 方法查询和修改飞行器最大飞行速度。
 *
 *  @see AUTELFlightLimitation
 */
@property(nonatomic, assign) float autoFlightSpeed;

/**
 *  @brief Set the mode after mission finished.
 *
 *  任务结束模式，默认 AUTELNavigationMissionFinishModeGoHome。
 *
 *  @discussion If finishMode equals to AUTELNavigationMissionFinishModeGoHome, then the aircraft will fly back to the home point after mission completed.
 *  If finishMode equals AUTELNavigationMissionFinishModeHover, then the aircraft will hover in the air after mission completed.
 *  The finishMode can not be set to AUTELNavigationMissionFinishModeHover.
 *
 *  如果 finishMode 等于 AUTELNavigationMissionFinishModeGoHome，飞行器执行完该任务后，会自动返航。
 *  如果 finishMode 等于 AUTELNavigationMissionFinishModeHover，飞行器在完成任务后原地悬停。
 *  不能将 finishMode 设置为 AUTELNavigationMissionFinishModeGoHotPoint。
 *
 *  @see AUTELNavigationMissionFinishMode
 *  @see AUTELMissionHandler
 */
@property (nonatomic) AUTELNavigationMissionFinishMode finishMode;

/**
 *  @brief Go home altitude is the relative altitdue of take off point, its default value is 30m.
 *
 *  返航高度（m），该高度是相对于起飞点的相对高度，默认30m。
 *
 *  @discussion After mission completed, If current altitude of aircraft is not highter than go home altitdue, aircraft will ascend to go home altitdue and then enter into finish mode.
 *
 *  飞行器执行完该任务后，如果此时飞行器的高度大于 goHomeAltitude，飞行器将按照 finishMode 执行结束动作，否则将先上升到 goHomeAltitude 高度在执行结束动作。
 */
@property (nonatomic) float goHomeAltitude;

/**
 *  @brief estMissionTime is approximation time for mission to complete.
 * 
 *  @discussion estimated Mission Time is computed based out of each waypoint lat-long, altitude and hover time.
 *  Here, drone max speed is considered as 5m/sec.
 */
@property (nonatomic, assign) double estMissionTime;

/**
 *  @brief Adds a waypoint to waypoint mission. The maximum number of waypoints is 99.
 *
 *  添加一个航点到航点飞行任务，航点最大数目不能超过99。
 *
 *  @param Waypoint to be added to the waypoint mission. 
 *
 *  添加到航点飞行任务的航点。
 */
- (void)addWaypoint:(AUTELWaypoint*)waypoint;

/**
 *  @brief Adds an array of waypoints to the waypoint mission.
 *
 *  添加一组航点到航点飞行任务。
 *
 *  @param waypoints The array of waypoints to be added to waypoint mission.
 *
 *  添加到航点飞行任务的航点数组。
 */
- (void)addWaypoints:(NSArray*)waypoints;

/**
 *  @brief Removes a waypoint from waypoint mission.
 *
 *  移除一个已经添加到航点飞行任务的航点。
 *
 *  @param waypoint Waypoint object to be removed.  
 *
 *  要移除的航点。
 */
- (void)removeWaypoint:(AUTELWaypoint*)waypoint;

/**
 *  @brief Removes a waypoint at the index of the waypoin array from waypoint mission.
 *
 *  移除已添加的第index个航点。
 *
 *  @param index Index of waypoint to be removed from the waypoint mission from
 *  the array of all waypoints.
 *
 *  将要被移除航点在已添加航点数字组中的位置。
 */
- (void)removeWaypointAtIndex:(int)index;

/**
 *  @brief Removes all waypoints from the waypoint mission. 
 *  
 *  删除所有航点。
 */
- (void)removeAllWaypoints;

/**
 *  @brief  Gets a waypoint at the index of the waypoint array from waypoint mission.
 *
 *  获取第index个添加到飞行任务中的航点。
 *
 *  @param index Index of the waypoint wanting to be retrieved from the array of waypoints in the
 *  waypoint mission.
 *
 *  需要获取的航点的下标。
 *
 *  @return Waypoint of type AUTELWaypoint if the index exists. 
 *
 *  获取到的航点
 */
- (AUTELWaypoint*)getWaypointAtIndex:(int)index;


/// return waypoints number
/// 航点个数
- (int)waypointCount;

@end
