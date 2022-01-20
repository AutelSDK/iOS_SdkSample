//
//  AUTELOrbitDelayShotMissionHandler.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/12/09.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AUTELSDK/AUTELVisionOrbitMissionHandler.h>
#import <AUTELSDK/AUTELDelayShotMissionHandler.h>
//#import <AUTELSDK/AUTELCameraDef.h>

@protocol AUTELOrbitDelayShotMissionHandler <NSObject, AUTELVisionOrbitMissionHandler, AUTELDelayShotMissionHandler>

- (void)startCameraDelayShotWithCompletion:(AUTELCompletionBlock)block;


@end


