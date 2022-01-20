//
//  AUTELCameraSDCardState.h
//  AUTELSDK
//
//  Created by 虢蔚翔 on 16/8/8.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELCameraDef.h>

/**
 *  Get the current SD card state through AUTELCameraSDCardState.
 *
 *  相机SD卡状态对象，通过该类可以获取到SD卡当前状态。
 */
@interface AUTELCameraSDCardState : NSObject<NSCopying>

/**
 *  @brief Whether it is now initilizing or not? 
 *
 *  是否正在初始化
 */
@property (nonatomic, assign) BOOL isInitializing;

/**
 *  @brief Whether there is  SD card error or not?
 *
 *  是否存在SD卡错误
 */
@property (nonatomic, assign) BOOL hasError;

/**
 *  @brief Whether the SD card is only readable?
 *
 *  SD卡是否只读
 */
@property (nonatomic, assign) BOOL isReadOnly;

/**
 *  @brief Invalid format or not?
 *  
 *  是否是无效格式
 */
@property (nonatomic, assign) BOOL isInvalidFormat;

/**
 *  @brief Whether it is formatting or not?
 *
 *  是否正在格式化
 */
@property (nonatomic, assign) AUTELCameraSDCardFormattingState formattingState;

/**
 *  @brief Is the storage space of the SD card full?
 *  
 *  是否SD卡存储空间已满
 */
@property (nonatomic, assign) BOOL isFull;

/**
 *  @brief Is it a low-speed SD card?
 *
 *  SD卡是否是低速卡
 */
@property (nonatomic, assign) BOOL isVerified;

/**
*  @brief Whether the SD card is slow to write, need to stop recording
*
*  SD卡是否写入慢，需要停止录像
*/
@property (nonatomic) BOOL isLowSpeedStopRecord;

/**
 *  @brief Has the SD card been inserted?
 *
 *  SD卡是否已经插入，注意：MMC也是使用AUTELCameraSDCardState，但MMC的isInserted还是指SD卡的插入状态，MMC没有插入状态
 */
@property (nonatomic, assign) BOOL isInserted;

/**
 *  @brief The total storage capacity of the current SD card
 *
 *  当前SD卡的总存储容量
 */
@property (nonatomic, assign) NSInteger totalSpaceInMegaBytes;

/**
 *  @brief The residual capacity of the current SD card.
 *
 *  当前SD卡的剩余存储容量。
 */
@property (nonatomic, assign) NSInteger remainingSpaceInMegaBytes;

/**
 *  @brief The remaining number of photos can be taken and stored in SD card. 
 *
 *  SD卡的剩余可拍照张数
 */
@property (nonatomic, assign) NSInteger availableCaptureCount;

/**
 *  @brief The remaining time length in SD card to take videos.
 *
 *  SD卡的剩余可录像时间
 */
@property (nonatomic, assign) NSTimeInterval availableRecordingTimeInSeconds;

@end
