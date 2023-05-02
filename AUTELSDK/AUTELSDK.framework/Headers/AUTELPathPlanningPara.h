//
//  AUTELPathPlanningPara.h
//  AutelGen2
//
//  Created by zhiganglet on 2022/8/2.
//  Copyright © 2022 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELPathCoordinate3D.h"

NS_ASSUME_NONNULL_BEGIN

@interface AUTELPathPlanningPara : NSObject

@property (nonatomic) double curFlyTime;//
@property (nonatomic) double curFlyDistance;//

@end


@interface AUTELPathCoordInfo : AUTELPathCoordinate3D
///当前飞行时间
@property (nonatomic) double curFlyTime;
///当前飞行距离
@property (nonatomic) double curFlyDistance;
///航线箭头
@property (nonatomic) BOOL showArrow;
///飞行航向角
@property (nonatomic) double heading;

@end

NS_ASSUME_NONNULL_END
