//
//  AUTELLinkGen2.h
//  AUTELSDK
//
//  Created by IOS on 2017/11/23.
//  Copyright © 2017年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELLinkModels.h"

/**
 *   frequency band for airlink
 *
 *   图传频率带
 */
typedef NS_ENUM(NSInteger, AUTELLinkGen2FrequencyBand) {
    /**
    * Auto 2400MHz_900MHz
    */
    AUTELLinkGen2FrequencyBand2400MHz_900MHz = 0,
    /**
    * Auto 2400MHz_5800MHz
    */
    AUTELLinkGen2FrequencyBand2400MHz_5800MHz,
    /**
    * 2.4G
    **/
    AUTELLinkGen2FrequencyBand2400MHz,
    /**
    * 5.7G
    **/
    AUTELLinkGen2FrequencyBand5700MHz,
    /**
    * 5.8G
    **/
    AUTELLinkGen2FrequencyBand5800MHz,
    /**
    * 900M
    **/
    AUTELLinkGen2FrequencyBand900MHz,
    /**
    * 1.4G
    **/
    AUTELLinkGen2FrequencyBand1400MHz,
    
    /**
    * unknown
    **/
    AUTELLinkGen2FrequencyBandUnknown = -1,
};

/**
 *   The specified frequency bandwidth
 *
 *   指定的带宽
 */
typedef NS_ENUM(NSInteger, AUTELLinkGen2Bandwidth) {
    /**
    *20 MHz
    **/
    AUTELLinkGen2Bandwidth20MHz = 0,
    /**
    * 10 MHz
    **/
    AUTELLinkGen2Bandwidth10MHz,
    /**
    * 5 MHz
    **/
    AUTELLinkGen2Bandwidth5MHz,
    /**
    * 3 MHz
    **/
    AUTELLinkGen2Bandwidth3MHz,
    /**
    * unknown
    **/
    AUTELLinkGen2BandwidthUnknown = -1,
};

/**
 *   Master-slave State
 *
 *   飞行器主从状态
 */
typedef NS_ENUM(NSInteger,AUTELAirLinkMainMasterSlaveState) {
    ///非主从机模式
    AUTELAirLinkMainMasterSlaveStateNormal = 0,                 //非主从机模式
    ///主机模式
    AUTELAirLinkMainMasterSlaveStateOnlyMastOn,                 //主机模式
    ///从机控制状态
    AUTELAirLinkMainMasterSlaveStateOnlySlaveOn,                //从机控制状态
    ///主从都打开
    AUTELAirLinkMainMasterSlaveStateAllOn,                      //主从都打开
    ///主从都关闭
    AUTELAirLinkMainMasterSlaveStateAllOff,                     //主从都关闭
    ///Unknown
    AUTELAirLinkMainMasterSlaveStateUnknown = -1,
};

/// Master-slave role
typedef NS_ENUM(NSInteger, AUTELLinkGen2Role) {
    ///主机模式
    AUTELLinkGen2RoleMaster,
    ///从机模式
    AUTELLinkGen2RoleSlave,
    ///普通模式
    AUTELLinkGen2RoleNone = -1,                                 //普通模式
};

/**
 *   Master-slave penetrate action
 *
 *   主从机图传透传Action，消息ID：AU_CTRL_MSG_APP_PASSBY_MSG
 */
typedef NS_ENUM(NSInteger, AUTELAirLinkAction) {
    ///Draw Start
    AUTELAirLinkActionDrawStart,
    ///Tracking Start
    AUTELAirLinkActionTrackingStart,
    ///Enter
    AUTELAirLinkActionEnter,
    ///Exit
    AUTELAirLinkActionExit,
};

/**
 *   Master-slave penetrate params
 *
 *   主从机图传透传Params
 */
typedef NS_ENUM(NSInteger, AUTELAirLinkParamsMode) {
    ///Tracking
    AUTELAirLinkParamsModeTracking = 1,
    ///ViewPoint
    AUTELAirLinkParamsModeViewPoint = 2,
    ///Album
    AUTELAirLinkParamsModeAlbum = 3,
};

