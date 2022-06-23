//
//  AUTELCameraDef.h
//  AUTELSDK
//
//  Created by IOS on 16/7/1.
//  Copyright © 2016年 Autel. All rights reserved.
//

#ifndef AUTELCameraDef_h
#define AUTELCameraDef_h

#import <Foundation/Foundation.h>


#define InvCameraPara (-1)//参数是无效的或参数不需要传给相机

//--------------------------------------------------------------
#pragma mark - AUTELBaseCameraType
//--------------------------------------------------------------
/**
 *  Define camera type.
 *
 *  定义相机类型
 *
 */
typedef NS_ENUM(NSInteger, AUTELBaseCameraType){
    /**
     *  @brief Unknown type
     *
     *  未知类型
     */
    AUTELBaseCameraType_Unknown           = 0xFF,
    
    /**
     *  @brief Type for camera Xteady R12
     *
     *  Xteady R12 相机
     */
    AUTELBaseCameraType_XteadyR12         = 0x00,
    
    /**
     *  @brief Type for camera of the Xteady R20
     *
     *  Xteady R20 相机
     */
    AUTELBaseCameraType_XteadyR20,
    
    /**
     *  @brief Type for camera of the Xteady H2
     *
     *  Xteady H2 相机
     */
    AUTELBaseCameraType_XteadyH2,
    
    /**
     *  @brief Type for camera of the XT701
     *
     *  XT701 相机
     */
    AUTELBaseCameraType_XT701,

    /**
     *  @brief Type for camera of the XT705
     *
     *  XT705 相机
     */
    AUTELBaseCameraType_XT705,
    
    /**
     *  @brief Type for camera of the XT706
     *
     *  XT706 双光相机
     */
    AUTELBaseCameraType_XT706,
    
    /**
     *  @brief Type for camera of the XT706 R
     *
     *  XT706R 双光相机
     */
    AUTELBaseCameraType_XT706_R,
    
    /**
     *  @brief Type for camera of the XT709
     *
     *  XT709 双光相机
     */
    AUTELBaseCameraType_XT709,
    
    /**
     *  @brief Type for camera of the XT712
     *
     *  XT712 相机
     */
    AUTELBaseCameraType_XT712,
    
    /**
     *  @brief Type for camera of the XL719
     *
     *  XL719 相机
     */
    AUTELBaseCameraType_XL719,
    
    /**
     *  @brief Type for camera of the XL720
     *
     *  XL720 相机
     */
    AUTELBaseCameraType_XL720,
    
    /**
     *  @brief Type for camera Flir Duo
     *
     *  Flir Duo 相机
     */
    AUTELBaseCameraType_FlirDuo,
    
    /**
     *  @brief Type for camera Flir Duo R
     *
     *  Flir Duo 相机
     */
    AUTELBaseCameraType_FlirDuo_R,
};

//--------------------------------------------------------------
#pragma mark - AUTELCameraConnectState
//--------------------------------------------------------------

/**
 *  Define camera connecting state.
 *
 *  定义相机连接状态
 */
typedef NS_ENUM(NSInteger, AUTELCameraConnectState) {
    /**
     *  @brief Camera disconnected
     *
     *  相机断开连接
     */
    AUTELCameraConnectStateDisconnect = 0,
    
    /**
     *  @brief Camera connected
     *
     *  相机已连接
     */
    AUTELCameraConnectStateConnected,
    
    /**
     *  @brief Camera state: unknown
     *
     *  未知状态
     */
    AUTELCameraConnectStateUnknown
};

//--------------------------------------------------------------
#pragma mark - AUTELCameraWorkMode
//--------------------------------------------------------------
/**
 *  Define camera working mode.
 *
 *  定义相机工作模式，可选模式包括Record、Single、Burst、Timelapse、AEB、Panorama、DelayShot、MotionDelayShot、SlowMotionRecord和LoopRecord、HDR、MFNR
 */
typedef NS_ENUM(uint8_t, AUTELCameraWorkMode){
    /**
     *  @brief Single shot
     *
     *  单拍
     */
    AUTELCameraWorkModeCaptureSingle    = 0x00,
    
    /**
     *  @brief Video mode
     *
     *  录像
     */
    AUTELCameraWorkModeRecordVideo,
    
    /**
     *  @brief Burst
     *
     *  连拍
     */
    AUTELCameraWorkModeCaptureBurst,
    
    /**
     *  @brief Timelaspe
     *
     *  定时拍
     */
    AUTELCameraWorkModeCaptureInterval,
    
    /**
     *  @brief AEB
     *
     *  AEB
     */
    AUTELCameraWorkModeCaptureAEB,
    
    /**
     *  @brief Panorama
     *
     *  全景拍摄
     */
    AUTELCameraWorkModeCapturePanorama,
    
    /**
     *  @brief Slow Motion
     *
     *  慢动作录影
     */
    AUTELCameraWorkModeRecordVideoSlowMotion,
    
    /**
     * @brief Looping
     *
     *  循环录影
     */
    AUTELCameraWorkModeRecordVideoLooping,
    
    /**
     *  @brief Moving TimeLapse
     *
     *  移动延时摄影
     */
    AUTELCameraWorkModeCaptureMovingTimeLapse,

    /**
     *  @brief HDR
     *
     *  HDR
     */
    AUTELCameraWorkModeCaptureHDR,

    /**
     *  @brief MFNR
     *
     *  纯净夜拍
     */
    AUTELCameraWorkModeCaptureMFNR,
    
    /**
     *  @brief Camera work mode unknown
     *
     *  未知工作模式
     */
    AUTELCameraWorkModeUnknown = 0xFF,
};

//--------------------------------------------------------------
#pragma mark - AUTELCameraSDCardFormattingState
//--------------------------------------------------------------
/**
 *  Define the SD card formatting state
 *
 *  定义相机 SD 卡格式化状态
 */
typedef NS_ENUM(uint8_t, AUTELCameraSDCardFormattingState) {
    /**
     *  @brief 没有在格式化
     */
    AUTELCameraSDCardFormattingStateNone,
    
    /**
     *  @brief 正在格式化 SD 卡
     */
    AUTELCameraSDCardFormattingStateFormatting,
    
    /**
     *  @brief 格式化成功
     */
    AUTELCameraSDCardFormattingStateSuccess,
    
    /**
     *  @brief 格式化失败
     */
    AUTELCameraSDCardFormattingStateFaile,
    
    /**
     *  @brief Unknown
     */
    AUTELCameraSDCardFormattingStateUnknown = 0xFF
};

//--------------------------------------------------------------
#pragma mark - AUTELCameraVideoFileFormat
//--------------------------------------------------------------
/**
 *  Define the file format of videos taken by the camera.
 *
 *  定义相机录制视频的文件格式
 */
typedef NS_ENUM(uint8_t, AUTELCameraVideoFileFormat)
{
    /**
     *  @brief MOV
     *
     *  MOV 格式
     **/
    AUTELCameraVideoFileFormatMOV       = 0,
    
    /**
     *  @brief MP4
     *
     *  MP4 格式
     **/
    AUTELCameraVideoFileFormatMP4,
    
    /**
     *  @brief TIFF, only for Thermal Camera
     */
    AUTELCameraVideoFileFormatTIFF,
    
    /**
     *  @brief Video format unknown
     *
     *  未知视频格式
     */
    AUTELCameraVideoFileFormatUnknown    = 0xFF,
};

//--------------------------------------------------------------
#pragma mark - AUTELCameraVideoResolution
//--------------------------------------------------------------
/**
 *  Define the resolution of videos taken by the camera.
 *
 *  定义相机录制视频的分辨率
 */
