//
//  AUTELMCSystemState.h
//  AUTELSDK
//
//  Created by IOS on 15/11/4.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AUTELSDK/AUTELMainControllerDef.h>

/**
 *  Define main cotroller flight mode.
 *
 *  定义主控的飞行模式
 */
typedef NS_ENUM(uint8_t, AUTELMainControllerFlightMode) {
    /**
     *  @brief Motors stopped.
     *
     *  电机停止
     */
    AutelMCFlightModeDisarm = 0,
    /**
     *  @brief Motors rotating with aircraft on the ground.
     *
     *  飞行器电机在转动，但飞行器还在地面上。
     */
    AutelMCFlightModeLanded = 1,
    /**
     *  @brief The aircraft is landing.
     *
     *  飞行器正在降落
     */
    AutelMCFlightModeLanding = 2,
    /**
     *  @brief The airrcraft is taking off (with the use of the Takeoff/landing button or left command stick).
     *
     *  飞行器正在起飞,包括自动起飞和通过遥控器控制起飞
     */
    AutelMCFlightModeTakeoff = 3,
    /**
     *  @brief The aircraft is flying in ATTI mode.
     *
     *  飞行器正在飞行，处于姿态模式
     */
    AutelMCFlightModeAttitude = 4,
    /**
     *  @brief The aircraft is flying in GPS mode or Starpoint mode.
     *
     *  飞行器正在飞行，处于 GPS 模式或 Starpoint 模式
     */
    AutelMCFlightModeGPS = 5,
    /**
     *  @brief The aircraft is flying in IOC mode.
     *
     *  飞行器正在飞行，IOC模式
     */
    AutelMCFlightModeIOC = 6,
    /**
     *  @brief The aircraft is returing to the home point according to Go Home orders sent through remote controller or app.
     *
     *  飞行器正在自动返航，返航原因：通过遥控器或 App 向飞行器发送自动返航命令
     */
    AutelMCFlightModeManualGoHome = 7,
    /**
     *  @brief The aircraft is returning to the home point because low battery warning (25%) is activated. 
     *
     *  飞行器正在自动返航，返航原因：飞行器低电警报
     */
    AutelMCFlightModeLowBattreyGoHome = 8,
    /**
     *  @brief The aircraft is returning to the home point because minimum battery level needed for Go Home is reached.
     *
     *  飞行器正在自动返航，返航原因：智能低电返航
     */
    AutelMCFlightModeSmartLowBatteryGoHome = 9,
    /**
     *  @brief The aircraft is returning to the home point because Failsafe is treggered by signal loss between the remote controller and the aircraft.
     *
     *  飞行器正在自动返航，返航原因：飞行器丢失遥控器信号，失联保护启动
     */
    AutelMCFlightModeFailSaveGoHome = 10,
    /**
     *  @brief Auto hovering due to signal loss with the remote controller.
     *
     *  遥控器失联自动悬停
     */
    AutelMCFlightModeFailSaveHover = 11,
    /**
     *  @brief The aircraft is performing the Waypoint task.
     *
     *  飞行器正在执行航点任务
     */
    AutelMCFlightModeWaypoint = 12,
    /**
     *  @brief Waypoint task paused. Aircraft hovering.
     *
     *  航点任务已暂停，飞行器正在悬停。
     */
    AutelMCFlightModeWaypointPause = 13,
    /**
     *  @brief The aircraft exited from the Aotopilot mode and is returning to the home point automatically.
     *
     *  飞行器已自动退出智能飞行模式，正在返航。
     */
    AutelMCFlightModeWaypointGoHome = 14,
    /**
     *  @brief The aircraft is performing the Follow task.
     *
     *  飞行器正在执行追踪任务
     */
    AutelMCFlightModeFollowMe = 15,
    /**
     *  @brief The aircraft is performing the Orbit task.
     *
     *  飞行器正在执行兴趣点环绕任务
     */
    AutelMCFlightModeHotpoint = 16,
    /**
     *  @brief Follow task paused. Aircraft hovering.
     *
     *  追踪任务已暂停，飞行器正在悬停。
     */
    AutelMCFlightModeFollowMePause = 17,
    /**
     *  @brief Orbit task paused. Aircraft hovering.
     *
     *  环绕任务已暂停，飞行器正在悬停。
     */
    AutelMCFlightModeHotpointPause = 18,
    /**
     *  @see AutelMCFlightModeHotpointPause
     */
    AutelMCFlightModeEnd = AutelMCFlightModeHotpointPause,
    
    /**
     *  @brief The aircraft is performing the 360° Shoot task.
     *
     *  飞行器正在执行360°拍摄任务
     */
    AutelMCFlightMode360Shoot = 19,
    /**
     *  @brief The aircraft is performing the Epic task.
     *
     *  飞行器正在执行远景镜头任务
     */
    AutelMCFlightModeEpic = 20,
    /**
     *  @brief The aircraft is performing the Rise task.
     *
     *  飞行器正在执行上升镜头任务
     */
    AutelMCFlightModeRise = 21,
    /**
     *  @brief The aircraft is performing the FadeAway task.
     *
     *  飞行器正在执行渐远拍摄任务
     */
    AutelMCFlightModeFadeAway = 22,
    /**
     *  @brief The aircraft is performing the Intosky task.
     *
     *  飞行器正在执行冲天追踪任务
     */
    AutelMCFlightModeIntosky = 23,
    /**
     *  @brief The aircraft is performing the Boomerang task.
     *
     *  飞行器正在执行回旋镖任务
     */
    AutelMCFlightModeBoomerang = 24,
    /**
     *  @brief The aircraft is performing the Screw task.
     *
     *  飞行器正在执行螺旋拍摄任务
     */
    AutelMCFlightModeScrew = 25,
    /**
     *  @brief The aircraft is performing the Parabola task.
     *
     *  飞行器正在执行抛物线任务
     */
    AutelMCFlightModeParabola = 26,
    /**
     *  @brief The aircraft is performing the Asteroid task.
     *
     *  飞行器正在执行小行星任务
     */
    AutelMCFlightModeAsteroid = 27,
    /**
     *  @brief The aircraft is performing the Circle Round task.
     *
     *  飞行器正在执行环绕追踪任务
     */
    AutelMCFlightModeCircleRound= 28,
    /**
     *  @brief The aircraft is performing the DollyZoom task.
     *
     *  飞行器正在执行移动变焦任务
     */
    AutelMCFlightModeDollyZoom = 29,
    /**
     *  @brief The aircraft is performing the Tripod task.
     *
     *  飞行器正在执行三脚架任务
     */
    AutelMCFlightModeTripod = 30,
    /**
     *  @brief The aircraft is performing the Photographer task.
     *
     *  飞行器正在执行影像增稳任务
     */
    AutelMCFlightModePhotographer = 31,
    
    /**
     *  @brief The aircraft is performing the Rectangle task.
     *
     *  飞行器正在执行矩形任务飞行
     */
    AutelMCFlightModeRectangle = 32,
    /**
     *  @brief Rectangle task paused. Aircraft hovering.
     *
     *  矩形任务已暂停，飞行器正在悬停。
     */
    AutelMCFlightModeRectanglePause = 33,
    
    /**
    *  @brief The aircraft is performing the Polygon task.
    *
    *  飞行器正在执行多边形任务飞行
    */
   AutelMCFlightModePolygon = 34,
   /**
    *  @brief Polygon task paused. Aircraft hovering.
    *
    *  多边形任务已暂停，飞行器正在悬停。
    */
   AutelMCFlightModePolygonPause = 35,
    
    /**
     *  @brief The aircraft is performing the DelayShot task.
     *
     *  飞行器正在进行自由延时摄影任务
     */
    AutelMCFlightModeDelayShot = 36,
    /**
     *  @brief DelayShot task paused. Aircraft hovering.
     *
     *  飞行器自由延时摄影任务暂停。
     */
    AutelMCFlightModeDelayShotPause = 37,
    
    /**
     *  @brief The aircraft is performing the Oblique photography  task.
     *
     *  飞行器正在执行倾斜摄影任务飞行
     */
    AutelMCFlightModeObliquePhoto = 38,
    /**
     *  @brief Oblique photography  task paused. Aircraft hovering.
     *
     *  倾斜摄影已暂停，飞行器正在悬停。
     */
    AutelMCFlightModeObliquePhotoPause = 39,
    
    /**
     *  @brief The aircraft is performing the Panoramic photo task.
     *
     *  飞行器正在进行全景摄影任务
     */
    AutelMCFlightModePanoramicPhoto = 40,
    /**
     *  @brief Panoramic photo task paused. Aircraft hovering.
     *
     *  飞行器全景摄影任务暂停。
     */
    AutelMCFlightModePanoramicPhotoPause = 41,
    
    /**
     * The Dynamic Track mode is common.__deprecated
     */
    AutelMCFlightModeTrackCommonMode = 19 + 181,
    /**
     * The Dynamic Track mode is parallel.__deprecated
     */
    AutelMCFlightModeTrackParallelMode = 20 + 181,
    /**
     * The Dynamic Track mode is tripod.__deprecated
     */
    AutelMCFlightModeTrackLockedMode = 21 + 181,
    /**
     *  @brief Indoor view point.__deprecated
     *
     * 室内指点飞行
     */
    AutelMCFlightModePointFlyInside = 22 + 181,
    /**
     *  @brief Outdoor view point.__deprecated
     *
     * 室外指点飞行
     */
    AutelMCFlightModePointFlyOutside = 23 + 181,
    
    /**
     *  @brief Unknown flight mode
     *
     *  飞行模式未知
     */
    AutelMCFlightModeUnknow = 0xFF,
};

