//
//  AUTELBaseCameraÏ.h
//  AUTELSDK
//
//  Created by 虢蔚翔 on 16/8/8.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import "AUTELBaseCamera.h"
#import <AUTELSDK/AUTELCameraExposureParameters.h>
#import <AUTELSDK/AUTELCameraDef.h>
#import <AUTELSDK/AUTELMedia.h>
#import <AUTELSDK/AUTELCameraParameters.h>
#import <AUTELSDK/AUTELCameraSDCardState.h>
#import <AUTELSDK/AUTELDrone.h>
#import <AUTELSDK/AUTELCameraSystemBaseState.h>
#import <AUTELSDK/AUTELPlaybackManager.h>
#import "AUTELCameraSystemBaseState.h"
#import <AUTELSDK/AUTELIrTemperatureModel.h>
#import <AUTELSDK/AUTELMisstionRecordModel.h>
#import <AUTELSDK/AUTELCameraSettingModel.h>


#pragma mark - Range Key of the change dictionary.
/**
 *  @breif CameraVideoResolutionAndFrameRateRange key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前视频标准下支持的视频分辨率和帧率设置范围。
 */
extern NSString *const AUTELSupportedCameraVideoResolutionAndFrameRateRange;

/**
 *  @brief CameraTimeLapseIntervalRange key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前图片格式下支持的定时拍摄时间设置范围。
 */
extern NSString *const AUTELSupportedCameraTimeLapseIntervalRange;

/**
 *  @brief CameraModeRange key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取当前相机支持的工作模式设置范围。
 */
extern NSString *const AUTELSupportedCameraModeRange;

/**
 *  @brief CameraExposureModeRange key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取当前相机支持的曝光模式设置范围。
 */
extern NSString *const AUTELSupportedCameraExposureModeRange;

/**
 *  @brief CameraISORange key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前曝光模式下支持的ISO设置范围。
 */
extern NSString *const AUTELSupportedCameraISORange;

/**
 *  @brief CameraISOModeRange key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取当前相机支持的曝光模式设置范围。
 */
extern NSString *const AUTELSupportedCameraISOModeRange;

//extern NSString *const AUTELSupportedCameraResolution;
/**
 *  @brief CameraPhotoRatio key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前分辨率。
 */
extern NSString *const AUTELSupportedCameraPhotoRatio;

/**
 *  @brief CameraPhotoFileFormat key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前图片格式。
 */
extern NSString *const AUTELSupportedCameraPhotoFileFormat;

/**
 *  @brief CameraExposureMode key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机曝光模式。
 */
//extern NSString *const AUTELSupportedCameraExposureMode;

/**
 *  @brief CameraWhiteBalance key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前白平衡。
 */
extern NSString *const AUTELSupportedCameraWhiteBalance;

/**
 *  @brief CameraPhotoColor key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前色彩。
 */
extern NSString *const AUTELSupportedCameraPhotoColor;

/**
 *  @brief CameraImageStyle key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前风格。
 */
extern NSString *const AUTELSupportedCameraImageStyle;

/**
 *  @brief CameraEnableSubtitle key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机是否打开视频字幕。
 */
extern NSString *const AUTELSupportedCameraEnableSubtitle;

/**
 *  @brief CameraVideoFileFormat key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前视频格式。
 */
extern NSString *const AUTELSupportedCameraVideoFileFormat;

/**
 *  @brief CameraVideoStandard key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前视频制式。
 */
extern NSString *const AUTELSupportedCameraVideoStandard;

/**
 *  @brief CameraVideoPIV key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前PIV模式。
 */
extern NSString *const AUTELSupportedCameraVideoPIV;

/**
 *  @brief CameraVideoEncoderConfiguration key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机拍摄分辨率和帧率。
 */
extern NSString *const AUTELSupportedCameraVideoEncoderConfiguration;

/**
 *  @brief CameraCaptionEnable key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前PIV模式。
 */
extern NSString *const AUTELSupportedCameraCaptionEnable;

/**
 *  @brief CameraCaptionEnable key.
 *
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前PIV模式。
 */
extern NSString *const AUTELSupportedCameraVideoFileCompressionStandard;


/**
 *  @brief CameraShutterSpeedRange key.
 *  
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前曝光模式下支持的快门速度设置范围。
 */
extern NSString *const AUTELSupportedCameraShutterSpeedRange;

/**
 *  @brief CameraExposureCompensationRange key.
 *  
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前曝光模式下支持的曝光补偿设置范围。
 */
extern NSString *const AUTELSupportedCameraExposureCompensationRange;

/**
 *  @brief CameraApertureRange key.
 * 
 *  关联方法 -camera:didUpdateParameters:change: 中的参数改变字典，根据该键可获取相机当前曝光模式下支持的光圈值设置范围。
 */
extern NSString *const AUTELSupportedCameraApertureRange;

/**
 *  @brief AUTELCameraDeviceInforFirmwareVersion Key
 *
 *  @see - (void)getCameraDeviceInfoWithCompletion: 方法返回的 info 中有包含有固件版本信息，通过该 Key 可以读取
 *
 */
extern NSString *const AUTELCameraDeviceInforFirmwareVersionKey;

/**
 *  @brief AUTELCameraDeviceInforSerialNumber Key
 *  @see - (void)getCameraDeviceInfoWithCompletion: 方法返回的 info 中有包含有序列号信息，通过该 Key 可以读取
 */
extern NSString *const AUTELCameraDeviceInforSerialNumberKey;

/**
 *  @brief AUTELCameraDeviceInforName Key
 *  @see - (void)getCameraDeviceInfoWithCompletion: 方法返回的 info 中有包含有相机名称信息，通过该 Key 可以读取
 */
extern NSString *const AUTELCameraDeviceInforNameKey;

/**
 *  @brief AUTELCameraDeviceInforHardwareId Key
 *  @see - (void)getCameraDeviceInfoWithCompletion: 方法返回的 info 中有包含有相机名称信息，通过该 Key 可以读取
 */
extern NSString *const AUTELCameraDeviceInforHardwareIdKey;

/**
 *  @brief AUTELCameraDeviceInforLensModelKey Key
 *  @see - (void)getCameraDeviceInfoWithCompletion: 方法返回的 info 中有包含有相机镜头型号，通过该 Key 可以读取
 */
extern NSString *const AUTELCameraDeviceInforLensModelKey;

/**
 *  @brief AUTELCameraDeviceInforLensSoftVersionKey Key
 *  @see - (void)getCameraDeviceInfoWithCompletion: 方法返回的 info 中有包含有相机镜头软件版本号，通过该 Key 可以读取
 */
extern NSString *const AUTELCameraDeviceInforLensSoftVersionKey;


@class AUTELBaseCamera;
/**
 *
 *  This protocol offers various proxy methods to update camera state in real time.
 *
 *  该协议提供实时更新相机当前状态的各类代理方法。
 *
 */
@protocol AUTELBaseCameraDelegate <NSObject>

@optional

/**
 *  @brief This callback method provides real-time feedback on the current connect state of the camera. 
 *
 *  该回调方法会实时返回当前相机的连接状态。
 *
 *  @param camera       Current camera.
 *
 *                      当前相机对象。
 *
 *  @param connectState Current connect state of the camera.
 *
 *                      相机当前连接状态。
 *
 *  @see AUTELCameraConnectState
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateConnectState:(AUTELCameraConnectState)connectState NS_SWIFT_NAME(camera(_:didUpdateConnectState:));

/**
 *  @brief This callback method returns the current connect state of the camera. When the connect state is AutelCameraConnectStateConnected, this method will be called every 0.2 second.
 *  
 *  该回调方法会返回当前相机的连接状态，在相机连接状态为 AUTELCameraConnectStateConnected 时，该方法会0.2秒调用一次。
 *
 *  @param camera       Current connected camera.
 *
 *                      当前相机对象。
 *
 *  @param systemState  Current system state of the camera
 *
 *                      相机当前系统状态。
 *
 *  @see AUTELCameraSystemBaseState
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateSystemState:(AUTELCameraSystemBaseState *)systemState NS_SWIFT_NAME(camera(_:didUpdateSystemState:));


/**
 *  @brief This callback method will be called in real time when the camera produces new media files (images or videos).
 *
 *  相机生成新的多媒体文件（图片或录像）时会实时回调该代理方法。
 *
 *  @param camera       Current connected camera.
 *
 *                      当前相机对象。
 *
 *  @param newMedia     new media.
 *
 *                      新生成的多媒体对象。
 *
 *  @warning In this callback method, AUTELMedia can download and obtain thumbnail images, previews, original images or videos through AUTELPlaybackManager only when the state of AUTELPlaybackManager is AUTELPlaybackExecuteTaskIdle .
 *
 *  在该回调方法中的 AUTELMedia 对象，可以通过 AUTELPlaybackManager 对象进行下载得到缩略图、预览图、原图或者录像，但是必须 AUTELPlaybackManager 对象的工作状态(AUTELPlaybackWorkState) 为空闲状态(AUTELPlaybackExecuteTaskIdle)。
 *
 *  @see AUTELMedia
 *  @see AUTELPlaybackManager
 *  @see AUTELPlaybackWorkState
 *
 */
- (void)camera:(AUTELBaseCamera *)camera didGenerateNewMediaFile:(AUTELMedia *)newMedia NS_SWIFT_NAME(camera(_:didGenerateNewMediaFile:));

/**
 *  @brief This callback method will return the current SD card status in real time. When the camera connection state is AUTELCameraConnectStateConnected, the method will be called every 0.2 second.
 *
 *  该回调方法会实时返回当前SD卡状态，在相机连接状态为 AUTELCameraConnectStateConnected 时，该方法会0.2秒调用一次。
 *
 *  @param camera       Current connected camera.
 *
 *                      当前相机对象。
 *
 *  @param sdCardState  Current SD card state.
 *
 *                      SD卡当前状态。
 *
 *  @see AUTELCameraSDCardState
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateSDCardState:(AUTELCameraSDCardState *)sdCardState NS_SWIFT_NAME(camera(_:didUpdateSDCardState:));


/**
 *  @brief This callback method will return the current flashCard status in real time. When the camera connection status is AUTELCameraConnectStateConnected, the method will be called every 0.2 second.
 *
 *  该回调方法会实时返回当前mmc 机载闪存状态，在相机连接状态为 AUTELCameraConnectStateConnected 时，该方法会0.2秒调用一次。
 *
 *  @param camera       Current connected camera.
 *
 *                      当前相机对象。
 *
 *  @param mmcState  Current flashCard status.
 *
 *                      flash Card 机载闪存当前状态。
 *
 *  @see AUTELCameraSDCardState
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateMMCState:(AUTELCameraSDCardState *)mmcState NS_SWIFT_NAME(camera(_:didUpdateMMCState:));



/**
 *  @brief This callback method updates the current exposure state in the present exposure value. When the camera connection state is AUTELCameraConnectStateConnected, the method will be called every 0.2 second.
 *
 *  该回调方法会实时返回相机当前曝光模式下各曝光参数的状态，在相机连接状态为 AUTELCameraConnectStateConnected 时，该方法会0.2秒调用一次。
 *
 *  @discussion Xteady R20 camera supports three exposure modes: Auto Exposure, Manual Exposure and Aperture-priority.
 *              1. In Auto Exposure: EV can be set manually, aperture value will vary by EV, ISO and shutter speed cannot be adjusted. 
 *              2. In Manual Mode: ISO, shutter speed and aperture value can be set while EV is not adjustable. 
 *              3. In Aperture-priority Mode: ISO and shutter speed will be set automatically, while EV and aperture value can be set manually.
 *              
 *              Xteady R20 相机支持自动曝光、手动曝光、光圈优先三种曝光模式。
 *              1、在自动曝光模式下，曝光补偿可手动设置参数，光圈值会随曝光补偿实时变化，ISO值和快门速度不可调。
 *              2、在手动曝光模式下，ISO值、快门速度和光圈值都可手动设置参数，曝光补偿不可调。
 *              3、在光圈优先模式下，ISO值、快门速度会自动设置参数，曝光补偿和光圈值可手动设置参数。
 *
 *  @param camera   Current connected camera.
 *
 *                  当前相机对象。
 *
 *  @param exposureParameters   Exposure parameters.
 *
 *                              曝光参数。
 *
 *  @see AUTELCameraExposureParameters
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateCurrentExposureValues:(AUTELCameraExposureParameters *)exposureParameters NS_SWIFT_NAME(camera(_:didUpdateCurrentExposureValues:));


/**
 *  @brief The adjustment range of all parameters will vary by camera some other states. This will trigger the callback method in real time.
 *
 *  当相机某些状态改变时会牵动其他参数可设置范围，会实时触发该回调方法。
 *
 *  @discussion All the parameter setting ranges will vary when the camera connecting state changes.As there are numerous parameters, change parameters are now null. Get the corresponding parameter setting ranges through `parameters`.
 *
 *  当相机连接状态变化时，所有参数可设置范围都会改变，由于参数过多因此change参数此时为空，可通过parameters参数获取对应参数的设置范围。
 *
 *  @param camera       Current connected camera.
 *
 *                      当前相机对象。
 *
 *  @param parameters   Parameters setting range
 *
 *                      参数设置范围对象。
 *
 *  @param change       All the parameters with changes in setting range. 
 *
 *                      设置范围改变的参数集合。
 *
 *  @see AUTELCameraParameters
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateParameters:(AUTELCameraParameters *)parameters change:(NSDictionary <id, NSArray *>*)change NS_SWIFT_NAME(camera(_:didUpdateParameters:change:));

/**
 *  @brief When the camera is in TimeLapse shooting mode, the changes in the number of image captured and countdown will call back the method in real time.
 *
 *  当相机处于定时拍摄模式时，已经拍摄的照片张数和定时倒数时间改变时会实时回调该方法。
 *
 *  @param camera       Current connected camera.
 *
 *                      当前相机对象。
 *
 *  @param captureCount The number of image captured in the current TimeLapse shooting mode.
 *
 *                      当前定时拍摄已拍摄照片张数。
 *
 *  @param timeInterval Time interval with next shooting (seconds) 
 *
 *                      距离下次拍摄的时间，单位为秒。
 *
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateTimeLapseCaptured:(NSInteger)captureCount andCountDown:(NSTimeInterval)timeInterval NS_SWIFT_NAME(camera(_:didUpdateTimeLapseCaptured:andCountDown:));

/**
 *  @brief This callback method will update the current histogram total pixels in real time.
 *  
 *  该回调方法会实时返回当前直方图参数。
 *
 *  @param camera       Current connected camera.
 *
 *                      当前相机对象。
 *
 *  @param totalPixels  Total pixels. 
 *
 *                      总像素数。
 *
 *  @param pixelsArray  Pixel array at different luminance level. 
 *
 *                      不同亮度级别的像素数，总共64级。
 *  
 *  @warning  To trigger the current method, Histogram functions needs to be enabled in setHistogramEnabled:withCompletion (Enabled needs to be set as YES)
 *  
 *  当前方法会触发的前提是，在方法-setHistogramEnabled:withCompletion:中设置支持直方图功能（enabled参数设置为YES）。
 *
 *  @see -setHistogramEnabled:withCompletion:。
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateHistogramTotalPixels:(NSInteger)totalPixels andPixelsPerLevel:(NSArray *)pixelsArray NS_SWIFT_NAME(camera(_:didUpdateHistogramTotalPixels:andPixelsPerLevel:));

/**
 *  @brief This callback method updates Auto Focus state in real time.
 *
 *  该回调方法会实时返回自动对焦状态。
 *
 *  @param camera       Current connected camera.
 *
 *                      当前相机对象。
 *
 *  @param focusState   Auto Focus state: Auto Focus finishes when the state is AUTELCameraAFLensFocusStateClear.
 *
 *                      自动对焦状态，当对焦状态为 AUTELCameraAFLensFocusStateClear 时，表示自动对焦完成。
 *
 *  @param rowIndex     When the focus state is AUTELCameraAFLensFocusStateClear, the row index of the focus point is AUTELCameraAFLensFocusStateFuzzy and the value is 0.
 *
 *                      聚焦状态为 AUTELCameraAFLensFocusStateClear 时，聚焦清楚位置的横坐标，为AUTELCameraAFLensFocusStateFuzzy时，该值为0。
 *
 *  @param colIndex     When the focus state is AUTELCameraAFLensFocusStateClear, the column index of the focus point is AUTELCameraAFLensFocusStateFuzzy and the value is 0.
 *
 *                      聚焦状态为 AUTELCameraAFLensFocusStateClear 时，聚焦清楚位置的纵坐标，为AUTELCameraAFLensFocusStateFuzzy时，该值为0。
 *
 *  @warning the current method will be triggered when the focus mode is AUTELCameraLensFocusModeAuto (Auto Focus mode). 
 *
 *  当前方法会触发的前提是，对焦模式为 AUTELCameraLensFocusModeAuto 自动对焦模式。
 *
 *  @see AUTELCameraAFLensFocusState
 *  @see AUTELCameraLensFocusMode
 *
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateAutoFocusState:(AUTELCameraAFLensFocusState)focusState andLensFocusAreaRowIndex:(NSInteger)rowIndex andColIndex:(NSInteger)colIndex NS_SWIFT_NAME(camera(_:didUpdateAutoFocusState:andLensFocusAreaRowIndex:andColIndex:));

/**
 *  @brief This callback method updates the record recover state in real time. When an abort occurs, the camera will recover the video automatically.
 *
 *  该回调方法会实时返回录像恢复状态，当上次录像异常退出时，相机会自动进行录像恢复。
 *
 *  @param camera Current connected camera.
 *
 *                当前相机对象。
 *
 *  @param state  The record recovery states, namely Start and End. 
 *  
 *                录像恢复状态，分为开始和结束。
 *
 *  @see AUTELCameraRecordRecoverState
 *
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateRecordRecoverState:(AUTELCameraRecordRecoverState)state NS_SWIFT_NAME(camera(_:didUpdateRecordRecoverState:));


/**
*  @brief This callback method updates the ae af  back to center in real time.
*
*  该回调方法会实时返回AE/AF状态回中心点的事件。
*
*  @param camera Current connected camera.
*
*                当前相机对象。
*
*  @param state  AE Status，not used.
*
*                AE/AF状态。
*
*/
- (void)camera:(AUTELBaseCamera *)camera didUpdateAeAfState:(AUTELCameraAFWorkStatus)state NS_SWIFT_NAME(camera(_:didUpdateAeAfState:));

