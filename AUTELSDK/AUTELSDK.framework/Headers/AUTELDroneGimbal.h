//
//  AUTELDroneGimbal.h
//  AUTELSDK
//
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Define gimbal work mode.
 *
 *  定义云台工作模式。
 */
typedef NS_ENUM(uint8_t, AUTELDroneGimbalWorkMode){
    /**
     *  Free mode
     *
     *  自由模式
     */
    GimbalAttitudMode,
    
    /**
     *  FPV mode
     *
     *  第一人称视角模式
     */
    GimbalFpvMode,
    
    /**
     * Follow mode
     */
    GimbalYawFollowMode,
    
    /**
     *  Panorama
     *
     *  跟踪模式
     */
    GimbalPanoramaMode,
    
    /**
     *  Unknown
     *
     *  未知
     */
    GimbalWorkModeUnknown = 0xFF,
};

/**
 *  Gimbal attitude
 *
 *  云台姿态
 */
typedef struct {
    /**
     *  @brief Gimbal pitch angle (°)
     *
     *  云台俯仰角（°）
     */
    float pitch;
    /**
     *  @brief Gimbal roll angle (°)
     *
     *  云台横滚角（°）
     */
    float roll;
    /**
     *  @brief Gimbal yaw angle (°)
     *  
     *  云台偏航角（°）
     */
    float yaw;
} AUTELGimbalAttitude;

/**
 *  Gimbal pitch speed
 *
 * 定义云台各轴速度
 */
typedef struct {
    /**
     *  @brief Gimbal pitch speed
     *
     *  @brief 云台 Pitch 轴速度
     */
    float pitchSpeed;
    
    /**
     *  @brief Gimbal yaw speed
     *
     *  @brief 云台 Yaw 轴速度
     */
    float yawSpeed;
    
    /**
     *  @brief Gimbal roll speed
     *
     *  @brief 云台 Roll 轴速度
     */
    float rollSpeed;
}AUTELGimbalAngleSpeed;

/**
 *  The mode of the gimbal rotation operation.
 */
typedef NS_ENUM(NSInteger, AUTELGimbalRotationMode) {
    /**
     *  The angle value, when the gimbal is rotating, relative to 0 degrees (aircraft
     *  heading).
     */
    AUTELGimbalRotationModeAbsoluteAngle,
    
    /**
     *  Rotate the gimbal's pitch, roll, and yaw in SPEED Mode. The direction can either
     *  be set to clockwise or  counter-clockwise.
     *   For Phantom 3 Professional, Phantom 3 Advanced and Phantom 3 Standard, roll and
     *  yaw rotations are not available.
     *   For Inspire 1, Inspire Pro and M100, pitch, roll and yaw rotations  are
     *  available.
     *   For Osmo, roll rotation is not available. The yaw angleVelocity of
     *  DJIGimbalSpeedRotation range is (0, 120).
     */
    AUTELGimbalRotationModeSpeed
};

/**
 *  Gimbal Calibration Status
 *
 *  定义云台校准状态
 */
typedef NS_ENUM(NSInteger, AUTELGimbalCalibrationStatus) {
    /**
     *  @brief Gimbal
     *
     *  未校准
     */
    AUTELGimbalCalibrationNone = 0,
    
    /**
     *  @brief Gimbal ready for calibration
     *
     *  即将校准
     */
    AUTELGimbalCalibrationReady = 1,
    
    /**
     *  @brief Gimbal is Calibrating
     *
     *  正在校准
     */
    AUTELGimbalCalibrationInProgress = 2,
    
    /**
     *  @brief Gimbal calibration completed, ready to save data
     *
     *  校准完成,准备保存数据
     */
    AUTELGimbalCalibrationSavingData = 3,
    
    /**
     *  @brief Gimbal calibration failed
     *
     *  校准失败
     */
    AUTELGimbalCalibrationFailed = 4,
    
    /**
     *  @brief Gimbal save data failed
     *
     *  保存数据失败
     */
    AUTELGimbalCalibrationSavingDataFailed = 5,
    
    /**
     *  @brief Gimbal calibration success
     *
     *  校准成功
     */
    AUTELGimbalCalibrationSuccess = 6,
    
    /**
     *  @brief Gimbal unable to calibrate, the aircraft is leaning
     *
     *  无法校准,飞行器倾斜
     */
    AUTELGimbalCalibrationAircraftLeans = 7,
    
    /**
     *  @brief Gimbal unable to calibrate, the aircraft is shaking
     *
     *  无法校准,飞行器倾斜
     */
    AUTELGimbalCalibrationAircraftShaking = 8,
    
    /**
     *  @brief Gimbal unable to calibrate, the aircraft motor is turning
     *
     *  无法校准,飞行器电机正在转动
     */
    AUTELGimbalCalibrationAircraftMotorWorking = 9,
};