/**
 *  Aircraft Main mode
 *
 *  无人机飞行主模式
 */
typedef NS_ENUM(uint8_t, AUTELMainControllerMainMode) {
    /**
     *  @brief Unknown main mode
     *
     *  主模式未知
     */
    AUTELMCMainModeUnknown = 0,
    /**
     *  @brief attitude (ATTI)
     *
     *  姿态
     */
    AUTELMCMainModeAttitude,
    /**
     *  @brief GPS
     *
     *  GPS
     */
    AUTELMCMainModeGPS,
    /**
     *  @brief IOC
     *
     *  IOC
     */
    AUTELMCMainModeIOC,
    /**
     *  @brief Indoor positioning
     *
     *  室内定位
     */
    AUTELMCMainModeStarpoint,
};

/**
 *  App-controlled stick mode
 *
 *  无人机虚拟摇杆模式
 */
typedef NS_ENUM(uint8_t, AUTELVirtualStickMode) {
    /**
     *  @brief The aircraft is not in app-controlled stick mode.
     *
     *  无人机不在虚拟摇杆模式
     */
    AUTELVirtualStickModeNone,
    /**
     *  @brief App-controlled stick mode (control all axes)
     *
     *  无人机虚拟摇杆模式（所有轴都能控制）
     */
    AUTELVirtualStickModeAll,
    /**
     *  @brief App-controlled stick mde (control yaw axis only)
     *
     *  无人机虚拟摇杆模式（只控制Yaw轴）
     */
    AUTELVirtualStickModeYaw,
};

