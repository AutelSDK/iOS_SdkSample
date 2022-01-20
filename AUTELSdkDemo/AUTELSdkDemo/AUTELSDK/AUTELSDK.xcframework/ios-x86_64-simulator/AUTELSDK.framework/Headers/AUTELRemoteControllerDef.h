//
//  AUTELRemoteControllerDef.h
//  AUTELSDK
//
//  Created by IOS on 15/11/23.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AUTEL_RC_NAME_BUFFER_SIZE         (17)               //ssid 长度8-16

#define AUTEL_RC_PWD_BUFFER_SIZE         (17)               //password 长度8-16

#define AUTEL_RC_CONTROL_CHANNEL_SIZE     (4)

/**
 *  Define the state of the right dial.
 *
 *  定义遥控器右侧滚轮状态.
 */
typedef NS_ENUM(NSUInteger, AUTELRCMultiPurposeButtonState) {
    /**
     *  @brief Roll
     *
     *  滚动
     */
    RCMultiPurposeButtonUp = 0,
    /**
     *  @brief Press
     *
     *  短按
     */
    RCMultiPurposeButtonShortDown,
    /**
     *  @brief Hold
     *
     *  长按
     */
    RCMultiPurposeButtonLongDown
};

/**
 *  RC Signal quality 
 *
 *  遥控器信号质量.
 */
typedef struct
{
    /**
     *  @brief Range of the signal strength: [0, 100]
     *
     *  信号强度,范围[0, 100]
     */
    uint8_t mQuality;
} AUTELRCSignalQuality;

/**
 *  RC name
 *
 *  遥控器名称
 */
typedef struct
{
    char mBuffer[AUTEL_RC_NAME_BUFFER_SIZE];
} AUTELRCName;

/**
 *  RC Password 
 *
 *  遥控器WiFi密码
 */
typedef struct
{
    char mBuffer[AUTEL_RC_PWD_BUFFER_SIZE];
} AUTELRCPassword;

/**
 *  Control style for RC 
 *
 *  遥控器摇杆操控模式
 */
typedef NS_ENUM(uint8_t, AUTELRCControlStyle){
    /**
     *  Remote Controller uses Japanese controls (also known as Mode 1). In this mode the left stick controls Pitch and Yaw, and the right stick controls Throttle and Roll.
     *
     *  日本手，左边摇杆控制 Pitch 和 Yaw，右边摇杆控制油门 和 Roll。
     */
    RCControlStyleJapanese,
    /**
     *  Remote Controller uses American controls (also known as Mode 2). In this mode the left stick controls Throttle and Yaw, and the right stick controls Pitch and Roll.
     *
     *  美国手，左边摇杆控制油门和 Yaw，右边摇杆控制 Pitch 和 Roll。
     */
    RCControlStyleAmerican,
    /**
     *  Remote Controller uses Chinese controls (also know as Mode 3). In this mode the left stick controls Pitch and Roll, and the right stick controls Throttle and Yaw.
     *
     *  中国手，左边摇杆控制 Pitch 和 Roll，右边摇杆控制油门和 Yaw。
     */
    RCControlStyleChinese,
    
    /**
     *  Error style
     *
     *  模式错误
     */
    RCControlStyleError,
    
    /**
     *  Unknown control style.
     *
     *  未知。
     */
    RCControlStyleUnknown = 0xFF,
};

/**
 *  Control style for RC
 *
 *  遥控器摇杆操控模式
 */
typedef struct
{
    /**
     *  @brief Control style.
     *
     *  操控模式
     */
    AUTELRCControlStyle mControlStyle;
} AUTELRCControlMode;

/**
 *  RC paring state 
 *
 *  遥控器配对状态
 */
typedef NS_ENUM(uint8_t, AUTELRCParingState){
    /**
     *  @brief RC not in paring state
     *
     *  未处于配对状态
     */
    RCParingStateNormal,
    /**
     *  @brief RC is in paring 
     *
     *  正在配对
     */
    RCParingStateParing,
    /**
     *  @brief RC paring completed 
     *
     *  配对完成
     */
    RCParingStateCompleted,
    /**
     *  @brief RC Paring state unknown 
     *
     *  未知配对状态
     */
    RCParingStateUnknown,
};

