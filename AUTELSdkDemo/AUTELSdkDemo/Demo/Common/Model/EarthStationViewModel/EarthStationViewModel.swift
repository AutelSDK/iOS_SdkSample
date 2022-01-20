//
//  EarthStationView.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet Argo on 2020/5/10.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation

class EarthStationViewModel: NSObject {
    
    //手机设备坐标，已纠偏
    var es_deviceCoordinate:CLLocationCoordinate2D?
    //当前飞机坐标，已纠偏
    var es_currentAircraftGPS:CLLocationCoordinate2D?
    //手机设备坐标，未纠偏,真实坐标
    var es_deviceCoordinateNoCalibrared:CLLocationCoordinate2D?
    //当前飞机坐标，未纠偏
    var es_currentAircraftGPSNoCalibrared:CLLocationCoordinate2D?
    //当前飞机相对起点高度
    var es_currentDroneAltitude:Float?
    
    
    var isMapCalibrared:Bool {
        get {
            return isMapNeedCorrect
        }
    }
    
    // MARK: - Const
    static let aircraftReuseIdentifier:String               = "AIRCRAFT_ANNOTATION_VIEW"
    static let homeReuseIdentifier:String                   = "HOME_ANNOTATION_VIEW"
    static let mcWaypointReuseIdentifier                    = "MCMissionWaypointReuseIdentifier"
    static let missionAddIconReuseIdentifier                = "MissionAddIconReuseIdentifier"
    static let missionInterestingPointAnnotation            = "MCMissionInterestingPointAnnotation"
    
    // MARK: -
    
    /// aircraft Mark
    var aircraftAnnotation:AutelAircraftAnnotation?
    /// home Mark, Corrected
    var homeAnnotation:AutelHomeAnnotation?
    
    ///red line between aircraft and home
    var aircraftToHomeline:AutelAircraftToHomeLacationLine?
    
    var aircraftGPSCircle: AircraftGPSCircle?
    
    var aircraftGoHomeRouteLines:Array<MKPolyline> = Array()
    
    ///set  flight path
    var routeLines:Array<MKPolyline> = Array()
    var routeCoordinates:Array<CLLocationCoordinate2D> = Array()
    /// flight path
    var routeLine: MKPolyline?
    
   
    var safeCircle: AircraftSafeCircle?
    /// The current device returns to home coordinates and has been corrected
    var currentHomeGPS:CLLocationCoordinate2D?
    ///The current device returns to home real coordinates without correction
    var currentHomeGPSNoCalibrared:CLLocationCoordinate2D?

    var pathColor:UIColor = UIColor.init(red: 99, green: 195, blue: 198, alpha: 0.25)
    ///Current heading
    var currentHeading:CLHeading?
    
    var followAircrafte:Bool = true
    /// Store the last point of the aircraft
    var lastAircraftCoordination: CLLocationCoordinate2D = CLLocationCoordinate2D(latitude: 0.0, longitude: 0.0)
    var lastDroneYaw: Float = 0.0
    
    
    // MARK: - Funs
    func isAircraftInVisbleMapView(_ mapView: MKMapView)->Bool {
        //飞机真实位置转换为地图上点位置
        let mapPoint:MKMapPoint = MKMapPoint.init(es_currentAircraftGPS!)
        //        print("mapPoint = \(mapPoint)")
        
        //地图可视范围转换为mapRect
        let mapRect:MKMapRect = mapView.visibleMapRect
        //        print("mapRect =\(mapRect)")
        
        //判断点是否在地图可视范围内
        let isContain:Bool = mapRect.contains(mapPoint)
        //        print("isContains = \(isContain)")
        return isContain
    }
    
    func checkAircraftInVisbleMapView(currentDroneCoordinate coordinate:CLLocationCoordinate2D) {
//        if self.isAircraftInVisbleMapView() {
//
//        } else {
////            print("飞机飞出去了")
//        if followAircrafte {
//            let centerCoordinate:CLLocationCoordinate2D = mapView.convert(mapView.center, toCoordinateFrom: mapView)
//            let zoomLevel:Double = mapView.getZoomLevel()
//            mapView.as_setCenterCoordinate(centerCoordinate: centerCoordinate, zoomLevel: (zoomLevel - 0.5), animated: true)}
//        }
    }
}
