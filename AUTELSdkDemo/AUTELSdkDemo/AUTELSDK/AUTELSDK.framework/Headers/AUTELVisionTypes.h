//
//  AUTELVisionTypes.h
//  AUTELSDK
//
//  Created by IOS on 2017/7/17.
//  Copyright © 2017年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Position of the sensor on the aircraft.
 */
typedef NS_ENUM(NSUInteger, AUTELVisionSensorPosition) {
    
    /**
     *  The sensor is on the front or nose of the aircraft.
     */
    AUTELVisionSensorPositionNose,
    
    /**
     *  The sensor is on the back or tail of the aircraft.
     */
    AUTELVisionSensorPositionTail,
    
    /**
     *  The sensor is on the left or port side of the aircraft.
     */
    AUTELVisionSensorPositionLeft,
    
    /**
     *  The sensor is on the right or starboard side of the aircraft.
     */
    AUTELVisionSensorPositionRight,
    
    /**
     *  The sensor is on the top  side of the aircraft.
     */
    AUTELVisionSensorPositionTop,
    
    /**
     *  The sensor is on the bottom side of the aircraft.
     */
    AUTELVisionSensorPositionBottom,
    
    /**
     *  Unknown.
     */
    AUTELVisionSensorPositionUnknown = -1,
};

/**
 *  Distance warning returned by each sector of the front vision system. Warning
 *  Level 4 is the most serious level.
 */
typedef NS_ENUM (NSInteger, AUTELObstacleDetectionSectorWarning){
    
    
    /**
     *  The warning level is invalid. The sector cannot determine depth of the scene in
     *  front of it.
     */
    AUTELObstacleDetectionSectorWarningInvalid,
    
    
    /**
     *  The distance between the obstacle detected by the sector and the aircraft is
     *  over 4 meters.
     */
    AUTELObstacleDetectionSectorWarningLevel1,
    
    
    /**
     *  The distance between the obstacle detected by the sector and the aircraft is
     *  between 3 - 4 meters.
     */
    AUTELObstacleDetectionSectorWarningLevel2,
    
    
    /**
     *  The distance between the obstacle detected by the sector and the aircraft is
     *  between 2 - 3 meters.
     */
    AUTELObstacleDetectionSectorWarningLevel3,
    
    
    /**
     *  The distance between the obstacle detected by the sector and the aircraft is
     *  less than 2 meters.
     */
    AUTELObstacleDetectionSectorWarningLevel4,
    
    
    /**
     *  The distance warning is unknown. This warning is returned when an exception
     *  occurs.
     */
    AUTELObstacleDetectionSectorWarningUnknown = 0xFF
};

/**
 *  Distance warning returned by the front vision system. Warning Level 4 is the
 *  most serious level.
 */
typedef NS_ENUM (NSInteger, AUTELVisionSystemWarning){
    
    
    /**
     *  The warning is invalid. The front vision system cannot determine depth of the
     *  scene in front of it.
     */
    AUTELVisionSystemWarningInvalid,
    
    
    /**
     *  The distance between the obstacle detected by the vision system and the aircraft
     *  is safe (over 2 meters).
     */
    AUTELVisionSystemWarningSafe,
    
    
    /**
     *  The distance between the obstacle detected by the vision system and the aircraft
     *  is dangerous (less than 2 meters).
     */
    AUTELVisionSystemWarningDangerous,
    
    
    /**
     *  The distance warning is unknown. This warning is returned when an exception
     *  occurs.
     */
    AUTELVisionSystemWarningUnknown = 0xFF
};

/**
 *  The vision system can see in front of the aircraft with a 60 degree horizontal
 *  field of view (FOV) and 55 degree  vertical FOV. The horizontal FOV is split
 *  into four equal sectors, and this class gives the distance and warning  level
 *  for one sector.
 */
@interface AUTELObstacleDetectionSector : NSObject<NSCopying>


/**
 *  The detected obstacle distance to the aircraft in meters.
 */
@property(nonatomic, assign) double obstacleDistanceInMeters;


/**
 *  The warning level based on distance.
 */
@property(nonatomic, assign) AUTELObstacleDetectionSectorWarning warningLevel;

@end



@interface AUTELVisionDetectionState : NSObject<NSCopying>

/**
*  timeStamp.
*/
@property(nonatomic, assign) double timeStamp;

/**
*  vision sensor position.
*/
@property(nonatomic, assign) AUTELVisionSensorPosition position;

/**
 *  `YES` if the vision sensor is working.
 */
@property(nonatomic, assign) BOOL isSensorBeingUsed;

/**
 *  Distance warning level between the obstacle and the aircraft. This is a
 *  combination of warning levels from each sector.
 */
@property(nonatomic, assign) AUTELVisionSystemWarning systemWarning;

/**
 *  The distance to the closest detected obstacle, in meters. It is only used when
 *  the sensor is an infrared TOF  sensor. The valid range is [0.3, 5.0]. Phantom 4
 *  Pro has two infrared sensors on its left and right. Both sensors have a
 *  70-degree horizontal field of view (FOV) and 20-degree vertical FOV. The value
 *  is always 0.0 if the sensor is a dual-camera sensor or the sensor is not working
 *  properly.
 */
@property(nonatomic, assign) double obstacleDistanceInMeters;

/**
 *  The vision system can see in front of the aircraft with a 70 degree horizontal
 *  field of view (FOV) and 55-degree  vertical FOV for the Phantom 4. The
 *  horizontal FOV is split into four equal sectors and this array contains the
 *  distance and warning information for each sector. For Phantom 4, the horizontal
 *  FOV is separated into 4 sectors.
 */
@property(nullable, nonatomic) NSArray<AUTELObstacleDetectionSector *> *detectionSectors;

@end
