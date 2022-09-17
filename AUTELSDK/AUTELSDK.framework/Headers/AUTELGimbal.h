//
//  AUTELGimbal.h
//  AUTELSDK
//
//  Created by Autel on 15/12/3.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>
#import <AUTELSDK/AUTELDroneGimbal.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark AUTELGimbalAttitude


///**
// *  云台姿态
// */
//typedef struct {
//    /**云台俯仰角（°）*/
//    float pitch;
//    /**云台横滚角（°）*/
//    float roll;
//    /**云台偏航角（°）*/
//    float yaw;
//} AUTELGimbalAttitude;

/**
 *  The speed of gimbal
 */
typedef struct {
    NSInteger pitch;
    NSInteger roll;
    NSInteger yaw;
} AUTELGimbalValue;

typedef AUTELGimbalValue AUTELGimbalSmoothTrackSpeed;

#pragma mark AUTELGimbalMotorPower
/**
 *  The power of Gimbal Motor
 */
typedef struct {
    NSInteger pitch;
    NSInteger roll;
    NSInteger yaw;
} AUTELGimbalMotorPower;

#pragma mark AUTELGimbalRotateDirection
/**
 *  Gimbal rotate direction.
 */
typedef NS_ENUM (uint8_t, AUTELGimbalRotateDirection){
    /**
     *  Sets the gimbal to rotate clockwise.
     */
    AUTELGimbalRotateDirectionClockwise,
    /**
     *  Sets the gimbal to rotate counter-clockwise.
     */
    AUTELGimbalRotateDirectionCounterClockwise,
};

#pragma mark AUTELGimbalRotateAngleMode
/**
 *  The rotation angle of gimbal can be defined as either Absolute (relative to 0 degrees), or Relative (relative to it's current angle).
 */
typedef NS_ENUM(uint8_t, AUTELGimbalRotateAngleMode) {
    /**
     *  The angle value, when the gimbal is rotating, will be relative to the current angle.
     */
    AUTELGimbalAngleModeRelativeAngle,
    /**
     *  The angle value, when the gimbal is rotating, will be relative to 0 degrees.
     */
    AUTELGimbalAngleModeAbsoluteAngle,
};

#pragma mark AUTELGimbalAngleRotation
/**
 *  Struct used to control the gimbal by angle (either absolutely or relatively).
 */
typedef struct {
    /**
     *  Gimbal rotation is enabled. If enable is set to NO, you will not be able
     *  to rotate the gimbal.
     */
    BOOL enabled;
    /**
     *  Gimbal rotation angle in degrees.
     */
    float angle;
    /**
     *  Gimbal rotate direction，while you rotate gimbal by angle absolutely, it may be ineffective.
     */
    AUTELGimbalRotateDirection direction;
} AUTELGimbalAngleRotation;

#pragma mark AUTELGimbalSpeedRotation
/**
 *  Struct used to control the gimbal by speed.
 */
typedef struct {
    /**
     *  Gimbal rotation angle velocity in degree/second.
     */
    float angleVelocity;
    /**
     *  Gimbal rotate direction
     */
    AUTELGimbalRotateDirection direction;
} AUTELGimbalSpeedRotation;

#pragma mark AUTELGimbalWorkMode
/**
 *  Gimbal work modes.
 */
typedef NS_ENUM (uint8_t, AUTELGimbalWorkMode){
    /**
     *  The gimbal's work mode is yaw axis follow mode.
     */
    AUTELGimbalWorkModeYawFollowMode = 0,
    /**
     *  The gimbal's work mode is full follow mode.
     */
    AUTELGimbalWorkModeFreeMode = 1,
    /**
     *  The gimbal's work mode is all axes lock.
     */
    AUTELGimbalWorkModeLockMode = 2,
    /**
     *  The gimbal's work mode is FPV(First-person view) mode.
     *  Not supported by Small HandHeld.
     */
    AUTELGimbalWorkModeFpvMode,
    /**
     *  The gimbal's work mode is unknown.
     */
    AUTELGimbalWorkModeUnknown = 0xFF,
};