/**
 *  Gimbal attitude type
 *
 *  云台姿态类型
 */
typedef NS_ENUM(NSInteger, AUTELGimbalAttitudeType) {
    /**
     *  @brief Gimbal pitch angle (°)
     *
     *  云台俯仰角（°）
     */
    AUTELGimbalAttitudeTypePitch,
    /**
     *  @brief Gimbal roll angle (°)
     *
     *  云台横滚角（°）
     */
    AUTELGimbalAttitudeTypeRoll,
    /**
     *  @brief Gimbal yaw angle (°)
     *
     *  云台偏航角（°）
     */
    AUTELGimbalAttitudeTypeYaw,
};

/**
 *  Gimbal Motor Status
 *
 *  定义云台电机状态
 */
typedef NS_ENUM(NSInteger, AUTELGimbalMotorStatus) {
    /**
     *  @brief normal
     *
     *  正常
     */
    AUTELGimbalMotorStatusNone = 0,
    
    /**
     *  @brief Gimbal motor stall protection
     *
     *  云台电机堵转保护
     */
    AUTELGimbalMotorStatusProtection = 1,
    
    /**
     *  @brief Gimbal motor close
     *
     *  云台电机关闭
     */
    AUTELGimbalMotorStatusClose = 2

};

/**
 *  Define gimbal pitch angle range.
 *
 *  定义云台pitch 角度范围类型。
 */
typedef NS_ENUM(uint8_t, AUTELDroneGimbalPitchAngleRange){
    /**
     *  AngleRange：[0~90°]
     *
     *  范围：[0~90°]
     */
    AUTELDroneGimbalPitchAngleRangeType1 = 0,
    
    /**
     *  AngleRange：[-30~90°]
     *
     *  范围：[-30~90°]
     */
    AUTELDroneGimbalPitchAngleRangeType2 = 1,
    
    /**
     *  Unknown
     *
     *  未知
     */
    AUTELDroneGimbalPitchAngleRangeUnknown = 0xFF,
};



/**
 *  Represents a gimbal speed or angular rotation operation.
 */
@interface AUTELGimbalRotation : NSObject


/**
 *  Type of gimbal rotation operation mode.
 */
@property (nonatomic, assign, readonly) AUTELGimbalRotationMode mode;


/**
 *  The pitch property of a gimbal rotation operation, how much the gimbal rotates
 *  on the pitch axis.
 */
@property (nonatomic, strong, nullable, readonly) NSNumber *pitch;


/**
 *  The roll property of a gimbal rotation operation, how much the gimbal rotates on
 *  the roll axis.
 */
@property (nonatomic, strong, nullable, readonly) NSNumber *roll;


/**
 *  The yaw property of a gimbal rotation operation, how much the gimbal rotates on
 *  the yaw axis.
 */
@property (nonatomic, strong, nullable, readonly) NSNumber *yaw;


/**
 *  Constructor for `AUTELGimbalRotation`.
 *
 *  @param pitchValue NSNumber object of pitch value.
 *  @param rollValue NSNumber object of roll value.
 *  @param yawValue NSNumber object of yaw value.
 *  @param mode An enum value of `AUTELGimbalRotationMode`.
 *
 *  @return Instance of `AUTELGimbalRotation`.
 */
+ (nullable instancetype)gimbalRotationWithPitchValue:(nullable NSNumber *)pitchValue
                                           rollValue:(nullable NSNumber *)rollValue
                                            yawValue:(nullable NSNumber *)yawValue
                                                mode:(AUTELGimbalRotationMode)mode;

@end

/**
 *  This class saves the info of gimbal states.
 *
 *  该类存储云台状态信息
 */
@interface AUTELDroneGimbalState : NSObject<NSCopying>

