//
//  AUTELPathMissionLine.h
//  AutelGen2
//
//  Created by zhiganglet on 2022/8/1.
//  Copyright © 2022 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELPathMissionDef.h"
#import "AUTELPathCoordinate3D.h"
#import "AUTELWayPointPathModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  该类描述一条航线相关信息.
 */
@interface AUTELPathMissionLine : NSObject

/// 航点类型    1 代表停下的点，2 代表协调转弯
@property(nonatomic, assign)int wpType;
/// 航线类型，1直线，2圆弧
@property(nonatomic, assign)int lineType;
/// 起点坐标    LLA（deg,deg,m）
@property(nonatomic, strong) AUTELPathCoordinate3D * prevLLA;
/// 终点坐标    LLA（deg,deg,m）
@property(nonatomic, strong) AUTELPathCoordinate3D * currLLA;
/// 圆心坐标    LLA（deg,deg,m）
@property(nonatomic, strong) AUTELPathCoordinate3D * centLLA;
/// 航线最大速度    m/s
@property(nonatomic, assign) double maxSpeed;
/// 下一条航线最大速度    m/s
@property(nonatomic, assign) double maxSpeedNext;
/// 高度优先级    全是0，表示无优先级
@property(nonatomic, assign)int altPriority;
/// 此航点中 动作朝向模式    1表示沿航线，2表示手动，3表示自定义
@property(nonatomic, assign)int heading_Mode;
/// 对应兴趣点的坐标    LLA（deg,deg,m）
@property(nonatomic, strong) AUTELPathCoordinate3D * interestingPoint;
/// 航线长度    m
@property(nonatomic, assign) double fp_length;
/// 航线预计飞行时间    s
@property(nonatomic, assign) double time;
/// 拍照张数
@property(nonatomic, assign) int photoCount;
/// 是否存在定距拍照动作，0/1
@property(nonatomic, assign) int has_distancePhoto;

/// 航点动作（11个）    有效ActionNum_FP+1个，最后一个是下一个航点的第一个动作
@property (nonatomic, strong) NSArray <AUTELPathPlanningAction*> * actions;


@end

NS_ASSUME_NONNULL_END
