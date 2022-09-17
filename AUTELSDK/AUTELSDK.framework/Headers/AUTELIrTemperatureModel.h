//
//  AUTELIrTempAttrModel.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/5/20.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>



/**
*  Temperature measurement mode
*
*   测温模式
*/
typedef NS_ENUM(int, AUTELCameraTempMode) {
    /**
    *  @brief  None
    *
    *  无
    */
    AUTELCameraTempModeNone = 0,
    /**
    *  @brief  Center temperature measurement
    *
    *  中心测温
    */
    AUTELCameraTempModeCenter = 1,
    /**
    *  @brief  Hot temperature measurement
    *
    *  热测温
    */
    AUTELCameraTempModeHot = 2,
    /**
    *  @brief Cold temperature measurement
    *
    *  冷测温
    */
    AUTELCameraTempModeCold = 3,
    /**
    *  @brief  Touch temperature measurement
    *
    *  点击位置测温
    */
    /// Touch temperature measurement
    AUTELCameraTempModeTouch = 4,
    /**
    *  @brief  Region temperature measurement
    *
    *  区域测温
    */
    AUTELCameraTempModeRegion = 5,
    /**
    *  @brief  Track temperature measurement
    *
    *  跟踪测温
    */
    AUTELCameraTempModeTrack = 6,
    /**
    *  @brief  User1 temperature measurement
    *
    *  用户1测温
    */
    AUTELCameraTempModeUser1 = 7,
    /**
    *  @brief User2 temperature measurement
    *
    *  用户2测温
    */
    AUTELCameraTempModeUser2 = 8
    
};
    
/**
*  Temperature alarm type
*
*   告警报警类型，分高温报警和低温报警.
*/
typedef NS_ENUM(uint8_t, AUTELCameraTempAlarmEvenType) {
    /// High temperature alarm
    AUTELCameraTempAlarmEvenTypeHot = 0,
    /// Low temperature alarm
    AUTELCameraTempAlarmEvenTypeCold = 1,
    
};
NS_ASSUME_NONNULL_BEGIN


/// Thermal imaging temperature attribute model
@interface AUTELIrTempAttrModel : NSObject

/**
*  @brief Temperature measurement mode.
*
*  测温模式
*/
@property (nonatomic, assign) AUTELCameraTempMode tempMode;

/**
*  @brief Point temperature measurement x coordinate
*
*  指点测温x坐标，以yuv图像宽比例计算
*/
@property (nonatomic, assign) float touchX;

/**
*  @brief Point temperature measurement y coordinate.
*
*  指点测温y坐标，以yuv图像高比例计算
*/
@property (nonatomic, assign) float touchY;

/**
*  @brief The x coordinate of regional temperature measurement, calculated based on the yuv image width ratio.
*
*  区域测温x坐标，以yuv图像宽比例计算
*/
@property (nonatomic, assign) float regionX;

/**
*  @brief The y-coordinate of regional temperature measurement, calculated by the high proportion of yuv image.
*
*  区域测温y坐标，以yuv图像高比例计算
*/
@property (nonatomic, assign) float regionY;

/**
*  @brief Width of regional temperature measurement, calculated based on yuv image width ratio.
*
*  区域测温宽，以yuv图像宽比例计算
*/
@property (nonatomic, assign) float regionW;

/**
*  @brief Area temperature measurement is high, calculated based on the high proportion of yuv image.
*
*  区域测温高，以yuv图像高比例计算
*/
@property (nonatomic, assign) float regionH;

/**
*  @brief Limit the x coordinate of the small temperature measurement screen, calculated based on the maximum image width ratio of yuv.
*
*  限制测温小画面x坐标，以yuv最大图像宽比例计算，Float型
*/
@property (nonatomic, assign) float limitTempX;

/**
*  @brief Limit the y-coordinate of the small temperature measurement screen, calculated based on the maximum image height ratio of yuv.
*
*  限制测温小画面y坐标，以yuv最大图像高比例计算，Float型
*/
@property (nonatomic, assign) float limitTempY;

/**
*  @brief Limit the width of the small picture for temperature measurement, calculated based on the yuv maximum image width ratio.
*
*  限制测温小画面宽，以yuv最大图像宽比例计算，Float型
*/
@property (nonatomic, assign) float limitTempW;

/**
*  @brief Limit the height of small images for temperature measurement, and calculate with the maximum image height ratio of yuv.
*
*  限制测温小画面高，以yuv最大图像高比例计算，Float型
*/
@property (nonatomic, assign) float limitTempH;



- (instancetype)initWithParam:(NSDictionary *)param;

- (NSString *)getTempModeString;

- (void)reset;

@end



/// Thermal imaging temperature alarm attribute model
@interface AUTELIrTempAlarmModel : NSObject

/**
*  @brief Alarm enable.
*
*  报警使能
*/
@property (nonatomic, assign) int enable;

/**
*  @brief Alarm when temperature threshold is exceeded, unit: Celsius * 10
*
*  超过温度阈值就告警，单位摄氏度*10
*/
@property (nonatomic, assign) int hotThred;

/**
*  @brief Alarm if the temperature is below the threshold, the unit is Celsius * 10.
*
*  低于温度阈值就告警，单位摄氏度*10
*/
@property (nonatomic, assign) int coldThred;

- (instancetype)initWithParam:(NSDictionary *)param;

- (void)reset;

@end




/// Report a temperature alarm event
@interface AUTELIrTempAlarmEven : NSObject

/**
*  @brief Temperature alarm type.
*
*  告警报警类型，分高温报警和低温报警.
* @see AUTELDroneMainController
*/
@property (nonatomic, readonly, assign) AUTELCameraTempAlarmEvenType evenType;

/**
*  @brief High temperature alarm point temperature, unit Celsius * 10.
*
*  高温告警点温度,单位摄氏度*10.
*/
@property (nonatomic, readonly, assign) float hotTemp;

/**
*  @brief High temperature alarm X coordinate
*
*  高温报警X坐标，以图像宽比例
*/
@property (nonatomic, readonly, assign) float hotX;

/**
*  @brief High temperature alarm X coordinate
*
*   高温报警Y坐标，以图像宽比例
*/
@property (nonatomic, readonly, assign) float hotY;

/**
*  @brief Low temperature alarm point temperature, unit Celsius * 10.
*
*  低温告警点温度,单位摄氏度*10.
*/
@property (nonatomic, readonly, assign) float coldTemp;

/**
*  @brief Low temperature alarm X coordinate, with the image width ratio
*
*  低温报警X坐标，以图像宽比例
*/
@property (nonatomic, readonly, assign) float coldX;

/**
*  @brief Low temperature alarm Y coordinate, with the image width ratio
*
*  低温报警Y坐标，以图像宽比例
*/
@property (nonatomic, readonly, assign) float coldY;



- (instancetype)initWithParam:(NSDictionary *)param;

@end

NS_ASSUME_NONNULL_END
