//
//  AUTELVisionOrbitMission.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/4/25.
//  Copyright © 2020 Autel. All rights reserved.
//

#import "AUTELVisionOrbitMission.h"


NS_ASSUME_NONNULL_BEGIN


/**
 *  This class allowed user get real-time status of one shot video mission. The aircraft follows the coordinate sent by AUTELNavigation.updateUserCoordinate method.
 *
 *  延时摄影任务实时状态，当飞行器在执行一键短片任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELOrbitDelayShotMissionStatus : AUTELMissionProgressStatus

/**
*  @brief Current task status.
*
* 当前环绕延时摄影任务状态
*/
@property (nonatomic) AUTELVisionOrbitModeStatus execStatus;

/**
*  @brief The real-time status of the smart orbit mission.
*
*  智能环绕任务实时状态
*/
@property (nonatomic, strong) AUTELVisionOrbitMissionStatus *visionOrbitMissionStatus;

/**
*  @brief The real-time status of the  time-lapse photography mission.
*
*  延时摄影任务实时状态
*/
@property (nonatomic, strong) AUTELDelayShotMissionStatus *delayShotMissionStatus;


@end

/**
 *  This class includes hot point mission related functions.
 *
 *  延时摄影任务
 
 */

@interface AUTELOrbitDelayShotMission : AUTELVisionOrbitMission<NSCopying>


@end


NS_ASSUME_NONNULL_END



