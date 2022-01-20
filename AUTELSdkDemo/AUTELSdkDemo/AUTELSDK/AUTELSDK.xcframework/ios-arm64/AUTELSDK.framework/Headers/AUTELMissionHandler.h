//
//  AUTELMissionHandler.h
//  AUTELSDK
//
//  Created by IOS on 16/3/2.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELMission.h>

/**
 *  Autopilot type
 *
 *  智能飞行任务类型
 */
typedef NS_ENUM(uint8_t, AUTELMissionHandlerType) {
    /**
     *  @brief Not performing any task.
     *
     *  没有执行任务
     */
    AUTELMissionHandlerTypeUnknown,
    /**
     *  @brief Waypoint task
     *
     *  航点飞行
     */
    AUTELMissionHandlerTypeWaypoint,
    /**
     *  @brief Obrit task
     *
     *  环绕飞行
     */
    AUTELMissionHandlerTypeHotPoint,
    /**
     *  @brief Follow task
     *
     *  追踪
     */
    AUTELMissionHandlerTypeFollowMe,
    /**
     *  @brief Track task
     *
     *  智能追踪
     */
    AUTELMissionHandlerTypeTrack,
    /**
    *  @brief view point task
    *
    *  指点飞行
    */
    AUTELMissionHandlerTypeViewpoint,
    /**
    *  @brief One shot video task
    *
    * 一键短片
    */
    AUTELMissionHandlerTypeOneShotVideo,
    /**
    *  @brief Precision Flight task
    *
    * 精准飞行
    */
    AUTELMissionHandlerTypeTripod,
    /**
    *  @brief Dual Stability task
    *
    *  影像增稳
    */
    AUTELMissionHandlerTypePhotographer,
    /**
    *  @brief Gesture task
    *
    *  手势识别
    */
    AUTELMissionHandlerTypeGesture,
    /**
    *  @brief time-lapse photography  task
    *
    *  延时摄影
    */
    AUTELMissionHandlerTypeDelayShot,
    /**
    *  @brief Vision Orbit task
    *
    *  视觉环绕
    */
    AUTELMissionHandlerTypeVisionOrbit,
    /**
    *  @brief Vision Orbit time-lapse photography  task
    *
    *  环绕延时摄影
    */
    AUTELMissionHandlerTypeOrbitDelayShot,
    /**
    *  @brief Panoramic photography  task
    *
    *  全景拍摄摄影
    */
    AUTELMissionHandlerTypePanoramicPhoto
};


/**
 *  Autopilot task state
 *
 *  智能飞行任务状态
 */
typedef NS_ENUM(uint8_t, AUTELMissionHandlerState) {
    /**
     *  @brief Idle
     *
     *  空闲
     */
    AUTELMissionHandlerStateIdle,
    /**
     *  @brief Uploading task
     *
     *  正在上传任务
     */
    AUTELMissionHandlerStateUploadMissionData,
    /**
     *  @brief Downloading task
     *
     *  正在下载任务
     */
    AUTELMissionHandlerStateDownloadMissionData,
};

/**
 *  Protocols for Autopilot are used to download, perform, stop, and pause Autopilot tasks.
 *
 *  处理智能飞行任务的协议,用于下载,上传,执行,停止,暂停任务。
 *
 *  @see AUTELNavigation
 */
@protocol AUTELMissionHandler < NSObject >


/**
 用于需求扩展
 */
/**
*  @brief Used for demand expansion
*
*  用于需求扩展
*/
@property (nonatomic, strong) NSMutableDictionary *extraDic;

/**
 *  @brief Type for AUTELMissionHandler
 *
 *  AUTELMissionHandler 的类型
 *
 *  @see AUTELMissionHandlerType
 */
@property (assign, nonatomic, readonly) AUTELMissionHandlerType handlerType;

/**
 *  @brief Return to the state of "uploading or downloading the task data"
 *
 *  返回是否正在上传或下载任务数据
 *
 *  @see AUTELMissionHandlerState
 */
@property (nonatomic, readonly) AUTELMissionHandlerState handlerState;

/**
 *  @brief Whether the aircraft is performing or about to perform the handlerType task
 *  If handlerType = AUTELMissionHandlerTypeWaypoint, isRunning means the state of "whether the aircraft is performing or about to perform the Waypoint task"
 *  If handlerType = AUTELMissionHandlerTypeHotPoint, isRunning means the state of "whether the aircraft is performing or about to perform the Orbit task"
 *  If handlerType = AUTELMissionHandlerTypeFollowMe, isRunning means the state of "whether the aircraft is performing or about to perform the Follow task"
 *  Other tasks are the same.
 *
 *  飞行器是否正在执行或即将执行 handlerType 类型的任务。
 *  如果 handlerType = AUTELMissionHandlerTypeWaypoint，isRunning 表示飞行器是否正在执行或即将执行航点任务。
 *  如果 handlerType = AUTELMissionHandlerTypeHotPoint，isRunning 表示飞行器是否正在执行或即将执行热点环绕任务。
 *  如果 handlerType = AUTELMissionHandlerTypeFollowMe，isRunning 表示飞行器是否正在执行或即将执行追踪任务。
 *  其他任务照此类推。
 *
 *  @see handlerType
 */
@property (nonatomic, readonly) BOOL isRunning;


