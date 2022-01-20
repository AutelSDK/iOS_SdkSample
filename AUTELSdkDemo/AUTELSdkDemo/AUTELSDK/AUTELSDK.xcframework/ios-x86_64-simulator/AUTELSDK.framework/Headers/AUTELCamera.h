//
//  AUTELCamera.h
//  AUTELSDK
//
//  Created by Autel on 15/10/22.
//  Copyright © 2015年 Autel. All rights reserved.
//
#import "AUTELCameraObject.h"
#import "AUTELCameraSettingsDef.h"
#import "AUTELCameraSystemState.h"
#import <AUTELSDK/AUTELCameraObject.h>
#import "AUTELSDK/AUTELCameraError.h"
#import <UIKit/UIKit.h>
@class MessageQueueNote;
@class AUTELCamera;
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@protocol AUTELCameraDelegate <NSObject>

@required
///**
// *  Update the camera's system state. User should call the startCameraSystemStateUpdates
// *  interface to begin the update.
// *
// *  @param systemState The camera's system state.
// */
//- (void)camera:(AUTELCamera *)camera didUpdateSystemState:(AUTELCameraSystemState *)systemstate;

@optional
/**
 * 处理系统主动发送的消息
 *
 * Handling messages sent by the system
 *
 **/
- (void)camera:(AUTELCamera *)camera didReceiveSystemNotice:(AUTELCameraSystemNotice *)systemsNotice __deprecated;

/**
 * 相机状态发生变化。只有在一英寸相机上才会回调
 *
 * The camera status has changed. Callback only on a one inch camera
 */
- (void)cameraDidUpdateSystemStatus:(AUTELCamera *)camera __deprecated;




@end
@protocol AUTELHttpCameraDelegate <NSObject> 

@optional

/**
 * 收到相机推送消息
 *
 * Receive camera push message
 */
- (void)camera:(AUTELCamera *)camera didReceiveSelfieCameraPushMessage:(NSDictionary *)result __deprecated;


/**
 * 收到系统状态，已转换格式
 *
 * Received system status, converted format
 */
- (void)camera:(AUTELCamera *)camera didReceiveInchCameraStatus:(NSArray *)array __deprecated;

@end

/**
*  @warning    __deprecated
*/
@interface AUTELCamera : AUTELCameraObject

@property (nonatomic, weak) id<AUTELCameraDelegate> delegate;
@property (nonatomic, copy) AUTELListResultBlock thumbBlock;
@property (nonatomic, weak) id<AUTELHttpCameraDelegate> selfieCameradelegate;

/**
 * 获取相机IP地址
 *
 * Get the camera IP address
 */
-(NSString *)fetchCameraAddress  __deprecated;

