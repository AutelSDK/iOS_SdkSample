//
//  AUTELNavigation.h
//  AUTELSDK
//
//  Created by IOS on 15/12/22.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <CoreLocation/CoreLocation.h>
#import <AUTELSDK/AUTELMissionHandler.h>


@protocol AUTELHotPointMission;
@protocol AUTELMissionHandler;
@protocol AUTELHotPointMissionHandler;
@protocol AUTELFollowMeMissionHandler;
@protocol AUTELTrackMissionHandler;
@protocol AUTELViewpointMissionHandler;
@protocol AUTELOneShotVideoMissionHandler;
@protocol AUTELTripodMissionHandler;
@protocol AUTELPhotographerMissionHandler;
@protocol AUTELWaypointMissionHandler;
@protocol AUTELDelayShotMissionHandler;
@protocol AUTELVisionOrbitMissionHandler;
@protocol AUTELOrbitDelayShotMissionHandler;
@protocol AUTELPanoramicPhotoMissionHandler;

@class AUTELMissionProgressStatus;
@class AUTELMCWaypointMission;
@class AUTELWaypointMissionStatus;
@class AUTELDelayShotMissionStatus;
@class AUTELVisionOrbitMissionStatus;
@class AUTELPanoramicPhotoMissionStatus;


/**
* mission type
*
*  任务类型
*/
typedef NS_ENUM(uint8_t, AUTELMissionType) {
    /**
    *  @brief Invalid mission
    *
    *  无效任务
    */
    AUTELMissionTypeInvalid = 0,
    /**
    *  @brief Waypoint mission
    *
    *  航点任务
    */
    AUTELMissionTypeWaypoint = 1,
    /**
    *  @brief Orbit mission
    *
    *  环绕任务
    */
    AUTELMissionTypeOrbit = 2,
    /**
    *  @brief Cylinder mission
    *
    *  立体环绕任务
    */
    AUTELMissionTypeCylinder = 3,
    //全景任务
    /**
    *  @brief Panorama mission
    *
    *  全景任务
    */
    AUTELMissionTypePanorama = 4,
    //GPS跟踪任务
    /**
    *  @brief GPSFollow mission
    *
    *  GPS跟踪任务
    */
    AUTELMissionTypeGPSFollow = 5,
    /**
    *  @brief Rectangle mission
    *
    * 矩形测绘任务
    */
    AUTELMissionTypeRectangle = 6,
    /**
    *  @brief Polygon mission
    *
    *  多边形测绘任务
    */
    AUTELMissionTypePolygon = 7,
    /**
    *  @brief One shot mission
    *
    *  一键短片任务
    */
    AUTELMissionTypeOneShotVideo = 8,
    /**
    *  @brief Precision Flight mission
    *
    *  精准飞行
    */
    AUTELMissionTypeTripod = 9,
    /**
    *  @brief Dual Stability mission
    *
    *  影像增稳任务
    */
    AUTELMissionTypePhotographer = 10,
    /**
    *  @brief Time Lapse mission
    *
    *  自由延时任务
    */
    AUTELMissionTypeFreeDelayShot = 11,
    /**
    *  @brief Oblique photography  mission
    *
    *  倾斜摄影任务
    */
    AUTELMissionTypeObliquePhoto = 12
};


/**
 *  Go Home mode upon completion of the Autopilot task
 *
 *  智能飞行结束后返航模式
 */
typedef NS_ENUM(int, AUTELNavigationMissionFinishMode) {
    
    /**
     *  @brief Invalid mode
     *
     *  无效动作
     */
    AUTELNavigationMissionFinishModeInvalid = 0,
    
    /**
     *  @brief Hover onsite
     *
     *  停留在最后一个航点，用户这时候可以接管操控飞机
     */
    AUTELNavigationMissionFinishModeHover,
    
    /**
     *  @brief Return to the home point
     *
     *  返回Home点
     */
    AUTELNavigationMissionFinishModeGoHome,
    
    /**
     *  @brief Land onsite
     *
     *  在最后一个航点着陆
     */
    AUTELNavigationMissionFinishModeLand,
    
    /**
     *  @brief Return to the first waypoint
     *
     *  返回第一个航点
     */
    AUTELNavigationMissionFinishModeGoFirstWaypoint,
    
    /**
     *  @brief Return to the home point
     *
     *  停留在最后一个航点，但保持航点任务模式，用户可以通过遥控操控飞机倒退一个航点或者退出航点任务模式
     */
    AUTELNavigationMissionFinishModeHoverAndKeepMissionStatus,
    
    /**
    *  @brief Return to the hot point
    *
    *  返回兴趣点
    */
    AUTELNavigationMissionFinishModeGoHotPoint,
};