/**
 *  RC remaining battery level (%)
 *
 *  遥控器剩余电量百分比值.
 */
typedef struct
{
    /**
     *  @brief The remaining power percent of RC battery. [0, 100]
     *
     *  剩余电量百分比,范围[0, 100]
     */
    uint8_t  mRemainPowerPercent;
} AUTELRCBatteryInfo;

/**
 *  Wheel on the top right of RC. 
 *
 *  右侧滚轮滚动状态.
 */
typedef struct
{
    /**
     *  @brief Wheel value changed.
     *
     *  是否滚动
     */
    BOOL mWheelChanged;
    /**
     *  @brief Wheel pressed.
     *
     *  按压滚轮
     */
    AUTELRCMultiPurposeButtonState  mWheelButtonDown;
    /**
     *  @brief Wheel offset sign(+/-), YES = +, NO = -
     *
     *  滚轮偏移方向的标志,YES表示顺时针(数值为正数),NO表示逆时针(数值为负数)
     */
    BOOL mWheelOffsetSign;
    /**
     *  @brief Wheel offset value
     *
     *  滚动偏移量
     */
    int8_t mWheelOffset;
    
} AUTELRCHardwareRightWheel;


/**
 *  Wheel on the top left of RC.
 *
 *  遥控器左侧滚轮.
 */
typedef struct
{
    /**
     *  @brief Wheel value in range [364, 1684]
     *
     *  滚动范围[364, 1684]
     */
    uint16_t mValue;
} AUTELRCHardwareLeftWheel;

/**
 *  Define switch gear of RC
 *
 *  定义遥控器飞行模式切换开关档位.
 */
typedef NS_ENUM(uint8_t, AUTELRCHardwareModeSwitchState)
{
    /**
     *  @brief IOC mode on the left
     *
     *  开关处于左边档位，代表IOC模式
     */
    RCHardwareModeSwitchIOC,
    
    /**
     *  @brief GPS mode on the middle
     *
     *  开关处于中间档位，代表GPS模式
     */
    RCHardwareModeSwitchGPS,
    
    /**
     *  @brief ATTI mode on the right
     *
     *  开关处于右边档位，代表姿态模式
     */
    RCHardwareModeSwitchATTI,
    
    /**
     *  @brief Unknown
     *
     *  开关位置未知
     */
    RCHardwareModeSwitchUnknown,
};

/**
 *  @brief Mode switch on the top left of RC.
 *
 *  当前遥控器飞行模式切换开关档位.
 */
typedef struct
{
    AUTELRCHardwareModeSwitchState mMode;
} AUTELRCHardwareModeSwitch;

/**
 *  @brief State of the RC buttons
 *
 *  遥控器面板上按钮状态.
 */
typedef struct
{
    /**
     *  @brief Button state. 
     *
     *  按钮状态,YES表示按下,NO表示未按下.
     */
    BOOL mButtonDown;
} AUTELRCHardwareButton;

/**
 *  Joystick 
 *
 *  摇杆杆位值
 */
struct AUTELRCHardwareJoystick_t
{
    /**
     *  @brief Joystick's channel value in range [364, 1684]
     *
     *  摇杆杆位值范围为[364, 1684]
     */
    uint16_t mValue;
};

typedef struct AUTELRCHardwareJoystick_t AUTELRCHardwareJoystick;
//typedef struct
//{
//    /**
//     *  Joystick's channel value in range [364, 1684]
//     *  摇杆杆位值范围为[364, 1684]
//     */
//    uint16_t mValue;
//} AUTELRCHardwareJoystick;

/**
 *  The state value of the RC buttons, command sticks, and dials.
 *
 *  遥控器面板按键、摇杆、滚轮状态值.
 */
