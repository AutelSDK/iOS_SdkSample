//
//  AUTELRemoteController.h
//  AUTELSDK
//
//  Created by IOS on 15/12/14.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELRemoteControllerDef.h>

@class AUTELRemoteController;

/**
 *  This protocol informs the remote controller's delegate of the changing status of the command sticks, buttons, dials, and remote controller.
 *
 *  该协议可告知遥控器代理关于遥控器摇杆，按键，拨轮以及遥控器状态的改变.
 */
@protocol AUTELRemoteControllerDelegate <NSObject>

@optional

/**
 *  @brief This callback method is used to update the position of the command sticks, the position of the Flight Mode Switch, the state of the buttons, and the position of the left dial. When the app is connected to the remote controller, this method will be invoked 5 times per second.
 *
 *  该回调方法更新遥控器摇杆位置，主模式开关位置，遥控器面板上的按键状态，左拨轮位置。如果 App 与遥控器连接，该方法每秒被调用5次。
 *
 *  @param rc   The remote controller instance which informs the delegate of the updated state.
 *
 *  告知代理状态更新的遥控器实例。
 *
 *  @param hardwareState State of the command sticks and buttons on the remote controller.
 *
 *  遥控器面板上摇杆与相关按键的状态
 *
 *  @see AUTELRCHardwareState
 *  @see AUTELRemoteController
 */
- (void)remoteController:(AUTELRemoteController*)rc didUpdateHardwareState:(AUTELRCHardwareState)hardwareState NS_SWIFT_NAME(remoteController(_:didUpdateHardwareState:));

/**
 *  @brief This method is invoked when the RC's state is changed, including the RC signal strength, video link signal strength, battery level, and RC calibration status. If the app is connected to the RC, this method will be invoked 5 times per second. 
 *
 *  该方法在遥控器状态改变时调用，包括遥控器信号强度、图传信号强度、电池电量信息以及遥控器校准状态。如果 App 与遥控器连接，该方法每秒被调用5次。
 *
 *  @param rc   The remote controller instance which informs the delegate of the updated state.
 *
 *  告知代理状态更新的遥控器实例。
 *
 *  @param rcState  RC state
 *
 *  遥控器信息状态
 *
 *  @see AUTELRemoteController
 *  @see AUTELRCState
 */
- (void)remoteController:(AUTELRemoteController *)rc didUpdateRCState:(AUTELRCState)rcState NS_SWIFT_NAME(remoteController(_:didUpdateRCState:));

/**
 *  @brief This method is invoked when the cammand from RC buttons is responded, including the Record button, Shutter button, Playback button, and dials.  If the app is connected to the RC, this method will be invoked 5 times per second. 
 *
 *  该方法在遥控器前端特殊按键响应时调用,包括左侧录像按钮,右侧拍照、回放按钮以及滚轮。如果 App 与遥控器连接，该方法每秒被调用5次。
 *
 *  @param rc   The remote controller instance which informs the delegate of the updated state.
 *
 *  告知代理状态更新的遥控器实例。
 *  
 *  @param specialButtonState   State of the RC specified buttons
 *
 *  前端特殊按键状态
 *
 *  @see AUTELRemoteController
 *  @see AUTELSpecialButtonState
 */
- (void)remoteController:(AUTELRemoteController *)rc didUpdateSpecialButtonState:(AUTELSpecialButtonState)specialButtonState NS_SWIFT_NAME(remoteController(_:didUpdateSpecialButtonState:));

/**
 *  @brief This method is invoked when the connection state between the RC and app is changed.
 *
 *  该方法在遥控器与app的连接状态发生改变时被调用。
 *
 *  @param rc   The remote controller instance which informs the delegate of the updated state.
 *
 *  告知代理状态更新的遥控器实例。
 *
 *  @param connected    Connected or not.
 *
 *  是否连接正常。
 *
 *  @see AUTELRemoteController
 */
