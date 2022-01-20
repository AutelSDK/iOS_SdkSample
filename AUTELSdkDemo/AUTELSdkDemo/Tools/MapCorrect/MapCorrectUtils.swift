//
//  MapCorrectUtils.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet Argo on 2020/5/10.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation


extension CLLocationCoordinate2D {
    
    /// 计算两个坐标间的距离
    ///
    /// - Parameter another: CLLocationCoordinate2D
    /// - Returns: CLLocationDistance
    func distanceWith(_ another: CLLocationCoordinate2D) -> CLLocationDistance {
        return location.distance(from: another.location)
    }
    
    /// 计算两坐标点间的中心点
    ///
    /// - Parameter another: CLLocationCoordinate2D
    /// - Returns: CLLocationCoordinate2D
    func middleCoordinateWith(_ another: CLLocationCoordinate2D) -> CLLocationCoordinate2D {
        let lat = (latitude + another.latitude) / 2.0
        //首先，判断是否是跨经度180的情况
        let longitudeFabsSum = fabs(longitude) + fabs(another.longitude)
        //如果绝对值之和超过180°且，和的绝对值小于绝对值的和，说明经度坐标符号不一样，且夸过了经度180°
        if longitudeFabsSum > 180 && fabs(longitude + another.longitude) < longitudeFabsSum {
            let halfSpan = (360.0 - longitudeFabsSum) / 2.0     //跨度的一半
            let multiplier = (longitude + another.longitude < 0) ? 1.0 : -1.0
            let lon = (min(fabs(longitude), fabs(another.longitude)) + halfSpan) * multiplier
            return CLLocationCoordinate2D(latitude: lat, longitude: lon)
        } else {
            let lon = (longitude + another.longitude) / 2.0
            return CLLocationCoordinate2D(latitude: lat, longitude: lon)
        }
    }
    
    private var location: CLLocation {
        get {
            return CLLocation(latitude: latitude, longitude: longitude)
        }
    }
}


/// 是否打开了纠偏开关
var isMapNeedCorrect: Bool {
    get {
        if NSTimeZone.local.description.contains("Asia/Chongqing")
            || NSTimeZone.local.description.contains("Asia/Harbin")
            || NSTimeZone.local.description.contains("Asia/Shanghai")
            || NSTimeZone.local.description.contains("Asia/Beijing") {
            return true
        }
        return false
    }
}

/// 如果打开了纠偏开关，需要将真实的坐标转换成纠偏后的坐标 （如果需要的话 - 真实坐标转换为高德坐标）
///
/// - Parameter CLLocationCoordinate2D: 原始坐标点
/// - Returns: CLLocationCoordinate2D
func coordinateCorrectIfNeeded(_ coordinate: CLLocationCoordinate2D) -> CLLocationCoordinate2D {
    if isMapNeedCorrect {
        return MapCorrect.wgs2gcj(with: coordinate)
    } else {
        return coordinate
    }
}

/// 如果打开了纠偏开关，将纠偏后的坐标转换成纠偏前的真实坐标 （如果需要的话 - 高德坐标转换为真实坐标）
///
/// - Parameter coordinate: 待处理的坐标点
/// - Returns: CLLocationCoordinate2D
func coordinateAntiCorrectIfNeeded(_ coordinate: CLLocationCoordinate2D) -> CLLocationCoordinate2D {
    if isMapNeedCorrect {
        return MapCorrect.gcj2wgs(with: coordinate)
    } else {
        return coordinate
    }
}