typedef struct
{
//    AUTELRCHardwareJoystick mAileron;//副翼
//    AUTELRCHardwareJoystick mElevator;//前，后
//    AUTELRCHardwareJoystick mThrottle;//油门
//    AUTELRCHardwareJoystick mRudder;//方向舵
    
    /**
     *  @brief The horizontal direction value of the left command stic
     *
     *  左摇杆水平方向值
     */
    AUTELRCHardwareJoystick mLeftHorizontal;
    /**
     *  @brief The vertical direction value of the left command stick
     *
     *  左摇杆竖直方向值
     */
    AUTELRCHardwareJoystick mLeftVertical;
    /**
     *  @brief The horizontal direction value of the right command stick
     *
     *  右摇杆水平方向值
     */
    AUTELRCHardwareJoystick mRightHorizontal;
    /**
     *  @brief The vertical direction value of the right command stick
     *
     *  右摇杆竖直方向值
     */
    AUTELRCHardwareJoystick mRightVertical;
    
    /**
     *  @brief Wheel on top left 
     *
     *  左滚轮值
     */
    AUTELRCHardwareLeftWheel mLeftWheel;
    
    /**
     *  @brief Wheel on top right 
     *
     *  右滚轮值(暂不可用)
     */
    AUTELRCHardwareRightWheel mRightWheel;
    
    /**
     *  @brief Mode switch 
     *
     *  飞行模式切换开关档位
     */
    AUTELRCHardwareModeSwitch mModeSwitch;
    
    /**
     *  @brief Go home button  
     *
     *  Go home按钮
     */
    AUTELRCHardwareButton mGoHomeButton;
    
    /**
     *  @brief Record button  
     *
     *  录制视频按钮(暂不可用)
     */
    AUTELRCMultiPurposeButtonState mRecordButton;
    
    /**
     *  @brief Shutter button  
     *
     *  拍照按钮(暂不可用)
     */
    AUTELRCHardwareButton mShutterButton;
    
    /**
     *  @brief Playback button  
     *
     *  回放按钮(暂不可用)
     */
    AUTELRCMultiPurposeButtonState mPlaybackButton;
    
    /**
     *  @brief Hover button
     *
     *  悬停按钮
     */
    AUTELRCHardwareButton mHoverButton;
    
    /**
     *  @brief Takeoff/Landing button
     *
     *  起飞和降落按钮
     */
    AUTELRCHardwareButton mTakeOffOrLandButton;
    
    /**
     *  @brief Motor Starter button
     *
     *  启动电机按钮
     */
    AUTELRCHardwareButton mTurnOnMotorButton;
    
    /**
     *  @brief Custom button1 on the bottom left
     *
     *  左侧自定义按钮(暂不可用)
     */
    AUTELRCMultiPurposeButtonState mCustomButton1;
    
    /**
     *  @brief Custom button2 on the bottom right 
     *
     *  右侧自定义按钮(暂不可用)
     */
    AUTELRCMultiPurposeButtonState mCustomButton2;
    
} AUTELRCHardwareState;

/**
 *  Define remote controller's calibration state.
 *
 *  定义遥控器校准状态.
 */
typedef NS_ENUM(uint8_t, AUTELRCCalibrationState){
    /**
     *  Normal state 
     *
     *  正常
     */
    RCCalibrationNormal,
    
    /**
     *  Record middle value 
     *
     *  记录中间值状态
     */
    RCCalibrationRecordMiddleValue,
    
    /**
     *  Record extreme value 
     *
     *  记录最大值状态
     */
    RCCalibrationRecordExtremeValue,
    
    /**
     *  Exit calibration 
     *
     *  退出校准状态
     */
    RCCalibrationExit,
};

/**
 *  Define the RF mode
 *
 *  定义射频模式.
 */
typedef NS_ENUM(uint8_t, AUTELRCRadioFrequencyMode) {
    /**
     *  @brief FCC mode
     *
     *  FCC模式
     */
    RCRadioFrequencyFCC = 0,
    /**
     *  @brief CE mode
     *
     *  CE模式
     */
    RCRadioFrequencyCE,
    /**
     *  @brief RF mode unknown
     *
     *  未知
     */
    RCRadioFrequencyUnknow = 0xFF,
};

/**
 *  Define the RC language type
 *
 *  定义遥控器语言类型
 */
typedef NS_ENUM(uint8_t, AUTELRCLanguage) {
    /**
     *  @brief English
     *
     *  英文
     */
    RCLanguageEnglish,
    
    /**
     *  @brief Chinese
     *
     *  中文
     */
    RCLanguageChinese,
    
    /**
     *  @brief Unknown
     *
     *  未知
     */
    RCLanguageUnknown = 0xFF,
};

