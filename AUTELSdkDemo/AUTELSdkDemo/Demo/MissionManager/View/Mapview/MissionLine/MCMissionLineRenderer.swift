//
//  MCMissionLineRenderer.swift
//  AutelGen2
//
//  Created by Autel-xufeng on 2019/10/6.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import UIKit

class MCMissionLineRenderer: MKPolylineRenderer {
        
    var width: CGFloat = 0
    var canDraw = false

    init(line: MissionConnectionLine, width: CGFloat) {
        super.init(overlay: line)
        self.width = width
    }

    //2020-03-13 17:17:49.844814+05 AutelGen2[1949:532390] *** -[AutelGen2.MCMissionLineRenderer canDrawMapRect:zoomScale:]: message sent to deallocated instance 0x283d82be0
    //这里出现crash
    //iOS 13.5已修复crash问题，故屏蔽该方法。
//    override func canDraw(_ mapRect: MKMapRect, zoomScale: MKZoomScale) -> Bool {
//        canDraw = super.canDraw(mapRect, zoomScale: zoomScale)
//        return canDraw
//    }

    override func draw(_ mapRect: MKMapRect,
                       zoomScale: MKZoomScale,
                       in context: CGContext) {
//        if !canDraw { return }
//        super.draw(mapRect, zoomScale: zoomScale, in: context)
        
//        dPrint("LineRenderer draw MissionLine \(zoomScale) \(mapRect)")
        
        guard let line = overlay as? MissionConnectionLine else { return }
        let theMapRect = overlay.boundingMapRect
        guard theMapRect.intersects(mapRect) else {
            return
        }
        
        lineWidth = width / zoomScale
//        dPrint("LineRenderer draw MissionLine zoomScale \(zoomScale) lineW\(lineWidth)")
        renderer(context: context,
                 width: lineWidth,
                 color: line.strokeColor.cgColor,
                 arrowWidth: lineWidth * 2)
        if line.strokeColor.isEqual(line.fillColor) {
            return
        }
        renderer(context: context,
                 width: lineWidth - 2,
                 color: line.fillColor.cgColor,
                 arrowWidth: lineWidth * 2 - 3)
    }
    
   private func renderer(context: CGContext,
                  width: CGFloat,
                  color: CGColor,
                  arrowWidth: CGFloat) {
        guard let line = overlay as? MissionConnectionLine else { return }
        if polyline.pointCount > 1 {
            let count = polyline.pointCount
            for index in 1 ..< count {
                var fPoint = point(for: polyline.points()[index - 1])
                var tPoint = point(for: polyline.points()[index])
                var showArrow = true
                if line.showArrows.count > index - 1 {
                    showArrow = line.showArrows[index - 1]
                }
                if line.isReverse {
                    let temp = fPoint
                    fPoint = tPoint
                    tPoint = temp
                }
                lineSegmentRenderer(context, line, fPoint, tPoint, color, width, arrowWidth, showArrow)
            }
        }
    }
    
