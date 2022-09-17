//
//  AUTELDroneMainController.h
//  AUTELSDK
//
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELMainControllerDef.h>
#import <CoreLocation/CoreLocation.h>
#import <AUTELSDK/AUTELRTKModel.h>
#import "AUTELTransferFileModel.h"

@class AUTELDroneMainController;
@class AUTELMCSystemState;
@class AUTELDrone;
@protocol AUTELFlightLimitation;
@protocol AUTELCompass;
@class AUTELNavigation;
@class AUTELFlightAssistant;

/**
 *  The vertical control velocity MIN value is -4 m/s in `VirtualStickControlMode`. Negative velocity is down.
 *
 *  `VirtualStickControlMode`模式下最小速度是-4，负代表向下。
 */
extern const float AUTELVirtualStickVerticalControlMinVelocity;
/**
 *  The vertical control velocity MAX value is 4 m/s in VirtualStickControlMode. Positive velocity is up.
 *
 *  `VirtualStickControlMode`模式下最大速度是4，正代表向上。
 *
 */
extern const float AUTELVirtualStickVerticalControlMaxVelocity;

/**
 *  The vertical control position MIN value is 0 m for `VirtualStickVerticalControlModePosition`.
 *
 *  竖向控制位置最小值为0米 `VirtualStickVerticalControlModePosition`
 */
extern const float AUTELVirtualStickVerticalControlMinPosition;
/**
 *  The vertical control position MAX value is 500 m for `VirtualStickVerticalControlModePosition`.
 *
 *  竖向控制最大值为500米 `VirtualStickVerticalControlModePosition`
 */
extern const float AUTELVirtualStickVerticalControlMaxPosition;

/**
 *  Defines how vertical control values are interpreted by the aircraft.
 *
 *  定义飞机竖向的控制类型
 */
typedef NS_ENUM (uint8_t, AUTELVirtualStickVerticalControlMode){
    /**
     *  Sets the Virtual Stick Control vertical control values to be a vertical velocity.
     *  Positive and negative vertical velocity is for the aircraft ascending and descending
     *  respectively. Maximum vertical velocity is defined as `AUTELVirtualStickVerticalControlMaxVelocity`.
     *  Minimum vertical velocity is defined as `AUTELVirtualStickVerticalControlMinVelocity`.
     *
     *  给 Virtual Stick Control vertical control 设置速度值
     *  正负速度分别代表飞机上升和下降，
     *  `AUTELVirtualStickVerticalControlMaxVelocity` 是最大速度
     *  `AUTELVirtualStickVerticalControlMinVelocity` 是最小速度
     */
    AUTELVirtualStickVerticalControlModeVelocity,
    /**
     *  Sets the `VirtualStickControlMode` vertical control values to be an altitude. Maximum position is defined as `AUTELVirtualStickVerticalControlMaxPosition`.
     *  Minimum position is defined as `AUTELVirtualStickVerticalControlMinPosition`.
     *
     *  给 `VirtualStickControlMode` vertical control 设置高度值。
     *  `AUTELVirtualStickVerticalControlMaxPosition` 是最大值
     *  `AUTELVirtualStickVerticalControlMinPosition` 是最小值
     */
    AUTELVirtualStickVerticalControlModePosition,
};

/**
 *  Roll/Pitch control velocity MAX value is 15m/s.
 *
 *  滚动、俯仰的控制的最大值是15米每秒
 */
extern const float AUTELVirtualStickRollPitchControlMaxVelocity;
/**
 *  Roll/Pitch control velocity MIN value is -15m/s.
 *
 *  滚动、俯仰的控制的最大小值是-15米每秒
 */
extern const float AUTELVirtualStickRollPitchControlMinVelocity;
/**
 *  Roll/Pitch control angle MAX value is 30 degrees.
 *
 *  滚动、俯仰的控制的最大小值是30度
 */
extern const float AUTELVirtualStickRollPitchControlMaxAngle;
/**
 *  Roll/Pitch control angle MIN value is -30 degrees.
 *
 *  滚动、俯仰的控制的最大小值是-30度
 */
extern const float AUTELVirtualStickRollPitchControlMinAngle;

/**
 *  Defines how manual roll and pitch values are interpreted by the aircraft.
 *
 *  定义了飞机的手动滚动和俯仰方式，
 */
typedef NS_ENUM (uint8_t, AUTELVirtualStickRollPitchControlMode){
    /**
     *  Sets the `VirtualStickControlMode` roll and pitch values to be an angle relative to
     *  a level aircraft. In the body coordinate system, positive and negative pitch angle is for the aircraft rotating about
     *  the y-axis in the positive direction or negative direction, respectively. Positive and negative roll angle is the positive direction or
     *  negative direction rotation angle about the x-axis, respectively.
     *  However in the ground coordinate system, positive and negative pitch angle is the angle value for the aircraft moving south and
     *  north, respectively. Positive and negative roll angle is the angle when the aircraft is moving east and west, respectively.
     *  Maximum angle is defined as `AUTELVirtualStickRollPitchControlMaxAngle`.
     *  Minimum angle is defined as `AUTELVirtualStickRollPitchControlMinAngle`.
     *
     *  给 飞机`VirtualStickControlMode` 的滚动和俯仰设置一个角度值。在体坐标系下，俯仰角值是指飞机自身平面相对于Y轴的角度，
     *  滚动角度是飞机自身平面相对于的X轴的角度
     *  地面坐标系下，  pitch angle 表示相对于南北方向的角度，roll angle 表示相对于东西的角度。
     *  `AUTELVirtualStickRollPitchControlMaxAngle` 是最大值
     *  `AUTELVirtualStickRollPitchControlMinAngle` 是最小值
     */
    AUTELVirtualStickRollPitchControlModeAngle,
    /**
     *  Sets the `VirtualStickControlMode` roll and pitch values to be a velocity.
     *  In the body coordinate system, positive and negative pitch velocity is for the aircraft moving towards the positive direction or
     *  negative direction along the pitch axis and y-axis, respectively. Positive and negative roll velocity is when the aircraft is moving towards
     *  the positive direction or negative direction along the roll axis and x-axis, respectively.
     *  However, in the ground coordinate system, positive and negative pitch velocity is for the aircraft moving east and west, respectively.
     *  Positive and negative roll velocity is when the aircraft is moving north and south, respectively.
     *  Maximum velocity is defined as `AUTELVirtualStickRollPitchControlMaxVelocity`.
     *  Minimum velocity is defined as `AUTELVirtualStickRollPitchControlMinVelocity`.
     *
     *  给 飞机`VirtualStickControlMode` 的滚动和俯仰设置一个角度速度值。在体坐标系下，俯仰角速度值是指飞机自身平面相对于Y轴的角速度，
     *  滚动角速度是飞机自身平面相对于的X轴的角速度
     *  地面坐标系下，  pitch velocity angle 表示相对于南北方向的角速度，roll velocity angle 表示相对于东西的角速度。
     *
     */
    AUTELVirtualStickRollPitchControlModeVelocity,
};

