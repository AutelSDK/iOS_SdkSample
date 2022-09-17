//
//  AUTELFlightLimitation.h
//  AUTELSDK
//
//  Created by IOS on 15/11/18.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELRTKModel.h>

/**
 *  This protocol defines the API for reading and writing the flight limit parameters.
 *
 *  该协议定义了读写飞行限制参数的接口
 */
@protocol AUTELFlightLimitation <NSObject>

/**
 *  @brief Set the max flight altitude between 30 m (99 ft) and 800 m (2624 ft).
 *
 *  设置飞行器的最大飞行高度，maxHeight 的可设置范围是30米(99英尺)至800米(2624英尺)。
 *
 *  @param maxHeight The unit for max flight altitude is meter.
 *
 *  飞行器最大飞行高度，单位为m。
 *
 *  @param block     Completion Blok. 
 *
 *  完成block。
 *
 *  @discussion The max flight altitude is the distance between the aircraft and the takeoff point. When the max flight altitude is reached, the aircraft cannot ascend any more. You can check if the aircraft has reached the max flight altitude through AUTELMCSystemState.isReachMaxHeight.
 *  You can check the aircraft's current max flight altitude through -getMaxFlightHeightWithCompletion:.
 *  In Beginner mode, this parameter will be ignored, and the max flight altitude is 30 m. You can check and modify the parameter in Beginner mode through -getBeginnerModeEnableWithCompletion: and -setBeginnerMode:withCompletion: respectively.
 *
 *  该最大高度是飞行器相对于起飞点的相对高度。当飞行器到达最大高度时，不能再上升。你可以通过 AUTELMCSystemState.isReachMaxHeight 知道飞行器是否到达了最大高度。
 *  通过 -getMaxFlightHeightWithCompletion: 方法可以查询当前飞行器的最大飞行高度参数值。
 *  当飞行器新手模式被打开时，飞行器将忽略该参数，最高只能飞行到30米高，你可以通过 -getBeginnerModeEnableWithCompletion: 和 -setBeginnerMode:withCompletion: 方法来查询和修改新手模式参数。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELDroneMainControllerDelegate
 *  @see -getMaxFlightHeightWithCompletion:
 *  @see -getBeginnerModeEnableWithCompletion:
 *  @see -setBeginnerMode:withCompletion:
 */
- (void)setMaxFlightHeight:(float)maxHeight withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get max flight heigh limitation from aircraft. 
 *
 *  查询飞行器最大飞行高度参数值。
 *
 *  @param block Completion block，the unit is meter.
 *
 *  完成block，height 的单位为m。
 *
 *  @discussion You can use -setMaxFlightHeight:withCompletion: to set the aircraft's max flight altitude. 
 *  In Beginner mode, this parameter will be ignored, and the max flight altitude is 30 m. You can check and modify the parameter in Beginner mode through -getBeginnerModeEnableWithCompletion: and -setBeginnerMode:withCompletion: respectively.
 *
 *  调用 -setMaxFlightHeight:withCompletion: 方法来设置飞行器最大飞行高度参数。
 *  当飞行器新手模式被打开时，飞行器将忽略该参数，最高只能飞行到30米高，你可以通过 -getBeginnerModeEnableWithCompletion: 和 -setBeginnerMode:withCompletion: 方法来查询和修改新手模式参数
 *
 *  @see -setMaxFlightHeight:withCompletion:
 *  @see -getBeginnerModeEnableWithCompletion:
 *  @see -setBeginnerMode:withCompletion:
 */
- (void)getMaxFlightHeightWithCompletion:(void(^_Nullable)(float height, NSError* _Nullable error))block;