/**
 *  Go Home mode upon completion of the Autopilot task
 *
 *  智能飞行任务避障模式
 */
typedef NS_ENUM(int, AUTELMissionAvoidanceType) {
    /**
     *  @brief Avoidance is invalid
     *
     *  无效模式
     */
    AUTELMissionAvoidanceTypeNone,
    
    /**
     *  @brief Avoidance is invalid
     *
     *  遇到障碍物悬停
     */
    AUTELMissionAvoidanceTypeHover,
    
    /**
     *  @brief Avoidance is invalid
     *
     *  遇到障碍物左右避让，避让失败时悬停（如果装置有顶部避障系统则尝试爬升避障，再次失败时悬停）
     */
    AUTELMissionAvoidanceTypeHorizontal,
    
    /**
     *  @brief Avoidance is invalid
     *
     *  遇到障碍物爬升避让，避让失败时尝试左右避让，再次失败时悬停
     */
    AUTELMissionAvoidanceTypeVertical,
};

/**
 *  Go Home mode upon completion of the Autopilot task
 *
 *  控制信号丢失动作
 */
typedef NS_ENUM(int, AUTELMissionSignalLostHandleType) {
    
    /**
     *  @brief Avoidance is invalid
     *
     *  无效动作
     */
    AUTELMissionSignalLostHandleTypeNone,
    
    /**
     *  @brief Avoidance is invalid
     *
     *  返航到Home点
     */
    AUTELMissionSignalLostHandleTypeGoHome,
    
    /**
     *  @brief Avoidance is invalid
     *
     *  继续执行任务直到电量不足或者任务完成
     */
    AUTELMissionSignalLostHandleTypeContinue,
};

/**
 *  Shooting Mode
 *
 *  拍摄模式
 */
typedef NS_ENUM(int, AUTELMissionShootingType) {
    
    /**
     *  @brief Avoidance is invalid
     *
     *  无效动作
     */
    AUTELMissionShootingTypeNone,
    
    /**
     *  @brief Avoidance is invalid
     *
     *  晴天
     */
    AUTELMissionShootingTypeSunny,
    
    /**
     *  @brief Avoidance is invalid
     *
     *  阴天
     */
    AUTELMissionShootingTypeCloudyDay,
};

/**
 *  image format
 *
 *  图片格式
 */
typedef NS_ENUM(int, AUTELMissionImageFormat) {
    
    /**
     *  @brief  invalid
     *
     *  无效动作
     */
    AUTELMissionImageFormatNone,
    
    /**
     *  @brief A
     *
     *  A格式
     */
    AUTELMissionImageFormatA,
    
    /**
     *  @brief D
     *
     *  D格式
     */
    AUTELMissionImageFormatD,
};
/*
 *  This protocol provides real-time status of the Autopilot task.
 *
 *  该协议实时提供智能飞行任务的状态
 */
@protocol AUTELNavigationDelegate <NSObject>

@required

/**
 *  @brief Updates the navigation mission status. If the missionType is of type AUTELNavigationMissionWaypoint
 *  then the missionStatus will be of class AUTELWaypointMissionStatus. If missionType is
 *  AUTELNavigationMissionHotpoint then the missionStatus will be of class AUTELHotpointMissionStatus.
 *  If the missionType is AUTELNavigationMissionFollowMe then the missionStatus will be of class @see AUTELFollowMeMissionStatus.
 *
 *  更新智能飞行任务的状态。
 *  若 missionStatus 是 AUTELWaypointMissionStatus 类型，则当前正在执行航点任务。
 *  若 missionStatus 是 AUTELHotpointMissionStatus 类型，则当前正在执行热点环绕任务。
 *  若 missionStatus 是 AUTELFollowMeMissionStatus 类型，则当前正在执行追踪任务。
 *
 *  @param missionStatus Mission status based on the current mission.
 *
    根据当前智能飞行模式返回的任务状态
 *
 *  @see AUTELMissionProgressStatus
 *  @see AUTELWaypointMissionStatus
 *  @see AUTELHotpointMissionStatus
 *  @see AUTELFollowMeMissionStatus
 */
- (void)onNavigationMissionStatusChanged:(AUTELMissionProgressStatus* _Nonnull)missionStatus;

@optional

