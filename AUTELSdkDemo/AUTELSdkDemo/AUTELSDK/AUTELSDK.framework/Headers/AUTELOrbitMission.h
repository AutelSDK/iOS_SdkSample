//
//  AUTELOrbitMission.h
//  AUTELSDK
//
//  Created by Devin on 2018/1/18.
//  Copyright © 2018年 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELSDK.h>

typedef float AUTELRadian;

typedef NS_ENUM(uint8_t, AUTELOrbitEntryPointType) {
    /**
     *  @brief Enter orbit mission at the nearest point
     *
     *  由最近点进入
     */
    AUTELOrbitEntryPointTypeNearest,
    
    /**
     *  @brief Enter orbit mission at the northest
     *
     *  由最北点进入
     */
    AUTELOrbitEntryPointTypeNorth,
    
    /**
     *  @brief Enter orbit mission at the southest
     *
     *  由最南点进入
     */
    AUTELOrbitEntryPointTypeSouth,
    
    /**
     *  @brief Enter orbit mission at the far east point
     *
     *  由最东点进入
     */
    AUTELOrbitEntryPointTypeEast,
    
    /**
     *  @brief Enter orbit mission at the far west point
     *
     *  由最西点进入
     */
    AUTELOrbitEntryPointTypeWest,
};

typedef NS_ENUM(uint8_t, AUTELOrbitHeading) {
    /**
     *  @brief Heading is invalid
     *
     *  无效朝向
     */
    AUTELOrbitHeadingInvalid = 0,
    
    /**
     *  @brief Heading is face forward
     *
     *  机头朝前
     */
    AUTELOrbitHeadingFaceForward,
    
    /**
     *  @brief Heading is towards to center
     *
     *  机头朝中
     */
    AUTELOrbitHeadingTowardsCenter,
    
    /**
     *  @brief Heading is outside faced
     *
     *  机头朝外
     */
    AUTELOrbitHeadingAwayFromCenter,
    
    /**
     *  @brief Heading is backward
     *
     *  机头朝后
     */
    AUTELOrbitHeadingFaceBackward,
    
    /**
     *  @brief Heading is controlled by user
     *
     *  用户自己操作控制
     */
    AUTELOrbitHeadingUserControlled,
};

@interface AUTELOrbitMissionStatus: AUTELHotPointMissionStatus

/**
 *  @brief The identifier of mission which it belongs to.
 *
 *  任务id
 */
@property (nonatomic, readonly) uint32_t missionId;

/**
 *  @brief Identifier
 *
 *  航点id
 */
@property (nonatomic, readonly) uint32_t waypointId;


@property (nonatomic, readonly) AUTELOrbitEntryPointType entryType;
@property (nonatomic, readonly) AUTELOrbitHeading heading;

/**
 *  @brief The remaining degrees of the whole circle when the aircraft is executing the Orbit mission(the fractional part of the circle).
 *
 *  进行环绕飞行时的圈数剩余弧度（圈数的小数部分）
 */
@property (nonatomic, readonly) AUTELRadian rotateRadian;

/**
 *  @brief The orbit altitude is indicated that at which altitude the orbit mission is executed.
 *
 *  进行环绕飞行时的圈数剩余弧度（圈数的小数部分）
 */
@property (nonatomic, readonly) float orbitAltitude;

@end

@interface AUTELOrbitMission : AUTELHotPointMission

/**
 *  @brief The identifier of mission which it belongs to.
 *
 *  任务id
 */
@property (nonatomic) uint32_t missionId;

/**
 *  @brief Identifier
 *
 *  航点id
 */
@property (nonatomic) uint32_t waypointId;
@property (nonatomic) AUTELOrbitEntryPointType entryType;
@property (nonatomic) AUTELOrbitHeading heading;

/**
 *  @brief The remaining degrees of the whole circle when the aircraft is executing the Orbit mission(the fractional part of the circle).
 *
 *  进行环绕飞行时的圈数剩余弧度（圈数的小数部分）
 */
@property (nonatomic) AUTELRadian rotateRadian;

/**
 *  中心点的相对高度, 相对于起飞点, 单位:米
 */
@property (nonatomic) float orbitAltitude;

@end
