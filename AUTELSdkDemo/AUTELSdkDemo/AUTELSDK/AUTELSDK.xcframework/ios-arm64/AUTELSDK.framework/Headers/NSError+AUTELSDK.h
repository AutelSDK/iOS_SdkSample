//
//  NSError+AUTELSDK.h
//  AUTELSDK
//
//  Created by IOS on 16/4/6.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//-----------------------------------------------------------------
#pragma mark - Error Domains
//-----------------------------------------------------------------
/**
 *  SDK common error domain
 */
FOUNDATION_EXPORT NSString * _Nonnull const AUTELSDKErrorDomain;

/**
 *  SDK flight controller domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKFlightControllerErrorDomain;

/**
 *  SDK remote controller domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKRemoteControllerErrorDomain;

/**
 *  SDK mission error domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKMissionErrorDomain;

/**
 *  SDK camera error domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKCameraErrorDomain;

/**
 *  SDK playback error domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKPlaybackErrorDomain;

/**
 *  SDK Gimbal error domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKGimbalErrorDomain;

/**
 *  SDK AirLink error domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKAirLinkErrorDomain;

/**
 *  SDK vision model error domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKVisionModelErrorDomain;

/**
 *  SDK Firmware Update Error Domain
 */
FOUNDATION_EXPORT NSString *_Nonnull const AUTELSDKFirmwareUpdateErrorDomain;

//-----------------------------------------------------------------
#pragma mark - Error UserInfo key
//-----------------------------------------------------------------
/**
 *  followMe max distance
 *
 *  追踪模式最大距离
 */
FOUNDATION_EXPORT NSString *_Nonnull const MaxFollowMeDistanceKey;

/**
 *  Number of unqualified waypoints uploaded
 *
 *  上传航点任务时不合格的航点数组
 */
FOUNDATION_EXPORT NSString *_Nonnull const NotPassWaypointArrayKey;

//-----------------------------------------------------------------
#pragma mark AUTELSDKErrorDomain
//-----------------------------------------------------------------

/**
 *  Define SDK error
 *
 *  定义 SDK 错误
 */
typedef NS_ENUM (NSInteger, AUTELSDKError){
    /**
     *  @brief Timeout error.
     *
     *  命令超时。
     */
    AUTELSDKErrorTimeout = -1000L,
    /**
     *  @brief Parameters invalid error
     *
     *  参数非法。
     */
    AUTELSDKErrorInvalidParameters = -1001L,
    /**
     *  @brief Command execute failed error.
     *
     *  命令执行失败。
     */
    AUTELSDKErrorCommandExecutionFailed = -1002L,
    /**
     *  @brief Send data failed error.
     *
     *  数据发送失败。
     */
    AUTELSDKErrorSendDataFailed = -1003L,
    /**
     *  @brief Product not support.
     *
     *  不支持
     */
    AUTELSDKErrorProductNotSupport = -1004L,
    /**
     *  @brief Device not found.
     *
     *  未连接设备
     */
    AUTELSDKErrorDeviceNotFound = -1005L,
    /**
     *  @brief Receive error data.
     *
     *  收到错误数据
     */
    AUTELSDKErrorReceiveInvalidData = -1006L,
    /**
     *  @brief The Altitude Limit value has been set lower than that of the Go Home Altitude.
     *
     *  设置高度限制低于自动返航高度
     */
    AUTELSDKErrorMaxHeightLessThanGoHomeAlitutde = -1007L,
    /**
     *  @brief The Go Home Altitude value has been set higher than that of the Altitude Limit.
     *
     *  设置自动返航高度大于高度限制
     */
    AUTELSDKErrorGoHomeAlitutdeHigherThanMaxHeight = -1008L,
    /**
     *  @brief Operation is cancelled.
     *
     *  操作被取消
     */
    AUTELSDKErrorOperationCancelled = -1009L,
    /**
     *  @brief Uploading file data error.
     *
     *  上传文件数据出错。
     */
    AUTELSDKErrorUploadFileDataError = -1010L,
    /**
     *  @brief Parsering file data error.
     *
     *  解析文件数据出错。
     */
    AUTELSDKErrorParserDataError = -1011L,
};

