
//  AutelAircraftAnnotationView.swift
//  AutelGen2
//  Created by autel_ivan on 2017/10/23.
//  Copyright © 2017年 AUTEL. All rights reserved.

import UIKit
import MapKit

class AutelAircraftAnnotationView: MKAnnotationView {

    func updateHeading(heading:Float) {
        self.transform = CGAffineTransform.identity;
        self.transform = CGAffineTransform.init(rotationAngle: CGFloat(heading));
    }
    
    func updateHeading(heading: Float, in mapView: MKMapView) {
        let mapCamaraHeading = mapView.camera.heading
        var mapOffsetHeading: Double = 0
        if mapCamaraHeading > 180 {
            mapOffsetHeading = (360 - mapCamaraHeading)*Double.pi/180
        } else {
            mapOffsetHeading = -mapCamaraHeading*Double.pi/180
        }
        updateHeading(heading: heading + Float(mapOffsetHeading))
    }
    
    override init(annotation: MKAnnotation?, reuseIdentifier: String?) {
        super.init(annotation: annotation, reuseIdentifier: reuseIdentifier)
        self.isEnabled = false
        self.isDraggable = false
        self.image = UIImage.init(named: "map_icon_aircraft")
        self.isUserInteractionEnabled = false
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