/**
 *  @brief Define No-fly state of the aircraft.
 *
 *  定义飞行器禁飞状态
 */
typedef NS_ENUM(uint8_t, AUTELMainControllerNoFlyStatus){
    /**
     *  @brief Flying normal
     *
     *  正常飞行
     */
    DroneNormalFlying = 0,
    
    /**
     *  @brief Approaching Flight-Restricted Zone.
     *
     *  靠近限飞区
     */
    DroneApproachingNoFlyZone = 1,
    
    /**
     *  @brief Arrived at Flight-Restricted zone.
     *
     *  到达限飞区
     */
    DroneUnderLimitFlyZone = 2,
    
    /**
     *  @brief Max altitude reached in Flight-Restricted Zone.
     *
     *  在限飞区中到达最大高度
     */
    DroneReachMaxFlyingHeightInLimitFlyZone = 3,
    
    /**
     *  @brief Entering No-Fly zone.
     *
     *  飞机进入禁飞区
     */
    DroneInNoFlyZone = 4,
    
    /**
     *  @brief Entering No-Fly zone.
     *
     *  飞机进入禁飞区，谨慎飞行（美国地区禁飞区也可飞行）
     */
    DroneInENNoFlyZone = 5,

    /**
     *  @brief Unknown No-Fly state of the aircraft.
     *
     *  飞机禁飞状态未知
     */
    UnknownStatus,
};