//-----------------------------------------------------------------
#pragma mark AUTELSDKFlightControllerError
//-----------------------------------------------------------------

/**
 *  Define flight control error.
 *
 *  定义飞控错误
 */
typedef NS_ENUM (NSInteger, AUTELSDKFlightControllerError) {
    /**
     *  @brief Flight mode or flight status error.
     *
     *  主模式或飞行状态错误。
     */
    AUTELSDKFlightControllerErrorModeError = -4000L,
    /**
     *  @brief Aircraft GPS weak.
     *
     *  飞行器 GPS 信号弱。
     */
    AUTELSDKFlightControllerErrorBadGPS = -4001L,
    /**
     *  @brief Aircraft low battery.
     *
     *  飞行器电量低。
     */
    AUTELSDKFlightControllerErrorLowBattery = -4002L,
    /**
     *  @brief Aircraft not record home point.
     *
     *  飞行器返航点无效。
     */
    AUTELSDKFlightControllerErrorHomePointNotRecord = -4003L,
    /**
     *  @brief Aircraft in a no fly zone.
     *
     *  飞行器到达禁飞区。
     */
    AUTELSDKFlightControllerErrorInNoFlyZone = -4004L,
    /**
     *  @brief Aircraft is flying.
     *
     *  飞行器正在飞行。
     */
    AUTELSDKFlightControllerErrorAircraftFlying = -4005L,
    /**
     *  @brief Aircraft is not fly.
     *
     *  飞行器没有在飞行
     */
    AUTELSDKFlightControllerErrorAircraftNotFly = -4006L,
    /**
     *  @brief The new home point is too far.
     *
     *  新返航点与飞行器距离过远。
     */
    AUTELSDKFlightControllerErrorHomePointTooFar = -4007L,
    /**
     *  @brief The motors are rotating.
     *
     *  电机正在转动。
     */
    AUTELSDKFlightControllerErrorMotorWorking = -4008L,
    /**
     *  @brief The motors are not rotating.
     *
     *  电机没有转动。
     */
    AUTELSDKFlightControllerErrorMotorNotWork = -4009L,
    /**
     *  @brief Compass abnormal.
     *
     *  指南针异常。
     */
    AUTELSDKFlightControllerErrorCompassError = -4010L,
    /**
     *  @brief Compass is Calibrating
     *
     *  指南针正在校准。
     */
    AUTELSDKFlightControllerErrorCompassIsCalibrationg = -4011L,
    /**
     *  @brief  The aircraft is going home.
     *
     *  飞行器正在返航
     */
    AUTELSDKFlightControllerErrorIsGoingHome = -4012L,
    /**
     *  @brief command Invalid.
     *
     *  不支持。
     */
    AUTELSDKFlightControllerErrorCommandInvalid = -4013L,
    /**
     *  @brief not supported.
     *
     *  不支持。
     */
    AUTELSDKFlightControllerErrorNotSupport = -4014L,
    /**
     *  @brief Aircraft low battery.
     *
     *  飞行器严重电量低。
     */
    AUTELSDKFlightControllerErrorCriticalLowBattery = -4015L,
    /**
     *  @brief Battery overheated
     *
     *  电池温度过高
     */
    AUTELSDKFlightControllerErrorBatteryOverheated = -4016L,
    /**
     *  @brief Battery overheated
     *
     *  电池温度过高
     */
    AUTELSDKFlightControllerErrorBatteryTemperatureLow = -4017L,
    /**
     *  @brief Remote controller signal lost
     *
     *  遥控器信号丢失
     */
    AUTELSDKFlightControllerErrorRCSignalLoss = -4018L,
    
    /**
     *  @brief Aircrafl is landing
     *
     *  飞行器正在降落
     */
    AUTELSDKFlightControllerErrorIsLanding = -4019L,
    
    /**
     *  @brief Unknow Error
     *
     *  未知错误
     */
    AUTELSDKFlightControllerErrorUnknowError = -4020L,
    
    /**
     *  @brief Unknow Error
     *
     *  没有国家禁飞区文件
     */
    AUTELSDKFlightControllerErrorNOCountryNFZFile = -4021L,
};

