//
//  MapCorrect.h
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/7.
//  Copyright © 2020 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
//////////////////////////////////
@interface MapCorrect : NSObject

/// 真实坐标转换为高德坐标
+ (CLLocationCoordinate2D)wgs2gcjWithCoordinate:(CLLocationCoordinate2D)coordinate;

/// 高德坐标转换为真实坐标
+ (CLLocationCoordinate2D)gcj2wgsWithCoordinate:(CLLocationCoordinate2D)coordinate;

@end