/**
 *  @brief Check if the task parameter is correct.
 *
 *  检查mission参数是否正确
 *
 *  @param mission    Mission object.
 *
 *  待检查的任务。
 *
 *  @param completion   Execution result: if the task data is legal, error is nil; otherwise error contains the error message.
 *
 *  执行结果回调，如果任务数据合法，error 为 nil，否则 error 包含错误信息。
 *
 *  @discussion If handlerType = AUTELMissionHandlerTypeWaypoint, the mission must be an instance from AUTELFollowMeMission.
 *  If handlerType = AUTELMissionHandlerTypeWaypoint, the mission must be an instance from AUTELHotPointMission.
 *  If handlerType = AUTELMissionHandlerTypeFollowMe, the mission must be an instance from AUTELFollowMeMissio
 *
 *  如果 handlerType = AUTELMissionHandlerTypeWaypoint，mission 必须是 AUTELWaypointMission 实例。
 *  如果 handlerType = AUTELMissionHandlerTypeHotPoint，mission 必须是 AUTELHotPointMission 实例。
 *  如果 handlerType = AUTELMissionHandlerTypeFollowMe，mission 必须是 AUTELFollowMeMission 实例。
 *
 *  @see handlerType
 *  @see AUTELWaypointMission
 *  @see AUTELHotPointMission
 *  @see AUTELFollowMeMission
 */
- (void)checkMission:(AUTELMission *)mission withCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Prepares the mission for execution. For the waypoint mission, data needs to be uploaded to the aircraft (product) and the
 *  AUTELMissionProgressHandler can be used to monitor upload progress. The follow-me, panorama, hotpoint and custom missions
 *  require much shorter time for the preparation phase. PrepareMission should fail if a mission is currently executing.
 *
 *  准备当前要执行的任务。若当前任务是航点飞行任务，需要先把航点数据上传到飞行器，同时 preparationProgress 会返回当前准备任务的进度状态。若当前任务是追踪或热点环绕任务，只需要更短的时间准备，没有进度状态返回。任务准备完毕后，completion会有结果回调，若准备任务时已经有任务正在执行，completion则会是任务失败的结果回调。
 *
 *  @param mission Mission object.
 *
 *  任务对象
 *
 *  @param preparationProgress Progress handler callback method to monitor preparation progress .
 *
 *  监控当前准备任务进度的block回调.
 *
 *  @param completion The callback method after execution is finished
 *
 *  方法执行完毕的结果block回调
 */
- (void)prepareMission:(AUTELMission *)mission withProgress:(AUTELMissionProgressHandler)preparationProgress withCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Download flight task from aircraft: only available when the aircraft is ready for the given flight task.
 *
 *  从飞行器下载飞行任务，该方法只在无人机有飞行任务已经准备完毕的情况下才有效。
 *
 *  @param downloadProgress Progress handler callback method to monitor download progress. 
 *
 *  下载任务的进度回调
 *
 *  @param completion Completion block. 
 *
 *  下载任务完成的结果回调
 */
- (void)downloadMissionWithProgress:(AUTELMissionProgressHandler)downladProgress withCompletion:(AUTELMissionDownloadCompletionBlock)completion;

/**
 *  @brief Start performing the task: only available when the task is prepared successfully.
 *
 *  开始执行任务，只有成功准备任务后执行才有效。
 *
 *  @param completion Completion block. 
 *
 *  结束回调 block。
 *
 *  @discussion Only when flying in GPS mode can the aircraft perform the task successfully.
 *
 *  只有在无人机处于GPS模式且已经起飞的状态才能过成功执行任务
 */
- (void)startMissionExecutionWithCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Pauses the current mission being executed and the aircraft will hover in its current location. Current state
 *  will be saved until resumeMissionExecutionWithCompletion is called.
 *
 *  暂停当前飞行任务，无人机会在当前位置悬停。当前状态会被保存，直到调用 -resumeMissionExecutionWithCompletion:completion 恢复飞行任务。
 *
 *  @param completion Completion block. 命令结束回调
 */
- (void)pauseMissionExecutionWithCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Resumes the currently paused mission.
 *
 *  恢复当前被暂停的飞行任务。
 *
 *  @param completion Completion block. 
 *
 *  命令结束回调。
 */
- (void)resumeMissionExecutionWithCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Stops the current mission. The aircraft will hover in place.
 *
 *  取消当前飞行任务，无人机悬停在当前位置
 *
 *  @param completion Completion block. 
 *
 *  命令结束回调
 */
- (void)stopMissionExecutionWithCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Reset aircraft nose. In Waypoint mode, this commands the aircraft nose to face the next waypoint. In Follow mode, this commands the aircraft nose to face the target to be followed. In Orbit mode, this commands the aircraft nose to face the Point of Interest.
 *
 *  机头方向回中。如果飞行器在执行航点任务，该方法让飞行器机头与飞行方向一致；如果飞行器在执行追踪任务，该方法让飞行器机头朝向追踪点；如果飞行器在执行热点环绕任务，该方法让飞行器朝向热点。
 *
 *  @param completion Completion block. 
 *
 *  完成 block。
 */
- (void)facePOIWithCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Return to the cached flight task.
 *
 *  返回缓存的飞行任务
 *
 *  @discussion Everytime the `-prepareMission:withProgress:withCompletion:` or `- downloadMissionWithProgress:withCompletion:` is completed successfully, the uploaded and downloaded flight tasks will be cached automatically. When the aircraft is disconnected from the app, the cache will be deleted.
 *
 *  每次成功执行 -prepareMission:withProgress:withCompletion: 或 - downloadMissionWithProgress:withCompletion: 后都会缓存上传和下载的飞行器任务，当 App 与 飞行断开连接后，缓存被清除。
 */
- (AUTELMission *)getMission;

/**
 *  @brief Return whether current mission can be paused.
 *
 *  飞行器是否处于暂停任务状态
 *
 *  @return YES if mission can be paused. No if mission can not be paused.
 *
 *  飞行器处于暂停执行任务状态，返回 YES，否则返回 NO。
 */
- (BOOL)isPausable;
@end