//-----------------------------------------------------------------
#pragma mark AUTELSDKMissionError
//-----------------------------------------------------------------

/**
 *  Define Autopilot error
 *
 *  定义自动飞行任务错误
 */
typedef NS_ENUM (NSInteger, AUTELSDKMissionError){
    /**
     *  @brief Flight mode or flight status error
     *
     *  主模式或飞行状态错误。
     */
    AUTELSDKMissionErrorModeError = -5000L,
    /**
     *  @brief Aircraft's GPS too weak.
     *
     *  飞行器 GPS 信号弱。
     */
    AUTELSDKMissionErrorAircraftBadGPS = -5001L,
    /**
     *  @brief Aircraft's battery too low.
     *
     *  飞行器电量低。
     */
    AUTELSDKMissionErrorAircraftLowBattery = -5002L,
    /**
     *  @brief Aircraft's not in the air.
     *
     *  飞行器没有在飞行。
     */
    AUTELSDKMissionErrorAircraftNotInTheAir = -5003L,
    /**
     *  @brief Aircraft is taking off.
     *
     *  飞行器起飞错误。
     */
    AUTELSDKMissionErrorAircraftTakingoff = -5004L,
    /**
     *  @brief Aircraft's home point not record.
     *
     *  飞行器返航点无效。
     */
    AUTELSDKMissionErrorAircraftHomePointNotRecord = -5005L,
    /**
     *  @brief Aircraft is in no fly zone.
     *
     *  飞行器到达禁飞区。
     */
    AUTELSDKMissionErrorAircraftInNoFlyZone = -5006L,
    /**
     *  @brief Aircraft is running a mission.
     *
     *  飞行器正在执行任务。
     */
    AUTELSDKMissionErrorAircraftRunningMission = -5007L,
    /**
     *  @brief Aircraft no running mission.
     *
     *  飞行器没有在执行任务。
     */
    AUTELSDKMissionErrorAircraftNoRunningMission = -5008L,
    /**
     *  @brief Aircraft no mission.
     *
     *  飞行器没有任务。
     */
    AUTELSDKMissionErrorAircraftNoMission = -5009L,
    /**
     *  @brief Aircraft is too far away to the mission.
     *
     *  飞行器在执行追踪任务追踪点离飞行器距离过远或兴趣点环绕任务时兴趣点离飞行器过远。
     */
    AUTELSDKMissionErrorAircraftFarAwayMission = -5010L,
    /**
     *  @brief Mission's total distance is too large.
     *
     *  航点任务的中距离过长。
     */
    AUTELSDKMissionErrorMissionTotalDistanceTooLarge = -5011L,
    /**
     *  @brief Mission resume failed.
     */
    AUTELSDKMissionErrorMissionResumeFailed = -5012L,
    /**
     *  @brief Uploading waypoints error.
     *
     *  上传任务数据出错。
     */
    AUTELSDKMissionErrorUploadMissionDataError = -5013L,
    /**
     *  @brief The aircraft is uploading or downloading the task data.
     *
     *  飞行器正在上传或下载任务数据。
     */
    AUTELSDKMissionErrorIsUploadingOrDownloadingMission = -5014L,
    /**
     *  @brief Task type error
     *
     *  任务类型错误。
     */
    AUTELSDKMissionErrorInvalidMissionClass = -5015L,
    /**
     *  @brief The waypoint number exceeds the allowable value.
     *
     *  航点个数过多。
     */
    AUTELSDKMissionErrorWaypointNumberOver = -5016L,
    /**
     *  @brief The waypoint number is 0.
     *
     *  航点个数为0。
     */
    AUTELSDKMissionErrorNoWaypoint = -5017L,
    /**
     *  @brief The waypoint coordinate is invalid.
     *
     *  航点坐标无效。
     */
    AUTELSDKMissionErrorWaypointCoorditionInvalid = -5018L,
    /**
     *  @brief The distance between the waypoint and the home point exceeds the allowable value.
     *
     *  航点离Home点太远。
     */
    AUTELSDKMissionErrorWaypopintTooFarAway = -5019L,
    /**
     *  @brief The waypoint exceeds the limt.
     *
     *  航点超出限制
     */
    AUTELSDKMissionErrorWaypointsExceedLimit = -5020L,
    /**
     *  @brief The GPS signal sent from the ground station is weak, or no GPS signal is sent.
     *
     *  地面站发送的 GPS 信号弱或没有发送 GPS。
     */
    AUTELSDKMissionErrorGrondStationBadGPS = -5021L,
    /**
     *  @brief The POI coordinate is invalid.
     *
     *  兴趣点坐标无效。
     */
    AUTELSDKMissionErrorHotPointCoorditionInvalid = -5022L,
    /**
     *  @brief The distance between the POI and the aircraft exceeds the allowable value.
     *
     *  兴趣点离飞行器太远。
     */
    AUTELSDKMissionErrorHotPointTooFarAwayForAircraft = -5023L,
    /**
     *  @brief The distance between the POI and the home point exceeds the allowable value.
     *
     *  兴趣点离Home点太远。
     */
    AUTELSDKMissionErrorHotPointTooFarAwayForHomePoint = -5024L,
    /**
     *  @brief The Orbit radius is too large.
     *
     *  兴趣点环绕半径太大。
     */
    AUTELSDKMissionErrorHotPointRadiusTooLarge = -5025L,
    /**
     *  @brief Downloading task data not supported.
     *
     *  不支持下载任务数据。
     */
    AUTELSDKMissionErrorNoSupportDownloadMission = -5026L,
    /**
     *  @brief Pausing and restarting task not supported.
     *
     *  不支持暂停和重启任务。
     */
    AUTELSDKMissionErrorNoSupportPauseAndResumMission = -5027L,
    /**
     *  @brief The Go Home mode is not supported.
     *
     *  不支持该返航模式。
     */
    AUTELSDKMissionErrorMissionNoSupportFinishMode = -5028L,
    /**
     *  @brief Autopilot not supported in Beginner mode.
     *
     *  新手模式不支持智能飞行
     */
    AUTELSDKMissionErrorNoSupportInBeginnerMode = -5029L,
    /**
     *  @brief 相机未连接
     */
    AUTELSDKMissionErrorCameraDisconnected = -5030L,
    /**
     *  @brief 飞行器高度过低
     */
    AUTELSDKMissionErrorAircraftAltitudeTooLow = -5031L,
    /**
     *  @brief 飞行器达到最大追踪半径
     */
    AUTELSDKMissionErrorReachMaximumTrackingRadius = -5032L,
    /**
     *  @brief 飞行器达到最大追踪半径
     */
    AUTELSDKMissionErrorReachMinimumTrackingRadius = -5033L,
    /**
     *  @brief 飞行器达到最大追踪半径
     */
    AUTELSDKMissionErrorReachMaximumTrackingAltitude = -5034L,
    /**
     *  @brief 飞行器达到最大追踪半径
     */
    AUTELSDKMissionErrorReachMinimumTrackingAltitude = -5035L,
    /**
     *  @brief Download waypoints error.
     *
     *  下载任务数据出错。
     */
    AUTELSDKMissionErrorDownloadMissionDataError = -5036L,
};

