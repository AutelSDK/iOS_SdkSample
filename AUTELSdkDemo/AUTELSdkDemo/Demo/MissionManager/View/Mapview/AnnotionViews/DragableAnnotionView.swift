//
//  DragableAnnotionView.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/7.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

class DragableAnnotionView: MKAnnotationView {
    
    private var timer: GCDTimer?
    private var lastLocation: CGPoint = .zero
    var whenMoveTo: ((CGPoint) -> ())?
    var whenTap: (() -> ())?
    
    override init(annotation: MKAnnotation?, reuseIdentifier: String?) {
        super.init(annotation: annotation, reuseIdentifier: reuseIdentifier)
        setupPanGesture()
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func setupPanGesture() {
        // 添加滑动手势
        let panGesture = UIPanGestureRecognizer.init(target: self, action: #selector(panGestureAction(_:)))
        self.addGestureRecognizer(panGesture)
        let tapGesture = UITapGestureRecognizer.init(target: self, action: #selector(tapGestureAction(_:)))
        self.addGestureRecognizer(tapGesture)
    }
    
    @objc private func tapGestureAction(_ recognizer: UITapGestureRecognizer) {
        whenTap?()
    }
    
    @objc private func panGestureAction(_ recognizer: UIPanGestureRecognizer) {
        let translation  = recognizer.translation(in: self.superview)
        let point = CGPoint(x: lastLocation.x + translation.x, y: lastLocation.y + translation.y)
        self.whenMoveTo?(point)
    }
    
    override func touchesBegan(_ touches: (Set<UITouch>?), with event: UIEvent!) {
        // 记住原来的位置
        lastLocation = self.center
    }
}
