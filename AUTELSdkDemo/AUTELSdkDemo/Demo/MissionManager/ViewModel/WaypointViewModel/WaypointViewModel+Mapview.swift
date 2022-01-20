//
//  WaypointViewModel+Mapview.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/9.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation
// Map view
extension WaypointViewModel {
    
    func add(element missionStatus: MCMissionStatus, touchPoint: CGPoint, mapView: MKMapView) {
        switch missionStatus {
        case .addWaypoint:
            addWayPoint(touchPoint: touchPoint, mapView: mapView)
        case .addPointOfInterest:
            addPointOfInterest(touchPoint: touchPoint, mapView: mapView)
        default: break
        }
    }
    
    func mapView_clear(mapView: MKMapView) {
        mapView.removeAnnotations(WayPointManager.shared.addIconAnnotations)
        mapView.removeAnnotations(WayPointManager.shared.wayPoints.compactMap{$0.markAnnotation})
        mapView.removeOverlays(WayPointManager.shared.connectionLines)
        
        WayPointManager.shared.clear()
    }
    
    // Waypoint Actions
    func mapView_update_wayPointMarkAnnotationViewDidMoved(notification: Notification) {
        guard let object = notification.object as? (CLLocationCoordinate2D, Int, MKMapView) else { return }
        let coordinate = object.0
        let index = object.1
        let mapView = object.2
        
        mapView.removeOverlays(WayPointManager.shared.connectionLinesBackup)
        mapView.removeAnnotations(WayPointManager.shared.addIconAnnotationsBackup)
        WayPointManager.shared.updateWayPoint(coordinate: coordinate, index: index)
        mapView.addAnnotations(WayPointManager.shared.addIconAnnotations)
        mapView.addOverlays(WayPointManager.shared.connectionLines)
        
        WayPointManager.shared.select(index: index)
        mapView_reload_markAnnotationViewsSelectedState(mapView: mapView)
    }
    func mapView_update_addAnnotationViewDidTap(notification: Notification) {
        guard let object = notification.object as? (CLLocationCoordinate2D, Int, MKMapView) else { return }
        let coordinate = object.0
        let index = object.1
        let mapView = object.2
        
        mapView.removeOverlays(WayPointManager.shared.connectionLinesBackup)
        mapView.removeAnnotations(WayPointManager.shared.addIconAnnotationsBackup)
        mapView_removeWaypointMarkAnnotions(mapView: mapView)
        WayPointManager.shared.insert(wayPoint: WayPointModel(coordinate), at: index+1)
        mapView.addAnnotations(WayPointManager.shared.addIconAnnotations)
        mapView.addOverlays(WayPointManager.shared.connectionLines)
        mapView_addWaypointMarkAnnotions(mapView: mapView)
        mapView_updateLastSecond_textLable(mapView: mapView)
    }
    func mapView_update_wayPointMarkAnnotationViewDidTap(notification: Notification) {
        guard let object = notification.object as? (Int, MKMapView) else { return }
        let index = object.0
        let mapView = object.1
        WayPointManager.shared.select(index: index)
        mapView_reload_markAnnotationViewsSelectedState(mapView: mapView)
    }
    
    func addWayPoint(touchPoint: CGPoint, mapView: MKMapView) {
        let coordinateMap = mapView.convert(touchPoint, toCoordinateFrom: mapView)
        let wayPoint = WayPointModel(coordinateMap)
        
        WayPointManager.shared.append(wayPoint: wayPoint)
        mapView_addWayPointAnotion(wayPoint: wayPoint, mapView: mapView)
        mapView_updateLastSecond_textLable(mapView: mapView)
        
        mapView_updateConnectLines(mapView: mapView)
        mapView_updateAddIcons(mapView: mapView)
        
        WayPointManager.shared.select(waypoint: wayPoint)
        mapView_reload_markAnnotationViewsSelectedState(mapView: mapView)
    }
    
    // Waypoint Annotions
    func mapView_addWayPointAnotion(wayPoint: WayPointModel, mapView: MKMapView) {
        let wayPointMarkAnnotation = wayPoint.markAnnotation
        mapView.addAnnotation(wayPointMarkAnnotation)
    }
    
    func mapView_removeWaypointMarkAnnotions(mapView: MKMapView) {
        let markAnnotions = WayPointManager.shared.wayPoints.compactMap{$0.markAnnotation}
        mapView.removeAnnotations(markAnnotions)
    }
    
