//
//  AUTELWayPointPathModel.h
//  AutelGen2
//
//  Created by zhiganglet on 2022/8/1.
//  Copyright © 2022 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELPathMissionDef.h"
#import "AUTELPathCoordinate3D.h"

NS_ASSUME_NONNULL_BEGIN


@interface AUTELPathPlanningAction : NSObject

@property (nonatomic) float droneYaw;
@property (nonatomic) float gimbalPitch;
@property (nonatomic) float gimbalRoll;
@property (nonatomic) float gimbalYaw;
@property (nonatomic) int cameraActionType;
@property (nonatomic) float cameraInterval;
@property (nonatomic) float cameraZoom;
@property (nonatomic) int actionTimeLen;

@end



/// 一个航点或顶点的模型定义
@interface AUTELWayPointPathModel : NSObject

//变量 0：当前航点所属任务标识( 4字节无符号) 其中：1-航点任务; 6-测绘任务。
@property (nonatomic)  AUTELPathPointMissionType missionType;
//变量 1：当前航点标识（目前等于航点在当前任务中的序号）
@property (nonatomic) double missionID;
//变量 2：当前航点类型，其中：2–飞越/协调转弯;1–悬停
@property (nonatomic, assign) AUTELPathPlanningWayPointType waypointType;
//变量 3：航点坐标，纬度
@property (nonatomic) double latitude;
//变量 4：航点坐标，经度
@property (nonatomic) double longitude;
//变量 5：航点坐标，高度
@property (nonatomic) double altitude;
//变量 6：航点飞行速度，单位米/秒
@property (nonatomic) double speed;
//变量 12：相机动作类型: 0-无，1-拍照，2-定时拍照，3-定距拍照，4-录像，5-停止录像
@property (nonatomic) uint8_t cameraAction;
// 此航点中 动作朝向模式,1表示沿航线，2表示手动，3表示自定义
@property (nonatomic) uint8_t Heading_Mode;
@property (nonatomic) float radius;
@property (nonatomic) int altitudePriority;
@property (nonatomic, strong) NSArray <AUTELPathPlanningAction*> * missionActions;
@property (nonatomic, strong) AUTELPathCoordinate3D * interestingPoint;

@end

NS_ASSUME_NONNULL_END
