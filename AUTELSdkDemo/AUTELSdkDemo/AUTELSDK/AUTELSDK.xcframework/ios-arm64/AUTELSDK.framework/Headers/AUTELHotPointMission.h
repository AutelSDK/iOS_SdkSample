//
//  AUTELHotPointMission.h
//  AUTELSDK
//
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AUTELSDK/AUTELFoundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELNavigation.h>

/**
 *  Define POI type
 *
 *  定义兴趣点类型
 */
typedef NS_ENUM(uint8_t, AUTELHotpointType) {
    /**
     *  @brief A fixed point as POI
     *
     *  以固定点为兴趣点
     */
    AUTELHotpointTypeFixedPoint,
    
    /**
     *  @brief A moving point as POI
     *
     *  以移动点为兴趣点
     */
    AUTELHotpointTypeMobilePoint,
};

/**
 *  State of the Orbit task
 *
 *  环绕任务的行动状态
 */
typedef NS_ENUM(uint8_t, AUTELHotpointMissionExecuteState ) {
    /**
     *  @brief Initializing Orbit task
     *
     *  正在初始化环绕任务
     */
    AUTELHotPointMissionExecuteStateInitializing,
    /**
     *  @brief Performing Orbit task
     *
     *  正在执行环绕任务
     */
    AUTELHotPointMissionExecuteStateMoving,
    /**
     *  @brief Orbit task paused. Aircraft hovering.
     *
     *  环绕任务已暂停，飞行器正在悬停。
     */
    AUTELHotPointMissionExecuteStatePause,
    /**
     *  @brief Orbit task finished
     *
     *  环绕任务已执行完毕
     */
    AUTELHotPointMissionExecuteStateFinish,
    /**
     *  @brief Orbit task state unknown
     *
     *  环绕任务状态未知
     */
    AUTELHotPointMissionExecuteStateUnknown = 0xFF,
};

/**
 *  This class allowed user get real-time status of hot point mission. The aircraft follows the coordinate sent by AUTELNavigation.updateUserCoordinate method.
 *
 *  兴趣点环绕飞行任务实时状态，当飞行器在执行兴趣点环绕任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELHotPointMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execute state of the hot point mission. 
 *
 *  兴趣点飞行任务执行状态
 *
 *  @see AUTELHotpointMissionExecuteState
 */
@property (nonatomic, readonly) AUTELHotpointMissionExecuteState execState;

/**
 *  @brief The GPS coordinate of hot point.
 *
 *  返回当前环绕的兴趣点的经纬度坐标。
 */
@property (nonatomic, readonly) CLLocationCoordinate2D hotPoint;

/**
 *  @brief Returns a boolean value indicates whether the aircraft is facing to the hot point.
 *
 *  返回飞行器机头方向是否朝向兴趣点
 *
 *  @discussion User can control the direction of aircraft head by calling AUTELNavigation.hotpointMissionHandler.facePOIWithCompletion: during the mission.
 *
 *  在飞行器执行环绕兴趣点任务过程中，用户可以用遥控器改变飞行器机头方向，你可以调用 AUTELNavigation.hotpointMissionHandler 的 -facePOIWithCompletion: 方法让飞行器的机头朝向兴趣点。
 *
 *  @see AUTELNavigation
 *  @see AUTELHotPointMissionHandler
 */
@property (nonatomic, readonly) BOOL isFaceToHotpoint;

/**
 *  @brief The type of hot point.
 *
 *  兴趣点类型。
 *
 *  @see AUTELHotpointTypeFixedPoint
 */
@property (nonatomic, readonly) AUTELHotpointType hotpointType;

/**
 *  @brief The number of circles aircraft already flew.
 *
 *  当前兴趣点飞行任务已飞行的圈数
 */
@property (nonatomic, readonly) int turns;

/**
 *  @brief If the speed >0, then the aircraft will fly surround the hot point in clockwise direction. Else if the speed <0, then the aircraft will fly surround the hot point in countclockwise direction.
 *
 *  兴趣点飞行任务的目标速度（m/s），如果 speed > 0 表示飞行顺时针环绕兴趣点，如果 speed < 0 表示逆时针环绕兴趣点。
 *
 *  @discussion speed This property is not the real-time speed property, it only shows the desired speed of aircraft. The value of this property may vary by changing the speed, radius from remote controller. The real-time speed of aircraft is presented by AUTELMCSystemState.velocityX, AUTELMCSystemState.velocityY and AUTELMCSystemState.velocityZ.
 *
 *  并不是飞行器的实时速度，而是飞行器以 speed 为目标控制飞行器执行环绕飞行，当用户用遥控器加速，或改变环绕半径时，该速度可能会改变。飞行器的实时速度由 AUTELMCSystemState.velocityX, AUTELMCSystemState.velocityY, AUTELMCSystemState.velocityZ 联合表示
 */
