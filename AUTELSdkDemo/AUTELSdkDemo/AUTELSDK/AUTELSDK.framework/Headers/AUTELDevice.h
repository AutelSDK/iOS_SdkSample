//
//  AUTELDevice.h
//  AUTELSDK
//
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Define connection state between the app and device
 *
 *  定义App与设备的的连接状态
 */
typedef NS_ENUM(uint8_t, AUTELDeviceConnectionStatus) {
    /**
     *  @brief Disconnected
     *
     *  连接断开
     */
    ConnectionBroken,
    
    /**
     *  @brief Connection successful
     *
     *  连接成功
     */
    ConnectionSucceeded,
};

/**
 *  Define device type
 *
 *  定义设备类型
 */
typedef NS_ENUM(NSUInteger, AUTELDeviceType) {
    
    /**
     *  @brief Aircraft type: X-Star Premium
     *
     *  设备型号：X-Star Premium
     */
    AUTELDevice_Drone_XStarPremium = 0,
    
    /**
     *  @brief Aircraft type: X-Star 
     *
     *  设备型号：X-Star
     */
    AUTELDevice_Drone_XStar,
    
    /**
     *  @brief Aircraft type: New
     *
     *  设备型号：2G
     */
    AUTELDevice_Drone_2G,
    
    /**
     *  @brief Aircraft type: Vivid
     *
     *  设备型号：小手持
     */
    AUTELDevice_Handheld_Vivid,
    
    /**
     *  @brief Aircraft type: ModelC
     *
     *  设备型号：ModelC
     */
    AUTELDevice_Drone_ModelC,
    
    /**
     *  @brief Unknown device type
     *
     *  未知设备类型
     */
    AUTELDevice_Unknown = -1,
};

@class AUTELDevice;

/**
 *  Provides delegate methods of real-time status of connections between app and devices.
 *
 *  该协议提供实更新设备当前与 App 连接状态的的代理方法。
 */
@protocol AUTELDeviceDelegate <NSObject>

/**
 *  @brief Tell the delegate that the status of connection is chenged.
 *
 *  告知代理设备与App的连接状态改变了。
 *
 *  @param device The AUTELDevice instance which connetiong is changed.
 *
 *  连接状态改变的 AUTELDevice 实例。
 *
 *  @param status Connection status. 
 *
 *  连接状态。
 *
 *  @discussion  When app is on the backend, connection breaks.
 *
 *
 *  当 App 退到后台时，App 与设备的连接会断开。
 *
 *  @see AUTELDevice
 *  @see AUTELDeviceConnectionStatus
 */
- (void)device:(AUTELDevice *)device didConnectionStatusChanged:(AUTELDeviceConnectionStatus)status NS_SWIFT_NAME(device(_:didConnectionStatusChanged:));

@end

/**
 *  @brief The base class of AUTEL device class which provides the status of connection.
 *
 *  该类是道通智能设备的基类，通过该类实例可以获取设备连接状态。
 */
@interface AUTELDevice : NSObject

/**
 *  @brief Use this delegate to get notifications when connection status changes.
 *
 *  通过该代理对象获取设备连接状态改变的通知。
 *
 *  @see AUTELDeviceDelegate
 */
@property (weak, nonatomic) id<AUTELDeviceDelegate> delegate;

/**
 *  @brief Initial AUTELDevice object with device type.
 *
 *  用设备类型初始化 AUTELDevice 对象。
 *
 *  @param deviceType Device type.
 *
 *  指定设备类型。
 *
 *  @return Returns an instance of AUTELDevice object if initialization succeeded or return nil.
 *
 *  如果成功，则返回初始化后的 AUTELDevice 对象，否则返回nil。
 *
 *  @discussion If deviceType equals to AUTELDevice_Drone_XstarPremium or AUTELDevice_Drone_Xstar, return AUTELDevice object. If deviceType equals to AUTELDevice_Handheld_Vivid or AUTELHandHeld, return nil.
 *
 *  如果 deviceType 等于 AUTELDevice_Drone_XStarPremium 或 AUTELDevice_Drone_XStar，将返回 AUTELDrone 实例；deviceType 等于 AUTELDevice_Handheld_Vivid 将返回 AUTELHandHeld 实例，其他返回nil。
 *
 *  @see AUTELDeviceType
 *  @see AUTELDrone
 */
- (instancetype)initWithType:(AUTELDeviceType)deviceType;

/**
 *  @brief Retuen device type.
 *
 *  返回设备类型。
 */
- (AUTELDeviceType)deviceType;

/**
 *  @brief Returns Yes if app is connected to device, else No.
 *
 *  返回 App 是否连接上该设备。
 */
- (BOOL)isConnected;

@end
