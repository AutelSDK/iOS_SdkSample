//
//  EarthStationViewModel+Mapview.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/14.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

// mapview
extension EarthStationViewModel: MKMapViewDelegate {
    
    func mapView(_ mapView: MKMapView, didDeselect view: MKAnnotationView) {
    }
    
    //MARK:大头针选中
    func mapView(_ mapView: MKMapView, didSelect view: MKAnnotationView) {
    }
    
    func mapView(_ mapView: MKMapView, didAdd views: [MKAnnotationView]) {
        views.forEach { (annotationView) in
        }
    }
    
    //MARK:拖动大头针状态变化代理方法
    func mapView(_ mapView: MKMapView, annotationView view: MKAnnotationView, didChange newState: MKAnnotationView.DragState, fromOldState oldState: MKAnnotationView.DragState) {
        
    }
    
    //
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        
        //        if overlay is AircraftGPSCircle {
        //            let circle = MCCircleRenderer.init(overlay: overlay as! AircraftGPSCircle)
        //            circle.fillColor = UIColor.init(0x1E90FF)
        //            circle.alpha = 0.1
        //            return circle
        //        }
        //        else
        
        if overlay is AutelAircraftToHomeLacationLine {
            let routeLineRender:MKPolylineRenderer = MKPolylineRenderer(polyline: overlay as! AutelAircraftToHomeLacationLine)
            routeLineRender.lineWidth = 1
            routeLineRender.strokeColor = UIColor.init(fromHex: 0xff0000, alpha: 0.5)
            return routeLineRender
        } else if overlay is AircraftSafeCircle {  // panxiangxi add 2020-03-19
            let circle = MKCircleRenderer.init(circle: overlay as! AircraftSafeCircle)
            circle.strokeColor = UIColor.blue
            circle.lineWidth = 2
            return circle
        } else if overlay.isMember(of: MissionConnectionLine.self), let line = overlay as? MissionConnectionLine {
            let render = MCMissionLineRenderer.init(line: line, width: line.width)
            return render
        }  else {
            return MKOverlayRenderer()
        }
    }
    
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        if annotation.isKind(of:AutelAircraftAnnotation.self) {
            var aircraftAnnoView = mapView.dequeueReusableAnnotationView(withIdentifier:EarthStationViewModel.aircraftReuseIdentifier)
            if aircraftAnnoView == nil {
                aircraftAnnoView = AutelAircraftAnnotationView.init(annotation:annotation, reuseIdentifier:EarthStationViewModel.aircraftReuseIdentifier)
            }
            aircraftAnnoView?.layer.zPosition = 1
            
            return aircraftAnnoView
        } else if annotation.isKind(of: AutelHomeAnnotation.self) {
            var homeAnnoview = mapView.dequeueReusableAnnotationView(withIdentifier:EarthStationViewModel.homeReuseIdentifier)
            if homeAnnoview == nil {
                homeAnnoview = AutelHomeAnnotationView.init(annotation: annotation, reuseIdentifier: EarthStationViewModel.homeReuseIdentifier)
            }
            homeAnnoview?.layer.zPosition = 1
            drawSafeCircle(mapView: mapView)
            return homeAnnoview
        } else if annotation.isKind(of: MissionMarkPointAnnotation.self) {
            let identifier = EarthStationViewModel.mcWaypointReuseIdentifier
            var annotationView = mapView.dequeueReusableAnnotationView(withIdentifier: identifier) as? MCMarkAnnotationView
            if annotationView == nil {
                annotationView = MCMarkAnnotationView(annotation: annotation, reuseIdentifier: identifier)
            }
            
            annotationView?.whenMoveTo = { cgPoint in
                let coordinate = mapView.convert(cgPoint, toCoordinateFrom: mapView)
                NotificationCenter.default.post(name: NSNotification.Name.wayPointMarkAnnotationViewDidMoved, object: (coordinate,
                                                                                                                       (annotation as! MissionMarkPointAnnotation).index, mapView))
            }
            annotationView?.whenTap = {
                NotificationCenter.default.post(name: NSNotification.Name.wayPointMarkAnnotationViewDidTap, object: ((annotation as! MissionMarkPointAnnotation).index, mapView))
            }
            
            return annotationView
        } else if annotation.isMember(of: MissionAddIconAnnotation.self) {
            let identifier = EarthStationViewModel.missionAddIconReuseIdentifier
            var annotationView = mapView.dequeueReusableAnnotationView(withIdentifier: identifier) as? MCMissionAddIconAnnotationView
            if annotationView == nil {
                annotationView = MCMissionAddIconAnnotationView(annotation: annotation, reuseIdentifier: identifier)
            }
            annotationView?.whenTap = {
                NotificationCenter.default.post(name: NSNotification.Name.addAnnotationViewDidTap, object: ((annotation as! MissionAddIconAnnotation).coordinate,
                                                                                                            (annotation as! MissionAddIconAnnotation).index,
                                                                                                            mapView))
            }
            return annotationView
        } else if annotation.isMember(of: MCMissionInterestingPointAnnotation.self) {
            let identifier = EarthStationViewModel.missionInterestingPointAnnotation
            var annotationView = mapView.dequeueReusableAnnotationView(withIdentifier: identifier) as? MCMissionInterestingPointAnnotationView
            if annotationView == nil {
                annotationView = MCMissionInterestingPointAnnotationView(annotation: annotation, reuseIdentifier: identifier)
            }
            return annotationView
        }
        return nil
    }
    
    func mapView(_ mapView: MKMapView, regionWillChangeAnimated animated: Bool) {
        
    }
    
    func mapView(_ mapView: MKMapView, regionDidChangeAnimated animated: Bool) {
        //Automatically retract and release the map logic according to the position of the aircraft
        if es_currentAircraftGPS != nil {
            if self.isAircraftInVisbleMapView(mapView) {
                //修改region 后飞机在可视范围内
                followAircrafte = true
            } else {
                //修改region 后飞机不在可视范围内
                followAircrafte = false
            }
        }
        
    }
}
