//
//  AUTELTripodMission.h
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
 *  This class allowed user get real-time status of one shot video mission. The aircraft follows the coordinate sent by AUTELNavigation.updateUserCoordinate method.
 *
 *  一键短片飞行任务实时状态，当飞行器在执行一键短片任务时，该状态由 AUTELNavigationDelegate 的 -onNavigationMissionStatusChanged: 方法实时更新。
 *
 */
@interface AUTELPhotographerMissionStatus : AUTELMissionProgressStatus

/**
 *  @brief Returns the current execute state of the one shot video mission.
 *
 *  一键短片任务执行状态
 *
 *  @see AUTELMissionExecuteState
 */
@property (nonatomic, readonly) AUTELMissionExecuteState execState;

@end

/**
 *  This class includes hot point mission related functions.
 *
 *  一键短片任务
 
 */

@interface AUTELPhotographerMission : AUTELMission<NSCopying>

@end


NS_ASSUME_NONNULL_END



