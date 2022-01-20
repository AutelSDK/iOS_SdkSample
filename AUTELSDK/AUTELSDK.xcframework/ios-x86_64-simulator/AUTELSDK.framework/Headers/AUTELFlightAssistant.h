//
//  AUTELFlightAssistant.h
//  AUTELSDK
//
//  Created by IOS on 2017/7/18.
//  Copyright © 2017年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELVisionTypes.h>
#import <AUTELSDK/AUTELSmartTrackDef.h>
#import <CoreGraphics/CGGeometry.h>

@class AUTELFlightAssistant;


/**
*  Bypass state
*
*  飞行绕行方向
*/
typedef NS_ENUM(NSInteger, AUTELBypassState) {
    /**
    *  @brief  no bypass
    *
    *  没绕行
    */
    AUTELBypassStateNone = 0,
    /**
    *  @brief  Detouring
    *
    *  迂回绕行
    */
    AUTELBypassStateDetouring,
    /**
    *  @brief  Bypass from above
    *
    *  从上边绕行
    */
    AUTELBypassStateFromAbove,
    /**
    *  @brief   Bypass from left
    *
    *  从左边绕行
    */
    AUTELBypassStateFromLeft,
    /**
    *  @brief   Bypass from above right
    *
    *  从右边绕行
    */
    AUTELBypassStateFromRight,
    /**
    *  @brief  unkown state
    *
    *  unkown state
    */
    AUTELBypassStateUnknown = -1,
};

/**
*  Landing Protection State
*
*  降落保护状态
*/
typedef NS_ENUM(NSInteger, AUTELLandingProtectionState) {
    /**
    *  @brief  no protection
    *
    *  没保护
    */
    AUTELLandingProtectionStateNone,
    /**
    *  @brief  Landing protection takes effect
    *
    *  降落保护生效
    */
    AUTELLandingProtectionStateWorking,
    /**
    *  @brief  Landing protection takes effect
    *
    *  检测到不明物体,需要用户确认降落
    */
    AUTELLandingProtectionStateAnalysisFailed,
    /**
    *  @brief  Landing protection takes effect
    *
    *  降落区域不安全
    */
    AUTELLandingProtectionStateNotSafeToLand,
    /**
    *  @brief  Landing protection takes effect
    *
    *  飞行器接近地面
    */
    AUTELLandingProtectionStateNearLand,
    /**
    *  @brief  Landing protection takes effect
    *
    *  飞行器已经安全着陆
    */
    AUTELLandingProtectionStateSafeLanded,
    /**
    *  @brief  unkown state
    *
    *  unkown state
    */
    AUTELLandingProtectionStateUnkown = -1
};

/**
*  Landing Protection Event
*
*  降落保护事件
*/
typedef NS_ENUM(NSInteger, AUTELLandingProtectionEvent) {
    /**
       *  @brief  Start landing, start smart landing, visual obstacle avoidance
       *
       *  开始降落,启动智能降落,视觉避障关闭
       */
    AUTELLandingProtectionEventStart = 0,
    /**
       *  @brief  Landing area is not safe, stop landing
       *
       *  降落区域不安全, 停止降落
       */
    AUTELLandingProtectionEventUnsafeToLanding,
    /**
       *  @brief  The landing area is not safe, but the user forcibly landed again
       *
       *  降落区域不安全, 但是用户再次常熟强行降落
       */
    AUTELLandingProtectionEventUnsafeAndUserTryAgain,
    /**
    *  @brief  Unknown obstacle detected
    *
    *  检测到不明障碍物
    */
    AUTELLandingProtectionEventUnknownObstruction,
    /**
       *  @brief   Accurate landing, correcting position
       *
       *  精准降落, 正在修正位置
       */
    AUTELLandingProtectionEventRejudgeLanding,
    /**
       *  @brief  The aircraft is close to the ground and requires user confirmation
       *
       *  飞行器接近地面, 需要用户确认
       */
    AUTELLandingProtectionEventNearLand,
    /**
       *  @brief  Have landed safely
       *
       *  已经安全降落
       */
    AUTELLandingProtectionEventFinishSafeLading,
    /**
       *  @brief  Landing was cancelled
       *
       *  降落被取消
       */
    AUTELLandingProtectionEventLandingCancel,
    /**
       *  @brief no update
       *
       *  没有更新
       */
    AUTELLandingProtectionEventNoUpdate,
    /**
       *  @brief  none
       *
       *  无事件
       */
    AUTELLandingProtectionEventNone = -1,
};