//-----------------------------------------------------------------
#pragma mark AUTELSDKRemoteControllerError
//-----------------------------------------------------------------

/**
 *  Define RC error
 *
 *  定义遥控器错误
 */
typedef NS_ENUM (NSInteger, AUTELSDKRemoteControllerError) {
    /**
     *  @brief RC not connected.
     *
     *  未连接遥控器。
     */
    AUTELSDKRCErrorNotFoundDevice = -6000L,
    /**
     *  @brief Incorrect RC command stick mode received.
     *
     *  收到错误的遥控器摇杆操控模式。
     */
    AUTELSDKRCErrorReceiveInvalidControlMode = -6001L,
    /**
     *  @brief Parameter error.
     *
     *  参数错误。
     */
    AUTELSDKRCErrorInvalidParameters = -6002L,
    /**
     *  @brief Not supported by RC.
     *
     *  遥控器不支持。
     */
    AUTELSDKRCErrorRCNotSupport = -6003L,
    /**
     *  @brief Get parameter failed error.
     *
     *  查询任务失败。
     */
    AUTELSDKRCErrorParameterGetFailed = -6004L,
    /**
     *  @brief Command execute failed error.
     *
     *  命令执行错误。
     */
    AUTELSDKRCErrorCommandExecutionFailed = -6005L,
    /**
     *  @brief Send data failed error.
     *
     *  发送数据错误。
     */
    AUTELSDKRCErrorSendDataFailed = -6006L,
    /**
     *  @brief Timeout error.
     *
     *  超时。
     */
    AUTELSDKRCErrorTimeout = -6007L,
    /**
     *  @brief RC disconnected
     *
     *  遥控器断开连接
     */
    AUTELSDKRCErrorDisconnected = -6008L,
};

