//
//  AUTELDrone.h
//  AUTELSDK
//
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELDevice.h>

@class AUTELDroneMainController;
@class AUTELBattery;
@class AUTELRemoteController;
@class AUTELDroneGimbal;
@class AUTELNavigation;
@class AUTELBaseCamera;
@class AUTELAirLink;

/**
 *  Control X-Star and X-Star Premium through AUTELDrone class
 *
 *  通过该类可以对 X-Star 和 X-Star Premium飞行器进行操作
 */
@interface AUTELDrone : AUTELDevice

/**
 *  @brief Returns an instance of the drone's main controller. 
 *
 *  返回飞行器主控对象实例
 *
 *  @see AUTELDroneMainController
 */
@property (readonly, strong, nonatomic) AUTELDroneMainController *mainController;

/**
 *  @brief Returns an instance of the drone's smart battery. 
 *
 *  返回飞行器智能电池对象实例。
 *
 *  @see AUTELBattery
 */
@property (readonly, strong, nonatomic) AUTELBattery *battery;

/**
 *  @brief Returns an instance of the drone's remote controller. 
 *
 *  返回飞行器的遥控器对象实例。
 *
 *  @see AUTELRemoteController
 */
@property (readonly, strong, nonatomic) AUTELRemoteController *remoteController;

/**
 *  @brief Returns an instance of the drone's gimbal. 
 *
 *  返回飞行器云台对象实例。
 *
 *  @see AUTELDroneGimbal
 */
@property (readonly, strong, nonatomic) AUTELDroneGimbal *gimbal;

/**
 *  @brief Returns an instance of the drone's camera.
 *
 *  返回飞行器相机对象实例。
 *
 *  @see AUTELDroneGimbal
 */
@property (readonly, strong, nonatomic) AUTELBaseCamera *camera;

/**
 Returns an instance of the drone's airlink
 */
@property (readonly, strong, nonatomic) AUTELAirLink *airLink;

@end