/**
 *  @brief The aircraft's max flight radius is based on the home point as the center point. The maxRadius can be set between 30 m and 10000 m.
 *
 *  设置飞行器的最大飞行半径，该半径已返航点为圆心计算，maxRadius 的可设置范围为30米至10000米
 *
 *  @param maxRadius max flight radius,the unit is meter.
 *
 *  飞行器最大飞行半径，单位为m。
 *
 *  @param block  Completion Blok. 
 *
 *  完成block。
 *
 *  @discussion When the max flight radius is reached, the aircraft cannot fly out any more. You can check if the aircraft has reached the max flight radius through  isReachMaxRange in AUTELMCSystemState.
 *  The flight distance is also relevant to the flight environment. If the control signal is lost during flight, the aircraft will Go Home automatically.
 *  You can check the max flight radius through -getMaxFlightRadiusWithCompletion:.
 *  In Beginner mode, this parameter will be ignored, and the flight radius is 30 m. You can check and modify the parameter in Beginner mode through -getBeginnerModeEnableWithCompletion: and -setBeginnerMode:withCompletion:.
 *
 *  遥控器达到最大半径后，无法再往外飞行，你可以通过 AUTELMCSystemState 的 isReachMaxRange 属性表示飞行器是否到达了最大半径。
 *  飞行器实际能飞多远，还与飞行环境有关，如果飞行器在飞行过程中发生遥控器信号丢失的情况，飞行器会自动返航。
 *  你可以通过 -getMaxFlightRadiusWithCompletion: 可以查询飞行器最大飞行半径参数。
 *  当飞行器新手模式被打开时，飞行器将忽略该参数，飞行半径为30米，你可以通过 -getBeginnerModeEnableWithCompletion: 和 -setBeginnerMode:withCompletion: 方法来查询和修改新手模式参数
 *
 *  @see AUTELMCSystemState
 *  @see AUTELDroneMainControllerDelegate
 *  @see -getMaxFlightRadiusWithCompletion:
 *  @see -getBeginnerModeEnableWithCompletion:
 *  @see -setBeginnerMode:withCompletion:
 */
- (void)setMaxFlightRadius:(float)maxRadius withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get max flight radius limitation from aircraft. 
 *
 *  查询新飞行器最大飞行半径。
 *
 *  @param block Completion block,the unit of rudius is meter.
 *
 *  完成block，radius 单位为m。
 *
 *  @discussion You can use -setMaxFlightRadius:withCompletion: to set the aircraft's max flight radius. 
 *  In Beginner mode, this parameter will be ignored, and the flight radius is 30 m. You can check and modify the parameter in Beginner mode through -getBeginnerModeEnableWithCompletion: and -setBeginnerMode:withCompletion:.
 *
 *  你可以通过 -setMaxFlightRadius:withCompletion: 可以设置飞行器最大飞行半径参数。
 *  当飞行器新手模式被打开时，飞行器将忽略该参数，飞行半径为30米，你可以通过 -getBeginnerModeEnableWithCompletion: 和 -setBeginnerMode:withCompletion: 方法来查询和修改新手模式参数
 *
 *  @see -setMaxFlightRadius:withCompletion:
 *  @see -getBeginnerModeEnableWithCompletion:
 *  @see -setBeginnerMode:withCompletion:
 */
- (void)getMaxFlightRadiusWithCompletion:(void(^_Nullable)(float radius, NSError * _Nullable error))block;

/**
 *  @brief The max horizontal speed can be set between 2 m/s and 15 m/s.
 *  
 *  设置飞行器最大水平速度，maxHorizontalSpeed 的可设置范围为 2m/s 至 15m/s。
 *
 *  @param maxHorizontalSpeed Max horizontal speed,the unit is m/s.
 *
 *  最大水平速度，单位为m/s。
 *
 *  @param block  Completion Blok. 
 *
 *  完成block。
 *
 *  @discussion You can use -getMaxFlightHorizontalSpeedWithCompletion: to check the aircraft's max horizontal speed. 
 *
 *  In Beginner mode, this parameter will be ignored, and the max horizontal speed is 6 m/s. You can check and modify the parameter in Beginner mode through -getBeginnerModeEnableWithCompletion: and -setBeginnerMode:withCompletion:.
 *
 *  你可以通过 -getMaxFlightHorizontalSpeedWithCompletion: 方法查询飞行器最大水平速度参数。
 *  当飞行器新手模式被打开时，飞行器将忽略该参数，飞行器最大水平速度为6m/s，你可以通过 -getBeginnerModeEnableWithCompletion: 和 -setBeginnerMode:withCompletion: 方法来查询和修改新手模式参数。
 *
 *  @see -getMaxFlightHorizontalSpeedWithCompletion:
 *  @see -getBeginnerModeEnableWithCompletion:
 *  @see -setBeginnerMode:withCompletion:
 */
