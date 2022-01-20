//
//  AUTELBattery.h
//  AUTELSDK
//
//  Created by cyl on 15/11/12.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>

@class AUTELDrone;

/**
 *  Define AUTELBatterySafeState Class
 */

@interface AUTELBatterySafeState : NSObject<NSCopying> {
}

/**
 battery value
 */
@property(nonatomic, assign) int64_t rawBatteryValue;

/**
 *  @brief is Battery about to shut down
 *
 *  电池即将关闭
 */
@property(nonatomic, assign) BOOL isWillShutDown;

/**
 *  @brief is Coulometer hitch
 *
 *  电量计异常
 */
@property(nonatomic, assign) BOOL isCoulometerHitch;

/**
 *  @brief is Voltage difference alarm
 *
 *  电压差报警
 */
@property(nonatomic, assign) BOOL isCellVoltageDifference;

/**
 *  @brief is the Battery temperature too low
 *
 *  电池温度过低
 */
@property(nonatomic, assign) BOOL isLowTemperature;

/**
 *  @brief is the Battery temperature critically low
 *
 *  温度严重过低
 */
@property(nonatomic, assign) BOOL isCriticallyLowTemperature;

/**
 *  @brief is overheated
 *
 *  温度过高
 */
@property(nonatomic, assign) BOOL isOverheated;

/**
 *  @brief is the cell low voltage compensated
 *
 *  电芯低压补偿保护
 */
@property(nonatomic, assign) BOOL isCellLowVoltageCompensated;

/**
 *  @brief is Discharge short circuit Latch
 *
 *  放电短路保护锁
 */
@property(nonatomic, assign) BOOL isDischargeShortCircuitLatch;

/**
 *  @brief Is the cell voltage too high
 *
 *  电芯电压过高
 */
@property(nonatomic, assign) BOOL isCellOvervoltage;

/**
 *  @brief is cell low voltage
 *
 *  电芯电压过低
 */
@property(nonatomic, assign) BOOL isCellLowVoltage;

/**
 *  @brief is short circuit
 *
 *  放电短路
 */
@property(nonatomic, assign) BOOL isShortCircuit;

/**
 *  @brief is overload
 *
 *  过载
 */
@property(nonatomic, assign) BOOL isOverload;

@end

@interface AUTELBatteryState : NSObject<NSCopying>

/**
 *  @brief Designed capacity of battery (mAh).
 *
 *  电池设计容量(mAh).
 */
@property(nonatomic, assign) NSInteger designedVolume;

/**
 *  @brief Full charge capacity of battery (mAh).
 *
 *  电池满电容量(mAh).
 */
@property(nonatomic, assign) NSInteger fullChargeVolume;

/**
 *  @brief Current electricity volume of battery (mAh).
 *
 *  当前电池电量(mAh).
 */
@property(nonatomic, assign) float currentElectricity;

/**
 *  @brief The current voltage of battery (mV).
 *
 *  当前电压(mV).
 */
@property(nonatomic, assign) float currentVoltage;

/**
 *  @brief Current current of battery. A negative value indicates that the battery is in discharge.
 *
 *  当前电流(mA),负值表示电池正在放电.
 */
@property(nonatomic, assign) float currentCurrent;

/**
 *  @brief Remain power percentage of battery.
 *
 *  剩余电量百分比.
 */
@property(nonatomic, assign) NSUInteger remainPowerPercent;

/**
 *  @brief Remaining flight time
 *
 *  剩余飞行时间
 */
@property(nonatomic, assign) float remainingFlightTime;

/**
 *  @brief The temperature of battery between -128 to 127 (Centigrade).
 *
 *  电池温度，范围 -128 至 127(摄氏度).
 */
@property(nonatomic, assign) float batteryTemperature;

/**
 *  @brief Returns Yes if battery overheated else No.
 *
 *  返回电池是否过热，电池过热返回 YES，否则返回 NO。
 */
@property(nonatomic, assign) BOOL isBatteryOverheated;

/**
 *  @brief Returns Yes if battery has low temperature else No.
 *
 *  返回电池温度是否过低，电池温度过低返回 YES，否则返回 NO。
 */
@property(nonatomic, assign) BOOL isBatteryLowTemperature;

/**
 *  @brief Is the battery temperature too low
 *
 *  电池温度过低
 */
@property(nonatomic, assign) BOOL isBatteryCriticallyLowTemperature;

/**
 *  @brief Returns Yes if the battery cell voltage imbalance else No
 *
 *  电池电芯电压不平衡
 */
@property(nonatomic, assign) BOOL isBatteryVoltageDiff;

/**
 *  @brief Total number of battery discharge time.
 *
 *  电池放电次数.
 */
@property(nonatomic, assign) NSInteger numberOfDischarge;

/**
 *  @brief Current voltage of battery cells.
 *
 *  各电芯电压.
 */
@property(nonatomic, copy) NSArray<NSNumber *> *voltageOfCells;

@property(nonatomic, assign) uint32_t maxError;

/**
 *  @brief Safe State, only for module B gimbal, if App connected to x-start, this property will be nil
 */
@property(nonatomic, strong) AUTELBatterySafeState *safeState;

@end

extern NSString *const kBatteryInfoFirmwareVirsion;

