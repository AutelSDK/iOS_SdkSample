//
//  AUTELMisstionRecordModel.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/8/17.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUTELMisstionRecordModel : NSObject

/**
 *  @brief Coordinate of the waypoint in degrees.
 *
 *  航点坐标
 */
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 *  @brief This property describes the altitude of aircraft is the relative altitude of the take off point when it reaches the waypoint. The value of altitude in meters. The valid range for the altitude is from 0m to 800m.
 *
 *  The altitude value must be smaller than maximum flight altitude. We can invoke [AUTELFlightLimitation getMaxFlightHeightWithCompletion:] and [AUTELFlightLimitation setMaxFlightHeight:withCompletion:] to read and write flight altitude limitation.
 *
 *  航点高度，该高度是相对于飞行器起飞点的高度，该高度范围为[0, 800]，且不能高度飞行器的最大高度限制。通过 AUTELFlightLimitation 的 -getMaxFlightHeightWithCompletion: 方法和 -setMaxFlightHeight:withCompletion: 方法可以查询和修改飞行器最大飞行高度限制。
 *
 *  @see AUTELFlightLimitation
 */
@property(nonatomic, assign) double height;

/**
 *  @brief Altitude
 *
 *  海拔高度
 */
@property (nonatomic) double altitude;

/**
 *  @brief head angle
 *
 *  主航向角度
 */
@property (nonatomic) float headAngle;

/**
 *  @brief camera pitch
 *
 *  相机pitch角度。
 */
@property (nonatomic) float cameraPitch;
/**
 *  @brief camera yaw
 *
 *  相机yaw角度。
 */
@property (nonatomic) float cameraYaw;

/**
 *  @brief camera roll
 *
 *  roll角
 */
@property (nonatomic) float cameraRoll;

/**
 *  @brief camera zoom
 *
 *  相机变焦
 */
@property (nonatomic) float cameraZoom;

/**
 *  @brief file path
 *
 *  图片文件地址
 */
@property (nonatomic, copy) NSString *filePath;


- (instancetype)initWithParam:(NSDictionary *)param;

@end

NS_ASSUME_NONNULL_END