/**
 *  @brief The callback method will report the temperature alarm event in real time。
 *
 *  该回调方法会实时上报温度报警事件。
 *
 *  @param camera Current connected camera.
 *
 *  当前相机对象。
 *
 *  @param even   Temperature alarm event model.
 *
 *  温度报警事件模型
 *
 *  @see AUTELIrTempAlarmEven
 *
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateTempAlarmEven:(AUTELIrTempAlarmEven *)even NS_SWIFT_NAME(camera(_:didUpdateTempAlarmEven:));

/**
 *  @brief The callback method will report the camera warnning event in real time。
 *
 *  该回调方法会实时上报相机报警事件。
 *
 *  @param camera Current connected camera.
 *
 *  当前相机对象。
 *
 *  @param warnningType   camera warnning type.
 *
 *  相机报警类型
 *
 *  @see AUTELCameraWarnningType
 *
 */
- (void)camera:(AUTELBaseCamera *)camera didUpdateWarnningEven:(AUTELCameraWarnningType)warnningType NS_SWIFT_NAME(camera(_:didUpdateWarnningEven:));

/**
 *  @brief The callback method will report the misstion recording event in real time。
 *
 *  该回调方法会实时上报任务录制事件。
 *
 *  @param camera Current connected camera.
 *
 *  当前相机对象。
 *
 *  @param model   camera misstion recording model.
 *
 *  相机报警类型
 *
 *  @see AUTELMisstionRecordModel
 *
 */
- (void)camera:(AUTELBaseCamera *)camera didReceivedMissionRecordEven:(AUTELMisstionRecordModel *)model NS_SWIFT_NAME(camera(_:didReceivedMissionRecordEven:));

/// The callback method will report the encryption status of the camera in real time
/// 该回调方法会实时上报相机的加密状态
///
/// @param camera AUTELBaseCamera
/// 相机
///
/// @param In dic, Status indicates the encryption status: 0, reserved; 1, decrypted; 2, encrypted
/// In dic, Total represents the total number of files that need to be decrypted
/// In dic, Current indicates the number of files currently decrypted
///
/// dic中，Status表示加密状态：0，预留；1，解密；2，加密
/// dic中，Total表示需要解密文件的总数
/// dic中，Current表示当前已经解密的文件个数
- (void)camera:(AUTELBaseCamera *)camera didUpdateCipherStatus:(NSDictionary *)dic
    NS_SWIFT_NAME(camera(_:didUpdateCipherStatus:));


@end

/**
 *
 *  Obtain current state of the camera, read and write camera parameters, send operation orders to camera through AUTELBaseCamera Class.
 *
 *  通过 AUTELBaseCamera 类，可以获取到相机的当前状态，可以对相机参数进行读写操作，也可以对相机进行相关操作。
 *
 */
@interface AUTELBaseCamera :NSObject <AUTELBaseCameraDelegate>

/**
 *  @brief  Delegate instance. Obtain camera state and camera operation state through delegate callback.  
 *
 *  代理实例，通过代理回调方法，可以获取相机状态以及相机操作事件的状态
 *
 *  @see AUTELBaseCameraDelegate
 */
@property (nonatomic, weak) id<AUTELBaseCameraDelegate> delegate;

/**
 *  @brief  Return AUTELDrone instance with current instance. `drone.camera` and `self` is the same instance.
 *
 *  返回拥有当前实例的 AUTELDrone 实例，drone.camera 与 self 是同一个实例。
 *
 *  @see AUTELDrone
 */
@property (nonatomic, readonly, weak)AUTELDrone *drone;

/**
 *  @brief Returns camera connecting state. Most camera operations, parameter reading and writing are based on the connecting state of AUTELCameraConnectStateConnected 
 *
 *  返回相机的连接状态，相机的绝大部分操作和参数的读取都建立在连接状态为 AUTELCameraConnectStateConnected 的基础上。
 *
 *  @see AUTELCameraConnectState
 */
@property (nonatomic, readonly)AUTELCameraConnectState connectState;

/**
 *  @brief Return AUTELCameraParameters instance.
 *
 *  返回相机参数范围对象。
 *
 *  @see AUTELCameraParameters
 */
@property (nonatomic, readonly, strong)AUTELCameraParameters *parameters;

/**
 *  @brief Return camera type.
 *
 *  返回相机类型。
 */
@property (nonatomic, readonly)AUTELBaseCameraType cameraType;

/**
 *  @brief Return isEarlyThanModelC.
 *
 *  返回是否属于ModelC之前的相机。
 */
@property (nonatomic, readonly)BOOL isEarlyThanModelC;

/**
 *  @brief Return SD Card playback manager.
 *
 *  SD卡相册管理对象
 */
@property (nonatomic, readonly,strong) AUTELPlaybackManager *playbackManager;

/**
 *  @brief Return flash Card playback manager.
 *
 *  机载闪存相册管理对象
 */
@property (nonatomic, readonly,strong) AUTELPlaybackManager *mmcPlaybackManager;


#pragma mark - Get Camera all settings
/*-------------------------------------------------------------------------*/

- (void)getCameraAllSettingsWithCompletion:(void (^_Nullable)(NSDictionary * _Nullable dict, NSError * _Nullable error))block;

/*********************************************************************************/
#pragma mark - Camera work mode
/*********************************************************************************/

/**
 *  @brief Set camera work mode.
 *
 *  设置相机工作模式。
 *
 *  @discussion Obtain supported working modes when member variable parameters call `–supportedCameraModeRange` method.
 *
 *  支持的工作模式可通过成员变量 parameters 调用 -supportedCameraModeRange 方法获取。
 *
 *  @param mode     Camera work mode.
 *
 *                  相机工作模式。
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCameraWorkMode
 *  @see AUTELCompletionBlock
 *  @see AUTELCameraParameters
 */
- (void)setCameraWorkMode:(AUTELCameraWorkMode)mode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get camera work mode.
 *
 *  获取相机工作模式。
 *
 *  @param block    Completion block which including two parameters, error and mode. Mode is the current camera working mode. 
 *
 *                  完成 block，该 block 包含两个参数，mode 为当前相机工作状态，error 为错误信息。
 *
 *  @discussion When succeed to obtain, error is nil. When fails to obtain, error will return error information, and mode is AUTELCameraWorkModeUnknown.
 *
 *  当获取成功时，error 为nil；当获取成功时，error 会返回错误信息，mode 为 AUTELCameraWorkModeUnknown。
 *
 *  @see AUTELCameraWorkMode
 */
- (void)getCameraWorkModeWithCompletion:(void (^_Nullable)(AUTELCameraWorkMode mode, NSError * _Nullable error))block;


/*********************************************************************************/
#pragma mark - Camera Shoot photos
/*********************************************************************************/

/**
 *  @brief Start shooting photos
 *
 *  开始拍照
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @discussion To start photo shooting, the current camera work mode must support photo shooting and the camera is in idle state. 
 *              Self’s delegate can obtain current photo shooting state by calling -camera:didUpdateSystemState:.
 *              Self’s delegate can obtain media files after photo shooting by calling -camera:didGenerateNewMediaFile:.
 *
 *              开始拍照必须要求当前相机的工作模式支持拍照，并且当前相机处于空闲状态。
 *              self 的 delegate 代理对象可以通过实现 -camera:didUpdateSystemState: 方法获取当前的拍照状态。
 *              self 的 delegate 代理对象可以通过实现 -camera:didGenerateNewMediaFile: 方法获取到拍照完成时的多媒体对象。
 *
 *  @see -delegate
 *  @see -camera:didUpdateSystemState:
 *  @see -camera:didGenerateNewMediaFile:
 *  @see AUTELBaseCameraDelegate
 */
- (void)startShootPhotoWithCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief Stop shooting photos
 *
 *  停止拍照
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @discussion To stop photo shooting, the -isShootingBurstPhoto or –isShootingTimeLapsePhoto of the current camera state must be YES, and the working mode is not AUTELCameraWorkModeCaptureSingle. 
 *              Self’s delegate can obtain the current photo shooting state by calling -camera:didUpdateSystemState:.
 *              Self’s delegate can obtain media files after photo shooting by calling -camera:didGenerateNewMediaFile:.
 *
 *              停止拍照必须要求当前相机系统状态的 -isShootingBurstPhoto 或者 -isShootingIntervalPhoto 为YES，且工作模式不为 AUTELCameraWorkModeCaptureSingle
 *              self 的 delegate 代理对象可以通过实现 -camera:didUpdateSystemState: 方法获取当前的拍照状态。
 *              self 的 delegate 代理对象可以通过实现 -camera:didGenerateNewMediaFile: 方法获取到拍照完成时的多媒体对象。
 *
 *  @see -delegate
 *  @see -isShootingBurstPhoto
 *  @see -isShootingIntervalPhoto
 *  @see -camera:didUpdateSystemState
 *  @see -camera:didGenerateNewMediaFile
 *  @see AUTELBaseCameraDelegate
 */
- (void)stopShootPhotoWithCompletion:(AUTELCompletionBlock)block;


/*********************************************************************************/
#pragma mark - Camera Record Video
/*********************************************************************************/

/**
 *  @brief Start video recording
 *
 *  开始录像
 *
 *  @param block    Completion block
 *
 *                  完成 block
 *
 *  @discussion To start video recording, the current working mode of the camera must support video shooting and the camera shall be in idle state. 
 *              Self’s delegate can get the current video shooting state by calling -camera:didUpdateSystemState:.
 *              Self’s delegate can get media files after video shooting by calling -camera:didGenerateNewMediaFile:.
 *
 *              开始录像必须要求当前相机的工作模式支持录像，并且当前相机处于空闲状态。
 *              self 的 delegate 代理对象可以通过实现 -camera:didUpdateSystemState: 方法获取当前的录像状态。
 *              self 的 delegate 代理对象可以通过实现 -camera:didGenerateNewMediaFile: 方法获取到录像完成时的多媒体对象。
 *
 *  @see -delegate
 *  @see -camera:didUpdateSystemState:
 *  @see -camera:didGenerateNewMediaFile:
 *  @see AUTELCameraSystemBaseState
 *  @see AUTELBaseCameraDelegate
 */