- (void)remoteController:(AUTELRemoteController *)rc didUpdateConnecteState:(BOOL)connected NS_SWIFT_NAME(remoteController(_:didUpdateConnecteState:));

/**
 *  @brief  This method is called when the remote control is connected to other remote controllers with CAN cable.
 *
 *  遥控器与其他遥控器用 CAN 线连接时，该方法被调用
 *
 *  @param rc   The remote controller instance which informs the delegate of the updated state.
 *
 *  告知代理状态更新的遥控器实例。
 *
 *  @param state    Interconnected state between remote controls.
 *
 *  遥控器之间互联状态,教练/学生模式。
 *
 *  @see AUTELRemoteController
 */
- (void)remoteController:(AUTELRemoteController *)rc didUpdateInterconnectionState:(AUTELRCInterconnectionState)state NS_SWIFT_NAME(remoteController(_:didUpdateInterconnectionState:));
@end

@class AUTELDevice;

/**
 *  This class provides real-time status of RC, gimbal wheel, buttons and sticks. Provides functions of reading and writing RC parameters.
 *
 *  通过该类可以读写遥控器参数，校准遥控器，还可以实时获得遥控器状态，各摇杆、按钮和波轮的状态。
 */
@interface AUTELRemoteController : NSObject

/**
 *  @brief Returns an instance of current device object which is connected to RC.
 *
 *  返回与遥控器向连的设备的实例。
 */
@property (weak, nonatomic, readonly) AUTELDevice *device;

/**
 *  @brief The delegate of RC.
 *
 *  遥控器的代理。
 *
 *  @discussion 通过该代理，可以实时获取遥控器状态，摇杆状态，各按钮状态和波轮状态。
 *
 *  @see AUTELRemoteControllerDelegate
 */
@property (nonatomic, weak) id<AUTELRemoteControllerDelegate> delegate;

#pragma mark - RC Pairing
/**
 *  @brief Enter frequency pairing mode. 
 *
 *  进入遥控器配对模式.
 *
 *  @param block Completion block. If err is nil, then RC is pairing. Else if error returns pairingResult, then it indicates the pairing result.
 *
 *  完成 block。如果 err 为 nil，表示遥控器进行了配对动作，paringResult 表示配对的结果。
 *
 *  @discussion Fails to apply if invoke this function when motors are on, block returns AUTELSDKFlightControllerErrorMotorWorking error..
 *
 *  对于 X-Star 或 X-Star Premium 遥控器，电机转动时调用该方法，执行失败，block 返回 AUTELSDKFlightControllerErrorMotorWorking 错误。
 *
 *  @see AUTELRCParingResultState
 *  @see AUTELSDKFlightControllerError
 */
- (void)enterRCPairingModeWithCompletion:(void(^)(AUTELRCParingResultState paringResult, NSError *err))block;

#pragma mark - RC Control Mode
/**
 *  @brief Set the control mode of RC. 
 *
 *  设置遥控器摇杆操控模式。
 *
 *  @param mode  Control mode to be set.
 *
 *  遥控器操控模式。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @see AUTELRCControlMode
 */
- (void)setRCControlMode:(AUTELRCControlMode)mode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get the control mode of RC. 
 *
 *  查询遥控器摇杆操控模式。
 *
 *  @param block Completion block. 
 *
 *  完成 block。
 *
 *  @see AUTELRCControlMode
 */
- (void)getRCControlModeWithCompletion:(void(^)(AUTELRCControlMode mode, NSError *error))block;

#pragma mark - RC Calibration
/**
 *  @brief Record RC Calibration middle value. 
 *
 *  记录遥控器摇杆和拨轮中间值.
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @discussion Compass calibration has 2 steps. First call this method to record the middle value of sticks and gimbal wheel. If this method applies successfully, then enter into next step, call this method again to record the limit of gimbal wheel and sticks. Finally invoke recordRCCalibrationExtremeValueWithCompletion method finish compass calibration. AUTELRCState.rcCalibrationState indicates current state of compass calibration.
 *
 *  遥控器校准分两个步骤，首先不要触碰遥控器的摇杆和拨轮，调用该方法记录摇杆和拨轮的中位。
 *  如果该方法正确执行，遥控器将自动进入下一步记录摇杆和拨轮的限位，这时你要尽量将摇杆和拨轮移动到极限位置，
 *  然后调用 -recordRCCalibrationExtremeValueWithCompletion: 方法来完成遥控器校准。
 *  AUTELRCState.rcCalibrationState 表示遥控器当前校准状态。
 *
 *  @see -recordRCCalibrationExtremeValueWithCompletion:
 *  @see AUTELRCState
 */
- (void)recordRCCalibrationMiddleValueWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Record RC Calibration extreme value. 
 *
 *  记录遥控器摇杆和拨轮的极限值.
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @see -recordRCCalibrationMiddleValueWithCompletion:
 */
- (void)recordRCCalibrationExtremeValueWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Exit RC calibration mode.
 *
 *  退出遥控器校准模式.
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @discussion AUTELRCState.rcCalibrationState indicates current calibration state.
 *
 *  AUTELRCState.rcCalibrationState 表示遥控器当前校准状态。
 *
 *  @see AUTELRCState
 */
- (void)exitRCCalibrationWithCompletion:(AUTELCompletionBlock)block;

#pragma mark - RC Language
/**
 *  @brief Set language of RC
 *
 *  设置遥控器语言.
 *
 *  @param language language
 *
 *  设置语言
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @see AUTELRCLanguage
 *  @see -getRCLanguageWithCompletion:
 */
- (void)setRCLanguage:(AUTELRCLanguage)language withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get language of RC.
 *
 *  查询遥控器语言。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @see AUTELRCLanguage
 *  @see -setRCLanguage:withCompletion:
 */
- (void)getRCLanguageWithCompletion:(void(^)(AUTELRCLanguage language, NSError *error))block;

#pragma  mark - Wheel Speed
/**
 *  @brief Set the speed of gimbal wheel.
 *
 *  设置云台滚轮控制速率。
 *
 *  @param speed control the speed of gimbal wheel with value from 0 to 100.
 *
 *  滚轮控制速率,范围[0, 100]。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 * @see -getGimbalWheelSpeedWithCompletion:
 */
- (void)setGimbalWheelSpeed:(uint32_t)speed withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get the speed of gimbal wheel.
 *
 *  查询云台滚轮控制速率。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @see -setGimbalWheelSpeed:withCompletion:
 */
- (void)getGimbalWheelSpeedWithCompletion:(void(^)(uint32_t speed, NSError *error))block;

#pragma mark - frequency mode
/**
 *  @brief Set the radio frequency mode of RC (FCC or CE).
 *
 *  设置遥控器射频模式（FCC 或 CE）。
 *
 *  @discussion 该方法只适用于X-Star
 *
 *  @param rf Frequency mode.
 *
 *  射频模式。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @discussion Set the radio frequency mode of RC. This method is only applicable to X-Star. If invoke this method for X-Star Premium, block returns AUTELSDKRCErrorRCNotSupport error.
 *
 *  只有 X-Star 的遥控器支持该方法，对 X-Star Premium 遥控器调用该方法，block 返回 AUTELSDKRCErrorRCNotSupport 错误。
 *
 *  @see AUTELRCRadioFrequencyMode
 *  @see -getRadioFrequencyModeWithCompletion:
 *  @see AUTELSDKRemoteControllerError
 */
- (void)setRadioFrequencyMode:(AUTELRCRadioFrequencyMode)rf withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get the radio frequncy mode of RC.
 *
 *  查询遥控器射频模式。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @discussion Get the radio frequency mode of RC. This method is only applicable to X-Star. If invoke this method for X-Star Premium, block returns AUTELSDKRCErrorRCNotSupport error.
 *
 *  只有 X-Star 的遥控器支持该方法，对 X-Star Premium 遥控器调用该方法，block 返回 AUTELSDKRCErrorRCNotSupport 错误。
 *
 *  @see AUTELRCRadioFrequencyMode
 *  @see -setRadioFrequencyMode:withCompletion:
 *  @see AUTELSDKRemoteControllerError
 */
