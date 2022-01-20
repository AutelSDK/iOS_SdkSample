//
//  AUTELCompass.h
//  AUTELSDK
//
//  Created by IOS on 15/11/9.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELMainControllerDef.h>

@protocol AUTELCompass <NSObject>

/**
 *  @brief This property indicates the direction of compass from –π to π. Sets 0 as north, -π/2 as west,  π/2 as ease, π or –π as south. The value of heading equals to the value of AUTELMCSystemState.attitude.yaw.
 *
 *  该值表示磁力计方向，范围[-π, π]，正北为 0，正西为 -π/2，正东为 π/2，正南为 π 或 -π。这个值等于'AUTELMCSystemState.attitude.yaw'
 *
 *  @see AUTELMCSystemState
 */
@property(nonatomic, readonly) double heading;

/**
 *  @brief This property describes whether the compass has error or not. If Yes, the compass need calibration.
 *
 *  指南针是否有错误。如果有，则需要校准。
 *
 *  @discussion The value of hasError equals to AUTELMCSystemState.isCompassError.
 *
 *  该属性值与 AUTELMCSystemState.isCompassError 一致
 *
 *  @see AUTELMCSystemState
 */
@property(nonatomic, readonly) BOOL hasError;

/**
 *  @brief Whether or not the compass is in calibrating.
 *
 *  指南针是否正在校准。
 *
 *  @see calibrationStatus
 */
@property(nonatomic, readonly) BOOL isCalibrating;

/**
 *  @brief If isCalibration equals to Yes, this property indicates the status of calibration.
 *
 *  如果 isCalibrating 为 YES，该属性表示指南针校准状态。
 *
 *  @discussion Call startCalibrationWithCompletion method to trigger calibration mode. The order of calibration status is : AUTELCompassCalibrationNone -> AUTELCompassCalibrationStep1 -> AUTELCompassCalibrationStep2 -> AUTELCompassCalibrationCalculating -> AUTELCompassCalibrationSucceeded/AUTELCompassCalibrationFailed -> AUTELCompassCalibrationNone. The value of this property equals to AUTELMCSystemState.compassCalibrationStatus.
 *
 *  你可以通过 -startCalibrationWithCompletion: 方法让磁力计进入校准状态。校准状态跳转如下：AUTELCompassCalibrationNone -> AUTELCompassCalibrationStep1 -> AUTELCompassCalibrationStep2 -> AUTELCompassCalibrationCalculating -> AUTELCompassCalibrationSucceeded/AUTELCompassCalibrationFailed -> AUTELCompassCalibrationNone
 *  该属性值与 AUTELMCSystemState.compassCalibrationStatus 一致
 *
 *  @see AUTELCompassCalibrationStatus
 *  @see -startCalibrationWithCompletion:
 *  @see AUTELMCSystemState
 */
@property(nonatomic, readonly) AUTELCompassCalibrationStatus calibrationStatus;

/**
 *  @brief The level of magnetic interference.
 *
 *  磁力计受干扰级别。
 *
 *  @discussion The value of this property equals to AUTELMCSystemState.compassInterferenceLevel. When compassInterferenceLevel is AUTELCompassInterferenceLevel4, hasErorr property sets to Yes.
 *
 *  该值与 AUTELMCSystemState.compassInterferenceLevel 一致
 *  compassInterferenceLevel 为 AUTELCompassInterferenceLevel4 时，hasError 为 YES.
 *
 *  @see AUTELMCSystemState
 */
@property(nonatomic, readonly) AUTELCompassInterferenceLevel compassInterferenceLevel;

/**
 *  @brief Invoke this method to start compass calibration.
 *
 *  调用该方法让飞行器进入校准。
 *
 *  @param block if main controller received the command, returns nil. Else returns error message.
 *
 *  如果命令发送成功，block 的 error 返回 nil，否则返回错误信息。
 *
 *  @discussion This method can be invoked when motors are on and returns AUTELSDKFlightControllerErrorMotorWorking error.
 *
 *  当飞行器电机转动时，该方法将执行失败，返回 AUTELSDKFlightControllerErrorMotorWorking 错误
 *
 *  @see AUTELSDKFlightControllerError
 *  @see AUTELMCSystemState
 */
- (void)startCalibrationWithCompletion:(AUTELCompletionBlock)block;

@end