- (void)startRecordVideoWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Stop video recording
 *
 *  停止录像
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @discussion To stop video recording, the –isRecording of current camera system state must be “YES”.
 *              Self’s delegate can get the current video shooting state by calling -camera:didUpdateSystemState:.
 *              Self’s delegate can get media files after video shooting by calling -camera:didGenerateNewMediaFile:.
 *
 *              停止录像必须要求当前相机系统状态的 -isRecording 为 YES。
 *              self 的 delegate 代理对象可以通过实现 -camera:didUpdateSystemState: 方法获取当前的录像状态。
 *              self 的 delegate 代理对象可以通过实现 -camera:didGenerateNewMediaFile: 方法获取到录像完成时的多媒体对象。
 *
 *  @see -delegate
 *  @see -camera:didUpdateSystemState:
 *  @see -camera:didGenerateNewMediaFile:
 *  @see AUTELCameraSystemBaseState
 *  @see AUTELBaseCameraDelegate
 */
- (void)stopRecordVideoWithCompletion:(AUTELCompletionBlock)block;


#pragma mark 以下接口仅内部使用，不对外发布

///// 内部接口
///// @param block 内部接口
//- (void)getEncryptionPubKeyWithCompletion:(void(^_Nullable)(NSString * _Nullable pubKey, NSError * _Nullable error))block;
///// 内部接口
///// @param block 内部接口
//- (void)startEncryptionText:(NSString *_Nullable)text withCompletion:(void(^_Nullable)(NSDictionary * _Nullable dic, NSError * _Nullable error))block;
///// 内部接口
///// @param block 内部接口
//- (void)startDecryptionText:(NSString *_Nullable)text withCompletion:(void(^_Nullable)(NSDictionary * _Nullable dic, NSError * _Nullable error))block;

@end

/*******************************************************************************/
#pragma mark - AUTELBaseCamera (CameraSetting)
/*******************************************************************************/

/**
 *
 *  Camera Settings Class for AUTELBaseCamera, which mainly sets and reads camera parameters.
 *
 *  AUTELBaseCamera 的 CameraSetting 类别，该类别主要实现相机参数的设置和读取。
 */
@interface AUTELBaseCamera(CameraSetting)

/*-------------------------------------------------------------------------*/
#pragma mark - Load camera factory settings
/*-------------------------------------------------------------------------*/

/**
 *  @brief Restore factory settings.
 *
 *  恢复出厂设置
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 */
- (void)loadFactorySettings:(AUTELCompletionBlock)block;


/*-------------------------------------------------------------------------*/
#pragma mark - Camera video setting
/*-------------------------------------------------------------------------*/

/**
 *  @brief Set video resolution and frame rate. 
 *
 *  设置相机录像的视频分辨率和帧率
 *
 *  @discussion the supported video resolution and frame rate depend on the current video format, namely PAL and NSTC. The supported video resolution and frame rate are:
 *
 *  相机支持的视频分辨率和帧率取决于相机当前的视频制式，视频标准分为 PAL 和 NSTC，分别支持的视频分辨率和帧率如下:
 *  XteadyR20 Camera:
 *  PAL:4096x2160_24fps
 *      4096x2160_25fps
 *      3840x2160_24fps
 *      3840x2160_25fps
 *      2704x1520_24fps
 *      2704x1520_25fps
 *      2704x1520_48fps
 *      2704x1520_50fps
 *      1920x1080_24fps
 *      1920x1080_25fps
 *      1920x1080_48fps
 *      1920x1080_50fps
 *      1280x720_24fps
 *      1280x720_25fps
 *      1280x720_48fps
 *      1280x720_50fps
 *  NTSC:4096x2160_24fps
 *      3840x2160_24fps
 *      3840x2160_30fps
 *      2704x1520_24fps
 *      2704x1520_30fps
 *      2704x1520_48fps
 *      2704x1520_60fps
 *      1920x1080_24fps
 *      1920x1080_30fps
 *      1920x1080_48fps
 *      1920x1080_60fps
 *      1920x1080_120fps
 *      1280x720_24fps
 *      1280x720_30fps
 *      1280x720_48fps
 *      1280x720_60fps
 *      1280x720_120fps
 *
 *  XteadyR12 Camera:
 *  PAL:4096x2160_24fps
 *      4096x2160_25fps
 *      3840x2160_24fps
 *      3840x2160_25fps
 *      2704x1520_24fps
 *      2704x1520_25fps
 *      2704x1520_48fps
 *      2704x1520_50fps
 *      1920x1080_24fps
 *      1920x1080_25fps
 *      1920x1080_48fps
 *      1920x1080_50fps
 *      1280x720_24fps
 *      1280x720_25fps
 *      1280x720_48fps
 *      1280x720_50fps
 *  NTSC:4096x2160_24fps
 *      3840x2160_24fps
 *      3840x2160_30fps
 *      2704x1520_24fps
 *      2704x1520_30fps
 *      2704x1520_60fps
 *      1920x1080_24fps
 *      1920x1080_30fps
 *      1920x1080_48fps
 *      1920x1080_60fps
 *      1920x1080_120fps
 *      1280x720_24fps
 *      1280x720_30fps
 *      1280x720_48fps
 *      1280x720_60fps
 *      1280x720_240fps
 *
 *  XT701 Camera:Video standards no longer distinguish between PAL and NSTC.
 *      7680x4320_24fps
 *      7680x4320_25fps
 *      5760x3240_24fps
 *      5760x3240_25fps
 *      5760x3240_30fps
 *      3840x2160_24fps
 *      3840x2160_25fps
 *      3840x2160_30fps
 *      3840x2160_48fps
 *      3840x2160_50fps
 *      3840x2160_60fps
 *      2720x1528_24fps
 *      2720x1528_25fps
 *      2720x1528_30fps
 *      2720x1528_48fps
 *      2720x1528_50fps
 *      2720x1528_60fps
 *      2720x1528_120fps
 *      1920x1080_24fps
 *      1920x1080_25fps
 *      1920x1080_30fps
 *      1920x1080_48fps
 *      1920x1080_50fps
 *      1920x1080_60fps
 *      1920x1080_120fps
 *      1280x720_24fps
 *      1280x720_25fps
 *      1280x720_30fps
 *      1280x720_48fps
 *      1280x720_50fps
 *      1280x720_60fps
 *      1280x720_120fps
 *
 *  @param resolution   Video resolution.
 *
 *                      录像分辨率。
 *
 *  @param rate         Video frame rate.
 *
 *                      录像帧率。
 *
 *  @param block        Completion block.
 *
 *                      完成 block。
 *
 *  @see AUTELCameraVideoResolution
 *  @see AUTELCameraVideoFrameRate
 *  @see AUTELCompletionBlock
 */
- (void)setVideoResolution:(AUTELCameraVideoResolution)resolution
              andFrameRate:(AUTELCameraVideoFrameRate)rate
            withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get the video resolution and frame rate of the camera.
 *
 *  获取相机录像的视频分辨率和帧率
 *
 *  @param block    Competition block,including three parameters, error is wrong information, if error is nil, it means succeeds to obtain. Rate is the frame rate of the camera. When error is nor nil, resolution is AUTELCameraVideoResolutionUnknown, rate is AUTELCameraVideoFrameRateUnknown.
 *
 *                  完成 block，包含三个参数，error 为错误信息，error 为nil表示获取成功，rasolution 为相机录像的分辨率，rate 为相机录像的帧率，error不为nil时，resolution 为 AUTELCameraVideoResolutionUnknown，rate 为 AUTELCameraVideoFrameRateUnknown。
 *
 *  @see AUTELCameraVideoResolution
 *  @see AUTELCameraVideoFrameRate
 */
- (void)getVideoResolutionAndFrameRateWithCompletion:(void (^_Nullable)(AUTELCameraVideoResolution resolution, AUTELCameraVideoFrameRate rate, NSError * _Nullable error))block;

/**
 *  @brief Set video caption enabled.
 *
 *  设置相机录像的字幕使能。
 *
 *  @param enabled  Whether video caption is supported.
 *
 *                  是否支持视频字幕功能。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCompletionBlock
 */
- (void)setVideoCaptionEnabled:(BOOL)enabled withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get video caption enabled.
 *
 *  获取相机字幕使能
 *
 *  @param block    Completion block,including two parameters: error is wrong information; if error is nil, it means succeeded to obtain. Enabled is set as “NO” by default.
 *
 *                  完成 block，包含两个参数，error 为错误信息，error 为nil表示获取成功，error 不为空时，enabled 默认为NO.
 *
 */
- (void)getVideoCaptionEnabledWithCompletion:(void (^_Nullable)(BOOL enabled, NSError * _Nullable error))block;

/**
 *  @brief Set video file format.
 *  
 *  设置相机录像视频格式。
 *
 *  @param format   The supported video formats are: MOV and MP4.
 *
 *                  视频格式，支持MOV和MP4两种格式。
 *
 *  @param block    Completion block.
 *                  
 *                  完成 block。
 *
 *  @see AUTELCameraVideoFileFormat
 *  @see AUTELCompletionBlock
 */
- (void)setVideoFileFormat:(AUTELCameraVideoFileFormat)format
            withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get video file format.
 *
 *  获取相机录像视频格式
 *
 *  @param block    Completion block which includes two parameters: error is wrong information. If error is nil, it means succeeded to obtain. Format is video file format. When error is not nil, the format is AUTELCameraVideoFileFormatUnknown.
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，format 为录像视频格式，error不为nil时，format 为 AUTELBCameraVideoFileFormatUnknown。
 *
 *  @see AUTELCameraVideoFileFormat
 */
- (void)getVideoFileFormatWithCompletion:(void (^_Nullable)(AUTELCameraVideoFileFormat format, NSError * _Nullable error))block;

/**
 *  @brief Set Picture in video.
 *
 *  设置PIV使能。
 *
 *  @param enable  Whether auto enable picture in video feature.
 *
 *                  是否开启自动PIV功能。
 *
 *  @param interval  gap between each picture in auto PIV
 *
 *                  自动PIV时拍照间隔
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCameraPictureInVideoInterval
 *  @see AUTELCompletionBlock
 */
- (void)setPictureInVideoAutoEnable:(BOOL)enable andCaptureInterval:(AUTELCameraPictureInVideoInterval)interval withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get picture in video setting.
 *
 *  获取相机PIV设置
 *
 *  @param block    Competition block,including three parameters, error is wrong information, if error is nil, it means succeeds to obtain.
 *
 *                  完成 block，包含三个参数，error 为错误信息，error 为nil表示获取成功。
 *
 *  @see AUTELCameraPictureInVideoGap
 */
- (void)getPictureInVideoWithCompletion:(void (^_Nullable)(BOOL autoEnable, AUTELCameraPictureInVideoInterval interval, NSError * _Nullable error))block;


/**
 *  @brief Set video standard.
 *
 *  设置相机视频标准
 *
 *  @param videoStandard    Video standard. Support two standards: PAL and NTSC. Video resolution and frame rate are different for different standards.
 *
 *                          视频格式，支持PAL和NTSC两种标准，不同标准下支持的视频分辨率和帧率不同。
 *
 *  @param block  Completion block.
 *
 *                完成 block。
 *
 *  @see AUTELCameraVideoStandard
 *  @see AUTELCompletionBlock
 */
- (void)setVideoStandard:(AUTELCameraVideoStandard)videoStandard
          withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get video standard.
 *         
 *  获取相机录像视频格式
 *
 *  @param block    Completion block which includes two parameters: error is wrong information. When error is nil, it means succeeded to obtain. VideoStandard is video standard for the camera. If error is not nil, the video standard is AUTELCameraVideoStandardUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，videoStandard 为录像视频标准，error不为nil时，videoStandard 为 AUTELCameraVideoStandardUnknown。
 *
 *  @see AUTELCameraVideoStandard
 */
- (void)getVideoStandardWithCompletion:(void (^_Nullable)(AUTELCameraVideoStandard videoStandard, NSError * _Nullable error))block;

/**
 *  @brief 设置视频文件压缩标准
 *
 *  @param standard 待设置的标准
 *  @param block 返回 block
 */
- (void)setVideoFileCompressionStandard:(AUTELCameraVideoFileCompressionStandard)standard
                         withCompletion:(AUTELCompletionBlock)block;

/**
 * @brief 查询过视频文件压缩标准
 *
 *  @param block 完成 block, 如果查询过成功,则 error 为 nil, 否则 error 为查询失败原因
 */
- (void)getVideoFileCompressionStandard:(void(^_Nullable)(AUTELCameraVideoFileCompressionStandard standard, NSError * _Nullable error))block;


/*-------------------------------------------------------------------------*/
#pragma mark - Camera photo setting
/*-------------------------------------------------------------------------*/

/**
 *  @brief Set photo ratio.
 *
 *  设置拍照图片比例
 *
 *  @param ratio    Photo ratio. Supports three photo ratios: AUTELCameraPhotoAspectRatio4_3 (4864x3648)、AUTELCameraPhotoAspectRatio16_9 (5376x3024) and AUTELCameraPhotoAspectRatio3_2 (5376x3584).
 *
 *                  图片比例，支持三种比例：AUTELCameraPhotoAspectRatio4_3 (4864x3648)、AUTELCameraPhotoAspectRatio16_9 (5376x3024) 和 AUTELCameraPhotoAspectRatio3_2 (5376x3584)。
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCameraPhotoAspectRatio
 *  @see AUTELCompletionBlock
 */
- (void)setPhotoRatio:(AUTELCameraPhotoAspectRatio)ratio withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get photo ratio.
 *
 *  获取拍照图片比例。
 *
 *  @param block    Completion block which includes two parameters. Error is information error. If error is nil, it means succeeded to obtain. Ratio is photo ratio. When error is not nil, ratio is AUTELCameraPhotoAspectRatioUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，ratio 为拍照图片比例，error不为nil时，ratio 为 AUTELCameraPhotoAspectRatioUnknown。
 *
 *  @see AUTELCameraPhotoAspectRatio
 */
- (void)getPhotoRatioWithCompletion:(void (^_Nullable)(AUTELCameraPhotoAspectRatio ratio, NSError * _Nullable error))block;

///**
// *  @brief Whether photo quality setting is supported
// *
// *  是否支持设置图像质量
// */
//- (BOOL)isPhotoQualitySupported;

/**
 *  @brief Set photo file format.
 *
 *  设置拍照图片格式。
 *
 *  @param format   Photo file format.Three formats are supported: JPG, DNG, JPG+DNG.
 *
 *                  图片格式，支持三种格式 JPG、DNG 和 JPG+DNG
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCameraPhotoFileFormat
 *  @see AUTELCompletionBlock
 */
