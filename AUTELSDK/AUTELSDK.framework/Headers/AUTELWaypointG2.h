//
//  AUTELWaypointG2.h
//  AUTELSDK
//
//  Created by Devin on 2018/1/23.
//  Copyright © 2018年 Autel. All rights reserved.
//

#import "AUTELWaypoint.h"

/**
*  Define Waypoint Style
*
*  定义航点类型
*/
typedef NS_ENUM(int, AUTELWaypointStyle) {
    /**
     *  @brief fly over
     *
     *  飞越。
     */
    AUTELWaypointStyleNormal = 0,
    
    /**
     *  @brief Orbit
     *
     *  环绕。
     */
    AUTELWaypointStyleOrbit = 1,
    
    /**
     *  @brief Cylinder
     *
     *  Cylinder。
     */
    AUTELWaypointStyleCylinder = 2,
    
    /**
     *  @brief Panorama
     *
     *  Panorama。
     */
    AUTELWaypointStylePanorama = 3,
    
    /**
     *  @brief Mapping
     *
     *  测绘点。
     */
    AUTELWaypointStyleMapping = 9,
    
    /**
     *  @brief emergency land
     *
     *  应急降落点。
     */
    AUTELWaypointStyleEmergencyLand = 10,
    
    /**
     *  @brief Hover
     *
     *  悬停。
     */
    AUTELWaypointStyleHover = 12,
    
    /**
    *  @brief Unknown
    *
    * 未知。
    */
    AUTELWaypointStyleUnknown
};

/**
*  Define Waypoint Altitude Priority Mode
*
*  定义航点高度优先模式
*/
typedef NS_ENUM(int, AUTELWaypointAltitudePriorityMode) {
    /**
     *  @brief Altitude priority mode is disabled, the aircraft will ascend (or descend) to the next waypoint altitude along with the flight.
     *
     *  高度优先模式关闭，飞行器将随着飞行提升（或下降）到下一个航点高度。
     */
    AUTELWaypointAltitudePriorityModeOff,
    /**
     *  @brief Altitude priority mode is turned on, the aircraft will first ascend (or descend) to the next waypoint altitude, and then fly to the next waypoint.
     *
     *  高度优先模式打开，飞行器将先提升（或下降）到下一个航点高度，再飞向下一个航点。
     */
    AUTELWaypointAltitudePriorityModeOn,
};

/**
*  Define Waypoint Heading Mode
*
*  定义航点朝向模式
*/
typedef NS_ENUM(int, AUTELWaypointHeadingMode) {
    /**
     *  @brief Avoidance is invalid
     *
     *  无效模式。
     */
    AUTELWaypointHeadingModeInvalid = 0,
    /**
     *  @brief Avoidance is toward next waypoint
     *
     *  朝向下一个航点。
     */
    AUTELWaypointHeadingModeTowardsNext = 1,
    /**
     *  @brief Keep the initial heading.
     *
     *  保持初始航向。
     */
    AUTELWaypointHeadingModeInitial = 2,
    /**
     *  @brief Towards a user-defined direction.
     *
     *  朝向用户定义的方向。
     */
    AUTELWaypointHeadingModeCustom = 3,
    /**
     *  @brief Avoidance is freedom
     *
     *  自由朝向，用用户控制，响应用户打杆
     */
    AUTELWaypointHeadingModeFreedom = 4,
};


/**
 *  该类描述航点信息.
 *
 *  This class contains information about a Waypoint.
 */
@interface AUTELWaypointG2 : AUTELWaypoint

/**
 *  @brief Waypoint index subscript
 *
 *  航点索引下标。
 */
@property (nonatomic) int waypointIndex;
/**
 *  @brief The identifier of the task is a 32-bit integer
 *
 *  任务的标识，为32位整型。
 */
@property (nonatomic) int missionId;
/**
 *  @brief The identifier of the waypoint is a 32-bit integer
 *
 *  航点的标识，为32位整型。
 */
@property (nonatomic) int waypointId;
/**
 *  @see AUTELWaypointStyle
 *
 *  航点类型。
 */
@property (nonatomic) AUTELWaypointStyle style;

/**
 *  @brief Speed
 *
 *  速度。
 */
@property (nonatomic) float speed;

/**
 *  @brief Focus point coordinates.
 *
 *  聚焦点坐标。
 */
@property (nonatomic) CLLocationCoordinate2D focusCoordinate;
/**
 *  @brief Focus point height.
 *
 *  聚焦点高度。
 */
@property (nonatomic) float focusAltitude;
/**
 *  @brief Avoidance is invalid
 *
 *  为非负数时为贝塞尔模式半径，单位米；否则的话，0：关闭贝塞尔模式，自动选择最小角度转向；-1：关闭贝塞尔模式，并且逆时针转向；-2：关闭贝塞尔模式，并且顺时针转向。
 */
@property (nonatomic) int beizerParam;
/**
 *  @see AUTELWaypointAltitudePriorityMode, High priority mode.
 *
 *  高度优先模式。
 */
@property (nonatomic) AUTELWaypointAltitudePriorityMode altitudePriorityMode;
/**
 *  @see AUTELWaypointHeadingMode
 *
 *  机头朝向。
 */
@property (nonatomic) AUTELWaypointHeadingMode headingMode;
/**
 *  @brief Customize the nose orientation angle.
 *
 *  自定义机头朝向角度。
 */
@property (nonatomic) float userDefinedHeading;
/**
 *  @brief The pitch angle of the camera, that is, the pitch angle of the gimbal.
 *
 *  相机pitch角度，即云台俯仰角。
 */
@property (nonatomic) float cameraPitch;
/**
 *  @brief Camera yaw angle.
 *
 *  相机yaw角度。
 */
@property (nonatomic) float cameraYaw;
/**
 *  @brief number of actions.
 *
 *  动作数量。
 */
@property (nonatomic) float actionCount;

@end