/**
 *  Define GPS signal strength level.
 *
 *  定义GPS信号强度级别
 */
typedef NS_ENUM(uint8_t, AUTELGpsSignalLevel){
    /**
     *  @brief GPS signal critical weak
     *
     *  GPS 信号非常差
     */
    GpsSignalLevel0,
    
    /**
     *  @brief Gps signal very weak
     *
     *  GPS 信号很弱
     */
    GpsSignalLevel1,
    
    /**
     *  @brief Gps signal weak
     *
     *  GPS 信号弱
     */
    GpsSignalLevel2,
    
    /**
     *  @brief Gps signal good
     *
     *  GPS 信号好
     */
    GpsSignalLevel3,
    
    /**
     *  @brief Gps signal very good
     *
     *  GPS 信号很好
     */
    GpsSignalLevel4,
    
    /**
     *  @brief Gps signal very strong
     *
     *  GPS 非常强
     */
    GpsSignalLevel5,
    
    /**
     *  @brief No GPS signal or GPS signal unavailable.
     *
     *  没有 GPS 信号，或 GPS 不可用
     */
    GpsSignalLevelNone,
};

/**
 *  Define low battery warning.
 *
 *  定义低电警报
 */
typedef NS_ENUM(uint8_t, AUTELDroneLowPowerWarning) {
    /**
     *  @brief No low battery warning.
     *
     *  无低电警报
     */
    DroneHeightPower,
    
    /**
     *  @brief Low battery.
     *
     *  低电量
     */
    DroneLowPower,
    
    /**
     *  @brief Critical low battery.
     *
     *  严重低电量
     */
    DroneVeryLowPower,
    
    /**
     *  @brief Unknown
     *
     *  未知
     */
    DroneLowPowerUnknow = 0xFF
};

/**
 *  Define the causes for failure of starting motors.
 *
 *  定义电机无法转动原因
 */
typedef NS_ENUM(uint8_t, AUTELControlMotorError) {
    /**
     *  @brief Motor work normal
     *
     *  电机没有警告
     */
    AUTELControlMotorErrorNormal = 0,
    
    /**
     *  @brief IMU abnormal
     *
     *  IMU 异常
     */
    AUTELControlMotorErrorIMUError = 1,
    
    /**
     *  @brief critical low power
     *
     *  严重低电量
     */
    AUTELControlMotorErrorCriticalLowPower = 2,
    
    /**
     *  @brief Barometer abnormal
     *
     *  气压计异常
     */
    AUTELControlMotorErrorBarometerError = 3,
    
    /**
     *  @brief In NoFly zone
     *
     *  在禁飞区内
     */
    AUTELControlMotorErrorInNoFlyZone = 4,
    
    /**
     *  @brief IOC abnormal
     *
     *  IOC 异常
     *
     *  正在校准指南针
     */
    AUTELControlMotorErrorIOCError = 5,
    
    /**
     *  @brief GPS signal not found in Beginner mode.
     *
     *  新手模式,无GPS
     */
    AUTELControlMotorErrorNoviceModeEnableAndNoGPSSignal = 6,
    
    /**
     *  @brief Aircraft tilting, turning off the motor
     *
     *  飞行器倾斜, 关闭电机
     */
    AUTELControlMotorErrorDisamrAircraftTilt = 7,
    
    /**
     *  @brief IMU abnormal, turn off the motor
     *
     *  IMU 异常, 关闭电机
     */
    AUTELControlMotorErrorDisamrIMUError = 8,
    
    /**
     *  @brief IMU preheating
     *
     *  @brief IMU 预热
     */
    AUTELControlMotorErrorIMUPreheating = 9,
    
    /**
     *  @brief Compass is calibrating
     *
     *  指南针正在校准
     */
    AUTELControlMotorErrorIsCalibratingCompress = 10,
    
    /**
     *  @brief Multiple sensor anomalies
     *
     *  多个传感器异常
     */
    AUTELControlMotorErrorMultipleSensorsError = 11,
    
    /**
     *  @brief Gimbal is not ready
     *
     *  云台未就绪
     */
    AUTELControlMotorErrorGimbalNotReady = 12,
    
    /**
     *  @brief Firmware upgrade is in progress
     *
     *  正在执行固件升级
     */
    AUTELControlMotorErrorIsUpgradingFirmware = 13,
    
    /**
     *  @brief Initializing attitude
     *
     *  姿态初始化中
     */
    AUTELControlMotorErrorIsInitializingAttitude = 15,
    
    /**
     *  @brief RTK is not ready
     *
     *  RTK未就绪
     */
    AUTELControlMotorErrorIsRTKNotReady = 16,
    
    /**
     *  @brief Aircraft is not activated
     *
     *  飞机未激活
     */
    AUTELControlMotorErrorIsAircraftNotActivated = 17,
};