- (void)setPhotoFileFormat:(AUTELCameraPhotoFileFormat)format
            withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get photo file format.
 *
 *  获取拍照图片格式
 *
 *  @param block    Completion block which including two parameters. Error and format. When error is nil, it means succeeded to get. Format is photo file format. When error is not nil, format is AUTELCameraPhotoFileFormatUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，format 为拍照图片格式，error不为nil时，format 为 AUTELCameraPhotoFileFormatUnknown。
 *
 *  @see AUTELCameraPhotoFileFormat
 */
- (void)getPhotoFileFormatWithCompletion:(void (^_Nullable)(AUTELCameraPhotoFileFormat format, NSError * _Nullable error))block;

/**
 *  @brief Set numbers of burst shooting
 *
 *  设置快拍张数
 *
 *  @param count    Number of burst shooting.
 *
 *                  快拍张数。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCameraPhotoBurstCount
 *  @see AUTELCompletionBlock
 */
- (void)setPhotoBurstCount:(AUTELCameraPhotoBurstCount)count
            withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set numbers of burst shooting and set camera work mode to burst mode
 *
 *  设置快拍张数并将相机模式设置为连拍模式
 *
 *  @param count    Number of burst shooting.
 *
 *                  快拍张数。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCameraPhotoBurstCount
 *  @see AUTELCompletionBlock
 */
- (void)setWorkModeToBurstWithBurstCount:(AUTELCameraPhotoBurstCount)count withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief  Get numbers of burst shooting.
 *
 *  获取快拍张数设置
 *
 *  @param block    Completion block which including two parameters, error and format. When error is nil, it means succeeded to get. Count is the number of burst shooting images. When error is not nil, count is AUTELCameraPhotoBurstCountUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，count 为快拍张数设置，error不为nil时，count 为 AUTELCameraPhotoBurstCountUnknown。
 *
 *  @see AUTELCameraPhotoBurstCount
 */
- (void)getPhotoBurstCountWithCompletion:(void (^_Nullable)(AUTELCameraPhotoBurstCount count, NSError * _Nullable error))block;

/**
 *  @brief Set numbers of AEB shooting.
 *
 *  设置 AEB 模式拍照张数
 *
 *  @param count    Numbers of AEB shooting.
 *
 *                  AEB 模式拍照张数
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCameraPhotoAEBCaptureCount
 *  @see AUTELCompletionBlock
 */
- (void)setPhotoAEBCaptureCount:(AUTELCameraPhotoAEBCaptureCount)count
                 withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set camera work mode to AEB mode and set numbers of AEB shooting.
 *
 *  将相机工作模式设置为 AEB 连拍, 并设置 AEB 模式拍照张数
 *
 *  @param count    Numbers of AEB shooting.
 *
 *                  AEB 模式拍照张数
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCameraPhotoAEBCaptureCount
 *  @see AUTELCompletionBlock
 */
- (void)setWorkModeToAEBWithCount:(AUTELCameraPhotoAEBCaptureCount)count withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get numbers of AEB shooting.
 *
 *  获取 AEB 模式拍照张数设置
 *
 *  @param block    Completion block which including two parameters, error and count. When error is nil, it means succeeded to get. Count is the number of captures in AEB mode. When error is not nil, count is AUTELCameraPhotoAEBCountUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，count 为 AEB 模式拍照张数设置，error不为nil时，count 为 AUTELCameraPhotoAEBCaptureCountUnknown。
 *
 *  @see AUTELCameraPhotoAEBCaptureCount
 */
- (void)getPhotoAEBCaptureCountWithCompletion:(void (^_Nullable)(AUTELCameraPhotoAEBCaptureCount count, NSError * _Nullable error))block;

/**
 *  @brief Set timelapse interval。
 *
 *  设置定时拍摄参数.
 *
 *  @param interval Interval time (seconds). The parameter setting range is related to photo format. For DNG or JPG+DNG photos, the interval time shall be no less than 10s. This can be obtained when member variable parameters call –supportedCameraTimeLapseIntervalRange.
 *
 *                  定时拍间隔时间，单位为秒。可设置参数范围与图片格式相关，DNG 或者 JPG+DNG 模式下间隔时间应大于等于10s，可以通过成员变量 parameters 调用 -supportedCameraTimeLapseIntervalRange 方法获取。
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see -supportedCameraTimeLapseIntervalRange
 *  @see AUTELCameraPhotoTimeLapseInterval
 *  @see AUTELCompletionBlock
 */
- (void)setPhotoTimeLapseInterval:(AUTELCameraPhotoTimeLapseInterval)interval
               withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get timelapse interval.
 *
 *  获取定时拍摄参数。
 *
 *  @param block    Completion block which including two parameters, error and interval. When error is nil, it means succeeded to get. Interval is the interval time. When error is not nil, interval is AUTELCameraPhotoTimeLapseIntervalUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，interval 为 间隔时间，error不为nil时，interval 为 AUTELCameraPhotoTimeLapseIntervalUnknown。
 *
 *  @see AUTELCameraPhotoTimeLapseInterval
 */
- (void)getPhotoTimeLapseIntervalWithCompletion:(void (^_Nullable)(AUTELCameraPhotoTimeLapseInterval interval, NSError * _Nullable error))block;

/**
 *  @brief Set camera work mode to timelapse and set timelapse interval。
 *
 *  将相机工作模式修改为定实拍并设置定时拍摄参数.
 *
 *  @param interval Interval time (seconds). The parameter setting range is related to photo format. For DNG or JPG+DNG photos, the interval time shall be no less than 10s. This can be obtained when member variable parameters call –supportedCameraTimeLapseIntervalRange.
 *
 *                  定时拍间隔时间，单位为秒。可设置参数范围与图片格式相关，DNG 或者 JPG+DNG 模式下间隔时间应大于等于10s，可以通过成员变量 parameters 调用 -supportedCameraTimeLapseIntervalRange 方法获取。
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see -supportedCameraTimeLapseIntervalRange
 *  @see AUTELCameraPhotoTimeLapseInterval
 *  @see AUTELCompletionBlock
 */
- (void)setWorkModeToTimeLapseWithInterval:(AUTELCameraPhotoTimeLapseInterval)interval withCompletion:(AUTELCompletionBlock)block;

/*-------------------------------------------------------------------------*/
#pragma mark - Camera photo hdr
/*-------------------------------------------------------------------------*/

/// Turn HDR on and off
/// 打开、关闭HDR
///
/// @param ratio ratio
/// 比率
///
/// @param enable enable
/// 是否可用
///
/// @param block Completion
/// 完成回调
- (void)setPhotoRatio:(AUTELCameraPhotoAspectRatio)ratio HDREnable:(BOOL)enable  withCompletion:(AUTELCompletionBlock)block;

/// Get HDR on and off state
/// 获取打开、关闭HDR
///
/// @param block Completion
/// 完成回调
- (void)getPhotoRatioHDREnabledWithCompletion:(void (^_Nullable)(BOOL enabled, NSError * _Nullable error))block;

/*-------------------------------------------------------------------------*/
#pragma mark - Camera Video HDR
/*-------------------------------------------------------------------------*/

/**
 *  打开、关闭HDR
 */


/// Turn HDR on and off
/// 打开、关闭HDR
///
/// @param resolution resolution
/// 分辨率
/// @param rate rate
/// 比率
/// @param enable enable
/// 是否可用
/// @param block Completion
/// 完成回调
- (void)setVideoResolution:(AUTELCameraVideoResolution)resolution
              andFrameRate:(AUTELCameraVideoFrameRate)rate
                 HDREnable:(BOOL)enable
            withCompletion:(AUTELCompletionBlock)block;


/// /// Get HDR on and off state
/// 获取打开、关闭HDR
/// @param block Completion
/// 完成回调
- (void)getVideoHDREnabledWithCompletion:(void (^_Nullable)(BOOL enabled, NSError * _Nullable error))block;

/*-------------------------------------------------------------------------*/
#pragma mark - Camera Exposure Setting
/*-------------------------------------------------------------------------*/

///**
// *
// *  @brief Native method.Get setting states of exposure parameters in current exposure mode. Exposure settings include ISO, shutter speed, EV and aperture value.
// *
// *  本地方法,获取当前曝光模式下的曝光设置项可设置状态,曝光设置项包含ISO值、快门速度、曝光补偿和光圈值
// *
// *  @returen    NSDictionary type which includes four keys: ISO, Shutter Speed, Exposure Compensation and Aperture, respectively to set ISO value, shutter speed, EV and aperture value. Each key has three states: `Auto`, `Manual` and `Unknown`. `Auto` means the camera automatically sets the parameters, thus users cannot adjust the values. `Manual` means that users can adjust the values manually. `Unknown` means the camera is not connected, or unable to get the current exposure mode of the camera.
// *
// *              NSDictionary 类型，包含四个键: `ISO` , `ShutterSpeed`, `ExposureCompensation`, `Aperture` ,分别对应设置项ISO值、快门速度、曝光补偿和光圈值。每个键对应的值有三个状态，`Auto` 、 `Manual` 、 `Unknown` ，其中 `Auto` 表示当前曝光模式下相机自动配置该设置项，用户不可调； `Manual` 表示当前曝光模式下，用户可以手动调整该设置项； `Unknown` 表示没有连上相机，或者无法获取到相机当前曝光模式。
// */
//
//- (NSDictionary *)getExposureSettingState;

/**
 *  @brief Set exposure mode
 *
 *  设置曝光模式
 *
 *  @param mode Exposure mode. The setting range can be obtained when member variable parameters call –supportedCameraExposureModeRange.
 *
 *              曝光模式，设置范围可以通过成员变量 parameters 调用 -supportedCameraExposureModeRange 方法获取。
 *
 *  @param block  Completion block
 *
 *                完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see -supportedCameraExposureModeRange
 *  @see AUTELCameraExposureMode
 *  @see AUTELCompletionBlock
 */
- (void)setExposureMode:(AUTELCameraExposureMode)mode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get exposure mode
 *
 *  获取曝光模式
 *
 *  @param block    Completion block which including two parameters, error and exposureMode. When error is nil, it means succeeded to get. When error is not nil, exposureMode is AUTELCameraExposureModeUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，exposureMode 为曝光模式，error不为nil时，exposureMode 为 AUTELCameraExposureModeUnknown。
 *
 *  @see AUTELCameraExposureMode
 */
- (void)getExposureModeWithCompletion:(void (^_Nullable)(AUTELCameraExposureMode exposureMode, NSError * _Nullable error))block;

/**
 *  @brief Set ISO value
 *
 *  设置 ISO 值
 *
 *  @param iso  ISO value. The setting range of ISO value is related to exposure mode. ISO could be set only in AUTELCameraExposureModeManual(Manual Exposure Mode). The setting range could be obtained when member variable parameters call –supportedCameraISORange.
 *
 *              ISO参数值，设置范围与曝光模式相关，只有曝光模式为 AUTELCameraExposureModeManual(手动曝光模式) 时才能设置 ISO 值，设置范围可以通过成员变量 parameters 调用 -supportedCameraISORange 方法获取。
 *
 *  @param block  Completion block
 *
 *                完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see AUTELCameraISO
 *  @see AUTELCompletionBlock
 */
- (void)setISO:(AUTELCameraISO)iso withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get ISO value
 *
 *  获取 ISO 值
 *
 *  @param block Completion block which Block finished, including two parameters: error and iso. When error is nil, it means succeeded to obtain. If not, iso is AUTELCameraISOUnknown.
 *      
 *               完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，iso 为 AUTELCameraISOUnknown。
 *
 *  @see AUTELCameraISO
 */
- (void)getISOWithCompletion:(void (^_Nullable)(AUTELCameraISO iso, NSError * _Nullable error))block;

/**
 *  @brief Set ISO mode
 *
 *  设置感光度模式
 *
 *  @param mode ISO mode. The setting range can be obtained when member variable parameters call –supportedCameraISOModeRange.
 *
 *              曝光模式，设置范围可以通过成员变量 parameters 调用 -supportedCameraISOModeRange 方法获取。
 *
 *  @param block  Completion block
 *
 *                完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see -supportedCameraISOModeRange
 *  @see AUTELCameraISOMode
 *  @see AUTELCompletionBlock
 */
- (void)setISOMode:(AUTELCameraISOMode)mode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get ISO mode
 *
 *  获取曝光模式
 *
 *  @param block    Completion block which including two parameters, error and exposureMode. When error is nil, it means succeeded to get. When error is not nil, exposureMode is AUTELCameraExposureModeUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，exposureMode 为曝光模式，error不为nil时，exposureMode 为 AUTELCameraExposureModeUnknown。
 *
 *  @see AUTELCameraExposureMode
 */
- (void)getISOModeWithCompletion:(void (^_Nullable)(AUTELCameraISOMode mode, NSError * _Nullable error))block;

/**
 *  @brief Set shutter speed
 *
 *  设置快门速度
 *
 *  @param shutterSpeed Shutter speed. The setting range of shutter speed is related to exposure mode. Shutter speed could be set only in AUTELCameraExposureModeManual (Manual Exposure Mode). The setting range could be obtained when member variable parameters call –supportedCameraShutterSpeedRange. 
 *
 *                      快门速度，设置范围与曝光模式相关，只有曝光模式为 AUTELCameraExposureModeManual(手动曝光模式) 时才能设置快门速度，设置范围可以通过成员变量 parameters 调用 -supportedCameraShutterSpeedRange 方法获取。
 *
 *  @param block        Completion block.
 *
 *                      完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see AUTELCameraShutterSpeed
 *  @see AUTELCompletionBlock
 */
- (void)setShutterSpeed:(AUTELCameraShutterSpeed)shutterSpeed
         withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get shutter speed
 *
 *  获取快门速度
 *
 *  @param block    Completion block which including two parameters: error and ShutterSpeed. When error is nil, it means succeeded to obtain. If not, ShutterSpeed is AUTELCameraShutterSpeedUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，shutterSpeed 为 AUTELCameraShutterSpeedUnknown。
 *
 *  @see AUTELCameraShutterSpeed
 */
- (void)getShutterSpeedWithCompletion:(void (^_Nullable)(AUTELCameraShutterSpeed shutterSpeed, NSError * _Nullable error))block;

