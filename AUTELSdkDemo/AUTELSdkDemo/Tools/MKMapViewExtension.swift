//
//  MKMapViewExtension.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/9.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation


extension MKMapView {
    open func views(for annotations: [MKAnnotation]) -> [MKAnnotationView] {
        return annotations.compactMap{view(for: $0)}
    }
}