/**
 *  @brief Returns gimbal attitude info. For X-Star and X-Star Premium, only attitude.pitch property is valid.
 *
 *  返回云台姿态，对于 X-Srat 和 X-Star Premium 飞行器云台只有 attitude.pitch 有效，attitude.roll 和 attitude.yaw 值无效
 *
 *  @see AUTELGimbalAttitude
 */
@property(nonatomic) AUTELGimbalAttitude attitude;

/**
 *  @brief Check if gimbal attitude is initialized. If Yes, attitude has a valid value.
 *
 *  云台姿态是否已经被初始化，当该值为 YES 时，attitude 才是有效的。
 */
@property(nonatomic) BOOL isAttitudeAvailable;

/**
 *  @brief Returns working mode of gimbal. 
 *
 *  返回云台工作模式。TODO 该属性不能用，固定返回unknown
 *
 *  @see AUTELDroneGimbalWorkMode
 */
@property(nonatomic) AUTELDroneGimbalWorkMode workMode;

/**
 *  @brief Returns YES if gimbal is calibrating, else NO.
 *
 *  返回云台当前是否在校准，YES 表示云台正在校准，NO 表示云台没有在校准
 */
@property(nonatomic) BOOL isCalibrating;

/**
 *  gimbal calibration status
 */
@property(nonatomic) AUTELGimbalCalibrationStatus calibrationStatus;

/**
 *  gimbal motor status
 */
@property(nonatomic) AUTELGimbalMotorStatus gimbalMotorStatus;

/**
 *  @brief Returns calibration progress value from 0 to 100. Only if isCalibrating is set to Yes, calibrationProgress has a valid value.
 *
 *  返回校准进度，值的范围为 0 至 100，当 isCalibrating 为 YES 时，该值有效。
 */
@property(nonatomic) uint8_t calibrationProgress;

/**
 *  @brief Returns a Boolean value which indicates whether gimbal reach roll axis maximum angle.
 *
 *  返回一个布尔值，表示云台 Roll 轴是否撞限位。
 */
@property(nonatomic) BOOL isRollReachMax;

/**
 *  @brif If the Gimbal is overheated, return YES, otherwise return NO.
 *
 *  如果云台过热返回 YES, 否则返回 NO
 */
@property(nonatomic) BOOL isOverheat;

/**
 *  @brif Return YES if the Gimbal hardware failure occurs, otherwise return NO
 *
 *  如果云台发生硬件故障返回 YES, 否则返回 NO
 */
@property(nonatomic) BOOL isHardwareFail;

/**
 *  @brief Returns a boolean value which indicates whether gimbal is in sleep mode because of no coming attitude data.
 *
 *  返回一个布尔值，表示云台是否因没有收到飞控姿态数据而处于休眠状态.
 */
@property(nonatomic) BOOL isSleepForNoAttitude;

/**
 *  @brief Returns a Boolean value which indicates whether gimbal is in sleep mode because of reaching roll axis maximum angle.
 *
 *  返回一个布尔值，表示云台是否因达到 Roll 轴限位而进入休眠状态.
 */
@property(nonatomic) BOOL isSleepForRollReachMax;

@property(nonatomic) BOOL isWorkError;

@end


@class AUTELDroneGimbal;

/**
 *  Provides delegate to update real-time status of gimbal.
 *
 *  该协议提供了实时更新云台状态的方法
 */
@protocol AUTELDroneGimbalDelegate<NSObject>

@optional

/**
 *  @brief Update current status of gimbal. After the app connect to the aircraft, the instance of AUTELDroneGimbal object call startUpdataGimbalState method 5 times per second.
 *
 *  该回调方法更新飞机云台的当前状态。在 App 连上飞行器，AUTELDroneGimbal 实例的 startUpdataGimbalState 方法调用以后，该方法每秒被调用5次。
 *
 *  @param controller The instance of gimbal object.
 *
 *  更新状态的云台实例。
 *
 *  @param gimbalState Current state of gimbal.
 *
 *  云台当前状态
 *
 *  @discussion To invoke this call back method, AUTELDroneGimbal.starUpdataGimbalState has to be called first. To stop this call back method, call AUTELDroneGimbal.stopUpdataGimbalState. This call back method won’t be invoked until AUTELDroneGimbal.starUpdataGimbalState is called again.
 *
 *  默认该方法不会被调用，只有调用了 AUTELDroneGimbal 的 -startUpdataGimbalState 方法后，该回调方法才回被调用。调用 AUTELDroneGimbal 的 -stopUpsataGimbalState 方法后，该方法也不会被调用，直到再次调用了 -startUpdataGimbalState 方法。
 *
 *  @see AUTELDroneGimbal
 *  @see AUTELDroneGimbalState
 */
