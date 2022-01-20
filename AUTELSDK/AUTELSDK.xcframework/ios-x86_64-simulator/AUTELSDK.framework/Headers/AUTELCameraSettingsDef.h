//
//  AUTELCameraSettinsDef.h
//  AUTELSDK
//
//  Created by Autel on 15/10/22.
//  Copyright © 2015年 Autel. All rights reserved.
//

#ifndef AUTELCameraSettingsDef_h
#define AUTELCameraSettingsDef_h

#import <Foundation/Foundation.h>
/**
 *  Camera capture mode
 */
typedef NS_ENUM(uint8_t, CameraCaptureMode){
    /**
     *  Single capture
     */
    CameraSingleCapture,
    /**
     *  Multiple capture
     */
    CameraMultiCapture,
    /**
     *  Continuous capture
     */
    CameraContinousCapture,
    /**
     *  BURST capture. Support in Inspire/Phantom3 professional
     */
    CameraBURSTCapture = CameraContinousCapture,
    /**
     *  AEB capture. Support in Inspire/Phantom3 professional
     */
    CameraAEBCapture,
};

/**
 *  Video quality
 */
typedef NS_ENUM(uint8_t, VideoQuality){
    /**
     *  Normal, Used in Inspire/Phantom3 professional
     */
    CameraVideoQualityNormal                = 0x00,
    /**
     *  Quality fine, Used in Inspire/Phantom3 professional
     */
    CameraVideoQualityFine                  = 0x01,
    /**
     *  Quality excellent, Used in Inspire/Phantom3 professional
     */
    CameraVideoQualityExcellent             = 0x02,
    /**
     *  Video resolution 320x240 15fps,  Used in Phantom 2 Vision
     */
    Video320x24015fps                       = 0x01,
    /**
     *  Video resolution 320x240 30fps,  Used in Phantom 2 Vision
     */
    Video320x24030fps                       = 0x02,
    /**
     *  Video resolution 640x480 15fps,  Used in Phantom 2 Vision
     */
    Video640x48015fps                       = 0x03,
    /**
     *  Video resolution 640x480 30fps,  Used in Phantom 2 Vision
     */
    Video640x48030fps                       = 0x04,
    /**
     *  Unknown
     */
    CameraVideoQualityUnknown               = 0xFF
};

/**
 *  The video storage format
 */
typedef NS_ENUM(uint8_t, CameraVideoStorageFormat){
    /**
     *  MOV storage format
     */
    CameraVideoStorageFormatMOV,
    /**
     *  MP4 storage format
     */
    CameraVideoStorageFormatMP4,
    /**
     *  Unknown
     */
    CameraVideoStorageFormatUnknown = 0xFF
};

/**
 *  Camera mode used in Phantom 2 Vision
 */
typedef NS_ENUM(uint8_t, CameraMode){
    /**
     *  Camera mode, Under this mode, user can do capture, record, set/get camera parameters and video preview.
     */
    CameraCameraMode                        = 0x00,
    /**
     *  USB mode. Under this mode, user can download media files from camera, but the video stream will stop push
     */
    CameraUSBMode                           = 0x01,
    /**
     *  Unknown
     */
    CameraModeUnknown                       = 0xFF
};
/**
 * Camera state
 */
typedef NS_ENUM(int, CameraWorkState)
{
    /** 
     * Unknown
     */
    CameraWorkStateUnknown                        = 0xFF,
    /**
     * idle
     */
    CameraWorkStateIdle                           = 0x00,
    /**
     * capture
     */
    CameraWorkStateCapture,
    /**
     * record
     */
    CameraWorkStateRecord
};

/**
 *  Camera work mode. Used in Inspire/Phantom3 professional
 */
typedef NS_ENUM(uint8_t, CameraWorkMode){
    /**
     *  Unknown
     */
    CameraWorkModeUnknown                          = 0xFF,
    /**
     *  Capture mode. In this mode, user could do capture action only.
     */
    CameraWorkModeCaptureSingal                    = 0x00,
    /**
     *  Record mode. In this mode, user could do record action only.
     */
    CameraWorkModeRecord                                 ,
    /**
     *  Burst mode. In this mode, user could capture burst.
     */
    CameraWorkModeCaptureBurst                           ,
    /**
     * TimeLapse mode. In this mode, user could capture timelapse.
     */
    CameraWorkModeCaptureTimeLapse                       ,
    /**
     *  AEB mode.
     */
    CameraWorkModeCaptureAeb                             ,
    /**
     * Panorama mode
     */
    CameraWorkModeCapturePanorama                        ,
    /**
     * slowmotionrec mode 慢动作录影
     */
    CameraWorkModeSlowmotionrec,
#pragma mark- 废弃
    /**
     * delayedrec mode 移动延时摄影
     */
    CameraWorkModeDelayedrec,
#pragma mark
    /**
     * 循环录影
     */
    CameraWorkModeLoopRecord,
    /**
     * 延时摄影
     */
    CameraWorkModeDelayShot,
    /**
     * 移动延时摄影
     */
    CameraWorkModeMotionDelayShot
};

/**
 *  Camera exposure mode
 */
typedef NS_ENUM(uint8_t, CameraExposureMode){
    /**
     *  Program
     */
    CameraExposureModeProgram                = 0x00,
    /**
     *  Shutter
     */
    CameraExposureModeShutter,
    /**
     *  Manual
     */
    CameraExposureModeManual,
    /**
     *  Unknown
     */
    CameraExposureModeUnknown               = 0xFF
};

/**
 *  Camera storage photo size
 */
typedef NS_ENUM(uint8_t, CameraPhotoSizeType){

    CameraPhotoSizeUnknown           = 0xFF,
    /**
     *  12M A7
     */
    CameraPhotoSize12M               = 0x00,
    /**
     *  8M A7
     */
    CameraPhotoSize8M                ,
    /**
     *  5M A7
     */
    CameraPhotoSize5M                ,
    /**
     * CameraPhotoSize4000X3000(4:3) A9
     */
    CameraPhotoSize4000X3000              ,
    /**
     * CameraPhotoSize4000X2250(16:9) A9
     */
    CameraPhotoSize4000X2250,
    /**
     * CameraPhotoSize5376X3584(3:2) Inch
     */
    CameraPhotoSize5376X3584,
    /**
     * CameraPhotoSize4864X3648(4:3) Inch
     */
    CameraPhotoSize4864X3648,
    /**
     * CameraPhotoSize5376X3024(16:9) Inch
     */
    CameraPhotoSize5376X3024,
};

/**
 *  Camera's photo ration = width / height
 */
typedef NS_ENUM(uint8_t, CameraPhotoRatioType){
    /**
     *  Photo 4 : 3
     */
    CameraPhotoRatio4_3      = 0x00,
    /**
     *  Photo 16 : 9
     */
    CameraPhotoRatio16_9,
    /**
     *  Unknown
     */
    CameraPhotoRatioUnknown = 0xFF
};

/**
 *  Photo quality
 */
typedef NS_ENUM(uint8_t, CameraPhotoQualityType){
    /**
     *  Photo quality normal
     */
    CameraPhotoQualityNormal   = 0x00,
    /**
     *  Photo quality fine
     */
    CameraPhotoQualityFine,
    /**
     *  Photo quality excellent
     */
    CameraPhotoQualityExcellent,
    /**
     *  Unknown
     */
    CameraPhotoQualityUnknown = 0xFF
};

/**
 *  Camera ISO
 */
typedef NS_ENUM(uint8_t, CameraISOType){
    /**
     *  ISO Auto
     */
    CameraISOAuto                           = 0x00,
    /**
     *  ISO 100
     */
    CameraISO100                            = 0x01,
    /**
     *  ISO 200
     */
    CameraISO200                            = 0x02,
    /**
     *  ISO 400
     */
    CameraISO400                            = 0x03,
    /**
     *  ISO 800
     */
    CameraISO800                            = 0x04,
    /**
     *  ISO 1600
     */
    CameraISO1600                           = 0x05,
    /**
     *  ISO 3200
     */
    CameraISO3200                           = 0x06,
    /**
     *  ISO 6400
     */
    CameraISO6400                           = 0x07,
    /**
     *  ISO 12800
     */
    CameraISO12800                           = 0x08,
    /**
     *  ISO 25600
     */
    CameraISO25600                           = 0x09,
    /**
     *  Unknown
     */
    CameraISOUnknown                        = 0xFF
};

/**
 *  Camera white balance
 */
