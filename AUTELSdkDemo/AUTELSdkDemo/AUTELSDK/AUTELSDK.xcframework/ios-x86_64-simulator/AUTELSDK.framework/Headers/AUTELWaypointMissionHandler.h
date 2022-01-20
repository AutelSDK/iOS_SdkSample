//
//  AUTELTripodMissionHandler.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/4/27.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELWaypointMission.h>

/**
*  Protocols for waypoint mission are used to download, perform, stop, and pause mission.
*
*  处理航点任务的协议,用于下载,上传,执行,停止,暂停任务。
*
*  @see AUTELWaypointMission
*/
@protocol AUTELWaypointMissionHandler <NSObject, AUTELMissionHandler>

/**
*  @brief Stops the current mission. The aircraft will hover in place.
*
*  取消当前飞行任务，无人机悬停在当前位置
*
*  @param completion Completion block.
*
*  命令结束回调
*/
- (void)stopMissionExecution:(WaypointMissionFinishAction)finishAction WithCompletion:(AUTELCompletionBlock)completion;


@end



