//
//  AUTELDSPSignalChannel.h
//  AUTELSDK
//
//  Created by Autel_ljm on 15/12/17.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct {
    /**
     *  @brief Signal frequency
     *
     *  信息频率
     */
    NSUInteger frequency;
    /**
     *  @brief Signal strength
     *
     *  信息强度
     */
    NSInteger signalStrength;
} AUTELDSPSignalStrength;

/**
 *  @brief Signal strengths
 *
 *  所有信道的数值
 */
typedef struct {
    AUTELDSPSignalStrength signalChannelOne;
    AUTELDSPSignalStrength signalChannelTwo;
    AUTELDSPSignalStrength signalChannelThree;
    AUTELDSPSignalStrength signalChannelFour;
} AUTELDSPSignalStrengths;

/**
*  通过该类，你可以获得图传信道的实时状态，也可以向图传信道发送命令，控制图传信道。
*
*  通过该类，你可以获得图传信道的实时状态，也可以向图传信道发送命令，控制图传信道。
*/
@interface AUTELDSPSignalChannel : NSObject

/**
 *  @brief Start monitoring the channel
 *
 *  开始监听图传信道
 */
- (void)startMonitor;

/**
 *  @brief Stop monitoring the channel
 *
 *  停止监听图传信道
 */
- (void)stopMonitor;

/**
 *  @brief Get the signal strength of all channels
 *
 *  获取所有信道的信号强度
 *
 *  @param result 获取成功与否
 */
- (void)getAllSignalStrengthWithResult:(void (^)(AUTELDSPSignalStrengths signalStrengths, AUTELError *_Nullable error))result;

/**
 *  @brief Get current signal strength
 *
 *  获取所有信道的信号强度
 *
 *  @param result 获取成功与否和当前频率的信道信息
 */
- (void)getCurrentSignalStrengthWithResult:(void (^)(AUTELDSPSignalStrength signalStrength, AUTELError *_Nullable error))result;

/**
 *  @brief set current signal strength
 *
 *  设置当前信道的频率
 *
 *  @param set_frequency 信道频率
 *  @param result        设置成功与否
 */
- (void)setCurrentSignalStrength:(NSUInteger)set_frequency withResult:(AUTELExecuteResultBlock)result;

@end

NS_ASSUME_NONNULL_END