/**
 *  @brief Set spot metering coordinate value
 *
 *  设置点测光坐标值
 *
 *  @discussion To enable this method, AELock must be NO.
 *
 *  要使该方法有效，`AELock` 必须为NO。
 *
 *  @param rowIndex The setting range for Spot Metering Area row index is [1, 9].
 *
 *                  点测光横坐标值，设置范围为[1,9]
 *
 *  @param colIndex The setting range for Spot Metering Area col index is [1, 9].
 *
 *                  点测光纵坐标值，设置范围为[1,5]
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see AUTELCompletionBlock
 */
- (void)setSpotMeteringAreaRowIndex:(uint8_t)rowIndex
                        andColIndex:(uint8_t)colIndex
                     withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get spot metering coordinate value.
 *
 *  获取点测光坐标值。
 *
 *  @discussion To enable this method, AELock must be NO.
 *
 *  要使该方法有效，`AELock` 必须为NO。
 *
 *  @param block    Completion block which including three parameters. When error is nil, it means succeeded to obtain. If not, row index and column index are all 0.
 *                  完成 block，该 block 包含三个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，rowIndex 和 colIndex 均为0。
 *
 */
- (void)getSpotMeteringAreaRowIndexAndColIndexWithCompletion:(void (^_Nullable)(uint8_t rowIndex, uint8_t colIndex, NSError * _Nullable error))block;

/**
 *  @brief Set exposure compensation.
 *
 *  设置曝光补偿。
 *
 *  @param compensationType     Exposure compensation.The setting range of exposure compensation is related to exposure mode. Exposure compensation is only available when exposure mode is AUTELCameraExposureModeAuto (Auto Exposure mode) or AUTELCameraExposureModeAperture (Aperture-priority mode).The setting range could be obtained when member variable parameters call –supportedCameraExposureCompensationRange.
 *
 *                              曝光补偿值，设置范围与曝光模式相关，只有曝光模式为 AUTELCameraExposureModeAuto(自动曝光模式) 或者 AUTELCameraExposureModeAperture(光圈优先模式) 时才能设置曝光补偿，设置范围可以通过成员变量 parameters 调用 -supportedCameraExposureCompensationRange 方法获取。
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see AUTELCameraExposureCompensation
 *  @see AUTELCompletionBlock
 */
- (void)setExposureCompensation:(AUTELCameraExposureCompensation)compensationType withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get exposure compensation.
 *
 *  获取曝光补偿值。
 *
 *  @param block    Completion block which including two parameters, error and exposureCompensation. When error is nil, it means succeeded to obtain. If not, exposureCompensation is AUTELCameraExposureCompensationUnknown.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，exposureCompensation 为AUTELCameraExposureCompensationUnknown。
 *
 *  @see AUTELCameraExposureCompensation
 */
- (void)getExposureCompensationWithCompletion:(void (^_Nullable)(AUTELCameraExposureCompensation exposureCompensation, NSError * _Nullable error))block;

/**
 *  @brief Set AE Lock
 *
 *  设置 AE (自动曝光)是否锁定
 *
 *  @param isLock   Whether AE is locked. If isLock is YES, Then AE is locked. When AE is locked, spot metering function is not available.
 *
 *                  是否锁定 AE (自动曝光)，如果 isLock 为 YES 表示锁定 AE ，NO 表示不锁定。当 AE 锁定时，点测光功能不可使用。
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCompletionBlock
 */
- (void)setAELock:(BOOL)isLock withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get AE Lock
 *
 *  获取 AE (自动曝光)是否锁定
 *
 *  @discussion When AE is locked, spot metering function id not available.
 *
 *  当 AE 锁定时，点测光功能不可使用。
 *
 *  @param block    Completion block which including two parameters, error and isLock. When error is nil, it means succeeded to obtain. If not, isLock is set as NO by default.
 *                  
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，isLock 默认为 NO。
 *
 */
- (void)getAELockWithCompletion:(void (^_Nullable)(BOOL isLock, NSError * _Nullable error))block;


/**
 *  @brief Set white balance parameters
 *
 *  设置白平衡参数
 *
 *  @discussion Color temperature value is only available when the white balance mode is AUTELCameraWhiteBalanceCustom (custom mode).
 *
 *  色温值仅当白平衡模式为 AUTELCameraWhiteBalanceCustom（自定义模式）时有效。
 *
 *  @param whiteBalance     White balance value. Refer to AUTELCameraWhiteBalance for setting range. 
 *
 *                          白平衡值。设置范围参考 AUTELCameraWhiteBalance 枚举。
 *
 *  @param colorTemperature Color temperature setting range is [20,100]. The actual color temperature is: actual colorTemperature (K) = colorTemperature * 100, i.e. if the color temperature is 50, then the actual color temperature is 5000K. 
 *      
 *                          色温值，参数范围为 [20,100]，实际色温值 colorTemperature (K) = colorTemperature * 100,例如色温值为50，表示真实色温值为 5000K。
 *
 *  @param block  完成 block。
 *
 *  @see AUTELCameraWhiteBalance
 *  @see AUTELCompletionBlock
 */
- (void)setWhiteBalance:(AUTELCameraWhiteBalance)whiteBalance
    andColorTemperature:(uint8_t)colorTemperature
         withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get white balance parameters.
 *
 *  获取白平衡参数。
 *
 *  @param block    Completion block which including three parameters, error, whiteBalance and colorTemperature. When error is nil, it means succeeded to obtain. If not, whiteBalance is set as AUTELCameraWhiteBalanceUnknown by default, colorTemperature is set as 0 by default.  
 *
 *                  完成 block，该 block 包含三个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，whiteBalance 白平衡默认为 AUTELCameraWhiteBalanceUnknown， colorTemperature 色温默认为 0。
 *
 *  @see AUTELCameraWhiteBalance
 */
- (void)getWhiteBalanceAndColorTemperatureWithCompletion:(void (^_Nullable)(AUTELCameraWhiteBalance whiteBalance, uint8_t colorTemperature, NSError * _Nullable error))block;


/*-------------------------------------------------------------------------*/
#pragma mark - Camera Other Setting
/*-------------------------------------------------------------------------*/

/**
 *  @brief  Set video anti-flicker type 
 *
 *  设置视频抗闪烁模式
 *
 *  @discussion To enable this method, the exposure mode must be AUTELCameraExposureModeAuto (Auto Exposure mode).
 *
 *  要使该方法有效，必须曝光模式为 AUTELCameraExposureModeAuto(自动曝光模式)
 *
 *  @param antiFlickerType  Anti-flicker type.Refer to AUTELCameraAntiFlicker for setting range.
 *
 *                          抗闪烁模式。设置范围参考 AUTELCameraAntiFlicker 枚举。
 *
 *  @param block            Completion block.
 *
 *                          完成 block。
 *
 *  @see AUTELCameraAntiFlicker
 *  @see AUTELCompletionBlock
 */
- (void)setAntiFlicker:(AUTELCameraAntiFlicker)antiFlickerType
        withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief  Get video anti-flicker type 
 *
 *  获取视频抗闪烁模式
 *
 *  @discussion To enable this method, the exposure mode must be AUTELCameraExposureModeAuto (Auto Exposure mode).
 *
 *  要使该方法有效，必须曝光模式为 AUTELCameraExposureModeAuto(自动曝光模式)。
 *
 *  @param block    Completion block which including two parameters, error and anti-flicker. When error is nil, it means succeeded to obtain. If not, anti-flicker mode is set as AUTELCameraAntiFlickerUnknown by default.
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，antiFlicker 抗闪烁模式默认为 AUTELCameraAntiFlickerUnknown。
 *
 *  @see AUTELCameraAntiFlicker
 */
- (void)getAntiFlickerWithCompletion:(void (^_Nullable)(AUTELCameraAntiFlicker antiFlicker, NSError * _Nullable error))block;

/**
 *  @brief Set Photo style,sharpness,contrast,satutation and hue.
 *
 *  设置图像风格，锐度，对比度，饱和度，色度
 *
 *  @discussion Sharpness, contrast, saturation and color hue are available only when photo style is AUTELCameraPhotoStyleCustom (Customized mode). Sharpness setting is temporarily not available for Xteady R20 camera and it is set as zero by default.
 *
 *  仅当图像风格为 AUTELCameraPhotoStyleCustom(自定义风格) 时，锐度、对比度、饱和度和色度的设置才有效,Xteady R20 相机暂时不支持锐度设置，默认为0。
 *
 *  @param photoStyle   Photo style.Refer to AUTELCameraPhotoStyle for setting range.
 *
 *                      图像风格参数。设置范围参考 AUTELCameraPhotoStyle 枚举。
 *
 *  @param sharpness    Photo sharpness. Setting range: [-3, 3].
 *
 *                      图像锐度。设置范围[-3,3]。
 *
 *  @param contrast     Photo contrast. Setting range: [-3, 3].
 *
 *                      图像对比度。设置范围[-3,3]。
 *
 *  @param satutation   Photo satutation. Setting range: [-3, 3].
 *
 *                      图像饱和度。设置范围[-3,3]。
 *
 *  @param hue          Photo hue. Setting range: [-3, 3].
 *
 *                      图像色度。设置范围[-3,3]。
 *
 *  @param block        Completion block.
 *
 *                      完成 block。
 *
 *  @see AUTELCameraPhotoStyle
 *  @see AUTELCompletionBlock
 */
- (void)setPhotoStyle:(AUTELCameraPhotoStyle)photoStyle
         andSharpness:(int8_t)sharpness
          andContrast:(int8_t)contrast
        andSaturation:(int8_t)satutation
               andHue:(int8_t)hue
       withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get Photo style,sharpness,contrast,satutation and hue.
 *
 *  获取图像风格,锐度，对比度，饱和度，色度
 *
 *  @param block    Completion block which including five parameters. When error is nil, it means succeeded to obtain. If not, sharpness, contrast, saturation and hue are all set as zero by default.
 *  
 *                  完成 block，该 block 包含五个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，sharpness、contrast、saturation 和 hue 均默认为0。
 *
 *  @see AUTELCameraAntiFlicker
 */
- (void)getPhotoStyleAndSharpnessAndContrastAndSaturationAndHueWithCompletion:
(void (^_Nullable)(AUTELCameraPhotoStyle photoStyle, int8_t sharpness, int8_t contrast, int8_t saturation, int8_t hue, NSError * _Nullable error))block;

/**
 *  @brief Set photo digital filter (Photo color)
 *
 *  设置图像数码滤波风格(图像颜色)
 *
 *  @param filter   Photo digital filter. Refer to AUTELCameraDigitalFilter for the setting range of digital filter. 
 *
 *                  数码滤波风格参数。设置范围参考 AUTELCameraDigitalFilter 枚举。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCameraDigitalFilter
 *  @see AUTELCompletionBlock
 */
- (void)setDigitalFilter:(AUTELCameraDigitalFilter)filter withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief  Get photo digital filter (Photo color)
 *
 *  获取图像数码滤波风格(图像颜色)
 *
 *  @param  block   Completion block which including two parameters, error and filter.  When error is nil, it means succeeded to obtain. If not, filter is set as AUTELCameraDigitalFilterUnknown by default. 
 *
 *                  完成 block，该 block 包含两个个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，filter 默认为 AUTELCameraDigitalFilterUnknown。
 *
 *  @see AUTELCameraDigitalFilter
 */
- (void)getDigitalFilterWithCompletion:(void (^_Nullable)(AUTELCameraDigitalFilter filter, NSError * _Nullable error))block;

/**
 *  @brief Set aperture value.
 *
 *  设置光圈值。
 *
 *  @param aperture Aperture value.The setting range of aperture value is related to exposure mode. Aperture setting is only available when exposure mode is AUTELCameraExposureModeManual (Manual Exposure mode) or AUTELCameraExposureModeAperture (Aperture-priority mode). In AUTELCameraExposureModeAuto (Auto Exposure mode), aperture value changes in real time. The setting range could be obtained when member variable parameters call –supportedCameraApertureRange.
 *
 *                  光圈值，设置范围与曝光模式相关，只有曝光模式为 AUTELCameraExposureModeManual(手动曝光模式) 或者 AUTELCameraExposureModeAperture(光圈优先模式) 时才能设置光圈值，AUTELCameraExposureModeAuto(自动曝光模式) 下光圈值会实时变化，设置范围可以通过成员变量 parameters 调用 -supportedCameraApertureRange 方法获取。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see AUTELCameraAperture
 *  @see AUTELCompletionBlock
 */
- (void)setAperture:(AUTELCameraAperture)aperture withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get aperture value.
 *
 *  获取光圈值。
 *
 *  @param block    Completion block which including two parameters, error and aperture.  When error is nil, it means succeeded to obtain. If not, aperture is set as AUTELCameraApertureUnknown. 
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，aperture 为AUTELCameraApertureUnknown。
 *
 *  @see AUTELCameraAperture
 */
- (void)getApertureWithCompletion:(void (^_Nullable)(AUTELCameraAperture aperture, NSError * _Nullable error))block;

/**
 *  @brief Set lens focus mode. Support `Auto Focus` and `Manual Focus` two modes.
 *
 *  设置对焦模式，支持 Auto(自动对焦) 和 Manual(手动对焦) 两种模式。
 *
 *  @param focusMode    Lens focus mode.
 *
 *                      对焦模式。
 *
 *  @param block        Completion block.
 *
 *                      完成 block。
 *
 *  @see AUTELCameraLensFocusMode
 *  @see AUTELCompletionBlock
 */
- (void)setLensFocusMode:(AUTELCameraLensFocusMode)focusMode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get lens focus mode.
 *
 *  获取对焦模式
 *
 *  @param block    Completion block which including two parameters, error and focusMode.  When error is nil, it means succeeded to obtain. If not, focusMode is set as AUTELCameraLensFocusUnknown. 
 *
 *                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，focusMode 为AUTELCameraLensFocusModeUnknown。
 *
 *  @see AUTELCameraLensFocusMode
 */
- (void)getLensFocusModeWithCompletion:(void (^_Nullable)(AUTELCameraLensFocusMode focusMode, NSError * _Nullable error))block;