@end
//@interface AUTELCamera (Clear)
//
///**
// * 清理消息队列
// *
// * Clear camera queue
// *
// * @attention e.g 退出请求缩略图时，清理队列
// */
//- (void)ClearCameraNoteQueue;
///**
// * 清理本地沙盒
// *
// * clear camera photo local cache
// */
//- (void)clearCameraPhotoLocalCache;
//
//@end
@interface AUTELCamera (CameraSettings) 
///**
// * 获取相机模式
// *
// * method GetCameraMode
// * workmode Record、Singl、Burst、Time-lapse、AEB
// */
//- (void)getCameraMode:(void (^)(CameraWorkMode  workMode, AUTELCameraError* error))block;
///**
// * 设置相机模式
// *
// * method SetCameraMode
// * workmode Record、Singl、Burst、Time-lapse、AEB
// */
//- (void)setCameraMode:(CameraWorkMode)mode withResultBlock:(AUTELResultBlock)block;
//
//
//
//
///**
// * 获取相机的所有设置项 paramKey＝@"setting"
// *
// * Get all the settings for the camera
// *
// * @param block Return an array of all settings 返回所有设置的数组
// **/
//-(void)getCameraAllSetting:(AUTELOptionsResultBlock)block; //飞机
- (void)getCameraAllSettings:(void (^)(NSDictionary *result, AUTELCameraError *error))block  __deprecated; //小手持
///**
// * 获取相机的所有设置状态项 paramKey＝@"status"
// *
// * Get all the settings status items of the camera
// *
// * @param block Returns an array of all set states 返回所有设置状态的数组
// **/
//-(void)getCameraAllStatus:(AUTELOptionsResultBlock)block;
//
//
///**
// * 使用模式拍照，如果拍摄模式为CameraMultiCapture或CameraContinuCapture，则应调用StopTakePhotoWithResult停止拍照。在调用此API之前，用户应该检查sd caard状态。
// *
// *  Take photo with mode, if the capture mode is CameraMultiCapture or CameraContinousCapture, you should call stopTakePhotoWithResult to stop photoing. User should check the SD caard state before call this api.
// *
// *  @param block  The remote execute result.
// *
// *  @attention For the Inspire/Phantom 3 PRO/Phantom 3 Advanced camera, should switch camera mode to CameraWorkModeCapture.
// */
//-(void) startTakePhotowithResult:(AUTELResultBlock)block;
///**
// * 停止拍照
// *
// * stop take photo
// *
// * @param block  The remote execute result.返回操作结果
// *
// * @attention 在连拍和间隔拍模式
// **/
//-(void) stopTakePhotowithResult:(AUTELResultBlock)block;
//
///**
// * 切换相机模式
// *
// * set camera mode
// *
// * @param CameraWorkMode 拍照 录像 间隔拍 定时拍
// **/
//- (void) setCameraWorkMode:(CameraWorkMode)mode;
//
///**
// *  开始录制。 用户应在调用此API之前检查SD卡状态。
// *
// *  Start recording. User should check the SD caard state before call this api.
// *
// *  @param block The remote execute result callback.
// *
// *  @attention For the Inspire/Phantom 3 PRO/Phantom 3 Advanced camera, should switch camera mode to CameraWorkModeRecord.
// */
//-(void) startRecord:(AUTELResultBlock)block;
//
///**
// *  停止录制
// *
// *  Stop recording
// *
// *  @param block The remote execute result callback.
// */
//-(void) stopRecord:(AUTELResultBlock)block;
//
///**
// * 获取当前可选分辨率列表
// *
// * Get the current list of available resolutions
// *
// * @attention 不同的帧率下分辨率列表不同
// * @param block 返回的列表字典
// **/
//-(void) getCameraResolutionList:(void(^)(NSDictionary *result, AUTELCameraError *err))block;
//
/////**
//// * 获取当前设置的分辨率
//// *
//// * @attention 不同机型分辨率描述不同
//// **/
////-(void) getCameraCurrentResolution:(void (^)(CameraRecordingResolutionType, AUTELCameraError *err))block;
//
///**
// * 设置当前设置的分辨率
// *
// * Set the resolution of the current setting
// *
// * @attention 不同机型分辨率描述不同 Different models have different resolution descriptions
// **/
//-(void) setCameraResolution:(CameraRecordingResolutionType) type withResult:(AUTELResultBlock)block;
//
///**
// * 获取帧率列表
// *
// * Get frame rate list
// *
// **/
//-(void) getCameraFpsList:(void (^)(NSDictionary *result, AUTELCameraError *err))block;
///**
// * 设置当前分辨率
// *
// * set camera Fps
// *
// * @param CameraVideoFrameRate type 30Fps 为最佳设置
// **/
//-(void) setCameraFps:(CameraVideoFrameRate)type withResult:(AUTELResultBlock)block;
///**
// * 获取缩略图文件夹
// *
// * Get thumbnail folder
// *
// * @attention Get the SD card folder list and get the file list under the folder, the same command ID  获取SD卡文件夹列表和获取文件夹下的文件列表，相同命令ID
// **/
//-(void) getCameraSDFilefolderList:(void(^)(NSDictionary *result, AUTELCameraError *err))block;
//
/////**
//// * 获取缩略图文件夹下的文件列表
//// *
//// **/
////-(void) getCameraSDFileNameList:(void(^)(NSDictionary *result, AUTELCameraError *err))block;
////
////-(void) setCameraFps:(CameraVideoFrameRate)type withResult:(AUTELResultBlock)block;
//
//
///**
// * 获取缩略图文件夹下的文件列表
// *
// * Get the list of files under the thumbnail folder
// **/
//-(void) getCameraSDFileList:(void(^)(NSDictionary *result, AUTELCameraError *err))block;
///**
// * 删除sd卡文件
// *
// * Delete sd card file
// *
// * @param path 文件绝对路径
// **/
//-(void) deleteCameraSDFileInPath:(NSString *)path withResult:(AUTELResultBlock)block;
///**
// * 获取缩略图
// *
// * get camera thumb image in path
// *
// * @attention 缩略图数据在8787端口
// **/
//-(void) getCameraThumbImageInPath:(NSString *)path withResult:(void(^)(NSDictionary *result, AUTELCameraError *err))block  __deprecated;
//
///**
// * 获取缩略图
// *
// * get camera thumb image
// *
// **/
//- (void)getCameraThumbImageWithPath:(NSString *)path completion:(void (^)(UIImage *image, NSError *error))completion;
//
///**
// *  设置照片的像素大小。 拍照后，相机将使用此尺寸存储照片。
// *
// *  Set the photo's pixel size. The camera will used this size to storage photo after taking photo.
// *
// *  @param photoSize Photo's pixel size
// *  @param block     The remote execute result callback.
// */
//-(void) setCameraPhotoSize:(CameraPhotoSizeType)photoSize withResultBlock:(AUTELResultBlock)block;
//
///**
// *  获取相机的照片像素大小参数列表。
// *
// *  Get the camera's photo pixel size parameter list.
// *
// *  @param block The remote execute result callback.
// */
//-(void) getCameraPhotoSizeLIST:(void (^)(NSDictionary * RESULT, AUTELCameraError* error))block;
//
///**
// *  设置连拍张数
// *
// *  Set multi capture count.
// *
// *  @param count Multi capture count
// *  @param block The remote execute result callback.
// */
//-(void) setMultiCaptureCount:(CameraMultiCaptureCount)count withResultBlock:(AUTELResultBlock)block;
//
///**
// *  获取连拍张数数组
// *
// *  Get multi capture count list.
// *
// *  @param block The remote execute result callback.
// */
//-(void) getMultiCaptureCountList:(void(^)(NSDictionary *result, AUTELCameraError* error))block;
///**
// * 设置定时拍间隔
// *
// * Set the timer interval
// *
// * @param timelapae 间隔时间
// **/
//-(void) setTimeLapse:(CameraTimeLapse)timeLapse withResultBlock:(AUTELResultBlock)block;
///**
// * 获取timelapse设置列表
// *
// * Get the list of timelapse settings
// *
// * @attention Different models return different 不同机型返回不同
// **/
//-(void) getTimeLapseList:(void(^)(NSDictionary *result, AUTELCameraError* error))block;
//
///**
// * 获取当前录像时间
// *
// * Get current recording time
// */
//-(void) getCameraVideoTime:(void(^)(NSDictionary *result, AUTELCameraError* error))block;
//
///**
// * 获取当前可拍照照片数
// *
// * Get the current number of photos you can take
// */
//-(void) getCameraFSPhotos:(void(^)(NSDictionary *result, AUTELCameraError* error))block;
//
///**
// * 获取piv设置列表
// *
// * Get the list of piv settings
// **/
//-(void) getCameraPivList:(void(^)(NSDictionary *result, AUTELCameraError* error))block;
///**
// * 设置piv参数
// *
// * set camera piv
// *
// * @param piv photo in video
// **/
//-(void) setCameraPiv:(CameraPiv)vpiv withResultBlock:(AUTELResultBlock)block;
/////**
//// * 获取录像格式列表
//// **/
////-(void) getCameraRecordFormatList:(void(^)(NSDictionary *result, AUTELCameraError* error))block;
///**
// * 设置录像格式
// *
// * set camera record format
// **/
//-(void) setcameraRecordFormat:(CameraRecordFormat)recordFormat withResultBlock:(AUTELResultBlock)block;
///**
// * 设置照片格式
// *
// * set camera photo format
// *
// * @attention A7无此设置
// **/
//-(void) setCameraPhotoFormat:(CameraPhotoFormatType)photoFormat withResultBlock:(AUTELResultBlock)block;
//
///**
// *  设置相机白平衡参数
// *
// *  Set the camera's white balance parameter.
// *
// *  @param whiteBalance White balance parameter.
// *  @param block        The remote execute result callback. CameraWBStruct typeStruct = { type, 2000,};
// */
////-(void) setCameraWhiteBalance:(CameraWhiteBalanceType)whiteBalance withResultBlock:(AUTELResultBlock)block;
//-(void) setCameraWhiteBalance:(CameraWBStruct)whiteBalance withResultBlock:(AUTELResultBlock)block;
///**
// * 设置相机曝光值
// *
// * set camera exposure compensation
// *
// * @param compensationType 曝光补偿
// */
//-(void) setCameraExposureCompensation:(CameraExposureCompensationType)compensationType withResultBlock:(AUTELResultBlock)block;
//
///**
// *  设置相机的清晰度参数
// *
// *  Set the camera's sharpness parameter.
// *
// *  @param sharpness Camera's sharpness parameter.
// *  @param block     The remote execute result callback.
// */
//-(void) setCameraSharpness:(CameraSharpnessType)sharpness withResultBlock:(AUTELResultBlock)block;
///**
// * 设置相机制式
// *
// * set camera system type
// *
// * @attention 更改制式需重新获取相机其他参数
// */
//-(void) setCameraSystemType:(CameraSystemType)systemType withResultBlock:(AUTELResultBlock)block;
//
///**
// *  设置相机的防闪烁参数
// *
// *  Set the camera's anti flicker parameter
// *
// *  @param antiFlickerType Camera's anti flicker parameter.
// *  @param block           The remote execute result callback.
// */
//-(void) setCameraAntiFlicker:(CameraAntiFlickerType)antiFlickerType withResultBlock:(AUTELResultBlock)block;
///**
// * 格式化
// *
// * Format sd card
// *
// * @attention 完成后需重新获取其他参数
// */
//-(void) CameraFormatSDWithResultBlock:(AUTELResultBlock)block;
///**
// * Aeb设置
// *
// * set camera aeb
// *
// * @attention aeb自动包围曝光
// **/
//-(void) setCameraAeb:(CameraAEB)aebType withResultBlock:(AUTELResultBlock)block;
/**
 * 重置相机设置
 *
 * Reset camera settings
 *
 * @attention 重置时需断开于相机连接后重新连接,无返回消息
 */
