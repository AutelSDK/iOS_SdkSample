//
//  AUTELHandHeld.h
//  AUTELSDK
//
//  Created by Autel_ljm on 16/1/22.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELDevice.h>

NS_ASSUME_NONNULL_BEGIN

@class AUTELGimbal, AUTELGimbalBattery, AUTELHandheldController;

/**
 *  This class contains the components of a handheld device. __deprecated
 */
@interface AUTELHandHeld : AUTELDevice

/**
 *  Returns an instance of the handheld device's gimbal.
 */
@property (nonatomic, readonly) AUTELGimbal *gimbal;

/**
 *  Returns an instance of the handheld device's battery.
 */
@property (nonatomic, readonly) AUTELGimbalBattery *gimbalBattery;

/**
 *  Returns an instance of the handheld device's handheldController.
 */
@property (nonatomic, readonly) AUTELHandheldController *handheldController;

@end

NS_ASSUME_NONNULL_END
