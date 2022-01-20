//
//  WayPointManager.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/6.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

class WayPointManager: NSObject {
    static let shared = WayPointManager()
    
    // Waypoint
    var wayPoints: [WayPointModel] = []
    
    // AddIcons
    var addIconAnnotations: [MissionAddIconAnnotation] {
        let addIconAnnotions = getAddIconAnnotations()
        addIconAnnotationsBackup = addIconAnnotions
        return addIconAnnotions
    }
    var addIconAnnotationsBackup: [MissionAddIconAnnotation] = []
    
    // Connected line
    var connectionLines: [MissionConnectionLine] {
        let lines = getConnectionLines()
        connectionLinesBackup = lines
        return lines
    }
    var connectionLinesBackup: [MissionConnectionLine] = []
    
    
    // SelectedItem
    var lastSecondWayPoint: WayPointModel? {
        return wayPoints.first(where: { wayPoint in
            return wayPoint.index == wayPoints.count - 2
        })
    }
    
    var selectedWaypoint: WayPointModel? {
        return wayPoints.first { wayPointModel in
            wayPointModel.isSelected
        }
    }
    var selectedWaypointIndex: Int? {
        return selectedWaypoint?.index
    }
    
    // POI
    var pois: [PointOfInterestModel] = []
    var selectedPOI: PointOfInterestModel? {
        return pois.first { pointOfInterestModel in
            pointOfInterestModel.isSelected
        }
    }
    var selectedPOIIndex: Int? {
        return selectedPOI?.index
    }
    
    //MARK: - Core
    func clear() {
        clearWayPoints()
        clearPOIs()
    }
    
    func clearPOIs() {
        pois = []
    }
    
    func clearWayPoints() {
        wayPoints = []
        addIconAnnotationsBackup = []
        connectionLinesBackup = []
    }
    
    //MARK: Way points
    func append(wayPoint point: WayPointModel) {
        wayPoints.append(point)
        configWayPointModel()
    }

    func insert(wayPoint point: WayPointModel, at index: Int) {
        guard index < wayPoints.count else {
            return
        }
        wayPoints.insert(point, at: index)
        configWayPointModel()
    }

    func deleteSelectedWaypoint() {
        guard let selectedWaypointIndex = selectedWaypointIndex else { return }
        delete(wayPoint: selectedWaypointIndex)
        configWayPointModel()
    }

    func delete(wayPoint index: Int) {
        guard index < wayPoints.count else {
            return
        }
        wayPoints.remove(at: index)
    }

    func updateWayPoint(coordinate: CLLocationCoordinate2D, index: Int) {
        guard index < wayPoints.count else {
            return
        }
        wayPoints[index].coordinate = coordinate
    }


    func replace(wayPoint point: WayPointModel, index: Int) {
        wayPoints.remove(at: index)
        wayPoints.insert(point, at: index)
    }

    func select(index: Int) {
        wayPoints.forEach{
            if $0.isSelected == true {
                $0.isSelected = false
            }
        }
        wayPoints[index].isSelected = true
    }
    
    func select(waypoint: WayPointModel) {
        wayPoints.forEach{
            if $0.isSelected == true {
                $0.isSelected = false
            }
        }
        waypoint.isSelected = true
    }
    
    //MARK: POI
    func append(poi point: PointOfInterestModel) {
        pois.append(point)
        configPOIModel()
    }

    func deleteSelectedPOI() {
        guard let selectedIndex = selectedWaypointIndex else { return }
        delete(wayPoint: selectedIndex)
    }

    func delete(poi index: Int) {
        guard index < pois.count else {
            return
        }
        pois.remove(at: index)
    }

    func updatePOI(coordinate: CLLocationCoordinate2D, index: Int) {
        guard index < pois.count else {
            return
        }
        pois[index].coordinate = coordinate
    }


    func replace(poi point: PointOfInterestModel, index: Int) {
        pois.remove(at: index)
        pois.insert(point, at: index)
    }

    func selectPOI(index: Int) {
        pois.forEach{
            if $0.isSelected == true {
                $0.isSelected = false
            }
        }
        pois[index].isSelected = true
    }
    
    
    //MARK: - Private
    private func getAddIconAnnotations() -> [MissionAddIconAnnotation] {
        var addIconAnnotations: [MissionAddIconAnnotation] = []
        wayPoints.enumerated().forEach { (index, element) in
            guard  index < wayPoints.count - 1 else { return }
            let coordinate1 = wayPoints[index].coordinate
            let coordinate2 = wayPoints[index+1].coordinate
            let addIconAnnotation = MissionAddIconAnnotation()
            addIconAnnotation.index = index
            addIconAnnotation.coordinate = CLLocationCoordinate2D(latitude: (coordinate1.latitude + coordinate2.latitude)*0.5,
                                                                  longitude: (coordinate1.longitude + coordinate2.longitude)*0.5)
            addIconAnnotations.append(addIconAnnotation)
        }
        return addIconAnnotations
    }
    
    private func getConnectionLines() -> [MissionConnectionLine] {
        var connectionLines: [MissionConnectionLine] = []
        wayPoints.enumerated().forEach { (index, element) in
            guard  index < wayPoints.count - 1 else { return }
            let coordinate1 = wayPoints[index].coordinate
            let coordinate2 = wayPoints[index+1].coordinate
            connectionLines.append(MissionConnectionLine(coordinates: [coordinate1, coordinate2], count: 2))
        }
        return connectionLines
    }
    
    private func configWayPointModel() {
        wayPoints.enumerated().forEach { (index, item) in
            item.index = index
            item.markAnnotation.index = index
        }
        updateIsLast()
    }
    
    private func updateIsLast() {
        wayPoints.forEach { item in
            item.markAnnotation.isLast = false
        }
        wayPoints.last?.markAnnotation.isLast = true
    }
    
    private func configPOIModel() {
        pois.enumerated().forEach { (index, item) in
            item.index = index
            item.markAnnotation.index = index
        }
    }
}