/**
 *  This class includes the states of main controller. The real-time state of main controller is updated by AUTELDroneMainControllerDelegate.mainController:didUpdateSystemState:
 *
 *  该类存储飞行器主控状态。飞行器主控状态由 AUTELDroneMainControllerDelegate 的 -mainController:didUpdateSystemState: 方法实时更新。
 */
@interface AUTELMCSystemState : NSObject<NSCopying>

/**
 *  @brief Visibility of GPS satellite.
 *
 *  可见卫星数
 */
@property(nonatomic, assign) int satelliteCount;

/**
 *  @brief Home location of the aircraft as a coordinate.
 *
 *  飞行器返航点位置.
 *
 *  @discussion This is the location where the aircraft fly to when go home is triggered. Call AUTELDroneMainController. setHomePointAtCurrentGPSPositionWithComletion and AUTELDroneMainController. setHomePoint:withCompletion to set home point.
 *
 *  The main controller sets current location as home point when motors started. If the home point is invalid, property isHomeInvalid will turn to YES.
 *
 *  当飞行器自动返航时将飞行到该位置。用户可以通过 AUTELDroneMainController 的 -setHomePointAtCurrentGPSPositionWithComletion 和 -setHomePoint:withCompletion: 方法设置返航点。
 *
 *  每次飞行器启动电机时都会将返航点重置为飞行器的当前位置。如果飞行器返航点无效，则 isHomeInvalid 属性为 YES。
 *
 *  @see AUTELDroneMainController
 *  @see isHomeInvalid
 */
@property(nonatomic, assign) CLLocationCoordinate2D homeLocation;

/**
 *  @brief Current location of the aircraft as a coordinate.
 *
 *  飞行器当前位置
 *
 *  @discussion If property isGPSWeakWarning is Yes, then current location of drone is invalid.
 *
 *  当 droneLocation 是个无效 GPS 坐标或 isGPSWeakWarning 为 YES，说明无法定位飞行器位置，应当忽略 droneLocation。
 *
 *  @see isGPSWeakWarning
 */
@property(nonatomic, assign) CLLocationCoordinate2D droneLocation;

/**
 *  @brief Current speed of the aircraft in the x direction in meters per second using the N-E-D (North-East-Down) coordinate system.
 *
 *  无人机当前在 x 方向上的速度（m/s），该速度使用北-东-下坐标系。
 */
@property(nonatomic, assign) float velocityX;

/**
 *  @brief Current speed of the aircraft in the y direction in meters per second using the N-E-D (North-East-Down) coordinate system.
 *
 *  无人机当前在 y 方向上的速度（m/s），该速度使用北-东-下坐标系。
 */
@property(nonatomic, assign) float velocityY;

/**
 *  @brief Current speed of the aircraft in the z direction in meters per second using the N-E-D (North-East-Down) coordinate system.
 *
 *  无人机当前在 z 方向上的速度（m/s），该速度使用北-东-下坐标系。
 */
@property(nonatomic, assign) float velocityZ;

/**
 *  @brief AGL：Relative altitude of the aircraft relative to take off location, in meters.
 *
 *  飞行器相对于起飞点的相对高度（m）。
 */
