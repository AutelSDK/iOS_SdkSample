//
//  AUTELRTKModel.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/8/26.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class AUTELRTKAuthInfoModel;

typedef void (^_Nullable AUTELGetRTKAuthInfoCompletionBlock)(AUTELRTKAuthInfoModel * _Nullable model, NSError *_Nullable error);

/**
 *  Define RTK positioning method
 *
 *  定义RTK定位方式
 */
typedef NS_ENUM(uint8_t, AUTELRTKlocationType) {
    /**
     *  @brief GNSS
     */
    AUTELRTKlocationTypeGNSS = 0,
    /**
     *  @brief RTK
     */
    AUTELRTKlocationTypeRTK  = 1,

};

/**
 *  Define RTK positioning method
 *
 *  定义RTK定位方式
 */
typedef NS_ENUM(uint8_t, AUTELRTKRecvDiffType) {
    /**
     *  @brief 无
    */
    AUTELRTKRecvDiffTypeNone = 0,
    /**
     *  @brief RTK移动站
     */
    AUTELRTKRecvDiffTypeStation  = 1,
    /**
     *  @brief 网络RTK
     */
    AUTELRTKRecvDiffTypeNetwork  = 2,
    /**
     *  @brief 自定义网络RTK
     */
    AUTELRTKRecvDiffTypeCustomize  = 3,

};

/**
 *  Define RTK positioning method
 *
 *  定义RTK解状态
 */
typedef NS_ENUM(uint8_t, AUTELRTKParseStatus) {
    /**
     *  @brief 已解出
    */
    AUTELRTKParseStatusCOMPUTED = 0,
    /**
     *  @brief 观测数据不足
     */
    AUTELRTKParseStatusINSUFFICIENT_OBS  = 1,
    /**
     *  @brief 无法收敛
     */
    AUTELRTKParseStatusNO_CONVERGENCE  = 2,
    /**
     *  @brief 协方差矩阵的迹超过最大值
     */
    AUTELRTKParseStatusCOV_TRACE  = 4,

};

/**
 *  Define RTK positioning method
 *
 *  定义RTK解状态
 */
typedef NS_ENUM(uint8_t, AUTELRTKPositionType) {
    /**
     *  @brief 无解
    */
    AUTELRTKPositionType0 = 0,
    /**
     *  @brief 位置由FIX POSITION命令指定
     */
    AUTELRTKPositionType1  = 1,
    /**
     *  @brief 暂不支持
     */
    AUTELRTKPositionType2  = 2,
    /**
     *  @brief 速度由即时多普勒信息导出
     */
    AUTELRTKPositionType8  = 8,
    /**
     *  @brief 单点定位
     */
    AUTELRTKPositionType16  = 16,
    /**
     *  @brief 伪距差分解
     */
    AUTELRTKPositionType17  = 17,
    /**
     *  @brief SBAS定位
     */
    AUTELRTKPositionType18  = 18,
    /**
     *  @brief  L1浮点解
     */
    AUTELRTKPositionType32  = 32,
    /**
     *  @brief 消电离层浮点解
     */
    AUTELRTKPositionType33  = 33,
    /**
     *  @brief 消电离层浮点解
     */
    AUTELRTKPositionType34  = 34,
    /**
     *  @brief L1固定解
     */
    AUTELRTKPositionType48  = 48,
    /**
     *  @brief 宽巷固定解
     */
    AUTELRTKPositionType49  = 49,
    /**
     *  @brief 窄巷固定解
     */
    AUTELRTKPositionType50  = 50,
    /**
     *  @brief 纯惯导定位解
     */
    AUTELRTKPositionType52  = 52,
    /**
     *  @brief 惯导与单点定位组合解
     */
    AUTELRTKPositionType53  = 53,
    /**
     *  @brief 惯导与伪距差分定位组合解
     */
    AUTELRTKPositionType54  = 54,
    /**
     *  @brief 惯导与载波相位差分浮点解组合解
     */
    AUTELRTKPositionType55  = 55,
    /**
     *  @brief 惯导与载波相位差分固定解组合解
     */
    AUTELRTKPositionType56  = 56,

};

/**
 *  Define RTK coordinate system
 *
 *  定义RTK坐标系
 */
