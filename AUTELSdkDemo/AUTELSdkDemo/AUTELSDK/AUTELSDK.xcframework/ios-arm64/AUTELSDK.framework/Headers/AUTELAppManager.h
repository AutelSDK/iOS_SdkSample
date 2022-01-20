//
//  AUTELAppManager.h
//  AUTELSDK
//
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELLinkGen2.h>
#import <AUTELSDK/AUTELMainControllerDef.h>


@class AUTELDevice;

@interface AUTELDeviceFirmwareUpdateState: NSObject

@property (nonatomic, assign) BOOL isUpgrading;
@property (nonatomic, assign) float progress;
@property (nonatomic, assign) BOOL isRemoterControllerLowBattery;
@property (nonatomic, assign) BOOL isAircraftLowBattery;
@property (nonatomic, assign) BOOL isAircrafrArmed;
@property (nonatomic, assign) AUTELFirmwareUploadingStatue uploadingState;
@property (nonatomic, assign) BOOL isNoSDCard;

@end

/**
 *  Provides call back methods of connecting or switching to new device.
 *
 *  该协议提供了新设备连接或设备切换的回调方法。
 */
@protocol AUTELAppManagerDelegate <NSObject>

@required
/**
 *  @brief Call back method of app registration.
 *
 *  注册结果回调，当注册成功或者失败，该回调方法被调用
 *  
 *  @param error If registration succeeded, retuns nil. Else returns error message.
 *
 *  如果注册成功，该值为nil，否则返回错误信息
 */
- (void)appManagerDidRegisterWithError:(NSError *_Nullable)error;

@optional
/**
 *  @brief Call back this method when connect to a new device or switch to another device.
 *
 *  当有设备连接上，或连接设备发生了切换，该回调方法会被调用。
 *
 *  @param newDevice The new drone object that connected.
 *
 *  与 App 连接的新设备。
 *
 */
- (void)appManagerDidConnectedDeviceChanged:(AUTELDevice*_Nonnull)newDevice;


///  Call back method of firmware update.
/// @param state see AUTELDeviceFirmwareUpdateState
- (void)didFirmwareUpdateState:(AUTELDeviceFirmwareUpdateState *_Nonnull)state;

- (void)didUpdataLinkState:(AUTELLinkGen2State *_Nonnull)linkState;

@end

/**
 *This class provides methods which registers the app. If registration succeeded, returns current connected device object.
 *
 * 通过该类注册你的 App，如果注册成功，你可以通过该类获得当前与 App 连接的设备。
 */
@interface AUTELAppManager : NSObject {
    BOOL _runned;   //是否启动过
    BOOL _inBackground; //是否在后台；
}

/// 当前接入图传类型
@property (assign, nonatomic, readonly) AUTELAirLinkType airLinkType;

@property (nonatomic) BOOL runned;
@property (nonatomic) BOOL inBackground;

+ (AUTELAppManager *_Nonnull)share;

/**
 *  @brief Returns current connected device. 
 *
 *  返回当前连接的设备。
 *
 *  @return Returns current connected device object or return nil if no connected device.
 *
 *  返回当前 App 连接的设备，如果没有连接设备，返回 nil。
 *
 *  @see AUTELDevice
 */
+ (AUTELDevice*_Nullable)connectedDevice;

/**
 *  @brief Invoke this function first to register app every time after launch the app. Internet connection is required for first time registration. Once registration succeeded, app will auto connect to the device.
 *
 *  注册 App。每次启动 App 用户应该首先调用一次该方法，且在第一次调用该方法时需要连接互联网。当 App 注册成功后会自动判断是否有设备连接上。
 *
 *  @param appKey   App key that applied from AUTEL's developer website. 
 *
 *  从 AUTEL 的开发网站上获取到的 App key。
 *
 *  @param delegate Register result callback. 
 *
 *  注册结果回调
 *
 *  @see AUTELAppManagerDelegate
 */
+ (void)registerApp:(NSString*_Nonnull)appKey withDelegate:(id<AUTELAppManagerDelegate>_Nonnull)delegate;


/// get firmware version of all modules
/// @param block the block firsr parameter  is an array whose elements are dictionaries, corresponding to the version information of each module
+ (void)getFirmwareVersionWithCompletion:(void (^_Nullable)(NSArray<NSDictionary*>*_Nullable firmwareInfo, NSError * _Nullable error))block;




@end


@interface AUTELAppManager (Test)

+ (void)testWaypointUpload;

+ (void)testWaypointdDownload;

@end
