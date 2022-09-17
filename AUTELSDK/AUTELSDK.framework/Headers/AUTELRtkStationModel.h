//
//  AUTELRtkStationModel.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/11/9.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AUTELRTKModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface AUTELRtkStationBaseInfo : NSObject

@end

@interface AUTELRtkStationLocationStatus : NSObject

///解状态
@property (nonatomic, assign) AUTELRTKParseStatus parseStatus;

///位置类型
@property (nonatomic, assign) AUTELRTKPositionType positionType;

/**
 *  @brief Latitude
 *
 *  纬度坐标
 */
@property(nonatomic, assign) double latitude;

/**
 *  @brief longitude
 *
 *  经度坐标
 */
@property(nonatomic, assign) double longitude;

/**
*  @brief altitude
*
*  海拔高，m
*/
@property(nonatomic, assign) double altitude;



- (instancetype)initWithParam:(NSDictionary *)param;

@end

NS_ASSUME_NONNULL_END
