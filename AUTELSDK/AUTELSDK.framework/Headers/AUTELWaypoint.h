//
//  AUTELWaypoint.h
//  AUTELSDK
//
//  Created by IOS on 15/12/22.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 *  Waypoint type
 *
 *  航点类型
 */
typedef NS_ENUM(NSUInteger, AUTELWaypointType) {
    /**
     *  @brief The flight path covers this waypoint.
     *
     *  飞机的飞行路径经过该航点
     */
    AUTELWaypointTypeApproved,
    /**
     *  @brief The aircraft flies around this waypoint.
     *
     *  飞机围绕该航点飞行
     */
    AUTELWaypointTypeCircle,
};

/**
 *  This class provides the info of waypoints
 *
 *  航线飞行任务中的航点
 */
@interface AUTELWaypoint : NSObject<NSCopying, NSCoding>

/**
 *  @brief Coordinate of the waypoint in degrees.
 *
 *  航点坐标
 */
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 *  @brief This property describes the altitude of aircraft is the relative altitude of the take off point when it reaches the waypoint. The value of altitude in meters. The valid range for the altitude is from -200m to 500m.
 *
 *  The altitude value must be smaller than maximum flight altitude. We can invoke [AUTELFlightLimitation getMaxFlightHeightWithCompletion:] and [AUTELFlightLimitation setMaxFlightHeight:withCompletion:] to read and write flight altitude limitation.
 *
 *  航点高度，该高度是相对于飞行器起飞点的高度，该高度范围为[-200, 500]，且不能高度飞行器的最大高度限制。通过 AUTELFlightLimitation 的 -getMaxFlightHeightWithCompletion: 方法和 -setMaxFlightHeight:withCompletion: 方法可以查询和修改飞行器最大飞行高度限制。
 *
 *  @see AUTELFlightLimitation
 */
@property(nonatomic, assign) float altitude;

/**
 *  @brief Hold time (s). The default holeTime is 0s.
 *
 *  停留时间（s），默认0s。
 */
@property(nonatomic, assign) float holdTime;

/**
 *  @brief Initial the waypoint object by using GPS coordinate.
 *
 *  用经纬度坐标来初始化航点对象
 *
 *  @param coordinate GPS coordinate.
 *
 *  经纬度坐标。
 *
 *  @return Target waypoint 
 *
 *  航点对象
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * @brief Compare the other waypoint with self.
 * 将另一个航点与自己进行比较
 *
 * @param object AUTELWaypoint type object.
 *
 * @return Boolean check.
 */
- (BOOL)isEqualToWaypoint:(id)object;

@end