typedef NS_ENUM (uint8_t, AUTELCameraVideoResolution){
    /**
     *  @brief The camera's video resolution is 640x512.
     *
     *  相机录像分辨率为 640x512。
     */
    AUTELCameraVideoResolution640x512 = 0,
    /**
     *  @brief The camera's video resolution is 1280x720.
     *
     *  相机录像分辨率为 1280x720。
     */
    AUTELCameraVideoResolution1280x720,
    
    /**
     *  @brief The camera's video resolution is 1920x1080.
     *
     *  相机录像分辨率为 1920x1080。
     */
    AUTELCameraVideoResolution1920x1080,
    
    /**
     *  @brief The camera's video resolution is 2704x1520.
     *
     *  相机录像分辨率为 2704x1520。
     */
    AUTELCameraVideoResolution2704x1520,
    
    /**
     *  @brief The camera's video resolution is 2720x1528.
     *
     *  相机录像分辨率为 2720x1528。
     */
    AUTELCameraVideoResolution2720x1528,
    
    /**
     *  @brief The camera's video resolution is 2720x1530.
     *
     *  相机录像分辨率为 2720x1530。
     */
    AUTELCameraVideoResolution2720x1530,
    
    /**
     *  @brief The camera's video resolution is 3840x2160.
     *
     *  相机录像分辨率为 3840x2160。
     */
    AUTELCameraVideoResolution3840x2160,
    
    /**
     *  @brief The camera's video resolution is 4096x2160.
     *
     *  相机录像分辨率为 4096x2160。
     */
    AUTELCameraVideoResolution4096x2160,

    /**
     *  @brief The camera's video resolution is 4800x2700.
     *
     *  相机录像分辨率为 4800x2700。
     */
    AUTELCameraVideoResolution4800x2700,
    
    /**
     *  @brief The camera's video resolution is 5472x3076.
     *
     *  相机录像分辨率为 5472x3076。
     */
    AUTELCameraVideoResolution5472x3076,

    /**
     *  @brief The camera's video resolution is 5760x3240.
     *
     *  相机录像分辨率为 5760x3240。
     */
    AUTELCameraVideoResolution5760x3240,
    
    /**
     *  @brief The camera's video resolution is 7680x4320.
     *
     *  相机录像分辨率为 7680x4320。
     */
    AUTELCameraVideoResolution7680x4320,
    
    /**
     *  @brief The camera's video resolution is unknown.
     *
     *  相机录像分辨率未知。
     */
    AUTELCameraVideoResolutionUnknown = 0xFF,
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraVideoFrameRate
//-----------------------------------------------------------------
/**
 *  Define the frame rate of videos taken by the camera.
 *
 *  定义相机录制视频的帧率
 */
typedef NS_ENUM (uint8_t, AUTELCameraVideoFrameRate){
    /**
     *  @brief The camera's video frame rate is 9fps (frames per second).
     *
     *  相机录像帧率为 9fps (帧每秒)
     */
    AUTELCameraVideoFrameRate9fps = 0,
    /**
     *  @brief The camera's video frame rate is 24fps (frames per second).
     *
     *  相机录像帧率为 24fps (帧每秒)
     */
    AUTELCameraVideoFrameRate24fps,
    
    /**
     *  @brief The camera's video frame rate is 25fps (frames per second).
     *
     *  相机录像帧率为 25fps (帧每秒)
     */
    AUTELCameraVideoFrameRate25fps,
    
    /**
     *  @brief The camera's video frame rate is 30fps (frames per second).
     *
     *  相机录像帧率为 30fps (帧每秒)
     */
    AUTELCameraVideoFrameRate30fps,
    
    /**
     *  @brief The camera's video frame rate is 48fps (frames per second).
     *
     *  相机录像帧率为 48fps (帧每秒)
     */
    AUTELCameraVideoFrameRate48fps,
    
    /**
     *  @brief The camera's video frame rate is 50fps (frames per second).
     *
     *  相机录像帧率为 50fps (帧每秒)
     */
    AUTELCameraVideoFrameRate50fps,
    
    /**
     *  @brief The camera's video frame rate is 60fps (frames per second).
     *
     *  相机录像帧率为 60fps (帧每秒)
     */
    AUTELCameraVideoFrameRate60fps,
    
    /**
     *  @brief The camera's video frame rate is 120fps (frames per second).
     *  The frame rate can only be used when Slow Motion enabled.
     *
     *  相机录像帧率为 120fps (帧每秒)
     *  该视频帧率仅用于慢动作摄影中
     */
    AUTELCameraVideoFrameRate120fps,
    
    /**
     *  @brief The camera's video frame rate is 240fps (frames per second).
     *
     *  相机录像帧率为 240fps (帧每秒)
     */
    AUTELCameraVideoFrameRate240fps,
    
    /**
     *  @brief The camera's video frame rate is unknown.
     *
     *  相机录像帧率未知
     */
    AUTELCameraVideoFrameRateUnknown = 0xFF,
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraVideoStandard
//-----------------------------------------------------------------
/**
 *  Define the standard of videos taken by the camera.
 *
 *  定义相机录制视频的标准
 */
typedef NS_ENUM (uint8_t, AUTELCameraVideoStandard){
    /**
     *  @brief The video standard is set as PAL.
     *
     *  视频标准为PAL。
     */
    AUTELCameraVideoStandardPAL = 0,
    /**
     *  @brief The video standard is set as NTSC.
     *
     *  视频标准为NTSC。
     */
    AUTELCameraVideoStandardNTSC,
    /**
     *  @brief The video standard is unknown.
     *
     *  视频标准未知。
     */
    AUTELCameraVideoStandardUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraThermalVideoSavingMode
//-----------------------------------------------------------------
/**
 *  热成像相机保存视频的类型
 */
typedef NS_ENUM (uint8_t, AUTELCameraThermalVideoSavingMode) {
    /**
     *  @brief 保存可见光的视频
     */
    AUTELCameraThermalVideoSavingModeVisible = 0,
    
    /**
     *  @brief 保存红外辐射视频
     */
    AUTELCameraThermalVideoSavingModeInfraredRadiation,
    
    /**
     *  @brief 同时保存红外辐射视频和可见光视频
     */
    AUTELCameraThermalVideoSavingModeInfraredRadiationAndVisible,
    
    /**
     *  @brief 未知
     */
    AUTELCameraThermalVideoSavingModeUnknown = 0xFF,
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraVideoFileCompressionStandard
//-----------------------------------------------------------------
/**
 *  视频文件压缩标准
 */
typedef NS_ENUM (uint8_t, AUTELCameraVideoFileCompressionStandard) {
    /**
     *  @brief  H264 Video
     */
    AUTELCameraVideoFileCompressionStandardH264 = 0,
    
    /**
     *  @brief H265 Video
     */
    AUTELCameraVideoFileCompressionStandardH265,
    
    /**
     *  @brief Unknown
     */
    AUTELCameraVideoFileCompressionStandardUnknown = 0xFF,
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraExposureMode
//-----------------------------------------------------------------
/**
 *  Camera exposure modes.
 *
 *  The different exposure modes define whether Aperture, Shutter Speed, ISO, EV can
 *  be set automatically or manually. Exposure compensation can be changed in all modes
 *  except Manual mode where it is not settable.
 *
 *  相机曝光模式
 *
 *  不同的曝光模式会决定光圈值、快门速度、ISO 值、曝光补偿是自动设置还是可手动设置。曝光补偿除了手动曝光模式外，其他模式都可调。
 *
 *   Xteady R20:
 *       Auto Mode:          Shutter: Auto      Aperture: Auto     ISO: Auto     EV: Manual
 *       Shutter Priority:   N/A
 *       Aperture Priority:  Shutter: Auto      Aperture: Manual   ISO: Manual   EV: Manual
 *       Manual Mode:        Shutter: Manual    Aperture: Manual   ISO: Manual   EV: Auto
 *
 *
 */
typedef NS_ENUM (uint8_t, AUTELCameraExposureMode){
    /**
     *  @brief Auto mode.
     *
     *  自动曝光模式
     */
    AUTELCameraExposureModeAuto = 0,
    /**
     *  @brief Shutter priority mode.
     *
     *  快门优先模式（X008\XB012相机不支持）
     */
    AUTELCameraExposureModeShutter,
    /**
     *  @brief Aperture priority mode.
     *
     *  光圈优先模式 (XB012相机不支持)
     */
    AUTELCameraExposureModeAperture,
    /**
     *  @brief Manual mode.
     *
     *  手动曝光模式
     */
    AUTELCameraExposureModeManual,
    /**
     *  @brief The camera exposure mode is unknown.
     *
     *  未知曝光模式
     */
    AUTELCameraExposureModeUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraShutterSpeed
//-----------------------------------------------------------------
/**
 *  Define shutter speed options of the camera.
 *
 *  定义相机快门速度选项
 */
typedef NS_ENUM (uint8_t, AUTELCameraShutterSpeed) {
    /**
     *  @brief The shutter speed is 1/10000 s.
     *
     *  快门速度是 1/10000 秒
     */
    AUTELCameraShutterSpeed1_10000 = 0x0f,//从0f开始，预留位置
    /**
     *  @brief The shutter speed is 1/8000 s.
     *
     *  快门速度是 1/8000 秒
     */
    AUTELCameraShutterSpeed1_8000 = 0x10,
    /**
     *  @brief The shutter speed is 1/6000 s.
     *
     *  快门速度是 1/6000 秒
     */
    AUTELCameraShutterSpeed1_6000 = 0x11,
    /**
     *  @brief The shutter speed is 1/5000 s.
     *
     *  快门速度是 1/5000 秒
     */
    AUTELCameraShutterSpeed1_5000 = 0x12,
    /**
     *  @brief The shutter speed is 1/4000 s.
     *
     *  快门速度是 1/4000 秒
     */
    AUTELCameraShutterSpeed1_4000 = 0x13,
    /**
     *  @brief The shutter speed is 1/3200 s.
     *
     *  快门速度是 1/3200 秒
     */
    AUTELCameraShutterSpeed1_3200 = 0x14,
    /**
     *  @brief The shutter speed is 1/2500 s.
     *
     *  快门速度是 1/2500 秒
     */
    AUTELCameraShutterSpeed1_2500 = 0x15,
    /**
     *  @brief The shutter speed is 1/2000 s.
     *
     *  快门速度是 1/2000 秒
     */
    AUTELCameraShutterSpeed1_2000 = 0x16,
    /**
     *  @brief The shutter speed is 1/1600 s.
     *
     *  快门速度是 1/1600 秒
     */
    AUTELCameraShutterSpeed1_1600 = 0x17,
    /**
     *  @brief The shutter speed is 1/1250 s.
     *
     *  快门速度是 1/1250 秒
     */
    AUTELCameraShutterSpeed1_1250 = 0x18,
    /**
     *  @brief The shutter speed is 1/1000 s.
     *
     *  快门速度是 1/1000 秒
     */
    AUTELCameraShutterSpeed1_1000 = 0x19,
    /**
     *  @brief The shutter speed is 1/800 s.
     *
     *  快门速度是 1/800 秒
     */
    AUTELCameraShutterSpeed1_800 = 0x1A,
    /**
     *  @brief The shutter speed is 1/640 s.
     *
     *  快门速度是 1/640 秒
     */
    AUTELCameraShutterSpeed1_640 = 0x1B,
    /**
     *  @brief The shutter speed is 1/500 s.
     *
     *  快门速度是 1/500 秒
     */
    AUTELCameraShutterSpeed1_500 = 0x1C,
    /**
     *  @brief The shutter speed is 1/400 s.
     *
     *  快门速度是 1/400 秒
     */
    AUTELCameraShutterSpeed1_400 = 0x1D,
    /**
     *  @brief The shutter speed is 1/320 s.
     *
     *  快门速度是 1/320 秒
     */
    AUTELCameraShutterSpeed1_320 = 0x1E,
    /**
     *  @brief The shutter speed is 1/240 s.
     *
     *  快门速度是 1/240 秒
     */
    AUTELCameraShutterSpeed1_240 = 0x1F,
    /**
     *  @brief The shutter speed is 1/200 s.
     *
     *  快门速度是 1/200 秒
     */
    AUTELCameraShutterSpeed1_200 = 0x20,
    /**
     *  @brief The shutter speed is 1/160 s.
     *
     *  快门速度是 1/160 秒
     */
    AUTELCameraShutterSpeed1_160 = 0x21,
    /**
     *  @brief The shutter speed is 1/120 s.
     *
     *  快门速度是 1/120 秒
     */
    AUTELCameraShutterSpeed1_120 = 0x22,
    /**
     *  @brief The shutter speed is 1/100 s.
     *
     *  快门速度是 1/100 秒
     */
    AUTELCameraShutterSpeed1_100 = 0x23,
    /**
     *  @brief The shutter speed is 1/80 s.
     *
     *  快门速度是 1/80 秒
     */
    AUTELCameraShutterSpeed1_80 = 0x24,
    /**
     *  @brief The shutter speed is 1/60 s.
     *
     *  快门速度是 1/60 秒
     */
    AUTELCameraShutterSpeed1_60 = 0x25,
    /**
     *  @brief The shutter speed is 1/50 s.
     *
     *  快门速度是 1/50 秒
     */
    AUTELCameraShutterSpeed1_50 = 0x26,
    /**
     *  @brief The shutter speed is 1/40 s.
     *
     *  快门速度是 1/40 秒
     */
    AUTELCameraShutterSpeed1_40 = 0x27,
    /**
     *  @brief The shutter speed is 1/30 s.
     *
     *  快门速度是 1/30 秒
     */
    AUTELCameraShutterSpeed1_30 = 0x28,
    /**
     *  @brief The shutter speed is 1/25 s.
     *
     *  快门速度是 1/25 秒
     */
    AUTELCameraShutterSpeed1_25 = 0x29,
    /**
     *  @brief The shutter speed is 1/20 s.
     *
     *  快门速度是 1/20 秒
     */
    AUTELCameraShutterSpeed1_20 = 0x2A,
    /**
     *  @brief The shutter speed is 1/15 s.
     *
     *  快门速度是 1/15 秒
     */
    AUTELCameraShutterSpeed1_15 = 0x2B,
    /**
     *  @brief The shutter speed is 1/12.5 s.
     *
     *  快门速度是 1/12.5 秒
     */
    AUTELCameraShutterSpeed1_12p5 = 0x2C,
    /**
     *  @brief The shutter speed is 1/10 s.
     *
     *  快门速度是 1/10 秒
     */
    AUTELCameraShutterSpeed1_10 = 0x2D,
    /**
     *  @brief The shutter speed is 1/8 s.
     *
     *  快门速度是 1/8 秒
     */
    AUTELCameraShutterSpeed1_8 = 0x2E,
    /**
     *  @brief The shutter speed is 1/6.25 s.
     *
     *  快门速度是 1/6.25 秒
     */
    AUTELCameraShutterSpeed1_6p25 = 0x2F,
    /**
     *  @brief The shutter speed is 1/5 s.
     *
     *  快门速度是 1/5 秒
     */
    AUTELCameraShutterSpeed1_5 = 0x30,
    /**
     *  @brief The shutter speed is 1/4 s.
     *
     *  快门速度是 1/4 秒
     */
    AUTELCameraShutterSpeed1_4 = 0x31,
    /**
     *  @brief The shutter speed is 1/3 s.
     *
     *  快门速度是 1/3 秒
     */
    AUTELCameraShutterSpeed1_3 = 0x32,
    /**
     *  @brief The shutter speed is 1/2.5 s.
     *
     *  快门速度是 1/2.5 秒
     */
    AUTELCameraShutterSpeed1_2p5 = 0x33,
    /**
     *  @brief The shutter speed is 1/2 s.
     *
     *  快门速度是 1/2 秒
     */
    AUTELCameraShutterSpeed1_2 = 0x34,
    /**
     *  @brief The shutter speed is 1/1.67 s.
     *
     *  快门速度是 1/1.67 秒
     */
    AUTELCameraShutterSpeed1_1p67 = 0x35,
    /**
     *  @brief The shutter speed is 1/1.25 s.
     *
     *  快门速度是 1/1.25 秒
     */
    AUTELCameraShutterSpeed1_1p25 = 0x36,
    /**
     *  @brief The shutter speed is 1 s.
     *
     *  快门速度是 1 秒
     */
    AUTELCameraShutterSpeed1p0 = 0x37,
    /**
     *  @brief The shutter speed is 1.3 s.
     *
     *  快门速度是 1.3 秒
     */
    AUTELCameraShutterSpeed1p3 = 0x38,
    /**
     *  @brief The shutter speed is 1.6s.
     *
     *  快门速度是 1.6 秒
     */
    AUTELCameraShutterSpeed1p6 = 0x39,
    /**
     *  @brief The shutter speed is 2 s.
     *
     *  快门速度是 2 秒
     */
    AUTELCameraShutterSpeed2p0 = 0x3A,
    /**
     *  @brief The shutter speed is 2.5 s.
     *
     *  快门速度是 2.5 秒
     */
    AUTELCameraShutterSpeed2p5 = 0x3B,
    /**
     *  @brief The shutter speed is 3.0s.
     *
     *  快门速度是 3.0 秒
     */
    AUTELCameraShutterSpeed3p0 = 0x3C,
    /**
     *  @brief The shutter speed is 3.2 s.
     *
     *  快门速度是 3.2 秒
     */
    AUTELCameraShutterSpeed3p2 = 0x3D,
    /**
     *  @brief The shutter speed is 4 s.
     *
     *  快门速度是 4 秒
     */
    AUTELCameraShutterSpeed4p0 = 0x3E,
    /**
     *  @brief The shutter speed is 5 s.
     *
     *  快门速度是 5 秒
     */
    AUTELCameraShutterSpeed5p0 = 0x3F,
    /**
     *  @brief The shutter speed is 6 s.
     *
     *  快门速度是 6 秒
     */
    AUTELCameraShutterSpeed6p0 = 0x40,
    /**
     *  @brief The shutter speed is 8 s.
     *
     *  快门速度是 8 秒
     */
    AUTELCameraShutterSpeed8p0 = 0x41,
    /**
     *  @brief The shutter speed is 9 s.
     *
     *  快门速度是 9 秒
     */
    AUTELCameraShutterSpeed9p0 = 0x42,
    /**
     *  @brief The shutter speed is 10 s.
     *
     *  快门速度是 10 秒
     */
    AUTELCameraShutterSpeed10p0 = 0x43,
    /**
     *  @brief The shutter speed is 13 s.
     *
     *  快门速度是 13 秒
     */
    AUTELCameraShutterSpeed13p0 = 0x44,
    /**
     *  @brief The shutter speed is 15 s.
     *
     *  快门速度是 15 秒
     */
    AUTELCameraShutterSpeed15p0 = 0x45,
    /**
     *  @brief The shutter speed is 20 s.
     *
     *  快门速度是 20 秒
     */
    AUTELCameraShutterSpeed20p0 = 0x46,
    /**
     *  @brief The shutter speed is 25 s.
     *
     *  快门速度是 25 秒
     */
    AUTELCameraShutterSpeed25p0 = 0x47,
    /**
     *  @brief The shutter speed is 30 s.
     *
     *  快门速度是 30 秒
     */
    AUTELCameraShutterSpeed30p0 = 0x48,
    /**
     *  @brief The shutter speed is unknown.
     *
     *  快门速度未知
     */
    AUTELCameraShutterSpeedUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraISO
//-----------------------------------------------------------------
/**
 *  Define ISO options of the camera.
 *
 *  定义相机 ISO 选项
 */
typedef NS_ENUM (uint8_t, AUTELCameraISO){
    /**
     *  @brief The ISO value is set to 100.
     *
     *  ISO 值为 100。
     */
    AUTELCameraISO100 = 0,
    /**
     *  @brief The ISO value is set to 200.
     *
     *  ISO 值为 200。
     */
    AUTELCameraISO200 = 1,
    /**
     *  @brief The ISO value is set to 400.
     *
     *  ISO 值为 400。
     */
    AUTELCameraISO400 = 2,
    /**
     *  @brief The ISO value is set to 800.
     *
     *  ISO 值为 800。
     */
    AUTELCameraISO800 = 3,
    /**
     *  @brief The ISO value is set to 1600.
     *
     *  ISO 值为 1600。
     */
    AUTELCameraISO1600 = 4,
    /**
     *  @brief The ISO value is set to 3200.
     *
     *  ISO 值为 3200。
     */
    AUTELCameraISO3200 = 5,
    /**
     *  @brief The ISO value is set to 6400.
     *
     *  ISO 值为 6400。
     */
    AUTELCameraISO6400 = 6,
    /**
     *  @brief The ISO value is set to 12800.
     *
     *  ISO 值为 12800。
     */
    AUTELCameraISO12800 = 7,
    /**
     *  @brief The ISO value is set to 25600.
     *
     *  ISO 值为 25600。
     */
    AUTELCameraISO25600 = 8,
    /**
     *  @brief The ISO value is set to an unknown value.
     *
     *  ISO 值未知。
     */
    AUTELCameraISOUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraISOMode
//-----------------------------------------------------------------
/**
 *  Define ISO Mode of the camera.
 *
 *  定义相机 ISO 模式
 */
typedef NS_ENUM (uint8_t, AUTELCameraISOMode){
    /**
     *  @brief The ISO Mode is Auto.
     *
     *  ISO 模式为自动。
     */
    AUTELCameraISOModeAuto = 0,
    /**
     *  @brief The ISO Mode is Manual.
     *
     *  ISO 模式为手动。
     */
    AUTELCameraISOModeManual = 1,
    /**
     *  @brief The ISO Mode  is set to an unknown value.
     *
     *  ISO  模式未知。
     */
    AUTELCameraISOModeUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraExposureCompensation
//-----------------------------------------------------------------
/**
 *   Define EV options.
 *
 *   定义曝光补偿选项。
 */
typedef NS_ENUM (uint8_t, AUTELCameraExposureCompensation){
    /**
     *  @brief The camera's exposure compensation is -3.0ev.
     *
     *  相机曝光补偿值为 -3.0ev。
     */
    AUTELCameraExposureCompensationN30 = 0x00,
    /**
     *  @brief The camera's exposure compensation is -2.7ev.
     *
     *  相机曝光补偿值为 -2.7ev。
     */
    AUTELCameraExposureCompensationN27,
    /**
     *  @brief The camera's exposure compensation is -2.3ev.
     *
     *  相机曝光补偿值为 -2.3ev。
     */
    AUTELCameraExposureCompensationN23,
    /**
     *  @brief The camera's exposure compensation is -2.0ev.
     *
     *  相机曝光补偿值为 -2.0ev。
     */
    AUTELCameraExposureCompensationN20,
    /**
     *  @brief The camera's exposure compensation is -1.7ev.
     *
     *  相机曝光补偿值为 -1.7ev。
     */
    AUTELCameraExposureCompensationN17,
    /**
     *  @brief The camera's exposure compensation is -1.3ev.
     *
     *  相机曝光补偿值为 -1.3ev。
     */
    AUTELCameraExposureCompensationN13,
    /**
     *  @brief The camera's exposure compensation is -1.0ev.
     *
     *  相机曝光补偿值为 -1.0ev。
     */
    AUTELCameraExposureCompensationN10,
    /**
     *  @brief The camera's exposure compensation is -0.7ev.
     *
     *  相机曝光补偿值为 -0.7ev。
     */
    AUTELCameraExposureCompensationN07,
    /**
     *  @brief The camera's exposure compensation is -0.3ev.
     *
     *  相机曝光补偿值为 -0.3ev。
     */
    AUTELCameraExposureCompensationN03,
    /**
     *  @brief The camera's exposure compensation is 0.0ev.
     *
     *  相机曝光补偿值为 0.0ev。
     */
    AUTELCameraExposureCompensationN00,
    /**
     *  @brief The camera's exposure compensation is +0.3ev.
     *
     *  相机曝光补偿值为 +0.3ev。
     */
    AUTELCameraExposureCompensationP03,
    /**
     *  @brief The camera's exposure compensation is +0.7ev.
     *
     *  相机曝光补偿值为 +0.7ev。
     */
    AUTELCameraExposureCompensationP07,
    /**
     *  @brief The camera's exposure compensation is +1.0ev.
     *
     *  相机曝光补偿值为 +1.0ev。
     */
    AUTELCameraExposureCompensationP10,
    /**
     *  @brief The camera's exposure compensation is +1.3ev.
     *
     *  相机曝光补偿值为 +1.3ev。
     */
    AUTELCameraExposureCompensationP13,
    /**
     *  @brief The camera's exposure compensation is +1.7ev.
     *
     *  相机曝光补偿值为 +1.7ev。
     */
    AUTELCameraExposureCompensationP17,
    /**
     *  @brief The camera's exposure compensation is +2.0ev.
     *
     *  相机曝光补偿值为 +2.0ev。
     */
    AUTELCameraExposureCompensationP20,
    /**
     *  @brief The camera's exposure compensation is +2.3ev.
     *
     *  相机曝光补偿值为 +2.3ev。
     */
    AUTELCameraExposureCompensationP23,
    /**
     *  @brief The camera's exposure compensation is +2.7ev.
     *
     *  相机曝光补偿值为 +2.7ev。
     */
    AUTELCameraExposureCompensationP27,
    /**
     *  @brief The camera's exposure compensation is +3.0ev.
     *
     *  相机曝光补偿值为 +3.0ev。
     */
    AUTELCameraExposureCompensationP30,
    /**
     *  @brief The camera's exposure compensation is unknown.
     *
     *  相机曝光补偿值未知。
     */
    AUTELCameraExposureCompensationUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraAperture
//-----------------------------------------------------------------
/**
 *  Define aperture value (only for XT705).
 *
 *  定义光圈值，仅 XT705  相机支持
 *
 */
typedef NS_ENUM (uint8_t, AUTELCameraAperture) {
    /**
     *  @brief The camera's aperture is 1.8 ,float type.
     *
     *  相机光圈值为 1.8，浮点数。
     */
    AUTELCameraApertureF1p8 = 0,
    /**
     *  @brief The camera's aperture is 2.0 ,float type.
     *
     *  相机光圈值为 2.0，浮点数。
     */
    AUTELCameraApertureF2p0,
    /**
     *  @brief The camera's aperture is 2.2 ,float type.
     *
     *  相机光圈值为 2.2，浮点数。
     */
    AUTELCameraApertureF2p2,
    /**
     *  @brief The camera's aperture is 2.5 ,float type.
     *
     *  相机光圈值为 2.5，浮点数。
     */
    AUTELCameraApertureF2p5,
    /**
     *  @brief The camera's aperture is 2.8 ,float type.
     *
     *  相机光圈值为 2.8，浮点数。
     */
    AUTELCameraApertureF2p8,
    /**
     *  @brief The camera's aperture is 3.2 ,float type.
     *
     *  相机光圈值为 3.2，浮点数。
     */
    AUTELCameraApertureF3p2,
    /**
     *  @brief The camera's aperture is 3.5 ,float type.
     *
     *  相机光圈值为 3.5，浮点数。
     */
    AUTELCameraApertureF3p5,
    /**
     *  @brief The camera's aperture is 4.0 ,float type.
     *
     *  相机光圈值为 4.0，浮点数。
     */
    AUTELCameraApertureF4p0,
    /**
     *  @brief The camera's aperture is 4.5 ,float type.
     *
     *  相机光圈值为 4.5，浮点数。
     */
    AUTELCameraApertureF4p5,
    /**
     *  @brief The camera's aperture is 5.0 ,float type.
     *
     *  相机光圈值为 5.0，浮点数。
     */
    AUTELCameraApertureF5p0,
    /**
     *  @brief The camera's aperture is 5.6 ,float type.
     *
     *  相机光圈值为 5.6，浮点数。
     */
    AUTELCameraApertureF5p6,
    /**
      *  @brief The camera's aperture is 6.3 ,float type.
      *
      *  相机光圈值为 6.3，浮点数。
      */
    AUTELCameraApertureF6p3,
    /**
     *  @brief The camera's aperture is 7.1 ,float type.
     *
     *  相机光圈值为 7.1，浮点数。
     */
    AUTELCameraApertureF7p1,
    /**
     *  @brief The camera's aperture is 8.0 ,float type.
     *
     *  相机光圈值为 8.0，浮点数。
     */
    AUTELCameraApertureF8p0,
    /**
     *  @brief The camera's aperture is 9.0 ,float type.
     *
     *  相机光圈值为 9.0，浮点数。
     */
    AUTELCameraApertureF9p0,
    /**
     *  @brief The camera's aperture is 10.0 ,float type.
     *
     *  相机光圈值为 10.0，浮点数。
     */
    AUTELCameraApertureF10,
    /**
     *  @brief The camera's aperture is 11.0 ,float type.
     *
     *  相机光圈值为 11.0，浮点数。
     */
    AUTELCameraApertureF11,
    /**
     *  @brief The camera's aperture is 1.8 ,float type.
     *
     *  相机光圈值为 1.8，浮点数。
     */
    AUTELCameraApertureUnknown = 0xFF   //Unknown
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraWhiteBalance
//-----------------------------------------------------------------
/**
 *  Define white balance.
 *  
 *  定义白平衡
 */
typedef NS_ENUM (uint8_t, AUTELCameraWhiteBalance) {
    /**
     *  @brief Auto
     *  
     *  自动
     */
    AUTELCameraWhiteBalanceAuto = 0,
    
    /**
     *  @brief Sunny
     *
     *  日光
     */
    AUTELCameraWhiteBalanceSunny,
    
    /**
     *  @brief Cloudy
     *  
     *  阴天
     */
    AUTELCameraWhiteBalanceCloudy,
    
    /**
     *  @brief Incandescent
     *
     *  白炽灯
     */
    AUTELCameraWhiteBalanceIncandescent,
    
    /**
     *  @brief Neon
     *
     *  荧光灯
     */
    AUTELCameraWhiteBalanceFluorescent,
    
    /**
     *  @brief Custom
     *
     *  自定义
     */
    AUTELCameraWhiteBalanceCustom,
    
    /**
     *  @brief White balance status unknown
     *
     *  未知类型
     */
    AUTELCameraWhiteBalanceUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraPhotoAspectRatio
//-----------------------------------------------------------------
/**
 *  Define the aspect ratio of images.
 *
 *
 *  定义拍照图片比例
 */
typedef NS_ENUM (uint8_t, AUTELCameraPhotoAspectRatio) {
    /**
     *  @brief 相机图片比例为3:2，分辨率为5376x3584
     *
     *  The image ratio is 3:2, and the resolution is 5376x3584.
     */
    AUTELCameraPhotoAspectRatio3_2 = 0,
    
    /**
     *  @brief 相机图片比例为4:3，分辨率为4864x3648
     *  
     *  The image ratio is 4:3, and the resolution is 4864x3648.
     */
    AUTELCameraPhotoAspectRatio4_3,
    
    /**
     *  @brief 相机图片比例为16:9，分辨率为5376x3024
     *
     *  The image ratio is 16:9, and the resolution is 5376x3024.
     */
    AUTELCameraPhotoAspectRatio16_9,
    
    /**
     *  @brief 相机图片比例为4:3，分辨率为640x512
     *
     *  The image ratio is 5:4, and the resolution is 640x512.
     */
    AUTELCameraPhotoAspectRatio640_512,
    
    /**
     *  @brief 相机图片比例为4:3，分辨率为4000x3000
     *
     *  The image ratio is 4:3, and the resolution is 4000x3000.
     */
    AUTELCameraPhotoAspectRatio4000_3000,
    
    /**
     *  @brief 相机图片比例为16:9，分辨率为4000x2250
     *
     *  The image ratio is 16:9, and the resolution is 4000x2250.
     */
    AUTELCameraPhotoAspectRatio4000_2250,

    /**
     *  @brief 相机图片比例为16:9，分辨率为1280x720
     *
     *  The image ratio is 16:9, and the resolution is 1280x720.
     */
    AUTELCameraPhotoAspectRatio1280_720,

    /**
     *  @brief 相机图片比例为16:9，分辨率为1920x1080
     *
     *  The image ratio is 16:9, and the resolution is 1920x1080.
     */
    AUTELCameraPhotoAspectRatio1920_1080,
    
    /**
     *  @brief 相机图片比例为16:9，分辨率为2720x1528
     *
     *  The image ratio is 16:9, and the resolution is 2720x1528.
     */
    AUTELCameraPhotoAspectRatio2720_1528,
    
    /**
     *  @brief 相机图片比例为16:9，分辨率为3840x2160
     *
     *  The image ratio is 16:9, and the resolution is 3840x2160.
     */
    AUTELCameraPhotoAspectRatio3840_2160,
    
    /**
     *  @brief 相机图片比例为4:3，分辨率为4096x3072
     *
     *  The image ratio is 4:3, and the resolution is 4096x3072.
     */
    AUTELCameraPhotoAspectRatio4096_3072,

    /**
     *  @brief 相机图片比例为16:9，分辨率为5472x3076
     *
     *  The image ratio is 16:9, and the resolution is 5472x3076.
     */
    AUTELCameraPhotoAspectRatio5472_3076,

    /**
     *  @brief 相机图片比例为4:3，分辨率为5472x3648
     *
     *  The image ratio is 4:3, and the resolution is 5472x3648.
     */
    AUTELCameraPhotoAspectRatio5472_3648,
    
    /**
     *  @brief 相机图片比例为16:9，分辨率为5760x3240
     *
     *  The image ratio is 16:9, and the resolution is 5760x3240.
     */
    AUTELCameraPhotoAspectRatio5760_3240,
    
    /**
     *  @brief 相机图片比例为16:9，分辨率为7680x4320
     *
     *  The image ratio is 16:9, and the resolution is 7680x4320.
     */
    AUTELCameraPhotoAspectRatio7680_4320,
    
    /**
     *  @brief 相机图片比例为4:3，分辨率为8000x6000
     *
     *  The image ratio is 4:3, and the resolution is 8000x6000.
     */
    AUTELCameraPhotoAspectRatio8000_6000,
    
    /**
     *  @brief 相机图片比例为4:3，分辨率为8192x6144
     *
     *  The image ratio is 4:3, and the resolution is 8192x6144.
     */
    AUTELCameraPhotoAspectRatio8192_6144,
    
    /**
     *  @brief 相机图片比例未知
     *  
     *  The image ratio and resolution are unknown.
     */
    AUTELCameraPhotoAspectRatioUnknown = 0xFF
};


//-----------------------------------------------------------------
#pragma mark - AUTELCameraPhotoFileFormat
//-----------------------------------------------------------------
/**
 *  Sets the camera’s photo file format. See AUTELCameraPhotoFileFormat to view all possible photo formats to which the camera can be set
 *
 *  设置相机图片格式
 *
 */
typedef NS_ENUM (uint8_t, AUTELCameraPhotoFileFormat) {
    /**
     *  @brief 相机图片格式为 JPG
     */
    AUTELCameraPhotoFileFormatJPG = 0,
    
    /**
     *  @brief 相机图片格式为 DNG
     */
    AUTELCameraPhotoFileFormatDNG,
    
    /**
     *  @brief 相机图片格式为 JPG和DNG
     */
    AUTELCameraPhotoFileFormatJPGAndDNG,
    
    /**
     *  @brief 相机图片格式为 RJPEG
     */
    AUTELCameraPhotoFileFormatRJPEG,
    
    /**
     *  @brief 相机图片格式为 RJPEG+TIFF
     */
    AUTELCameraPhotoFileFormatRJPEGAndTIFF,
    
    /**
     *  @brief 相机图片格式未知
     */
    AUTELCameraPhotoFileFormatUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraPhotoBurstCount
//-----------------------------------------------------------------
/**
 *  Sets the burst shoot count for the camera when the user wants to use that feature. See AUTELCameraPhotoBurstCount to view all possible burst count values to which the camera can be set.
 *
 *  设置快速拍照张数
 */
typedef NS_ENUM (uint8_t, AUTELCameraPhotoBurstCount) {
    /**
     *  @brief The burst count is 3 captures.
     *  
     *  快拍照片张数为 3 张
     */
    AUTELCameraPhotoBurstCount3 = 0,
    /**
     *  @brief The burst count is 5 captures.
     *
     *  快拍照片张数为 5 张
     */
    AUTELCameraPhotoBurstCount5,
    /**
     *  @brief The burst count is 7 captures.
     *
     *  快拍照片张数为 7 张
     */
    AUTELCameraPhotoBurstCount7,
    /**
     *  @brief The burst count is 10 captures.
     *
     *  快拍照片张数为 10 张
     */
    AUTELCameraPhotoBurstCount10,
    /**
     *  @brief The burst count is 14 captures.
     *
     *  快拍照片张数为 14 张
     */
    AUTELCameraPhotoBurstCount14,
    /**
     *  @brief The burst count is unknown.
     *
     *  快拍照片张数未知
     */
    AUTELCameraPhotoBurstCountUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraPhotoAEBParam
//-----------------------------------------------------------------
/**
 *  Define AEB capture parameters
 *
 *  定义 AEB 拍照张数
 *
 */
typedef NS_ENUM (uint8_t, AUTELCameraPhotoAEBCaptureCount) {
    /**
     *  @brief The AEB capture count is 3 captures.
     *
     *  AEB 拍照张数为 3 张
     */
    AUTELCameraPhotoAEBCaptureCount3 = 0,
    /**
     *  @brief The AEB capture count is 5 captures.
     *
     *  AEB 拍照张数为 5 张
     */
    AUTELCameraPhotoAEBCaptureCount5,
    /**
     *  @brief The AEB capture count is unknown.
     *
     *  AEB 拍照张数未知
     */
    AUTELCameraPhotoAEBCaptureCountUnknown = 0xFF
};


//-----------------------------------------------------------------
#pragma mark - AUTELCameraPhotoTimeLapseInterval
//-----------------------------------------------------------------
/**
 *  Define interval of time lapse shooting
 *
 *  设置定时拍摄的间隔时间
 *
 */
typedef NS_ENUM (uint8_t, AUTELCameraPhotoTimeLapseInterval) {
    /**
     *  @brief The interval is 2 s.
     *
     *  间隔时间为 2 秒
     */
    AUTELCameraPhotoTimeLapseInterval2 = 2,
    
    /**
     *  @brief The interval is 3 s.
     *
     *  间隔时间为 3 秒
     */
    AUTELCameraPhotoTimeLapseInterval3 = 3,
    
    /**
     *  @brief The interval is 5 s.
     *
     *  间隔时间为 5 秒
     */
    AUTELCameraPhotoTimeLapseInterval5 = 5,
    
    /**
     *  @brief The interval is 7 s.
     *
     *  间隔时间为 7 秒
     */
    AUTELCameraPhotoTimeLapseInterval7 = 7,
    
    /**
     *  @brief The interval is 10 s.
     *
     *  间隔时间为 10 秒
     */
    AUTELCameraPhotoTimeLapseInterval10 = 10,
    
    /**
     *  @brief The interval is 20 s.
     *
     *  间隔时间为 20 秒
     */
    AUTELCameraPhotoTimeLapseInterval20 = 20,
    
    /**
     *  @brief The interval is 30 s.
     *
     *  间隔时间为 30 秒
     */
    AUTELCameraPhotoTimeLapseInterval30 = 30,
    
    /**
     *  @brief The interval is 60 s.
     *
     *  间隔时间为 60 秒
     */
    AUTELCameraPhotoTimeLapseInterval60 = 60,
    
    /**
     *  @brief The interval is unknown.
     *
     *  间隔时间未知
     */
    AUTELCameraPhotoTimeLapseIntervalUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraAntiFlicker
//-----------------------------------------------------------------
/**
 *  Define anti-flicker
 *
 *  定义抗闪烁模式
 */
typedef NS_ENUM (uint8_t, AUTELCameraAntiFlicker) {
    /**
     *  @brief Auto mode
     *
     *  自动模式
     */
    AUTELCameraAntiFlickerAuto = 0,
    
    /**
     *  60Hz
     */
    AUTELCameraAntiFlicker60Hz,
    
    /**
     *  50Hz
     */
    AUTELCameraAntiFlicker50Hz,
    
    /**
     *  Close
     */
    AUTELCameraAntiFlickerClose,
    
    /**
     *  @brief Unknown mode
     *
     *  未知模式
     */
    AUTELCameraAntiFlickerUnknown = 0xFF
};


//-----------------------------------------------------------------
#pragma mark - AUTELCameraDigitalFilter
//-----------------------------------------------------------------
/**
 *  Define digital filter (photo color)
 *
 *  数码滤波风格（图像颜色）
 *
 */
typedef NS_ENUM (uint8_t, AUTELCameraDigitalFilter) {
    /**
     *  @brief None
     *
     *  原图，不添加任何效果
     */
    AUTELCameraDigitalFilterNone = 0,
    
    /**
     *  @brief Log
     *
     *  原木风格
     */
    AUTELCameraDigitalFilterLog,
    
    /**
     *  @brief Vivid
     *
     *  鲜艳风格
     */
    AUTELCameraDigitalFilterVivid,
    
    /**
     *  @brief Black and white
     *
     *  黑白风格
     */
    AUTELCameraDigitalFilterBlackAndWhite,
    
    /**
     *  @brief Art
     *
     *  艺术风格
     */
    AUTELCameraDigitalFilterArt,
    
    /**
     *  @brief Film
     *
     *  电影风格
     */
    AUTELCameraDigitalFilterFilm,
    
    /**
     *  @brief Beach
     *
     *  沙滩风格
     */
    AUTELCameraDigitalFilterBeach,
    
    /**
     *  @brief Dream
     *
     *  梦幻风格
     */
    AUTELCameraDigitalFilterDream,
    
    /**
     *  @brief Classic
     *
     *  古典风格
     */
    AUTELCameraDigitalFilterClassic,
    
    /**
     *  @brief Nostalgic
     *
     *  怀旧风格
     */
    AUTELCameraDigitalFilterNostalgic,
    
    /**
     *  @brief Unknown
     *
     *  未知风格
     */
    AUTELCameraDigitalFilterUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraPhotoStyle
//-----------------------------------------------------------------
/**
 *  Define photo style
 *
 *  定义图片风格
 */
typedef NS_ENUM (uint8_t, AUTELCameraPhotoStyle) {
    /**
     *  @brief Standard
     *
     *  标准
     */
    AUTELCameraPhotoStyleStandard = 0,
    
    /**
     *  @brief LandScape
     *
     *  风景
     */
    AUTELCameraPhotoStyleLandScape,
    
    /**
     *  @brief Soft
     *
     *  柔和
     */
    AUTELCameraPhotoStyleSoft,
    
    /**
     *  @brief Custom
     *
     *  自定义
     */
    AUTELCameraPhotoStyleCustom,
    
    /**
     *  @brief Unknown
     *
     *  未知
     */
    AUTELCameraPhotoStyleUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraLensFocusMode
//-----------------------------------------------------------------
/**
 *  Define lens focus mode
 *
 *  定义对焦模式
 */
typedef NS_ENUM (uint8_t, AUTELCameraLensFocusMode) {
    /**
     *  @brief Auto focus mode
     *
     *  自动对焦模式
     */
    AUTELCameraLensFocusModeAuto = 0,
    
    /**
     *  @brief AF_C mode
     *
     *  AF_C
     */
    AUTELCameraLensFocusModeAFC,
    
    /**
     *  @brief Manual focus mode
     *
     *  手动对焦模式
     */
    AUTELCameraLensFocusModeManual,
    
    /**
     *  @brief Unknown focus mode
     *
     *  未知模式
     */
    AUTELCameraLensFocusModeUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraAFLensFocusMode
//-----------------------------------------------------------------
/**
 *  Define auto lens focus Mode
 *
 *
 *  自动对焦类型
 */
typedef NS_ENUM (uint8_t, AUTELCameraAFLensFocusMode) {
    /**
     *  @brief Average focus mode
     *
     *  平均对焦
     */
    AUTELCameraAFLensFocusModeAverage = 0,
    
    /**
     *  @brief Center focus mode
     *
     *  中心对焦
     */
    AUTELCameraAFLensFocusModeCenter,
    
    /**
     *  @brief Spot focus mode
     *
     *  点对焦
     */
    AUTELCameraAFLensFocusModeSpot,
    
    /**
     *  @brief Unknown focus mode
     *
     *  未知类型
     */
    AUTELCameraAFLensFocusModeUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraAFLensFocusState
//-----------------------------------------------------------------
/**
 *  Define auto lens focus state
 *
 *  定义自动对焦状态
 */
typedef NS_ENUM (uint8_t, AUTELCameraAFLensFocusState) {
    /**
     *  @brief Clear State
     *
     *  清晰状态
     */
    AUTELCameraAFLensFocusStateClear = 0,
    
    /**
     *  @brief Fuzzy state
     *
     *  模糊状态
     */
    AUTELCameraAFLensFocusStateFuzzy,
    
    /**
     *  @brief Unknown state
     *
     *  未知状态
     */
    AUTELCameraAFLensFocusStateUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraRecoverState
//-----------------------------------------------------------------
/**
 *  Define record recover state
 *
 *  定义录像恢复状态
 */
typedef NS_ENUM (uint8_t, AUTELCameraRecordRecoverState) {
    /**
     *  @brief Start to recover the video
     *
     *  录像恢复开始
     */
    AUTELCameraRecordRecoverStateBegin = 0,
    
    /**
     *  @brief  Video recovering finished
     *
     *  录像恢复完成
     */
    AUTELCameraRecordRecoverStateComplete,
    
    /**
     *  @brief Video recovering state unknown
     *
     *  未知状态
     */
    AUTELCameraRecordRecoverStateUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraInfraredRadiationColorPalette
//-----------------------------------------------------------------
/**
 *  定义红外成像的色表
 */
typedef NS_ENUM(uint8_t, AUTELCameraThermalPalette) {
    AUTELCameraThermalPaletteHotMetal = 0,
    
    AUTELCameraThermalPaletteWhiteHot,
    
    AUTELCameraThermalPaletteRainbow,
    
    AUTELCameraThermalPaletteUnknown = 0xFF,
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraThermalDisplayMode
//-----------------------------------------------------------------
/**
*  Define the thermal imaging display mode
*
*  定义热成像显示模式
*/
typedef NS_ENUM(uint8_t, AUTELCameraThermalDisplayMode) {
    /**
    *  @brief  Show visible light imaging
    *
    *  只显示可见光成像
    */
    AUTELCameraThermalDisplayModeVisible = 0,
    
    /**
    *  @brief  Show picture-in-picture
    *
    *  显示画中画
    */
    AUTELCameraThermalDisplayModePicturePicture,
    
    /**
    *  @brief   Show infrared thermal imaging video
    *
    *  只显示红外热成像视频
    */
    AUTELCameraThermalDisplayModeInfraredRadiation,
    
    /**
     *  @brief 显示融合
     */
    /**
    *  @brief  Show fusion
    *
    *  显示融合
    */
    AUTELCameraThermalDisplayModeOverlap,
    
    /**
    *  @brief  Unknown
    *
    *  未知
    */
    AUTELCameraThermalDisplayModeUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraThermalPIPPosition
//-----------------------------------------------------------------
/**
 *  定义热成像画中画位置
 */
typedef NS_ENUM(uint8_t, AUTELCameraThermalPIPPosition) {
    /**
     *  @brief 画中画在左上角
     */
    AUTELCameraThermalPIPPositionLeftUp = 0,
    
    /**
     *  @brief 画中画在顶部中间
     */
    AUTELCameraThermalPIPPositionMiddleUp,
    
    /**
     *  @brief 画中画在右上角
     */
    AUTELCameraThermalPIPPositionRightUp,
    
    /**
     *  @brief 画中画在左边中间
     */
    AUTELCameraThermalPIPPositionLeftMiddle,
    
    /**
     *  @brief 画中画在正中
     */
    AUTELCameraThermalPIPPositionCentral,
    
    /**
     *  @brief 画中画在右边中间
     */
    AUTELCameraThermalPIPPositionRightMiddle,

    /**
     *  @brief 画中画在左下角
     */
    AUTELCameraThermalPIPPositionLeftDown,
    
    /**
     *  @brief 画中画在底部中间
     */
    AUTELCameraThermalPIPPositionMiddleDown,
    
    /**
     *  @brief 画中画在右下角
     */
    AUTELCameraThermalPIPPositionRightDown,
    
    /**
     *  @brief 未知
     */
    AUTELCameraThermalPIPPositionUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraThermalLEDState
//-----------------------------------------------------------------
/**
 *  定义热成像相机LED状态
 */
typedef NS_ENUM(uint8_t, AUTELCameraThermalLEDState) {
    /**
     *  @brief 关闭
     */
    AUTELCameraThermalLEDStateOff,
    
    /**
     *  @brief 打开
     */
    AUTELCameraThermalLEDStateOn,
    
    /**
     *  @brief 未知
     */
    AUTELCameraThermalLEDStateUnknown = 0xFF
};

#pragma mark - AUTELCameraThermalTemperatureUnit
//-----------------------------------------------------------------
/**
 *  定义热成像温度单位
 */
typedef NS_ENUM(uint8_t, AUTELCameraThermalTemperatureUnit) {
    /**
     *  @brief 摄氏度
     */
    AUTELCameraThermalTemperatureUnitCelcius = 0,
    
    /**
     *  @brief 华氏度
     */
    AUTELCameraThermalTemperatureUnitFahrenheit,
    
    /**
     *  @brief 未知
     */
    AUTELCameraThermalTemperatureUnitUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraThermalSkyCondition
//-----------------------------------------------------------------
/**
 *  定义热成像温度单位
 */
typedef NS_ENUM(uint8_t, AUTELCameraThermalSkyCondition) {
    /**
     *  @brief 清澈
     */
    AUTELCameraThermalSkyConditionClear = 0,
    
    /**
     *  @brief 疏云
     */
    AUTELCameraThermalSkyConditionScattered,
    
    /**
     *  @brief 多云
     */
    AUTELCameraThermalSkyConditionCloudy,
    
    /**
     *  @brief 未知
     */
    AUTELCameraThermalSkyConditionUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraPictureInVideoInterval
//-----------------------------------------------------------------
/**
 *  picture in video 自动模式下时间间隔
 */
typedef NS_ENUM(uint8_t, AUTELCameraPictureInVideoInterval) {
    /**
     *  @brief 5s
     */
    AUTELCameraPictureInVideoInterval5s = 0,
    
    /**
     *  @brief 10s
     */
    AUTELCameraPictureInVideoInterval10s,
    
    /**
     *  @brief 30s
     */
    AUTELCameraPictureInVideoInterval30s,
    
    /**
     *  @brief 60s
     */
    AUTELCameraPictureInVideoInterval60s,
    
    /**
     *  @brief 未知
     */
    AUTELCameraPictureInVideoIntervalUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraPictureInVideoStatus
//-----------------------------------------------------------------
/**
 *  picture in video 状态
 */
typedef NS_ENUM(uint8_t, AUTELCameraPictureInVideoStatus) {
    
    /**
     *  @brief 空闲
     */
    AUTELCameraPictureInVideoStatusIdle = 0,
    
    /**
     *  @brief 拍照
     */
    AUTELCameraPictureInVideoStatusPhotoTaking,
    
    /**
     *  @brief 未知
     */
    AUTELCameraPictureInVideoStatusUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraStorageType
//-----------------------------------------------------------------
/**
 *  Define storage type
 *
 *  存储设备类型
 */
typedef NS_ENUM (uint8_t, AUTELCameraStorageType) {
    /**
     *  @brief SDCard
     *
     *  SDCard
     */
    AUTELCameraStorageTypeSDCard = 0,
    
    /**
     *  @brief EMMC
     *
     *  闪存
     */
    AUTELCameraStorageTypeEMMC,
    
    /**
     *  @brief Unknown
     *
     *  未知
     */
    AUTELCameraStorageTypeUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraIrColorType
//-----------------------------------------------------------------
/**
 *  Define Ir False color type
 *
 *  伪彩类型
 */
typedef NS_ENUM (uint8_t, AUTELCameraIrColorType) {
    /**
     *  @brief WhiteHot
     *
     *  白热
     */
    AUTELCameraIrColorTypeWhiteHot = 0,
    
    /**
     *  @brief BlackHot
     *
     *  冷热
     */
    AUTELCameraIrColorTypeBlackHot,
    
    /**
     *  @brief RainBow
     *
     *  彩虹
     */
    AUTELCameraIrColorTypeRainBow,
    
    /**
     *  @brief RainHC
     *
     * 增强彩虹
     */
    AUTELCameraIrColorTypeRainHC,
    
    /**
     *  @brief IronBow
     *
     *  铁红
     */
    AUTELCameraIrColorTypeIronBow,
    
    /**
     *  @brief Lava
     *
     *  熔岩
     */
    AUTELCameraIrColorTypeLava,
    
    /**
     *  @brief Arctic
     *
     *  极光
     */
    AUTELCameraIrColorTypeArctic,
    
    /**
     *  @brief GlowBow
     *
     *  灼热
     */
    AUTELCameraIrColorTypeGlowBow,
    
    /**
     *  @brief GradedFire
     *
     *  渐变
     */
    AUTELCameraIrColorTypeGradedFire,
    
    /**
     *  @brief HotTest
     *
     *  热探测
     */
    AUTELCameraIrColorTypeHotTest,
    
    /**
     *  @brief DoubleRainBow
     *
     *  双彩虹
     */
    AUTELCameraIrColorTypeDoubleRainBow,
    
    /**
     *  @brief ColorWheel
     *
     *  色环
     */
    AUTELCameraIrColorTypeColorWheel,
    
    /**
     *  @brief Unknown
     *
     *  未知
     */
    AUTELCameraIrColorTypeUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraHDRSetting
//-----------------------------------------------------------------
/**
 *  Define hdr setting
 *
 *  存储设备类型
 */
typedef NS_ENUM (uint8_t, AUTELCameraHDRSetting) {
    /**
     *  @brief Enable
     *
     *  打开
     */
    AUTELCameraHDRSettingDisable = 0,
    
    /**
     *  @brief Disable
     *
     *  打开
     */
    AUTELCameraHDRSettingEnable,
    
    /**
     *  @brief Unknown
     *
     *  未知
     */
    AUTELCameraHDRSettingUnknown = 0xFF
};

//-----------------------------------------------------------------
#pragma mark - AUTELCameraCommonSetting
//-----------------------------------------------------------------
/**
 *  Define hdr setting
 *
 *  相机通用开关设置
 */
typedef NS_ENUM (uint8_t, AUTELCameraSwitchStatus) {
    /**
     *  @brief Enable
     *
     *  关闭
     */
    AUTELCameraSwitchStatusDisable = 0,
    
    /**
     *  @brief Disable
     *
     *  打开
     */
    AUTELCameraSwitchStatusEnable,
    
    /**
     *  @brief Unknown
     *
     *  未知
     */
    AUTELCameraSwitchStatusUnknown = 0xFF
};

/**
 *  @brief  Camera Pattern
 *
 *  更新相机界面模式
 */
typedef NS_ENUM(uint8_t, AUTELMisstionCameraPattern) {
    /**
     *  @brief manual fly
     *
     *  手动飞行
     */
    AUTELMisstionCameraPatternManualFly = 0,
    /**
     *  @brief mission fly
     *
     *  任务飞向
     */
    AUTELMisstionCameraPatternMisstionFly = 1,
    /**
     *  @brief tracking mode
     *
     *  智能跟踪、手势识别、指点飞行
     */
    AUTELMisstionCameraPatternTrack = 2,
    /**
     *  @brief delay take photo
     *
     *  延时摄影
     */
    AUTELMisstionCameraPatternDelayPhoto = 3,
    
    /**
     *  @brief delay take photo
     *
     *  视觉环绕
     */
    AUTELMisstionCameraPatternVisionOrbit = 4,
    
    /**
     *  @brief Panoramic photo
     *
     *  全景拍照
     */
    AUTELMisstionCameraPatternPanoramicPhoto = 5,
    
    /**
     *  @brief Mission record
     *
     *  任务录制
     */
    AUTELMisstionCameraPatternMissionRecord = 6,
};

/**
 *  @brief  Smart photography operation：Camera time-lapse photography misstion operation and Panoramic photo misstion operation
 *
 *  智能拍摄操作，包括延时摄影任务和全景摄影任务操作
 */
typedef NS_ENUM(uint8_t, AUTELCameraSmartPhotoOperation) {
    /**
     *  @brief start time-lapse photography  mission
     *
     *  开始延时摄影
     */
    AUTELCameraSmartPhotoOperationStart = 0,
    /**
     *  @brief pause time-lapse photography  mission
     *
     *  暂停延时摄影
     */
    AUTELCameraSmartPhotoOperationPause = 1,
    /**
     *  @brief resume time-lapse photography mission
     *
     *  恢复延时摄影
     */
    AUTELCameraSmartPhotoOperationResume = 2,
    /**
     *  @brief stop time-lapse photography mission
     *
     *  停止延时摄影
     */
    AUTELCameraSmartPhotoOperationStop = 3,
    
    /**
     *  @brief start Panoramic photo  mission
     *
     *  开始全景摄影
     */
    AUTELCameraPanoramicPhotoOperationStart = 10,
    /**
    *  @brief stop Panoramic photo mission
    *
    *  停止全景摄影
    */
   AUTELCameraPanoramicPhotoOperationStop = 11,

};

/**
 *  @brief  Camera motion delay shot misstion pperation promptTone
 *
 *  触发提示音
 */
typedef NS_ENUM(uint8_t, AUTELCameraDelayShotPromptTone) {
    /**
     *  @brief no promptTone
     *
     *  不触发提示音
     */
    AUTELCameraDelayShotPromptToneNo = 0,
    /**
     *  @brief promptTone
     *
     *  触发提示音
     */
    AUTELCameraDelayShotPromptToneYes = 1,

};

/**
 *  @brief  Camera motion delay shot misstion pperation promptTone
 *
 *  移动延时摄影保存原片格式
 */
typedef NS_ENUM(uint8_t, AUTELCameraDelayShotPhotoFormat) {
    /**
     *  @brief None
     *
     *  None
     */
    AUTELCameraDelayShotPhotoFormatNone = 0,
    /**
     *  @brief JPG
     *
     *  JPG
     */
    AUTELCameraDelayShotPhotoFormatJPG = 1,
    /**
     *  @brief DNG
     *
     *  DNG
     */
    AUTELCameraDelayShotPhotoFormatDNG = 2,

};

/**
 *  @brief  Camera Gimbal Lock State
 *
 *  云台锁定状态
 */
typedef NS_ENUM(uint8_t, AUTELCameraGimbalLockState) {
    /**
     *  @brief unlock
     *
     *  未锁定
     */
    AUTELCameraGimbalLockStateUnLock = 0,
    /**
     *  @brief lock
     *
     *  锁定
     */
    AUTELCameraGimbalLockStateLock = 1,
    
    
    AUTELCameraGimbalLockStateNone = 0xff

};


/**
 *  @brief  Camera warnning type
 *
 *  相机警告类型
 */
typedef NS_ENUM(uint8_t, AUTELCameraWarnningType) {
    /**
     *  @brief over exposed
     *
     *  过曝
     */
    AUTELCameraWarnningTypeOverexposed = 0,
    /**
     *  @brief under exposed
     *
     *  欠曝
     */
    AUTELCameraWarnningTypeUnderexposed = 1,
    /**
    *  @brief no warnning
    *
    *  没有警告
    */
    AUTELCameraWarnningTypeNone = 0xff

};

/**
 *  @brief  Thermal imaging gain type
 *
 *  热成像增益类型
 */
typedef NS_ENUM(uint8_t, AUTELCameraIrGainType) {
    /**
     *  @brief High gain
     *
     *  高增益
     */
    AUTELCameraIrGainTypeHigh = 0,
    /**
     *  @brief Low gain
     *
     *  低增益
     */
    AUTELCameraIrGainTypeLow = 1,
    /**
    *  @brief automatic
    *
    *  自动
    */
    AUTELCameraIrGainTypeAuto = 2,
    /**
    *  @brief Unknow
    *
    *  未知
    */
    AUTELCameraIrGainTypeUnknow = 0xff

};

/**
 *  @brief  Thermal imaging mode
 *
 *  热成像图像模式
 */
typedef NS_ENUM(uint8_t, AUTELCameraIrImageMode) {
    /**
     *  @brief High gain
     *
     *  手动（手动调节对比度和亮度）
     */
    AUTELCameraIrImageModeManual = 0,
    /**
     *  @brief automatic 0
     *
     *  自动0
     */
    AUTELCameraIrImageModeAuto0 = 1,
    /**
    *  @brief automatic 1
    *
    *  自动1
    */
    AUTELCameraIrImageModeAuto1 = 2,
    /**
    *  @brief Unknow
    *
    *  未知
    */
    AUTELCameraIrImageModeUnknow = 0xff

};

/**
 *  @brief  Thermal imaging Warm line mode
 *
 *  热成像等温线模式
 */
typedef NS_ENUM(uint8_t, AUTELCameraIrIsoThermMode) {
    /**
     *  @brief Close
     *
     *  关闭
     */
    AUTELCameraIrIsoThermModeClose = 0,
    /**
     *  @brief search people
     *
     *  搜人
     */
    AUTELCameraIrIsoThermModePeople = 1,
    /**
    *  @brief search fire
    *
    *  搜火
    */
    AUTELCameraIrIsoThermModeFire = 2,
    /**
    *  @brief customize
    *
    *  自定义
    */
    AUTELCameraIrIsoThermModeCustomize = 3,
    /**
    *  @brief Unknow
    *
    *  未知
    */
    AUTELCameraIrIsoThermModeUnknow = 0xff

};



/**
*  @brief  Camera WorkStatus
*
*  系统工作状态
*/
typedef enum : NSUInteger {
    /**
    *  @brief Unknown
    *
    *  未知
    */
    AUTELCameraWorkStatusUnknown,
    /**
    *  @brief Idel
    *
    *  未进行工作
    */
    AUTELCameraWorkStatusIdel,
     /**
       *  @brief Recording
       *
       *  录制中
       */
    AUTELCameraWorkStatusRecording,
    /**
    *  @brief TakingPhoto
    *
    *  拍摄中
    */
    AUTELCameraWorkStatusTakingPhoto,
    /**
    *  @brief Detach
    *
    *  分离
    */
    AUTELCameraWorkStatusDetach,
} AUTELCameraWorkStatus;


/**
 *  @brief  Camera Gimbal Lock State
 *
 *  云台锁定状态
 */
typedef NS_ENUM(uint8_t, AUTELCameraVideoTransmissionMode) {
    /**
     *  @brief horizontal screen
     *
     *  横屏
     */
    AUTELCameraVideoTransmissionModeHorizontal = 0,
    /**
     *  @brief vertical screen
     *
     *  竖屏
     */
    AUTELCameraVideoTransmissionModeVertical = 1,
    

};

/**
*  @brief  AF working status
*
*  AF对焦工作状态
*/
typedef enum : NSUInteger {
    /**
    *  @brief Unknown
    *
    *  开始对焦
    */
    AUTELCameraAFWorkStatusBegin = 0,
    /**
    *  @brief Idel
    *
    *  正在对焦
    */
    AUTELCameraAFWorkStatusFocusing = 1,
     /**
       *  @brief Recording
       *
       *  对焦完成
       */
    AUTELCameraAFWorkStatusFinish = 2,
    /**
    *  @brief TakingPhoto
    *
    *  回中
    */
    AUTELCameraAFWorkStatusCenter = 10,
    
} AUTELCameraAFWorkStatus;


///接口类型
typedef NS_ENUM (uint8_t, AUTELCameraCommonAPISetType) {
    ///
    AUTELCameraCommonAPISetTypeNone = 0,
    AUTELCameraCommonAPISetTypeGPSMapDatum = 1,
    AUTELCameraCommonAPISetTypeMisstionFlyImageFormat = 2,
    AUTELCameraCommonAPISetTypeMisstionFlyImageMode = 3,

}; 


#endif /* AUTELCameraDef_h */