//-----------------------------------------------------------------
#pragma mark AUTELSDKCameraError
//-----------------------------------------------------------------

/**
 *  Define camera error
 *
 *  定义相机错误
 */
typedef NS_ENUM(NSInteger, AUTELSDKCameraError) {
    /**
     *  @brief Command to cancel execution.
     *
     *  命令取消执行
     */
    AUTELSDKCameraErrorCommandExecutionCancelled = -7000L,
    
    /**
     *  @brief Command for execution failed.
     *
     *  命令执行失败
     */
    AUTELSDKCameraErrorCommandExecutionFailed = -7001L,
    
    /**
     *  @brief Unable to execute the command.
     *
     *  命令现在无法执行
     */
    AUTELSDKCameraErrorCommandCurrentlyNotEnabled = -7002L,
    
    /**
     *  @brief Incorrect data received.
     *
     *  收到错误数据
     */
    AUTELSDKCameraErrorReceiveBadData = -7003L,
    
    /**
     *  @brief Analyzing data failed.
     *
     *  解析数据失败
     */
    AUTELSDKCameraErrorAnalyDataFailed = -7004L,
    
    /**
     *  @brief No SD card.
     *
     *  没有 SD 卡
     */
    AUTELSDKCameraErrorSDCardNotInserted = -7005L,
    
    /**
     *  @brief SD card full.
     *
     *  SD 卡已满
     */
    AUTELSDKCameraErrorSDCardFull = -7006L,
    
    /**
     *  @brief SD card format error
     *
     *  SD 卡格式错误
     */
    AUTELSDKCameraErrorSDCardFormatError = -7007L,
    
    /**
     *  @brief SD card is formatting
     *
     *  SD 卡正在格式化
     */
    AUTELSDKCameraErrorSDCardIsFormatting = -7008L,
    
    /**
     *  @brief SD card is initializing
     *
     *  SD 卡正在初始化
     */
    AUTELSDKCameraErrorSDCardIsInitializing = -7009L,
    
    /**
     *  @brief SD card low speed
     *
     *  SD 卡是低速卡
     */
    AUTELSDKCameraErrorSDCardIsVerified = -7010L,
    
    /**
     *  @brief SD card error.
     *
     *  SD 卡错误
     */
    AUTELSDKCameraErrorSDCardError = -7011L,
    
    /**
     *  @brief Camera work mode error
     *
     *  相机工作模式错误
     */
    AUTELSDKCameraErrorWorkModeError = -7012L,
    
    /**
     *  Not supported command or command not support in this firmware.
     *
     *  不支持该请求，或当前固件不支持该请求
     */
    AUTELSDKCameraErrorFirmwareDoesNotSupportCommand = -7013L,
    
    /**
     *  @brief Camera not connected
     *
     *  相机未连接
     */
    AUTELSDKCameraErrorDisconnected = -7014L,
    
    /**
     *  @brief 相机对焦模式错误
     */
    AUTELSDKCameraErrorFocusModeError = -7015L,
    
    /**
     *  @brief 曝光模式错误
     */
    AUTELSDKCameraErrorExposureModeError = -7016L,
    
    /**
     *  @brief 自动测光被锁定
     */
    AUTELSDKCameraErrorAELockEnable = -7017L,
    
    /**
     * @brief 参数错误
     */
    AUTELSDKCameraErrorParamError = -7018L,
    
    /**
     *  @brief 视频分辨率过高
     */
    AUTELSDKCameraErrorVideoResolutionTooHight = -7019L,
    
    /**
     *  @brief 相机正在更新
     */
    AUTELSDKCameraErrorUpgrading = -7020L,
    
    /**
     *  @brief 视频帧率过高
     */
    AUTELSDKCameraErrorVideoFrameRateTooHight = -7021L,
    
    /**
     *  @brief ROI使能关闭
     */
    AUTELSDKCameraErrorImageRoiIsDisable = -7022L,
};