/**
*  track Speed Mode
*
*  跟踪速度模式
*/
typedef NS_ENUM(NSInteger, AUTELTrackSpeedMode) {
    /**
    *  @brief  no bypass
    *
    *  low speed mode
    */
    AUTELTrackSpeedModeLow = 0,
    /**
    *  @brief  high speed mode
    *
    *  高速模式
    */
    AUTELTrackSpeedModeHigh,
    
};

@interface AUTELVisionControlState: NSObject<NSCopying>

// 视觉心跳AlarmStatus1(仅用于飞行记录)
@property (nonatomic, assign) uint32_t alarmStatus1;

// 视觉心跳AlarmStatus2(仅用于飞行记录)
@property (nonatomic, assign) uint32_t alarmStatus2;

// 视觉错误码(仅用于飞行记录)
@property (nonatomic, assign) uint32_t visionErrorCode;

/// 避障使能
@property (nonatomic, assign) BOOL collisionAvoidanceEnable;

/// 是否显示雷达图
@property (nonatomic, assign) BOOL showObstaclesDetectionChar;

/// forward Tracking Ambient Light State
@property (nonatomic) AUTELTrackingAmbientLightState forwardLightState;

/// donwared Tracking Ambient Light State
@property (nonatomic) AUTELTrackingAmbientLightState donwaredlightState;

/// There are obstacles ahead, speed limit   前方有障碍物，进行速度限制
@property (nonatomic) BOOL isFrontObstaclesAndLimitSpeed;

/// Can't pass in front, please bypass   前方无法通行，请绕行
@property (nonatomic) BOOL isNoFrontWayTurnAround;

/// There are obstacles at the rear, the plane has hovered   后方有障碍物，飞机已悬停
@property (nonatomic) BOOL isNoBackWayAndHover;

/// The under-view sensor calibration parameters are abnormal, and the precise hovering and obstacle avoidance functions are affected.   下视传感器标定参数异常，精准悬停和避障功能受到影响
@property (nonatomic) BOOL isDownwardVisualSensorCalibrationParameterException;

/// The front view sensor calibration parameters are abnormal, and the precise hovering and obstacle avoidance functions are affected.   前视传感器标定参数异常，精准悬停和避障功能受到影响
@property (nonatomic) BOOL isFrontVisualSensorCalibrationParameterException;

//错误码序列编号

/// 飞机已达到最远距离限制 44
@property (nonatomic) BOOL isReachtMaxFlighRadiusLimit;
/// 飞机已达到最大高度限制 45
@property (nonatomic) BOOL isReachMaxFlightHeightLimit;

/// Front view vision module status is abnormal  前视视觉模组状态异常 62
@property (nonatomic) BOOL isForwardVisionModuleAbnormal;

/// Lower vision module status is abnormal   下视视觉模组状态异常 63
@property (nonatomic) BOOL isDownwardVisionModuleAbnormal;

