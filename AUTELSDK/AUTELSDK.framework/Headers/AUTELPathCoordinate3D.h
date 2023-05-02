//
//  AUTELPathCoordinate3D.h
//  AutelGen2
//
//  Created by zhiganglet on 2022/8/2.
//  Copyright © 2022 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUTELPathCoordinate3D : NSObject
///latitude
@property (nonatomic) double latitude;//纬度
///longitude
@property (nonatomic) double longitude;//经度
///altitude
@property (nonatomic) double altitude;//高度

- (instancetype)initWith:(CLLocationCoordinate2D)coordinate altitude:(double)altitude;
@end

NS_ASSUME_NONNULL_END