typedef NS_ENUM(uint8_t, CameraWhiteBalanceType){
    /**
     *  White balance unknown
     */
    CameraWhiteBalanceUnknown               = 0xFF,
    /**
     *  White balance auto
     */
    CameraWhiteBalanceAuto                  = 0x00,
    /**
     *  White balance sunny
     */
    CameraWhiteBalanceSunny                       ,
    /**
     *  White balance cloudy
     */
    CameraWhiteBalanceCloudy                      ,
    /**
     * White balance incan
     */
    CameraWhiteBalanceIncan                       ,
    /**
     * White balance fulor
     */
    CameraWhiteBalanceFluor                       ,
    /**
     * White balance 3000K
     */
    CameraWhiteBalance3000K                       ,
    /**
     * White balance 5500K
     */
    CameraWhiteBalance5500K                       ,
    /**
     * White balance 6500K
     */
    CameraWhiteBalance6500K                       ,
    /**
     * White balance Custom // inch 支持
     */
    CameraWhiteBalanceCustom                      ,
   
};

/**
 *  Camera exposure metering
 */
typedef NS_ENUM(uint8_t, CameraExposureMeteringType){

    /**
     *  Unknown
     */
    CameraExposureMeteringUnknown           = 0xFF,
    /**
     *  Exposure metering center
     */
    CameraExposureMeteringCenter            = 0x00,
    /**
     *  Exposure metering average
     */
    CameraExposureMeteringAverage                 ,
    /**
     *  Exposure metering point
     */
    CameraExposureMeteringPoint
};
typedef NS_ENUM(uint8_t, CameraSystemType){
    
    /**
     *  Unknown
     */
    CameraSystemTypeUnknown           = 0xFF,
    /**
     * CameraSystemType_PAL
     */
    CameraSystemTypePAL               = 0x00,
    /**
     * CameraSystemType_NTSC
     */
    CameraSystemTypeNTSC
};


/**
 *  Camera recording resolution
 */
typedef NS_ENUM(uint8_t, CameraRecordingResolutionType){
 
    /**
     *  Resolution Unknown
     */
    CameraRecordingResolutionUnknown        = 0xFF ,
    /**
     *  Resolution 4096*2160p 25
     */
    CameraRecordingResolution4096x216025p   = 0 ,
    /**
     *  Resolution 4096*2160p24
     */
    CameraRecordingResolution4096x216024p     ,
    /**
     *  Resolution 3840*2160p30
     */
    CameraRecordingResolution3840x216030p    ,
    /**
     *  Resolution 3840*2160 25
     */
    CameraRecordingResolution3840x216025p    ,
    /**
     *  Resolution 3840*2160p24
     */
    CameraRecordingResolution3840x216024p    ,
    /**
     * Resolution  2704*1520 30
     */
    CameraRecordingResolution2704x152030p   = 5 ,
    /**
     * Resolution  2704*1520 25
     */
    CameraRecordingResolution2704x152025p    ,
    /**
     * Resolution  2704*1520 24
     */
    CameraRecordingResolution2704x152024p    ,
    /**
     * Resolution  1920*1080 120
     */
    CameraRecordingResolution1920x1080120p   ,
    /**
     *  Resolution 1920*1080p60
     */
    CameraRecordingResolution1920x108060p    ,
    /**
     * Resolution  1920*1080 50
     */
    CameraRecordingResolution1920x108050p   =10 ,
    /**
     *  Resolution 1920x1080p48
     */
    CameraRecordingResolution1920x108048p   ,
    /**
     *  Resolution 1920x1080 30p
     */
    CameraRecordingResolution1920x108030p   ,
    /**
     * Resolution  1920*1080 25
     */
    CameraRecordingResolution1920x108025p    ,
    /**
     *  Resolution 1920x1080 24p
     */
    CameraRecordingResolution1920x108024p   ,
    /**
     * Resolution  1280*720 240
     */
    CameraRecordingResolution1280x720240p   = 15 ,
    /**
     *  Resolution 1280*720p60
     */
    CameraRecordingResolution1280x72060p    ,
    /**
     * Resolution  1280*720 50
     */
    CameraRecordingResolution1280x72050p     ,
    /**
     *  Resolution 1280*720p48
     */
    CameraRecordingResolution1280x72048p    ,
    /**
     *  Resolution 1280*720p30
     */
    CameraRecordingResolution1280x72030p    ,
    /**
     * Resolution  1280*720 25
     */
    CameraRecordingResolution1280x72025p   = 20 ,
    /**
     *  Resolution 1280*720p24
     */
    CameraRecordingResolution1280x72024p    ,
    /**
     *  Resolution A7 1080P(16:9)
     */
    CameraRecordingResolutionA71080P        ,
    /**
     * Resolution A7 720P(16:9)
     */
    CameraRecordingResolutionA7720P,
    
    CameraRecordingResolution2704x152048p,
    CameraRecordingResolution2704x152050p   = 25 ,
    CameraRecordingResolution2704x152060p,
    /**
     * Resolution  1280*720 120
     */
    CameraRecordingResolution1280x720120p   

};

/**
 *  Camera's video resolution. Used in Inspire/Phantom3 professional camera
 */
typedef NS_ENUM(uint8_t, CameraVideoResolution){
    /**
     *  1280x720P
     */
    CameraVideoResolution1280x720p     = 0x00,
    /**
     *  1920x1080P
     */

    /**
     *  3840x2160P
     */
    CameraVideoResolution3840x2160p,
    /**
     *  4096x2160
     */
    CameraVideoResolution4096x2160p,
    /**
     *  Unknown
     */
    CameraVideoResolutionUnknown       = 0xFF,
};

/**
 *  Camera's video frame rate
 */
typedef NS_ENUM(uint8_t, CameraVideoFrameRate){
    /**
     *  24fps
     */
    CameraVideoFrameRate24fps      = 0x00,
    /**
     *  25fps
     */
    CameraVideoFrameRate25fps,
    /**
     *  30fps
     */
    CameraVideoFrameRate30fps,
    /**
     *  48fps
     */
    CameraVideoFrameRate48fps,
    /**
     *  50fps
     */
    CameraVideoFrameRate50fps,
    /**
     *  60fps
     */
    CameraVideoFrameRate60fps,
    /**
     *  100fps
     */
    CameraVideoFrameRate100fps,
    /**
     *  1200fps
     */
    CameraVideoFrameRate120fps,
    /**
     *  200fps
     */
    CameraVideoFrameRate200fps,
    /**
     *  240fps
     */
    CameraVideoFrameRate240fps,
    /**
     *  Unknonwn
     */
    CameraVideoFrameRateUnknown = 0xFF
};

/**
 *  Camera FOV
 */
typedef NS_ENUM(uint8_t, CameraRecordingFovType){
    /**
     *  Wide FOV
     */
    CameraRecordingFOV0                     = 0x00,
    /**
     *  Middle FOV, Only support in Phantom 2 Vision
     */
    CameraRecordingFOV1                     = 0x01,
    /**
     *  Narrow FOV, Only support in Phantom 2 Vision
     */
    CameraRecordingFOV2                     = 0x02,
    /**
     *  Unknown
     */
    CameraRecordingFOVUnknown               = 0xFF
};

/**
 *  Camera's photo storage format
 */
typedef NS_ENUM(uint8_t, CameraPhotoFormatType){
    /**
     *  Unknown
     */
    CameraPhotoFormatUnknown               = 0x00,
    /**
     *  JPG format
     */
    CameraPhotoJPG                         = 0x01,
    /**
     *  DNG format
     */
    CameraPhotoDNG                         = 0x02,
    /**
     * JPG and DNG
     */
    CameraPhotoJPGAndDNG
 };

/**
 *  Camera exposure compensation
 */