/// 前视视觉模组标定状态异常 65
@property (nonatomic) BOOL isFrontVisionModuleAbnormal;
/// 后视视觉模组标定状态异常 66
@property (nonatomic) BOOL isBackVisionModuleAbnormal;
/// 下视视觉模组标定状态异常 67
@property (nonatomic) BOOL isDownVisionModuleAbnormal;
/// 右视视觉模组标定状态异常 68
@property (nonatomic) BOOL isRightVisionModuleAbnormal;
/// 左视视觉模组标定状态异常 69
@property (nonatomic) BOOL isLeftVisionModuleAbnormal;
/// 上视视觉模组标定状态异常 70
@property (nonatomic) BOOL isUpVisionModuleAbnormal;
/// 多个视觉模组标定状态异常 71
@property (nonatomic) BOOL isMoreThanOneVisionModuleAbnormal;
/// 飞机高度已调整到最大值 72
@property (nonatomic) BOOL isReachMaxHeight;
/// 飞机高度已调整到最小值 73
@property (nonatomic) BOOL isReachMinHeight;
/// 飞机近距变焦已调整到最小值 74
@property (nonatomic) BOOL isReachMinZoom;
/// 飞机近距变焦已调整到最大值 75
@property (nonatomic) BOOL isReachMaxZoom;
/// 无法继续通行，退出指向飞行 76
@property (nonatomic) BOOL canNotKeepFly;
/// ATTI模式，任务退出 77
@property (nonatomic) BOOL attiModeExit;
/// 长按遥控器任务退出 78
@property (nonatomic) BOOL longPressExit;
/// 磁航向偏差过大，跟踪异常退出 79
@property (nonatomic) BOOL courseDeviation;
/// 磁航向偏差过大，指向飞行异常退出 80
@property (nonatomic) BOOL courseDeviationViewPoint;

/// 磁航向偏差过大，环绕异常退出．（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_81;
/// 距离过近，请调整目标距离重试．（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_82;
/// 初始化失败， 请保持目标静止．　（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_83;
/// 正在测算距离， 请保持目标静止．（仅提示）
@property (nonatomic) BOOL visual_warning_84;
/// 初始化成功，开始执行任务．　　（仅提示）
@property (nonatomic) BOOL visual_warning_85;
/// 目标丢失，请重新框选目标　（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_86;
/// 目标纹理过弱，请重新框选目标　（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_87;
/// GPS信号弱，无法执行任务　（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_88;
/// 目标过小，请重新框选目标（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_89;
/// 飞行器运动方向有障碍物，请移至空旷区域后重试（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_90;
/// 初始化失败，请重试（App需退出至目标框选界面）
@property (nonatomic) BOOL visual_warning_91;


//心跳包的序列编号
/// 0 - 标定参数有效 1 - 标定参数过期 status2 5
@property (nonatomic) BOOL isVisionCalibrationInvalid;

/// 前视左目传感器状态异常 status2 20
@property (nonatomic) BOOL isFrontLeftVisualSensorAbnormal;
/// 前视右目传感器状态异常 status2 21
@property (nonatomic) BOOL isFrontRightVisualSensorAbnormal;
/// 后视左目传感器状态异常 status2 22
@property (nonatomic) BOOL isBackLeftVisualSensorAbnormal;
/// 后视右目传感器状态异常 status2 23
@property (nonatomic) BOOL isBackRightVisualSensorAbnormal;
/// 下视左目传感器状态异常 status2 24
@property (nonatomic) BOOL isDownLeftVisualSensorAbnormal;
/// 下视右目传感器状态异常 status2 25
@property (nonatomic) BOOL isDownRightVisualSensorAbnormal;
/// 右视左目传感器状态异常 status2 26
@property (nonatomic) BOOL isRightLeftVisualSensorAbnormal;
/// 右视右目传感器状态异常 status2 27
@property (nonatomic) BOOL isRightRightVisualSensorAbnormal;
/// 左视左目传感器状态异常 status2 28
@property (nonatomic) BOOL isLeftLeftVisualSensorAbnormal;
/// 左视右目传感器状态异常 status2 29
@property (nonatomic) BOOL isLeftRightVisualSensorAbnormal;
/// 上视左目传感器状态异常 status2 30
@property (nonatomic) BOOL isUpLeftVisualSensorAbnormal;
/// 上视右目传感器状态异常 status2 31
@property (nonatomic) BOOL isUpRightVisualSensorAbnormal;