   private func lineSegmentRenderer(_ context: CGContext,
                                    _ line:MissionConnectionLine,
                                    _ fPoint: CGPoint,
                                    _ tPoint: CGPoint,
                                    _ color: CGColor,
                                    _ width: CGFloat,
                                    _ arrowWidth: CGFloat,
                                    _ showArrow: Bool) {
//        guard let line = overlay as? MissionConnectionLine else { return }

        if line.arrowPosition.count > 1 && showArrow {
            context.saveGState()
            context.setLineJoin(.miter)
            context.setLineCap(.square)
            context.setFillColor(color)
            context.setStrokeColor(color)
            context.setLineWidth(4)
           //时间紧迫，此处还没处理成完全动态化配置
           //1/4点 3/4点
           let pivot = CGPoint(x: (fPoint.x + tPoint.x) / 2,
                               y: (fPoint.y + tPoint.y) / 2)
           var quarter = CGPoint(x: (fPoint.x + pivot.x) / 2,
                                 y: (fPoint.y + pivot.y) / 2)
           var three_quarters = CGPoint(x: (pivot.x + tPoint.x) / 2,
                                        y: (pivot.y + tPoint.y) / 2)
           if width < lineWidth {
               //上层小箭头位置 (签蓝色的箭头 getArrowPoint 中 tPoint 往向量方向 多 一个 单位)
               let angle = MCMissionLineRenderer.getAnglesX(p1: fPoint,
                                                           p2: tPoint)
               let _x = CGFloat(abs(cos(angle)))
               let _y = CGFloat(abs(sin(angle)))
               //此处坐标系与数学象限相反
               if tPoint.x >= fPoint.x && tPoint.y <= fPoint.y {
                   quarter = CGPoint(x: quarter.x + _x,
                                     y: quarter.y - _y)
                   three_quarters = CGPoint(x: three_quarters.x + _x,
                                            y: three_quarters.y - _y)
               } else if tPoint.x > fPoint.x && tPoint.y > fPoint.y {
                   //向右下角
                   quarter = CGPoint(x: quarter.x + _x,
                                     y: quarter.y + _y)
                   three_quarters = CGPoint(x: three_quarters.x + _x,
                                            y: three_quarters.y + _y)
               } else if tPoint.x < fPoint.x && tPoint.y < fPoint.y {
                   //向左上角
                   quarter = CGPoint(x: quarter.x - _x,
                                     y: quarter.y - _y)
                   three_quarters = CGPoint(x: three_quarters.x - _x,
                                            y: three_quarters.y - _y)
               } else if tPoint.x < fPoint.x && tPoint.y >= fPoint.y {
                   //向左下角,水平向左
                   quarter = CGPoint(x: quarter.x - _x,
                                     y: quarter.y + _y)
                   three_quarters = CGPoint(x: three_quarters.x - _x,
                                            y: three_quarters.y + _y)
               } else if fPoint.x == tPoint.x {
                   //竖直方向
                   quarter = CGPoint(x: quarter.x,
                                     y: quarter.y + _y)
                   three_quarters = CGPoint(x: three_quarters.x,
                                            y: three_quarters.y + _y)
               }
           }
           let arrows1 = getArrowPoint(fPoint: fPoint,
                                       tPoint: quarter,
                                       arrowWidth: arrowWidth)
           let arrows2 = getArrowPoint(fPoint: fPoint,
                                       tPoint: three_quarters,
                                       arrowWidth: arrowWidth)
            let path = CGMutablePath()
           //1/4箭头
           path.move(to: arrows1.0)
           path.addLine(to: arrows1.1)
           path.addLine(to: arrows1.2)
           path.addLine(to: arrows1.0)
           //3/4箭头
           path.move(to: arrows2.0)
           path.addLine(to: arrows2.1)
           path.addLine(to: arrows2.2)
           path.addLine(to: arrows2.0)
            
            //绘制
          context.beginPath()
          context.addPath(path)
          context.closePath()
          context.drawPath(using: .fillStroke)
          context.restoreGState()
    } else if line.arrowPosition.count == 1 && showArrow {
            context.saveGState()
            context.setLineJoin(.miter)
            context.setLineCap(.square)
            context.setFillColor(color)
            context.setStrokeColor(color)
            context.setLineWidth(4)
            
           let factor = CGFloat(1.0 / (line.arrowPosition.first ?? 0.5))
           var pivot = CGPoint(x: (fPoint.x + tPoint.x) / factor,
                               y: (fPoint.y + tPoint.y) / factor)
           if width < lineWidth {
               let angle = MCMissionLineRenderer.getAnglesX(p1: fPoint,
                                                           p2: tPoint)
               let _x = CGFloat(abs(cos(angle)))
               let _y = CGFloat(abs(sin(angle)))
               //此处坐标系与数学象限相反
               if tPoint.x >= fPoint.x && tPoint.y <= fPoint.y {
                   pivot = CGPoint(x: pivot.x + _x,
                                   y: pivot.y - _y)
               } else if tPoint.x > fPoint.x && tPoint.y > fPoint.y {
                   //向右下角
                   pivot = CGPoint(x: pivot.x + _x,
                                   y: pivot.y + _y)
               } else if tPoint.x < fPoint.x && tPoint.y < fPoint.y {
                   //向左上角
                   pivot = CGPoint(x: pivot.x - _x,
                                   y: pivot.y - _y)
               } else if tPoint.x < fPoint.x && tPoint.y >= fPoint.y {
                   //向左下角,水平向左
                   pivot = CGPoint(x: pivot.x - _x,
                                   y: pivot.y + _y)
               } else if fPoint.x == tPoint.x {
                   //竖直方向
                   pivot = CGPoint(x: pivot.x,
                                   y: pivot.y + _y)
                   }
               }
           let arrows1 = getArrowPoint(fPoint: fPoint,
                                       tPoint: pivot,
                                       arrowWidth: arrowWidth)
            let path = CGMutablePath()
           path.move(to: arrows1.0)
           path.addLine(to: arrows1.1)
           path.addLine(to: arrows1.2)
           path.addLine(to: arrows1.0)
            
            //绘制
          context.beginPath()
          context.addPath(path)
          context.closePath()
            context.drawPath(using: .fillStroke)
            context.restoreGState()
       }

        //直线
        context.saveGState()
        context.setStrokeColor(color)
        context.setLineWidth(width)
        if line.isDashLine {
          context.setLineDash(phase: 0, lengths: line.dashLenths)
        }
        context.beginPath()
        context.move(to: fPoint)
        context.addLine(to: tPoint)
        context.closePath()
        context.drawPath(using: .stroke)
        context.restoreGState()
    }
    
