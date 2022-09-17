//
//  AUTELMCWaypointMission.h
//  AUTELSDK
//
//  Created by zhiganglet on 2019/7/25.
//  Copyright © 2019 Autel. All rights reserved.
//

#import "AUTELGen2WaypointMission.h"
#import <AUTELSDK/AUTELCameraDef.h>

//-----------------------------------------------------------------
/**
 *
 * 定义拍照图片分辨率
 */
typedef NS_ENUM (uint8_t, AUTELDronePhotoAspectRatio) {
    /**
   * @brief 分辨率为未定义 Resolution is undefined
   *
   */
  AUTELDronePhotoAspectRatioUnknown = 0,
    /**
   * @brief 相机图片比例为16:9，分辨率为3840x2160 The camera picture ratio is 16:9 and the resolution is 3840x2160
   *
   */
  AUTELDronePhotoAspectRatio3840_2160 = 1,

  /**
   * @brief 相机图片比例为16:9，分辨率为1280x720 The camera image ratio is 16:9 and the resolution is 1280x720
   *
   */
  AUTELDronePhotoAspectRatio1280_720 = 2,

  /**
   * @brief 相机图片比例为16:9，分辨率为1920x1080 The camera picture ratio is 16:9 and the resolution is 1920x1080
   *
   */
  AUTELDronePhotoAspectRatio1920_1080 = 3,

  /**
   * @brief 相机图片比例为4:3，分辨率为4000x3000 The camera image ratio is 4:3 and the resolution is 4000x3000
   *
   */
  AUTELDronePhotoAspectRatio4000_3000 = 4,

  /**
   * @brief 相机图片比例为16:9，分辨率为5472x3076 The camera image ratio is 16:9 and the resolution is 5472x3076
   *
   */
  AUTELDronePhotoAspectRatio5472_3076 = 5,

  /**
   * @brief 相机图片比例为4:3，分辨率为5472x3648 The camera image ratio is 4:3 and the resolution is 5472x3648
   *
   */
  AUTELDronePhotoAspectRatio5472_3648 = 6,

  /**
   * @brief 相机图片比例为16:9，分辨率为7680x4320 The camera image ratio is 16:9 and the resolution is 7680x4320
   *
   */
  AUTELDronePhotoAspectRatio7680_4320 = 7, 

  /**
   * @brief 相机图片比例为4:3，分辨率为8000x6000  The camera image ratio is 4:3 and the resolution is 8000x6000
   *
   */
  AUTELDronePhotoAspectRatio8000_6000 = 8,

  /**
   * @brief 相机图片比例为4:3，分辨率为640x512 The camera image ratio is 4:3 and the resolution is 640x512
   *
   */
  AUTELDronePhotoAspectRatio640_512 = 9,

};


//-----------------------------------------------------------------
/**
 *
 * 设置相机图片格式
 * Set camera image format
 *
 */
typedef NS_ENUM (uint8_t, AUTELDronePhotoFileFormat) {
  /**
   * @brief 分辨率为未定义
   * Resolution is undefined
   *
   */
  AUTELDronePhotoFileFormatUnknown = 0,
    
  /**
   * @brief 相机图片格式为 JPG
   * Camera image format is JPG
   */
  AUTELDronePhotoFileFormatJPG = 1,
 
  /**
   * @brief 相机图片格式为 DNG
   * Camera image format is DNG
   */
  AUTELDronePhotoFileFormatDNG = 2,

  /**
   * @brief 相机图片格式为 JPG和DNG
   * Camera image formats are JPG and DNG
   */
  AUTELDronePhotoFileFormatJPGAndDNG = 3,
   
  /**
   * @brief 相机图片格式为 RJPEG
   * Camera image format is RJPEG
   */
  AUTELDronePhotoFileFormatRJPEG = 4,

  /**
   * @brief 相机图片格式为 RJPEG+TIFF
   * Camera image format is RJPEG+TIFF
   */
  AUTELDronePhotoFileFormatRJPEGAndTIFF = 5,

};


@class AUTELWaypointMC;
@class InterestPointModel;
@class AUTELCoordinate3D;

/**
*  @brief Waypoint mission,Inherit the AUTELGen2WaypointMission class
*
*  航点飞行任务
*/
@interface AUTELMCWaypointMission : AUTELGen2WaypointMission

/**
*  @brief missionId.
*
* 任务上报ID，APP用于上传下载识别
*/
@property (nonatomic, assign) int missionId;

/**
*  @brief missionType.
*  任务类型
*  @see AUTELMissionType
*/
@property (nonatomic, assign) AUTELMissionType missionType;

