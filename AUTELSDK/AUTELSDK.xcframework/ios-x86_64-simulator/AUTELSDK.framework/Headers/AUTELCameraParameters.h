//
//  AUTELCameraParameters.h
//  AUTELSDK
//
//  Created by 虢蔚翔 on 16/8/15.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  You can learn the currently supported parameter ranges .
 *
 *  相机参数，可获取相机当前支持的参数范围
 */
@interface AUTELCameraParameters : NSObject


/**
 *  @brief Returns the current valid range for video resolution (AUTELCameraVideoResolution) and frame rate(AUTELCameraVideoFrameRate). Returns an empty array if current camera does not support any video resolution or frame rate setting, returns nil if the camera is disconnected.
 *
 *  返回相机当前视频标准下支持的视频分辨率和帧率范围。当前相机不支持任何视频分辨率和帧率时，会返回一个空数组；相机断开连接时会返回nil。
 *
 *  @return Array of pairs. Each pair represents a valid AUTELCameraVideoResolution value and AUTELCameraVideoFrameRate value.
 *  
 *  数组对象，数组对象内会有多个数组，每个数组对应一个视频分辨率(AUTELCameraVideoResolution) 下支持的帧率(AUTELCameraVideoFrameRate)
 */
- (NSArray<NSArray<NSNumber *> *> *)supportedCameraVideoResolutionAndFrameRateRange;


/**
 *  @brief Return to the resolution and frame rate info.
 *
 *
 返回相机当前视频制式支持的分辨率和帧率信息

 @return 一个字典对象，其中 key 为分辨率，参考 `AUTELCameraVideoResolution`, value 为一个当前分辨率支持的帧率数组, 数组元素代表一个帧率，参考 `AUTELCameraVideoFrameRate`
 */
- (NSDictionary<NSNumber *, NSArray <NSNumber *> *> *)supportedVideoResolutionAndFrameRateRange;

/**
 *  @brief Returns the current valid range for camera mode (AUTELCameraWorkMode). Returns an empty array if current camera has no supported camera mode,returns nil if the camera is disconnected.
 *
 *  返回当前相机支持的工作模式范围(AUTELCameraWorkMode)。当前相机不支持任何工作模式时，会返回一个空数组；相机断开连接时会返回nil。
 *
 *  @return Array of NSNumber. Each element represents one current supported camera mode.
 *
 *  返回一个数组，数组中的每个元素都是 NSNumber 类型。每一个元素都代表一种当前支持的相机工作模式。
 */
- (NSArray<NSNumber *> *)supportedCameraModeRange;

/**
 *  @brief Returns the current valid range for camera's exposure mode (AUTELCameraExposureMode). Returns an empty array if current camera does not support any exposure mode,returns nil the camera is disconnected.
 *
 *  返回当前相机支持的曝光模式（AUTELCameraExposureMode）。当前相机不支持任何曝光模式会返回一个空数组；相机断开连接时会返回nil。
 *
 *  @return Array of NSNumber. Each element represent one current supported exposure mode.
 *
 *  返回一个数组，数组中的每个元素都是 NSNumber 类型。每一个元素都代表一种当前相机支持的曝光模式。
 *
 */
- (NSArray<NSNumber *> *)supportedCameraExposureModeRange;

/**
 *  @brief Returns the current valid range for camera's ISO (AUTELCameraISO) to set. Returns an empty array if current camera does not support any iso value to set. And returns nil if the camera is disconnected.
 *
 *  返回相机当前曝光模式下支持设置的 ISO (AUTELCameraISO) 值。当前相机不支持任何 ISO 值设置时会返回一个空数组，比如在 自动曝光模式(AUTELCameraExposureModeAuto)下，ISO值不可设置，将会返回一个空数组。当相机断开连接时会返回nil。
 *
 *  @return Array of NSNumber. Each element represent one current supported ISO value.
 *
 *  返回一个数组，数组中每个元素都是 NSNumber 类型。每一个元素都代表一种当前相机支持设置的 ISO 值。
 */
- (NSArray<NSNumber *> *)supportedCameraISORange;