/**
 *   Video transmission mode
 *
 *   视频传输模式
 */
typedef NS_ENUM(NSInteger, AUTELLinkVideoTransmissionMode) {
    ///Normal
    AUTELLinkVideoModeTransmissionNormal,
    ///High Quality
    AUTELLinkVideoModeTransmissionHighQuality,
    ///Low Latency
    AUTELLinkVideoModeTransmissionLowLatency,
    ///Unknown
    AUTELLinkVideoModeTransmissionUnknown = -1,
};

/**
 *   Firmware update status
 *
 *   固件更新状态
 */
typedef NS_ENUM(NSInteger, AUTELFirmwareUpdateStatue) {
    AUTELFirmwareUpdateStatueNoUpdate = 0,
    AUTELFirmwareUpdateStatueDowloading = 1,
    AUTELFirmwareUpdateStatueUpgrading = 2,
    AUTELFirmwareUpdateStatueSuceess = 3,
    AUTELFirmwareUpdateStatueFailed = 4,
    AUTELFirmwareUpdateStatueUnknown = -1
};

/**
 *   Firmware uploading status
 *
 *   固件上传状态
 */
typedef NS_ENUM(NSInteger, AUTELFirmwareUploadingStatue) {
    AUTELFirmwareUploadingStatueNoUpload = 0,
    AUTELFirmwareUploadingStatueIsUploading = 1,
    AUTELFirmwareUploadingStatueSuccess = 2,
    AUTELFirmwareUploadingStatueFailed = 3,
    AUTELFirmwareUploadingStatueUnknown = -1
};

typedef NS_ENUM(int, AUTELFirmwareUpdateTyp) {
    ///Upgrade
    AUTELFirmwareUpdateTypUpgrade = 0,
    ///Degrade
    AUTELFirmwareUpdateTypDegrade = 1
};


/**
 *   Remote control type
 *
 *   遥控器型号 -1—无效， 0—老EVO, 1—新EVO外观+Modelc软件，2—EVO2 遥控,  3 --- 黑盒子, 4--酷芯遥控器
 */
typedef NS_ENUM(NSInteger, AUTELAirLinkRCType) {
    ///无效
    AUTELAirLinkRCTypeInvalid = -1,
    ///老EVO,
    AUTELAirLinkRCTypeEVO1 = 0,
    ///新EVO外观+Modelc软件
    AUTELAirLinkRCTypeEVO2 = 1,
    ///无效
    AUTELAirLinkRCTypeEVO2RC = 2,
    ///EVO2 遥控,
    AUTELAirLinkRCTypeLiveDeck = 3,
    ///酷芯遥控器
    AUTELAirLinkRCTypeWimaxRC = 4
};

typedef NS_ENUM(NSInteger, AUTELAirLinkDistrict) {
    ///非北美地区
    AUTELAirLinkDistrictNormal = 0,
    ///北美地区
    AUTELAirLinkDistrictAmerica = 1,
    ///日本地区
    AUTELAirLinkDistrictJa = 2
};



/**
 *  @brief Store the information of each channel
 *
 *  定义 AUTELAirLinkChannelInfo 类,存储图传每个信道的信息
 */
@interface AUTELAirLinkChannelInfo: NSObject<NSCopying>

/**
 *  @brief Channel interference value, unit mdB
 *
 *  信道干扰值,单位 mdB
 */
@property (nonatomic, assign) NSInteger power;

/**
 *  @brief frequency
 *
 *  频率
 */
@property (nonatomic, assign) NSInteger frequencyInMHz;

/**
 *  @brief channel
 *
 *  信道号
 */
@property (nonatomic, assign) NSInteger channel;

@end

/**
 *  Define the second generation airlink status
 *
 *  @brief 定义二代图传状态
 */