/**
 *  Define playback error
 *
 *  定义回放错误
 */
typedef NS_ENUM(NSInteger, AUTELSDKPlaybackError) {
    /**
     *  @brief AppTransportSecurity is not set in info.plist.
     *
     *  未在info.plist中设置AppTransportSecurity
     */
    AUTELSDKPlaybackErrorAppTransportSecurityRequiresSecureConnection = -8001L,
    /**
     *  @brief Request timed out.
     *
     *  请求超时
     */
    AUTELSDKPlaybackErrorTimedout = -8002L,
    /**
     *  @brief Relevant file not found in the SD card
     *
     *  SD卡中无相关文件
     */
    AUTELSDKPlaybackErrorDeleteFileNotExist = -8003L,
    /**
     *  @brief Storage path for downloaded files not set
     *
     *  未设置下载存储路径
     */
    AUTELSDKPlaybackErrorLackOfDownloadDestinationPath = -8004L,
    /**
     *  @brief Unable to create the specified storage path for downloaded files
     *
     *  无法创建指定的下载存储路径
     */
    AUTELSDKPlaybackErrorInvalidDownloadDestinationPath = -8005L,
    /**
     *  @brief Sytem memory insufficient
     *
     *  系统内存不足
     */
    AUTELSDKPlaybackErrorInsufficientSystemMemory = -8006L,
    /**
     *  @brief The system is busy retrieving the file list.
     *
     *  系统繁忙,正在获取文件列表
     */
    AUTELSDKPlaybackErrorBusyWithFetchFileList = -8007L,
    /**
     *  @brief The system is busy retrieving the file thumbnails.
     *
     *  系统繁忙,正在获取文件缩略图
     */
    AUTELSDKPlaybackErrorBusyWithFetchThumbnail = -8008L,
    /**
     *  @brief The system is busy retrieving the previews.
     *
     *  系统繁忙,正在获取预览图
     */
    AUTELSDKPlaybackErrorBusyWithFetchPreview = -8009L,
    /**
     *  @brief The system is busy deleting the files.
     *
     *  系统繁忙,正在删除文件
     */
    AUTELSDKPlaybackErrorBusyWithDeleteFile = -8010L,
    /**
     *  @brief The system is busy downloading the original files.
     *
     *  系统繁忙,正在下载原始文件
     */
    AUTELSDKPlaybackErrorBusyWithDownloadOriginalFile = -8011L,
    /**
     *  @brief Not deleting.
     *
     *  未在进行删除操作
     */
    AUTELSDKPlaybackErrorNotInDeletingFile = -8012L,
    /**
     *  @brief Not downloading.
     *
     *  未在进行下载操作
     */
    AUTELSDKPlaybackErrorNotInDownloadingFile = -8013L,
    /**
     *  @brief There is no playerItem for image file.
     *
     *  图片文件无playerItem
     */
    AUTELSDKPlaybackErrorNoPlayerItemForImageFile = -8014L,
    /**
     *  @brief Camera has disconnected.
     *
     *  相机已断开连接
     */
    AUTELSDKPlaybackErrorCameraDisconnected = -8015L,
    /**
     *  @brief No SD card.
     *
     *  无 SD 卡
     */
    AUTELSDKPlaybackErrorNoSDCard = -8016L,
};