@property(nonatomic, assign) float altitude;

/**
 *  @brief MSL：The absolute height of the aircraft relative to sea level (m), measured by barometer.
 *
 *  飞行器相对于海平面的绝对高度（m）。
 */
@property(nonatomic, assign) float altitudeMSL;

/**
 *  @brief Distance between the aircraft and the Home point
 *
 *  飞行器与 Home 点之间的距离
 */
@property(nonatomic, assign) float distance;

/**
 *  @brief The attidue of aircraft.
 *
 *  飞行器姿态。
 *
 *  @discussion The range of attitude.pitch is from - π/2 to π/2. Sets to -π/2 so that the head of aircraft vertically faces down. Sets to π/2 so that the head of aircraft vertically faces up. Sets to 0 so that the front and back wing stays in horizon.  
 *  The range of attitude.roll is –π to π. Sets to 0 so that the left and right ailerons stays in horizon. Sets to -π/2 so that the right aileron is higher than left aileron and stays vertically to the ground. Sets to π/2 so that the left aileron is high then the right aileron and stays vertically to the ground. Sets to π or –π so that the aircraft horizontal inverse. 
 *  The range of attitude.yaw is from –π to π. Sets 0 for attitude.yaw to face north, sets  -π/2 to face west, sets π/2 to face east and sets π or –π to face south.
 *
 *  attitude.pitch 范围[-π/2, π/2]，前后翼水平为 0，机头垂直朝上为 π/2，机头垂直朝下为 -π/2。
 *  attitude.roll 范围[-π, π]，左右副翼水平为 0，右副翼高于左副翼垂直与地面为 -π/2，左副翼高于右副翼垂直于地面为 π/2，水平倒置为 π 或 -π。
 *  attitude.yaw 范围[-π, π]，正北为 0，正西为 -π/2，正东为 π/2，正南为 π 或 -π。
 *
 *  @see AUTELAttitude
 */
@property(nonatomic) AUTELAttitude attitude;

/**
 *  @brief Remain power percentage of the battery.
 *
 *  剩余电量百分比
 **/
@property(nonatomic, assign) float powerPercentage;

/**
 *  @brief 剩余飞行时间
 */
@property(nonatomic, assign) float remainingFlightTime;

/**
 *  @brief The current electricity volume of battery (mAh). 
 *
 *  电池剩余电量(mAh)。
 */
@property(nonatomic, assign) float currentElectricity;

/**
 *  @brief Lower battery warning
 *
 *  低电警报
 *
 *  @discussion When powerWarning is DroneLowPower, the aircraft will start to go home. When powerWarning is DroneVeryLowPower, the aircraft will start to land on the ground.
 *
 *  当 powerWarning 为 DroneLowPower 时飞行器会自动返航，当 powerWarning 为 DroneVeryLowPower 时飞行器会自动降落。
 *
 *  @see AUTELDroneLowPowerWarning
 */
@property(nonatomic, assign) AUTELDroneLowPowerWarning powerWarning;

/**
 *  @brief This property describes whether the battery is an unknown battery.
 *
 *  无法识别的电池
 */
@property(nonatomic, assign) BOOL isUnknowBattery;

/**
 *  @brief Return whether the drone is flying.
 *
 *  返回无人机是否已经起飞。
 */
@property(nonatomic, assign) BOOL isFlying;

/**
 *  @brief Return whether the drone is auto flying to home point.
 *
 *  返回飞行器是否正在自动返航
 */
@property(nonatomic, assign) BOOL isAutoFlyingToHomePoint;

/**
 *  @brief Return flight mode. 
 *
 *  返回无人机飞行模式。
 *
 *  @see AUTELMainControllerFlightMode
 */
@property(nonatomic, assign) AUTELMainControllerFlightMode flightMode;

/**
 *  @brief Main mode. 
 *
 *  无人机主模式。
 *
 *  @see AUTELMainControllerMainMode
 */
@property(nonatomic, assign) AUTELMainControllerMainMode mainMode;

/**
 *  @brief No fly status. 
 *
 *  无人机限飞/禁飞状态。
 *
 *  @see AUTELMainControllerNoFlyStatus
 */