typedef NS_ENUM(uint8_t, CameraExposureCompensationType){

    /**
     *  Unknown
     */
    CameraExposureCompensationUnknown       = 0xFF,
    /**
     * CameraExposureCompensation -3.0
     */
    CameraExposureCompensationN30           = 0,
    /**
     * CameraExposureCompensation -2.7
     */
    CameraExposureCompensationN27                 ,
    /**
     * CameraExposureCompensation -2.3
     */
    CameraExposureCompensationN23                 ,
    /**
     * CameraExposureCompensation -2.0  A7,A9
     */
    CameraExposureCompensationN20                 ,
    /**
     * CameraExposureCompensation -1.7
     */
    CameraExposureCompensationN17                 ,
    /**
     * CameraExposureCompensation -1.5 A7 Only
     */
    CameraExposureCompensationN15           = 5,
    /**
     * CameraExposureCompensation -1.3
     */
    CameraExposureCompensationN13                 ,
    /**
     * CameraExposureCompensation -1.0  A7,A9
     */
    CameraExposureCompensationN10                 ,
    /**
     * CameraExposureCompensation -0.7
     */
    CameraExposureCompensationN07                 ,
    /**
     * CameraExposureCompensation -0.5 A7 Only
     */
    CameraExposureCompensationN05                 ,
    /**
     * CameraExposureCompensation -0.3
     */
    CameraExposureCompensationN03           = 10,
    /**
     * CameraExposureCompensation 0  A7,A9
     */
    CameraExposureCompensation00                  ,
    /**
     * CameraExposureCompensation +0.3
     */
    CameraExposureCompensationP03                 ,
    /**
     * CameraExposureCompensation +0.5 A7 Only
     */
    CameraExposureCompensationP05                 ,
    /**
     * CameraExposureCompensation +0.7
     */
    CameraExposureCompensationP07                 ,
    /**
     * CameraExposureCompensation +1.0  A7,A9
     */
    CameraExposureCompensationP10           = 15,
    /**
     * CameraExposureCompensation +1.3
     */
    CameraExposureCompensationP13                 ,
    /**
     * CameraExposureCompensation +1.5 A7 Only
     */
    CameraExposureCompensationP15                 ,
    /**
     * CameraExposureCompensation +1.7
     */
    CameraExposureCompensationP17                 ,
    /**
     * CameraExposureCompensation +2.0  A7,A9
     */
    CameraExposureCompensationP20                 ,
    /**
     * CameraExposureCompensation +2.3
     */
    CameraExposureCompensationP23           = 20,
    /**
     * CameraExposureCompensation +2.7
     */
    CameraExposureCompensationP27                 ,
    /**
     * CameraExposureCompensation +3.0
     */
    CameraExposureCompensationP30
};

/**
 *  Camera anti-flicker
 */
typedef NS_ENUM(uint8_t, CameraAntiFlickerType)
{

    /**
     *  Unknown
     */
    CameraAntiFlickerUnknown                = 0xFF,
    /**
     *  Auto
     */
    CameraAntiFlickerAuto                   = 0x00,
    /**
     *  60 Hz
     */
    CameraAntiFlicker60Hz                   ,
    /**
     *  50 Hz
     */
    CameraAntiFlicker50Hz
};
/**
 * 文件序号模式
 */
typedef NS_ENUM(uint8_t, CameraFilenumway)
{
    
    /**
     *  Unknown
     */
    CameraFilenumwayUnknown                = 0xFF,
    /**
     *  Continuous
     */
    CameraFilenumwayContinuous             = 0x00,
    /**
     *  Reset
     */
    CameraFilenumwayReset

};

typedef NS_ENUM(uint8_t, CameraHistoType)
{
    
    /**
     *  Unknown
     */
    CameraHistoTypeUnknown                = 0xFF,
    /**
     *  ON
     */
    CameraHistoTypeON                     = 0x00,
    /**
     *  OFF
     */
    CameraHistoTypeOFF
    
};

typedef NS_ENUM(uint8_t, CameraColorType)
{
    /**
     *  Unknown
     */
    CameraColorTypeUnknown                  = 0xFF,
    /**
     *  普通
     */
    CameraColorTypeNone                     = 0x00,
    /**
     *  LOG
     */
    CameraColorTypeLog,
    /**
     * 鲜艳
     */
    CameraColorTypeVivid,
    /**
     * 黑白
     */
    CameraColorTypeBANDW,
    /**
     * 艺术
     */
    CameraColorTypeArt,
    /**
     * 电影
     */
    CameraColorTypeFilm,
    /**
     * 海滩
     */
    CameraColorTypeBeach,
    /**
     * 梦幻
     */
    CameraColorTypeDream,
    /**
     * 经典
     */
    CameraColorTypeClassic,
    /**
     * 怀旧
     */
    CameraColorTypeNostalgic
};

typedef NS_ENUM(uint8_t, CameraStyleType)
{
    /**
     * UnKnown
     */
    CameraStyleTypeUnknown                =0xFF,
    /**
     * Standard
     */
    CameraStyleTypeStandard               =0x00,
    /**
     * Landscape
     */
    CameraStyleTypeLandscape,
    /**
     * Soft
     */
    CameraStyleTypeSoft,
    /**
     * Custom
     */
    CameraStyleTypeCustom,
};

/**
 *  Camera sharpness
 */
typedef NS_ENUM(uint8_t, CameraSharpnessType)
{
    /**
     *  Unknown
     */
    CameraSharpnessUnknown                  = 0xFF,
    /**
     *  High
     */
    CameraSharpnessHigh                     = 0x00,
    /**
     *  Medium
     */
    CameraSharpnessMedium                   ,
    /**
     * Low
     */
    CameraSharpnessLow
   };

/**
 *  Camera contrast
 */
typedef NS_ENUM(uint8_t, CameraContrastType)
{
    /**
     *  Standard
     */
    CameraContrastStandard                  = 0x00,
    /**
     *  Hard
     */
    CameraContrastHard                      = 0x01,
    /**
     *  Soft
     */
    CameraContrastSoft                      = 0x02,
    /**
     *  Unknown
     */
    CameraContrastUnknown                   = 0xFF
};

/**
 *  Camera will perform action when connection is broken
 */
typedef NS_ENUM(uint8_t, CameraActionWhenBreak)
{
  
    /**
     *  Unknown
     */
    CameraActionUnknown                           = 0xFF,
    /**
     *  Go on recording
     */
    CameraActionGoOnRecording                     = 0x00,
    /**
     *  Stop recording
     */
    CameraActionStoopRecording
};
/*
 * 慢动作回放帧率
 */
typedef NS_ENUM(uint8_t, CameraSlowPlaybackSpeed)
{
    /**
     * Unknown
     */
    CameraSlowPlaybackSpeedUnknown                = 0xFF,
    /**
     * CameraSlowPlaybackSpeed_120ps
     */
    CameraSlowPlaybackSpeed120ps                  = 0x00,
    /**
     * CameraSlowPlaybackSpeed_30ps
     */
    CameraSlowPlaybackSpeed30ps                         ,
    /**
     * CameraSlowPlaybackSpeed_40ps
     */
    CameraSlowPlaybackSpeed40ps                         ,
    /**
     * CameraSlowPlaybackSpeed_60ps
     */
    CameraSlowPlaybackSpeed60ps                         ,
    /**
     * CameraSlowPlaybackSpeed_80ps
     */
    CameraSlowPlaybackSpeed80ps                         ,
    /**
     * CameraSlowPlaybackSpeed_240ps
     */
    CameraSlowPlaybackSpeed240ps
};

/*
 * 延时摄影间隔
 */
typedef NS_ENUM(uint8_t, CameraDelayedInterval)
{
    /**
     * Unknown
     */
    CameraDelayedIntervalUnknown                 = 0xFF,
    /**
     * CameraDelayedInterval1Sec
     */
    CameraDelayedInterval1Sec                    = 0x00,
    /**
     * CameraDelayedInterval2Sec
     */
    CameraDelayedInterval2Sec                          ,
    /**
     * CameraDelayedInterval3Sec
     */
    CameraDelayedInterval3Sec                          ,
    /**
     * CameraDelayedInterval4Sec
     */
    CameraDelayedInterval4Sec                          ,
    /**
     * CameraDelayedInterval5Sec
     */
    CameraDelayedInterval5Sec                          ,
    /**
     * CameraDelayedInterval6Sec
     */
    CameraDelayedInterval6Sec                          ,
    /**
     * CameraDelayedInterval7Sec
     */
    CameraDelayedInterval7Sec                          ,
    /**
     * CameraDelayedInterval8Sec
     */
    CameraDelayedInterval8Sec                          ,
    /**
     * CameraDelayedInterval9Sec
     */
    CameraDelayedInterval9Sec                          ,
    /**
     * CameraDelayedInterval10Sec
     */
    CameraDelayedInterval10Sec                          ,
    /**
     * CameraDelayedInterval20Sec
     */
    CameraDelayedInterval20Sec                          ,
    /**
     * CameraDelayedInterval30Sec
     */
    CameraDelayedInterval30Sec                          ,
    /**
     * CameraDelayedInterval45Sec
     */
    CameraDelayedInterval45Sec                          ,
    /**
     * CameraDelayedInterval60Sec
     */
    CameraDelayedInterval60Sec
};
/**
 *  延时摄影持续时间
 */
