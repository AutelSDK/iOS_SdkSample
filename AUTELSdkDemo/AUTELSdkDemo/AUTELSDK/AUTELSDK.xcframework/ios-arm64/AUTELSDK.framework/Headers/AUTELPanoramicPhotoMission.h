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
*  Delay Shot Mission status
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
 *  The real-time status of the free time-lapse photography mission. When the aircraft is executing the time-lapse photography mission, the status is updated in real time by the -onNavigationMissionStatusChanged: method of AUTELNavigationDelegate.
 *
 *  自由延时摄影任务实时状态，当飞行器在执行延时摄影任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELPanoramicPhotoMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execute state of the one shot video mission.
 *
 *  延时摄影任务执行状态
 *
 *  @see AUTELMissionExecuteState
 */
@property (nonatomic) AUTELMissionExecuteState execState;

//全景摄影拍摄类型
@property (nonatomic, assign) AUTELPanoramicPhotoType shotType;

/**
*  全景拍照当前状态
*/
@property (nonatomic) AUTELCameraPanoramicPhotoStatus panoramicPhotoStatus;

/**
*  全景拍照当前步数
*/
@property (nonatomic) NSUInteger currentStep;

/**
*  全景拍照总步数
*/
@property (nonatomic) NSUInteger totalStep;

/**
*  全景拍照合成进度
*/
@property (nonatomic) float proportion;

@end

/**
 *  This class includes hot point mission related functions.
 *
 *  延时摄影任务
 
 */

@interface AUTELPanoramicPhotoMission : AUTELMission<NSCopying>

//全景摄影拍摄类型
@property (nonatomic, assign) AUTELPanoramicPhotoType shotType;

//是否保存原图，0-不保存，1-保存
@property (nonatomic, assign) int KeepPhoto;


@property (nonatomic, assign) int missionId;//任务上报ID，APP用于上传下载识别

@property (nonatomic, assign) AUTELMissionType missionType;//任务类型

@end


NS_ASSUME_NONNULL_END