/// Landing Protection State
@property (nonatomic) AUTELLandingProtectionState landingProtectionState;

/// Landing Protection Event
@property (nonatomic) AUTELLandingProtectionEvent landingProtectionEvent;

/// 视觉功能是否受限，环境较差
@property (nonatomic, assign) BOOL visionLimitWhenDark;

/// 安全空间不足，无法通过 错误码序列编号  54
@property (nonatomic, assign) BOOL canNotPassOutOfSafeSpace;

/// 将飞行器移到空旷区域后重试 55
@property (nonatomic) BOOL flyToOpenSpace;

@end

/**
 *  This protocol provides an delegate method to update the vision current state.
 */
@protocol AUTELFlightAssistantDelegate <NSObject>

@optional

/**
 *  Callback function that updates the vision detection state. The frequency of this
 *  method is 10Hz.
 *
 *  @param assistant Intelligent flight assistant that has the updated state.
 *  @param states The state of vision sensor.
 */
- (void)flightAssistant:(AUTELFlightAssistant *_Nonnull)assistant didUpdateVisionDetectionStates:(NSArray<AUTELVisionDetectionState *> *_Nonnull)states NS_SWIFT_NAME(flightAssistant(_:didUpdateVisionDetectionStates:));

/**
 Callback function that did update vision control state

 @param assistant Intelligent flight assistant that has the updated state
 @param state The state of vision sensor
 */
- (void)flightAssistant:(AUTELFlightAssistant *_Nonnull)assistant didUpdateState:(AUTELVisionControlState *_Nonnull)state NS_SWIFT_NAME(flightAssistant(_:didUpdateVisionControlState:));

/**
 *  Callback function that updates the vision detection state. The frequency of this
 *  method is 10Hz.
 *
 *  @param assistant Intelligent flight assistant that has the updated state.
 *  @param ObjectInfo The state of vision sensor.
 */
- (void)flightAssistant:(AUTELFlightAssistant *_Nonnull)assistant didUpdateDetectionObject:(NSDictionary *_Nonnull)ObjectInfo NS_SWIFT_NAME(flightAssistant(_:didUpdateDetectionObject:));

@end


/**
*  Get real-time vision status and send command to control vision.
*
*  通过该类，你可以获得视觉的实时状态，也可以向视觉发送命令，控制视觉。
*/
@interface AUTELFlightAssistant : NSObject

/**
 *  vision delegate.
 */
@property(nonatomic, weak) id<AUTELFlightAssistantDelegate> _Nullable delegate;

/**
 get all setting with completion

 @param block completion block
 */
- (void)getAllSettingWithCompletion:(AUTELCompletionBlock)block;

/**
*  @brief get collision avoidance enable
*
*  避障开关使能查询
*/
- (void)getCollisionAvoidanceEnableWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
*  @brief set collision avoidance enable
*
*  避障开关使能设置
*/
- (void)setCollisionAvoidanceEnable:(BOOL)enable
                     withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief get SOA enable
*
*  SOA使能查询
*/
- (void)getSOAEnableWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
*  @brief set SOA enable
*
*  SOA使能设置
*/
- (void)setSOAEnable:(BOOL)enable
                     withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief get retreat enable
*
*  查询智能追踪时后退使能
*/
- (void)getRetreatEnableWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
*  @brief set retreat enable
*
*  智能追踪时后退使能设置
*/
- (void)setRetreatEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief get avoidance while track enable
*
*  查询智能追踪时是否启用避障
*/
- (void)getAvoidanceWhileTrackEnableWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
*  @brief set avoidance while track enable
*
*  智能追踪时避障使能设置
*/
- (void)setAvoidanceWhileTrackEnable:(BOOL)enable
                      withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief get report obstacles detection enable
*
* 查询障碍物识别上报使能
*/
- (void)getReportObstaclesDetectionEnableWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
*  @brief set report obstacles detection enable
*
*  障碍物识别上报使能设置
*/
- (void)setReportObstaclesDetectionEnable:(BOOL)enable
                           withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief get vision assisted positioning enable