/**
 *  Yaw control angle MAX value is 180 degrees.
 *
 *  最大偏航角 180度
 */
extern const float AUTELVirtualStickYawControlMaxAngle;
/**
 *  Yaw control angle MIN value is -180 degrees.
 *
 *  最小偏航角 -180度
 */
extern const float AUTELVirtualStickYawControlMinAngle;
/**
 *  Yaw control angular velocity MAX value is 100 degrees/second.
 *
 *  最大偏航角速度 100度每秒
 */
extern const float AUTELVirtualStickYawControlMaxAngularVelocity;
/**
 *  Yaw control angular velocity MIN value is -100 degrees/second.
 *
 *  最小偏航角速度 -100度每秒
 *
 */
extern const float AUTELVirtualStickYawControlMinAngularVelocity;

/**
 *  Defines how manual yaw values are interpreted by the aircraft.
 *
 *  飞机偏航角类型
 */
typedef NS_ENUM (uint8_t, AUTELVirtualStickYawControlMode){
    /**
     * Sets the `VirtualStickControlMode` yaw values to be an angle relative to the front of the aircraft.
     * Positive and negative yaw angle is for the aircraft rotating clockwise and counterclockwise,
     * respectively. Maximum yaw angle is defined as `AUTELVirtualStickYawControlMaxAngle`. Minimum yaw
     * angle is defined as `AUTELVirtualStickYawControlMinAngle`.
     *
     * 设置机头一个偏航角，正负值表示顺时针或者逆时针；
     * `AUTELVirtualStickYawControlMaxAngle` 是最大偏航角
     * `AUTELVirtualStickYawControlMinAngle` 是最小偏航角
     *
     */
    AUTELVirtualStickYawControlModeAngle,
    /**
     * Sets the `VirtualStickControlMode` yaw values to be an angular velocity. Positive and negative
     * angular velocity is for the aircraft rotating clockwise and counterclockwise, respectively. Maximum
     * yaw angular velocity is defined as `AUTELVirtualStickYawControlMaxAngularVelocity`. Minimum yaw angular
     * velocity is defined as `AUTELVirtualStickYawControlMinAngularVelocity`.
     *
     *  设置机头一个偏航角速度，正负值表示顺时针或者逆时针；
     * `AUTELVirtualStickYawControlMaxAngle` 是最大偏航角速度
     * `AUTELVirtualStickYawControlMinAngle` 是最小偏航角速度
     *
     */
    AUTELVirtualStickYawControlModeAngularVelocity,
};


/**
 *
 *  This protocol provides delegate methods to update main controller's current state.
 *
 *  该协议提供实时更新主控当前状态的代理方法。
 *
 */
@protocol AUTELDroneMainControllerDelegate <NSObject>

/**
 *  @brief Callback function that updates the main controller's current state data. This method gets
 *  called 5 times per second after startUpdatingFlightControllerCurrentState is called.
 *
 *  该回调方法更新飞行器主控当前数据。在 AUTELDroneMainController 实例的 startUpdateMCSystemState 方法调用以后，该方法每秒被调用5次。
 *
 *  @param mc Instance of the main controller for which the data will be updated. 
 *
 *  将当前状态告知代理的主控对象
 *
 *  @param state Current state of the main controller. 
 *
 *  主控当前状态。
 *
 *  @see AUTELMCSystemState
 **/
- (void)mainController:(AUTELDroneMainController *_Nonnull)mc didUpdateSystemState:(AUTELMCSystemState *_Nonnull)state NS_SWIFT_NAME(mainController(_:didUpdateSystemState:));

@optional
 
/**
 *  @brief This callback method updates the current status data of the aircraft's RTK. The flight controller reports once every 1s..
 *
 *  该回调方法更新飞行器RTK当前状态数据。飞控1s上报1次。
 *
 *  @param mc Instance of the main controller for which the data will be updated.
 *
 *  将当前状态告知代理的主控对象
 *
 *  @param state Current state of the main controller.
 *
 *  RTK当前状态。
 *
 *  @see AUTELRTKStatusInfoModel
 **/
- (void)mainController:(AUTELDroneMainController *_Nonnull)mc didUpdateRTKState:(AUTELRTKStatusInfoModel *_Nonnull)state NS_SWIFT_NAME(mainController(_:didUpdateRTKState:));

/**
 *  @brief This callback method updates the aircraft RTK differential data.
 *
 *  该回调方法更新飞行器RTK差分数据。
 *
 *  @param mc Instance of the main controller for which the data will be updated.
 *
 *  将当前状态告知代理的主控对象
 *
 *  @param data RTK differential data.
 *
 *  RTK当前状态。
 *
 *  @see AUTELRTKStatusInfoModel
 **/
- (void)mainController:(AUTELDroneMainController *_Nonnull)mc didUpdateRTKDiffData:(NSData *_Nonnull)data NS_SWIFT_NAME(mainController(_:didUpdateRTKDiffData:));

/**
 *  @brief This callback method updates the current status data of the aircraft's LTE Module.
 *
 *  该回调方法更新飞行器4G模组相关信息当前状态数据。
 *
 *  @param mc Instance of the main controller for which the data will be updated.
 *
 *  将当前状态告知代理的主控对象
 *
 *  @param state Current state of the main controller.
 *
 *  4G模组相关信息当前状态。
 *
 *  @see AUTELLTEModuleInfoModel
 **/
- (void)mainController:(AUTELDroneMainController *_Nonnull)mc didUpdateLTEModuleState:(AUTELLTEModuleInfoModel *_Nonnull)state NS_SWIFT_NAME(mainController(_:didUpdateLTEModuleState:));
 
@end


/**
 * Through AUTELDroneMainController, you can know the current state of the aircraft's mian controller, Get and set the main controller's parameters, and send orders to the main controller.
 *
 * 通过 AUTELDroneMainController 类，你可以获得飞行器主控的当前状态，可以读写主控参数，也向主控发送命令。
 */
@interface AUTELDroneMainController : NSObject

/**
 *  @brief Returns an instance of AUTELDrone. drone.mainController is the same as self.
 *
 *  返回拥有当前实例的 AUTELDrone 实例，drone.mainController 与 self 是同一个实例。
 */
@property (weak, nonatomic, readonly) AUTELDrone * _Nullable drone;

/**
 *  @brief Returns an instance of delegate.
 *
 *  返回代理实例。
 *
 *  @discussion Implement mainController:didUpdateSystemState:state function to get main controller current status. 
 *  To get current status,invoke startUpdateMCSystemState function first When stopUpdateMCSystemState is called, mainController:didUpdateSystemState:state will not be invoked any more until startUpdateMCSystemState is called again.
 *
 *  通过该代理实例的 -mainController:didUpdateSystemState:state 方法，你可以实时获取主控当前状态。
 *  在获取实时状态前你需要调用 -startUpdateMCSystemState 方法，否则 -mainController:didUpdateSystemState:state 方法不会被调用。当你调用 -stopUpdateMCSystemState 方法后，-mainController:didUpdateSystemState:state 也将不会被调用，直到你再次调用 -startUpdateMCSystemState 方法。
 *
 *  @see AUTELDroneMainControllerDelegate
 */
