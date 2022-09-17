//
//  AUTELDelayShotMissionHandler.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/4/25.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELDelayShotMission.h>
#import <AUTELSDK/AUTELCameraDef.h>

/**
*  Protocols for delay shot mission are used to start, pause, resume, and exit the mission.
*
*  处理延时摄影任务的协议,用于开始，暂停，恢复,退出任务。
*
*  @see AUTELDelayShotMissionStatus
*/
@protocol AUTELDelayShotMissionHandler <AUTELMissionHandler>

/// Set delay shot mission parameters.
/// @param misstion Set the task parameter model, including horizontal speed, vertical speed and angular speed.
/// @param block completion block
- (void)setDelayShotInfo:(AUTELDelayShotMission *)misstion withCompletion:(AUTELCompletionBlock)block;

/**
 * Set the duration of the mobile time-lapse photography task
 *
 * 设置移动延时摄影任务的拍照时长
 *
 * @param duration 持续时间
 * @param block completion block
 */
- (void)setCameraMotionDelayShotDuration:(NSUInteger)duration withCompletion:(AUTELCompletionBlock)block;

/**
* Get the duration of the mobile time-lapse photography task
*
* 获取移动延时摄影任务的拍照时长
*
* @param duration 持续时间
* @param block completion block
*/
- (void)getCameraMotionDelayShotDurationWithCompletion:(void(^)(NSUInteger duration, NSError *error))block;

/**
 * Set the interval for mobile time-lapse photography tasks
 *
 * 设置移动延时摄影任务的拍照间隙
 *
 * @param interval 拍照间隙
 */
- (void)setCameraMotionDelayShotInterval:(NSUInteger)interval withCompletion:(AUTELCompletionBlock)block;

/**
* Get the interval for mobile time-lapse photography tasks
*
* 获取移动延时摄影任务的拍照间隙
*
* @param interval 拍照间隙
*/
- (void)getCameraMotionDelayShotIntervalWithCompletion:(void(^)(NSUInteger interval, NSError *error))block;

/**
 * Set mobile time-lapse photography to save photo format
 *
 * 设置移动延时摄影保存照片格式
 */
- (void)setCameraDelayShotKeepPhoto:(AUTELCameraDelayShotPhotoFormat)photoFormat withCompletion:(AUTELCompletionBlock)block;

/**
* Get mobile time-lapse photography to save photo format
*
* 获取移动延时摄影保存照片格式
*/
- (void)getCameraDelayShotKeepPhotoWithCompletion:(void(^)(AUTELCameraDelayShotPhotoFormat photoFormat, NSError *error))block;


@end


