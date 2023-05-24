//
//  AUTELPathPlanningInputModel.h
//  AutelGen2
//
//  Created by zhiganglet on 2022/8/1.
//  Copyright © 2022 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELPathMissionDef.h"
#import "AUTELPathCoordinate3D.h"
#import "AUTELPathPlanningPara.h"

NS_ASSUME_NONNULL_BEGIN


///测绘任务的航线输入数据模型
@interface AUTELPathPlanningBaseInputPara : NSObject

/// 飞行速度：米 / 秒
@property (nonatomic) double speed;
/// 用户是否自定义了飞行航向    0  1
@property (nonatomic) int customHeading ;
/// 用户自定义的飞行航向角 5  10
@property (nonatomic) double userDefinedHeading;
/// 旁向扫描宽度单位米
@property (nonatomic) double widthSid;
/// 旁向扫描重叠率，10%-90%
@property (nonatomic) double widthOverlap;
/// 航向扫描长度单位米
@property (nonatomic) double headSid;
/// 航向扫描重叠率，0%-90%
@property (nonatomic) double headOverlap;
/// 区域内飞行高度(相对(起始点)高度，飞控应加上起始高度，得到绝对高度进行高度控制)
@property (nonatomic) double altitude;
/// 区域飞行的云台角度
@property (nonatomic) double gimbalAngle;
/// 边距是自动还是手动定义 （0是自动，1是手动）
@property (nonatomic) int enlargeSwitch;
/// 用户定义的边距距离
@property (nonatomic) double enlargeValue;
/// 是否设置带速过弯
@property (nonatomic) double rEnable;
/// 高程优化
@property (nonatomic) int elevationOpt;
/// 飞机机头朝向与航线的夹角，此角度值为0度，90度或-90度
@property (nonatomic) int heading2Route;
/// 任务相对高度
@property (nonatomic) double relativeHeight;
/// 左扩距离
@property (nonatomic) double widthLeft;
/// 右扩距离
@property (nonatomic) double widthRight;
/// 分段长度
@property (nonatomic) double cutInterval;
/// 航线模式 1 纵向，2 横向，3 沿边缘
@property (nonatomic) int scanMode;
/// 边缘优化 1 不优化，2 优化
@property (nonatomic) int edgeImgImprove;
/// 全覆盖 1 全覆盖，2 高效（不覆盖）
@property (nonatomic) int coverEdge;
/// 中心线 1不包含 0包含
@property (nonatomic) int centerLine;
/// 执行子航带数量
@property (nonatomic) int selectedSubpolylineNum;
/// 执行子航带序号
@property (nonatomic) NSArray* selected_subpolyline_list;

@end

@interface AUTELPathPlanningInputModel : NSObject
///任务类型 uint8 0 航点，1 矩形，2 多边形， 3倾斜， 4 任务录制，5 航带
@property (nonatomic) int missionType;
///飞机基本输入参数
@property (nonatomic, strong) AUTELPathPlanningBaseInputPara *baseInputPara;
///飞机起飞点,无则传第一个航点
@property (nonatomic, strong) AUTELPathCoordinate3D *uavIniLLA;
///home点,无则传最后一个航点
@property (nonatomic, strong) AUTELPathCoordinate3D *homeLLA;
/// 任务结束动作：0-返航；1-悬停
@property (nonatomic) int taskCompAct;
/// 矩形任务标志位: 1-矩形任务；0-多边形任务
@property (nonatomic) int isRectangle;
/// 矩形任务是否区域内网格状规划路径标志位: 1-网格路径；0-单向路径
@property (nonatomic) int isMeshPaths;
///输入顶点，数组的元素类型必须是PathPlanningCoord3D
@property (nonatomic, copy) NSArray <AUTELPathCoordinate3D*> * _Nonnull vertexArr;

@property (nonatomic, strong) AUTELPathPlanningBaseInputPara *tiltInputPara;//飞机倾斜输入参数

@end



NS_ASSUME_NONNULL_END
