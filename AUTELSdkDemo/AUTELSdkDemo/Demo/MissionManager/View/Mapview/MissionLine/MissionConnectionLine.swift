//
//  MissionConnectionLine.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/6.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

class MissionConnectionLine: MKPolyline {
    var isReverse = false
    var isDashLine = false
    var dashLenths: [CGFloat] = [15, 30]
    //默认两个箭头，分别在1/4处和3/4处
    var arrowPosition = [0.25, 0.75]
    var arrowNums = 2
    //对应多边形，线段是否有箭头
    var showArrows: [Bool] = []
    var fillColor = UIColor(fromHex: 0x32C5FF, alpha: 1)
    var strokeColor = UIColor(fromHex: 0x01179D, alpha: 1)
    var width: CGFloat = 10
}