/**
 *  Gimbal Autodyne State
 */
typedef NS_ENUM(uint8_t, AUTELGimbalAutodyneState) {
    /**
     *  The Gimbal Power Mode is Exit.
     */
    AUTELGimbalAutodyneStateExit,
    /**
     *  The Gimbal Power Mode is enter.
     */
    AUTELGimbalAutodyneStateEnter,
};

#pragma mark AUTELGimbalUserConfigType
/**
 *  Gimbal User Config.
 *
 *  The gimbal has a feature called SmoothTrack
 *  SmoothTrack smooths out larger transitions in each axis (as opposed to keeping the camera pointed in the same direction at all times)
 *  SmoothTrack is used on three axes (pitch, roll and yaw) and has three presets of fast, medium or slow which impact the tracking speed, deadband and acceleration settings. These settings can also be customized.
 */
typedef NS_ENUM(uint8_t, AUTELGimbalUserConfigType) {
    /**
     *  The gimbal's user config type is unknown.
     */
    AUTELGimbalUserConfigTypeUnknown = 0,
    /**
     *  The gimbal's SmoothTrack will catch up with significant yaw and pitch changes with a slow speed.
     */
    AUTELGimbalUserConfigTypeSlowSmoothTrack,
    /**
     *  The gimbal's SmoothTrack will catch up with significant yaw and pitch changes with a medium speed.
     */
    AUTELGimbalUserConfigTypeMediumSmoothTrack,
    /**
     *  The gimbal's SmoothTrack will catch up with significant yaw and pitch changes with a fast speed.
     */
    AUTELGimbalUserConfigTypeFastSmoothTrack,
    /**
     *  The gimbal uses a custom configuration in memory slot where the roll yaw and pitch speed, deadband and acceleration can be defined.
     */
    AUTELGimbalUserConfigTypeCustom,
};

#pragma mark AUTELGimbalSmoothTrackSettings
/**
 *  Gimbal's SmoothTrack axis.
 */
typedef NS_ENUM(uint8_t, AUTELGimbalSmoothTrackAxis) {
    /**
     *  The gimbal's SmoothTrack axis is pitch
     */
    AUTELGimbalSmoothTrackAxisPitch,
    /**
     *  The gimbal's SmoothTrack axis is roll
     */
    AUTELGimbalSmoothTrackAxisRoll,
    /**
     *  The gimbal's SmoothTrack axis is yaw
     */
    AUTELGimbalSmoothTrackAxisYaw,
};

#pragma mark AUTELGimbalJoystick
/**
 *  Gimbal joystick axis.
 */
typedef NS_ENUM(uint8_t, AUTELGimbalJoystickAxis) {
    /**
     *  The axis of gimbal's joystick direction is pitch.
     */
    AUTELGimbalJoystickAxisPitch,
    /**
     *  The axis of gimbal's joystick direction is roll.
     */
    AUTELGimbalJoystickAxisRoll,
    /**
     *  The axis of gimbal's joystick direction is yaw.
     */
    AUTELGimbalJoystickAxisYaw,
};

/**
 *  Signal Strength（Gimbal Image Transmission, Remote Controller and wifi）
 */
typedef NS_ENUM (uint8_t, AUTELGimbalRSSI) {
    /**
    *  Signal Strength Level0.
    */
    AUTELGimbalRSSILevel0 = 0,
    /**
    *  Signal Strength Level1.
    */
    AUTELGimbalRSSILevel1,
    /**
    *  Signal Strength Level2.
    */
    AUTELGimbalRSSILevel2,
    /**
    *  Signal StrengthLevel3.
    */
    AUTELGimbalRSSILevel3,
    /**
    *  Signal Strength Level4.
    */
    AUTELGimbalRSSILevel4,
    /**
    *  Signal Strength Level5.
    */
    AUTELGimbalRSSILevel5,
};