-(void) gimbalController:(AUTELDroneGimbal * _Nonnull)controller didUpdateGimbalState:(AUTELDroneGimbalState* _Nonnull)gimbalState NS_SWIFT_NAME(gimbalController(_:didUpdateGimbalState:));

@end

@class AUTELDrone;

/**
 *  Get real-time gimbal status and send command to control gimbal.
 *
 *  通过该类，你可以获得云台的实时状态，也可以向云台发送命令，控制云台。
 */
@interface AUTELDroneGimbal : NSObject

/**
 *  @brief Returns a instance of AUTELDrone. drone.gimbal is the same as self.
 *
 *  返回持有当前云台实例的 AUTELDrone 实例，drone.gimbal 与 self 是同一对象。
 *
 *  @see AUTELDrone
 */
@property (weak, nonatomic, readonly) AUTELDrone *drone;

/**
 *  @brief Returns drone gimbal delegate object.
 *
 *  返回飞行器云台代理对象。
 *
 *  @see AUTELDroneGimbalDelegate
 */
@property (weak, nonatomic) id<AUTELDroneGimbalDelegate> delegate;

/**
 *  @brief Start to update gimbal states.
 *
 *  开始更新云台状态。
 *
 *  @discussion The -gimbalController:didUpdateGimbalState will be called by calling this function. To stop update gimbal states, call -stopUpdateGimbalState function.
 *
 *  调用该方法后 delegate 的 -gimbalController:didUpdateGimbalState: 方法才会被调用，如果需要停止更新云台状态，可以调用 -stopUpsataGimbalState 方法
 *
 *  @see AUTELDroneGimbalDelegate
 *  @see -stopUpsataGimbalState
 */
- (void)startUpdataGimbalState;

/**
 *  @brief Stop to update gimbal states.
 *
 *  停止更新云台状态。
 *  
 *  @discussion By calling this function, gimbalControlller:didUpdateGimbalState will not be invoked any more until startUpdateGimbalStaten is called again.
 *
 *  调用该方法后 delegate 的 -gimbalController:didUpdateGimbalState: 方法将不会被调用，直到再次调用了 -startUpdataGimbalState 方法。
 *
 *  @see AUTELDroneGimbalDelegate
 *  @see -startUpdataGimbalState
 */
- (void)stopUpsataGimbalState;

/**
 *  @brief Set working mode of gimbal.
 *
 8  设置云台工作模式。
 *
 *  @param workMode Work mode. 
 *
 *  工作模式。
 *
 *  @param block    Completion Block. 
 *
 *  完成 block。
 *
 *  @see AUTELDroneGimbalWorkMode
 */
- (void)setGimbalWorkMode:(AUTELDroneGimbalWorkMode)workMode withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get working mode of gimbal.
 *
 *  查询云台工作模式。
 *
 *  @param block Completion Block. 
 *
 *  完成 block。
 *
 *  @see AUTELDroneGimbalWorkMode
 */
- (void)getGimbalWorkModeWithCompletion:(void (^)(AUTELDroneGimbalWorkMode workMode, NSError *_Nullable error))block;

/**
 *  @brief Trigger gimbal auto calibration.
 *
 *  调用该方法，让云台开始自动校准。
 *
 *  @param block Completion Block. 
 *
 *  完成 block。
 *
 *  @discussion If auto calibration succeeded, AUTELDroneGimbalState.isCalibrating turns to Yes, and calibrationProgress has a valid value.
 *
 *  如果该方法成功执行，AUTELDroneGimbalState.isCalibrating 会变为 YES，而 AUTELDroneGimbalState.calibrationProgress 为校准进度。
 *
 *  @note Gimbal auto calibration will be failed if it is triggered while motors are on, and block returns AUTELSDKFlightControllerErrorMotorWorking error.
 *
 *  如果飞行器电机转动时调用该方法，则该方法会执行失败，block 返回 AUTELSDKFlightControllerErrorMotorWorking 错误。
 *
 *  @see AUTELDroneGimbalWorkMode
 *  @see AUTELDroneGimbalState
 *  @see AUTELSDKFlightControllerError
 */
- (void)startGimbalAutoCalibrationWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set gimbal pitch.
 *
 *  设置云台俯仰角度。
 *
 *  @param pitch Gimbal pitch angle, from 0 to 90 degree. When it’s 0 degree, camera face to the front, and when it’s 90 degree, camera face to the ground.
 *
 *  云台俯仰角，范围是0°至90°，该值等于0时相机朝向正前方，等于90时相机朝向正下方。
 *
 *  @param block Completion Block. 
 *
 *  完成 block。
 *
 *  @discussion AUTELDroneGimbalState.altitude changes value every time after pitch angle change applies.
 *
 *  如果该方法改变了云台俯仰角，AUTELDroneGimbalState.attitude 也会发生变化。
 *
 *  @note Gimal wheel on the controller has a higher priority than this function. If the user use gimbal wheel and app to change gimbal pitch angle at the same time. Gimbal maybe only accept the command from gimbal wheel.
 *
 *  用户还可以通过遥控器的拨轮改变云台俯仰角，遥控器的拨轮有较高的优先权，如果调用该方法的同时遥控器拨轮被拨动，云台有可能只受遥控器控制。
 *
 *  @see AUTELDroneGimbalState
 */
- (void)setGimbalPitch:(uint8_t)pitch withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set the speed of gimbal pitch.
 *
 *  设置云台转动速度。
 *
 *  @param pitchSpeed Set speed from 0 to 100, gimbal tiles up. Set speed from -100 to 0, gimbal tiles down.
 *
 *  指定云台的转动速度，范围[-100, 100]，speed > 0 表示向上转动，speed < 0 表示向下转动，绝对值越大转动速度越快。
 *
 *  @discussion Gimbal pitch angle changes with speed setting. Gimbal operates 300ms for each call. If gimbal continue to tile up or down, invoke this function every 100ms to get optimized performace . 
 *  AUTELDroneGimbalState.altitude changes value every time after pitch angle change applies.
 *
 *  如果该方法正确执行，云台会按照设置的速度和方向转动，每调用一次，云台转动约300毫秒，如果需要云台持续转动，建议你每隔100毫秒调用一次该方法。
 *  如果该方法改变了云台俯仰角，AUTELDroneGimbalState.attitude 也会发生变化。
 *
 *  @note Gimal wheel on the controller has a higher priority than this function. If the user use gimbal wheel and app to change gimbal pitch angle at the same time. Gimbal maybe only accept the command from gimbal wheel.
 *
 *  用户还可以通过遥控器的拨轮改变云台俯仰角，遥控器的拨轮有较高的优先权，如果调用该方法的同时遥控器拨轮被拨动，云台有可能只受遥控器控制。
 *
 *  @see AUTELDroneGimbalState
 */
- (void)setGimbalPitchSpeed:(int32_t)pitchSpeed;

/**
 *  @brief Rotating gimbal
 *
 *  转动云台
 *
 *  @param rotation 旋转参数
 *  @param block 完成 Block
 */
- (void)rotateWithRotation:(AUTELGimbalRotation *_Nonnull)rotation withCompletion:(nullable AUTELCompletionBlock)block;

/**
 *  @brief  Adjust gimbal roll axis angle from counterclockwise 10 degree to clockwise 10 degree. 0.2 degree for each adjustment.
 *
 *  通过该方法你可以对云台 roll 轴进行微调，如果 clockwise 为 YES，云台会顺时针旋转微调，如果为 NO，则逆时针旋转微调，该方法成功执行一次，云台会顺时针或逆时针旋转0.2°，最多能顺时针或逆时针旋转10°。
 *
 *  @param clockwise   If Yes, adjust the gimbal roll axis in clockwise direction. If no, adjust the gimbal roll axis in counterclockwise direction.
 *
 *  微调方向，YES 表示顺时针微调，NO 表示逆时针微调
 *
 *  @param block   Completion block. 
 *
 *  完成 block
 */