/**
 *  @brief The mission brief information of the last interrupted mission flight is issued to implement the breakpoint resume function.If the mission flight execution is interrupted, the aircraft will push the breakpoint information every 2s.The APP downloads mission information to the aircraft based on the breakpoint information
 *
 * 下发上一次被中断的任务飞行的任务简要信息，用于实现断点续飞功能。若任务飞行执行过程中被中断，飞机会每2s的频率推送断点信息过来。APP根据断点信息去飞机下载任务信息。
 *
 *  @param continueFlyInfo Breakpoint continued to fly info .
 *
 *  返回上一次被中断的任务信息
 *
 *  @see AUTELMCWaypointMission
 */
- (void)onMissionBreakPointContinueFlyInfoNote:(AUTELMCWaypointMission* _Nonnull)continueFlyInfo;

/**
 *  @brief The mission status information is pushed in real time during mission flight execution.Specifically refers to mission flight (waypoint flight, rectangular mission, polygonal mission)
 *
 *  任务飞行执行时实时推送任务状态信息。特指任务飞行（航点飞行、矩形任务、多边形任务）。
 *
 *  @param missionStatus Mission status based on the current mission.
 *
 *  任务飞行执行时实时推送任务状态信息
 *
 *  @see AUTELMissionProgressStatus
 */
- (void)onMissionCurrentStatusUpdateNote:(AUTELWaypointMissionStatus* _Nonnull)missionStatus;

/**
 *  @brief Enter the time-lapse photography task, the camera reports the time-lapse photography status information in real time
 *
 *  进入延时摄影任务，相机实时上报延时摄影状态信息
 *
 *  @param misstionStauts see AUTELDelayShotMissionStatus
 *
 *  移动延时摄影状态上报
 *
 *  @see AUTELDelayShotMissionStatus
 */
- (void)onMissionMotionDelayShotStatusUpdateNote:(AUTELDelayShotMissionStatus* _Nonnull)misstionStauts;

/**
 *  @brief 待翻译
 *  待翻译
 *  待翻译
 *  待翻译
 *
 *  进入视觉环绕任务，视觉实时上报视觉环绕状态
 *
 *
 *  @param misstionStauts see AUTELVisionOrbitMissionStatus
 *
 *  视觉环绕状态上报
 *
 *  @see AUTELVisionOrbitMissionStatus
 */
- (void)onMissionVisionOrbitStatusUpdateNote:(AUTELVisionOrbitMissionStatus* _Nonnull)misstionStauts;

/**
 *  @brief Enter the panoramic photo mission, the camera reports the panoramic photo status information in real time
 *
 *  进入全景摄影任务，相机实时上报全景拍照状态信息
 *
 *  @param misstionStauts see AUTELPanoramicPhotoMissionStatus
 *
 *  全景拍照状态上报
 *
 *  @see AUTELPanoramicPhotoMissionStatus
 */
- (void)onMissionPanoramicPhotoStatusUpdateNote:(AUTELPanoramicPhotoMissionStatus* _Nonnull)misstionStauts;

@end

/**
 *   Provides info of auto-piloting mission. Allows the aircraft to execute follow me mission, orbit mission and waypoint mission by calling followMeMissionHandle, hotpointMission and waypointMissionHandler. If the aircraft is executing mission, delegate.onNavigationMissionStatusChanged method will be invoked and return the real-time status of the mission.Other tasks are the same.
 *
 *  该类管理智能飞行，通过 waypointMissionHandler，hotpointMissionHandler 和 followMeMissionHandler 你可以分别让飞行器执行
 *  航点任务，兴趣点环绕任务和追踪任务。如果飞行器正在执行任务，delegate 的 -onNavigationMissionStatusChanged: 方法会被自动调用并返回任务的实时状态。其他任务照此类推。
 */
@interface AUTELNavigation : NSObject

/**
 *  @brief Navigation delegate.
 *
 *  代理对象
 *
 *  @discussion Gets real-time status of mission by implementing -onNavigationMissionStatusChanged:missionStatus method.
 *
 *  通过该代理实例的 -onNavigationMissionStatusChanged: 方法，你可以实时获取当前智能飞行任务状态。
 *
 *  @see AUTELNavigationDelegate
 */
@property(nonatomic, weak) id<AUTELNavigationDelegate> _Nullable delegate;

