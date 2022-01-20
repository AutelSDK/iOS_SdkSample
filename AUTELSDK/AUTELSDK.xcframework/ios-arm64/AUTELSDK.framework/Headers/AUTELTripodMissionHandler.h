//
//  AUTELTripodMissionHandler.h
//  AUTELSDK
//
//  Created by zhiganglet on 2019/7/29.
//  Copyright © 2019 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELTripodMission.h>

/**
*  Protocols for precision flight mission are used to download, perform, stop, and pause mission.
*
*  处理精准飞行任务的协议,用于下载,上传,执行,停止精准飞行任务。
*
*  @see AUTELTripodMission
*/
@protocol AUTELTripodMissionHandler <AUTELMissionHandler>


/// Set precise flight mission parameters.
/// @param misstion Set the task parameter model, including horizontal speed, vertical speed and angular speed.
/// @param block completion block
- (void)setTripodInfo:(AUTELTripodMission *)misstion withCompletion:(AUTELCompletionBlock)block;

@end