/**
 *  Define the RC parameter unit
 *
 *  定义遥控器单位公英制
 */
typedef NS_ENUM(uint8_t, AUTELRCUnitsOfMeasurement) {
    /**
     *  @brief Imperial
     *
     *  公制 m/s
     */
    RCUnitsOfMeasurementImperial,
    
    /**
     *  @brief Metric
     *
     *  英制mph
     */
    RCUnitsOfMeasurementMetric,
    /**
     *  @brief Imperial
     *
     *  公制 km/h
     */
    RCUnitsOfMeasurementImperialForKM,
    
    /**
     *  @brief Unknown
     *
     *  未知
     */
    
    RCUnitsOfMeasurementUnknown = 0xFF,
};

/**
 *  Define the RC relation mode
 *
 *  定义遥控器关系模式.
 */
typedef NS_ENUM(uint8_t, AUTELRCRelationshipMode) {
    /**
     *  @brief Independent
     *
     *  独立
     */
    RCRelationshipModeIndependent,
    
    /**
     *  @brief Instructor
     *
     *  教练
     */
    RCRelationshipModeTrainer,
    
    /**
     *  @brief Learner
     *
     *  学生
     */
    RCRelationshipModeStudent,
    
    /**
     *  @brief RC relation mode unknown
     *
     *  遥控器关系模式未知
     */
    RCRelationshipModeUnknown = 0xFF,
};

/**
 *  RC status information
 *
 *  遥控器状态信息.
 */
typedef struct {
    /**
     *  @brief RC signal strength
     *
     *  遥控器信号强度
     */
    AUTELRCSignalQuality rcSignalQuality;
    /**
     *  @brief Video link signal strength
     *
     *  图传信号强度
     */
    AUTELRCSignalQuality dspSignalQuality;
    /**
     *  @brief RC battery level information
     *
     *  遥控器电池电量信息
     */
    AUTELRCBatteryInfo rcBatteryInfo;
    /**
     *  @brief RC calibration status
     *
     *  遥控器校准状态
     */
    AUTELRCCalibrationState rcCalibrationState;
}AUTELRCState;

/**
 *  @brief State of the specified buttons
 *
 *  特殊按钮状态.
 */
typedef struct {
    /**
     *  @brief Right dial
     *
     *  右侧滚轮
     */
    AUTELRCHardwareRightWheel mRightWheel;
    /**
     *  @brief Shutter button
     *
     *  拍照按钮
     */
    AUTELRCHardwareButton mShutterButton;
    /**
     *  @brief Record button
     *
     *  录制视频按钮
     */
    AUTELRCMultiPurposeButtonState mRecordButton;
    /**
     *  @brief Playback button
     *
     *  回放按钮
     */
    AUTELRCMultiPurposeButtonState mPlaybackButton;
    /**
     *  @brief Custom button
     *
     *  自定义按钮
     */
    AUTELRCMultiPurposeButtonState mCustomButton1;
    
    /**
     *  @brief Custom button
     *
     *  自定义按钮
     */
    AUTELRCMultiPurposeButtonState mCustomButton2;
}AUTELSpecialButtonState;

/**
 *  RC pairing result
 *
 *  遥控器配对结果.
 */
typedef NS_ENUM(uint8_t, AUTELRCParingResultState) {
    /**
     *  @brief Pairing succeeded
     *
     *  配对成功
     */
    AUTELRCParingSuccess,
    /**
     *  @brief Pairing failed
     *
     *  配对失败
     */
    AUTELRCParingFail,
    /**
     *  @brief Pairing status unknown
     *
     *  配对结果未知
     */
    AUTELRCParingUnknow,
};

/**
 *  @brief Interconnected state between remote controls
 *
 *  遥控器之间互联状态,教练/学生模式
 */
