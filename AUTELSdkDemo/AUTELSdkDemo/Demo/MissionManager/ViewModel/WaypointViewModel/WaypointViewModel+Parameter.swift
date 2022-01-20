//
//  WaypointViewModel+Parameter.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/10.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation
// Parameter
extension WaypointViewModel {
    class func getSpeed(at index: Int) -> (value: String, text: String) {
        let value = WayPointManager.shared.selectedWaypoint?.speed ?? 60
        let text = getTextByUnitSystem(value:value, unit: "m")
        return (value.formatf(format: "%f"), text)
    }
    
    class func set(speed: Float, at index: Int) {
        WayPointManager.shared.selectedWaypoint?.speed = speed
    }
    
    class func getHeight(at index: Int) -> (value: String, text: String) {
        let value = WayPointManager.shared.selectedWaypoint?.height ?? 60
        let text = getTextByUnitSystem(value:value, unit: "m")
        return (value.formatf(format: "%f"), text)
    }
    class func set(height: Float, at index: Int) {
        WayPointManager.shared.selectedWaypoint?.height = height
    }
    
    class func set(coordinate: CLLocationCoordinate2D) {
        WayPointManager.shared.selectedWaypoint?.coordinate = coordinate
    }
}

func getTextByUnitSystem(value: Float, format: String = "", unit: String = "") -> String {
    var unitType: MCUnitType = .other
    if unit == "m" {
        unitType = .lenght
    } else if unit == "m/s" {
        unitType = .speed
    } else {
        unitType = .other
    }
    return showTextByUnitSystem(value: value, format: format, unitType: unitType, unit: unit)
}