- (void)getRadioFrequencyModeWithCompletion:(void(^)(AUTELRCRadioFrequencyMode mode, NSError *error))block;

#pragma mark - name (SSID) and password
/**
 *  @brief Get name (SSID) and password of RC.
 *
 *  获取遥控器名称（SSID）和密码。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @discussion 该方法只适用于 Wi-Fi 遥控器，如 X-Star 遥控器。如果对 X-Star Premium 遥控器调用该方法，block 将返回 AUTELSDKRCErrorRCNotSupport 错误。
 *
 *  @see AUTELRCName
 *  @see AUTELRCPassword
 *  @see -setRCName:andRCPassword:withCompletion:
 */
- (void)getRCNameAndPasswordWithCompletion:(void (^)(AUTELRCName name, AUTELRCPassword password, NSError *err))block;

/**
 *  @brief Set name (SSID) and password of RC.
 *
 *  设置遥控器名称和密码。
 *
 *  @param name The name of RC to be set. The name should be 8-16 charcters in length, and contain only letters, digits, '-' and '_'.
 *
 *  要设置的遥控器名称（SSID）。只能包含字母、数字、下划线、中划线，长度为8-16位字符。
 *
 *  @param password The password of RC to be set. The password should be 8-16 charcters in length.
 *
 *  要设置的遥控器密码，长度为8-16位字符。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @discussion 该方法只适用于 Wi-Fi 遥控器，如 X-Star 遥控器。如果对 X-Star Premium 遥控器调用该方法，block 将返回 AUTELSDKRCErrorRCNotSupport 错误。
 */
- (void)setRCName:(AUTELRCName)name andRCPassword:(AUTELRCPassword)password withCompletion:(AUTELCompletionBlock)block;

#pragma mark - unit of measurement
/**
 *  @brief Get unit of measurement (metric or imperial).
 *
 *  查询遥控器单位公英制.
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @see AUTELRCUnitsOfMeasurement
 *  @see -setUnitsOfMeasurement:withCompletion:
 */
- (void)getUnitOfMeasurementWithCompletion:(void(^)(AUTELRCUnitsOfMeasurement unit, NSError *error))block;

/**
 *  @brief Set unit of measurement (metric or imperial).
 *
 *  设置遥控器单位公英制。
 *
 *  @param unit Metric or imperial。
 *
 *  公英制.
 *
 *  @param block Remote execute result. 执行结果.
 *
 *  @see AUTELRCUnitsOfMeasurement
 *  @see -getUnitOfMeasurementWithCompletion:
 */
- (void)setUnitsOfMeasurement:(AUTELRCUnitsOfMeasurement)unit withCompletion:(AUTELCompletionBlock)block;

#pragma mark - relationship mode
/**
 *  @brief Get relationship mode of RC (off, instructor, learner)
 *
 *  获取遥控器主从模式。
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @see AUTELRCRelationshipMode
 *  @see -setRelationshipMode:withCompletion:
 */
- (void)getRelationshipModeWithCompletion:(void(^)(AUTELRCRelationshipMode mode, NSError *error))block;

/**
 *  @brief Set relationship mode of RC (off, instructor, learner).
 *
 *  设置遥控器主从模式。
 *
 *  @param mode Relationship mode of RC
 *
 *  主从模式
 *
 *  @param block Completion block.
 *
 *  完成 block。
 *
 *  @see AUTELRCRelationshipMode
 *  @see -getRelationshipModeWithCompletion:
 */
- (void)setRelationshipMode:(AUTELRCRelationshipMode)mode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Transmit iPhone/iPad's compass angle to RC
 *
 *  发送连接到遥控器的移动设备的指南针角度给遥控器
 *
 *  @param angle iPhone/iPad's compass angle
 */
- (void)setDeviceCompassAngle:(uint16_t)angle;
@end