/**
*  @brief Set Lens auto focus mode.Support `Average Focus`,`Center Focus` and `Spot Focus` three modes.
*
*  设置MF手动辅助对焦模式以及点对焦坐标点。
*
*  @discussion This method is only available when the focus mode is AUTELCameraLensFocusModeManual (Auto Focus mode). RowIndex and ColIndex setting in Auto Focus mode are only available when Auto Focus mode is AUTELCameraAFLensFocusModeSpot (Spot Focus mode).
*
*  该方法仅当对焦模式为 AUTELCameraLensFocusModeManual(手动对焦模式) 时有效。
*
*  @param rowIndex     Focus point row index. The parameter setting range is [1, 9].
*
*                      点对焦横坐标。参数范围[1,100]。
*
*  @param colIndex     Focus point column index. The parameter setting range is [1, 9].
*
*                      点对焦纵坐标。参数范围[1,100]。
*
*  @param block        Completion block.
*
*                      完成 block。
*
*  @see AUTELCameraAFLensFocusMode
*  @see AUTELCompletionBlock
*/
- (void)setMFSportAreaRowIndex:(NSInteger)rowIndex
               andColIndex:(NSInteger)colIndex
            withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set Lens auto focus mode.Support `Average Focus`,`Center Focus` and `Spot Focus` three modes.
 *
 *  设置自动对焦模式，支持 Average(平均对焦), Center(中心对焦) 和 Spot(点对焦) 三种模式。
 *
 *  @discussion This method is only available when the focus mode is AUTELCameraLensFocusModeAuto (Auto Focus mode). RowIndex and ColIndex setting in Auto Focus mode are only available when Auto Focus mode is AUTELCameraAFLensFocusModeSpot (Spot Focus mode).
 *
 *  该方法仅当对焦模式为 AUTELCameraLensFocusModeAuto(自动对焦模式) 时有效,自动对焦模式里的 rowIndex 和 colIndex 的设置仅当自动对焦模式为 AUTELCameraAFLensFocusModeSpot(点对焦) 时有效。
 *
 *  @param afFocusMode  Auto focus mode.
 *
 *                      自动对焦模式。
 *
 *  @param rowIndex     Focus point row index. The parameter setting range is [1, 9].
 *
 *                      点对焦横坐标。参数范围[1,100]。
 *
 *  @param colIndex     Focus point column index. The parameter setting range is [1, 9].
 *
 *                      点对焦纵坐标。参数范围[1,100]。
 *
 *  @param block        Completion block.
 *
 *                      完成 block。
 *
 *  @see AUTELCameraAFLensFocusMode
 *  @see AUTELCompletionBlock
 */
- (void)setAFLensFocusMode:(AUTELCameraAFLensFocusMode)afFocusMode
  andLensFocusAreaRowIndex:(NSInteger)rowIndex
               andColIndex:(NSInteger)colIndex
            withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get Lens auto focus mode.
 *
 *  获取自动对焦模式。
 *
 *  @param block    Completion block which ncluding four parameters. When error is nil, it means succeeded to obtain. If not, afFocusMode is AUTELCameraAFLensFocusMODEUnknown, rowIndex and ColIndex are all zero.
 *
 *                  完成 block，该 block 包含四个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，afFocusMode 为AUTELCameraAFLensFocusModeUnknown , rowIndex 和 colIndex 均为0。
 *
 *  @see AUTELCameraLensFocusMode
 */
- (void)getAFLensFocusModeAndLensFocusAreaWithCompletion:(void (^_Nullable)(AUTELCameraAFLensFocusMode afFocusMode, NSInteger rowIndex, NSInteger colIndex, NSError * _Nullable error))block;

/**
 *  @brief Set Object distance in `Manual Focus` mode.
 *
 *  设置手动对焦模式下的物距。
 *
 *  @discussion This method is only available when the focus mode is AUTELCameraLensFocusModeManual (Manual Focus mode).
 *
 *  该方法仅当对焦模式为 AUTELCameraLensFocusModeManual(手动对焦模式) 时有效
 *
 *  @param distance Object distance of focus (unit: mm). It could be divided into three sections: [10cm, 1m], [1m, 10m] and [10m -100m]. Special value: 0(zero). Micro distance: -1: +∞. 
 *
 *                  对焦的物距，单位mm，分三个段(每段10个刻度)：[10cm,1m]、[1m,10m]和[10m -100m], 特殊值 0：微距， -1：无穷远。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCompletionBlock
 */
- (void)setObjectDistance:(NSInteger)distance withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get Object distance in `Manual Focus` mode.
 *
 *  获取手动对焦模式下的物距。
 *
 *  @param block    Completion block which including two parameters, error and objectDistance. When error is nil, it means succeeded to obtain. If not, objectDistance is set as zero by default.
 *
 *                  完成 block，该 block 包含两个个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，objectDisctance 默认为0 。
 *
 *  @see AUTELCameraLensFocusMode
 */
- (void)getObjectDistanceWithCompletion:(void (^_Nullable)(NSInteger objectDisctance, NSError * _Nullable error))block;


/// Set Manual Manual Focus Assist Enable
/// 设置手动动辅助对焦使能
/// @param enable enable
/// 使能
/// @param block Completion call back
/// 完成回调
- (void)setMFAssistFocusEnable:(NSInteger)enable withCompletion:(AUTELCompletionBlock)block;


///
/// 获取手动动辅助对焦使能
/// Get manual manual focus assist enable
/// @param block Completion call back
/// 完成回调
- (void)getMFAssistFocusEnableWithCompletion:(void (^_Nullable)(NSInteger enable, NSError * _Nullable error))block;



/**
 *  @brief Get system time.
 *
 *  获取系统时间。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @param dateTime System date string, the format is yyyy-MM-dd HH:mm:ss.
 *
 *                  系统日期字符串，格式为yyyy-MM-dd HH:mm:ss。
 *
 *  @param timeZone Time zone. The value shall be the offset seconds relative to the prime meridian. East of the prime meridian is positive value, while west of the prime meridian is negative value. 
 *
 *                  所在时区，取值为相对于本初子午线的偏移秒数，本初子午线以东为正值，以西为负值。
 *
 *  @param error    Error information.
 *
 *                  错误信息。
 *
 */
- (void)getSystemDataAndTimeWithCompletion:(void (^_Nullable)(NSString * _Nullable dateTime, NSTimeInterval timeZone, NSError * _Nullable error))block;

/**
 *  @brief 相机是否支持3D 降噪
 *  Does the camera support 3D noise reduction?
 *
 *  @return 如果相机支持3D 降噪功能,则返回 YES，否则返回 NO。
 *  Returns YES if the camera supports 3D noise reduction, otherwise returns NO.
 */
- (BOOL)is3DNREnableSupported;

/**
 *  @brief Set 3D DNR enabled.
 *
 *  设置3D降噪使能。
 *
 *  @param enabled  Enable 3D DNR.When enabled is “YES”, it means that 3D DNR is on. When enabled is “NO”, it means that 3D DNR is off. 
 *
 *                  使能3D降噪，enabled 为 YES 时，表示打开3D降噪功能，为NO时，表示关闭3D降噪功能。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCompletionBlock
 */
- (void)set3DNREnabled:(BOOL)enabled withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set 3D DNR enabled.
 *
 *  获取3D降噪使能
 *
 *  @param block    Completion block which ncluding two parameters, error and enabled. When error is nil, it means succeeded to obtain. If not, enable is set as `NO` by default. 
 *
 *                  完成 block，该 block 包含两个个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，enabled 默认为NO。
 *
 */
- (void)get3DNREnabledWithCompletion:(void (^_Nullable)(BOOL enabled, NSError * _Nullable error))block;

/**
 *  @brief Set histogram enabled.
 *
 *  设置直方图使能。
 *
 *  @discussion The histogram parameter changes will be notified by the camera only when the “enabled” for histogram is “YES”. Self’s delegate can obtain histogram parameters through calling –camera:didUpdateHistogramTotalPxels: andPixelsPerLevel:
 *
 *  只有设置直方图使能为 YES 时，相机才会推送直方图参数改变状态，self 的 delegate 代理类可以实现 -camera:didUpdateHistogramTotalPixels:andPixelsPerLevel: 回调方法获取直方图参数值
 *
 *  @param enabled  Histogram enabled. When enabled is “YES”, it means that histogram is on. When enabled is “NO”, it means that Histogram is off.
 *
 *                  直方图功能使能，enabled 为 YES 时，表示打开直方图功能，为NO时，表示关闭直方图功能。
 *
 *  @param block    Completion block.
 *
 *                  完成 block。
 *
 *  @see AUTELCompletionBlock
 */
- (void)setHistogramEnabled:(BOOL)enabled withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get histogram enabled.
 *
 *  获取直方图使能。
 *
 *  @param block    Completion block which  including two parameters, error and enabled. When error is nil, it means succeeded to obtain. If not, enable is set as “NO” by default. 
 *
 *                  完成 block，该 block 包含两个个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，enabled 默认为NO。
 *
 */
- (void)getHistogramEnabledWithCompletion:(void (^_Nullable)(BOOL enabled, NSError * _Nullable error))block;

/**
 *  @brief 确认相机是否资质数码变焦
 *  Confirm whether the camera is qualified for digital zoom
 *
 *  @return 返回 YES 表示相机支持数码变焦,否则返回 NO.
 *  Return YES means the camera supports digital zoom, otherwise return NO.
 */
- (BOOL)isDigitalZoomScaleSupported;

/**
 *  @brief 查询相机当前数码变焦倍数
 *  Query the current digital zoom factor of the camera
 *
 *  @param block - 完成 block
 *              - complete block
 */
- (void)getDigitalZoomScaleWithCompletion:(void (^_Nullable)(float scale, NSError * _Nullable error))block;

/**
 *  @brief 设置数码变焦倍数
 *  Set the digital zoom factor
 *
 *  @param scale - 待设置的变焦倍数
 *  @param block - 完成 block
 */
- (void)setDigitalZoomScale:(float)scale withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置透雾开关状态和强度
 *  Set the state and intensity of the fog through switch
 *
 *  @param switchStatus - 待设置的开关
 *  switch to be set
 *
 *  @param strength - 待设置的透雾强度：0-到10
 *  The fog penetration intensity to be set: 0- to 10
 *
 *  @param block - 完成 block
 *  complete block
 */
- (void)setDehazeSetting:(AUTELCameraSwitchStatus)switchStatus
            withStrength:(uint8_t)strength
          withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 获取透雾开关状态和强度
 *  Get the status and strength of the fog switch
 *
 *  @param block - 完成 block
 *  complete block
 */
- (void)getDehazeSettingWithCompletion:(void (^_Nullable)(AUTELCameraSwitchStatus switchStatus, uint8_t strength, NSError * _Nullable error))block;


/**
 *  @brief 设置ROI开关状态和强度
 *  Set ROI switch state and intensity
 *
 *  @param switchStatus - 待设置的开关
 *  switch to be set
 *
 *  @param strength - 待设置的透雾强度：0到10
 *  The fog penetration intensity to be set: 0 to 10
 *
 *  @param block - 完成 block
 *  complete block
 */
- (void)setImageRoiSetting:(AUTELCameraSwitchStatus)switchStatus
              withStrength:(uint8_t)strength
            withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 获取ROI开关状态和强度
 *  Get ROI switch state and intensity
 *
 *  @param block - 完成 block
 *  complete block
 */
- (void)getImageRoiSettingWithCompletion:(void (^ _Nullable)(AUTELCameraSwitchStatus switchStatus, uint8_t strength, NSError * _Nullable error))block;

/**
 *  @brief Set ROI metering coordinate value
 *
 *  设置ROI坐标值
 *
 *  @discussion To enable this method, AELock must be NO.
 *
 *  要使该方法有效，`AELock` 必须为NO。
 *
 *  @param rowIndex The setting range for Spot Metering Area row index is [0, 100].
 *
 *                  点测光横坐标值，设置范围为[0,100]
 *
 *  @param colIndex The setting range for Spot Metering Area col index is [0, 100].
 *
 *                  点测光纵坐标值，设置范围为[0,100]
 *
 *  @param block    Completion block
 *
 *                  完成 block。
 *
 *  @see AUTELCameraParameters
 *  @see AUTELCompletionBlock
 */
- (void)setImageRoiAreaRowIndex:(uint8_t)rowIndex andColIndex:(uint8_t)colIndex withCompletion:(AUTELCompletionBlock)block;

@end

/**
 *  SDCardOperations category of AUTELBaseCamera,this category archive SD card reading & writing,and also some other related operations.
 *
 *  AUTELBaseCamera 的 SDCardOperations 类别，该类别主要实现SD卡信息的读取和相关操作。
 */
@interface AUTELBaseCamera(SDCardOperations)

/**
 *  @brief Format the SD card
 *
 *  格式化SD卡。
 *
 *  @discussion When the SD card is formatted successfully, all the SD card data will be restored to the default value, and the camera will be reconnected to the app automatically after short disconnection.
 *
 *  格式化SD卡成功后，SD卡所有状态将会恢复初始值，相机会断开重连。
 *
 *  @param block  completion block.
 *
 *  完成 block。
 *
 *  @see AUTELCompletionBlock
 */
- (void)formatSDCardWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Retrieve the SD card information.
 *  
 *  获取SD卡信息。
 *
 *  @param block    completion block
 *
 *  完成 block
 *
 *  @param state    SD card state,Error is not nil, State returns nil.
 *
 *                  SD卡状态，error 不为nil时，state返回nil。
 *
 *  @param error    Error information,when Error is nil, retrieving data succeeded; when Error is not nil, retrieving data failed.
 *
 *                  错误信息，error 为nil表示获取成功，error不为nil时，表示获取失败。
 *
 *  @see AUTELCompletionBlock
 */
- (void)getSDCardInfoWithCompletion:(void (^_Nullable)(AUTELCameraSDCardState * _Nullable state, NSError * _Nullable error))block;

/**
 *  @brief Format the MMC
 *
 *  格式化机载闪存。
 *
 *  @discussion When the flash Card is formatted successfully, all the MMCdata will be restored to the default value, and the camera will be reconnected to the app automatically after short disconnection.
 *
 *  格式化机载闪存成功后，机载闪存所有状态将会恢复初始值，相机会断开重连。
 *
 *  @param block  completion block.
 *
 *  完成 block。
 *
 *  @see AUTELCompletionBlock
 */
- (void)formatMMCWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Retrieve the flash Card information.
 *
 *  获取机载闪存信息。
 *
 *  @param block    completion block
 *
 *  完成 block
 *
 *  @param state    flash Card state,Error is not nil, State returns nil.
 *
 *                  机载闪存状态，error 不为nil时，state返回nil。
 *
 *  @param error    Error information,when Error is nil, retrieving data succeeded; when Error is not nil, retrieving data failed.
 *
 *                  错误信息，error 为nil表示获取成功，error不为nil时，表示获取失败。
 *
 *  @see AUTELCompletionBlock
 */