    func mapView_addWaypointMarkAnnotions(mapView: MKMapView) {
        let markAnnotions = WayPointManager.shared.wayPoints.compactMap{$0.markAnnotation}
        mapView.addAnnotations(markAnnotions)
    }

    private func mapView_annotionViews_wayPoint(mapView: MKMapView) -> [MKAnnotationView]{
        return mapView.views(for: WayPointManager.shared.wayPoints.compactMap{$0.markAnnotation})
    }
    
    func mapView_updateAddIcons(mapView: MKMapView) {
        mapView.removeAnnotations(WayPointManager.shared.addIconAnnotationsBackup)
        mapView.addAnnotations(WayPointManager.shared.addIconAnnotations)
    }
    
    // Waypoint connnectlines
    func mapView_updateConnectLines(mapView: MKMapView) {
        mapView.removeOverlays(WayPointManager.shared.connectionLinesBackup)
        mapView.addOverlays(WayPointManager.shared.connectionLines)
    }
    
    // Waypoint delete
    func mapView_remove_selectedElement(missinStatus: MCMissionStatus, mapView: MKMapView) {
        switch missionStatus {
        case .addWaypoint:
            mapView_remove_selectedWaypoint(mapView: mapView)
        case .addPointOfInterest:
            mapView_remove_selectedPOI(mapView: mapView)
        default: break
        }
    }
    
    func mapView_remove_selectedWaypoint(mapView: MKMapView) {
        mapView.removeAnnotations(WayPointManager.shared.wayPoints.compactMap{$0.markAnnotation})
        WayPointManager.shared.deleteSelectedWaypoint()
        mapView.addAnnotations(WayPointManager.shared.wayPoints.compactMap{$0.markAnnotation})
        mapView_updateConnectLines(mapView: mapView)
        mapView_updateAddIcons(mapView: mapView)
    }
    
    // Waypoint selected status
    func mapView_reload_markAnnotationViewsSelectedState(mapView: MKMapView) {
        mapView_annotionViews_wayPoint(mapView: mapView).enumerated().forEach{ (index, annotionView) in
            if annotionView.isSelected != WayPointManager.shared.wayPoints[index].isSelected {
                print("WayPoint index = \(index), WayPoint isSelected = \(WayPointManager.shared.wayPoints[index].isSelected)")
                annotionView.isSelected = WayPointManager.shared.wayPoints[index].isSelected
            }
        }
    }
    
    // Waypoint parameter
    func mapview_update_heightLable(waypoint index: Int?, mapView: MKMapView) {
        guard let index = index else {return }
        guard let markAnnotationView = mapView_annotionViews_wayPoint(mapView: mapView)[index] as? MCMarkAnnotationView else {return }
        markAnnotationView.stateChanged()
    }
    
    // Waypoint Last Second
    func mapView_updateLastSecond_textLable(mapView: MKMapView) {
        guard let lastSecondWayPoint = WayPointManager.shared.lastSecondWayPoint else {
            return
        }
        guard let wayPointMarkAnnotationView = mapView.view(for: lastSecondWayPoint.markAnnotation) as? MCMarkAnnotationView else {
            return
        }
        wayPointMarkAnnotationView.updateIndexText(lastSecondWayPoint.index + 1, false, false)
    }
    
   
    
    //MARK: - 兴趣点
    func addPointOfInterest(touchPoint: CGPoint, mapView: MKMapView) {
        let coordinateMap = mapView.convert(touchPoint, toCoordinateFrom: mapView)
        let poi = PointOfInterestModel(coordinateMap)
        WayPointManager.shared.append(poi: poi)
        
        mapView_addPOIAnotion(poi: poi, mapView: mapView)
    }
    
    func mapView_addPOIAnotion(poi: PointOfInterestModel, mapView: MKMapView) {
        let poiAnnotation = poi.markAnnotation
        mapView.addAnnotation(poiAnnotation)
    }
    
    func mapView_remove_selectedPOI(mapView: MKMapView) {
        mapView.removeAnnotations(WayPointManager.shared.pois.compactMap{$0.markAnnotation})
        WayPointManager.shared.deleteSelectedPOI()
        mapView.addAnnotations(WayPointManager.shared.pois.compactMap{$0.markAnnotation})
    }
}