@property (nonatomic, readonly) float speed;


@property (nonatomic, readonly) float altitude;

/**
 *  @brief The distance of the radius between the aircraft and the hot point. 
 *
 *  实时环绕半径（即兴趣点到无人机的距离）
 */
@property(nonatomic, readonly) float currentRadius;

@end

/**
 *  This class includes hot point mission related functions.
 *
 *  兴趣点飞行任务
 */
@interface AUTELHotPointMission : AUTELMission<NSCopying>

/**
 *  @brief Type of hot point, default type is AUTELHotpointTypeFixedPoint.
 *
 *  兴趣点类型，默认为 AUTELHotpointTypeFixedPoint
 *
 *  @see AUTELHotpointType
 */
@property (nonatomic) AUTELHotpointType hotpointType;

/**
 *  @brief Sets the coordinate of the hot point. 
 *
 *  兴趣点的经纬度
 *
 *  @discussion If hotpointType equals to AUTELHotpointTypeFixedPoint, then the aircraft will fly surround the hot point. Else if hotpointType equals to AUTELHotpointTypeMobilePoint, then the aircraft will fly surround the location which is sent by [AUTELNavigation updateUserCoordinate] method.
 *
 *  如果 hotpointType 为 AUTELHotpointTypeFixedPoint，飞行器以 hotPoint 为兴趣点环绕飞行，
 *  如果 hotpointType 为 AUTELHotpointTypeMobilePoint 飞行器将忽略 hotPoint，
 *  而是以由 AUTELNavigation 的 updateUserCoordinate 方法发送给飞行器的位置为兴趣点进行环绕飞行。
 *
 *  @see AUTELHotpointType
 *  @see AUTELNavigation
 */
@property (nonatomic) CLLocationCoordinate2D hotPoint;

/**
 *  @brief Sets surround radius in meters from 10m to 500m. Before the aircraft starts to execute orbit mission, it will fly to the spot where has a distance around the radius, and then set the hotpoint as center to start the orbit mission. During the mission, the radius varies by controling the aircraft flying further or closer to the hot point. Call AUTELHotPointMissionStatus.currentRadius to get the real-time radius.
 *
 *  设置环绕半径（m），范围为 10m 至 500m。飞行器开始执行环绕兴趣点任务时，会先飞到距离兴趣点约等于环绕半径的地方，然后以 surroundRadius 为半径开始环绕。
 *  执行环绕任务过程中，用户可以通过遥控器使飞行器靠近或远离兴趣点，此时环绕半径会变小或变大。
 *  你可以通过 AUTELHotPointMissionStatus.currentRadius 获取环绕飞行过程中的事实环绕半径。
 *
 *  @see AUTELNavigationDelegate
 *  @see AUTELHotPointMissionStatus
 */
@property (nonatomic) float surroundRadius;

/**
 *  @brief Default speed of aircraft when executes orbit mission (m/s).
 *
 *  飞行器执行环绕兴趣点任务时的默认速率（m/s）。
 *  
 *  @discussion The value of default speed is only used for reference. The real-time speed of aircraft is affected by radius and the speed controlled by user, so defaultSpeed may not be equal to real-time speed.
 *
 *  这是一个参考速率，但是飞行器的速率还受到环绕半径的影响，且在飞行过车中用户可以用遥控器调整速度，因此飞行器的速率不一定会等于该速率。
 */
@property (nonatomic) float defaultSpeed;

/**
 *  @brief This property describes the direction of surrounding the hot point. Returns YES if clockwise, else returns NO.
 *
 *  环绕方向，是返回 YES，否则返回 NO
 */
@property (nonatomic) BOOL isClockwise;

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
 *  @brief The number of turns. Set 0 as infinity turns. If turns > 0, then the aircraft enters into finish mode.
 *
 *  环绕圈数，如果 turns > 0 飞行器环绕 turns 后按照 finishMode 执行结束动作。如果 turns = 0，表示不对环绕圈数进行限制。
 *
 *  @discussion For various reasons( eg: low battery), the real number of turns may not equal to the property turns. To get the number of turns which aircraft already flew, read  AUTELHotPointMissionStatus.turns property.
 *
 *  由于各种原因（如电量不足），飞行器的实际环绕圈数不一定等于 turns。通过 AUTELHotPointMissionStatus.turns 表示当前飞行器已经环绕的圈数。
 *
 *  @see AUTELHotPointMissionStatu
 */
@property (nonatomic) uint16_t turns;

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

@end