- (void)fineTuneGimbalRollClockwise:(BOOL)clockwise withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief  设置云台 AUTELGimbalAttitudeType 轴微调
 *
 *  @param degree 微调角度,范围是[-10, 10](deg)
 *         attitude see AUTELGimbalAttitudeType
 *
 *  @param block   Completion block.
 *
 *  完成 block
 */
- (void)fineTuneGimbalRollInDegree:(float)degree gimbalAttitude:(AUTELGimbalAttitudeType)attitude withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Set gimbal roll axis angle to 0 degree.
 *
 *  将云台 Roll 轴微调角度置为 0°。
 *
 *  @param block 完成block
 */
- (void)resetGimbalFineTuneDegreeWithCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Get current gimbal pitch,yaw and roll axis angle.
 *
 *  查询云台 pitch,yaw和roll 轴微调角度。
 *
 *  @param block this block includes 4 parameters. xxxDegree indicates the angle; digree > 0 indicates clockwise direction, while digree < 0 indicates counterclockwise direction. Error indicates the error message. If this function applies successfully, error is nil.
 *
 *  完成 Block，该 Block 包含两个参数：digree 表示角度，digree > 0 表示微调角度为顺时针方向，digree < 0 表示逆时针方向，error 为错误信息，如果该方法执行成功，error 为 nil。
 */
- (void)getGimbalFineTuneDegreeWithCompletion:(void(^)(float pitchDigree, float yawDigree, float rollDigree, NSError *_Nullable error))block;

/**
 *  @brief get Gimbal angle and angular velocity range
 *
 *  查询云台角度和角速度范围
 *
 *  @param block 完成 block, 如果查询成功 capability 将返回云台角度和角速度范围, 否则error返回错误原因
 */
-(void)getGimbalCapabilityWithCompletion:(void(^_Nullable)(NSDictionary *_Nullable capability, NSError *_Nullable error))block;

/**
 *  @brief Reset the gimbal angle
 *
 *  重置云台角度
 *
 *  @param rotation 标识需要重置的云台转轴, rotation 的 pitch, roll, yaw 属性如果为 nil, 则忽略对应的云台转轴,如果不为 nil 则重置对应的转轴
 *
 *  @param block 返回 Block
 */
- (void)resetGimbalRotation:(AUTELGimbalRotation *_Nonnull)rotation withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Gimbal turns to the maximum limit
 *
 *  云台转动到最大限位
 *
 *  @param rotation 标识需要重置的云台转轴, rotation 的 pitch, roll, yaw 属性如果为 nil, 则忽略对应的云台转轴,如果不为 nil 则将对应云台轴转动到大角度
 */
- (void)rotateToMaxAngleWithRotation:(AUTELGimbalRotation *_Nonnull)rotation withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Gimbal turns to the minimum limit
 *
 *  云台转动到最小限位
 *
 *  @param rotation 标识需要重置的云台转轴, rotation 的 pitch, roll, yaw 属性如果为 nil, 则忽略对应的云台转轴,如果不为 nil 则将对应云台轴转动到小角度
 */
- (void)rotateToMinAngleWithRotation:(AUTELGimbalRotation *_Nonnull)rotation withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Start Gimbal calibration
 *
 *  启动云台校准
 *
 *  @param block 完成 block.
 */
- (void)startCalibrationWithCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Set pitch angle range type:[0~90°] or [-30~90°]
*
*  设置云台pitch角度范围。
*
*  @param  rangeType  pitch angle range type
*
*  角度范围类型。
*
*  @param block    Completion Block.
*
*  完成 block。
*
*  @see AUTELDroneGimbalPitchAngleRange
*/
- (void)setGimbalPitchAngleRange:(AUTELDroneGimbalPitchAngleRange)rangeType withCompletion:(AUTELCompletionBlock)block;

/**
*  @brief Get  pitch angle range type:[0~90°] or [-30~90°]
*
*  查询云台pitch角度范围。
*
*  @param block Completion Block.
*
*  完成 block。
*
*  @see AUTELDroneGimbalPitchAngleRange
*/
- (void)getGimbalPitchAngleRangeWithCompletion:(void (^_Nullable)(AUTELDroneGimbalPitchAngleRange rangeType, NSError *_Nullable error))block;

@end

NS_ASSUME_NONNULL_END