*
*  查询是否启动了视觉定位
*/
- (void)getVisionAssistedPositioningEnabledWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
*  @brief set vision assisted positioning enable
*
*  视觉定位使能设置
*/
- (void)setVisionAssistedPositioningEnabled:(BOOL)enable
                             withCompletion:(AUTELCompletionBlock)block;


/**
*  @brief get landing protection enable
*
*  查询是否启动了降落保护
*/
- (void)getLandingProtectionEnabledWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
*  @brief set landing protection enable
*
*  降落保护使能设置
*/
- (void)setLandingProtectionEnabled:(BOOL)enable
                     withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get precision landing enable
 *
 *  查询精准降落使能
 */
- (void)getPrecisionLandingEnabledWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
 *  @brief set precision landing enable
 *
 *  设置精准降落使能
 */
- (void)setPrecisionLandingEnabled:(BOOL)enable
                    withCompletion:(AUTELCompletionBlock)block;

///**
// *  @brief set smart track mode
// *
// *  设置智能追踪模式
// */
//- (void)setSmartTrackMode:(AUTELSmartTrackMode)trackMode withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief set smart track check action
// *
// *  设置退出、进入、停止追踪检测模式
// */
//- (void)setSmartTrackCheckAction:(AUTELSmartTrackCheckAction)action withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief set smart track check action
// *
// *  设置框选目标坐标
// */
//- (void)setSmartTrackGoalArea:(CGRect)area withObjid:(int32_t)objid andTargetType:(AUTELSmartTrackTargetType)target withCompletion:(AUTELCompletionBlock)block;


///**
//智能追踪高度设置
//*/
//- (void)setTrackHeightPara:(uint8_t)enable withCompletion:(AUTELCompletionBlock)block;
//
///**
//智能追踪Zoom设置
//*/
//- (void)setTrackZoomPara:(uint8_t)enable withCompletion:(AUTELCompletionBlock)block;

/**
智能追踪Zoom值调节 ，参数必须是+10或者-10
*/
- (void)setTrackZoomValue:(int32_t)value withCompletion:(AUTELCompletionBlock)block;

/**
智能追踪速度模式设置，0：低速模式，1：高速模式
*/
- (void)setTrackSpeedMode:(AUTELTrackSpeedMode)model withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get horizontal bypass while Viewpoint enable
 *
 *  查新 Viewpoint 飞行时左右绕行使能
 */
- (void)getHorizontalBypassWhileViewpointEnableWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
 *  @brief set horizontal bypass while Viewpoint enable
 *
 *  设置 Viewpoint 飞行时左右绕行使能
 */
- (void)setHorizontalBypassWhileViewpointEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get go home avoidance enable
 *
 *  查询返航避障使能
 */
- (void)getGoHomeAvoidanceEnableWithCompletion:(void (^_Nullable)(BOOL enable, NSError *_Nullable error))block;

/**
 *  @brief set go home avoidance enable
 *
 *  设置返航避障使能
 */
- (void)setGoHomeAvoidanceEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief force landing
 *
 *  允许降落
 */
- (void)forceLandingWithCompletion:(AUTELCompletionBlock)block;



///**
// *  @brief set Gesture check action
// *
// *  设置退出、进入手势识别模式
// *
// *  @see AUTELCameraPictureInVideoGap
// */
//- (void)setGestureCheckAction:(AUTELGestureCheckAction)action withCompletion:(AUTELCompletionBlock)block;


/**
*  @brief get  the  bottom LED enable
*
*  获取下视LED开关状态
*/
- (void)getBottomLedControlModeWithCompletion:(void (^_Nullable)(uint8_t enable, NSError *_Nullable error))block;


/// set  the bottom LED enable
/// @param enable 0：close，1：open
/// @param block  Completion block.
- (void)setBottomLedControlMode:(uint8_t)enable withCompletion:(AUTELCompletionBlock)block;


@end