/**
 *  @brief Returns the current valid range for camera's ISO mode (AUTELCameraISOMode). Returns an empty array if current camera does not support any ISO mode,returns nil the camera is disconnected.
 *
 *  返回当前相机支持的曝光模式（AUTELCameraISOMode）。当前相机不支持任何感光度模式会返回一个空数组；相机断开连接时会返回nil。
 *
 *  @return Array of NSNumber. Each element represent one current supported ISO mode.
 *
 *  返回一个数组，数组中的每个元素都是 NSNumber 类型。每一个元素都代表一种当前相机支持的感光度模式。
 *
 */
- (NSArray<NSNumber *> *)supportedCameraISOModeRange;

/**
 *  @brief Returns the current valid range for camera's shutter speed (AUTELCameraShutterSpeed) to set. Returns an empty array if current camera does not support any shutter speed value. And returns nil if the camera is disconnected.
 *
 *  返回相机当前曝光模式下支持设置的快门速度范围 (AUTELCameraShutterSpeed)。当前相机不支持任何快门速度的设置时会返回一个空数组，类似ISO值。当相机断开连接时会返回nil。
 *
 *  @return Array of NSNumber. Each element represent one current supported shutter speed value.
 *
 *  返回一个数组，数组中每个元素都是 NSNumber 类型。每一个元素都代表当前相机支持设置的快门速度。
 */
- (NSArray<NSNumber *> *)supportedCameraShutterSpeedRange;

/**
 *  @brief Returns the current valid range for camera's exposure compensation (AUTELCameraExposureCompensation) to set. Returns an empty array if current camera does not support any exposure compensation value. And returns nil if the camera is disconnected.
 *
 *  返回相机当前曝光模式下支持设置的曝光补偿范围 (AUTELCameraShutterSpeed)。当前相机不支持任何曝光补偿值的设置时会返回一个空数组，类似ISO值。当相机断开连接时会返回nil。
 *
 *  @return Array of NSNumber. Each element represent one current supported exposure compensation value.
 *
 *  返回一个数组，数组中每个元素都是 NSNumber 类型。每一个元素都代表当前相机支持设置的曝光补偿值。
 */
- (NSArray<NSNumber *> *)supportedCameraExposureCompensationRange;

/**
 *  @brief Returns the current valid range for camera's aperture (AUTELCameraAperture) to set. Returns an empty array if current camera does not support any aperture value. And returns nil if the camera is disconnected.
 *
 *  返回相机当前曝光模式下支持设置的光圈值范围 (AUTELCameraAperture)。当前相机不支持任何光圈值的设置时会返回一个空数组，类似ISO值。当相机断开连接时会返回nil。
 *
 *  @return Array of NSNumber. Each element represent one current supported aperture value.
 *
 *  返回一个数组，数组中每个元素都是 NSNumber 类型。每一个元素都代表当前相机支持设置的光圈值。
 */
- (NSArray<NSNumber *> *)supportedCameraApertureRange;

/**
 *  @brief Returns the current valid range for camera's interval parameter (AUTELCameraInterval) to set. Returns an empty array if current camera does not support any interval parameter. And returns nil if the camera is disconnected.
 *
 *  返回相机当前图片格式下支持设置的定时拍摄时间范围 (AUTELCameraInterval)。当前相机不支持任何定时拍摄时间的设置时会返回一个空数组。当相机断开连接时会返回nil。
 *
 *  @return Array of NSNumber. Each element represent one current supported interval parameter.
 *
 *  返回一个数组，数组中每个元素都是 NSNumber 类型。每一个元素都代表当前相机支持设置的定时拍摄时间。
 */
- (NSArray<NSNumber *> *)supportedCameraTimeLapseIntervalRange;

/**
 *  @brief Return to the AEB selectable range.
 *
 *  返回当前相机AEB拍摄张数可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray<NSNumber *> *)supportedCameraPhotoAEBCaptureCountRange;

/**
 *  @brief Return to the video format selectable range.
 *
 *  返回当前相机视频格式可选择的范围
 *
 *  @return Array of NSNumber
 */
- (NSArray<NSNumber *> *)supportedCameraVideoFileFormatRange;

/**
 *  @brief Return to the photo interval selectable range when recording.
 *
 *  返回当前相机录像时拍照间隔的可选择的范围
 *
 *  @return Array of NSNumber
 */
- (NSArray<NSNumber *> *)supportedCameraPictureInVideoIntervalRange;

