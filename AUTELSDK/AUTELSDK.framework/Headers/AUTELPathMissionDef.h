//
//  AUTELPathMissionDef.h
//  AutelGen2
//
//  Created by zhiganglet on 2022/8/1.
//  Copyright © 2022 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (uint8_t, AUTELPathMissionType) {
    /**
    *  @brief Waypoint mission
    *
    *  航点任务
    */
    AUTELPathMissionTypeWaypoint = 0,
    /**
    *  @brief Rectangle mission
    *
    * 矩形测绘任务
    */
    AUTELPathMissionTypeRectangle,
    /**
    *  @brief Polygon mission
    *
    *  多边形测绘任务
    */
    AUTELPathMissionTypePolygon,
    /**
    *  @brief Oblique photography  mission
    *
    *  倾斜摄影任务
    */
    AUTELPathMissionTypeObliquePhoto,
    /**
    *  @brief record  mission
    *
    *  录制任务
    */
    AUTELPathMissionTypeRecord,
    /**
    *  @brief strip  mission
    *
    *  航带任务
    */
    AUTELPathMissionTypeStrip
};

typedef NS_ENUM (uint8_t, AUTELPathPointMissionType) {
    AUTELPathPointMissionTypeUnknow = 0, //未知
    AUTELPathPointMissionTypeWayPoint = 1, //航点任务
    AUTELPathPointMissionTypePathPlanning = 6 //测绘任务
};

typedef NS_ENUM (uint8_t, AUTELPathPlanningLostActionType) {
    AUTELPathPlanningLostActionTypeUnknow = 0, //未知
    AUTELPathPlanningLostActionTypeGoHome = 1,
    AUTELPathPlanningLostActionTypeContinue = 2
};

typedef NS_ENUM (uint8_t, AUTELPathPlanningWayPointType) {
    AUTELPathPlanningWayPointTypeUnknow = 0, //未知
    AUTELPathPlanningWayPointTypeHover = 1,
    AUTELPathPlanningWayPointTypeFlyOver = 2
};