/**
 *  Gimbal Calibration Type
 */
typedef NS_ENUM(uint8_t, AUTELGimbalCalibrationType) {
    /**
     *  Gimbal Parameter Auto Calibration
     */
    AUTELGimbalCalibrationTypeParamAutoAdapt,
    /**
     *  Gimbal Bias Calibration
     */
    AUTELGimbalCalibrationTypeBias,
    /**
     *  Gimbal Yaw Center Calibration
     */
    AUTELGimbalCalibrationTypeYawCenter
};

#pragma mark - AUTELGimbalConstraints
@interface AUTELGimbalConstraints : NSObject

/**
 *  Yes if pitch can be controlled.
 */
@property(nonatomic, readonly) BOOL isPitchAdjustable;

/**
 *  Yes if roll can be controlled.
 */
@property(nonatomic, readonly) BOOL isRollAdjustable;

/**
 *  Yes if yaw can be controlled.
 */
@property(nonatomic, readonly) BOOL isYawAdjustable;

/**
 *  Returns the maximum angle the pitch can be set to.
 */
@property(nonatomic, readonly) float pitchStopMax;

/**
 *  Returns the minimum angle the pitch can be set to.
 */
@property(nonatomic, readonly) float pitchStopMin;

/**
 *  Returns the maximum angle the roll can be set to.
 */
@property(nonatomic, readonly) float rollStopMax;

/**
 *  Returns the minimum angle the roll can be set to.
 */
@property(nonatomic, readonly) float rollStopMin;

/**
 *  Returns the maximum angle the yaw can be set to.
 */
@property(nonatomic, readonly) float yawStopMax;

/**
 *  Returns the minimum angle the yaw can be set to.
 */
@property(nonatomic, readonly) float yawStopMin;

@end

/**
 *  This class provides the current state of the gimbal.
 *
 */
@interface AUTELGimbalState : NSObject

/**
 *  The current gimbal attitude in degrees.
 */
@property(nonatomic, readonly) AUTELGimbalAttitude attitudeInDegrees;

/**
 *  The current gimbal motor power.
 */
@property(nonatomic, readonly) AUTELGimbalMotorPower motorPower;

/**
 *  The current gimbal Image Transmission signal strength.
 */
@property(nonatomic, readonly) AUTELGimbalRSSI videoRSSI;

/**
 *  The current gimbal Remote Controller signal strenght.
 */
@property(nonatomic, readonly) AUTELGimbalRSSI rcRSSI;

/**
 *  gimbal autodyne state
 *  @see AUTELGimbalAutodyneState
 */
@property(nonatomic, readonly) AUTELGimbalAutodyneState autodyneState;


/// roll FineTune in degrees
@property(nonatomic, readonly) float rollFineTuneInDegrees;

/**
 *  Returns the gimbal's current work mode.
 */
@property(nonatomic, readonly) AUTELGimbalWorkMode workMode;

/**
 *  Returns whether or not the attitude has been reset.
 */
@property(nonatomic, readonly) BOOL isAttitudeReset;

/**
 *  Returns whether or not the gimbal calibration success
 */
@property(nonatomic, readonly) BOOL isCalibrationSuccessful;

/**
 *  YES if the Gimbal is calibrating
 */
@property(nonatomic, readonly) BOOL isCalibrating;

/**
 *  Returns current gimbal calibration progress
 */
@property(nonatomic, readonly) NSInteger calibrateProgress;

/**
 *  Returns whether or not the gimbal's pitch value is at its maximum or minimum.
 */
@property(nonatomic, readonly) BOOL isPitchAtStop;

/**
 *  Returns whether or not the gimbal's roll value is at its maximum or minimum.
 */
@property(nonatomic, readonly) BOOL isRollAtStop;

