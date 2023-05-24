//
//  AUTELMissionPathPlanTool.h
//  AUTELSDK
//
//  Created by jiangguoxi on 2021/6/9.
//  Copyright © 2021 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AUTELSDK/AUTELMCWaypointMission.h>

#import "AUTELPathMissionDef.h"
#import "AUTELConvertFileMissionMode.h"
#import "AUTELPathPlanningInputModel.h"
#import "AUTELPathPlanningOutputModel.h"
#import "AUTELWayPointPathInputModel.h"

NS_ASSUME_NONNULL_BEGIN



@interface AUTELMissionPathPlanTool : NSObject


/// 生成飞控执行文件
/// @param mission 任务模型
+ (nullable NSString *)mcMissionConvertToFile:(AUTELConvertFileMissionMode *)mission;

/**
 航点路径规划算法
 
 @param inputModel AUTELWayPointPathInputModel
 @return 成功返回AUTELPathPlanningOutputModel，失败返回nil
 */
+ (nullable AUTELPathPlanningOutputModel *)wayPointPathConvert:(AUTELWayPointPathInputModel *)inputModel;

/**
 矩形、多边形路径规划算法
 
 @param inputModel AUTELPathPlanningInputModel
 @return 成功返回AUTELPathPlanningOutputModel，失败返回nil
 */
+ (nullable AUTELPathPlanningOutputModel *)polygonAlgo:(AUTELPathPlanningInputModel *)inputModel;

/**
 倾斜摄影路径规划算法
 
 @param inputModel AUTELPathPlanningInputModel
 @return 成功返回AUTELPathPlanningOutputModel，失败返回nil
 */
+ (nullable AUTELPathPlanningOutputModel *)obliqueAlgo:(AUTELPathPlanningInputModel *)inputModel;

/**
 航带路径规划算法
 
 @param inputModel AUTELPathPlanningInputModel
 @return 成功返回AUTELPathPlanningOutputModel，失败返回nil
 */
+ (nullable AUTELPathPlanningOutputModel *)stripAlgo:(AUTELPathPlanningInputModel *)inputModel;


@end


NS_ASSUME_NONNULL_END
