//
//  EarthStationViewModel+Draw.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/14.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation
/// Some Draw
extension EarthStationViewModel {
    /// Draw the flight path of the aircraft
    func drawRouteLine(aircraftCoordinate location:CLLocationCoordinate2D, droneState:AUTELMCSystemState!, mapView: MKMapView) {
        
        //Waypoint collection
        routeCoordinates.append(location)
        //Draw route
        routeLine = MKPolyline.init(coordinates: routeCoordinates, count: routeCoordinates.count)
        //Add route to the map
        let index = mapView.overlays.count - 1
        mapView.insertOverlay(routeLine!, at: index)
        //Route collection
        routeLines.append(routeLine!)
        //Remove the line of all points drawn last time, each time it is drawn to draw the line of all points, not the line of two points
        if routeLines.count > 1 {
            mapView.removeOverlay(routeLines.first!)
            routeLines.removeFirst()
        }
    }


    /// Draw the connection between the plane and the home point in real time
    func drawAircraftGoHomeLine(mapView: MKMapView) {

        if let currentAircraftGPS = es_currentAircraftGPS, let homeGPSForDisPlay = currentHomeGPS {
            
            if CLLocationCoordinate2DIsValid(currentAircraftGPS) && CLLocationCoordinate2DIsValid(homeGPSForDisPlay) {
                //绘制航线
                let coordinatesArr = [currentAircraftGPS,homeGPSForDisPlay]
                aircraftToHomeline = AutelAircraftToHomeLacationLine.init(coordinates: coordinatesArr, count: coordinatesArr.count)
                //在地图添加航线
                mapView.addOverlay(aircraftToHomeline!)
                //航线集合
                aircraftGoHomeRouteLines.append(aircraftToHomeline!)
                //移除第一条航线
                if aircraftGoHomeRouteLines.count>1 {
                    mapView.removeOverlay(aircraftGoHomeRouteLines.first!)
                    aircraftGoHomeRouteLines.removeFirst()
                }
            }
        }
    }
    
    //MARK: Draw a safety circle
    func drawSafeCircle(mapView: MKMapView) {
        if currentHomeGPS != nil {
//            if let maxFlightRadius = FlightLimitationService.shared.maxFlightRadius {
            createSafeCircle(homeLocation: currentHomeGPS!, radius: Double(500), mapView: mapView)//500 is the test data, actually read from the aircraft
//            }
        }
    }
    
    func createSafeCircle(homeLocation: CLLocationCoordinate2D, radius: CLLocationDistance, mapView: MKMapView) {
        //if mapView != nil {
           if  safeCircle != nil {
                mapView.removeOverlay(safeCircle!)
                safeCircle = nil
            }
            if( radius > 9998) {
                return
            }
          //  let correctedCoordinate = coordinateCorrectIfNeeded(homeLocation)
            safeCircle = AircraftSafeCircle(center: homeLocation, radius: radius)
            if safeCircle != nil {
                mapView.addOverlay(safeCircle!)
            }
        //}
    }
}