- (void)setMaxFlightHorizontalSpeed:(float)maxHorizontalSpeed withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Request max horizontal speed.
 *
 *  请求飞行最大水平速度
 *
 *  @param block  Completion block.The unit for speed is m/s.
 *
 *  完成block，speed 的单位为 m/s。
 *
 *  @discussion You can use -setMaxFlightHorizontalSpeed:withCompletion: to set the aircraft's max horizontal speed. 
 *  
 *  In Beginner mode, this parameter will be ignored, and the max horizontal speed is 6 m/s. You can check and modify the parameter in Beginner mode through -getBeginnerModeEnableWithCompletion: and -setBeginnerMode:withCompletion:.
 *
 *  你可以通过 -setMaxFlightHorizontalSpeed:withCompletion: 方法设置飞行器最大水平速度参数
 *  当飞行器新手模式被打开时，飞行器将忽略该参数，飞行器最大水平速度为6m/s，你可以通过 -getBeginnerModeEnableWithCompletion: 和 -setBeginnerMode:withCompletion: 方法来查询和修改新手模式参数
 *
 *  @see -setMaxFlightHorizontalSpeed:withCompletion:
 *  @see -getBeginnerModeEnableWithCompletion:
 *  @see -setBeginnerMode:withCompletion:
 **/
- (void)getMaxFlightHorizontalSpeedWithCompletion:(void(^_Nullable)(float speed, NSError * _Nullable error))block;

/**
 *  @brief Check if the Beginner mode is enabled.
 *
 *  查询飞行器是否开启了新手模式
 *
 *  @param block  Completion Blok. 
 *
 *  完成block
 *
 *  @discussion You can use -setBeginnerMode:withCompletion: to enable or disable the Beginner mode.
 *  In Beginner mode, the max flight altitude is 30 m, the flight radius is 30 m, and the max horizontal speed is 6 m/s.
 *
 *  你可以通过 -setBeginnerMode:withCompletion: 方法打开或关闭新手模式。
 *  当新手模式打开时，飞行器的飞行最大高度被限定为30m，飞行半径本限定为30m，最大水平速度限定为6m/s。
 *
 *  @see -setBeginnerMode:withCompletion:
 **/
- (void)getBeginnerModeEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError * _Nullable error))block;

/**
 *  @brief Enable or disable the Beginner mode
 *
 *  设置飞行器新手模式
 *
 *  @param enable YES: enable Beginner mode. NO: disable Beginner mode.
 *
 *  YES:打开新手模式 NO:关闭新手模式
 *
 *  @param block  Completion Blok. 
 *
 *  完成block
 *
 *  @discussion If you are a beginner for flight control, you may enable the Beginner mode.In Beginner mode, the max flight altitude is 30 m, the flight radius is 30 m, and the max horizontal speed is 6 m/s.
 *
 *  当飞行器操控手对操控飞行器不太熟悉时，可以打开飞行器的新手模式。当新手模式打开时，飞行器的飞行最大高度被限定为30m，飞行半径本限定为30m，最大水平速度限定为6m/s。
 *
 *  @note The Beginner mode can only be activated before the flight instead of during the flight. If the enable property is set as YES, execution error will occur, and the block will return the AUTELSDKFlightControllerErrorAircraftFlying error.
 *
 *  如果你想打开新手模式，你必须在飞行器起飞前打开，飞行在飞行过程中，不能将新手模式从关闭变为打开，如果飞行器在飞行过程中，调用此方法，且 enable 为 YES，该方法将执行错误，block 返回 AUTELSDKFlightControllerErrorAircraftFlying 错误。
 *
 *  @see AUTELSDKFlightControllerError
 *  @see -getBeginnerModeEnableWithCompletion:
 **/
- (void)setBeginnerMode:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set the maximum ascent speed
 *
 *  设置最大上升速度
 *
 *  @param speed  ascent speed
 *  @param block  completion block
 **/
- (void)setMaxAscentSpeed:(float)speed withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get the maximum ascent speed
 *
 *  查询最大上升速度值
 *  @param block  完成block
 **/
- (void)getMaxAscentSpeedWithCompletion:(void(^_Nullable)(float speed, NSError * _Nullable error))block;

/**
 *  @brief Set the maximum descent speed
 *
 *  设置最大下降速度
 *
 *  @param speed  descent speed
 *  @param block  completion block
 **/
