  //
//  AUTELSDK.h
//  AUTELSDK
//
//  Created by Autel on 15/10/21.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <UIKit/UIKit.h>
//! Project version number for AUTELSDK.
FOUNDATION_EXPORT double AUTELSDKVersionNumber;

//! Project version string for AUTELSDK.
FOUNDATION_EXPORT const unsigned char AUTELSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AUTELSDK/PublicHeader.h>

//飞控
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELError.h>
#import <AUTELSDK/NSError+AUTELSDK.h>
#import <AUTELSDK/AUTELAppManager.h>
#import <AUTELSDK/AUTELAppManager+ClassMethod.h>
#import <AUTELSDK/AUTELMCSystemState.h>
#import <AUTELSDK/AUTELMainControllerDef.h>
#import <AUTELSDK/AUTELDroneMainController.h>
#import <AUTELSDK/AUTELFlightLimitation.h>
#import <AUTELSDK/AUTELBattery.h>
#import <AUTELSDK/AUTELDevice.h>
#import <AUTELSDK/AUTELDrone.h>
#import <AUTELSDK/AUTELDroneGimbal.h>
#import <AUTELSDK/AUTELRemoteController.h>
//RTK Access
#import <AUTELSDK/AUTELRTKModel.h>
#import <AUTELSDK/AUTELRtkStation.h>
#import <AUTELSDK/AUTELRtkStationModel.h>
#import <AUTELSDK/AUTELNtripClient.h>
#import <AUTELSDK/AUTELNtripConfigration.h>

#import <AUTELSDK/AUTELTransferFileModel.h>

//图传
#import <AUTELSDK/AUTELCompass.h>
#import <AUTELSDK/AUTELVisionTypes.h>
#import <AUTELSDK/AUTELFlightAssistant.h>//
#import <AUTELSDK/AUTELVideoFeed.h>//
#import <AUTELSDK/AUTELAirLink.h>
#import <AUTELSDK/AUTELLinkGen2.h>//
#import <AUTELSDK/AUTELLinkModels.h>

//camera
#import <AUTELSDK/AUTELCameraManager.h>
#import <AUTELSDK/AUTELCameraDef.h>//
#import <AUTELSDK/AUTELDSPSignalChannel.h>
#import <AUTELSDK/AUTELGimbal.h>
#import <AUTELSDK/AUTELHandHeld.h>
#import <AUTELSDK/AUTELMedia.h>
#import <AUTELSDK/AUTELPlaybackManager.h>
#import <AUTELSDK/AUTELPlaybackDef.h>
#import <AUTELSDK/AUTELCameraSDCardState.h>
#import <AUTELSDK/AUTELCameraParameters.h>
#import <AUTELSDK/AUTELBaseCamera.h>//
#import <AUTELSDK/AUTELBaseCamera+ToolMethod.h>
#import <AUTELSDK/AUTELCameraExposureParameters.h>
#import <AUTELSDK/AUTELCameraSystemBaseState.h>
#import <AUTELSDK/AUTELSmartTrackDef.h>
#import <AUTELSDK/AUTELIrTemperatureModel.h>
#import <AUTELSDK/AUTELMisstionRecordModel.h>

//misstion
#import <AUTELSDK/AUTELNavigation.h>//
#import <AUTELSDK/AUTELMission.h>
#import <AUTELSDK/AUTELMissionHandler.h>
#import <AUTELSDK/AUTELWaypointMissionHandler.h>
#import <AUTELSDK/AUTELTripodMissionHandler.h>
#import <AUTELSDK/AUTELDelayShotMissionHandler.h>
#import <AUTELSDK/AUTELVisionOrbitMissionHandler.h>
#import <AUTELSDK/AUTELOrbitDelayShotMissionHandler.h>
#import <AUTELSDK/AUTELPanoramicPhotoMissionHandler.h>
#import <AUTELSDK/AUTELWaypointMission.h>
#import <AUTELSDK/AUTELWaypoint.h>
#import <AUTELSDK/AUTELHotPointMission.h>
#import <AUTELSDK/AUTELFollowMeMission.h>
#import <AUTELSDK/AUTELTrackMissionHandler.h>
#import <AUTELSDK/AUTELTrackMission.h>
#import <AUTELSDK/AUTELOrbitMission.h>
#import <AUTELSDK/AUTELOneShotVideoMission.h>
#import <AUTELSDK/AUTELTripodMission.h>
#import <AUTELSDK/AUTELPhotographerMission.h>
#import <AUTELSDK/AUTELDelayShotMission.h>
#import <AUTELSDK/AUTELVisionOrbitMission.h>
#import <AUTELSDK/AUTELOrbitDelayShotMission.h>
#import <AUTELSDK/AUTELPanoramicPhotoMission.h>
#import <AUTELSDK/AUTELWaypointG2.h>
#import <AUTELSDK/AUTELWaypointMC.h>
#import <AUTELSDK/AUTELGen2WaypointMission.h>
#import <AUTELSDK/AUTELMCWaypointMission.h>
#import <AUTELSDK/AUTELViewpointMission.h>
#import <AUTELSDK/AUTELViewpointMissionHandler.h>

#pragma mark 以下接口仅内部使用，不对外发布
//#import <AUTELSDK/AutelVideo.h>