/**
 *  Returns whether or not the gimbal's yaw value is at its maximum or minimum.
 */
@property(nonatomic, readonly) BOOL isYawAtStop;

@end

/**
 *  This class provides advanced configuration of the gimbal.
 */
@interface AUTELGimbalConfig : NSObject

/**
 *  Gimbal configuration type. There are three preset types: fast, medium and slow.
 *  When the configuration type to AUTELGimbalUserConfigTypeCustom, user can change
 *  the configuration by calling methods related to smoothTracking.
 */
@property(nonatomic, readonly) AUTELGimbalUserConfigType configType;

/**
 *  YES if gimbal SmoothTrack is enabled for the pitch axis.
 */
@property(nonatomic, readonly) BOOL isSmoothTrackPitchEnabled;

/**
 *  YES if gimbal SmoothTrack is enabled for the roll axis.
 */
@property(nonatomic, readonly) BOOL isSmoothTrackRollEnabled;

/**
 *  YES if gimbal SmoothTrack is enabled for the yaw axis.
 */
@property(nonatomic, readonly) BOOL isSmoothTrackYawEnabled;

/**
 *  SmoothTrack pitch axis speed determines how fast the gimbal will catch up with the translated pitch handle movement.
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger smoothTrackPitchSpeed;

/**
 *  SmoothTrack roll axis speed determines how fast the gimbal will catch up with the translated roll handle movement.
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger smoothTrackRollSpeed;

/**
 *  SmoothTrack yaw axis speed determines how fast the gimbal will catch up with the translated yaw handle movement.
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger smoothTrackYawSpeed;

/**
 *   A larger SmoothTrack pitch axis deadband requires more pitch handle movement to translate into gimbal motion.
 *  Range is [0,60] degrees.
 */
@property(nonatomic, readonly) NSInteger smoothTrackPitchDeadband;

/**
 *   A larger SmoothTrack roll axis deadband requires more roll handle movement to translate into gimbal motion.
 *  Range is [0,60] degrees.
 */
@property(nonatomic, readonly) NSInteger smoothTrackRollDeadband;

/**
 *   A larger SmoothTrack yaw axis deadband requires more yaw handle movement to translate into gimbal motion.
 *  Range is [0,60] degrees.
 */
@property(nonatomic, readonly) NSInteger smoothTrackYawDeadband;

@property(nonatomic, readonly) NSInteger smoothTrackPitchAcceleration;
@property(nonatomic, readonly) NSInteger smoothTrackRollAcceleration;
@property(nonatomic, readonly) NSInteger smoothTrackYawAcceleration;

/**
 *  Joystick pitch axis smoothing controls the deceleration of the gimbal. A small value will cause the gimbal to stop abruptly.
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger joystickPitchSmoothing;

/**
 *  Joystick roll axis smoothing controls the deceleration of the gimbal. A small value will cause the gimbal to stop abruptly.
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger joystickRollSmoothing;

/**
 *  Joystick yaw axis smoothing controls the deceleration of the gimbal. A small value will cause the gimbal to stop abruptly.
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger joystickYawSmoothing;

/**
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger joystickPitchDeadband;

/**
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger joystickRollDeadband;

/**
 *  Range is [0,100].
 */
@property(nonatomic, readonly) NSInteger joystickYawDeadband;

@property(nonatomic, readonly) NSInteger joystickPitchSpeed;
@property(nonatomic, readonly) NSInteger joystickRollSpeed;
@property(nonatomic, readonly) NSInteger joystickYawSpeed;

@end

@class AUTELGimbal;

@protocol AUTELGimbalDelegate <NSObject>
@optional

/**
 *  Updates the gimbal's current state.
 */
- (void)gimbal:(AUTELGimbal *)gimbal didUpdateGimbalState:(AUTELGimbalState *)gimbalState;

/**
 *  Update the gimbal's user config data. Method only supported for A9.
 */