@property (weak, nonatomic) id<AUTELDroneMainControllerDelegate> _Nullable mcDelegate;

/**
 *  @brief Read and write flight limitation parameters, such as maximum altitude and maximum horizontal speed.
 *
 *  通过 flightLimitation 你可以读写主控参数，例如：飞行器的最大飞行高度和距离，最大飞行水平速度等等。
 *
 *  @see AUTELFlightLimitation
 */
@property (weak, nonatomic, readonly) NSObject<AUTELFlightLimitation> * _Nullable flightLimitation;

/**
 *  @brief Get and set compass status. AUTELMCSystemState also includes compass status.
 *
 *  通过 compass 你可以获取飞行器磁力计的状态，也可以校准磁力计。在主控状态 AUTELMCSystemState 中也包含有磁力计状态。
 *
 *  @see AUTELCompass
 *  @see AUTELMCSystemState
 */
@property (weak, nonatomic, readonly) NSObject<AUTELCompass> * _Nullable compass;

/**
 *  @brief Manage auto navigation function, such as waypoints, orbit and follow me mission.
 *
 *  通过 navigationManager 你可以让飞行器执行自动飞行任务，例如航点任务，追踪任务，和环绕兴趣点任务。
 *
 *  @see AUTELNavigation
 *  @see AUTELMission
 *  @see AUTELWaypointMission
 *  @see AUTELHotPointMission
 *  @see AUTELFollowMeMission
 */
@property (nonatomic, readonly) AUTELNavigation * _Nonnull navigationManager;

/**
*  Get real-time vision status and send command to control vision.
*
*  通过该类，你可以获得视觉的实时状态，也可以向视觉发送命令，控制视觉。
*/
@property (nonatomic, readonly) AUTELFlightAssistant * _Nonnull flightAssistant;

/**
 *  Vertical control mode
 *  垂直控制方式
 */
@property(nonatomic, assign) AUTELVirtualStickVerticalControlMode verticalControlMode;

/**
 *  Roll/Pitch control mode.
 *  滚动/俯仰控制模式。
 */
@property(nonatomic, assign) AUTELVirtualStickRollPitchControlMode rollPitchControlMode;

/**
 *  Yaw control mode.
 *  偏航控制模式。
 */
@property(nonatomic, assign) AUTELVirtualStickYawControlMode yawControlMode;

/**
 *  @brief firmware version
 *
 *  飞控固件版本号
 */
@property(nonatomic, readonly) NSString * _Nullable firmwareVersion;

/**
 *  @brief take off height
 *
 *  以前起飞默认高度
 */
@property(nonatomic, assign, readonly) float takeOffHeight;

/**
 *  @brief Start to update main controller system state. After invoke this function, if app has a connected drone object, -mainController:didUpdateSystemState: will be invoked. To stop updating main controller state, just call -stopUpdateMCSystemState function.
 *
 *  开始更新主控的系统状态，在调用该方法后，如果 App 与飞行器建立了连接，则 mcDelegate 的 -mainController:didUpdateSystemState: 方法会被调用。
 *  可以调用 -stopUpdateMCSystemState 方法来停止主控实时状态的更新。
 *
 *  @see AUTELDroneMainControllerDelegate
 *  @see -stopUpdateMCSystemState
 */
- (void)startUpdateMCSystemState;

/**
 *  @brief Stop updating main controller system state. By calling this function, -mainController:didUpdateSystemState: will not be able to invoked any more until -startUpdateMCSystemState is called again.
 *
 *  停止更新主控系统状态，调用该方法后，mcDelegate 的 -mainController:didUpdateSystemState: 方法不会被调用，直到 -startUpdateMCSystemState 方法被再次调用
 *
 *  @see AUTELDroneMainControllerDelegate
 *  @see -startUpdateMCSystemState
 */
- (void)stopUpdateMCSystemState;

/**
 *  @brief Set default go home altitude.
 *
 *  设置飞机返航默认高度。
 *
 *  @param altitude Go home altitude in meter.
 *
 *  返航高度（m）。
 *
 *  @param block    Completion block.
 *
 *  完成 block。
 *
 *  @discussion Set the default altitude relative to take off point, default altitude must be set before go home is triggered. This can be useful if user can foresees the obstacles on return path and set the default altitude higher than the obstacles. If current altitude is higher than (or equals to) default go home altitude, the aircraft will remian current altitude and fly back to the home point, If current altitude is lower than default go home altitude, the aircraft will ascend to default go home altitdue and then fly back to the home point. The valid range for the altitude is from 30m to 800m.
 *
 *  Default altitude value must be smaller than maximum flight altitude. We can invoke [flightLimitation getMaxFlightHeightWithCompletion:] and [flightLimitation setMaxFlightHeight:withCompletion:] to read and write flight altitude limitation.
 *
 *  该默认高度是相对于起飞点的相对高度，该高度在飞行器返航前设置才生效。当你能预计在飞行器返航路线上的障碍的高度，可以将该高度设置为高于障碍高度，保证飞行器自动返航的安全。当飞行器自动返航时，如果飞行高度高于默认返航高度，飞行器将自动返航，否则飞行器会自动上升到默认高度，然后开始返航。该参数的范围为30米至800米。
 *
 *  默认返航高度不能大于飞行器的飞行高度限制，否则将设置失败，可以通过调用 flightLimitation 的 -getMaxFlightHeightWithCompletion: 和 -setMaxFlightHeight:withCompletion: 方法来读写飞行器的飞行高度限制。
 *
 *  @see -getGoHomeDefaultAltitudeWithCompletion:
 *  @see AUTELFlightLimitation
 */
- (void)setGoHomeDefaultAltitude:(float)altitude withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get default go home altitude. 
 *
 *  查询飞行器返航默认高度。
 *
 *  @param block  Completion block. This block includes 2 parameters. One is altitude which indicates the default go home altitude, another one is error which indicates error message. Error retuns nil if this function applies successfully.
 *
 *  完成block，该block包含两个参数：altitude 为飞行器的返航默认高度，error 为错误信息，如果查询成功，则为nil。
 */
- (void)getGoHomeDefaultAltitudeWithCompletion:(void(^_Nullable)(float altitude, NSError* _Nullable error))block;

/**
 *  @brief Set Forced flight mode.
 *
 *  设置强制飞行态模式。
 *
 *  @param enable YES if drone can enable Forced flight mode, else NO.
 *
 *
 *  @param block Completion block.
 *
 *  完成block
 *
 *
 *  调用该方法时请慎重，Forced flight模式下，飞行器无法安全起飞，为了您的飞行安全，请在平整地面上起飞。
 **/