typedef NS_ENUM(uint8_t, CameraDelayedDuration)
{
    /**
     * Unknown
     */
    CameraDelayedDurationUnknown                      = 0xFF,
    /**
     * CameraDelayedDuration_1min
     */
    CameraDelayedDuration1Min                         = 0x00,
    /**
     * CameraDelayedDuration_2min
     */
    CameraDelayedDuration2Min,
    /**
     * CameraDelayedDuration_3min
     */
    CameraDelayedDuration3Min,
    /**
     * CameraDelayedDuration_4min
     */
    CameraDelayedDuration4Min,
    /**
     * CameraDelayedDuration_5min
     */
    CameraDelayedDuration5Min,
    /**
     * CameraDelayedDuration_6min
     */
    CameraDelayedDuration6Min,
    /**
     * CameraDelayedDuration_7min
     */
    CameraDelayedDuration7Min,
    /**
     * CameraDelayedDuration_8min
     */
    CameraDelayedDuration8Min,
    /**
     * CameraDelayedDuration_9min
     */
    CameraDelayedDuration9Min,
    /**
     * CameraDelayedDuration_10min
     */
    CameraDelayedDuration10Min,
    /**
     * CameraDelayedDuration_20min
     */
    CameraDelayedDuration20Min,
    /**
     * CameraDelayedDuration_30min
     */
    CameraDelayedDuration30Min,
    /**
     * CameraDelayedDuration_40min
     */
    CameraDelayedDuration40Min,
    /**
     * CameraDelayedDuration_50min
     */
    CameraDelayedDuration50Min,
    /**
     * CameraDelayedDuration_1hour
     */
    CameraDelayedDuration1Hour,
    /**
     * CameraDelayedDuration_2hour
     */
    CameraDelayedDuration2Hour,
    /**
     * CameraDelayedDuration_3hour
     */
    CameraDelayedDuration3Hour,
    /**
     * CameraDelayedDuration_4hour
     */
    CameraDelayedDuration4Hour,
    /**
     * CameraDelayedDuration_5hour
     */
    CameraDelayedDuration5Hour
};

/**
 * 倒计时拍照时间设置
 */
typedef NS_ENUM(uint8_t, CameraSelfTimerCount)
{
    /**
     * Unknown
     */
    CameraSelfTimerCountUnknown             =0xFF,
    /**
     * CameraSelfTimerCount_OFF
     */
    CameraSelfTimerCountOFF                 =0x00,
    /**
     * CameraSelfTimerCount_5sec
     */
    CameraSelfTimerCount5Sec,
    /**
     * CameraSelfTimerCount_10sec
     */
    CameraSelfTimerCount10Sec
};

typedef NS_ENUM(uint8_t, CameraDelayedSavePhoto)
{
    /**
     * Unknown
     */
    CameraDelayedSavePhotoUnknown          =0xFF,
    /**
     * CameraDelayedSavePhoto_ON
     */
    CameraDelayedSavePhotoOn               =0x00,
    /**
     * CameraDelayedSavePhoto_OFF
     */
    CameraDelayedSavePhotoOff
};
/**
 *  Camera multiple capture count
 */
typedef NS_ENUM(uint8_t, CameraMultiCaptureCount)
{
    /**
     *  Unknown
     */
    CameraMultiCaptureUnknown               = 0xFF,
    /**
     *  Capture 3 photo at one shot Support in A7
     */
    CameraMultiCapture3                     = 0x00,
    /**
     *  Capture 5 photo at one shot Support in A7
     */
    CameraMultiCapture5                     ,
    /**
     *  Capture 7 photo at one shot. Support in A7
     */
    CameraMultiCapture7                     ,
    /**
     *  Capture 8 photo at one shot. Support in A7
     */
    CameraMultiCapture8                     ,
    /**
     *  Capture 10 photo at one shot. Support in A7
     */
    CameraMultiCapture10,
    /**
     *  Capture 3 aeb photos once 小手持
     */
    CameraMultiCapture3aeb,
    /**
     *  Capture 5 aeb photos once 小手持
     */
    CameraMultiCapture5aeb
};
/**
 * 设置拍照模式 "AUTO","P", "M"
 */
typedef NS_ENUM(uint8_t, CameraCatureMode)
{
    /**
     * CameraCatureMode_Unknown
     */
    CameraCatureModeUnknown           = 0xFF,
    /**
     * CameraCatureMode_AUTO
     */
    CameraCatureModeAUTO              = 0x00,
    /**
     * CameraCatureMode_P
     */
    CameraCatureModeP,
    /**
     * CameraCatureMode_M
     */
    CameraCatureModeM,
    /**
     * CameraCatureMode_S
     */
    CameraCatureModeS,
    /**
     * CameraCatureMode_A
     */
    CameraCatureModeA
};
/**
 * Camera TimeLapse
 **/
typedef NS_ENUM(uint8_t, CameraTimeLapse)
{
    /**
     * Unknow
     */
    CameraTimeLapseUnknow     = 0xFF,
    /**
     * CameraTimeLapse_1s
     */
    CameraTimeLapse1s         = 0x00,
    /**
     * CameraTimeLapse_2s
     */
    CameraTimeLapse2s,
    /**
     * CameraTimeLapse_3s
     */
    CameraTimeLapse3s,
    /**
     * CameraTimeLapse_4s
     */
    CameraTimeLapse4s,
    /**
     * CameraTimeLapse_5s
     */
    CameraTimeLapse5s,
    /**
     * CameraTimeLapse_7s
     */
    CameraTimeLapse7s           = 5,
    /**
     * CameraTimeLapse_10s
     */
    CameraTimeLapse10s,
    /**
     * CameraTimeLapse_20s
     */
    CameraTimeLapse20s,
    /**
     * CameraTimeLapse_30s
     */
    CameraTimeLapse30s,
    /**
     * CameraTimeLapse_45s
     */
    CameraTimeLapse45s,
    /**
     * CameraTimeLapse_60s
     */
    CameraTimeLapse60s          = 10,
};
typedef NS_ENUM(uint8_t, CameraAEB)
{
    /**
     * Unknow
     */
    CameraAEBUnknow       = 0xFF,
    /**
     * CameraAEB3Photos,
     **/
    CameraAEB3Photos      = 0x00,
    /**
     * CameraAEB5Photos,
     **/
    CameraAEB5Photos

};
typedef NS_ENUM(uint8_t, CameraColor)
{
    /**
     * Unknow
     */
    CameraColorUnknow,
    /**
     * CameraAEB3Photos,
     **/

    
};
typedef NS_ENUM(uint8_t, CameraPiv)
{
    /**
     * Unknow
     */
    CameraPivUnknow        = 0xFF,
    /**
     * CameraPivOFF
     **/
    CameraPivOFF           = 0x00,
    /**
     * CameraPiv5sec
     **/
    CameraPiv5sec,
    /**
     * CameraPiv10sec
     **/
    CameraPiv10sec,
    /**
     * CameraPiv30sec
     **/
    CameraPiv30sec,
    /**
     * CameraPiv60sec
     **/
    CameraPiv60sec
    
};
typedef NS_ENUM(uint8_t, CameraRecordFormat)
{
    /**
     * Unknow
     */
    CameraRecordFormatUnknow    = 0xFF,
    /**
     * CameraRecordFormatMOV
     **/
    CameraRecordFormatMOV       = 0x00,
    /**
     * CameraRecordFormatMP4
     **/
    CameraRecordFormatMP4
};

typedef struct
{
    /**
     *  Value(1 ~ 254) indicate continuous capture photo count, when the camera complete take the specified photo count, it will stop automatically
     *  Value(255) indicate the camera will constantly take photo unless user stop take photo manually
     */
    uint8_t contiCaptureCount;
    
    /**
     *  time interval between two capture action. value should be in range [5, 30]
     */
    uint16_t timeInterval;
} CameraContinuousCapturePara;

typedef struct
{
    /**
     *  Quick view duration in range [0, 127] (second)
     */
    uint8_t duration;
    /**
     *  Quick view enable
     */
    bool enable;
} CameraQuickViewParam;

/**
 *  File inde mode
 */
typedef NS_ENUM(uint8_t, CameraFileIndexMode){
    /**
     *  Camera will reset storage file's index while change new SD card
     */
    CameraFileIndexReset,
    /**
     *  Camera will use the sequence index whle change new SD caard
     */
    CameraFileIndexSequence,
};

/**
 *  AEB continue capture parameter
 */
typedef struct
{
    /**
     *  Exposure offset value in range [1, 10] : 1 = 0ev, 2 = 0.3ev, 3 = 0.7ev, 4 = 1.0ev .... 10 = 3.0ev
     */
    uint8_t exposureOffset;
    /**
     *  Continue capture count
     */
    uint8_t continueCaptureCount;
} CameraAEBParam;

