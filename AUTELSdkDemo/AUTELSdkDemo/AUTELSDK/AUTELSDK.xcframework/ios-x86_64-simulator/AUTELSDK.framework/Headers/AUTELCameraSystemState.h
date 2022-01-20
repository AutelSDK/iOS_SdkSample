//
//  AUTELCameraSystemState.h
//  AUTELSDK
//
//  Created by Autel on 15/10/22.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELCameraSettingsDef.h"

@interface AUTELCameraSystemState : NSObject
/**
 *  Show the camera is taking RAW capture or JPEG capture.
 */
@property(nonatomic, readonly) BOOL isTakingRawCapture;

/**
 *  The camera is taking continuous capture.
 */
@property(nonatomic, readonly) BOOL isTakingContinusCapture;

/**
 *  The camera is taking multi capture.
 */
@property(nonatomic, readonly) BOOL isTakingMultiCapture;

/**
 *  The camera is taking single capture.
 */
@property(nonatomic, readonly) BOOL isTakingSingleCapture;

/**
 *  Whether the camera's time has synced.
 */
@property(nonatomic, readonly) BOOL isTimeSynced;

/**
 *  Whether the camera is in recording.
 */
@property(nonatomic, readonly) BOOL isRecording;

/**
 *  The camera is over heated.
 */
@property(nonatomic, readonly) BOOL isCameraOverHeated;

/**
 *  The camera's sensor error.
 */
@property(nonatomic, readonly) BOOL isCameraSensorError;

/**
 *  Invalid operation.
 */
@property(nonatomic, readonly) BOOL isInvalidOperation;

/**
 *  The camera has serious error.
 */
@property(nonatomic, readonly) BOOL isSeriousError;

/**
 *  Indicate whether the SD card exists in the camera.
 */
@property(nonatomic, readonly) BOOL isSDCardExist;

/**
 *  Indicate whether the camera is in usb mode.
 */
@property(nonatomic, readonly) BOOL isUSBMode;

/**
 *  Indicate whether the camera is connected to PC.
 */
@property(nonatomic, readonly) BOOL isConnectedToPC;

/**
 *  Current work mode of camera. Property is available in Inspire/Phantom3 professional
 */
@property(nonatomic, readonly) CameraWorkMode workMode;

/**
 *  Current recording time of camera. Property is available in Inspire/Phantom3 professional
 */
@property(nonatomic, readonly) int currentRecordingTime;

@end

@interface AUTELCameraSystemNotice : NSObject

@property(nonatomic, readonly, retain) NSString *noticeType;
@property(nonatomic, readonly, retain) NSString *paramType;
@property(nonatomic, readonly, retain) NSString *param;

- (id)initWithResponseNSDictionary:(NSDictionary *)responseDict;
@end