- (void)setForcedFlightEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get Forced flight setting.
 *
 *  查询强制飞行模式
 *  @see -setForcedFlightEnable:withCompletion:
 **/
- (void)getForcedFlightEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError* _Nullable error))block;

/**
 *  @brief Set whether RC can enable ATTI mode.
 *
 *  设置是否可以通过遥控器模式切换开关将飞行器的主模式切换为姿态模式。
 *
 *  @param enable YES if RC can enable ATTI mode, else NO.
 *
 *  YES:你可以通过遥控器的飞行模式切换开关将主模式切换为姿态模式，NO:不能手动切换姿态模式。
 *
 *  @param block Completion block.
 *
 *  完成block
 *
 *  @discussion AUTELMCSystemState.main presents current maincontroller mode.
 *
 *  AUTELMCSystemState.mainMode 表示当前飞行器的主模式。
 *
 *  @note Under ATTI mode, main controller does not have GPS services, the aircraft can not hover in the air. Please use GPS mode for safety.
 *
 *  调用该方法时请慎重，ATTI模式下，飞行器无法定位返航点及稳定悬停，为了您的飞行安全，请在GPS模式下飞行。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELMainControllerMainMode
 *  @see -getCutToATTIModeEnableWithCompletion:
 **/
- (void)setCutToATTIModeEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get ATTI enable setting to check whether RC can enable ATTI mode.
 *
 *  查询是否可以通过遥控器将飞行器的飞行模式切换为姿态模式
 *
 *  @param block Completion block. This block includes 2 parameters. One is enable which set to YES if RC can enable ATTI mode, else NO. Another one is error ndicates error message. Error retuns nil if this function applies successfully.
 *
 *  完成 block，包含两个参数：enable 如果为YES表示可以通过遥控器将飞行器的飞行模式切换为姿态模式，否则表示不能通过遥控器将飞行器的飞行模式切换为姿态模式，error 表示错误信息，如果查询成功值为nil。
 *
 *  @see -setCutToATTIModeEnable:withCompletion:
 **/
- (void)getCutToATTIModeEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError* _Nullable error))block;

/**
 *  @brief Get the aircraft indoor mode enable switch.
 *
 *  查询飞机室内模式使能开关
 *
 *  @param block Completion block. .
 *
 *  完成 block。
 *
 *  @see -setInRoomModeEnable:withCompletion:
 **/
- (void)getInRoomModeEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError* _Nullable error))block;

/**
 *  @brief Set the aircraft indoor mode enable switch.
 *
 *  设置飞机室内模式使能开关。
 *
 *  @param enable YES if RC can enable indoor mode, else NO.
 *
 *  YES:打开室内模式使能开关;NO:关闭室内模式使能开关
 *
 *  @param block Completion block.
 *
 *  完成block
 *
 *  @see -getInRoomModeEnableWithCompletion:
 **/
- (void)setInRoomModeEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief Get front and rear obstacle avoidance switches.
 *
 *  查询前后避障开关
 *
 *  @param block Completion block. .
 *
 *  完成 block。
 *
 *  @see -setFrontRearOAEnable:withCompletion:
 **/
- (void)getFrontRearOAEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError* _Nullable error))block;

/**
 *  @brief Set front and rear obstacle avoidance switches.
 *
 *  设置前后避障开关。
 *
 *  @param enable YES Turn on the front and rear obstacle avoidance switch, else NO Turn off the front and rear obstacle avoidance switches.
 *
 *  YES:打开前后避障开关;NO:关闭前后避障开关
 *
 *  @param block Completion block.
 *
 *  完成block
 *
 *  @see -getFrontRearOAEnableWithCompletion:
 **/
- (void)setFrontRearOAEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get left and right obstacle avoidance switches.
 *
 *  查询左右避障开关
 *
 *  @param block Completion block. .
 *
 *  完成 block。
 *
 *  @see -setLeftRightOAEnable:withCompletion:
 **/
- (void)getLeftRightOAEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError* _Nullable error))block;

/**
 *  @brief Set left and right obstacle avoidance switches.
 *
 *  设置左右避障开关。
 *
 *  @param enable YES Turn on the left and right obstacle avoidance switch, else NO Turn off the left and right obstacle avoidance switches.
 *
 *  YES:打开左右避障开关;NO:关闭左右避障开关
 *
 *  @param block Completion block.
 *
 *  完成block
 *
 *  @see -getLeftRightOAEnableWithCompletion:
 **/
- (void)setLeftRightOAEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get top obstacle avoidance switches.
 *
 *  查询上方避障开关
 *
 *  @param block Completion block. .
 *
 *  完成 block。
 *
 *  @see -setFrontRearOAEnable:withCompletion:
 **/
- (void)getTopOAEnableWithCompletion:(void(^_Nullable)(BOOL enable, NSError* _Nullable error))block;

/**
 *  @brief Set top obstacle avoidance switches..
 *
 *  设置上方避障开关。
 *
 *  @param enable YES Turn on the top obstacle avoidance switch, else NO Turn off the top obstacle avoidance switches.
 *
 *  YES:打开上方避障开关;NO:关闭上方避障开关
 *
 *  @param block Completion block.
 *
 *  完成block
 *
 *  @see -getTopOAEnableWithCompletion:
 **/
- (void)setTopOAEnable:(BOOL)enable withCompletion:(AUTELCompletionBlock)block;


/**
 *  @brief Aircraft starts to take off, and then hover at 4m height.
 *
 *  让飞机自动起飞，并在4m的高度悬停。
 *
 *  @param block Completion Block. 完成block。
 *
 *  @discussion Motors must be on before invoke this function, or block returns AUTELSDKFlightControllerErrorMotorNotWork error. AUTELMCSystemState.isMotorWorking indicates the status of motors. AUTELMCSystemState.flightMode indicates the status of aircraft, if AUTELMCSystemState.flightMode equals to AutelMCFlightModeTakeoff, then aircraft will take off. The return value of block does not indicate the real status of aircraft, it only tells whether the main controller received the command or not.
 *
 *  在调用该方法起飞飞行器前，飞行器的电机必须已经启动，否则该方法将执行失败 block 返回 AUTELSDKFlightControllerErrorMotorNotWork 错误。AUTELMCSystemState.isMotorWorking 表示电机的转动状态。
 *  block 返回执行成功只能说明飞行器接收到了起飞命令，飞行器是否真的起飞要通过 AUTELMCSystemState.flightMode 是否等于 AutelMCFlightModeTakeoff 来判断。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELMainControllerFlightMode
 *  @see AUTELSDKFlightControllerError
 **/
