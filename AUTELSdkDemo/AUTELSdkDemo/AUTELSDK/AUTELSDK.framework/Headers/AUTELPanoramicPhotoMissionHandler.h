//
//  AUTELPanoramicPhotoMissionHandler.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/12/22.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELPanoramicPhotoMission.h>
#import <AUTELSDK/AUTELCameraDef.h>

/**
*  Protocols for Panoramic photo mission are used to start, pause, resume, and exit the mission.
*
*  处理全景摄影任务的协议,用于开始，暂停，恢复,退出任务。
*
*  @see AUTELPanoramicPhotoMissionStatus
*/
@protocol AUTELPanoramicPhotoMissionHandler <AUTELMissionHandler>

/// Set Panoramic photo mission parameters.
/// @param misstion Set the photo type of the panorama photo mission.
/// @param block completion block
- (void)setPanoramicPhotoInfo:(AUTELPanoramicPhotoMission *)misstion withCompletion:(AUTELCompletionBlock)block;




@end