typedef struct
{
    CameraStyleType style;
    
    int8_t contrastNum;       //对比度
    int8_t saturateNum;       //饱和度
    int8_t sharpnessNum;      //锐度
    
    
} CameraStyleStruct;

/**
 *  WB  白平衡 parameter
 */
typedef struct
{
    CameraWhiteBalanceType type;
    
    int16_t customNum;       //对比度
    
} CameraWBStruct;

/**
 *  Video standard
 */
typedef NS_ENUM(uint8_t, CameraVideoStandard){
    /**
     *  PAL
     */
    CameraVideoStandardPAL     = 0x00,
    /**
     *  NTSC
     */
    CameraVideoStandardNTSC,
    /**
     *  Unknown
     */
    CameraVideoStandardUnknown = 0xFF
};

/**
 *  Camera user settings. user can save or load settings from specific position
 */
typedef NS_ENUM(uint8_t, CameraUserSettings){
    /**
     *  Default
     */
    CameraSettingsDefault,
    /**
     *  USER1
     */
    CameraSettingsUSER1,
    /**
     *  USER2
     */
    CameraSettingsUSER2,
    /**
     *  USER3
     */
    CameraSettingsUSER3,
    /**
     *  USER4
     */
    CameraSettingsUSER4,
    /**
     *  Unknown
     */
    CameraSettingsUnknown = 0xFF
};

/**
 *  Camera's digital filter
 */
typedef NS_ENUM(uint8_t, CameraDigitalFilter){
    /**
     *  None
     */
    CameraDigitalFilterNone,
    /**
     *  Art
     */
    CameraDigitalFilterArt,
    /**
     *  Reminiscence
     */
    CameraDigitalFilterReminiscence,
    /**
     *  Inverse
     */
    CameraDigitalFilterInverse,
    /**
     *  Black and white
     */
    CameraDigitalFilterBlackAndWhite,
    /**
     *  Bright
     */
    CameraDigitalFilterBright,
    /**
     *  Movie
     */
    CameraDigitalFilterMovie,
    /**
     *  Not Support Now
     */
    CameraDigitalFilterPunk,
    /**
     *  Not Support Now
     */
    CameraDigitalFilterPopArt,
    /**
     *  Not Support Now
     */
    CameraDigitalFilterWedding,
    /**
     *  Not Support Now
     */
    CameraDigitalFilterTinyHole,
    /**
     *  Not Support Now
     */
    CameraDigitalFilterMiniature,
    /**
     *  Not Support Now
     */
    CameraDigitalFilterOilPainting,
    /**
     *  Not Support Now
     */
    CameraDigitalFilterWaterColor,
    /**
     *  M31
     */
    CameraDigitalFilterM31,
    /**
     *  Delta
     */
    CameraDigitalFilterDelta,
    /**
     *  kDX
     */
    CameraDigitalFilterkDX,
    /**
     *  DK79
     */
    CameraDigitalFilterDK79,
    /**
     *  Prismo
     */
    CameraDigitalFilterPrismo,
    /**
     *  Jugo
     */
    CameraDigitalFilterJugo,
    /**
     *  Vision4
     */
    CameraDigitalFilterVision4,
    /**
     *  Vision6
     */
    CameraDigitalFilterVision6,
    /**
     *  VisionX
     */
    CameraDigitalFilterVisionX,
    /**
     *  Neutral
     */
    CameraDigitalFilterNeutral,
    /**
     *  Unknown
     */
    CameraDigitalFilterUnknown = 0xFF
};


typedef NS_ENUM(NSInteger, AUTELCameraStreamConnectState){
    /**
     *  断开状态
     **/
    AUTELCameraStreamDisconnected,
    /**
     *  已连接状态
     **/
    AUTELCameraStreamConnected,
    /**
     *  Type for camera A9
     */
    AUTELCameraStreamSession,
    /**
     *  Type for camera gopro
     */
    AUTELCameraStreamAllsetting,
    /**
     *  Unknown type
     */
    AUTELCameraStreamUnknown,
};

typedef NS_ENUM(NSInteger, AUTELCameraType){
    /**
     *  Unknown type
     */
    AUTELCamera_Unknown           = 0xFF,
    /**
     *  Type for camera A7
     */
    AUTELCamera_A7                = 0x00,
    /**
     *  Type for camera A9
     */
    AUTELCamera_A9,
    /**
     *  Type for camera gopro
     */
    AUTELCamera_Gopro,
    /**
     * 小手持相机
     */
    AUTELCamera_Selfie,
    /**
     * 一英寸相机
     */
    AUTELCamera_Inch,
};

typedef NS_ENUM(uint8_t, CameraSubTitleSwitchType)
{
    
    /**
     *  Unknown
     */
    CameraSubTitleSwitchTypeUnknown                = 0xFF,
    /**
     *  ON
     */
    CameraSubTitleSwitchTypeON                     = 0x00,
    /**
     *  OFF
     */
    CameraSubTitleSwitchTypeOFF
    
};
typedef NS_ENUM(uint8_t, CameraAutoSnapEnable)
{
    
    /**
     *  Unknown
     */
    CameraAutoSnapEnableUnknown                = 0xFF,
    /**
     *  ON
     */
    CameraAutoSnapEnableON                     = 0x00,
    /**
     *  OFF
     */
    CameraAutoSnapEnableOFF
    
};

typedef NS_ENUM(uint8_t, CameraDelayShotKeepPhotoEnable)
{
    
    /**
     *  Unknown
     */
    CameraDelayShotKeepPhotoEnableUnknown                = 0xFF,
    /**
     *  ON
     */
    CameraDelayShotKeepPhotoEnableON                     = 0x00,
    /**
     *  OFF
     */
    CameraDelayShotKeepPhotoEnableOFF
    
};

typedef NS_ENUM(uint8_t, CameraComposeVideoEnable)
{
    
    /**
     *  Unknown
     */
    CameraComposeVideoEnableUnknown                = 0xFF,
    /**
     *  ON
     */
    CameraComposeVideoEnableON                     = 0x00,
    /**
     *  OFF
     */
    CameraComposeVideoEnableOFF
    
};
typedef NS_ENUM(uint8_t, CameraVideoFramerateType)
{
    
    /**
     *  Unknown
     */
    CameraVideoFramerateTypeUnknown                = 0xFF,
    /**
     *  24fps
     */
    CameraVideoFramerateType24fps                    = 0x00,
    /**
     *  30fps
     */
    CameraVideoFramerateType30fps,
    /**
     *  40fps
     */
    CameraVideoFramerateType40fps,
    /**
     *  60fps
     */
    CameraVideoFramerateType60fps,
    
};
typedef NS_ENUM(uint8_t, CameraDelayShotRollingAngleType)
{
    
    /**
     *  Unknown
     */
    CameraDelayShotRollingAngleTypeUnknown                = 0xFF,
    /**
     *  180
     */
    CameraDelayShotRollingAngleType180                    = 0x00,
    /**
     *  270
     */
    CameraDelayShotRollingAngleType270,
    /**
     *  360
     */
    CameraDelayShotRollingAngleType360
   
    
};
typedef NS_ENUM(uint8_t, CameraDelayShotRollingDirectionType)
{
    
    /**
     *  Unknown
     */
    CameraDelayShotRollingDirectionTypeUnknown                = 0xFF,
    /**
     *  YawAnticlockwise
     */
    CameraDelayShotRollingDirectionTypeYawAnticlockwise                    = 0x00,
    /**
     *  YawClockwise
     */
    CameraDelayShotRollingDirectionTypeYawClockwise,
    /**
     *  YawPitchAnticlockwise
     */
    CameraDelayShotRollingDirectionTypeYawPitchAnticlockwise,
    /**
     *  YawPitchClockwise
     */
    CameraDelayShotRollingDirectionTypeYawPitchClockwise
    
};