-(void)StartFactoryResetWithResultBlock:(AUTELResultBlock)block  __deprecated;
///**
// * 设置文件序号模式
// *
// * set camera filenumway
// */
//-(void) setCameraFilenumway:(CameraFilenumway)filenumwayType withResultBlock:(AUTELResultBlock)block;
///**
// * 设置直方图开关
// *
// * Set the histogram switch
// */
//-(void) setCameraHisto:(CameraHistoType)histoType withResultBlock:(AUTELResultBlock)block;
///**
// * 设置颜色
// *
// * set camera color
// */
//-(void) setCameraColor:(CameraColorType)color withResultBlock:(AUTELResultBlock)block;
///**
// * 设置相机风格
// *
// * set camera style
// */
//-(void) setCameraStyle:(CameraStyleStruct)style withResultBlock:(AUTELResultBlock)block;
///**
// *  在连接断开时设置相机的操作方法。
// *
// *  Set the camera how to do while the connection was broken.
// *
// *  @param action How the Camera will action while the connection broken.
// *  @param block  The remote execute result callback.
// */
//-(void) setCameraActionWhenConnectionBroken:(CameraActionWhenBreak)action withResultBlock:(AUTELResultBlock)block;
///**
// * 设置延时间隔 delayed_interval
// *
// * set camera delayed interval
// *
// * @param delayedInterval 延时时长
// * @attention This setting is only available on some A9 models. 只有A9部分机型才有此设置
// */
//-(void) setCameraDelayedInterval:(CameraDelayedInterval)delayedInterval withResultBlock:(AUTELResultBlock)block;
///**
// * 设置延时持续时间
// *
// * set camera delayed duration
// *
// * @attention This setting is only available on some A9 models. 只有A9部分机型才有此设置
// */
//-(void) setCameraDelayedDuration:(CameraDelayedDuration)delayedDuration withResultBlock:(AUTELResultBlock)block;
///**
// * 设置间隔角度
// *
// * set camera panorama step
// *
// * @param panoramaStep (5-60度) such as: 55
// */
//-(void) setCameraPanoramaStep:(NSString *)panoramaStep withResultBlock:(AUTELResultBlock)block;
///**
// * 设置全景角度
// *
// * set camera panorama angle
// *
// * @param panoramaAngle (180-360度) such as: 200
// */
//-(void) setCameraPanoramaAngle:(NSString *)panoramaAngle withResultBlock:(AUTELResultBlock)block;
///**
// * 设置全景模式
// *
// * set camera panorama type
// */
//-(void) setCameraPanoramaType:(CameraPanoramaType )type withResultBlock:(AUTELResultBlock)block;
//
///**
// * 延时拍存储照片  delayed_save_photo
// *
// * set camera delayed save photo
// *
// * @param ON/OFF
// * @attentin 下发拍照命令触发开始和结束,默认不存储，如果存储照片每次拍完会发生photo_token，APP获取状态刷新，否则不会发生photo_token
// */
//-(void) setCameraDelayedSavePhoto:(CameraDelayedSavePhoto)delayedSavePhoto withResultBlock:(AUTELResultBlock)block;
///**
// * 设置相机快门 p_shutter
// *
// * set camera shutter
// *
// * @param shutter such as: 2s, 1
// */
//-(void) setCameraShutter:(NSString *)shutter withResultBlock:(AUTELResultBlock)block;
///**
// * 设置拍照模式 capture_mode
// *
// * set camera capture mode
// *
// * @attention 不同模式下，部分设置项不可以设置（光圈，曝光）
// */
//-(void) setCameraCaptureMode:(CameraCatureMode)captureMode withResultBlock:(AUTELResultBlock)block;
///**
// * 设置ISO感光度
// *
// * set image iSO
// *
// */
////- (void)setImageISO:(NSDictionary *)iso withResultBlock:(AUTELResultBlock)block;
//
//-(void) setCameraISO:(CameraISOType )isoType withResultBlock:(AUTELResultBlock)block;
//
///**
// * 设置点测光
// *
// * set camera photometry area
// *
// * @param area 测光点
// */
//-(void) setCameraPhotometryArea:(NSString *)area ;
///**
// * 设置相机字幕
// *
// * set camera subtitle
// *
// * @param CameraSubTitleSwitchType: on or off
// */
//-(void) setCameraSubTitleSwitch:(CameraSubTitleSwitchType)type withResultBlock:(AUTELResultBlock)block;
///**
// * 设置AE锁
// *
// * set camera AELock
// *
// * @param type ON or OFF
// */
//-(void) setCameraAELock:(CameraAELockType)type withResultBlock:(AUTELResultBlock)block;
///**
// * 设置小手持相机单拍
// *
// * Set a small handheld camera single shot
// *
// * 设置倒计时拍照 s_selftimer_count
// * @param  OFF/5sec/10sec/HDR
// * @attention 默认关闭，在倒计时时可通过下发拍照结束停止倒计时
// *
// */
//-(void) setCameraSingleTime:(CameraSinglePhotoTimerType)type withResultBlock:(AUTELResultBlock)block;
///**
// * 设置小手持慢动作录像分辨率
// *
// * Set small handheld slow motion video resolution
// */
//-(void) setCameraSlowMotionReso:(CameraSlowMotionResoType)type withResultBlock:(AUTELResultBlock)block;
///**
// * 设置小手持慢动作回放帧率 slow_playback_speed
// *
// * Set small handheld slow motion playback frame rate
// *
// * @param speedFps 帧率
// * @attention 只有A9部分机型才有此设置
// */
//-(void) setCameraSlowPlaybackSpeed:(CameraSlowPlaybackSpeed)speedFps withResultBlock:(AUTELResultBlock)block;
///**
// * 获取小手持慢动作录像当前可选分辨率列表
// *
// * Get a list of currently available resolutions for small handheld slow motion recordings
// *
// * @param block 返回的列表字典
// **/
//-(void) getCameraSlowMotionResolutionList:(void(^)(NSDictionary *result, AUTELCameraError *err))block;
//
///**
// * 设置倒计时拍照时间
// *
// * Set the countdown photo time
// *
// **/
//-(void) setCameraSelfTimerCount:(CameraSinglePhotoTimerType)type withResultBlock:(AUTELResultBlock)block;
//
//
//
//
//
//
//
////**********************************************************************************************************
///**
// * 获取录像参数
// *
// * Get video parameters
// */
//- (void)getRecordingFileFormat:(void (^)(CameraRecordFormat format, AUTELCameraError* error))block;
//- (void)getRecordingSettings:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
///**
// * 设置测光点
// *
// * set Location Meter
// */
//- (void)setLocationMeterWithX:(NSInteger)X withY:(NSInteger)Y withResultBlock:(AUTELResultBlock)block;
///**
// * 获取图像风格
// *
// * get camera style
// */
//- (void)getCameraStyle:(void(^)(CameraStyleStruct style, AUTELCameraError *error))block;
////- (void)getCameraStyle:(void(^)(CameraStyleType style, AUTELCameraError *error))block;
////- (void)getImageStyle:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
///**
// * 获取白平衡参数
// *
// * get camera white balance
// */
//- (void)getCameraWhiteBalance:(void(^)(CameraWhiteBalanceType whiteBalance, AUTELCameraError *error))block;
////- (void)getWhiteBalance:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
///**
// * 获取图像颜色参数
// *
// * get camera color
// */
//- (void)getCameraColor:(void (^)(CameraColorType color, AUTELCameraError* error))block;
////- (void)getImageColor:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
///**
// * 获取图像曝光参数
// *
// * get camera exposure compensation
// */
//- (void)getCameraExposureCompensation:(void (^)(CameraExposureCompensationType compensationType, AUTELCameraError* error))block;
////- (void)getImageExposure:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
//
//
///**
// * 获取ISO感光度
// *
// * get camera ISO
// */
////- (void)getImageISO:(void (^)(NSDictionary * iso, AUTELCameraError* error))block;
//-(void) getCameraISO:(void (^)(CameraISOType  iso, AUTELCameraError* error))block;
//
///**
// * 获取设备信息
// *
// * get device information
// */
//- (void)getDeviceInformation:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
//
///**
// * 获取系统状态
// *
// * get system status
// */
//- (void)getSystemStatus:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
//
///**
// * 获取SD卡状态
// *
// * get SD card status
// */
//- (void)getSDCardStatus:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
//
/////**
//// * 恢复出厂设置
//// */
////- (void)StartFactoryResetWithResultBlock:(AUTELResultBlock)block;
//
///**
// * 获取系统时间
// *
// * get system time
// */
//- (void)getSystemDateAndTime:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
///**
// * 设置系统时间
// *
// * set system Date And Time
// */
//- (void)setSystemDateAndTimeWithResultBlock:(AUTELResultBlock)block;
////- (void)setSystemDateAndTime:(NSDictionary *)isoType withResultBlock:(AUTELResultBlock)block;
///**
// * 获取视频编码器配置
// *
// * get camera current resolution
// */
////- (void)getVideoEncoderConfiguration:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
//-(void) getCameraCurrentResolution:(void (^)(CameraRecordingResolutionType resolution, AUTELCameraError *err))block;
///**
// * 获取视频编码器配置选项
// *
// * get video encoder configuration options
// */
//- (void)getVideoEncoderConfigurationOptions:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
//
///**
// * 获取相机制式
// *
// * get camera system type
// * @attention 更改制式需重新获取相机其他参数 Change the system to re-acquire other camera parameters
// */
//-(void) getCameraSystemType:(void (^)(CameraSystemType systemType, AUTELCameraError* error))block;
///**
// *  获取相机的防闪烁参数
// *
// *  get the camera's anti flicker parameter
// *
// *  @param antiFlickerType Camera's anti flicker parameter.
// *  @param block           The remote execute result callback.
// */
//-(void) getCameraAntiFlicker:(void (^)(CameraAntiFlickerType antiFlickerType, AUTELCameraError* error))block;
///**
// * 获取相机快门 p_shutter
// *
// * get camera shutter
// *
// * @param shutter such as: 2s, 1
// */
//-(void) getCameraShutter:(void (^)(NSDictionary *result, AUTELCameraError* error))block;
////- (void)setVideoSourceConfiguration:(NSDictionary *)isoType withResultBlock:(AUTELResultBlock)block;
//
///**
// * 获取视频源配置选项
// *
// * get video source configuration options
// */
//- (void)getVideoSourceConfigurationOptions:(void (^)(NSDictionary * mode, AUTELCameraError* error))block;
//
////---------------------------------未添加-----------------------------------
///**
// * 获取相机字幕开关
// *
// * get camera subtitle switch
// */
//- (void)getCameraSubTitleSwitch:(void (^)(CameraSubTitleSwitchType type, AUTELCameraError *error))block;
///**
// * 获取AE锁
// *
// * get camera AELock
// */
//-(void) getCameraAELock:(void (^)(CameraAELockType type, AUTELCameraError *error))block;
///**
// * 获取延时间隔 delayed_interval
// *
// * get camera delayed interval
// *
// * @param delayedInterval 延时时长
// */
//-(void) getCameraDelayedInterval:(void (^)(CameraDelayedInterval delayedInterval, AUTELCameraError *error))block;
//
//#pragma mark- 获取延时持续时间
///**
// * 获取延时持续时间
// *
// * get camera delayed duration
// *
// * @param delayed duration 延时持续时间
// */
//-(void) getCameraDelayedDuration:(void (^)(CameraDelayedDuration delayedDuration, AUTELCameraError *error))block;
//
//#pragma mark- 获取间隔角度
///**
// * 获取延时持续时间
// *
// * get camera delayed duration
// *
// * @param delayed duration 延时持续时间
// */
//-(void) getCameraPanoramaStep:(void (^)(NSDictionary *delayedDuration, AUTELCameraError *error))block;
//
//#pragma mark- 获取全景角度
///**
// * 获取全景角度
// *
// * get camera panorama angle
// *
// * @param panoramaAngle
// */
//-(void) getCameraPanoramaAngle:(void (^)(NSDictionary *panoramaAngle, AUTELCameraError *error))block;
//
//#pragma mark- 获取延时拍存储照片  delayed_save_photo
///**
// * 获取延时拍存储照片
// *
// * get camera delayed save photo
// *
// * @param panoramaAngle
// */
//-(void) getCameraDelayedSavePhoto:(void (^)(CameraDelayedSavePhoto save, AUTELCameraError *error))block;
//
//#pragma mark- 获取小手持相机单拍
///**
// * 获取小手持相机单拍
// *
// * get camera single time
// *
// * @param type
// */
//-(void) getCameraSingleTime:(void (^)(CameraSinglePhotoTimerType type, AUTELCameraError *error))block;
//
//#pragma mark- 获取小手持慢动作录像分辨率
///**
// * 获取小手持慢动作录像分辨率
// *
// * Get small handheld slow motion video resolution
// *
// * @param type
// */
//-(void) getCameraSlowMotionReso:(void (^)(CameraSlowMotionResoType type, AUTELCameraError *error))block;
//
//#pragma mark- 获取小手持慢动作回放帧率 slow_playback_speed
///**
// * 获取小手持慢动作回放帧率
// *
// * get camera slow playback speed
// *
// * @param speedFps
// */
//-(void) getCameraSlowPlaybackSpeed:(void (^)(CameraSlowPlaybackSpeed speedFps, AUTELCameraError *error))block;
//
//
///**
// * 设置录像自动拍照间隔
// *
// * set camera auto snapshot
// */
//- (void) setCameraAutoSnapshot:(CameraAutoSnapshotTimeType)snapshot withResultBlock:(AUTELResultBlock)block;
//
///**
// * 设置开关录像自动拍照间隔
// *
// * set camera auto snapshot enable
// */
//- (void) setCameraAutoSnapshotEnable:(CameraAutoSnapEnable)enable withResultBlock:(AUTELResultBlock)block;
//
///**
// * 设置循环录影的时间间隔
// *
// * set camera loop record time
// */
//- (void)setCAmeraLoopRecordTime:(CameraLoopRecordTimeType)time withResultBlock:(AUTELResultBlock)block;
//
///**
// * 设置定时拍摄生成视频开关
// *
// * set camera time lapse compose video
// */
//- (void)setcameraTimeLapseComposeVideo:(CameraComposeVideoEnable)enable withResultBlock:(AUTELResultBlock)block __deprecated;
//
///**
// * 设置定时拍持续时间
// *
// * set camera time lapse duration
// */
//- (void)setCameraTimeLapseDuration:(CameraTimeLapseDurationType )duration withResultBlock:(AUTELResultBlock)block __deprecated;
//
///**
// * 设置定时拍视频速率
// *
// * set camera time lapse video framerate
// */
//- (void)setCameraTimeLapseVideoFramerate:(CameraVideoFramerateType )VideoFramerate withResultBlock:(AUTELResultBlock)block __deprecated;
//
///**
// * 设置WiFi配置参数
// *
// * set camera WiFi configuration with SSID
// */
//- (void)SetCameraWiFiConfigurationWithSSID:(NSString *)str andPassword:(NSString *)password withResultBlock:(AUTELResultBlock)block;
//
///**
// * 设置视频录音开关
// *
// * set camera enable audio
// */
//- (void)setCameraEnableAudio:(CameraAudioEnable)enable withResultBlock:(AUTELResultBlock)block;
//
/////**
//// * 设置直方图开关
//// *
//// */
//
////-(void) setCameraHisto:(CameraHistoType)histoType withResultBlock:(AUTELResultBlock)block;
//
///**
// * 获取相机IP地址
// *
// * Get the camera IP address
// */
//-(NSString *)fetchCameraAddress;
//
///**
// * 设置wifi频率
// *
// * set camera WiFi band
// */
//- (void)setCameraWiFiBand:(CameraWiFiBandType)band withResultBlock:(AUTELResultBlock)block;
//
///**
// * 设置拍照录像提示音
// *
// * set camera record tone
// */
//- (void)setCameraRecordTone:(EnableType)recordTone withResultBlock:(AUTELResultBlock)block;
//
///**
// * 设置拍照录像提示音
// *
// * set camera capture tone
// */
//- (void)setCameraCaptureTone:(EnableType)captureTone withResultBlock:(AUTELResultBlock)block;
///**
// * 设置麦克风音量
// *
// * Set the microphone volume
// *
// * @param volume 0-100
// */
//- (void)setCameraMicVolume:(uint8_t)volume withResultBlock:(AUTELResultBlock)block;
//
///**
// * 设置扬声器音量
// *
// * Set the speaker volume
// *
// * @param volume 0-100
// */
//- (void)setCameraSpeakerVolume:(uint8_t)volume withResultBlock:(AUTELResultBlock)block;
//
///**
// * 开始生成全景图片
// *
// * Start generating panoramic images
// *
// * 发送命令通知相机
// */
//- (void)cameraStartSyntheticPanoramagramWithResultBlock:(AUTELResultBlock)block;
//
///**
// * 结束生成全景图片
// *
// * Stop generating panoramic images
// *
// * 发送命令通知相机
// */
//- (void)cameraStopSyntheticPanoramagramWithResultBlock:(AUTELResultBlock)block;
///**
// * 设置相机档位
// *
// * set camera gear
// *
// * @param Auto-自动档 Manual-手动档
// */
//- (void)setCameraGear:(CameraCatureMode)captureMode withResultBlock:(AUTELResultBlock)block;
//
//#pragma mark- 已废弃的移动延时摄影设置
///**
// * 设置延时摄影 延时时间
// *
// * set camera delay shot
// *
// * @param duration 持续时间
// */
//- (void)setCameraDelayShotDelayMin:(CameraTimeLapseDurationType)duration withResultBlock:(AUTELResultBlock)block __deprecated;
///**
// * 设置延时摄影 拍摄间隔
// *
// * set camera delay shot interval
// *
// * @param Interval 间隔时间
// */
//- (void)setCameraDelayShotInterval:(CameraTimeLapse)interval withResultBlock:(AUTELResultBlock)block __deprecated;
///**
// * 设置延时摄影 拍照帧率
// *
// * set camera delay shot framerate
// *
// * @param Framerate 拍照帧率
// */
//- (void)setCameraDelayShotFramerate:(CameraVideoFramerateType)framerate withResultBlock:(AUTELResultBlock)block __deprecated;
///**
// * 设置延时摄影 转动角度
// *
// * set camera delay shot rolling angle
// *
// * @param rollingAngle
// */
//- (void)setCameraDelayShotRollingAngle:(CameraDelayShotRollingAngleType)rollingAngle withResultBlock:(AUTELResultBlock)block __deprecated;
///**
// * 设置延时摄影 转动方向和转动轴
// *
// * set camera delay shot rolling direction
// */
//- (void)setCameraDelayShotRollingDirection:(CameraDelayShotRollingDirectionType)rollingDirection withResultBlock:(AUTELResultBlock)block __deprecated;
//
//#pragma mark- 新的移动延时摄影参数设置
///**
// * 设置移动延时摄影 延时时间
// *
// * set camera motion delay shot
// *
// * @param duration 持续时间
// */
//- (void)setCameraMotionDelayShotDelayMin:(CameraTimeLapseDurationType)duration withResultBlock:(AUTELResultBlock)block;
///**
// * 设置移动延时摄影 拍摄间隔
// *
// * set camera motion delay shot interval
// *
// * @param Interval 间隔时间
// */
//- (void)setCameraMotionDelayShotInterval:(CameraTimeLapse)interval withResultBlock:(AUTELResultBlock)block;
///**
// * 设置移动延时摄影 拍照帧率
// *
// * set camera motion delay shot framerate
// *
// * @param Framerate 拍照帧率
// */
//- (void)setCameraMotionDelayShotFramerate:(CameraVideoFramerateType)framerate withResultBlock:(AUTELResultBlock)block;
///**
// * 设置移动延时摄影 转动角度
// *
// * set camera motion delay shot rolling angle
// *
// * @param rollingAngle
// */
//- (void)setCameraMotionDelayShotRollingAngle:(CameraDelayShotRollingAngleType)rollingAngle withResultBlock:(AUTELResultBlock)block;
///**
// * 设置移动延时摄影 转动方向和转动轴
// *
// * set camera motion delay shot rolling direction
// */
//- (void)setCameraMotionDelayShotRollingDirection:(CameraDelayShotRollingDirectionType)rollingDirection withResultBlock:(AUTELResultBlock)block;
//
//#pragma mark- 延时摄影 （以前的定时拍照？）
///**
// * 是否保留照片
// *
// * set camera delay shot keep photo
// */
//- (void)setCameraDelayShotKeepPhoto:(CameraDelayShotKeepPhotoEnable)enable withResultBlock:(AUTELResultBlock)block;
///**
// * 设置延时摄影持续时间
// *
// * set camera shot duration
// */
//- (void)setCameraShotDuration:(CameraTimeLapseDurationType )duration withResultBlock:(AUTELResultBlock)block;
///**
// * 设置延时摄影视频速率
// *
// * set camera shot video framerate
// */
//- (void)setCameraShotVideoFramerate:(CameraVideoFramerateType )VideoFramerate withResultBlock:(AUTELResultBlock)block;
///**
// * 设置延时摄影 拍摄间隔
// *
// * set camera shot interval
// *
// * @param Interval 间隔时间
// */
//- (void)setCameraShotInterval:(CameraTimeLapse)interval withResultBlock:(AUTELResultBlock)block;
///**
// * 设置3D降噪开关
// *
// * set camera MCTF
// */
//- (void)setCameraMCTF:(EnableType)enable withResultBlock:(AUTELResultBlock)block;
///**
// * 获取小手持PIV状态
// *
// * get picture in video status
// *
// * "result": { "Supported": 1,"Captured": 10,"TimeLeft": 5,},
// */
//- (void)getPictureInVideoStatus:(void (^)(NSDictionary* result, AUTELCameraError* error))block;
//
//#pragma mark- 设置相机休眠模式
///**
// * 设置相机休眠模式
// *
// * set camera sleep mode
// *
// * 范围100-200 步进（0.1*100)
// */
//- (void)setCameraSleepMode:(AUTELCameraSleepModeType)sleepModel withResultBlock:(AUTELResultBlock)block;
//
///**
// * 变焦功能
// *
// * get camera zoom factor
// *
// * 范围100-200 步进（0.1*100)
// */
//- (void)getCameraZoomFactor:(void (^)(NSInteger value, AUTELCameraError *error))block;
//
///**
// * 变焦功能
// *
// * set camera zoom factor
// *
// * 范围100-200 步进（0.1*100)
// */
//- (void)setCameraZoomFactor:(NSInteger)value withResultBlock:(AUTELResultBlock)block;
//
//
//#pragma mark - 仅支持一英寸相机
////_______________________________________________________________________________________________________________
//
///**
// * 获取相机聚焦模式
// *
// * get camera focus mode
// */
//- (void)getCameraFocusMode:(void (^)(CameraFocusMode type, AUTELCameraError *error))block ;
//
//
///**
// * 设置相机聚焦模式
// *
// * set camera focus mode
// */
//- (void)setCameraFocusMode:(CameraFocusMode)type withResultBlock:(AUTELResultBlock)block;
//
///**
// * 获取自动测聚模式、AF 点聚焦坐标
// *
// * get camera focus AF meter mode
// */
//- (void)getCameraFocusAFMeterMode:(void (^)(CameraAFMeterMode type, uint8_t x, uint8_t y, AUTELCameraError *error))block;
//
///**
// * 设置自动测聚模式、AF 点聚焦坐标
// *
// * set camera focus AF meter mode
// */
//- (void)setCameraFocusAFMeterMode:(CameraAFMeterMode)type x:(uint8_t)x y:(uint8_t)y withResultBlock:(AUTELResultBlock)block;
//
///**
// * 获取物距
// *
// * get camera focus object distance
// */
//- (void)getCameraFocusObjectDistance:(void (^)(NSInteger objectDistance, AUTELCameraError *error))block;
//
///**
// * 设置物距
// *
// * set camera focus object distance
// */
//- (void)setCameraFocusObjectDistance:(NSInteger)objectDistance withResultBlock:(AUTELResultBlock)block;
//
///**
// * 获取辅助对焦使能
// *
// * get camera focus assist focus enable
// */
//- (void)getCameraFocusAssistFocusEnable:(void (^)(BOOL enable, AUTELCameraError *error))block;
//
///**
// * 设置辅助对焦使能
// *
// * set camera focus assist focus enable
// */
//- (void)setCameraFocusAssistFocusEnable:(BOOL)enable withResultBlock:(AUTELResultBlock)block;
//
///**
// * 获取光圈大小
// *
// * get camera IRIS
// */
//- (void)getCameraIRIS:(void (^)(CameraIRIS type, AUTELCameraError *error))block;
//
///**
// * 设置光圈大小
// *
// * set camera IRIS
// */
//- (void)setCameraIRIS:(CameraIRIS)type withResultBlock:(AUTELResultBlock)block;
//
///**
// * 开始拍照（拍照前聚焦）
// *
// * method StartTakePhotos
// */
//-(void) startTakePhotoFocusFirstwithResult:(AUTELResultBlock)block;

@end
