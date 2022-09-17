//
//  AUTELWaypointGMC.h
//  AUTELSDK
//
//  Created by zhiganglet on 2019/7/19.
//  Copyright © 2019 Autel. All rights reserved.
//

#import "AUTELWaypointG2.h"


/**
*  Define Waypoint Action Type
*
*  定义航点动作类型
*/
typedef NS_ENUM(int, AUTELWaypointActionType) {
    /**
     *  @brief Invalid
     *
     *  无效动作。
     */
    AUTELWaypointActionTypeInvalid = 0,
    
    /**
     *  @brief TakePhoto
     *
     *  拍照。
     */
    AUTELWaypointActionTypeTakePhoto = 1,
    
    /**
     *  @brief Start Video Record
     *
     *  开始录像
     */
    AUTELWaypointActionTypeStartRecordVideo = 2,
    
    /**
     *  @brief Stop Video Record
     *
     *  停止录像
     */
    AUTELWaypointActionTypeStopRecordVideo = 3,
    
    /**
     *  @brief TakePhoto Interval
     *
     *  定时拍
     */
    AUTELWaypointActionTypeTimeInterval = 11,
    
    /**
     *  @brief TakePhoto Distance
     *
     *  定距拍
     */
    AUTELWaypointActionTypeDistance= 12,
    
    /**
    *  @brief Unknown
    *
    * 未知。
    */
    AUTELWaypointActionTypeUnknown = 0xff
};



NS_ASSUME_NONNULL_BEGIN


/// AUTELCoordinate3D
@interface AUTELCoordinate3D : NSObject

/// latitude
/// 纬度
@property (nonatomic) CLLocationDegrees latitude;//纬度

/// longitude
/// 经度
@property (nonatomic) CLLocationDegrees longitude;//经度

/// altitude
/// 高度
@property (nonatomic) CLLocationDegrees altitude;//高度

@end

/// Interest Point Model
/// 插入 Point Model
@interface InterestPointModel : NSObject
/// coord
/// 坐标
@property (nonatomic, strong) AUTELCoordinate3D *coord;

/// index
/// index
@property (nonatomic) int index;//id

@end


/**
*  Waypoint action parameter.
The first parameters are gimbal pitch and yaw angle.
If waypoint type is over flight, the camera action can be 0 or 1 group. Every group actions are as below: If camera action is shooting, recording, no parameter will add; if camera action is timed shooting or fixed-distance shooting, parameter will add.
If the waypoint type is hovering, the camera action can be 0 or multiple groups. Every group definition is below: if camera action is nothing, no parameter will add; if camera action is recording, one parameter will add (recording time); if camera action is timed shooting, two parameters will add (shooting intervals and shooting time).
*
*  航点动作参数。
前两个参数固定是云台俯仰角和偏航角。
若航点类型是飞越，相机动作有0或1组：若是拍照、录像，没有参数增加；相机动作是定时拍照或定距拍照，有一个参数增加（对应定时间隙和拍照间距）；
若航点类型是悬停，相机动作可以是0到多组：相机动作是无，则无参数增加；相机动作是录像，则有一个参数增加（录像时长）；相机动作是定时拍照，有2个参数增加（拍照间隙和拍照时长）；
*/
@interface AUTELWaypointActionPara : NSObject

/**
 *  @brief camera Pitch
 *
 *  云台俯仰角，参数范围：0到90
 */
@property (nonatomic) float cameraPitch;

/**
 *  @brief camera Yaw
 *
 *  偏航角
 */
@property (nonatomic) float cameraYaw;

/**
 *  @brief camera roll
 *
 *  roll角
 */
@property (nonatomic) float cameraRoll;

/**
 *  @brief actionTimeout
 *
 *  定时拍照间隔（单位s）
 */
@property (nonatomic) float timeInterval;

/**
 *  @brief timeInterval Time Duration
 *
 *  定时拍照总时长（单位s）
 */
@property (nonatomic) float timeIntervalTimeDuration;

/**
 *  @brief distance Interval
 *
 *  定距拍照间隔（单位m）
 */
@property (nonatomic) float distanceInterval;

/**
 *  @brief record Video Time Duration
 *
 *  录像时长（单位s）
 */
@property (nonatomic) float recordVideoTimeDuration;

/**
 *  @brief hover Time Duration
 *
 *  悬停时长（单位s）
 */
@property (nonatomic) float hoverTimeDuration;

/**
 *  @brief camera zoom
 *
 *  相机变焦倍数，默认是1
 */
@property (nonatomic) float cameraZoom;

@end

/**
 *  This class contains information about a Waypoint action.
 *
 *  该类描述航点动作信息.
 */
@interface AUTELWaypointAction : NSObject

/**
 *  @brief actionId
 *
 *  当前动作标识
 */
@property (nonatomic) int actionId;

/**
 *  @brief actionType
 *
 *  航点动作类型
 */
@property (nonatomic) AUTELWaypointActionType actionType;

/**
 *  @brief actionTimeout
 *
 *  航点动作超时时长，单位秒
 */
@property (nonatomic) float actionTimeout;

/**
 *  @brief actionParas
 *
 *  航点动作参数列表。
 */
@property (nonatomic, strong) AUTELWaypointActionPara *actionPara;

@end


/**
 *  This class contains information about a Waypoint.
 *
 *  该类描述航点信息.
 */
@interface AUTELWaypointMC : AUTELWaypointG2


/**
 *  @brief ground lap
 *
 *  地面重叠率
 */
@property (nonatomic) float groundlap;
/**
 *  @brief heading lap
 *
 *  航向重叠率
 */
@property (nonatomic) float headinglap;
/**
 *  @brief side lap
 *
 *  旁向重叠率
 */
@property (nonatomic) float sidelap;
/**
 *  @brief head angle
 *
 *  主航向角度
 */
@property (nonatomic) float headAngle;
/**
 *  @brief interesting point index
 *
 *  关联兴趣点,若没关联要传-1
 */
@property (nonatomic) int poiIndex;
/**
*  @brief curFlyTime（Unused）
*
*  当前已飞行时长（未使用）
*/
@property(nonatomic, assign) float curFlyTime;
/**
*  @brief cur Fly Distance（Unused）
*
*  当前已飞行航程（未使用）
*/
@property(nonatomic, assign) float curFlyDistance;

/**
 *  @brief waypoint action list
 *
 *  航点动作列表。
 */
@property (nonatomic, strong) NSArray <AUTELWaypointAction *> *actions;


@end

NS_ASSUME_NONNULL_END