- (void)gimbal:(AUTELGimbal *)gimbal didUpdateGimbalConfig:(AUTELGimbalConfig *)gimbalConfig;

@end

/**
*  @warning    __deprecated
*/
@interface AUTELGimbal : NSObject

@property (nullable, nonatomic, weak) id<AUTELGimbalDelegate> delegate;

/**
 *  Returns the latest gimbal attitude data and nil if none is available.
 */
@property (nonatomic, readonly) AUTELGimbalAttitude attitudeInDegrees;
@property (nonatomic, assign) NSTimeInterval completionTimeForControlAngleAction;

//#pragma mark Set Gimbal Work Mode
///**
// *  Sets the gimbal's work mode. See enum AUTELGimbalWorkMode for modes.
// *
// *  @param workMode Gimbal work mode to be set.
// *  @param result    Remote execution result error block.
// */
//- (void)setGimbalWorkMode:(AUTELGimbalWorkMode)workMode withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Set the gimbal autodyne state
// *
// *  @param autodyneState The autodyne state to set.
// *  @param result        Remote execution result block.
// */
//- (void)setGimbalAutodyneState:(AUTELGimbalAutodyneState)autodyneState withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Get the gimbal autodyne state
// *
// *  @param result Get Gimbal Autodyne State in specific direction result block.
// */
//- (void)getGimbalAutodyneStateWithResult:(void (^_Nullable)(AUTELGimbalAutodyneState autodyneState, AUTELError *_Nullable error))result;
//
//#pragma mark Gimbal Control
//- (AUTELGimbalConstraints *)getGimbalConstraints;
//
///**
// *  Rotate the gimbal's pitch, roll, and yaw in offset Angle Mode.
// *
// *  For Small HandHeld, roll rotation is not available. The range for pitch and yaw rotation is [-1000, 1000].
// *
// *  @param pitchOffset Rotate gimbal with offset on the pitch axis
// *  @param yawOffset   Rotate gimbal with offset on the yaw axis
// *  @param result      Execution result error block.
// */
//- (void)rotateGimbalWithPitchOffset:(NSInteger)pitchOffset yawOffset:(NSInteger)yawOffset withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Resets the gimbal attitude. The gimbal's pitch, roll, and yaw will be set to the origin, which is
// *  the standard position for the gimbal.
// *
// *  @param result Remote execution result error block.
// */
//- (void)resetGimbalWithResult:(AUTELExecuteResultBlock)result;
//
//#pragma mark Gimbal Calibration
//
///**
// *  Fine-tune the gimbal's with targetAngle on axis.
// *
// *  For Small HandHeld, all axes are available. The range is [-10, 10].
// *
// *  @param targetFineTuneAttitude <#targetFineTuneAttitude description#>
// *  @param result                 <#result description#>
// */
//- (void)fineTuneGimbalWithTargetAttitude:(AUTELGimbalAttitude)targetFineTuneAttitude withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Get the gimbal's Fine-tune angle on axis.
// *
// *  For Small HandHeld, all axes are available. The range is [-10, 10].
// *
// *  @param result Get Gimbal Fine-tune attitude in specific direction result block.
// */
//- (void)getGimbalFineTuneAttitudeWithResult:(void (^_Nullable)(AUTELGimbalAttitude fineTuneAttitude, AUTELError *_Nullable error))result;
//
///**
// *  Prepare for gimbal calibrationType   为校准calibrationType，做准备工作
// *
// *  @param calibrationType 准备校准的类型
// *  @param result          Remote execution result error block.
// */
//- (void)prepareGimbalCalibrationType:(AUTELGimbalCalibrationType)calibrationType withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Starts calibrating the gimbal with Calibration Type. See enum AUTELGimbalCalibrationType for type.
// *
// *  @param calibrationType Calibration gimbal type to start calibrating.
// *  @param result          Remote execution result error block.
// */
//- (void)startGimbalCalibrationType:(AUTELGimbalCalibrationType)calibrationType withResult:(AUTELExecuteResultBlock)result;
//
//#pragma mark Gimbal User Config
//- (BOOL)isUserConfigSupported;
//
///**
// *  Resets the total gimbal params to the origin, which is the standard for the gimbal.
// *
// *  @param result Remote execution result error block.
// */
//- (void)resetGimbalParamsWithResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Set gimbal user config type.
// *
// *  @param userConfigType Gimbal user configure type
// *  @param result         Set Gimbal User Config result block.
// */
//- (void)setGimbalUserConfigType:(AUTELGimbalUserConfigType)userConfigType withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Gets gimbal user config type.
// *
// *  @param result Get Gimbal User Config result block.
// */
//- (void)getGimbalUserConfigTypeWithResult:(void (^_Nullable)(AUTELGimbalUserConfigType userConfigType, AUTELError *_Nullable error))result;
//
///**
// *  Enables a gimbal SmoothTrack axis.
// *
// *  @param axis    Gimbal axis.
// *  @param enabled YES if SmoothTrack is to be enabled on axis.
// *  @param result  set if Gimbal SmoothTrack Adjustment is available to be customized in the specific direction result block.
// */
//- (void)setGimbalSmoothTrackAxisEnabledOnAxis:(AUTELGimbalSmoothTrackAxis)axis isEnabled:(BOOL)enabled withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Gets whether an axis has SmoothTrack enabled.
// *
// *  @param axis   Gimbal axis.
// *  @param result Get if Gimbal SmoothTrack Adjustment is available to be customized in the specific direction result block.
// */
//- (void)getGimbalSmoothTrackAxisEnabledOnAxis:(AUTELGimbalSmoothTrackAxis)axis withResult:(void (^_Nullable)(BOOL isEnabled, AUTELError *_Nullable error))result;
//
///**
// *  Sets gimbal SmoothTrack catch up speed on an axis. SmoothTrack speed determines how fast the gimbal will catch up with a large, translated handle movement and has a range [0,100].
// *
// *  @param axis   Gimbal axis.
// *  @param speed  SmoothTrack speed [0,100].
// *  @param result Set Gimbal SmoothTrack Adjustment speed in specific direction result block.
// */
//- (void)setGimbalSmoothTrackSpeed:(AUTELGimbalSmoothTrackSpeed)smoothTrackSpeed withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Gets gimbal SmoothTrack speed on an axis.
// *
// *  @param axis   Gimbal axis.
// *  @param result Get Gimbal SmoothTrack Adjustment speed in specific direction result block.
// */
//- (void)getGimbalSmoothTrackSpeedWithResult:(void (^_Nullable)(AUTELGimbalSmoothTrackSpeed smoothTrackSpeed, AUTELError *_Nullable error))result;
//
///**
// *  Sets SmoothTrack deadband on an axis. A larger deadband requires more handle movement to translate into gimbal motion. Deadband has a range of [0,60] degrees.
// *
// *  @param axis     Gimbal axis.
// *  @param deadband SmoothTrack deadband [0,60].
// *  @param result    Set Gimbal SmoothTrack Adjustment deadband in specific direction result block.
// */
//- (void)setGimbalSmoothTrackDeadbandOnAxis:(AUTELGimbalSmoothTrackAxis)axis deadband:(NSInteger)deadband withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Gets SmoothTrack deadband on an axis.
// *
// *  @param axis   Gimbal axis.
// *  @param result Get Gimbal SmoothTrack Adjustment deadband in specific direction result block.
// */
//- (void)getGimbalSmoothTrackDeadbandOnAxis:(AUTELGimbalSmoothTrackAxis)axis withResult:(void (^_Nullable)(NSInteger deadband, AUTELError *_Nullable error))result;
//
//- (void)setGimbalSmoothTrackAccelerationOnAxis:(AUTELGimbalSmoothTrackAxis)axis acceleration:(NSInteger)acceleration withResult:(AUTELExecuteResultBlock)result;
//- (void)getGimbalSmoothTrackAccelerationOnAxis:(AUTELGimbalSmoothTrackAxis)axis withResult:(void (^_Nullable)(NSInteger acceleration, AUTELError *_Nullable error))result;
//
///**
// *  Sets joystick smoothing on an axis. Joystick smoothing controls the deceleration of the gimbal. A small value will cause the gimbal to stop abruptly. Smoothing has a range of [0, 100].
// *
// *  @param axis      Gimbal joystick axis.
// *  @param smoothing Joystick Smoothing [0, 100].
// *  @param result     Set Gimbal Joystick Smoothing in specific direction result block.
// */
//- (void)setGimbalJoystickSmoothingOnAxis:(AUTELGimbalJoystickAxis)axis smoothing:(NSInteger)smoothing withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Gets joystick smoothing on an axis.
// *
// *  @param axis   Gimbal joystick axis
// *  @param result Get Gimbal Joystick Smoothing in specific direction result block.
// */
//- (void)getGimbalJoystickSmoothingOnAxis:(AUTELGimbalJoystickAxis)axis withResult:(void (^_Nullable)(NSInteger smoothing, AUTELError *_Nullable error))result;
//
///**
// *  Sets joystick smoothing coefficient on an axis.
// *
// *  @param axis                 Gimbal joystick axis
// *  @param smoothingCoefficient Joystick Smoothing Coefficient [0, 100].
// *  @param result               Remote execution result error block.
// */
//- (void)setGimbalJoystickSmoothingCoefficientOnAxis:(AUTELGimbalJoystickAxis)axis smoothingCoefficient:(NSInteger)smoothingCoefficient withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Gets joystick smoothing coefficient on an axis.
// *
// *  @param axis   Gimbal joystick axis
// *  @param result Get Gimbal Joystick Smoothing Coefficient in specific direction result block.
// */
//- (void)getGimbalJoystickSmoothingCoefficientOnAxis:(AUTELGimbalJoystickAxis)axis withResult:(void (^_Nullable)(NSInteger smoothingCoefficient, AUTELError *_Nullable error))result;
//
///**
// *  Sets joystick deadband on an axis. Deadband has a range of [0, 100].
// *
// *  @param axis     Gimbal joystick axis
// *  @param deadband Joystick Deadband [0, 100].
// *  @param result   Set Gimbal Joystick Deadband in specific direction result block.
// */
//- (void)setGimbalJoystickDeadbandOnAxis:(AUTELGimbalJoystickAxis)axis deadband:(NSInteger)deadband withResult:(AUTELExecuteResultBlock)result;
//
///**
// *  Gets joystick deadband on an axis.
// *
// *  @param axis   Gimbal joystick axis
// *  @param result Get Gimbal Joystick Deadband in specific direction result block.
// */
//- (void)getGimbalJoystickDeadbandOnAxis:(AUTELGimbalJoystickAxis)axis withResult:(void (^_Nullable)(NSInteger deadband, AUTELError *_Nullable error))result;
//
///**
// Set Joystick Speed On an axis
//
// @param axis Gimbal joystick axis
// @param speed speed
// @param result result block
// */
//- (void)setGimbalJoystickSpeedOnAxis:(AUTELGimbalJoystickAxis)axis speed:(NSInteger)speed withResult:(AUTELExecuteResultBlock)result;
//
///**
// get Joystick Speed On an axis
//
// @param axis Gimbal joystick axis
// @param result result block
// */
//- (void)getGimbalJoystickSpeedOnAxis:(AUTELGimbalJoystickAxis)axis withResult:(void (^_Nullable)(NSInteger speed, AUTELError *_Nullable error))result;

@end

NS_ASSUME_NONNULL_END
