//
//  AUTELWayPointPathInputModel.h
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


/// 航点任务的航线输入数据模型
@interface AUTELWayPointPathInputModel : NSObject

@property (nonatomic, strong) AUTELPathCoordinate3D *uavIniLLA;      //飞机起飞点,无则传第一个航点
@property (nonatomic, strong) AUTELPathCoordinate3D *homeLLA;      //home点,无则传最后一个航点
@property (nonatomic) int taskCompAct;        // 任务结束动作：0-返航；1-悬停
@property (nonatomic, strong) NSArray <AUTELWayPointPathModel*> * _Nonnull vertexArr;//输入顶点，数组的元素类型必须是WayPointPathModel

@end

NS_ASSUME_NONNULL_END