/**
*  Define gimbal error.
*
*  定义云台错误
*/
typedef NS_ENUM(NSInteger, AUTELSDKGimbalError) {
    
    /**
     *  @brief Not supported by gimbal.
     *
     *  云台不支持。
     */
    AUTELSDKGimbalErrorGimbalNotSupport = -9001L,
    
    /**
     *  @brief Gimbal's current work mode can not run some command
     */
    AUTELSDKGimbalErrorWorkModeError = -9002L,
    
    /**
     *  @brief Rotation 
     */
    AUTELSDKGimbalErrorInvalidParameters = -9003L,
    
    /**
     * @brief 不支持将云台工作模式设置为该模式
     */
    AUTELSDKGimbalErrorUnsupportSetToThisWorkMode = -9004L,
    
    /**
     * @brief 收到错误数据
     */
    AUTELSDKGimbalErrorReceiveBadData = -9005L,
    
    /**
     *  @brief Command execute failed error.
     *
     *  命令执行错误。
     */
    AUTELSDKGimbalErrorCommandExecutionFailed = -9006L,
    
    /**
     *  @brief The drone's motors are rotating.
     *
     *  飞行器电机正在转动。
     */
    AUTELSDKGimbalErrorDroneMotorWorking = -9007L,
    
    /**
     * @brief 不支持将云台设置为该角度范围类型
     */
    AUTELSDKGimbalErrorUnsupportSetToThisAngleRangeType = -9008L,
};

/**
*  Define airLink error.
*
*  定义图传错误
*/
typedef NS_ENUM(NSInteger, AUTELSDKAirLinkError) {
    AUTELSDKAirLinkErrorDisconnected = -10000L,
    /**
     *  @brief Rotation
     */
    AUTELSDKAirLinkErrorInvalidParameters = -10001L,
    /**
     * @brief 收到错误数据
     */
    AUTELSDKAirLinkErrorReceiveBadData = -10002L,
    /**
     *  Not supported command or command not support in this firmware.
     *
     *  不支持该请求，或当前固件不支持该请求
     */
    AUTELSDKAirLinkErrorFirmwareDoesNotSupportCommand = -10003L,
};

/**
*  Define vision error.
*
*  定义视觉错误
*/
typedef NS_ENUM(NSInteger, AUTELSDKVisionModelError) {
    
    AUTELSDKVisionModelErrorFlightControlInFailSafeMode = -11000L,
    
    AUTELSDKVisionModelErrorBrightnessWeak = -11001L,
    
    AUTELSDKVisionModelErrorBrightnessStrong = -11002L,
    
    AUTELSDKVisionModelErrorOpticalFlowModelError = -11003L,
    
    AUTELSDKVisionModelErrorCancelByRC = -11004L,
    
    AUTELSDKVisionModelErrorCannotConfirmTrackTarget = -11005L
};

