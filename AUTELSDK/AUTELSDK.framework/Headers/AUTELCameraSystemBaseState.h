//
//  AUTELCameraSystemBaseState.h
//  AUTELSDK
//
//  Created by 虢蔚翔 on 16/8/17.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELCameraDef.h>

/**
*  This class provides the current status of the camera.
*
*/
@interface AUTELCameraSystemBaseState : NSObject<NSCopying>

/**
 *  @brief YES means the camera is taking photos in one of the given shooting modes. During the intervals of TimeLapse mode, this property is displayed as NO.
 *
 *  YES 表示相机正在拍照，无论是哪拍照模式。在定时拍的拍照间隔中，该属性为 NO。
 */
@property(nonatomic) BOOL isShootingSinglePhoto;

/**
 *  @brief When the camera is taking photos in one of the given shooting modes and the files are saved as RAW or RAW+JPEG format, this property is displayed as YES. During the intervals of TimeLapse mode, or if the photos are saved as JPEG format, this property is displayed as NO.
 *
 *  当相机正在拍照，无论哪种拍照方式，且保存的文件是 RAW 或 RAW+JPEG 格式，该属性值为 YES，在定时拍的拍照间隔中，该属性为 NO。如果照片只保存为 JPEG，该属性为 NO。
 */
@property(nonatomic) BOOL isShootingSinglePhotoInRAWFormat;

/**
 *  @brief YES In TimeLapse mode, YES means the camera is taking photos, and NO means the camera stops taking photos.
 *
 *  YES 表示相机正在执行定时拍，NO 表示定时拍停止。
 */
@property(nonatomic) BOOL isShootingIntervalPhoto;

/**
 *  @brief In Burst mode, YES means the camera is taking photos, and NO means the camera stops taking photos.
 *
 *  YES 表示相机正在进行连拍，连拍停止后该属性为 NO。
 */
@property(nonatomic) BOOL isShootingBurstPhoto;

/**
 *  @brief YES means the camera is recording a video.
 *
 *  YES 表示相机正在录像。
 */
@property(nonatomic) BOOL isRecording;

/**
 * @brief SD卡碎片造成录像停止
 *
 *  YES 表示 SD卡碎片造成录像停止,否则为 NO,当开始录像时，该标志会被置为 NO.
 */
@property(nonatomic) BOOL isFragmentationHinderVideo;

/**
 *  @brief YES means the camera is saving a photo. At this moment, the user cannot change the shooting mode or start to take another photo.
 *
 *  YES 表示相机正在存储图片
 *  当相机正在存储图片时，用户不能改变相机模式或者开始拍另外一张照片。
 */
@property(nonatomic) BOOL isStoringPhoto;

/**
 *  @brief YES means the camera is overheated.
 *
 *  YES 表示相机过热。
 */
@property(nonatomic) BOOL isCameraOverHeated;

/**
 *  @brief YES means the camera battery level is low.
 *
 *  YES 表示相机电量低。
 */
@property(nonatomic) BOOL isCameraLowBatteryLevel;


/**
 *  @brief YES means the camera is in USB mode.
 *
 *  YES 表示相机处于 usb 模式
 */
@property(nonatomic) BOOL isUSBMode;

/**
 *  @brief Yes if the camera is upgrading.
 *
 *  标记相机是否处于升级状态
 */
@property(nonatomic) BOOL isUpgrading;

/**
 *  @brief Current mode of the camera.
 *
 *  相机当前工作模式
 */
@property(nonatomic) AUTELCameraWorkMode mode;

/**
 *  @brief Current video duration
 *
 *  当前录像时间
 */
@property(nonatomic) NSTimeInterval currentVideoRecordingTimeInSeconds;

/**
 *  @brief Number of photos taken in TimeLapse mode
 *
 *  定时拍摄当前拍摄张数
 */
@property(nonatomic) int currentIntervalCaptureCount;

/**
 *  @brief Camera PIV status
 *
 *  相机PIV状态
 */
@property (nonatomic) AUTELCameraPictureInVideoStatus currentPivStatus;

/**
 *  @brief Camera zoom scale
 *
 *  相机PIV状态
 */
@property (nonatomic) float zoomValue;

/**
 *  @brief Lens level Fov
 *
 *  镜头水平Fov
 */
@property(nonatomic) float fovH;

/**
 *  @brief Lens Vertical Fov
 *
 *  镜头垂直Fov
 */
@property(nonatomic) float fovV;

/**
 *  @brief Minimum photo gap
 *
 *  最小拍照间隙
 */
@property(nonatomic) int photoIntervalMin;

/**
 *  @brief Camera pixel pitch
 *
 *  相机像元间距，double型，单位微米
 */
@property(nonatomic) double pixelSize;

/**
 *  @brief Camera focal length
 *
 *  相机焦距，double型，单位毫秒
 */
@property(nonatomic) double focalLength;

/**
 *  @brief Average temperature, unit Celsius * 10
 *
 *  平均温度,单位摄氏度*10
 */
@property(nonatomic) int averageTemp;
/**
 *  @brief Central temperature, unit Celsius * 10
 *
 *  中心温度,单位摄氏度*10
 */
@property(nonatomic) int centerTemp;
/**
 *  @brief Hot spot temperature in Celsius * 10
 *
 *  热点温度,单位摄氏度*10
 */
@property(nonatomic) int hotTemp;
/**
 *  @brief Hot spot X coordinate
 *
 *  热点X坐标，以图像宽比例，Float型
 */
@property(nonatomic) float hotX;
/**
 *  @brief Hot spot Y coordinate
 *
 *  热点Y坐标，以图像高比例，Float型
 */
@property(nonatomic) float hotY;
/**
 *  @brief Cold spot temperature in degrees Celsius * 10
 *
 *  冷点温度,单位摄氏度*10
 */
@property(nonatomic) int coldTemp;
/**
 *  @brief Cold spot X coordinate
 *
 *  冷点X坐标，以图像宽比例，Float型
 */
@property(nonatomic) float coldX;
/**
 *  @brief Cold spot Y coordinate
 *
 *  冷点Y坐标，以图像高比例，Float型
 */
@property(nonatomic) float coldY;
/**
 *  @brief Pointing temperature, unit Celsius * 10
 *
 *  指点温度,单位摄氏度*10
 */
@property(nonatomic) int touchTemp;
/**
 *  @brife
 *
 *  加密状态, 0：空闲，1：加密，2：解密
 */
@property(nonatomic) int cipherStatus;
/**
 *  @brife
 *
 *  解密文件总数（只在解密时，需要此参数）
 */
@property(nonatomic) int cipherTotal;
/**
 *  @brife
 *
 *  已解密文件数（只在解密时，需要此参数）
 */
@property(nonatomic) int cipherCurrent;

@end