typedef NS_ENUM(uint8_t, CameraTimeLapseDurationType)
{
    
    /**
     *  Unknown
     */
    CameraTimeLapseDurationTypeUnknown                = 0xFF,
    /**
     *  1min
     */
    CameraTimeLapseDurationType1min                    = 0x00,
    /**
     *  2min
     */
    CameraTimeLapseDurationType2min,
    /**
     *  3min
     */
    CameraTimeLapseDurationType3min,
    /**
     *  4min
     */
    CameraTimeLapseDurationType4min,
    /**
     *  5min
     */
    CameraTimeLapseDurationType5min,
    /**
     *  6min
     */
    CameraTimeLapseDurationType6min         = 5,
    /**
     *  7min
     */
    CameraTimeLapseDurationType7min,
    /**
     *  8min
     */
    CameraTimeLapseDurationType8min,
    /**
     *  9min
     */
    CameraTimeLapseDurationType9min,
    /**
     *  10min
     */
    CameraTimeLapseDurationType10min,
    /**
     *  20min
     */
    CameraTimeLapseDurationType20min        = 10,
    /**
     *  30min
     */
    CameraTimeLapseDurationType30min,
    /**
     *  40min
     */
    CameraTimeLapseDurationType40min,
    /**
     *  50min
     */
    CameraTimeLapseDurationType50min,
    /**
     *  1hr
     */
    CameraTimeLapseDurationType1hr,
    /**
     *  2hr
     */
    CameraTimeLapseDurationType2hr          = 15,
    /**
     *  3hr
     */
    CameraTimeLapseDurationType3hr,
    /**
     *  4hr
     */
    CameraTimeLapseDurationType4hr,
    /**
     *  5hr
     */
    CameraTimeLapseDurationType5hr,
    /**
     * 无限大
     */
    CameraTimeLapseDurationTypeDefault
};

typedef NS_ENUM(uint8_t, CameraAudioEnable)
{
    
    /**
     *  Unknown
     */
    CameraAudioEnableUnknown                = 0xFF,
    /**
     *  ON
     */
    CameraAudioEnableON                     = 0x00,
    /**
     *  OFF
     */
    CameraAudioEnableOFF
    
};
typedef NS_ENUM(uint8_t, EnableType)
{
    
    /**
     *  Unknown
     */
    EnableTypeUnknown                = 0xFF,
    /**
     *  ON
     */
    EnableTypeON                     = 0x00,
    /**
     *  OFF
     */
    EnableTypeOFF
    
};

typedef NS_ENUM(uint8_t, CameraWiFiBandType)
{
    
    /**
     *  Unknown
     */
    CameraWiFiBandTypeUnknown                = 0xFF,
    /**
     *  2.4G
     */
    CameraWiFiBandType24G                     = 0x00,
    /**
     *  5.8G
     */
    CameraWiFiBandType58G
    
};

typedef NS_ENUM(uint8_t, CameraLoopRecordTimeType)
{
    
    /**
     *  Unknown
     */
    CameraLoopRecordTimeTypeUnknown                = 0xFF,
    /**
     *  5分钟
     */
    CameraLoopRecordTimeType5Min                     = 0x00,
    /**
     *  10分钟
     */
    CameraLoopRecordTimeType10Min,
    /**
     *  20分钟
     */
    CameraLoopRecordTimeType20Min,
    /**
     *  30分钟
     */
    CameraLoopRecordTimeType30Min,
    /**
     *  60分钟
     */
    CameraLoopRecordTimeType60Min,
    /**
     *  120分钟
     */
    CameraLoopRecordTimeType120Min
    
};

typedef NS_ENUM(uint8_t, CameraAELockType)
{
    
    /**
     *  Unknown
     */
    CameraAELockTypeUnknown                = 0xFF,
    /**
     *  ON
     */
    CameraAELockTypeLOCK                   = 0x00,
    /**
     *  OFF
     */
    CameraAELockTypeUNLOCK
    
};
typedef NS_ENUM(uint8_t, CameraSinglePhotoTimerType)
{
    
    /**
     *  Unknown
     */
    CameraSinglePhotoTimerTypeUnknown                = 0xFF,
    /**
     *  OFF
     */
    CameraSinglePhotoTimerTypeOff                    = 0x00,
    /**
     * CameraSinglePhotoTimerType_3s
     */
    CameraSinglePhotoTimerType3s,
    /**
     * CameraSinglePhotoTimerType_5s
     */
    CameraSinglePhotoTimerType5s,
    /**
     * CameraSinglePhotoTimerType_10s
     */
    CameraSinglePhotoTimerType10s,
    /**
     * CameraSinglePhotoTimerType_HDR
     */
    CameraSinglePhotoTimerTypeHDR
};
typedef NS_ENUM(uint8_t, CameraAutoSnapshotTimeType)
{
    
    /**
     *  Unknown
     */
    CameraAutoSnapshotTimeTypeUnknown                = 0xFF,
    /**
     *  5s
     */
    CameraAutoSnapshotTimeType5s                    = 0x00,
    /**
     *  10s
     */
    CameraAutoSnapshotTimeType10s,
    /**
     *  30s
     */
    CameraAutoSnapshotTimeType30s,
    /**
     *  60s
     */
    CameraAutoSnapshotTimeType60s
};

typedef NS_ENUM(uint8_t, CameraSlowMotionResoType)
{
    
    /**
     *  Unknown
     */
    CameraSlowMotionResoTypeUnknown                = 0xFF,
    /**
     * CameraSlowMotionResoType_1080P120
     */
    CameraSlowMotionResoType1080p120               = 0x00,
    /**
     * CameraSlowMotionResoType_720P120
     */
    CameraSlowMotionResoType720p120,
    /**
     * CameraSlowMotionResoType_720P240
     */
    CameraSlowMotionResoType720p240
};
typedef NS_ENUM(uint8_t, CameraPanoramaType)
{
    /**
     * Unknown
     */
    CameraPanoramaType_Unknown                     = 0x00,
    /**
     * Auto
     */
     CameraPanoramaTypeAuto,
    /**
     * Selfie
     */
    CameraPanoramaTypeSelfie
    
};

typedef NS_ENUM(uint8_t, AUTELCameraSleepModeType)
{
    /**
     * Unknown
     */
    AUTELCameraSleepModeType_Unknown                     = 0x00,
    /**
     * Immediately
     */
    AUTELCameraSleepModeType_Immediately,
    /**
     * Never
     */
    AUTELCameraSleepModeType_Never
};


//  聚焦模式，可选项为AF/AF_C/AF_S/DMF/MF
typedef NS_ENUM(uint8_t, CameraFocusMode) {
    CameraFocusModeUnknown  = 0,
    CameraFocusModeAF,
    CameraFocusModeAF_C,
    CameraFocusModeAF_S,
    CameraFocusModeDMF,
    CameraFocusModeMF,
};

//  自动测聚模式，可选项为Average/Center/Spot，注：AF/AF_C/AF_S模式下有效
typedef NS_ENUM(uint8_t, CameraAFMeterMode) {
    CameraAFMeterModeUnknown    = 0,
    CameraAFMeterModeAverage,
    CameraAFMeterModeCenter,
    CameraAFMeterModeSpot,
};

//  光圈大小，可选参数1.8、2.0、2.2、2.5、2.8、3.2、3.6、4.0、4.5、5.1、5.7、6.4、7.2、8.0、9.0、10、11
typedef NS_ENUM(uint8_t, CameraIRIS) {
    CameraIRIS000   = 0,
    CameraIRIS018,
    CameraIRIS020,
    CameraIRIS022,
    CameraIRIS025,
    CameraIRIS028   = 5,
    CameraIRIS032,
    CameraIRIS036,
    CameraIRIS040,
    CameraIRIS045,
    CameraIRIS051   = 10,
    CameraIRIS057,
    CameraIRIS064,
    CameraIRIS072,
    CameraIRIS080,
    CameraIRIS090   = 15,
    CameraIRIS100,
    CameraIRIS110,
};


