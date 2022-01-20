//
//  PointOfInterestModel.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/14.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

class PointOfInterestModel: NSObject {
    var coordinate: CLLocationCoordinate2D {
        didSet {
            markAnnotation.coordinate = coordinate
        }
    }
    var index: Int = 0
    
    var markAnnotation = MCMissionInterestingPointAnnotation()
    
    var isSelected = false
    
    init(_ coordinate: CLLocationCoordinate2D) {
        self.coordinate = coordinate
        super.init()
        
        markAnnotation.coordinate = coordinate
    }
}
