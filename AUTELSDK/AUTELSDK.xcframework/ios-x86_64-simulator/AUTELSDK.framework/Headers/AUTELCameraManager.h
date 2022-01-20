//
//  AUTELCameraManager.h
//  AUTELSDK
//
//  Created by Autel on 15/10/28.
//  Copyright © 2015年 Autel. All rights reserved.
//

//#import <AUTELSDK/AUTELSDK.h>
#import "AUTELCameraSettingsDef.h"
#import "AUTELCameraSystemState.h"
#import "AUTELCameraObject.h"
#import "AUTELCamera.h"
#import "AUTELDevice.h"

//  连接类型
typedef NS_ENUM(NSInteger, AUTELCameraManagerConnectType) {
    AUTELCameraManagerConnectTypeUnknown = 0,
    AUTELCameraManagerConnectTypeTCP,
    AUTELCameraManagerConnectTypeHTTP,
};

//  连接状态
typedef NS_ENUM(NSInteger, AUTELCameraManagerConnectState) {
    AUTELCameraManagerConnectStateDisconnect = 0,
    AUTELCameraManagerConnectStateConnecting,
    AUTELCameraManagerConnectStateConnected,
};



@class MessageQueueNote;

@protocol AutelcameraManagerDelegate <NSObject>

@optional

- (void)autelCameraConnected:(AUTELCameraStreamConnectState)state;
- (void)autelCameraDisconnect;

- (BOOL)streamReconnectShouldAttemptAutoReconnect;
- (NSTimeInterval)streamReconnectTimeDelay;
@end

/**
*  @warning    __deprecated
*/
@interface AUTELCameraManager : NSObject
@property (nonatomic, weak) id<AutelcameraManagerDelegate> delegate;
@property (nonatomic, strong) AUTELCamera *camera;
@property (nonatomic, strong) NSNumber *cameraTpye;

@property (nonatomic) AUTELCameraManagerConnectType connectType;
@property (nonatomic) AUTELCameraManagerConnectState currentConnectState;           //  当前连接状态（！！！未用到）

//kvo 监听相机连接状态和相机录像状态，（这三个供给飞行记录用）
@property(nonatomic, retain) NSString *connectState;
@property(nonatomic, retain) NSString *cameraState;
@property(nonatomic, retain) NSString *cameraSnapFilePath;

//- (AUTELCamera *)createCamera;
- (BOOL)isCameraConnected;
+ (instancetype)shareInstance;
- (void)startAllCameraConnect;
- (void)closeAllCameraConnect;
- (void)sendHistoStart;
//  调用此方法，传递设备类型
- (void)ConnectedDeviceChanged:(AUTELDevice*)device
                      withtype:(AUTELDeviceType)type;
- (AUTELDeviceType)currentCameraType;
@end
