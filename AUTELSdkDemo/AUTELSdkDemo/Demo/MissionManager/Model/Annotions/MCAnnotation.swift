//
//  MCAnnotation.swift
//  AutelGen2
//
//  Created by Autel-xufeng on 2019/9/29.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import Foundation

enum MCCameraAction {
    case photo
    case record
    case stopRecord
    case none
}

//class MCWaypointAnnotation: MissionMarkPointAnnotation {
//    var capValue: Float = 0
//    var cameraAction = MCCameraAction.unknown
//    //角度，这里需要传递的是弧度单位, 正北为0°，正东为90°
//    var headingAngle: CGFloat = 0
//}

/// 兴趣点
class MCMissionInterestingPointAnnotation: MKPointAnnotation, MissionAnnotationDragable {
    var index: Int = 0
    var isSelected: Bool = false
    var annotationID = getRandomString()
}