extern NSString *const kBatteryInfoChargedTimes;

extern NSString *const kBatteryInfoTimeToDischarge;

@class AUTELBattery;

@protocol AUTELBatteryDelegate <NSObject>

- (void)battery:(AUTELBattery *)battery didUpdataState:(AUTELBatteryState *)state NS_SWIFT_NAME(battery(_:didUpdataState:));

@end

/**
 *  This class includs battery related functions, it is also able to get real-time battery status.
 *
 *  该类管理电池相关信息，并可获取飞行器电池的实时状态.
 */
@interface AUTELBattery : NSObject

/**
 *  @brief Designed capacity of battery (mAh).
 *
 *  电池设计容量(mAh).
 */
@property(nonatomic, readonly) NSInteger designedVolume;

/**
 *  @brief Full charge capacity of battery (mAh).
 *
 *  电池满电容量(mAh).
 */
@property(nonatomic, readonly) NSInteger fullChargeVolume;

/**
 *  @brief Current electricity volume of battery (mAh).
 *
 *  当前电池电量(mAh).
 */
@property(nonatomic, readonly) float currentElectricity;

/**
 *  @brief The current voltage of battery (mV).
 *
 *  当前电压(mV).
 */
@property(nonatomic, readonly) float currentVoltage;

/**
 *  @brief Current current of battery. A negative value indicates that the battery is in discharge.
 *
 *  当前电流(mA),负值表示电池正在放电.
 */
@property(nonatomic) float currentCurrent;

/**
 *  @brief Remain power percentage of battery.
 *
 *  剩余电量百分比.
 */
@property(nonatomic, readonly) NSInteger remainPowerPercent;

/**
 *  @brief The temperature of battery between -128 to 127 (Centigrade).
 *
 *  电池温度，范围 -128 至 127(摄氏度).
 */
@property(nonatomic, readonly) float batteryTemperature;

/**
 *  @brief Returns Yes if battery overheated else No.
 *
 *  返回电池是否过热，电池过热返回 YES，否则返回 NO。
 */
@property(nonatomic) BOOL isBatteryOverheated;

/**
 *  @brief Returns Yes if battery has low temperature else No.
 *
 *  返回电池温度是否过低，电池温度过低返回 YES，否则返回 NO。
 */
@property(nonatomic) BOOL isBatteryLowTemperature;

/**
 *  电池电芯电压是否不平衡
 */
@property(nonatomic) BOOL isBatteryVoltageDiff;

/**
 *  @brief Total number of battery discharge time.
 *
 *  电池放电次数.
 */
@property(nonatomic, readonly) NSInteger numberOfDischarge;

/**
 *  @brief Current voltage of battery cells.
 *
 *  各电芯电压.
 */
@property(nonatomic, readonly) NSArray *voltageOfCells;

/**
 *  @brief Firmware version of battery.
 *
 *  电池固件版本号。
 */
@property(nonatomic, readonly) NSString *version;

/**
 *  @brief Returns a instance of AUTELDrone. drone.battery is the same as self.
 *
 *  返回持有电池对象的 AUTELDrone 对象。self 与 drone.battery 是同一实例。
 *
 *  @see AUTELDrone
 */
@property (weak, nonatomic, readonly) AUTELDrone *drone;

@property (weak, nonatomic) id<AUTELBatteryDelegate> delegate;

@property (weak, nonatomic) id<AUTELBatteryDelegate> delegateSec;

/**
 *  @brief Update battery's information once, if Succeeded, the property value of battery will be update.
 *
 *  更新电池相关信息，如果成功，将会更新 self 的所有属性的数据一次.
 *
 *  @param block Completion block.
 *
 *  完成 block.
 */
- (void)updateBatteryInfo:(AUTELCompletionBlock)block;

/**
 *  @brief Get self discharge start time of battery.
 *
 *  获取智能电池开始自放电天数(数组第一个对象是当前电池自放电状态).
 *
 *  @param block 执行结果.
 */
- (void)getSelfDischargeDayWithCompletion:(void(^)(uint8_t days, NSError *err))block;

/**
 *  @brief Set self discharge start time of battery. 
 *
 *  设置智能电池开始自放电天数.
 *
 *  @param days self discharge start time from 1 to 10 days. 开始自放电天数,范围[1,10].
 */
- (void)setSelfDischargeDay:(uint8_t)days withCompletion:(AUTELCompletionBlock)block;

/**
 *  Gets the battery's history. The Autel battery keeps the history for
 *  the past 20 days. The `history` variable in the block stores objects of type
 *  state:1.充电过流 2.放电过流 3.充电过温 4.放电过温 5.过载保护 6.QMAX未更新 其他正常
 *
 *  @param block Remote execution result callback block.
 */
- (void)getWarningInformationRecordsWithCompletion:(void (^)(NSArray *history, NSError *error))block;

/**
 *  @brief Query battery serial number
 *
 *  查询电池序列号
 *
 *  @param block 执行结果
 */
- (void)getBatterySNWithCompletion:(void (^)(NSString *batterySN, NSError *error))block;

/**
 *  Get battery information
 */
- (void)getBateryInfo:(void (^)(NSDictionary *info, NSError *error))block;

@end