    // 获取箭头的点位置
    func getArrowPoint(fPoint: CGPoint,
                       tPoint: CGPoint,
                       arrowWidth: CGFloat) -> (CGPoint, CGPoint, CGPoint) {
        var p1 = CGPoint.zero           //箭头点1
        var p2 = CGPoint.zero           //箭头点2
        var p3 = CGPoint.zero           //箭头最前面点
        //假设箭头边长20,箭头是一个等腰三角形
//        let line = sqrt(pow(abs(tPoint.x - fPoint.x), 2) + pow(abs(tPoint.y - fPoint.y), 2))
//        let arrowH: CGFloat = line > 40 ? 20 : line / 3
        let arrowH: CGFloat = arrowWidth
        //线与水平方向的夹角
        let angle = MCMissionLineRenderer.getAnglesX(p1: fPoint,
                                                    p2: tPoint)
        let _x = CGFloat(abs(sin(angle))) * arrowH / 2
        let _y = CGFloat(abs(cos(angle))) * arrowH / 2
        //向右上角、水平向右
        if tPoint.x >= fPoint.x && tPoint.y <= fPoint.y {
            p1.x = tPoint.x - _x
            p1.y = tPoint.y - _y
            p2.x = tPoint.x + _x
            p2.y = tPoint.y + _y
            p3.x = tPoint.x + _y * 2
            p3.y = tPoint.y - _x * 2
        } else if tPoint.x > fPoint.x && tPoint.y > fPoint.y {
            //向右下角
            p1.x = tPoint.x + _x
            p1.y = tPoint.y - _y
            p2.x = tPoint.x - _x
            p2.y = tPoint.y + _y
            p3.x = tPoint.x + _y * 2
            p3.y = tPoint.y + _x * 2
        } else if tPoint.x < fPoint.x && tPoint.y < fPoint.y {
            //向左上角
            p1.x = tPoint.x - _x
            p1.y = tPoint.y + _y
            p2.x = tPoint.x + _x
            p2.y = tPoint.y - _y
            p3.x = tPoint.x - _y * 2
            p3.y = tPoint.y - _x * 2
        } else if tPoint.x < fPoint.x && tPoint.y >= fPoint.y {
            //向左下角,水平向左
            p1.x = tPoint.x - _x
            p1.y = tPoint.y - _y
            p2.x = tPoint.x + _x
            p2.y = tPoint.y + _y
            p3.x = tPoint.x - _y * 2
            p3.y = tPoint.y + _x * 2
        } else if fPoint.x == tPoint.x {
            //竖直方向
            p1.x = tPoint.x - arrowH / 2
            p1.y = tPoint.y
            p2.x = tPoint.x + arrowH / 2
            p2.y = tPoint.y
            p3.x = tPoint.x
            p3.y = tPoint.y > fPoint.y ? tPoint.y + arrowH : tPoint.y - arrowH
        }
        return (p1, p2, p3)
    }
    
    /// 计算三点之间的角度
    ///
    /// - Parameters:
    ///   - p1: 点1
    ///   - p2: 点2（也是角度所在点）
    ///   - p3: 点3
    /// - Returns: 线与Y轴夹角 0 - pi_2 (0-90)
    class func getAngles(p1: CGPoint, p2: CGPoint, p3: CGPoint) -> CGFloat {
        //排除特殊情况，三个点一条线
        if (p1.x == p2.x && p2.x == p3.x) || ( p1.y == p2.x && p2.x == p3.x){
            return 0
        }
        let a = abs(p1.x - p2.x)
        let b = abs(p1.y - p2.y)
        let c = abs(p3.x - p2.x)
        let d = abs(p3.y - p2.y)
        
        if (a < 1.0 && b < 1.0) || (c < 1.0 && d < 1.0){
            return 0
        }
        let e = a * c + b * d
        let f = sqrt(a * a + b * b)
        let g = sqrt(c * c + d * d)
        let r = acos(e / (f * g))
        //弧度值
        return r
    }
    
    
    //线与水平方向的夹角  0 - pi_2 [0-90]
    class func getAnglesX(p1: CGPoint, p2: CGPoint) -> CGFloat  {
//        if p1.x == p2.x && p1.y != p2.y {
//            return .pi
//        }
        let angle = MCMissionLineRenderer.getAngles(p1: p1, p2: p2, p3: CGPoint(x: p1.x + 10 + p2.x,y: p2.y))
        if angle > .pi / 2  {
            return .pi - angle
        }
        return angle
    }
    
    //线与垂直平方向的夹角  0 - pi_2 [0-90]
    class func getAnglesY(p1: CGPoint, p2: CGPoint) -> CGFloat  {
//                if p1.y == p2.y && p1.x != p2.x {
//                    return .pi
//                }
        let angle =  MCMissionLineRenderer.getAngles(p1: p1, p2: p2, p3: CGPoint(x: p2.x,y: p1.y + 10 + p2.y)) // + 10 否则 90度时异常 // + 1   if (a < 1.0 && b < 1.0) || (c < 1.0 && d < 1.0) 被拦截 。。。
        if angle > .pi / 2  {
            return .pi - angle
        }
        return angle
    }
}