@interface AUTELLinkGen2State: NSObject<NSCopying>

/**
 *  Information for all channels
 *
 *  @brief 所有信道的信息
 */
@property (nonatomic, copy) NSDictionary<NSString *, NSArray<AUTELAirLinkChannelInfo *>*> * _Nonnull channels;

/**
 *  Current channel
 *
 *  @brief 当前信道
 */
@property (nonatomic, assign) NSInteger currentChannel;

@property (nonatomic, copy) NSString * _Nullable currentChannelKey;

@property (nonatomic, assign) AUTELLinkGen2FrequencyBand frequencyBand;

@property (nonatomic, assign) AUTELLinkGen2Bandwidth bandwidth;

@property (nonatomic, assign) AUTELAirLinkMainMasterSlaveState mastSlaveState;

@property (nonatomic, assign) AUTELLinkGen2Role role;

///地区，0 --- 非北美地区， 1--- 北美地区，2--日本（5.7G频段）
@property (nonatomic, assign) AUTELAirLinkDistrict district;
///是否可设置频道，0：不可设置，1：可设置
@property (nonatomic, assign) int disableSetBandMode;
///RCType: 遥控器型号， -1—无效， 0—老EVO, 1—新EVO外观+Modelc软件，2—Modelc遥控,  3 --- 黑盒子, 4--酷芯遥控器
@property (nonatomic, assign) AUTELAirLinkRCType rcType;
//是否支持5.8G
@property (nonatomic, assign) int support5_8G;

@end

typedef void (^AUTELUploadFirmwareProgressHandler)(NSUInteger progress);

@class AUTELLinkGen2;

@protocol  AUTELLinkGen2Delegate<NSObject>

@optional

/**
 Update airlink State

 @param link the second generation airlink object
 @param linkState  the second generation airlink status
 */
- (void)linkGen2:(AUTELLinkGen2 *_Nonnull)link updataLinkState:(AUTELLinkGen2State *_Nonnull)linkState;

/**
 Update Remote control pairing status

 @param link the second generation airlink object
 @param pairingState  Remote control pairing status
 */
- (void)linkGen2:(AUTELLinkGen2 *_Nonnull)link updataRCPairingState:(RemoteControlPairingState *_Nonnull)pairingState;

@end

@class AUTELAirLink;

/**
 The second generation airlink object
 */
@interface AUTELLinkGen2 : NSObject

@property (nonatomic, weak) id<AUTELLinkGen2Delegate> _Nullable delegate;

@property (nonatomic, weak) AUTELAirLink * _Nullable airLink;

/**
 @brief Set the frequency band to the specified value
 将图传频率带设置为指定的值

 @param frenquencyBand Specified frequency band
 @param block completion block
 */
- (void)setFrequencyBand:(AUTELLinkGen2FrequencyBand)frenquencyBand withCompletion:(AUTELCompletionBlock)block;

/**
 @brief Set the bandwidth to the specified value
 将图传带宽设置为指定值
 
 @param bandwidth Specified bandwidth
 @param block completion block
 */
- (void)setBandwidth:(AUTELLinkGen2Bandwidth)bandwidth withCompletion:(AUTELCompletionBlock)block;

/**
 @brief  Synchronizing behavior in Tarcking/ViewPoint/Album mode
 同步Tarcking/ViewPoint/Album模式下的行为

 @param action action
 @param mode mode
 */
- (void)synchronizingAction:(AUTELAirLinkAction)action withMode:(AUTELAirLinkParamsMode)mode;

/**
 *  @brief  Query real-time video enable
 *  查询实时视频使能
 *
 *  @param block completed block, If the current airlink is sent live video enable is YES, otherwise NO. 如果当前图传发送了实时视频 enable 为 YES, 否则为 NO
 *
 *  @see AUTELLinkGen2Bandwidth
 */
- (void)getVideoPlayEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError * _Nullable error))block;