@property(nonatomic, assign) AUTELMainControllerNoFlyStatus noFlyStatus;

/**
 *  @brief GPS signal level. 
 *
 *  GPS 信号强度。
 *
 *  @see AUTELGpsSignalLevel
 */
@property(nonatomic, assign) AUTELGpsSignalLevel gpsSignalLevel;

/**
 *  @brief  This property describes whether RC singal is lost, if lost then execute failsafe program.
 *
 *  无人机是否跟遥控器失去联系。
 */
@property(nonatomic, assign) BOOL isFailsafe;

/**
 *  @brief This property describes whether IMU is pre-heating
 *
 *  IMU是否正在预热。
 */
@property(nonatomic, assign) BOOL isIMUPreheating;

/**
 *  @brief This property describes whether compass is abnomal
 *
 *  磁力计是否异常
 */
@property(nonatomic, assign) BOOL isCompassError;

/**
 *  @brief The level of compass interference.
 *
 *  指南针受干扰等级。
 *
 *  @see AUTELCompassInterferenceLevel
 */
@property(nonatomic, assign) AUTELCompassInterferenceLevel compassInterferenceLevel;

/**
 *  @brief This property describes whether ultrasonic is working
 *
 *  超声波模块是否工作。
 */
@property(nonatomic, assign) BOOL isUltrasonicWorking;

/**
 *  @brief Height of aircraft measured by the ultrasonic, data is valid while property isUltrasonicWorking is YES.
 *
 *  超声波测量的高度，只有在 isUltrasonicWorking 为 YES 的时候数据才是有效的。
 */
@property(nonatomic, assign) float ultrasonicHeight;

/**
 *  @brief This property describes whether motors are on.
 *
 *  电机是否转动。
 */
@property(nonatomic, assign) BOOL isMotorWorking;

/**
 *  @brief Main controller warning flag.
 *
 *  主控的警告标志。
 **/
@property(nonatomic, assign) uint32_t mcWarningFlage;

/**
 *  @brief This property describes whether the aircraft reaches maximum distance
 *
 *  飞行器是否到达最远飞行距离。
 **/
@property(nonatomic, assign) BOOL isReachMaxRange;

/**
 *  @brief 飞行器是否接近最远飞行距离。
 *
 *  飞行器是否接近最远飞行距离。
 **/
@property(nonatomic, assign) BOOL isNearMaxRange;

/**
 *  @brief This property describes whether the aircraft reaches maximum height.
 *
 *  飞行器是否到达最大飞行高度。
 **/
@property(nonatomic, assign) BOOL isReachMaxHeight;

/**
 *  @brief This property describes whether there is a GPS weak warning. If Yes, then the value of droneLocation is invalid.
 *
 *  是否有 GPS 信号差警报，如果 isGPSWeakWarning 为 YES，droneLocation 无效。
 **/
@property(nonatomic, assign) BOOL isGPSWeakWarning;

/**
 *  @brief If user presses go home button while pushing throttle. isPushThrottleWhileGoHome turns to Yes, else stays in no value.
 *
 *  如果用户在推摇杆时，遥控器模式开关拨到了“Go Home”位置，isPushThrottleWhileGoHome 为 YES，否则为 NO。
 **/
@property(nonatomic, assign) BOOL isPushThrottleWhileGoHome;

/**
 *  @brief This property describes whether user is pressing auto take-off button while motors are off.
 *
 *  如果用户在启动电机前尝试使用一键起飞功能，isTakeOffBeforArm 为 YES，否则为 NO。
 **/
@property(nonatomic, assign) BOOL isTakeOffBeforArm;

/**
 *  @brief This property describes whether front LED is on.
 *
 *  前臂灯是否打开
 **/
@property(nonatomic, assign) BOOL isFrontLEDTurnOn;

/**
 *  @brief This property describes the status of compass calibration.
 *
 *  指南针校准状态
 **/
@property(nonatomic, assign) AUTELCompassCalibrationStatus compassCalibrationStatus;