- (void)startTakeoffWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Call this function to start landing.
 *
 *  让飞行器开始自动降落。
 *
 *  @param block Completion Block. 完成block。
 *
 *  @discussion AUTELMCSystemState.flightMode indicates the status of aircraft, if AUTELMCSystemState.flightMode equals to AutelMCFlightModeLanding, then aircraft will start to land. The return value of block does not indicate the real status of aircraft, it only tells whether the main controller received the command or not.
 *
 *  block 返回执行成功只能说明飞行器接收到了降落命令，飞行器是否真的开始自动降落要通过 AUTELMCSystemState.flightMode 是否等于 AutelMCFlightModeLanding 来判断。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELMainControllerFlightMode
 */
- (void)startLandingWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Cancel auto landing. 
 *
 *  取消飞行器自动降落
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion This function cancels auto land and let the aircraft hover in the air. It can be applied successfully only if it is invoked while aircraft is landing, else it returns AUTELSDKFlightControllerErrorModeError error. 
 *
 *  AUTELMCSystemState.flightMode indicates the status of aircraft, if AUTELMCSystemState.flightMode dosn't equals to AutelMCFlightModeLanding, then aircraft will cancel auto landing. The return value of block does not indicate the real status of aircraft, it only tells whether the main controller received the command or not.
 *
 *  如果调用该方法时飞行器正在自动降落，飞机将会停止降落，并在当前位置悬停，如果飞行器没有在降落，该方法将执行失败，返回 AUTELSDKFlightControllerErrorModeError 错误。
 *
 *  block 返回执行成功只能说明飞行器接收到了取消降落命令，飞行器是否真的开始取消自动降落需要根据 AUTELMCSystemState.flightMode 是否不等于 AutelMCFlightModeLanding 来判断。
 *
 *  @see AUTELSDKFlightControllerError
 *  @see AUTELMCSystemState
 *  @see AUTELMainControllerFlightMode
 */
- (void)cancelLandingWithComletion:(AUTELCompletionBlock)block;

/**
 *  @brief Turn on the motors
 *
 *  启动飞行器电机。
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion AUTELMCSystemState.isMotorWorking indicates the status of motors, if AUTELMCSystemState.isMotorWorking is YES, then motors are running. The return value of block does not indicate the real status of aircraft, it only tells whether the main controller received the command or not.
 *
 *  block 返回执行成功只能说明飞行器收到了启动电机命令，电机是否开启要通过 AUTELMCSystemState.isMotorWorking 是否为 YES 来判断。
 *
 *  @see AUTELMCSystemState
 */
- (void)turnOnMotorWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Call this function to trigger aircraft go home. Aircraft will fly back to the home point and then auto land on the ground.
 *
 *  调用该方法，飞行器将开始返航，并在回到Home点后自动降落。
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion  If compass is abnormal (The value of AUTELMCSystemState.isCompassError is YES) or GPS singal is weak (The value of AUTELMCSystemState.isCompassError is YES) or home point is invalid (The value of AUTELMCSystemState.isHomeInvalid is YES), then block returns AUTELSDKFlightControllerErrorCompassError,  AUTELSDKFlightControllerErrorBadGPS, AUTELSDKFlightControllerErrorHomePointNotRecord error message accordingly
 *
 *  AUTELMCSystemState.flightMode indicates the status of aircraft, if AUTELMCSystemState.flightMode equals to AutelMCFlightModeManualGoHome, then aircraft will start to go home. The return value of block does not indicate the real status of aircraft, it only tells whether the main controller received the command or not.
 *
 *  如果飞行器的磁力计异常（ AUTELMCSystemState.isCompassError 为 YES ），GPS信号弱（ AUTELMCSystemState.isGPSWeakWarning 为 YES ）或 Home 点无效（ AUTELMCSystemState.isHomeInvalid 为 YES ），该方法将执行失败，block 将分别返回 AUTELSDKFlightControllerErrorCompassError，AUTELSDKFlightControllerErrorBadGPS，或 AUTELSDKFlightControllerErrorHomePointNotRecord 错误信息。
 *
 *  block 返回执行成功只能说明飞行器收到了返航命令，飞行器是否真的返航，需要根据 AUTELMCSystemState.flightMode 是否等于 AutelMCFlightModeManualGoHome 来判断。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELSDKFlightControllerError
 */
- (void)startGoHomeWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Call this function to cancel go home.
 *
 *  取消返航
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion This function can be applied successfully only if it is invoked while aircraft is going home, else it returns AUTELSDKFlightControllerErrorModeError error. If AUTELMCSystemState.isAutoFlyingToHomePoint is NO, then aircraft will cancel go home. The return value of block does not indicate the real status of aircraft, it only tells whether the main controller received the command or not.
 *
 *  如果飞行器没有处于返航状态，该方法将执行失败，block 将返回 AUTELSDKFlightControllerErrorModeError 错误。
 *  block 返回执行成功只能说明飞行器收到了取消返航的命令，飞行器是否真的取消返航需要根据 AUTELMCSystemState.isAutoFlyingToHomePoint 是否为 NO 来判断。
 *
 *  @see AUTELSDKFlightControllerError
 *  @see AUTELMCSystemState
 */
- (void)cancelGoHomeWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Turn on front LED indicator light. 
 *
 *  打开飞行器方向指示灯。
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion AUTELMCSystemState.isFrontLEDTurnOn indicates the status of front LED. Call -turnOffFrontLEDWithCompletion function to turn off the front LED.
 *
 *  通过 AUTELMCSystemState.isFrontLEDTurnOn 可以知道当前方向指示灯的开关状态。调用 -turnOffFrontLEDWithCompletion: 方法可以关闭方向指示灯。
 *
 *  @see AUTELMCSystemState
 *  @see -turnOffFrontLEDWithCompletion:
 */
- (void)turnOnFrontLEDWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Turn off front LED indicator light. 
 *
 *  关闭飞行器方向指示灯。
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion If the front LED has an effect on recording or taking pictures, this function can be invoked to turn off the front LED. AUTELMCSystemState.isFrontLEDTurnOn indicates the status of front LED. Call turnOnFrontLEDWithCompletion function to turn on the front LED.
 *
 *  如果你觉得方向指示灯对你的拍照或录像有影响，可以调用该方法关闭方向指示灯，飞行器尾灯不受影响。
 *  通过 AUTELMCSystemState.isFrontLEDTurnOn 可以知道当前方向指示灯的开关状态。调用 -turnOnFrontLEDWithCompletion: 方法可以打开方向指示灯。
 *
 *  @see AUTELMCSystemState
 *  @see -turnOnFrontLEDWithCompletion:
 */
- (void)turnOffFrontLEDWithCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Turn off the aircraft and turn off the forearm lights and rear arm lights.
*
*  关闭飞行器关闭前臂灯和后臂灯。
*
*  @param block Completion Block.
*
*  完成block。
*/
- (void)turnOffAllLEDWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief flashing LED indicator taking pictures.
 *
 *  拍照闪灯指示。
 *
 *  @param block Completion Block.
 *
 *  完成block。
 */
