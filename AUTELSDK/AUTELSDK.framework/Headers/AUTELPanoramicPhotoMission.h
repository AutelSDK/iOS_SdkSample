//
//  AUTELPanoramicPhotoMission.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/12/22.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AUTELSDK/AUTELFoundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELNavigation.h>



/**
 *  Types of panoramic photography
 *
 *  全景摄影拍摄类型
 */
typedef NS_ENUM(uint8_t, AUTELPanoramicPhotoType ) {
    /**
     *  @brief horizontal shot
     *
     *  横拍
     */
    AUTELPanoramicPhotoTypeHorizontal,
    
    /**
     *  @brief vertical shot
     *
     *  竖拍
     */
    AUTELPanoramicPhotoTypeVertical,
    
    /**
     *  @brief wide angle shot
     *
     *  广角拍
     */
    AUTELPanoramicPhotoTypeWideAngle,
    
    /**
     *  @brief spherical shot
     *
     *  球形全景
     */
    AUTELPanoramicPhotoTypeSpherical,
    
};

/**
*  Panorama photo current status
*
*  全景拍照当前状态
*/
typedef NS_ENUM(uint8_t, AUTELCameraPanoramicPhotoStatus ) {
    /**
    *  @brief Stop
    *
    *  停止状态
    */
    AUTELCameraPanoramicPhotoStatusStop = 0,
    
    /**
    *  @brief Taking Photo
    *
    *  拍照中
    */
    AUTELCameraPanoramicPhotoStatusTakingPhoto = 1,
    
    /**
    *  @brief Stitching Photo
    *
    *  拼接中
    */
    AUTELCameraPanoramicPhotoStatusStitching = 2,
    
    /**
    *  @brief Pause
    *
    *  暂停
    */
    AUTELCameraPanoramicPhotoStatusPause = 10,
    
};
     
NS_ASSUME_NONNULL_BEGIN


/**
 *  The real-time status of the Panorama photo mission. When the aircraft is executing the Panorama photo mission, the status is updated in real time by the -onNavigationMissionStatusChanged: method of AUTELNavigationDelegate.
 *
 *  全景拍照任务实时状态，当飞行器在执行全景拍照任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELPanoramicPhotoMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execute state of the panorama photo mission.
 *
 *  全景拍照任务执行状态
 *
 *  @see AUTELMissionExecuteState
 */
@property (nonatomic) AUTELMissionExecuteState execState;

/**
*  @brief Panoramic photo shooting type.
*
*  全景拍照拍摄类型。
*/
@property (nonatomic, assign) AUTELPanoramicPhotoType shotType;

/**
*  @brief for the current status of panoramic photography, see the definition of enumeration AUTELCameraPanoramicPhotoStatus
*
*  全景拍照当前状态
*/
@property (nonatomic) AUTELCameraPanoramicPhotoStatus panoramicPhotoStatus;

/**
*  @brief Panorama photo current steps
*
*  全景拍照当前步数
*/
@property (nonatomic) NSUInteger currentStep;

/**
*  @brief The total number of steps for panoramic photos
*
*  全景拍照总步数
*/
@property (nonatomic) NSUInteger totalStep;

/**
*  @brief Panorama photo synthesis progress
*
*  全景拍照合成进度
*/
@property (nonatomic) float proportion;

@end

/**
 *  This class includes Panorama photo mission related functions.
 *
 *  全景拍照任务封装数据模型，用于这种全景拍照拍摄类型和上传任务数据
 */
@interface AUTELPanoramicPhotoMission : AUTELMission<NSCopying>

/**
*  @brief Panoramic photo shooting type.
*
*  全景拍照拍摄类型。
*/
@property (nonatomic, assign) AUTELPanoramicPhotoType shotType;

/**
*  @brief Whether to save the original image, 0-do not save, 1-save.
*
*  是否保存原图，0-不保存，1-保存。
*/
@property (nonatomic, assign) int KeepPhoto;

/**
*  @brief The task report ID is used by the APP for upload and download identification.
*
*  任务上报ID，APP用于上传下载识别。
*/
@property (nonatomic, assign) int missionId;

/**
*  @brief mission type, see enumeration AUTELMissionType definition
*
*  任务类型
*/
@property (nonatomic, assign) AUTELMissionType missionType;

@end


NS_ASSUME_NONNULL_END