- (void)getMMCInfoWithCompletion:(void (^_Nullable)(AUTELCameraSDCardState * _Nullable state, NSError * _Nullable error))block;

@end

@interface AUTELBaseCamera(CameraDeviceInfor)

/**
 *  @brief Get camera device information, eg. firmware version, device type etc.
 *
 *  获取相机设备信息，如固件版本号，设备类型等
 *
 *  @param block    completion block
 *
 *  @see AUTELCameraDeviceInforFirmwareVersionKey
 *  @see AUTELCameraDeviceInforSerialNumberKey
 *  @see AUTELCameraDeviceInforNameKey
 *
 *  完成 block
 */
- (void)getCameraDeviceInfoWithCompletion:(void (^_Nullable)(NSDictionary * _Nullable info, NSError * _Nullable error))block;

@end

@interface AUTELBaseCamera(CameraStorageType)

/**
*  @brief  Get camera storage type.
*
*  获取存储设备类型。
*
*  @param block    Completion block which including two parameters, error and storageType.  When error is nil, it means succeeded to obtain. If not, storageType is set as AUTELCameraStorageTypeUnknown.
*
*                  完成 block，该 block 包含两个参数，error 为错误信息，error 为nil表示获取成功，error不为nil时，storageType 为AUTELCameraStorageTypeUnknown。
*
*  @see AUTELCameraStorageType
*/
- (void)getCameraStorageTypeWithCompletion:(void (^_Nullable)(AUTELCameraStorageType type, NSError * _Nullable error))block;

/**
 *  @brief Set Get camera storage type.
 *
 *  设置存储设备类型。
 *
 *  @param AUTELCameraStorageType    Storage Type.
 *
 *                      存储类型。
 *
 *  @param block        Completion block.
 *
 *                      完成 block。
 *
 *  @see AUTELCameraStorageType
 *  @see AUTELCompletionBlock
 */
- (void)setCameraStorageType:(AUTELCameraStorageType)type withCompletion:(AUTELCompletionBlock)block;

@end

@interface AUTELBaseCamera(ThermalCamera)
/**
 *  @brief 返回相机是否是热成像相机
 *
 *  @return YES 当前连接的是热成像相机, NO 当前返回的不是热成像相机
 */

/**
*  @brief  Whether it is a thermal imaging camera.
*
*  返回相机是否是热成像相机。
*
@return YES 当前连接的是热成像相机, NO 当前返回的不是热成像相机
*
*                  YES is currently connected to a thermal imaging camera, NO currently returned is not a thermal imaging camera
*/
- (BOOL)isThermalImagingCamera;

/**
 *  @brief Query the display mode of the thermal imaging camera
 *
 *  查询热成像相机显示模式
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getThermalDisplayModeWithCompletion:(void(^_Nullable)(AUTELCameraThermalDisplayMode displaMode, NSError * _Nullable error))block;

/**
 *  @brief Set the thermal imaging camera display mode
 *
 *  设置热成像相机显示模式
 *
 *  @param displayMode 待设置的显示模式
 *  @param block 完成 block
 *
 *  @see AUTELCameraThermalDisplayMode
 *
 */
- (void)setThermalDisplayMode:(AUTELCameraThermalDisplayMode)displayMode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get thermal imaging pseudo color information of thermal imaging camera
 *
 *  获取热成像相机热成像伪彩信息
 *
 *  @param block completion block
 *
 *  完成 block
 *
 *  @see AUTELCameraIrColorType
 *
 */
- (void)GetIrColorWithCompletion:(void(^_Nullable)(AUTELCameraIrColorType color, NSError * _Nullable error))block;

/**
 *  @brief Set the thermal imaging pseudo color information of the thermal imaging camera
 *
 *  设置热成像相机热成像伪彩信息
 *
 *  @param color Thermal imaging pseudo color information to be set
 *
 *  待设置的热成像伪彩信息
 *
 *  @param block  completion block
 *
 *  @see AUTELCameraIrColorType
 */
- (void)setIrColor:(AUTELCameraIrColorType)color withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Set the thermal imaging shutter (FFC)
*
*  设置热成像快门(FFC)
*
*  @param block completion block
*
*/
- (void)setIrFlushShutterWithCompletion:(AUTELCompletionBlock)block;

///**
// *  @brief 查询相机红外成像色表
// *
// *  @param block completion block
// *
// *  完成 block
// */
//- (void)getThermalPaletteWithCompletion:(void(^)(AUTELCameraThermalPalette palette, NSError *error))block;
//
///**
// *  @brief 设置相机红外成像色表
// *
// *  @param palette 带设置的色表模式
// *  @param block completion block
// *
// *  完成 block
// */
//- (void)setThermalPalette:(AUTELCameraThermalPalette)palette withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询相机当前是否使能 MSX 功能
// *
// *  @param block completion block
// */
//- (void)getThermalMSXEnableWithCompletion:(void(^)(BOOL enable, NSError *error))block;
//
///**
// *  @brief 设置相机 MSX 使能
// *
// *  @param enable YES 使能 MSX,否则为NO
// *  @param block Completion block
// */
//- (void)setThermalMSXEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询相机 MSX Strength
// *
// *  @param block Completion block
// */
//- (void)getThermalMSXStrengthWithCompletion:(void(^)(NSUInteger strength, NSError *error))block;
//
///**
// *  @brief 设置相机 MSX Strength
// *
// *  @param strength 待设置的MSX强度
// *  @param block Completion block
// */
//- (void)setThermalMSXStrength:(NSUInteger)strength WithCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询 MSX 图像偏移设置
// *
// *  @param block Completion block
// */
//- (void)getThermalMSXAlignWithCompletion:(void(^)(NSInteger horizontalOffset, NSInteger verticalOffset, NSError *error))block;
//
///**
// *  @brief 设置 MSX 对齐图像的水平和垂直偏移
// *
// *  @param horizotalOffset 水平偏移,范围[-100, 100]
// *  @param verticalOffset 垂直偏移,范围[-8, 8]
// *  @param block Completion block
// */
//- (void)setThermalMSXAlignHorizontalOffset:(NSInteger)horizotalOffset
//                         andVerticalOffset:(NSInteger)verticalOffset
//                            withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief 查询 画中画的热成像位置信息
 *  Query the thermal imaging position information of the picture-in-picture
 *
 *  @param block Completion block,
 *              the block contains three parameters, error is the error message,
 *              error is nil to indicate success, deltaX is the horizontal offset, and deltaY is the vertical offset.
 *
 *             完成 block，该 block 包含三个参数，error 为错误信息，error 为nil表示获取成功，deltaX 为水平偏移，deltaY 为垂直偏移。
 *
 */
- (void)getIrPositionWithCompletion:(void(^_Nullable)(NSInteger deltaX, NSInteger deltaY, NSError * _Nullable error))block;

/**
 *  @brief 设置 画中画的热成像位置信息
 *  Setting the thermal imaging location information for picture-in-picture
 *
 *  @param deltaX 水平偏移,范围[-5, 5]
 *  horizontal offset, range [-5, 5]
 *
 *  @param deltaY 垂直偏移,范围[-5, 5]
 *  vertical offset, range [-5, 5]
 *
 *  @param block Completion block
 */
- (void)setIrPositionDeltaX:(NSInteger)deltaX
                     DeltaY:(NSInteger)deltaY
             withCompletion:(AUTELCompletionBlock)block;

///**
// *  @brief 查询热成像相机定实拍的时间间隔和时长
// *
// *  @param block Completion block
// */
//- (void)getThermalPhotoTimeLapseIntervalAndDurationWithCompletion:(void (^)(NSUInteger interval, NSUInteger duration, NSError *error))block;
//
///**
// *  @brief 设置热成像相机定实拍参数
// *
// *  @param interval 拍照时间间隔，参数有效范围[1, 60]
// *
// *  @param duration 定实拍持续的时长
// */
//- (void)setThermalPhotoTimeLapseInterval:(NSUInteger)interval andDuration:(NSUInteger)duration withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询相机视频存储模式
// *
// *  @param block 完成 block, 返回查询结果, mode 返回视频存储模式, 若查询成功 error 为 nil, 否则 error 为错误信息
// *
// *  @see AUTELCameraThermalVideoSavingMode
// */
//- (void)getThermalVideoSavingModeWithCompletion:(void(^)(AUTELCameraThermalVideoSavingMode mode, NSError *error))block;
//
///**
// *  @brief 设置热成像相机的视频存储模式
// *
// *  @param mode 待设置的视频保存模式
// *
// *  @param block 完成 block
// *
// *  @see AUTELCameraThermalVideoSavingMode
// */
//- (void)setThermalVideoSavingMode:(AUTELCameraThermalVideoSavingMode)mode withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询热成像相机红外视频文件格式
// *
// *  @param block 完成 blocl, 返回查询结果, 如果查询过成功 fileFormat 返回相机红外视频文件格式, error 为 nil. 如果查询失败, fileFormat 返回 AUTELCameraVideoFileFormatUnknown, error 返回错误信息.
// *
// *  @see AUTELCameraVideoFileFormat
// */
//- (void)getThermalIRVideoFileFormatWithCompletion:(void(^)(AUTELCameraVideoFileFormat fileFormat, NSError *error))block;
//
///**
// *  @brief 将设置热成像相机红外视频文件格式设置为指定的格式
// *
// *  @param fileFormat 指定的红外视频文件格式
// *
// *  @param block 完成 block
// */
//- (void)setThermalIRVideoFileFormat:(AUTELCameraVideoFileFormat)fileFormat withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询热成像相机画中画位置
// *
// *  @param block Completion block
// *
// *  @see AUTELCameraThermalPIPPosition
// */
//- (void)getThermalPIPPositionWithCompletion:(void(^)(AUTELCameraThermalPIPPosition pipPosition, NSError *error))block;
//
///**
// *  @brief 设置热成像画中画位置
// *
// *  @param position 待设置的画中画位置 @see AUTELCameraThermalPIPPosition
// *
// *  @param block 完成 block, 返回设置结果, 如果设置成功 error 为 nil, 否则 error 为错误信息
// */
//- (void)setThermalPIPPosition:(AUTELCameraThermalPIPPosition)position withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询热成像相机LED灯的状态
// *
// *  @param block Completion block
// *
// *  @see AUTELCameraThermalLEDState
// */
//- (void)getThermalLEDSettingsWithCompletion:(void(^)(AUTELCameraThermalLEDState state, NSError *error))block;
//
///**
// *  @brief 设置热成像相机LED灯的状态
// *
// *  @param state 待设置的画中画位置 @see AUTELCameraThermalLEDState
// *
// *  @param block 完成 block, 返回设置结果, 如果设置成功 error 为 nil, 否则 error 为错误信息
// */
//- (void)setThermalLEDSettings:(AUTELCameraThermalLEDState)state withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询辐射系数的温度单位
// *
// *  @param block 完成 block, 返回查询结果, 如果查询成功, unit 返回温度单位且 error 为 nil,否则 error 返回错误信息
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELCameraThermalTemperatureUnit
// *  @see AUTELBaseCameraType
// */
//- (void)getThermalRadiometryTemperatureUnitWithCompletion:(void(^)(AUTELCameraThermalTemperatureUnit unit, NSError *error))block;
//
///**
// *  @brief 将热成像相机的辐射系数的温度单位设置为特定值
// *
// *  @param unit 带设置的温度单位
// *
// *  @param block 完成 block, 返回设置结果
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELCameraThermalTemperatureUnit
// *  @see AUTELBaseCameraType
// */
//- (void)setThermalRadiometryTemperatureUnit:(AUTELCameraThermalTemperatureUnit)unit withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询过测温点使能状态
// *
// *  @param block 完成 block, 返回查询结果. 如果查询成功, enable 返回使能状态,且 error 为 nil. 否则 error 返回错误信息
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)getThermalRadiometrySpotMeterEnableWithCompletion:(void(^)(BOOL enable, NSError *error))block;
//
///**
// *  @brief 设置测温点使能状态
// *
// *  @param enable 待设置的使能状态
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)setThermalRadiometrySpotMeterEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询发射率
// *
// *  @param block 完成 block, 返回查询结果. 如果查询成功, enable 返回使能状态,且 error 为 nil. 否则 error 返回错误信息
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)getThermalRadiometryEmissivityWithCompletion:(void(^)(NSUInteger emissivity, NSError *error))block;
//
///**
// *  @brief 设置发射率
// *
// *  @param emissivity 发射率, 范围[50, 100]
// *
// *  @param block 完成 block, 返回设置结果
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)setThermalRadiometryEmissivity:(NSUInteger)emissivity withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询热成像相机辐射系数的空气温度参数
// *
// *  @param block 完成 block, 返回查询结果, 若查询成功 airTemperature 返回空气温度参数且 error 为 nil, 否则 error 返回错误信息
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)getThermalRadiometryAirTemperatureWithCompletion:(void(^)(NSInteger airTemperature, NSError *error))block;
//
///**
// *  @brief 将热成像相机辐射系数的空气温度参数设置为指定的数值
// *
// *  @param airTemperature 指定的空气温度参数, 范围[-50, 127], 单位摄氏度
// *
// *  @param block 完成 block, 返回设置结果
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)setThermalRadiometryAirTemperature:(NSInteger)airTemperature withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询热成像相机辐射系数的天空条件参数
// *
// *  @param block 完成 block, 返回查询结果. 如果查询成功, skyCondition 返回天空条件参数且 error 为 nil, 否则 error 返回错误信息
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)getThermalRadiometrySkyConditionWithCompletion:(void(^)(AUTELCameraThermalSkyCondition skyCondition, NSError *error))block;
//
///**
// *  @brief 将热成像相机辐射系数的天空条件参数设为指定值
// *
// *  @param skyCondition 指定的天空条件参数
// *
// *  @param block 完成 block, 返回设置结果
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)setThermalRadiometrySkyCondition:(AUTELCameraThermalSkyCondition)skyCondition withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询热成像相机辐射系数的湿度参数
// *
// *  @param block 完成 block, 返回查询结果. 若查询成功, humidity 返回湿度且 error 为 nil, 若查询失败 error 返回错误信息.
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)getThermalRadiometryHumidityWithCompletion:(void(^)(NSUInteger humidity, NSError *error))block;
//
///**
// *  @brief 将热成像相机辐射系数的湿度设置为特定值
// *
// *  @param humidity 指定的湿度, 范围[0, 100]
// *
// *  @param block 完成 block, 返回设置结果
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)setThermalRadiometryHumidity:(NSUInteger)humidity withCompletion:(AUTELCompletionBlock)block;
//
///**
// *  @brief 查询热成像相机辐射系数的目标距离参数
// *
// *  @param block 完成 block, 返回查询结果. 若查询成功, distance 返回距离参数且 error 为 nil, 若查询失败 error 返回错误信息.
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)getThermalRadiometrySubjectDistanceWithCompletion:(void(^)(NSUInteger distance, NSError *error))block;
//
///**
// *  @brief  将热成像相机辐射系数的目标距离参数设置为特定值
// *
// *  @param distance 指定的目标距离
// *
// *  @param block 完成 block, 返回设置结果
// *
// *  @note 该方法仅对 AUTELBaseCameraType_FlirDuo_R 类型相机有效
// *
// *  @see AUTELBaseCameraType
// */
//- (void)setThermalRadiometrySubjectDistance:(NSUInteger)distance withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief 获取热成像温度属性
 *  Get Thermal Image Temperature Properties
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getIrTempAttrWithCompletion:( void(^_Nullable)(AUTELIrTempAttrModel * _Nullable model, NSError *_Nullable error))block;

