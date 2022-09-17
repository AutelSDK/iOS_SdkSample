//
//  AUTELGen2WaypointMission.h
//  AUTELSDK
//
//  Created by ChenYuanliang on 2018/4/24.
//  Copyright © 2018年 Autel. All rights reserved.
//

#import "AUTELWaypointMission.h"

@class AUTELWaypointG2;

/**
*  @brief Waypoint mission,Inherit the AUTELWaypointMission class
*
*  航点飞行任务
*/
@interface AUTELGen2WaypointMission : AUTELWaypointMission

/**
*  @brief Add a  waypoint to the waypoint mission.
*
*  添加一个航点到航点飞行任务。
*
*  @param waypoint The waypoint to be added to waypoint mission.
*
*  添加到航点飞行任务的航点。
*/
- (void)addGen2Waypoint:(AUTELWaypointG2 *)waypoint;

/**
 *  @brief Adds an array of waypoints to the waypoint mission.
 *
 *  添加一组航点到航点飞行任务。
 *
 *  @param waypoints The array of waypoints to be added to waypoint mission.
 *
 *  添加到航点飞行任务的航点数组。
 */
- (void)addGen2Waypoints:(NSArray<AUTELWaypointG2 *>*)waypoints;

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
- (AUTELWaypointG2*)getGen2WaypointAtIndex:(int)index;



@end