/**
*  @brief Collection of points of interest.
*
*  兴趣点集合
*  @see InterestPointModel
*/
@property (nonatomic, copy)  NSArray<InterestPointModel *>* _Nullable  poiList;

/**
*  @brief Total flight time.
*
*  航线飞行总时间
*/
@property (nonatomic, assign) int totalTimes;

/**
*  @brief Total flight distance.
*
*  航线总飞行距离
*/
@property (nonatomic, assign) int totalDistance;

/**
*  @brief Index of waypoints in progress
*
*  正在执行的航点索引
*/
@property (nonatomic, assign) int executeIndex;

/**
*  @brief Number of photos taken by the mission.
*
*  任务已拍照的张数
*/
@property (nonatomic, assign) int executePhotos;

/**
*  @brief number of vertex coordinates.
*
*  顶点坐标个数
*/
@property (nonatomic, assign) int numberVertexPoints;

/**
*  @brief Double grid flag,0:disable,1:enagle
*
*  双网格标记
*/
@property (nonatomic, assign) int gridEnable;

/**
*  @brief Elevation optimization  flag,0:disable,1:enagle
*
*  高程优化标记
*/
@property (nonatomic, assign) int elevationOpt;

/**
*  @brief Automatic switch of main course angle
*
*  主航线角度自动开关
*/
@property (nonatomic, assign) int autoAngle;

/**
*  @brief Waypoint height type
*
*  航点高度类型：0是相对高度，1是海拔高度
*/
@property (nonatomic, assign) int altitudeType;

/**
*  @brief record mission flag
*
*  任务录制标记,0是非录制任务，1是录制的任务
*/
@property (nonatomic, assign) int recordMission;

/**
*  @brief camera PhotoAspectRatio
*
*  相机拍照分辨率
*/
@property (nonatomic, assign) AUTELCameraPhotoAspectRatio cameraPhotoAspectRatio;

/**
*  @brief camera PhotoFileFormat
*
*  相机拍照照片格式
*/
@property (nonatomic, assign) AUTELCameraPhotoFileFormat cameraPhotoFileFormat;

/**
*  @brief mission unique identification ID.
*
*  任务唯一识别ID
*/
@property (nonatomic, copy)  NSString * _Nullable guid;

/**
*  @brief mission name.
*
*  任务名称
*/
@property (nonatomic, copy)  NSString * _Nullable missionName;

/**
*  @brief Aircraft takeoff coordinates.
*
*  飞机起飞坐标
*/
@property (nonatomic, strong) AUTELCoordinate3D * _Nonnull droneLocal;

/**
*  @brief Vertex Coordinate Collection.
*
*  顶点坐标
*/
@property (nonatomic, copy)  NSArray<InterestPointModel *>* _Nullable  vertexList;

/**
*  @brief lost connection action
*
*  失联动作
*/
@property (nonatomic, assign) AUTELMissionSignalLostHandleType lostConnectAction;

/**
*  @brief lost connection action
*
*  拍摄模式
*/
@property (nonatomic, assign) AUTELMissionShootingType shootingType;

/**
*  @brief image format
*
*  图片格式
*/
@property (nonatomic, assign) AUTELMissionImageFormat imageFormat;

/**
*  @brief Add a  waypoint to the waypoint mission.
*
*  添加一个航点到航点飞行任务。
*
*  @param waypoint The waypoint to be added to waypoint mission.
*
*  添加到航点飞行任务的航点。
*/
- (void)addGen2Waypoint:(AUTELWaypointMC *_Nonnull)waypoint;

/**
 *  @brief Adds an array of waypoints to the waypoint mission.
 *
 *  添加一组航点到航点飞行任务。
 *
 *  @param waypoints The array of waypoints to be added to waypoint mission.
 *
 *  添加到航点飞行任务的航点数组。
 */
- (void)addGen2Waypoints:(NSArray<AUTELWaypointMC *>*_Nonnull)waypoints;

/**
 *  @brief  Gets a waypoint at the index of the waypoint array from waypoint mission.
 *
 *  获取第index个添加到飞行任务中的航点。
 *
 *  @param index Index of the waypoint wanting to be retrieved from the array of waypoints in the
 *  waypoint mission.
 *
 *  需要获取的航点的下标。
 *
 *  @return Waypoint of type AUTELWaypoint if the index exists.
 *
 *  获取到的航点
 */
- (AUTELWaypointMC*_Nullable)getGen2WaypointAtIndex:(int)index;
@end
