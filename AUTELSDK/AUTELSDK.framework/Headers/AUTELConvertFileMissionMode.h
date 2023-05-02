//
//  AUTELConvertFileMissionMode.h
//  AutelGen2
//
//  Created by zhiganglet on 2022/8/1.
//  Copyright © 2022 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELPathMissionDef.h"
#import "AUTELPathCoordinate3D.h"
#import "AUTELPathMissionLine.h"
#import "AUTELWayPointPathModel.h"

NS_ASSUME_NONNULL_BEGIN


/// 生成飞控执行文件输入数据模型
@interface AUTELConvertFileMissionMode : NSObject

@property (nonatomic, copy)  NSArray< NSArray <AUTELPathMissionLine *> *>* _Nullable lines;

@property (nonatomic, assign) int missionId;
@property (nonatomic, assign) NSString * guid;
@property (nonatomic, assign) NSString * missionName;
@property (nonatomic, assign) AUTELPathMissionType missionType;
@property (nonatomic, assign) int totalTimes;
@property (nonatomic, assign) int totalDistance;
//@property (nonatomic, assign) int executeIndex;
//@property (nonatomic, assign) int executePhotos;
@property (nonatomic, assign) int numberVertexPoints;
@property (nonatomic, assign) int gridEnable;
@property (nonatomic, assign) int autoAngle;
@property (nonatomic, assign) int altitudeType;
@property (nonatomic, assign) int recordMission;
@property (nonatomic, assign) int finishMode; // 0:返航，1悬停，2降落，3返回第一个航点，4在最后一个航点暂停
@property (nonatomic, assign) int waypointCount;
@property (nonatomic, assign) AUTELPathPlanningLostActionType lostConnectAction;
@property (nonatomic, assign) int cameraPhotoAspectRatio; //相机分辨率
@property (nonatomic, assign) int cameraPhotoFileFormat; //相机照片格式
@property (nonatomic, assign) int obstacleMode; //避障模式

//测绘任务
@property (nonatomic, assign) float VFOV_Mapping; //相机视场角 degree
@property (nonatomic, assign) float Yaw_Ref_Mapping; //测绘航向角度 degree
@property (nonatomic, assign) float Overlap_Mapping; //航向重叠率
@property (nonatomic, assign) float Gimbal_Pitch_Mapping; //测绘云台角度 degree
@property (nonatomic) int elevationOpt;
@property (nonatomic) int heading2Route;

@property (nonatomic, strong) AUTELPathPlanningAction * defaultAction; //航点任务默认航线动作

@property (nonatomic, copy) NSArray<AUTELPathCoordinate3D *>* poiList; //兴趣点

@end


NS_ASSUME_NONNULL_END