/**
 *  @brief User can download or upload waypoints, start , stop or pause the waypoint mission by calling waypintMissionHandler method.
 *
 *  通过 waypointMissionHandler 可用于下载,上传,执行,停止,暂停航点任务
 *
 *  @discussion Make sure the type of mission is waypointMission before call downlongMissionWithProgress:withCompletion to download the data of misison. The onNavigationMissionStatusChanged call back method return current status of mission. If there is no current executing waypoint mission, downMissionWithProgress: withCompletion returns error when it is invoked.
 *
 *  waypointMissionHandler.handlerType 为 AUTELMissionHandlerTypeWaypoint。
 *  在调用 waypointMissionHandler 的 -checkMission:withCompletion: 和 -prepareMission:withProgress:withCompletion: 方法时，第一个参数必须是 AUTELWaypointMission 类型的实例，否则将执行失败。
 *
 *  在调用 -downloadMissionWithProgress:withCompletion: 方法下载任务数据前，要先确定当前执行的航点任务。你可以通过 -onNavigationMissionStatusChanged 回调方法返回的任务执行状态直到当前正在执行哪种任务。如果当前没有在执行航点任务，调用 -downloadMissionWithProgress:withCompletion: 方法将出错。
 *
 *  @see AUTELMissionHandler
 *  @see AUTELNavigationDelegate
 *  @see AUTELMissionProgressStatus
 *  @see AUTELWaypointMissionStatus
 */
@property(nonatomic, readonly) NSObject<AUTELWaypointMissionHandler>* _Nonnull waypointMissionHandler;

/**
 *  @brief 通过 hotpointMissionHandler 可用于下载,上传,执行,停止,暂停兴趣点环绕任务
 *
 *  @discussion hotpointMissionHandler.handlerType 为 AUTELMissionHandlerTypeHotPoint。
 *  在调用 hotpointMissionHandler 的 -checkMission:withCompletion: 和 -prepareMission:withProgress:withCompletion: 方法时，第一个参数必须是 AUTELHotPointMission 类型的实例，否则将执行失败。
 *
 *  在调用 -downloadMissionWithProgress:withCompletion: 方法下载任务数据前，要先确定当前执行的兴趣点环绕任务。你可以通过 -onNavigationMissionStatusChanged 回调方法返回的任务执行状态直到当前正在执行哪种任务。如果当前没有在执行航点任务，调用 -downloadMissionWithProgress:withCompletion: 方法将出错。
 *
 *  @see AUTELMissionHandler
 *  @see AUTELNavigationDelegate
 *  @see AUTELMissionProgressStatus
 *  @see AUTELHotPointMissionStatus
 */
@property(nonatomic, readonly) NSObject<AUTELMissionHandler>* _Nonnull hotpointMissionHandler;

/**
 *  @brief 通过 followMeMissionHandler 可用于下载,上传,执行,停止,暂停兴趣点环绕任务
 *
 *  @discussion followMeMissionHandler.handlerType 为 AUTELMissionHandlerTypeFollowMe。
 *  在调用 followMeMissionHandler 的 -checkMission:withCompletion: 和 -prepareMission:withProgress:withCompletion: 方法时，第一个参数必须是 AUTELFollowMeMission 类型的实例，否则将执行失败。
 *
 *  在调用 -downloadMissionWithProgress:withCompletion: 方法下载任务数据前，要先确定当前执行的兴趣点环绕任务。你可以通过 -onNavigationMissionStatusChanged 回调方法返回的任务执行状态直到当前正在执行哪种任务。如果当前没有在执行追踪任务，调用 -downloadMissionWithProgress:withCompletion: 方法将出错。
 *
 *  @see AUTELMissionHandler
 *  @see AUTELNavigationDelegate
 *  @see AUTELMissionProgressStatus
 *  @see AUTELFollowMeMissionStatus
 */
@property(nonatomic, readonly) NSObject<AUTELMissionHandler>* _Nonnull followMeMissionHandler;

/**
*  @brief Return to the tracking task processor, which can be used to enter, execute, stop, and suspend the tracking task through trackMissionHandler.
*
*  返回追踪任务处理器，通过 trackMissionHandler 可用于进入,执行,停止,暂停追踪任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELTrackMissionHandler> * _Nonnull trackMissionHandler;

/**
*  @brief Return to the gesture recognition task processor, which can be used to enter and exit the gesture recognition task through gestureMissionHandler.
*
*  返回手势识别任务处理器，通过 gestureMissionHandler 可用于进入,退出手势识别任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELTrackMissionHandler> * _Nonnull gestureMissionHandler;

/**
*  @brief Return to the pointing flight task processor, which can be used to enter, start, pause, resume, and exit pointing flight tasks through viewpointMissionHandler.
*
*  返回指点飞行任务处理器，通过 viewpointMissionHandler 可用于进入,开始，暂停，恢复，退出指点飞行任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELViewpointMissionHandler> * _Nonnull viewpointMissionHandler;

/**
 *  One Shot Video mission.
 */