typedef NS_ENUM(NSInteger, AUTELCameraMessageType){
    /**
     *  Unknown type
     */
    AUTELCameraMessageType_Unknown,
    /**
     * 获取session
     **/
    AUTELCameraMessageType_StartSession,
    /**
     *  获取相机设置项
     **/
    AUTELCameraMessageType_GetAllSetting,
    /**
     *  获取相机设置项
     **/
    AUTELCameraMessageType_GetAllStates,
    /**
     * 设置相机时间
     **/
    AUTELCameraMessageType_SetCameraClock,
    /**
     * 拍照
     **/
    AUTELCameraMessageType_TakePhoto,
    /**
     * 停止拍照
     **/
     AUTELCameraMessageType_StopTakePhoto,
    /**
     * 开始录像
     **/
    AUTELCameraMessageType_StartRecord,
    /**
    * 停止录像
    **/
    AUTELCameraMessageType_StopRecord,
    /**
     * 获取分辨率列表
     **/
    AUTELCameraMessageType_ResolutionList,
    /**
     * 获取小手持慢动作录影分辨率列表
     **/
    AUTELCameraMessageType_SlowMotionList,
    /**
     * 设置分辨率
     **/
    AUTELCameraMessageType_SetResolution,
    /**
     * 获取帧率列表
     **/
    AUTELCameraMessageType_GetFpsList,
    /**
     * 设置帧率
     **/
    AUTELCameraMessageType_SetFps,
    /**
     * 获取SD卡文件夹列表
     **/
    AUTELCameraMessageType_Get_CameraSDFileFolderList,
    /**
     * 获取SD卡文件夹下的文件列表
     **/
    AUTELCameraMessageType_Get_CameraSDFileNameList,
    /**
     * 删除SD卡文件
     **/
    AUTELCameraMessageType_Delete_CameraSDFile,
    /**
     * 获取缩略图
     **/
    AUTELCameraMessageType_Get_CameraSDThumbImage,
    /**
     * 获取照片大小列表
     **/
    AUTELCameraMessageType_Get_CameraPhotoSizeList,
    /**
     * 设置照片大小
     **/
    AUTELCameraMessageType_Set_CameraPhotoSize,
    /**
     * 获取burst设置列表
     **/
    AUTELCameraMessageType_Get_CameraPhotoBurstList,
    /**
     * 设置burst
     **/
    AUTELCameraMessageType_Set_CameraPhotoBurst,
    /**
     * 设置timelapse
     */
    AUTELCameraMessageType_Set_CameraTimeLapse,
    /**
     * 获取timelapse列表
     */
    AUTELCameraMessageType_Get_CameraTimeLapseList,
    /**
     * 获取piv列表
     */
    AUTELCameraMessageType_Get_CameraPivList,
    /**
     * 获取当前录像时间
     */
    AUTELCameraMessageType_Get_CameraVedioTime,
    /**
     * 获取当前可拍照张数
     */
    AUTELCameraMessageType_Get_CameraFSPhotos,
    /**
     * 设置piv
     **/
    AUTELCameraMessageType_Set_CameraPiv,
    /**
     * 设置AEB
     */
    AUTELCameraMessageType_Set_CameraAeb,
    /**
     * 设置录像格式
     **/
    AUTELCameraMessageType_Set_CameraRecordFormat,
    /**
     * 设置照片格式
     */
    AUTELCameraMessageType_Set_CameraPhotoFormat,
    /**
     * 设置白平衡
     */
    AUTELCameraMessageType_Set_CameraWhiteBalance,
    /**
     * 设置曝光值
     */
    AUTELCameraMessageType_Set_CameraExposureCompensation,
    /**
     * 设置锐度 A7
     */
    AUTELCameraMessageType_Set_CameraSharpness,
    /**
     * 设置点测光
     */
    AUTELCameraMessageType_Set_CameraMeter,
    /**
     * 设置制式
     */
    AUTELCameraMessageType_Set_CameraSystemType,
    /**
     * 设置抗闪烁
     */
    AUTELCameraMessageType_Set_CameraAntiFlickerType,
    /**
     * 相机格式化
     */
    AUTELCameraMessageType_Set_CameraFormat,
    /**
     * 文件序号模式
     */
    AUTELCameraMessageType_Set_CameraFilenumway,
    /**
     * 直方图开关
     */
    AUTELCameraMessageType_Set_CameraHisto,
    /**
     * 设置颜色
     */
    AUTELCameraMessageType_Set_CameraColor,
    /**
     * 设置相机风格
     */
    AUTELCameraMessageType_Set_CameraStyle,
    /**
     * 设置连接断开是否继续录像
     */
    AUTELCameraMessageType_Set_CameraActionWhenConnectionBroken,
    /**
     * 设置慢动作回放帧率
     */
    AUTELCameraMessageType_Set_CameraSlowPlaybackSpeed,
    /**
     * 设置延时间隔
     */
    AUTELCameraMessageType_Set_CameraDelayedInterval,
    /**
     * 设置延时持续时间
     */
    AUTELCameraMessageType_Set_CameraDelayedDuration,
    /**
     * 设置全景步长
     */
    AUTELCameraMessageType_Set_CameraPanoramaStep,
    /**
     * 设置全景角度
     */
    AUTELCameraMessageType_Set_CameraPanoramaAngle,
    /**
     * 倒计时时间设置
     */
    AUTELCameraMessageType_Set_CameraSelfTimerCount,
    /**
     * 延时拍照片存储
     */
    AUTELCameraMessageType_Set_CameraDelayedSavePhoto,
    /**
     * 设置相机快门
     */
    AUTELCameraMessageType_Set_CameraShutter,
    /**
     * 设置相机ISO
     */
    AUTELCameraMessageType_Set_CameraISO,
    /**
     * 设置拍照模式
     */
    AUTELCameraMessageType_Set_CameraCaptureMode,
    /**
     * 设置A9点测光
     */
    AUTELCameraMessageType_Set_CameraPhotometry,
    /**
     * 设置字幕开关
     */
    AUTELCameraMessageType_Set_CameraSubTileSwitch,
    /**
     * 设置AE锁
     */
    AUTELCameraMessageType_Set_CameraAELock,
    /**
     * 小手持单拍设置
     */
    AUTELCameraMessageType_Set_CameraSingleCount,
    /**
     * 小手持慢动作录像分辨率
     */
    AUTELCameraMessageType_Set_CameraSlowMotionReso,
    /**
     * 3D降噪
     */
    AUTELCameraMessageType_Set_CameraMCTF,
    /**
     * 变焦
     */
    AUTELCameraMessageType_Set_CameraRoom,
    AUTELCameraMessageType_Get_CameraPhotoSizeType,

};