- (void)photographFlashingLEDWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief flashing LED indicator recording.
 *
 *  录像闪灯指示。
 *
 *  @param block Completion Block.
 *
 *  完成block。
 */
- (void)recordFlashingLEDWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get front wall light switch status
 *
 *  查询前壁灯开关状态
 */
- (void)getFrontLEDStateWithCompletion:(void(^_Nullable)(BOOL isTurnOn, NSError * _Nullable error))block;

/**
 *  @brief Get the status of the front and rear LED lights.
 *
 *  查询前后LED灯开关状态
 */
- (void)getControlLEDStateWithCompletion:(void(^_Nullable)(AUTELAircraftLedState state, NSError * _Nullable error))block;

/// 控制臂灯
/// @param state 见AUTELAircraftLedState定义
/// @param block Completion Block.
- (void)controlLEDWithCompletion:(AUTELAircraftLedState)state withCompletion:(AUTELCompletionBlock)block;


/*
 *  @brief Set low battery waning data, percentage of voltage in range [25, 50]. 
 *
 *  设置低电警报的剩余电量百分比下限，范围[25, 50]。
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion When battery current electricity volum is lower than the low battery warning threashold, AUTELMCSystemState.powerWarning returns a low battery warning message, and force the aircraft to go home.
 *
 *  飞行器剩余电量低于该下限值时，将发出低电警报（AUTELMCSystemState.powerWarning 表示低电报警信息），并开始自动返航。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELDroneLowPowerWarning
 */
- (void)setLowBatteryWarning:(uint8_t)percent withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get low battery warning data. 
 *
 *  查询飞行器低电警报剩余电量百分比下限。
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion When battery current electricity volum is lower than the low battery warning threashold, AUTELMCSystemState.powerWarning returns a low battery warning message, and force the aircraft to go home.
 *
 *  飞行器剩余电量低于该下限值时，将发出低电警报（AUTELMCSystemState.powerWarning 表示低电报警信息），并开始自动返航。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELDroneLowPowerWarning
 */
- (void)getLowBatteryWarningWithCompletion:(void(^_Nullable)(uint8_t percent, NSError* _Nullable error))block;

/**
 *  @brief Set serious low battery waning data, percentage of voltage in range [10, 25]. 
 *
 *  设置严重低电警报剩余电量百分比下限，范围[10, 25]。
 *
 *  @param percent Percentage of serious low battery. 
 *
 *  剩余电量百分比。
 *
 *  @param block   Completion Block. 
 *
 *  完成block。
 *
 *  @discussion When battery current electricity volum is lower than the critical low battery warning threashold, AUTELMCSystemState.powerWarning returns a critical low battery warning message, and force the aircraft to land.
 *
 *  飞行器剩余电量低于该下限值时，将发出严重低电警报（AUTELMCSystemState.powerWarning 表示低电报警信息），并开始原地降落。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELDroneLowPowerWarning
 */
- (void)setSeriousLowBattery:(uint8_t)percent withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get serious low battery warning threashold in percentage. 
 *
 *  查询严重低电警报剩余电量百分比下限。
 *
 *  @param block Completion Block.
 *
 *  完成 block
 *
 *  @discussion When battery current electricity volum is lower than the critical low battery warning threashold, AUTELMCSystemState.powerWarning returns a critical low battery warning message, and force the aircraft to land.
 *
 *  飞行器剩余电量低于该下限值时，将发出严重低电警报（AUTELMCSystemState.powerWarning 表示低电报警信息），并开始原地降落。
 *
 *  @see AUTELMCSystemState
 *  @see AUTELDroneLowPowerWarning
 */
- (void)getSeriousLowBatteryWarningwithCompletion:(void(^_Nullable)(uint8_t percent, NSError* _Nullable error))block;

/**
 *  @brief Call this function to set aircraft current location as home point.
 *
 *  将飞机当前位置设置为Home点。
 *
 *  @param block Completion Block. 
 *
 *  完成block。
 *
 *  @discussion Get current aircraft location by read the value of AUTELMCSystemState.homeLocation.
 *
 *  你可以通过 AUTELMCSystemState.homeLocation 知道飞行器的当前返航点。
 *
 *  @see AUTELMCSystemState
 */
- (void)setHomePointAtCurrentGPSPositionWithComletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set a specific GPS coordinate as home point. 
 *
 *  更改返航点的坐标
 *
 *  @param homePoint GPS coordinate of home point.
 *
 *  返航点的GPS坐标。
 *
 *  @param block     Completion Block. 
 *
 *  完成block。
 *
 *  @discussion This function fails to apply if new home point is over 5km away from the aircraft, and block returns AUTELSDKFCErrorDesNewHomeTooFarAway error message. If this function applies successfully, the aircraft will return to new home point. Get current aircraft location by read the value of AUTELMCSystemState.homeLocation.
 *
 *  如果新的返航点距离当前飞机位置超过5km，该方法将执行失败，block 返回 AUTELSDKFCErrorDesNewHomeTooFarAway 错误。
 *  如果该方法执行成功，那么飞行器自动返航时，将飞到新的返航点，请谨慎调用该方法。
 *  飞行器每次启动电机都会从新将飞行的返航点更新为飞机的当前位置。
 *  你可以通过 AUTELMCSystemState.homeLocation 知道飞行器的当前返航点。
 *
 *  @see AUTELSDKFlightControllerError
 *  @see AUTELMCSystemState
 */
- (void)setHomePoint:(CLLocationCoordinate2D)homePoint withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Open USB data port.
 *
 *  打开飞行器的USB数据口
 *
 *  @return  Returns NO if motors are on, else return YES.
 *
 *  如果飞行器电机处于转动状态时，此方法将执行失败，返回NO，否则返回YES。
 *
 *  @discussion Call this function to open USB data port of the aircraft, and then the user can connect the aircraft to PC to read flight data. 
 *
 *  This function returns NO if motors are on. Otherwise it returns YES and disable the motors. App maybe not able to accept any data from main controller until the aircraft restarted.
 *
 *  调用该方法，可以打开飞行器的USB数据口，打开USB数据口后，你的电脑可以通过USB读取飞行器数据。
 *
 *  当飞行器电机转动时调用该方法，该方法将执行失败，返回 NO。
 *  如果该方法调用成功，飞行器的电机无法转动，App可能会接收不到飞控数据，直到你重启飞行器。
 */
- (BOOL)openDroneUSB;

/**
 *  @brief Invoke this method to start IMU calibration.
 *
 *  调用该方法让飞行器进入IMU校准。
 *
 *  @param block if main controller received the command, returns nil. Else returns error message.
 *
 *  如果命令发送成功，block 的 error 返回 nil，否则返回错误信息。
 *
 *  @discussion This method can be invoked when motors are on and returns AUTELSDKFlightControllerErrorMotorWorking error.
 *
 *  当飞行器电机转动时，该方法将执行失败，返回 AUTELSDKFlightControllerErrorMotorWorking 错误
 *
 *  @see AUTELIMUCalibrationWarn
 *  @see AUTELIMUCalibrationStatus
 */