/**
 *  @brief 设置热成像温度属性
 *  Set thermal imaging temperature properties
 *
 *  @param model 待设置的热成像温度属性
 *  Thermal imaging temperature property to be set
 *
 *  @param block 完成 block
 *  Completion Block
 */
- (void)setIrTempAttr:(AUTELIrTempAttrModel *_Nonnull)model withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief 设置热成像测温模式
 *  Set the thermal imaging temperature measurement mode
 *
 *  @param tempMode 待设置的热成像测温模式
 *  Thermal imaging temperature measurement mode to be set
 *
 *  @param block 完成 block
 *  Completion Block
 */
- (void)setIrTempAttrModel:(AUTELCameraTempMode)tempMode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置热成像指点测温坐标
 *  Set thermal imaging pointing temperature measurement coordinates
 *
 *  @param touchX  待设置的热成像指点测温坐标X
 *  Thermal imaging pointing temperature measurement coordinates to be set X
 *
 *  @param touchY  待设置的热成像指点测温坐标Y
 *  Thermal imaging pointing temperature measurement coordinate Y to be set
 *
 *  @param block 完成 block
 *  Completion Block
 */
- (void)setIrTempAttrTouchX:(float)touchX touchY:(float)touchY withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置热成像区域测温位置
 *  Set the temperature measurement position of the thermal imaging area
 *
 *  @param regionX 待设置的热成像区域起点X
 *  The starting point X of the thermal imaging area to be set
 *
 *  @param regionY 待设置的热成像区域起点Y
 *  The starting point Y of the thermal imaging area to be set
 *
 *  @param regionW 待设置的热成像区域宽度
 *  The width of the thermal imaging area to be set
 *
 *  @param regionH 待设置的热成像区域高度
 *  The height of the thermal imaging area to be set
 *
 *  @param block CompletionBlock 完成 block
 */
- (void)setIrTempAttrRegionX:(float)regionX regionY:(float)regionY regionW:(float)regionW regionH:(float)regionH withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 获取热成像温度告警属性
 *  Get thermal imaging temperature alarm properties
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getIrTempAlarmWithCompletion:(void(^_Nullable)(AUTELIrTempAlarmModel * _Nullable model, NSError * _Nullable error))block;

/**
 *  @brief 设置热成像温度告警属性
 *  Set thermal imaging temperature alarm properties
 *
 *  @param model 待设置的热成像温度告警属性
 *  Thermal imaging temperature alarm properties to be set
 *
 *  @param block completion block 完成 block
 */
- (void)setIrTempAlarm:(AUTELIrTempAlarmModel *_Nonnull)model withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 查询热成像辐射率
 *  Query Thermal Imaging Emissivity
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getIrTempEmitWithCompletion:(void(^_Nullable)(int emit, NSError * _Nullable error))block;

/**
 *  @brief 设置热成像辐射率
 *  Set Thermal Imaging Emissivity
 *
 *  @param emit 待设置的热成像辐射率
 *  Thermal imaging emissivity to be set
 *
 *  @param block 完成 block completion block
 */
- (void)setIrTempEmit:(int)emit withCompletion:(AUTELCompletionBlock)block;


#pragma mark - Camera XT709、XT706_R setting

/**
 *  @brief 获取热成像图像模式
 *  Acquiring Thermal Image Mode
 *
 *  @param block    Complete the block. The block contains three parameters. error is error information, error is nil, indicating successful acquisition, imageMode is image mode, contrast is contrast, and lum is brightness.
 *
 *             完成 block，该 block 包含三个参数，error 为错误信息，error 为nil表示获取成功，imageMode为图像模式，contrast为 对比度，lum为亮度。
 *
 */
- (void)getIrImageModeWithCompletion:(void(^_Nullable)(AUTELCameraIrImageMode imageMode, NSInteger contrast, NSInteger lum, NSError * _Nullable error))block;

/**
 *  @brief 设置热成像图像模式
 *  Set Thermal Image Mode
 *
 *  @param imageMode 图像模式
 *  @param block Completion block
 */
- (void)setIrImageMode:(AUTELCameraIrImageMode)imageMode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置热成像图像对比度和亮度
 *  Set Thermal Image Contrast and Brightness
 *
 *  @param contrast 对比度0~255
 *  Contrast 0~255
 *
 *  @param lum 亮度0~511
 *  Brightness 0~511
 *
 *  @param block Completion block
 */
- (void)setIrImageContrast:(NSInteger)contrast lum:(NSInteger)lum withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 获取热成像图像增强
 *  Acquiring Thermal Image Enhancement
 *
 *  @param block    Complete the block. The block contains three parameters. error is error information, error is nil, indicating successful acquisition, enable is enabled, and strength is intensity.
 *
 *             完成 block，该 block 包含三个参数，error 为错误信息，error 为nil表示获取成功，enable为使能，strength为 强度。
 *
 */
- (void)getIrEnhanceWithCompletion:(void(^_Nullable)(BOOL enable, NSInteger strength, NSError * _Nullable error))block;

/**
 *  @brief 设置热成像图像增强
 *  Set up thermal image enhancement
 *
 *  @param enable 使能0~1 enable 0~1
 *  @param strength 强度1~8 Strength 1~8
 *  @param block Completion block 完成回调
 */
- (void)setIrEnhance:(BOOL)enable
                strength:(NSInteger)strength
             withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置热成像图像增强开关
 *  Setting the Thermal Image Enhancement Switch
 *
 *  @param enable 使能0~1 enable 0~1
 *  @param block Completion block 完成回调
 */
- (void)setIrEnhanceEnable:(BOOL)enable
             withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置热成像图像增强强度
 *  Set Thermal Image Enhancement Strength
 *
 *  @param strength 强度1~8 Strength 1~8
 *  @param block Completion block 完成回调
 */
- (void)setIrEnhanceStrength:(NSInteger)strength
             withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief 获取热成像图像去噪
 *  Acquire thermal image denoising
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getIrNrWithCompletion:(void(^_Nullable)(BOOL enable, NSError * _Nullable error))block;

/**
 *  @brief 设置热成像去噪
 *  Setting up thermal imaging denoising
 *
 *  @param enable 待设置的热成像去噪开关
 *  Thermal imaging denoising switch to be set
 *
 *  @param block 完成 block
 */
- (void)setIrNr:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 获取热成像图像增益
 *  Obtain thermal image gain
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getIrGainWithCompletion:(void(^_Nullable)(AUTELCameraIrGainType gainType, NSError * _Nullable error))block;

/**
 *  @brief 设置热成像增益
 *  Set thermal imaging gain
 *
 *  @param gainType 待设置的热成像增益类型
 *  Thermal imaging gain type to be set
 *
 *  @param block 完成 block
 */
- (void)setIrGain:(AUTELCameraIrGainType)gainType withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief 获取热成像等温线信息
*  Obtain thermal imaging isotherm information
*
*  @param block   Complete the block. The block contains three parameters. error is error information, error is nil, indicating successful acquisition, mode is thermal imaging isotherm mode, hotThred is high threshold in custom mode, and coldThred is low threshold in custom mode.
*
*             完成 block，该 block 包含三个参数，error 为错误信息，error 为nil表示获取成功，mode为热成像等温线模式，hotThred为 自定义模式时高阈值，coldThred为自定义模式时低阈值。
*
*/
- (void)getIrIsoThermWithCompletion:(void(^_Nullable)(AUTELCameraIrIsoThermMode mode, NSInteger hotThred, NSInteger coldThred, NSError * _Nullable error))block;

/**
 *  @brief 设置热成像等温线模式
 *  Setting the Thermal Imaging Isotherm Mode
 *
 *  @param mode 待设置的热成像等温线模式
 *  Thermal imaging isotherm mode to be set
 *
 *  @param block 完成 block
 */
- (void)setIrIsoThermMode:(AUTELCameraIrIsoThermMode)mode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置热成像等温线阈值
 *  Thermal imaging isotherm mode to be set
 *
 *  @param hotThred 待设置的自定义模式时高阈值
 *  High threshold when custom mode to be set
 *
 *  @param coldThred 待设置的自定义模式时低阈值
 *  Low threshold when custom mode to be set
 *
 *  @param block 完成 block
 */
- (void)setIrIsoThermHotThred:(NSInteger)hotThred coldThred:(NSInteger)coldThred withCompletion:(AUTELCompletionBlock)block;

///**
// *  @brief 获取热成像温宽拉伸
// *
// *  @param block    Complete the block. The block contains three parameters. error is error information, error is nil, indicating successful acquisition, imageMode is image mode, contrast is contrast, and lum is brightness.
// *
// *             完成 block，该 block 包含三个参数，error 为错误信息，error 为nil表示获取成功，enable为使能，hotThred为 温宽拉伸高阈值，coldThred为温宽拉伸低阈值。
// *
// */
//- (void)getIrTempWidthWithCompletion:(void(^_Nullable)(BOOL enable, NSInteger hotThred, NSInteger coldThred, NSError * _Nullable error))block;
//
///**
// *  @brief 设置热成像温宽拉伸
// *
// *  @param enable 使能0~1
// *  @param hotThred 温宽拉伸高阈值/10000
// *  @param coldThred 温宽拉伸低阈值/10000
// *  @param block Completion block
// */
//- (void)setIrTempWidth:(BOOL)enable
//                hotThred:(NSInteger)hotThred
//                coldThred:(NSInteger)coldThred
//             withCompletion:(AUTELCompletionBlock)block;


@end

@interface AUTELBaseCamera(XT701)
/**
 *  @brief  设置相机任务模式
 *  Set camera task mode
 *
 *  @param pattern 任务模式
 *  mission mode
 *
 *  @param block 完成 block, 返回设置结果
 *
 *  @note 飞控、视觉的任务需要与相机任务模式一致，才能正常工作，入延时摄影任务，相机任务模式需要设置为AUTELMisstionCameraPatternDelayPhoto
 *  The flight control and vision tasks need to be consistent with the camera task mode to work properly. For time-lapse photography tasks, the camera task mode needs to be set to AUTLMisstionCameraPatternDelayPhoto
 *
 *  @see AUTELMisstionCameraPattern
 */
- (void)setCameraPattern:(AUTELMisstionCameraPattern)pattern withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief 查询相机云台锁定状态
 *  Query camera gimbal lock status
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getGimbalLockStateWithCompletion:(void(^_Nullable)(AUTELCameraGimbalLockState lockState, NSError * _Nullable error))block;

/**
 *  @brief 设置相机云台锁定状态
 *  Set the camera gimbal lock state
 *
 *  @param lockState 待设置的云台锁定状态
 *  PTZ lock status to be set
 *
 *  @param block 完成 block
 */
- (void)setGimbalLockState:(AUTELCameraGimbalLockState)lockState withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 查询图传视频横竖屏模式
 *  Querying the horizontal and vertical screen modes of image transmission and video
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getVideoTransmissionModeWithCompletion:(void(^_Nullable)(AUTELCameraVideoTransmissionMode state, NSError * _Nullable error))block;

/**
 *  @brief 设置图传视频横竖屏模式
 *  Set the image transmission video horizontal and vertical screen mode
 *
 *  @param state 待设置的图传视频横竖屏模式
 *  The horizontal and vertical screen mode of the image transmission video to be set
 *
 *  @param block 完成 block
 */
- (void)setVideoTransmissionMode:(AUTELCameraVideoTransmissionMode)state withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 获取录像分段打包大小
 *  Get the video segment package size
 *
 *  @param block completion block
 *
 *  完成 block
 */
- (void)getRecordPacketStateWithCompletion:(void(^_Nullable)(AUTELCameraRecordPacketModel * _Nullable model, NSError * _Nullable error))block;

/**
 *  @brief 设置录像分段打包大小
 *  Set the video segment package size
 *
 *  @param model 待设置的任务录制状态
 *  To-be-set task recording status
 *
 *  @param block 完成 block
 */
- (void)setRecordPacketState:(AUTELCameraRecordPacketModel *_Nonnull)model withCompletion:(AUTELCompletionBlock)block;

///**
// *  @brief 获取GPS坐标系
// *
// *  @param block completion block
// *
// *  完成 block
// */
//- (void)getGPSMapDatumWithCompletion:(void(^_Nullable)(AUTELCameraVideoTransmissionMode state, NSError * _Nullable error))block;

/**
 *  @brief 设置GPS坐标系
 *  Set GPS coordinate system
 *
 *  @param value 待设置的GPS坐标系, 0 ：WGS-84，1：CGCS-2000
 *  complete block
 *
 *  @param block 完成 block
 */
- (void)setGPSMapDatum:(int)value withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置任务飞行图像格式
 *  Setting the mission flight image format
 *
 *  @param value 待设置的任务飞行图像格式，0 ：A格式，1：D格式
 *  Mission flight image format to be set, 0: A format, 1: D format
 *
 *  @param block 完成 block
 */
- (void)setMisstionFlyImageFormat:(int)value withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief 设置任务飞行图像模式
 *  Set Mission Flight Image Mode
 *
 *  @param value 待设置的任务飞行图像模式，0 ：晴天，1：阴天
 *  Mission flight image mode to be set, 0: sunny, 1: cloudy
 *
 *  @param block 完成 block
 */
- (void)setMisstionFlyImageMode:(int)value withCompletion:(AUTELCompletionBlock)block;
 

@end