typedef NS_ENUM(NSInteger, AUTELCameraHttpMessageType){
    /**
     *  Unknown type
     */
    AUTELCameraHttpMessageType_Unknown,
    /**
     * 获取设备信息
     */
    AUTELCameraHttpMessageType_Get_CameraDeviceInformation,
    /**
     * 获取系统状态
     */
    AUTELCameraHttpMessageType_Get_CameraSystemStatus,
    /**
     * 获取SD卡状态
     */
    AUTELCameraHttpMessageType_Get_CameraSDCardStatus,
    /**
     * 格式化SD卡
     */
    AUTELCameraHttpMessageType_Set_CameraFormatSD,
    /**
     * 恢复出厂设置
     */
    AUTELCameraHttpMessageType_Set_CameraReset,
    /**
     * 获取系统时间
     */
    AUTELCameraHttpMessageType_Get_CameraSystemTime,
    /**
     * 设置系统时间
     */
    AUTELCameraHttpMessageType_Set_CameraSystemTime,
    /**
     * 获取视频编码器配置
     */
    AUTELCameraHttpMessageType_Get_CameraVideoEncoderCfg,
    /**
     * 设置视频编码器配置
     */
    AUTELCameraHttpMessageType_Set_CameraVideoEncoderCfg,
    /**
     * 录像分辨率
     */
    AUTELCameraHttpMessageType_Set_CameraResolution,
    /**
     * 获取视频编码器配置选项
     */
    AUTELCameraHttpMessageType_Get_CameraVideoEncoderCfgOptions,
    /**
     * 获取视频源配置
     */
    AUTELCameraHttpMessageType_Get_CameraVideoSourceCfg,
    /**
     * 设置视频源配置
     */
    AUTELCameraHttpMessageType_Set_CameraVideoSourceCfg,
    /**
     * 设置制式
     */
    AUTELCameraHttpMessageType_Set_CameraSystemType,
    /**
     * 设置抗闪烁
     */
    AUTELCameraHttpMessageType_Set_CameraAntiFlickerType,
    /**
     * 设置3D降噪
     */
    AUTELCameraHttpMessageType_Set_CameraEnable3DNR,
    /**
     * 设置快门
     */
    AUTELCameraHttpMessageType_Set_CameraShutter,
    /**
     * 获取视频源配置选项
     */
    AUTELCameraHttpMessageType_Get_CameraVideoSourceCfgOptions,
    /**
     * 获取图像参数
     */
    AUTELCameraHttpMessageType_Get_CameraImageSettings,
    /**
     * 设置图像参数
     */
    AUTELCameraHttpMessageType_Set_CameraImageSettings,
    /**
     * 获取相机模式
     */
    AUTELCameraHttpMessageType_Get_CameraMode,
    /**
     * 获取PIV
     */
    AUTELCameraHttpMessageType_Get_CameraPIV,
    /**
     * 设置相机模式
     */
    AUTELCameraHttpMessageType_Set_CameraMode,
    /**
     * 开始拍照
     */
    AUTELCameraHttpMessageType_CameraStartTakePhotos,
    /**
     * 停止拍照
     */
    AUTELCameraHttpMessageType_CameraStopTakePhotos,
    /**
     * 开始录像
     */
    AUTELCameraHttpMessageType_CameraStartRecording,
    /**
     * 停止录像
     */
    AUTELCameraHttpMessageType_CameraStopRecording,
    /**
     * 获取拍照参数
     */
    AUTELCameraHttpMessageType_Get_CameraPhotoTakingSettings,
    /**
     * 设置图片大小
     */
    AUTELCameraHttpMessageType_Set_CameraPhotoSize,
    /**
     * 设置照片格式
     */
    AUTELCameraHttpMessageType_Set_CameraPhotoFormat,
    /**
     * 设置间隔拍时间
     */
    AUTELCameraHttpMessageType_Set_CameraTimeLapse,
    /**
     * 设置拍照参数
     */
    AUTELCameraHttpMessageType_Set_CameraPhotoTakingSettings,
    /**
     * 设置定时拍生成视频开关
     */
    AUTELCameraHttpMessageType_Set_CameraTimeLapseComposeVideo,
    /**
     * 设置定时拍持续时间
     */
    AUTELCameraHttpMessageType_Set_CameraTimeLapseDuration,
    /**
     * 设置定时拍视频速率
     */
    AUTELCameraHttpMessageType_Set_CameraTimeLapseVideoFramerate,
    /**
     * 获取录像参数
     */
    AUTELCameraHttpMessageType_Get_CameraRecordingSettings,
    /**
     * 设置录像参数
     */
    AUTELCameraHttpMessageType_Set_CameraRecordingSettings,
    /**
     * 设置录像格式
     */
    AUTELCameraHttpMessageType_Set_CameraRecordFormat,
    /**
     * 设置录像自动拍照时间间隔
     */
    AUTELCameraHttpMessageType_Set_CameraAutoSnapshotTime,
    /**
     * 设置录像时拍照开关
     */
    AUTELCameraHttpMessageType_Set_CameraAutoSnapshotEnable,
    /**
     * 设置循环录影的时间
     */
    AUTELCameraHttpMessageType_Set_CameraLoopRecordTime,
    /**
     * 设置录像参数_录音开关
     */
    AUTELCameraHttpMessageType_Set_CameraEnableAudio,
    /**
     * 设置测光点
     */
    AUTELCameraHttpMessageType_Set_CameraLocationMeter,
    /**
     * 获取图像风格
     */
    AUTELCameraHttpMessageType_Get_CameraImageStyle,
    /**
     * 设置图像风格
     */
    AUTELCameraHttpMessageType_Set_CameraImageStyle,
    /**
     * 设置白平衡参数
     */
    AUTELCameraHttpMessageType_Set_CameraWhiteBalance,
    /**
     * 获取白平衡参数
     */
    AUTELCameraHttpMessageType_Get_CameraWhiteBalance,
    /**
     * 设置图像颜色参数
     */
    AUTELCameraHttpMessageType_Set_CameraImageColor,
    /**
     * 获取图像颜色参数
     */
    AUTELCameraHttpMessageType_Get_CameraImageColor,
    /**
     * 获取图像曝光参数
     */
    AUTELCameraHttpMessageType_Get_CameraImageExposure,
    /**
     * 设置图像曝光参数
     */
    AUTELCameraHttpMessageType_Set_CameraImageExposure,
    /**
     * 获取相机ISO
     */
    AUTELCameraHttpMessageType_Get_CameraISO,
    /**
     * 设置相机ISO
     */
    AUTELCameraHttpMessageType_Set_CameraISO,
    /**
     * 获取字幕开关
     */
    AUTELCameraHttpMessageType_Get_CameraSubTileSwitch,
    /**
     * 设置字幕开关
     */
    AUTELCameraHttpMessageType_Set_CameraSubTileSwitch,
    /**
     * 获取AE锁
     */
    AUTELCameraHttpMessageType_Get_CameraAELock,
    /**
     * 设置AE锁
     */
    AUTELCameraHttpMessageType_Set_CameraAELock,
    /**
     * 小手持单拍设置
     */
    AUTELCameraHttpMessageType_Set_CameraSingleCount,
    /**
     * 获取小手持慢动作录像分辨率
     */
    AUTELCameraHttpMessageType_Get_CameraSlowMotionReso,
    /**
     * 小手持慢动作录像分辨率
     */
    AUTELCameraHttpMessageType_Set_CameraSlowMotionReso,
    /**
     * 获取慢动作回放帧率
     */
    AUTELCameraHttpMessageType_Get_CameraSlowPlaybackSpeed,
    /**
     * 设置慢动作回放帧率
     */
    AUTELCameraHttpMessageType_Set_CameraSlowPlaybackSpeed,
    /**
     * 获取延时间隔
     */
    AUTELCameraHttpMessageType_Get_CameraDelayedInterval,
    /**
     * 设置延时间隔
     */
    AUTELCameraHttpMessageType_Set_CameraDelayedInterval,
    /**
     * 获取延时持续时间
     */
    AUTELCameraHttpMessageType_Get_CameraDelayedDuration,
    /**
     * 设置延时持续时间
     */
    AUTELCameraHttpMessageType_Set_CameraDelayedDuration,
    /**
     * 获取全景步长
     */
    AUTELCameraHttpMessageType_Get_CameraPanoramaStep,
    /**
     * 设置全景步长
     */
    AUTELCameraHttpMessageType_Set_CameraPanoramaStep,
    /**
     * 获取全景角度
     */
    AUTELCameraHttpMessageType_Get_CameraPanoramaAngle,
    /**
     * 设置全景角度
     */
    AUTELCameraHttpMessageType_Set_CameraPanoramaAngle,
    /**
     * 获取倒计时时间设置
     */
    AUTELCameraHttpMessageType_Get_CameraSelfTimerCount,
    /**
     * 倒计时时间设置
     */
    AUTELCameraHttpMessageType_Set_CameraSelfTimerCount,
    /**
     * 获取延时拍照片存储
     */
    AUTELCameraHttpMessageType_Get_CameraDelayedSavePhoto,
    /**
     * 延时拍照片存储
     */
    AUTELCameraHttpMessageType_Set_CameraDelayedSavePhoto,
    /**
     *
     */
    AUTELCameraHttpMessageType_Set_CameraFileNamingMode,
    /**
     * 设置WIFI配置参数
     */
    AUTELCameraHttpMessageType_Set_CameraWiFiConfiguration,
    /**
     * 直方图开关
     */
    AUTELCameraHttpMessageType_Set_CameraHistogramStream,
    /**
     * 设置录像提示音
     */
    AUTELCameraHttpMessageType_Set_CameraRecordTone,
    /**
     * 设置拍照提示音
     */
    AUTELCameraHttpMessageType_Set_CameraCaptureTone,
    /**
     * 设置麦克风音量
     */
    AUTELCameraHttpMessageType_Set_CameraMicVolume,
    /**
     * 设置扬声器音量
     */
    AUTELCameraHttpMessageType_Set_CameraSpeakerVolume,
    /**
     * 开始生成全景图
     */
    AUTELCameraHttpMessageType_CameraStartSyntheticPanoramagram,
    /**
     * 结束生成全景图
     */
    AUTELCameraHttpMessageType_CameraStopSyntheticPanoramagram,
    /**
     * 设置档位
     */
    AUTELCameraHttpMessageType_Set_CameraGear,
    /**
     * 设置延时摄影持续时间
     */
    AUTELCameraHttpMessageType_Set_CameraDelayShotDuration,
    /**
     * 设置延时摄影拍照间隔时间
     */
    AUTELCameraHttpMessageType_Set_CameraDelayShotInterval,
    /**
     * 设置延时摄影帧率
     */
    AUTELCameraHttpMessageType_Set_CameraDelayShotFramerate,
    /**
     * 设置延时摄影转动角度
     */
    AUTELCameraHttpMessageType_Set_CameraDelayShotRollingAngle,
    /**
     * 设置延时摄影转动方向
     */
    AUTELCameraHttpMessageType_Set_CameraDelayShotRollingDirection,
    /**
     * 设置休眠模式
     */
    AUTELCameraHttpMessageType_Set_CameraSleepModel,
    /**
     * 获取聚焦信息
     */
    AUTELCameraHttpMessageType_Get_Focus,
    /**
     * 设置聚焦信息
     */
    AUTELCameraHttpMessageType_Set_Focus,
    /**
     * 获取光圈大小
     */
    AUTELCameraHttpMessageType_Get_IRIS,
    /**
     * 设置光圈大小
     */
    AUTELCameraHttpMessageType_Set_IRIS,
    /**
     * 获取数码变焦信息
     */
    AUTELCameraHttpMessageType_Get_ZoomFactor,
    /**
     * 设置数码变焦信息
     */
    AUTELCameraHttpMessageType_Set_ZoomFactor,
};


#endif /* AUTELCameraSettingsDef_h */
