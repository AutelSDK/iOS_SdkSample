//
//  EarthStationViewController+MainControl.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/14.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

extension EarthStationViewController: MainControllerProtocol {
    
    //Aircraft status information callback, called once every 0.2 seconds
    @objc func mainController(_ mc: AUTELDroneMainController!, didUpdate state: AUTELMCSystemState!) {
        
        vm.lastDroneYaw = state.attitude.yaw
        //Save the current height value
        vm.es_currentDroneAltitude = state.altitude

        
        //Determine whether the home point coordinate returned by the aircraft is feasible
        if CLLocationCoordinate2DIsValid(state.homeLocation) && state.homeLocation.latitude != 0.0 && state.homeLocation.longitude != 0.0 {
            
            if vm.homeAnnotation == nil {
                vm.currentHomeGPSNoCalibrared = state.homeLocation
                if vm.isMapCalibrared {
                    vm.currentHomeGPS = MapCorrect.wgs2gcj(with: state.homeLocation)
                } else {
                    vm.currentHomeGPS = state.homeLocation
                }
                //The first time the home point is displayed on the map
                vm.homeAnnotation = AutelHomeAnnotation(coordinate:(vm.currentHomeGPS!))
                DispatchQueue.main.async {
                    self.mapView.addAnnotation((self.vm.homeAnnotation!))
                    self.vm.drawSafeCircle(mapView: self.mapView)
                }
            } else {
                
                let lat = state.homeLocation.latitude
                let long = state.homeLocation.longitude
                let latDev = fabs(lat-(vm.currentHomeGPSNoCalibrared?.latitude)!)
                let longDev = fabs(long-(vm.currentHomeGPSNoCalibrared?.longitude)!)
                if ((latDev > 0.000001) || (longDev > 0.000001)) {
                    //Deviations can update the interface
                    //Correction coordinates currentCoordinate for map display
                    var currentHomeCoordinate:CLLocationCoordinate2D = state.homeLocation
                    if (vm.isMapCalibrared) {
                        currentHomeCoordinate = MapCorrect.wgs2gcj(with:currentHomeCoordinate)
                    } else {
                        currentHomeCoordinate = state.homeLocation
                    }
                    
                    vm.currentHomeGPSNoCalibrared = state.homeLocation
                    vm.currentHomeGPS = currentHomeCoordinate
                    DispatchQueue.main.async {
                        print("更新homeAnniation")
                        self.mapView.removeAnnotation(self.vm.homeAnnotation!)
                        self.vm.homeAnnotation = AutelHomeAnnotation(coordinate:(self.vm.currentHomeGPS)!)
                        self.mapView.addAnnotation(self.vm.homeAnnotation!)
                        
                        self.vm.drawSafeCircle(mapView: self.mapView)
                    }
                }
            }
        }
        
        //Judge the validity of the returned aircraft coordinates and handle the status of the aircraft
        if CLLocationCoordinate2DIsValid(state.droneLocation) {
            
            let droneLocation:CLLocationCoordinate2D = state.droneLocation;
            vm.es_currentAircraftGPSNoCalibrared = state.droneLocation
            
            if vm.isMapCalibrared {
                vm.es_currentAircraftGPS = MapCorrect.wgs2gcj(with: droneLocation)
            } else {
                vm.es_currentAircraftGPS = droneLocation
            }

            if (vm.aircraftAnnotation == nil) {
                var region:MKCoordinateRegion = MKCoordinateRegion()
                region.center = vm.es_currentAircraftGPS!
                region.span.latitudeDelta = 0.001
                region.span.longitudeDelta = 0.001
                self.vm.aircraftAnnotation = AutelAircraftAnnotation(coordinate: self.vm.es_currentAircraftGPS!)
                self.vm.lastAircraftCoordination = droneLocation
                DispatchQueue.main.async {
                    if let aircraft = self.vm.aircraftAnnotation {
                        self.mapView.addAnnotation(aircraft)
                    }
                    self.mapView.setRegion(region, animated: true)
                    //Draw the connection between the plane and the home point in real time
                    self.vm.drawAircraftGoHomeLine(mapView: self.mapView)
                    //Real-time drawing of aircraft routes
                    self.vm.drawRouteLine(aircraftCoordinate: self.vm.es_currentAircraftGPS! ,droneState: state, mapView: self.mapView)
                    
                }
            }
            
            //Update aircraftView position and orientation
            let annotationView:AutelAircraftAnnotationView? = (self.mapView.view(for: vm.aircraftAnnotation!)) as? AutelAircraftAnnotationView
            if annotationView != nil {
                
                DispatchQueue.main.async {
                    //                    self.aircraftAnnotation?.coordinate = (es_currentAircraftGPS!)
                    annotationView?.updateHeading(heading: state.attitude.yaw)
//                    if droneLocation.distanceWith(self.lastAircraftCoordination) >= 0.2 && self.ignorUpdateAnnotationTimes >= 5 {
                    self.vm.lastAircraftCoordination = droneLocation
                    self.vm.aircraftAnnotation?.coordinate = (self.vm.es_currentAircraftGPS!)
                        //Draw the connection between the plane and the home point in real time
                    self.vm.drawAircraftGoHomeLine(mapView: self.mapView)
                        //Real-time drawing of aircraft routes
                    self.vm.drawRouteLine(aircraftCoordinate: self.vm.es_currentAircraftGPS! ,droneState: state, mapView: self.mapView)
                        //Determine whether the aircraft is within the flight range and zoom the map
                        
//                        self.ignorUpdateAnnotationTimes = 0
//                    } else {
//                        self.ignorUpdateAnnotationTimes += 1
//                    }
                }
            } else {
                //annotationView view 等于 nil
            }
  
            DispatchQueue.main.async {
                //                    //实时绘制飞机与home点连线
                //                    self.drawAircraftGoHomeLine()
                //                    //实时绘制飞机航线
                //                    self.drawRouteLine(aircraftCoordinate: es_currentAircraftGPS!)
                //Determine whether the aircraft is within the flight range and zoom the map
                self.vm.checkAircraftInVisbleMapView(currentDroneCoordinate: self.vm.es_currentAircraftGPS!)
//                    self.disPlayCoordinate(coordinateType:self.currentCoordinateType)
                //更新home点图标
            }
            
            //The current position of the aircraft from the center of the map
            let distanceFilter:CLLocationDistance = self.calculateDistanceBetweenPoint(point1:droneLocation, point2: mapView.centerCoordinate)
            
            //If the ground station is in a small view, the aircraft point is located
            if distanceFilter > 20 {
                DispatchQueue.main.async {
//                    if let aircraftCoord = self.vm.es_currentAircraftGPS {
//                        let region = MKCoordinateRegion(center: aircraftCoord,
//                                                        span: MKCoordinateSpan(latitudeDelta: self.mapView.region.span.latitudeDelta,
//                                                                               longitudeDelta: self.mapView.region.span.longitudeDelta))
//                        self.mapView.setRegion(region, animated: false)
//                    }
                }
            }
            
        } else {
            
            DispatchQueue.main.async {
                if let aircraft = self.vm.aircraftAnnotation {
                    self.mapView.removeAnnotation(aircraft)
                    self.vm.aircraftAnnotation = nil
                }
                //There is a problem with the returned aircraft coordinates
                guard let aAnnotation = self.vm.aircraftGPSCircle else {
                    return
                }
                
                self.mapView.removeAnnotation(aAnnotation)
                self.vm.aircraftAnnotation = nil
            }
        }
    }
    
    fileprivate func calculateDistanceBetweenPoint(point1:CLLocationCoordinate2D, point2:CLLocationCoordinate2D)-> CLLocationDistance {
        let locaiton1:CLLocation = CLLocation.init(latitude: point1.latitude, longitude: point1.longitude)
        let location2:CLLocation = CLLocation.init(latitude: point2.latitude, longitude: point2.longitude)
        return locaiton1.distance(from: location2)
    }
}