/**
 *  @brief The reason why motors can not be fire up.
 *
 *  电机无法启动原因。
 *
 *  @discussion IF motors can be fired up for some reasons, the value of turnOnMotoeError will ne assigned. Each bit of the value presents one error message, please check the detail error message in AUTELControlMotorError. Calculate the values of turnOnMotorError and  AUTELControlMotorError to get the error message.
 *
 *  当用户试图用遥控器启动飞行器电机，而由于某些原因电机无法启动时，turnOnMotorError 会被设置。当 turnOnMotorError 的每一位表示一种原因，每一位对应的原因参见 AUTELControlMotorError，turnOnMotorError 与 AUTELControlMotorError 中的值进行或运算就能知道电机无法启动的原因有哪些。
 *
 *  @see AUTELControlMotorError
 */
@property(nonatomic, assign) uint8_t turnOnMotorError;

/**
 *  @brief Battery temperature alarm
 *
 *  电池温度报警
 */
@property(nonatomic, assign) AUTELBatteryTemperatureWarning batteryTemperatureWarning;

/**
 *  @brief This property describes whether the battery is overheated.
 *
 *  电池是否过热
 */
@property(nonatomic, assign) BOOL isBatteryOverheated;

/**
 *  @brief This property describes whether the battery has too low temperature.
 *
 *  电池温度是否过低。
 */
@property(nonatomic, assign) BOOL isBatteryLowTemperature;

/**
 *  @brief This property describes whether Battery cell voltage imbalance
 *
 *  电池电芯电压不平衡
 */
@property(nonatomic, assign) BOOL isBatteryVoltageDiff;

/**
 *  @brief This property describes whether IMU is overheated.
 *
 *  IMU是否过热。
 */
@property(nonatomic, assign) BOOL isIMUOverheated;

/**
 *  @brief This property describes whether home point is valid.
 *
 *  Home点无效，如果为 YES，homeLocation 无效。
 *  
 *  @see homeLocation
 */
@property(nonatomic, assign) BOOL isHomeInvalid;

/**
 *  @brief The flight control requests to return, if the user does not respond, the aircraft will return after 10s.
 *
 *  飞控请求返航, 如果用户不回应, 则10s 后飞行器将返航
 */
@property(nonatomic, assign) BOOL isAircraftRequestingToGoHome;

/**
 *  @brief is stick limited
 *
 *  杆量受限
 */
@property(nonatomic, assign) BOOL isStickLimited;

/**
 *  @brief is Return point may not be accurate
 *
 *  返航点可能不准确
 */
@property(nonatomic, assign) BOOL isHomePointNotAccurate;

/**
 *  @brief Main mode string. ex. "GPS", "Atti", "IOC", "Starpoint".
 *
 *  主模式字符串。
 */
@property(nonatomic, copy) NSString* mainModeString;

/**
 *  @brief Virtual joystick mode
 *
 *  虚拟摇杆模式
 */
@property(nonatomic, assign) AUTELVirtualStickMode virtualMode;

/**
 *  Version ID
 */
@property(nonatomic, assign) NSUInteger versionID;

/**
 *  Support RTK
 */
@property(nonatomic, assign) BOOL supportRTK;

/**
 *  @brief Aircraft GPS signal radius
 *
 飞机GPS信号半径
 */
@property(nonatomic, assign) double aircraftGPSSignalRadius;

/**
*  @brief This property describes the status of IMU calibration.
*
IMU校准状态
*/
@property(nonatomic, assign) AUTELIMUCalibrationStatus imuCalibrationStatus;

/**
*  @brief IMU calibration warn
*
IMU校准告警
*/
@property(nonatomic, assign) AUTELIMUCalibrationWarn imuCalibrationWarn;


/**
 * 配件工作模式， 0 ：夜航灯， 1：探照灯， 2：喊话器
 */
@property(nonatomic) AUTELAccessoryWorkMode accessoryWorkMode;

/**
 * 配件调节值， 取值范围[0-100]。意义取决于WorkMode，
 * WorkMode如果为[0, 1], AdjustValue表示亮度
 * WorkMode如果为[2], AdjustValue表示音量
 */
@property(nonatomic) NSInteger accessoryAdjustValue;

@end
