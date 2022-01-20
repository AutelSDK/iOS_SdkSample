//
//  AUTELCameraExposureParameters.h
//  AUTELSDK
//
//  Created by 虢蔚翔 on 16/8/16.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELCameraDef.h>

/*********************************************************************************/
#pragma mark - AUTELCameraExposureParameters
/*********************************************************************************/

/**
 *  This class contains current values for some camera parameters related to exposure, which determines how sensitive the picture is to light and depends on the balance of the ISO value, the shutter speed, and the aperture value. When the camera is in different exposure modes, different parameters are automatically changed by the camera to either get the correct exposure (in Auto and Aperture Priority modes), or report back the current exposure (in Manual mode). The current values of these parameters used by the camera are contained in this class.
 *
 *  该类包含和相机曝光模式相关的几个参数值。ISO 值、快门速度和光圈值决定了图片对光的敏感程度。当相机在不同的曝光模式时，相机会自动调整到正确的曝光参数(在自动曝光、光圈优先模式下)，或者返回当前的曝光参数值(在手动曝光模式下)。这些相机使用到的曝光参数都包含在该类中。
 */

@interface AUTELCameraExposureParameters : NSObject

/**
 *  @brief Camera aperture value. A larger aperture results in a higher exposure and shallower depth of field.
 *
 *  相机光圈值。光圈值越大曝光量越大，景深越浅。
 *
 *  @see AUTELCameraAperture
 */
@property(nonatomic, readonly) AUTELCameraAperture aperture;

/**
 *  @brief Camera shutter speed. A slower shutter speed results in a higher exposure, but more blurring in areas of the scene that are moving.
 *
 *  相机快门速度。快门速度越慢曝光量越大，但是会导致移动场景中更多的模糊区域。
 *
 *  @see AUTELCameraShutterSpeed
 */
@property(nonatomic, readonly) AUTELCameraShutterSpeed shutterSpeed;

/**
 *  @brief Camera ISO. A higher ISO results in a higher exposure, and more noise in the resulting image.
 *
 *  相机ISO值。ISO值越高，曝光量越大，图片中的的噪点也会更多
 *
 *  @see AUTELCameraISO
 */
@property(nonatomic, readonly) AUTELCameraISO iso;

/**
 *  @brief Camera exposure compensation.The range of exposure compensation reported by the camera is -3.0 EV to 3.0 EV.
 *
 *  相机曝光补偿值。范围[-3ev,3ev]。
 *
 *  @see AUTELCameraExposureCompensation
 */
@property(nonatomic, readonly) AUTELCameraExposureCompensation exposureCompensation;

@end

