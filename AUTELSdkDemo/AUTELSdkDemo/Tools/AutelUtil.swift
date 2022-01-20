//
//  AutelUtil.swift
//  AutelGen2
//
//  Created by Devin on 2017/9/4.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation

/// provide minimum and maximum range of number and get a random number.
func randomNumber(MIN: Int, MAX: Int)-> Int{
    return Int(arc4random_uniform(UInt32(MAX-MIN)) + UInt32(MIN));
}

func getRandomString() -> String {
    let stamp = Date().timeStamp
    let random = randomNumber(MIN: 10000, MAX: 99999)
    let string = String(random) + String(stamp.suffix(5))
    return string
}


/// 国际化
///
/// - Parameter text: 待国际化字符串
/// - Returns: 已国际化的字符串
func local(text: String) -> String {
    return NSLocalizedString(text, comment: text)
}

/// 当前地图使用的坐标系类型
func mapUseCoordinateType() -> CoordinateType {
    if UserSettings.shared.isCalibrateMapCoordinates {
        return CoordinateType.GCJ02
    } else {
        return CoordinateType.WGS84
    }
}

func coordinate2Coordinate(coordinate: CLLocationCoordinate2D ,type:CoordinateType ,targetType:CoordinateType) -> CLLocationCoordinate2D {
    switch (type,targetType) {
    case (.WGS84,.GCJ02):
        return MapCorrect.wgs2gcj(with: coordinate)
    case (.GCJ02,.WGS84):
        return MapCorrect.gcj2wgs(with: coordinate)
    default:
        return coordinate
    }
}