/**
 *  @brief Return to the video standard selectable range.
 *
 *  返回当前相机视频标准可选择的范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray<NSNumber *> *)supportedCameraVideoStandardRange;

/**
 *  @brief Return to the image ratio selectable range.
 *
 *  返回当前相机拍照图片比例可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraPhotoAspectRatioRange;

/**
 *  @brief Return to the image format selectable range.
 *
 *  返回当前相机拍照图片格式可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraPhotoFileFormatRange;

/**
 *  @brief Return to the snapshots selectable range.
 *
 *  返回当前相机快拍张数可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraPhotoBurstCountRange;

/**
 *  @brief Return to the spot metering area horizontal axis selectable range.
 *
 *  返回当前相机点测光横轴可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraSpotMeteringAreaRowIndexRange;

/**
 *  @brief Return to the spot metering area vertical axis selectable range.
 *
 *  返回当前相机点测光纵轴可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraSpotMeteringAreaColIndexRange;

/**
 *  @brief Return to the white balance selectable range.
 *
 *  返回当前相机白平衡可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraWhiteBalanceRange;

/**
 *  @brief Return to white balance color temperature range.
 *
 *  返回当前相机白平衡自定义色温值范围
 *
 *  @return 返回一个字典，其中表示最大值的 key 为 @"Max"，最小值的 key 为 @"Min"，步进长度的 key 为 @"Step".
 *
 *  @note 实际色温值 colorTemperature (K) = colorTemperature * 100,例如色温值为50，表示真实色温值为 5000K。
 */
- (NSDictionary <NSString *, NSNumber *> *)supportedCameraWhiteBalanceCustomColorTemperatureRange;

/**
 *  @brief Return to anti-flicker mode selectable range.
 *
 *  返回当前相机抗闪烁模式可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraAntiFlickerRange;

/**
 *  @brief Return to image style selectable range.
 *
 *  返回当前相机图像风格可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraPhotoStyleRange;

/**
 *  @brief Return to sharpness selectable range.
 *
 *  返回当前相机锐度可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraSharpnessRange;

/**
 *  @brief Return to contrast selectable range.
 *
 *  返回当前相机对比度可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraContrastRange;

/**
 *  @brief Return to saturation selectable range.
 *
 *  返回当前相机饱和度可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraSaturationRange;

/**
 *  @brief Return to camera chroma selectable range.
 *
 *  返回当前相机色度可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraHueRange;

/**
 *  @brief Return to Digital filter type selectable range.
 *
 *  返回当前相机数码滤波类型可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraDigitalFilterRange;

/**
 *  @brief Return to focus mode selectable range.
 *
 *  返回当前相机对焦模式可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraLensFocusModeRange;

/**
 *  @brief Return to auto-focus mode selectable range.
 *
 *  返回当前相机自动对焦模式可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraAFLensFocusModeRange;

/**
 *  @brief Return to the point focus horizontal coordinate selectable range.
 *
 *  返回当前相机点对焦横坐标可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraLensFocusAreaRowIndexRange;

/**
 *  @brief Return to the point focus vertical coordinate selectable range.
 *
 *  返回当前相机点对焦纵坐标可选择范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraLensFocusAreaColIndexRange;

/**
 *  @brief Return to the digital zoom range.
 *
 *  返回当前相机支持的数码变焦范围
 *
 *  @return Dictionary with keys in {"Max", "Min", "Step"} and value is kinds of NSNumber
 */
- (NSDictionary <NSString *, NSNumber *> *)supportedCameraDigitalZoomScaleRange;

/**
 *  @brief Return to the digital zoom range.
 *
 *  返回当前相机支持的数码变焦范围
 *
 *  @return Array of NSNumber.
 */
- (NSArray <NSNumber *> *)supportedCameraDigitalZoomScaleNumberRange;

/**
*  @brief Returns the selectable range of display modes supported by the current camera, only for dual-light cameras.
*
*  返回当前相机支持的显示模式可选择范围，仅针对双光相机
*
*  @return Array of NSNumber.
*/
- (NSArray<NSNumber *> *)supportedCameraDisplayMode;

/**
*  @brief Returns the range of color types supported by the current camera pseudocolor, only for dual-light cameras.
*
*  返回当前相机伪彩支持的颜色类型可选择范围，仅针对双光相机
*
*  @return Array of NSNumber.
*/
- (NSArray<NSNumber *> *)supportedCameraIrColor;


@end
