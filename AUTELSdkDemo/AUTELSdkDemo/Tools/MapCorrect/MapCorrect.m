//
//  MapCorrect.m
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/7.
//  Copyright © 2020 AUTEL. All rights reserved.
//

#import "MapCorrect.h"

@interface MapCorrect (){
    NSArray *exclude;
    NSArray *region;
}

@end

@implementation MapCorrect

+ (CLLocationCoordinate2D )getCoordinateDelta:(CLLocationCoordinate2D )coordinate{
    double d1 = [self transformLatWithFirst:(coordinate.longitude - 105.0) AndSecond:(coordinate.latitude - 35.0)];
    double d2 = [self transformLonWithFirst:(coordinate.longitude - 105.0) AndSecond:(coordinate.latitude - 35.0)];
    double d3 = M_PI * (coordinate.latitude / 180.0);
    double d4 = sin(d3);
    double d5 = 1.0 - d4 * (0.006693421622965943 * d4);
    double d6 = sqrt(d5);
    double d7 = 180.0 * d1 / (M_PI * (6378245.0 * (1.0 - 0.006693421622965943) / (d5 * d6)));
    double d8 = 180.0 * d2 / (M_PI * (6378245.0 / d6 * cos(d3)));
    CLLocationCoordinate2D localLatLng = CLLocationCoordinate2DMake(d7, d8);
    return localLatLng;
}

+ (double)transformLatWithFirst:(double)lat1 AndSecond:(double)lat2{
    double absLat1 = lat1;
    if (lat1 < 0) {
        absLat1 = -lat1;
    }
    return -100.0
            + 2.0 * lat1
            + 3.0 * lat2
            + lat2 * (0.2 * lat2)
            + lat2 * (0.1 * lat1)
            + 0.2 * sqrt(absLat1)
            + 2.0 * (20.0 * sin(M_PI * (6.0 * lat1))
            + 20.0 * sin(M_PI * (2.0 * lat1))) / 3.0
            + 2.0 * (20.0 * sin(M_PI * lat2)
            + 40.0 * sin(M_PI * (lat2 / 3.0))) / 3.0
            + 2.0 * (160.0 * sin(M_PI * (lat2 / 12.0))
            + 320.0 * sin(M_PI * lat2 / 30.0)) / 3.0;
}

+ (double)transformLonWithFirst:(double)lon1 AndSecond:(double)lon2{
    double absLon1 = lon1;
    if (lon1 < 0) {
        absLon1 = -lon1;
    }
    return  300.0
            + lon1
            + 2.0 * lon2
            + lon1 * (0.1 * lon1)
            + lon2 * (0.1 * lon1)
            + 0.1 * sqrt(absLon1)
            + 2.0 * (20.0 * sin(M_PI * (6.0 * lon1))
            + 20.0 * sin(M_PI * (2.0 * lon1))) / 3.0
            + 2.0 * (20.0 * sin(M_PI* lon1)
            + 40.0 * sin(M_PI * (lon1 / 3.0))) / 3.0
            + 2.0 * (150.0 * sin(M_PI * (lon1 / 12.0))
            + 300.0 * sin(M_PI * (lon1 / 30.0))) / 3.0;
}

+ (CLLocationCoordinate2D)wgs2gcjWithCoordinate:(CLLocationCoordinate2D)coordinate{
    CLLocationCoordinate2D delta = [self getCoordinateDelta:coordinate];
    return CLLocationCoordinate2DMake(delta.latitude + coordinate.latitude, delta.longitude + coordinate.longitude);
}

+ (CLLocationCoordinate2D)gcj2wgsWithCoordinate:(CLLocationCoordinate2D)coordinate{
    CLLocationCoordinate2D delta = [self getCoordinateDelta:coordinate];
    return CLLocationCoordinate2DMake(coordinate.latitude - delta.latitude, coordinate.longitude - delta.longitude);
}

+ (CLLocationCoordinate2D)gcj2wgs_exactWithCoordinate:(CLLocationCoordinate2D)coordinate{
    double d1 = 0.0;
    double d2 = 0.0;
    double d3 = coordinate.latitude - 0.01;
    double d4 = coordinate.longitude - 0.01;
    double d5 = 0.01 + coordinate.latitude;
    double d6 = 0.01 + coordinate.longitude;
    int i = 0;
    CLLocationCoordinate2D localCoordinate1;
    if (i >= 30) {
        localCoordinate1 = CLLocationCoordinate2DMake(d1, d2);
        NSLog(@"%f, %f", localCoordinate1.latitude, localCoordinate1.longitude);
    }
    double d7;
    double d8;
    double abs_d7;
    double abs_d8;
    do {
        d1 = (d3 + d5) / 2.0;
        d2 = (d4 + d6) / 2.0;
        localCoordinate1 = CLLocationCoordinate2DMake(d1, d2);
        CLLocationCoordinate2D localCoordinate2 = CLLocationCoordinate2DMake(d1, d2);
        CLLocationCoordinate2D localCoordinate3 = [self wgs2gcjWithCoordinate:localCoordinate2];
        d7 = localCoordinate3.latitude - coordinate.latitude;
        d8 = localCoordinate3.longitude - coordinate.longitude;
        abs_d7 = d7;
        abs_d8 = d8;
        if (d7 < 0) {
            abs_d7 = -d7;
        }
        if (d8 < 0) {
            abs_d8 = -d8;
        }
    } while ( (abs_d7 < 1.0E-006) && (abs_d8 < 1.0E-006));
    return localCoordinate1;
}

@end
