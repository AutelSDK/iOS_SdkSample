//
//  AutelAircraftAnnotation.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet Argo on 2020/5/10.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit
import MapKit

class AutelAircraftAnnotation: NSObject,MKAnnotation {
    dynamic var coordinate: CLLocationCoordinate2D = CLLocationCoordinate2D.init()
    
    init(coordinate:CLLocationCoordinate2D) {
        self.coordinate = coordinate
        super.init()
    }
    
    func setCoordinate(coordinate:CLLocationCoordinate2D) {
        self.coordinate = coordinate
    }
}
