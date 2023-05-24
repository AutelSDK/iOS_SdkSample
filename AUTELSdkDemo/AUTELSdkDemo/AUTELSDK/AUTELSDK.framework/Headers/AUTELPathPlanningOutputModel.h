//
//  AUTELPathPlanningOutputModel.h
//  AutelGen2
//
//  Created by zhiganglet on 2022/8/1.
//  Copyright © 2022 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELPathMissionDef.h"
#import "AUTELPathCoordinate3D.h"
#import "AUTELPathPlanningPara.h"
#import "AUTELPathMissionLine.h"

NS_ASSUME_NONNULL_BEGIN


/// 航线规划统一输出数据模型
@interface AUTELPathPlanningOutputModel : NSObject
@property (nonatomic) int errorCode;         //航线规划错误码
@property (nonatomic) double flyLength;      //航程
@property (nonatomic) double flyTime;        //航时
@property (nonatomic) double pictNum;        //拍照次数
@property (nonatomic) double flyArea;
@property (nonatomic) double optFlyPathA;    //自动优化的航向

@property (nonatomic, strong) NSArray <AUTELPathPlanningPara*> * _Nonnull otherParaArr;
@property (nonatomic, strong) NSArray< NSArray <AUTELPathCoordinate3D *> *> * pathPoints;
@property (nonatomic, strong) NSArray< NSArray <AUTELPathMissionLine *> *> * lineInfos;

// 航线规划顶点坐标
@property (nonatomic, strong) NSArray< NSArray <AUTELPathCoordinate3D *> *> * vertexsArr;

@property (nonatomic, strong) NSArray <NSArray <AUTELPathCoordInfo*> *> * _Nonnull waypointCoorArrs;
@property (nonatomic, strong) NSArray <AUTELPathCoordinate3D*> * _Nonnull tiltBtnCoords;

@property (nonatomic, strong) NSArray <NSArray <AUTELPathCoordInfo*> *> * _Nonnull arrows;
///航点任务-航点可设的最大半径
@property (nonatomic, strong) NSArray <NSNumber*> * _Nonnull maxRadius;


@end

NS_ASSUME_NONNULL_END
