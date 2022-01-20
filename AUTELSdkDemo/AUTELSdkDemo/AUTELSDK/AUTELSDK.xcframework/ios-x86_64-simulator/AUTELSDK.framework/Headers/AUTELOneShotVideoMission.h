//
//  AUTELOneShotVideoMission.h
//  AUTELSDK
//
//  Created by zhiganglet on 2019/7/25.
//  Copyright © 2019 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AUTELSDK/AUTELFoundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELNavigation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 *  State of the one shot video task
 *
 *  一键短片的类型
 */
typedef NS_ENUM(uint8_t, AUTELOneShotVideoType) {
    /**
     *  @brief 360 shoot
     *
     *  360°拍摄
     */
    AUTELOneShotVideoType360Shoot = 0,
    
    /**
     *  @brief Epic
     *
     *  远景镜头
     */
    AUTELOneShotVideoTypeEpic = 1,
    
    /**
     *  @brief Rise
     *
     *  上升镜头
     */
    AUTELOneShotVideoTypeRise = 2,
    
    /**
     *  @brief Fadeaway
     *
     *  渐远拍摄
     */
    AUTELOneShotVideoTypeFadeaway = 3,
    
    /**
     *  @brief Intosky
     *
     *  冲天追踪
     */
    AUTELOneShotVideoTypeIntosky = 4,
    
    /**
     *  @brief Boomerang
     *
     *  回旋镖
     */
    AUTELOneShotVideoTypeBoomerang = 5,
    
    /**
     *  @brief Screw
     *
     *  螺旋拍摄
     */
    AUTELOneShotVideoTypeScrew = 6,
    
    /**
     *  @brief Parabola
     *
     *  抛物线
     */
    AUTELOneShotVideoTypeParabola = 7,
    
    /**
     *  @brief Asteroid
     *
     *  小行星
     */
    AUTELOneShotVideoTypeAsteroid = 8,
    
    /**
     *  @brief Circle Round
     *
     *  环绕追踪
     */
    AUTELOneShotVideoTypeCircleRound = 9,
};


/**
 *  This class allowed user get real-time status of one shot video mission. The aircraft follows the coordinate sent by AUTELNavigation.updateUserCoordinate method.
 *
 *  一键短片飞行任务实时状态，当飞行器在执行一键短片任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELOneShotVideoMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execute state of the one shot video mission.
 *
 *  一键短片任务执行状态
 *
 *  @see AUTELHotpointMissionExecuteState
 */
@property (nonatomic, readonly) AUTELMissionExecuteState execState;

@end

/**
 *  This class includes hot point mission related functions.
 *
 *  一键短片任务
 
 */

@interface AUTELOneShotVideoMission : AUTELMission<NSCopying>

/**
 *  @brief Set the mode after mission finished.
 *
 *  任务结束模式，默认 AUTELNavigationMissionFinishModeGoHome。
 *
 *  @discussion If finishMode equals to AUTELNavigationMissionFinishModeGoHome, then the aircraft will fly back to the home point after mission completed.
 *  If finishMode equals to AUTELNavigationMissionFinishModeGoHotPoint, then the aircraft will fly to the hot point after mission completed.
 *  If finishMode equals AUTELNavigationMissionFinishModeHover, then the aircraft will hover in the air after mission completed.
 *
 *  如果 finishMode 等于 AUTELNavigationMissionFinishModeGoHome，飞行器执行完该任务后，会自动返航。
 *  如果 finishMode 等于 AUTELNavigationMissionFinishModeGoHotPoint，飞行器在完成该任务后，会自动飞行到兴趣点上方。
 *  如果 finishMode 等于 AUTELNavigationMissionFinishModeHover，飞行器在完成任务后原地悬停。
 *
 *  @see AUTELNavigationMissionFinishMode
 *  @see AUTELMissionHandler
 */
@property (nonatomic) AUTELNavigationMissionFinishMode finishMode;

@property (nonatomic) AUTELOneShotVideoType videoType;

@end


NS_ASSUME_NONNULL_END



