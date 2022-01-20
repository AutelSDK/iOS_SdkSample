//
//  MissionAddIconAnnotationView.swift
//  AutelGen2
//
//  Created by Autel-iOS on 2019/4/24.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import UIKit

class MCMissionAddIconAnnotationView: DragableAnnotionView {
    
    override init(annotation: MKAnnotation?, reuseIdentifier: String?) {
        super.init(annotation: annotation, reuseIdentifier: reuseIdentifier)
        isDraggable = false
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override var annotation: MKAnnotation? {
        didSet {
            loadAnnotationIfNeeded()
        }
    }
    
    func loadAnnotationIfNeeded() {
        guard let addAnno = annotation as? MissionAddIconAnnotation else { return }
        if addAnno.isHidden {
            image = nil
        } else {
            let imageName = "map_btn_ad_def"
            image = UIImage.init(named: imageName)
        }
    }
}