- (void)startCalibrationIMUWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get aircraft binding information
 *
 *  查询飞行器的绑定信息
 *
 *  @param block 完成 block，bindState表示当前飞行器是否已经绑定了，sn表示飞行器的序列号，如果 bindState 为 AUTELDroneBindStateNoSupport 表示该飞行器不支持绑定功能，你应该忽略 sn，如果查询成功 error 为 nil，否则 error 包含错误信息。
 */
- (void)getDronBindInfoWithCompletion:(void(^_Nullable)(AUTELDroneBindUserState bindState, NSString * _Nullable sn, NSError * _Nullable error))block;

/**
 set aircraft binding

 @param block completion block
 */
- (void)bindDroneWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set the yaw axis joystick sensitivity
 *
 *  设置yaw轴摇杆感度
 *
 *  @param sensitivity 代设置的感度,范围为[0.2, 0.8],如果超过该范围block将返回错误。
 *  @param block 完成block。
 */
- (void)setYawStickSensitivity:(float)sensitivity withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get yaw axis joystick sensitivity
 *
 *  查询yaw轴摇杆感度
 *
 *  @param block 完成block。
 */
- (void)getYawStickSensitivityWithCompletion:(void(^_Nullable)(float sensitivity, NSError* _Nullable error))block;

/**
 *  @brief Set the Pitch And Roll axis joystick sensitivity
 *
 *  设置pitch轴摇杆感度
 *
 *  @param sensitivity 代设置的感度,范围为[0.2, 0.8],如果超过该范围block将返回错误。
 *  @param block 完成block。
 */
- (void)setPitchAndRollStickSensitivity:(float)sensitivity withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get Pitch And Roll axis joystick sensitivity
 *
 *  查询Pitch And Roll轴摇杆感度
 *
 *  @param block 完成block。
 */
- (void)getPitchAndRollStickSensitivityWithCompletion:(void(^_Nullable)(float sensitivity, NSError* _Nullable error))block;


/**
 *  @brief Set the Pitch axis joystick sensitivity
 *
 *  设置pitch轴摇杆感度
 *
 *  @param sensitivity 代设置的感度,范围为[0.2, 0.8],如果超过该范围block将返回错误。
 *  @param block 完成block。
 */
- (void)setPitchStickSensitivity:(float)sensitivity withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get Pitch axis joystick sensitivity
 *
 *  查询Pitch轴摇杆感度
 *
 *  @param block 完成block。
 */
- (void)getPitchStickSensitivityWithCompletion:(void(^_Nullable)(float sensitivity, NSError* _Nullable error))block;

/**
 *  @brief Set the Roll axis joystick sensitivity
 *
 *  设置Roll轴摇杆感度
 *
 *  @param sensitivity 代设置的感度,范围为[0.2, 0.8],如果超过该范围block将返回错误。
 *  @param block 完成block。
 */
- (void)setRollStickSensitivity:(float)sensitivity withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get Roll axis joystick sensitivity
 *
 *  查询Roll轴摇杆感度
 *
 *  @param block 完成block。
 */
- (void)getRollStickSensitivityWithCompletion:(void(^_Nullable)(float sensitivity, NSError* _Nullable error))block;


/**
 *  @brief Set the Thrust axis joystick sensitivity
 *
 *  设置Thrust轴摇杆感度
 *
 *  @param sensitivity 代设置的感度,范围为[0.2, 0.8],如果超过该范围block将返回错误。
 *  @param block 完成block。
 */
- (void)setThrustStickSensitivity:(float)sensitivity withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get Thrust axis joystick sensitivity
 *
 *  查询Thrust轴摇杆感度
 *
 *  @param block 完成block。
 */
- (void)getThrustStickSensitivityWithCompletion:(void(^_Nullable)(float sensitivity, NSError* _Nullable error))block;


/**
 *  @brief Set the attitude  sensitivity
 *
 *  设置姿态灵敏度
 *
 *  @param sensitivity 代设置的感度,范围为[0.2, 1.0],如果超过该范围block将返回错误。
 *  @param block 完成block。
 */
- (void)setAttitudeStickSensitivity:(float)sensitivity withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get attitude  sensitivity
 *
 *  查询姿态灵敏度
 *
 *  @param block 完成block。
 */
- (void)getAttitudeStickSensitivityWithCompletion:(void(^_Nullable)(float sensitivity, NSError* _Nullable error))block;

/**
 *  @brief Set the brake  sensitivity
 *
 *  设置刹车灵敏度
 *
 *  @param sensitivity 代设置的感度,范围为[0.5, 2.0],如果超过该范围block将返回错误。
 *  @param block 完成block。
 */
- (void)setBrakeStickSensitivity:(float)sensitivity withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get brake sensitivity
 *
 *  查询刹灵敏度
 *
 *  @param block 完成block。
 */
- (void)getBrakeStickSensitivityWithCompletion:(void(^_Nullable)(float sensitivity, NSError* _Nullable error))block;

/**
 *  @brief Set the yaw sch sensitivity
 *
 *  设置偏航行程灵敏度
 *
 *  @param sensitivity 代设置的感度,范围为[0.5, 2.5],如果超过该范围block将返回错误。
 *  @param block 完成block。
 */
- (void)setYawSchStickSensitivity:(float)sensitivity withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief get pitch axis joystick sensitivity
 *
 *  查询偏航行程灵敏度
 *
 *  @param block 完成block。
 */
- (void)getYawSchStickSensitivityWithCompletion:(void(^_Nullable)(float sensitivity, NSError* _Nullable error))block;


/**
 *  @brief Set the SD card reading frequency
 *
 *  设置SD卡读取频率
 *
 *  @param block 完成block。
 */
- (void)setSDLogSen:(uint8_t)sen withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get the SD card reading frequency
 *
 *  @brief 查询SD卡读取频率
 *
 *  @param block 完成block。
 */
- (void)getSDLogSenWithCompletion:(void(^_Nullable)(uint8_t sen, NSError* _Nullable error))block;

/**
 *  获取参数列表请求（仅用于内部测试）
 */
- (void)getParamList;

/**
 *  设置参数（仅用于内部测试）
 */
- (BOOL)setParameterWithData:(float)data
                    withName:(NSString *_Nonnull)name
                withParameterData:(int)dataTyp;

@end

@interface AUTELDroneMainController (VirtualStickControlMode)

/**
 is virtual stick control mode available
 
 virtual stick control mode 是否可用

 @return bool
 */
- (BOOL)isVirtualStickControlModeAvailable;

/**
 enable virtual joy stick control mode
 
 激活虚拟摇杆模式

 @param result completion block
 */
- (void)enableVirtualJoyStickControlModeWithCompletion:(AUTELCompletionBlock)result;

/**
 enable virtual joy stick yaw control mode

 启用虚拟摇杆偏航控制模式
 
 @param result completion block
 */
