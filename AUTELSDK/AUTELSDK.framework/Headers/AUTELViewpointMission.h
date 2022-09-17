//
//  AUTELViewpointMission.h
//  AUTELSDK
//
//  Created by ChenYuanliang on 2018/4/6.
//  Copyright © 2018年 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELMission.h>

@interface AUTELViewpointMission : AUTELMission<NSCopying>

@property (nonatomic, assign) float flightAngle;

@property (nonatomic, assign) float flightSpeed;

@property (nonatomic, assign) float horizontalFOV;

@property (nonatomic, assign) float verticalFOV;

@property (nonatomic, assign) float scaleX;

@property (nonatomic, assign) float scaleY;

@end