/**
*  @brief Return to one-click short film task processor, through oneShotVideoMissionHandler can be used to start, exit one-click short film task.
*
*  返回一键短片任务处理器，通过 oneShotVideoMissionHandler 可用于开始，退出一键短片任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELMissionHandler>* _Nonnull oneShotVideoMissionHandler;

/**
*  @brief Return to the precision flight mission processor, which can be used to download, upload, execute, and stop the precision flight mission through tripodMissionHandler.
*
*  返回精准飞行任务处理器，通过 tripodMissionHandler 可用于下载,上传,执行,停止精准飞行任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELTripodMissionHandler>* _Nonnull tripodMissionHandler;

/**
*  @brief Return to the image stabilization task processor, which can be used to enter and exit the image stabilization task through photographerMissionHandler.
*
*  返回影像增稳任务处理器，通过 photographerMissionHandler 可用于进入,退出影像增稳任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELMissionHandler>* _Nonnull photographerMissionHandler;

/**
*  @brief Return to the delay shot task processor, which can be used to start, pause, resume, and exit the delay shot task through delayShotMissionHandler.
*
*  返回延时摄影任务处理器，通过 delayShotMissionHandler 可用于开始，暂停，恢复,退出延时摄影任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELDelayShotMissionHandler>* _Nonnull delayShotMissionHandler;

/**
*  @brief Return to the intelligent surround task processor, which can be used to enter, pause, resume, stop, and exit the intelligent surround task through visionOrbitMissionHandler.
*
*  返回智能环绕任务处理器，通过 visionOrbitMissionHandler 可用于进入，暂停，恢复,停止，退出智能环绕任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELVisionOrbitMissionHandler>* _Nonnull visionOrbitMissionHandler;

/**
*  @brief Return to the surround time-lapse photography task processor, which can be used to enter, pause, resume, stop and exit the surround time-lapse photography task through orbitDelayShotMissionHandler.
*
*  返回环绕延时摄影任务处理器，通过 orbitDelayShotMissionHandler 可用于进入，暂停，恢复,停止，退出环绕延时摄影任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELOrbitDelayShotMissionHandler>* _Nonnull orbitDelayShotMissionHandler;

/**
*  @brief Return to the Panoramic photo task processor, which can be used to start, pause, resume, and exit the delay shot task through panoramicPhotoMissionHandler.
*
*  返回全景摄影任务处理器，通过 panoramicPhotoMissionHandler 可用于开始，暂停，恢复,退出延时摄影任务
*
*/
@property(nonatomic, readonly) NSObject<AUTELPanoramicPhotoMissionHandler>* _Nonnull panoramicPhotoMissionHandler;

/**
*  @brief The type of mission currently being executed, if no mission is executed, return AUTELMissionHandlerTypeUnknown.
*
*  当前正在执行的智能飞行任务类型，没有任务执行返回AUTELMissionHandlerTypeUnknown
*
*/
@property(nonatomic, readonly) AUTELMissionHandlerType runningMissionType;

/**
 *  @brief Upload current location of user to main controller.
 *
 *  上传用户的位置到无人机。
 *
 *  @param aLocation current location of user.
 *
 *  用户位置。
 *
 *  @discussion When executing follow me mission, this method must be invoked to get a tracing loction from aLocation. 
 *  If the aircraft is executing orbit mission and the hot point type is mobie point (AUTELHotPointMission.hotpointType = AUTELHotpointTypeMobilePoint), then this method must be invoked as well to get a hot point location from aLoction. 
 *  Call this method before executing any auto pilotiong mission to get a better performance. aLocation will be ignored if invoke this method with no executing mission.
 *
 *  当飞行器在执行追踪任务时，你必须调用这个方法，飞行器以 aLocation 为追踪的目标位置。
 *  如果飞行器在执行兴趣点环绕任务，且兴趣点的类型是移动点（AUTELHotPointMission.hotpointType = AUTELHotpointTypeMobilePoint）时，你也必须调用该方法，飞行器以 aLocation 作为兴趣点。
 *  建议你在飞行器执行追踪任务之前或执行环绕移动兴趣点的任务前就调用该方法。如果没有执行任务是调用该方法，飞行器将或略 aLocation。
 *
 *  @see AUTELFollowMeMission
 *  @see AUTELHotPointMission
 *  @see AUTELHotpointType
 */
- (void)updateUserCoordinate:(CLLocation *_Nonnull)aLocation;

@end
