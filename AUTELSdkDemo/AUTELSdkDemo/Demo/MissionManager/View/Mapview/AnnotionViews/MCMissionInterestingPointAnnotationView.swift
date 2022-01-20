//
//  MCMissionInterestingPointAnnotationView.swift
//  AutelGen2
//
//  Created by Autel-xufeng on 2019/10/11.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import Foundation

/// 兴趣点View
class MCMissionInterestingPointAnnotationView: MKAnnotationView {

    private lazy var indexLabel: UILabel = {
        let label = UILabel(frame: .zero)
        label.textAlignment = NSTextAlignment.center
        label.font = UIFont.systemFont(ofSize: 14)
        label.textColor = UIColor.white

        self.addSubview(label)
        label.snp.makeConstraints({ (maker) in
          maker.centerX.equalToSuperview()
          maker.centerY.equalToSuperview().offset(-6.0)
        })
        return label
    }()
    
    override init(annotation: MKAnnotation?, reuseIdentifier: String?) {
        super.init(annotation: annotation, reuseIdentifier: reuseIdentifier)
        isDraggable = false
        steupView()
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override var annotation: MKAnnotation? {
        didSet {
            updateAnnotationIfNeeded()
        }
    }
    
    func steupView() {
        // pxx 更改兴趣点标记与兴趣点对位问题
        self.image = UIImage(named: "map_btn_poi_def")
        if let imageNew = self.image
        {
            let size : CGSize = imageNew.size
            self.centerOffset.y = -(size.height/2.0)
        }
    }
    override var isSelected: Bool {
        didSet {
            selectStateChanged()
        }
    }
    
    func updateAnnotationIfNeeded() {
        guard let markAnnotation = annotation as? MCMissionInterestingPointAnnotation else { return }
        isSelected = markAnnotation.isSelected
        updateIndex(markAnnotation.index + 1)
    }
    
    func selectStateChanged() {
        guard let _ = annotation as? MCMissionInterestingPointAnnotation else { return }
        if isSelected {
            image = UIImage(named: "map_btn_poi_pre")
            indexLabel.font = UIFont.systemFont(ofSize: 14)
        } else {
            image = UIImage(named: "map_btn_poi_def")
            indexLabel.font = UIFont.systemFont(ofSize: 14)
        }
    }
    
    func updateIndex(_ index: Int) {
        indexLabel.text = "\(index)"
    }
}