typedef NS_ENUM(uint8_t, AUTELRCInterconnectionState) {
    /**
     *  @brief The remote control is not Interconnected
     *
     *  遥控器没有互联
     */
    AUTELRCInterconnectionStateNone = 0,
    /**
     *  @brief teacher mode
     *
     *  教师模式
     */
    AUTELRCInterconnectionStateInstructorMode,
    /**
     *  @brief student mode
     *
     *  学生模式
     */
    AUTELRCInterconnectionStateLearnerMode,
    /**
     *  @brief status error
     *
     *  状态错误
     */
    AUTELRCInterconnectionStateError = 0x0F,
    /**
     *  @brief status unknown
     *
     *  状态未知
     */
    AUTELRCInterconnectionStateUnknow = 0xFF,
};

/**
 *  @brief The callback result of checking the RC RF mode.
 *
 *  查询遥控器射频模式返回结果block.
 *
 *  @param mode  RF mode
 *
 *  射频模式
 *  
 *  @param error Error message
 *  
 *  错误信息
 */
typedef void(^AUTELRequestRFModeResult)(AUTELRCRadioFrequencyMode mode, NSError *error);

/**
 *  @brief The callback result of checking the RC parameters
 *
 *  查询遥控器相关参数返回结果block.
 *
 *  @param param Unit parameter
 *
 *  单位参数
 *
 *  @param error Error message
 *
 *  错误信息
 */
typedef void(^AUTELRequestRCUINT32ParamResult)(uint32_t param, NSError *error);

/**
 *  @brief The result of checking the Gimbal Pitch Dial speed
 *
 *  查询云台滚动速率结果。
 */
typedef AUTELRequestRCUINT32ParamResult AUTELRequestRCGimbalWheelSpeedResult;

/**
 *  @brief The result of setting the gimbal pitch angle
 *
 *  设置云台俯仰结果。
 */
typedef AUTELRequestRCUINT32ParamResult AUTELSetGimbalPitchResult;

/**
 *  @brief The result of checking the gimbal pitch angle.
 *
 *  查询云台俯仰角度结果。
 */
typedef AUTELRequestRCUINT32ParamResult AUTELRequestGimbalPitchResult;

/**
 *  @brief The result of checking the RC language。
 *
 *  查询遥控器语言结果。
 *
 *  @param language RC language
 *
 *  遥控器语言
 *
 *  @param errpr    Error message
 *
 *  错误信息
 */
typedef void(^AUTELRequestRCLanguageResult)(AUTELRCLanguage language, NSError *errpr);

/**
 *  @brief The result of checking the RC calibration status
 *
 *  查询遥控器校准状态结果.
 *
 *  @param state Calibration status
 *
 *  校准状态
 *  
 *  @param error Error message 
 *
 *  错误信息
 */
typedef void(^AUTELRCCalibrationResult)(AUTELRCCalibrationState state, NSError *error);

/**
 *  @brief The result of requesting the RC version
 *
 *  请求遥控器版本结果.
 *
 *  @param rcVersion Mainboard version
 *
 *  主板固件版本
 
 *  @param rfVersion RF version
 *
 *  射频版本
 *
 *  @param error     Error message
 *
 *  错误信息
 */
typedef void(^AUTELRCVersionResult)(NSString *rcVersion, NSString *rfVersion, NSError *error);

/**
 *  @brief The result of checking the RC pairing status
 *
 *  查询遥控器配对状态结果.
 *
 *  @param pairingState Pairing state
 *
 *  配对状态
 *  
 *  @param error        Error message
 *
 *  错误信息
 */
typedef void(^AUTELRequestRCPairingStateResult)(AUTELRCParingState pairingState, NSError *error);

/**
 *  @brief The result of checking the RC command stick mode
 *
 *  查询遥控器摇杆操控模式结果.
 *
 *  @param mode  Control style for RC
 *
 *  摇杆操控模式
 *
 *  @param error Error message
 *
 *  错误信息
 */
typedef void(^AUTELRequestRCControlModeResult)(AUTELRCControlMode mode, NSError *error);

/**
 *  The result of checking the RC pairing
 *
 *  查询遥控器配对结果.
 *
 *  @param paringResult Pairing result
 *
 *  配对结果
 *  
 *  @param err          Error message
 *
 *  错误信息
 */
typedef void(^AUTELRCParingResult)(AUTELRCParingResultState paringResult, NSError *err);