- (void)enableVirtualJoyStickYawControlModeWithCompletion:(AUTELCompletionBlock)result;

/**
 disable virtual stick yaw control mode

 禁用虚拟摇杆偏航控制模式
 
 @param result completion block
 */
- (void)disableVirtualStickControlModeWithCompletion:(AUTELCompletionBlock)result;

/**
 send virtual stick flight control data
 发送虚拟摇杆飞控数据

 @param stickData virtual stick flight control data
 @param 虚拟摇杆飞控数据
 @param result completion block
 */
- (void)sendVirtualStickFlightControlData:(AutelVirtualStickFlightControlData)stickData withCompletion:(AUTELCompletionBlock)result;

@end

@interface AUTELDroneMainController (RTK)


/// Get network RTK authentication information
/// 获取网络RTK认证信息
/// @param block completion block
- (void)getRTKAuthInfoWithCompletion:(AUTELGetRTKAuthInfoCompletionBlock)block ;

/// Set network RTK account information
/// 设置网络 RTK 账户信息
/// @param account Account
/// 账户
/// @param pwd password
/// 密码
/// @param deviceID device ID
/// 设备ID
/// @param deviceType device type
/// 设备类型
/// @param Completion block
/// 完成回调
- (void)setRTKAuthInfo:(NSString * _Nonnull)account pwd:(NSString * _Nonnull)pwd deviceID:(NSString * _Nonnull)deviceID deviceType:(NSString * _Nonnull)deviceType withCompletion:(AUTELCompletionBlock)block;

/// Upload RTK Different Data
/// 上传RTK查分数据
/// @param streamData data
/// 数据
/// @param Completion Completion block
/// 完成回调
- (void)uploadeRTKDiffData:(NSData *_Nullable)streamData withCompletion:(AUTELCompletionBlock)block;

/// Get Ntrip authentication information
/// 获取 Ntrip 授权信息
/// @param Completion Completion block
/// 完成回调
- (void)getNtripAuthInfoWithCompletion:(void(^_Nullable)(AUTELNtripAuthInfoModel * _Nullable model, NSError* _Nullable error))block;

/// Set Ntrip authentication information
/// 设置Ntrip RTK账号信息
/// @param Completion Completion block
/// 完成回调
- (void)setNtripAuthInfo:(AUTELNtripAuthInfoModel * _Nullable)model withCompletion:(AUTELCompletionBlock)block;

/// Get MQTT authentication information
/// 获取 MQTT 授权信息
/// @param Completion Completion block
/// 完成回调
- (void)getMQTTAuthInfoWithCompletion:(void(^_Nullable)(AUTELMQTTAuthInfoModel * _Nullable model, NSError* _Nullable error))block;

/// Set MQTT authentication information
/// 设置 MQTT RTK账号信息
/// @param Completion Completion block
/// 完成回调
- (void)setMQTTAuthInfo:(AUTELMQTTAuthInfoModel * _Nullable)model withCompletion:(AUTELCompletionBlock)block;
 
@end


@interface AUTELDroneMainController (TransferFile)

/**
*  @brief Check if the designated  no-fly zone file needs to be uploaded.
*  检查指定的禁飞区文件是否需要上传。
*
*  @param country Country code.
*  国家码
*
*  @param digest MD5 summary string of no-fly zone files.
*  禁飞区文件的 MD5 摘要字符串
*
*  @param block Completion Block.
*  完成block。
*/
- (void)checkNfzNeedUpload:(NSString *_Nonnull)country andDigest:(NSString *_Nullable)digest withCompletion:(AUTELCompletionBlock)block;


/// Check if the designated  no-fly zone file needs to be uploaded
/// 检查指定禁飞区文件是否需要上传
///
/// @param country  Country code.
/// 国家码
///
/// @param filePath filePath
/// 文件路径
///
/// @param block  Completion Block, code = 0 do not need upload, else need upload.
/// 完成回调，code = 0 不需要上传，否则需要上传。
- (void)checkNfzNeedUpload:(NSString * _Nonnull)country filePath:(NSString * _Nullable)filePath withCompletion:(void(^_Nullable)(int code, NSError* _Nullable error))block;

- (void)uploadNfzFileWithCountry:(NSString *_Nonnull)country
                        filePath:(NSString *_Nonnull)filePath
                 withStartUpLoad:(void(^_Nullable)(int code))start//code == 0：不需要上传，code == 1：开始上传，
                    withProgress:(AUTELProgressHandler)progress
                  withCompletion:(AUTELCompletionBlock)block;


/// Check if the designated  no-fly zone file needs to be uploaded.
/// 检查指定禁飞区文件是否需要上传。
///
/// @param fileName file name
/// 文件名
///
/// @param progress upload progress
/// 上传进度
///
/// @param block Completion Block.
/// 完成回调
- (void)uploadAuthfzFileWithModels:(NSArray <AUTELTransferAuthFlyzoneFileModel *> *_Nonnull)models
                            fileName:(NSString *_Nonnull)fileName
                    withProgress:(AUTELProgressHandler)progress
                      withCompletion:(AUTELCompletionBlock)block;

@end



@interface AUTELDroneMainController (Accessories)

/// Upload mp3 file to Accessories
/// 上传mp3文件到喊话器
///
/// @param mp3Data mp3 Data
/// mp3 数据
///
/// @param block completion block
/// 完成回调
- (void)uploadIntercomMp3FileData:(NSData *_Nullable)mp3Data
                        completion:(AUTELCompletionBlock)block;

/// Upload real time mp3 file to Accessories
/// 上传实时mp3文件到喊话器
///
/// @param mp3Data mp3 Data
/// mp3 数据
///
/// @param block completion block
/// 完成回调
- (void)uploadRealTimeMp3FileData:(NSData *_Nullable)mp3Data
                       completion:(AUTELCompletionBlock)block;

/// Cancel upload mp3 data
/// 取消上传
- (void)cancelUploadInterMp3FileData;

/// Control night light brightness command
/// 控制夜航灯亮度命令
///
/// @param luminance luminance
/// 亮度
///
/// @param block ompletion block
/// 完成回调
- (void)updateNlightLuminance:(int)luminance
                   completion:(void (^_Nullable)(NSDictionary * _Nullable answer, NSError * _Nullable error))block;


/// Control searchlight brightness command
/// 控制探照灯亮度命令
///
/// @param luminance luminance
/// 亮度
///
/// @param block ompletion block
/// 完成回调
- (void)updateSlightLuminance:(int)luminance
                   completion:(void (^_Nullable)(NSDictionary * _Nullable answer, NSError * _Nullable error))block;

/// Megaphone volume command
/// 喊话器音量大小命令
/// @param volume volume
/// @param block ompletion block
/// 完成回调
- (void)updateSpeakerVolume:(int)volume
                 completion:(void (^_Nullable)(NSDictionary * _Nullable answer, NSError * _Nullable error))block;

@end
