//
//  MissionAnotation.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/6.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

@objc protocol MissionAnnotationDragable {
    var annotationID: String { set get }
    var index: Int { set get }
    @objc optional var isSelected: Bool { set get }
    @objc optional var isEnable: Bool { get set }
    @objc optional var isHidden: Bool { get set }
    @objc optional var handleRectOffRatio: CGPoint { get set } // 取值范围 0 ~1
}

/// 任务飞行航点，测绘任务顶点，断点
class MissionMarkPointAnnotation: MKPointAnnotation, MissionAnnotationDragable {
    var index = 0
    var isSelected = false
    var annotationID = getRandomString()
    var isIndexLabHidden = false
    var isLast = false
    var isCircleIcon = false
    var isPolygonSE = false
    var isHidden = false
    var isBreakPoint = false//断点续飞
    var capValue: Float = 60
    var capValueType: Int = 0
    var cameraAction = CameraAction.none
    //角度，这里需要传递的是弧度单位, 正北为0°，正东为90° 默认正南
    var headingAngle: CGFloat = .pi
    
    private var _handleRectOffRatio:CGPoint?
    var handleRectOffRatio:CGPoint {
        set {
            _handleRectOffRatio = newValue
        }
        get {
            if let p =  _handleRectOffRatio {
                return p
            }
            
            if isCircleIcon {
                return CGPoint.zero
            }
            
            if isBreakPoint {
                return CGPoint.zero
            }
            
            return CGPoint.init(x: 0, y: 0.5)
        }
    }
}

/// 任务飞行中间＋号图标
class MissionAddIconAnnotation: MKPointAnnotation, MissionAnnotationDragable {
    var index: Int = 0
    /// 两个坐标间的距离
    var altitude: Float = 0
    var annotationID = getRandomString()
    var isHidden = false
}
