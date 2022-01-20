//
//  AutelHomeAnnotationView.swift
//  AutelGen2
//
//  Created by autel_ivan on 2017/10/23.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import UIKit
import MapKit

class AutelHomeAnnotationView: MKAnnotationView {

    override init(annotation: MKAnnotation?, reuseIdentifier: String?) {
        super.init(annotation: annotation, reuseIdentifier: reuseIdentifier)
        
        self.isEnabled = false
        self.isDraggable = false
        self.image = UIImage.init(named: "map_btn_homepoint_def")
        self.centerOffset = CGPoint.init(x: 0, y: -CGFloat((self.image?.size.height)!/2))
        self.isUserInteractionEnabled = false
        
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
}