/**
 *  @brief  set real-time video enable
 *  设置实时视频使能
 *
 *  @param block completed block, If the current airlink is sent live video enable is YES, otherwise NO. 如果当前图传发送了实时视频 enable 为 YES, 否则为 NO
 *
 *  @see AUTELLinkGen2Bandwidth
 */
- (void)setVideoPlayEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 Get video transmission mode With completion

 @param block Video transmission mode & error
 */
- (void)getVideoTransmissionModeWithCompletion:(void(^_Nullable)(AUTELLinkVideoTransmissionMode mode, NSError * _Nullable error))block;

/**
 set video transmission mode With completion

 @param mode Video transmission mode
 @param block Completion block for asynchronous operations
 */
- (void)setVideoTramsmissionMode:(AUTELLinkVideoTransmissionMode)mode withCompletion:(AUTELCompletionBlock)block;

/**
 Firmware upgrade

 @param infor info
 @param fileName fileName
 @param progress progress
 @param block completion block
 */
- (void)updateFirmwareWithInfor:(NSDictionary *_Nonnull)infor
                     updateType:(AUTELFirmwareUpdateTyp)type
               withFirmwareName:(NSString *_Nonnull)fileName
                   withProgress:(AUTELUploadFirmwareProgressHandler _Nullable )progress
                 withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Query the coordinates of the last GPS point of the aircraft
*  查询飞机最后的GPS点坐标
*
*  @param block completed block,
*
*  @see AUTELAircraftGPSRecordInfo
*/
- (void)getAirplaneGPSRecordInfoWithCompletion:(void(^_Nullable)(NSArray <AUTELAircraftGPSRecordInfo *> * _Nullable recordInfos, NSError * _Nullable error))block;

/**
 *  @brie _Nullable f Get a collection of custom key functions for the remote control.
*
*  获取遥控器自定义按键功能集合
*
*  @param block completed block,
*
*  @see AUTELRCCustomKeyFuncModel
*/
- (void)getRCCustomKeyFuncWithCompletion:(void(^_Nullable)(NSArray <AUTELRCCustomKeyFuncModel *> * _Nullable models, NSError * _Nullable error))block;

/**
*  @brief Set the function definition of the custom key of the remote control.
*
*  设置遥控器自定义按键功能定义
*
*  @param model set model parameters,
*  @param block completed block,
*
*  @see AUTELRCCustomKeyFuncModel
*/
- (void)setRCCustomKeyFunc:(AUTELRCCustomKeyFuncModel * _Nonnull)model withCompletion:(AUTELCompletionBlock)block;


/**
*  @brief Send virtual joystick control commands.
*
*  下发虚拟摇杆控制指令
*
*  @param model set model parameters,
*  @param block completed block,
*
*  @see AUTELRCVirtualJoystickControlModel
*/
- (void)sendVirtualJoystickControlCommand:(AUTELRCVirtualJoystickControlModel *_Nonnull)model withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brie Query the IP address of Live Deck.
*
*  查询Live Deck的IP地址
*
*  @param block completed block,
*
*/
- (void)getLiveDeckIPInfoWithCompletion:(void(^_Nullable)(NSString * _Nullable ip, NSError * _Nullable error))block;

/**
*  @brief Set the IP address of the Live Deck.
*
*  设置Live Deck的IP地址
*
*  @param ip set ip string,
*  @param block completed block,
*
*/
- (void)setLiveDeckIPInfo:(NSString * _Nonnull)ip withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Binding the aircraft terminal and the remote control terminal.
*
*  绑定飞机端与遥控端
*
*  @param role  角色： 1：主机， 2：从机, see AUTELRCPairingRole
*  @param deviceType  设备类型： 0： 普通设备，1：中继, see AUTELRCPairingDeviceType
*  @param block completed block,
*
*/
- (void)bindingAirRemoteRole:(AUTELRCPairingRole)role deviceType:(AUTELRCPairingDeviceType)deviceType withCompletion:(AUTELCompletionBlock)block;

@end