/**
*  Define firmware update error.
*
*  定义固件升级错误
*/
typedef NS_ENUM(NSInteger, AUTELSDKFirmwareUpdateError) {
    AUTELSDKFirmwareUpdateErrorReadFileFaile = -12000L,
    
    /**
    *  @brief firmware Upload Faile
    *
    *  固件上传失败
    */
    AUTELSDKFirmwareUpdateErrorUploadFaile = -12001L,
    
    /**
    *  @brief Aircraft Armed
    *
    *  飞行器电机启动
    */
    AUTELSDKFirmwareUpdateErrorAircraftArmed = -12002L,
    
    /**
    *  @brief NoCard
    *
    *  无 SD 卡
    */
    AUTELSDKFirmwareUpdateErrorNoCard = -12003L,
    
    /**
    *  @brief Device Low Battery
    *
    *  设备电量低
    */
    AUTELSDKFirmwareUpdateErrorDeviceLowBattery = -12004L,
    
    /**
    *  @brief RC Low Battery
    *
    *  遥控器电量低
    */
    AUTELSDKFirmwareUpdateErrorRCLowBattery = -12005L,
    
    /**
    *  @brief Card Failure
    *
    *  相机 SD 写入错误
    */
    AUTELSDKFirmwareUpdateErrorCardFailure = -12006L,
    
    /**
    *  @brief No Firmware Zip
    *
    *  固件不存在
    */
    AUTELSDKFirmwareUpdateErrorNoFirmwareZip = -12007L,
    
    /**
    *  @brief Unzip Failed
    *
    *  固件解压失败
    */
    AUTELSDKFirmwareUpdateErrorUnzipFailed = -12008L,
    
    /**
    *  @brief camera is working
    *
    *  相机正在拍照或录像
    */
    AUTELSDKFirmwareUpdateErrorIsCameraWorking = -12009L,
    
    /**
    *  @brief Card Space Insufficient
    *
    *  SD 卡空间不足
    */
    AUTELSDKFirmwareUpdateErrorCardSpaceInsufficient = -12010L,
    
    /**
    *  @brief Master Slaver Mode
    *
    *  当前为主从模式
    */
    AUTELSDKFirmwareUpdateErrorMasterSlaverMode = -12011L,
};

@interface NSError(AUTELSDK)

///**
// *  Get AUTELSDKError
// *
// *  @param errorCode errorCode for AUTELSDKError
// */
//+ (_Nullable instancetype)AUTELSDKErrorForCode:(NSInteger)errorCode;
//
///**
// *  Get AUTELSDKCameraError
// *
// *  @param errorCode errorCode for AUTELSDKCameraError
// */
//+ (_Nullable instancetype)AUTELSDKCameraErrorForCode:(NSInteger)errorCode;
//
///**
// *  Get AUTELSDKFlightControllerError
// *
// *  @param errorCode errorCode for AUTELSDKFlightControllerError
// */
//+ (_Nullable instancetype)AUTELSDKFlightControllerErrorForCode:(NSInteger)errorCode;
//
///**
// *  Get AUTELSDKMissionError
// *
// *  @param errorCode errorCode for AUTELSDKMissionError
// */
//+ (_Nullable instancetype)AUTELSDKMissionErrorForCode:(NSInteger)errorCode;
//
///**
// *  Get AUTELSDKRegistrationError
// *
// *  @param errorCode errorCode for AUTELSDKRegistrationError
// */
//+ (_Nullable instancetype)AUTELSDKRegistrationErrorForCode:(AUTELSDKRegistrationError)errorCode;

/**
 *  Get AUTELSDKError
 *
 *  @param errorCode errorCode for AUTELSDKError
 *  @param errorDomain domain for AUTELSDKError
 *  @param desc desc for AUTELSDKError
 */
+ (_Nullable instancetype)AUTELSDKErrorForCode:(NSInteger)errorCode domain:(NSString *_Nonnull)errorDomain desc:(const NSString *_Nonnull)desc;

/**
 *  Get AUTELSDKError
 *
 *  @param errorCode errorCode for AUTELSDKError
 *  @param errorDomain domain for AUTELSDKError
 *  @param desc desc for AUTELSDKError
 *  @param info info for AUTELSDKError
 */
+ (_Nullable instancetype)AUTELSDKErrorForCode:(NSInteger)errorCode domain:(NSString *_Nonnull)errorDomain desc:(const NSString *_Nonnull)desc userInfo:(NSDictionary *)info;

@end

NS_ASSUME_NONNULL_END