- (void)setMaxDescentSpeed:(float)speed withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get the maximum descent speed
 *
 *  查询最大下降速度值
 *  @param block  completion block
 **/
- (void)getMaxDescentSpeedWithCompletion:(void(^_Nullable)(float speed, NSError * _Nullable error))block;

/**
 set maximum pitch angle

 @param angle pitch angle
 @param block completion block
 */
- (void)setMaxPitchAngle:(float)angle withCompletion:(AUTELCompletionBlock)block;

/**
 get maximum pitch angle

 @param block completion block
 */
- (void)getMaxPitchAngelWithCompletion:(void(^_Nullable)(float angle, NSError* _Nullable error))block;

/**
 set maximum yaw angle speed

 @param speed angle speed
 @param block completion block
 */
- (void)setMaxYawAngleSpeed:(float)speed withCompletion:(AUTELCompletionBlock)block;

/**
 get maximum yaw angle speed

 @param block completion block
 */
- (void)getMaxYawAngleSpeedWithCompletion:(void(^_Nullable)(float speed, NSError* _Nullable error))block;

/**
 Set flight limit parameter

 @param paramName param name
 @param value param value
 @param block completion block
 */
- (void)setParam:(NSString *_Nonnull)paramName paramValue:(float)value withCompletion:(AUTELCompletionBlock)block;

/**
 get flight limit parameter

 @param paramName param name
 @param block completion block
 */
- (void)getParam:(NSString *_Nonnull)paramName withCompletion:(void(^_Nullable)(float value, NSError * _Nullable error))block;


/**
 *  @brief Check whether the aircraft has RTK location enabled.
 *
 *  查询飞行器是否开启了RTK定位
 *
 *  @param block  Completion Blok.
 *
 *  完成block
 *
 **/
- (void)getRTKLocationEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError * _Nullable error))block;

/**
 *  @brief Enable or disable the RTK location
 *
 *  设置飞行器RTK定位使能
 *
 *  @param enable YES: enable RTK location. NO: disable RTK location.
 *
 *  YES:打开RTK定位使能 NO:关闭RTK定位使能
 *
 *  @param block  Completion Blok.
 *
 *  完成block
 *
 **/
- (void)setRTKLocationEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Query how the aircraft receives RTK signals.
 *
 *  查询飞行器接收RTK信号方式
 *
 *  @param block  Completion Blok.
 *
 *  完成block
 *
 **/
- (void)getRTKRecvDiffTypeWithCompletion:(void(^_Nullable)(AUTELRTKRecvDiffType type, NSError * _Nullable error))block;

/**
 *  @brief Set the type the aircraft RTK receives RTK signals.
 *
 *  设置飞行器RTK接收RTK信号方式
 *
 *  @param type the type the aircraft RTK receives RTK signals.
 *
 *  YES:打开RTK定位使能 NO:关闭RTK定位使能
 *
 *  @param block  Completion Blok.
 *
 *  完成block
 *
 **/
- (void)setRTKRecvDiffType:(AUTELRTKRecvDiffType)type withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief Query the aircraft's RTK coordinate system.
 *
 *  查询飞行器RTK坐标系
 *
 *  @param block  Completion Blok.
 *
 *  完成block
 *
 **/
- (void)getRTKCoordinateSysWithCompletion:(void(^_Nullable)(AUTELRTKCoordinateSys type, NSError * _Nullable error))block;

/**
 *  @brief Set the aircraft RTK coordinate system
 *
 *  设置飞行器RTK坐标系
 *
 *  @param type coordinate system type.
 *
 *  YES:打开RTK定位使能 NO:关闭RTK定位使能
 *
 *  @param block  Completion Blok.
 *
 *  完成block
 *
 **/
- (void)setRTKCoordinateSys:(AUTELRTKCoordinateSys)type withCompletion:(AUTELCompletionBlock)block;



//#pragma mark 以下接口仅内部使用，不对外发布
//
//
///// 查询飞行器IMU Modeule ID
///// @param block Completion Blok.
//- (void)getIMUModelIDWithCompletion:(void(^_Nullable)(uint64_t id, NSError * _Nullable error))block;
//
//
///// 设置飞行器激活状态（仅内部使用！！！！！）
///// @param enable 激活状态
///// @param block 完成block
//- (void)setActivateState:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;


@end