typedef NS_ENUM(uint8_t, AUTELRTKCoordinateSys) {
    /**
     *  @brief WGS84
     */
    AUTELRTKCoordinateSysWGS84 = 0,
    /**
     *  @brief CGCS2000
     */
    AUTELRTKCoordinateSysCGCS2000  = 1,
    /**
     *  @brief Unknow
     */
    AUTELRTKCoordinateSysUnknow  = 0xff,

};

/**
 *  Define RTK fix status
 *
 *  定义RTK fix 状态
 */
typedef NS_ENUM(uint8_t, AUTELRTKFixStatus) {
    /**
     *  @brief NONE
     */
    AUTELRTKFixStatusNone = 0,
    /**
     *  @brief SINGLE
     */
    AUTELRTKFixStatusSingle = 1,
    /**
     *  @brief FLOAT
     */
    AUTELRTKFixStatusFloat  = 2,
    /**
     *  @brief FIX
     */
    AUTELRTKFixStatusFix  = 3,
    /**
     *  @brief Unknow
     */
    AUTELRTKFixStatusUnkonw  = 0xff,

};



NS_ASSUME_NONNULL_BEGIN

/**
 *  RTK working parameters.
 *
 *  RTK 工作参数
 */
@interface AUTELRTKAuthInfoModel : NSObject

///账户
@property (nonatomic, copy) NSString * serviceKey;

///密码
@property (nonatomic, copy) NSString * serviceSecret;

///设备ID
@property (nonatomic, copy) NSString * deviceID;

///设备类型
@property (nonatomic, copy) NSString * deviceType;


- (instancetype)initWithParam:(NSDictionary *)param;

@end

/**
 *  RTK working parameters.
 *
 *  RTK 工作参数
 */
@interface AUTELRTKWokeParamsModel : NSObject

///是否使用RTK定位，0 -- 不使用， 1 -- 使用
@property (nonatomic, assign) BOOL isUsedRTK;

///定位方式
@property (nonatomic, assign) AUTELRTKlocationType locationType;

///接收RTK信号方式
@property (nonatomic, assign) AUTELRTKRecvDiffType recvDiffType;

@end


/**
 *  RTK working parameters.
 *
 *  RTK 工作参数
 */
@interface AUTELRTKStatusInfoModel : AUTELRTKWokeParamsModel

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

/**
*  @brief Standard deviation of latitude
*
*  纬度标准差，m
*/
@property(nonatomic, assign) float latSigma;

/**
*  @brief Standard deviation of longitude
*
*  经度标准差，m
*/
@property(nonatomic, assign) float lonSigma;

/**
*  @brief Standard deviation of altitude
*
* 高度标准差，m
*/
@property(nonatomic, assign) float altitudeSigma;

/**
*  @brief Number of satellites tracked
*
* 跟踪的卫星数
*/
@property(nonatomic, assign) uint8_t satellitesTrackedNum;

/**
*  @brief Number of satellites used in the solution
*
* 在解中使用的卫星数
*/
@property(nonatomic, assign) uint8_t satellitesInUsedNum;

/**
*  @brief GPS satellite number
*
* GPS卫星数
*/
@property(nonatomic, assign) uint8_t gpsStarNum;

/**
*  @brief Number of Beidou satellites
*
* 北斗卫星数
*/
@property(nonatomic, assign) uint8_t beidouStarNum;

/**
*  @brief Number of glonass satellites
*
*  glonass卫星数
*/
@property(nonatomic, assign) uint8_t glonassStarNum;

/**
*  @brief Number of galileo satellites
*
* galileo卫星数
*/
@property(nonatomic, assign) uint8_t galileoStarNum;

/**
*  @brief Is RTK in place
*
* RTK是否在位，0 -- 不在位， 1 -- 在位
*/
@property(nonatomic, assign) BOOL inPos;

/**
*  @brief RTK Fix Status
*
* fix状态  see AUTELRTKFixStatus
*/
@property(nonatomic, assign) AUTELRTKFixStatus fixSta;

///RTK坐标系
@property (nonatomic, assign) AUTELRTKCoordinateSys coordinateSys;


- (instancetype)initWithParam:(NSDictionary *)param;

@end


NS_ASSUME_NONNULL_END
