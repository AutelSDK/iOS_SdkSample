//
//  MCMarkAnnotationView.swift
//  AutelGen2
//
//  Created by Autel-xufeng on 2019/9/29.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import UIKit

class MCMarkAnnotationView: DragableAnnotionView, UIGestureRecognizerDelegate {

    lazy var capLabel: UILabel = {
        let label = UILabel()
        label.textAlignment = NSTextAlignment.center
        label.font = UIFont.systemFont(ofSize: 10)
        label.textColor = UIColor.white
        label.backgroundColor = UIColor.black.withAlphaComponent(0.7)
        label.layer.cornerRadius = 2.0
        label.clipsToBounds = true
        self.addSubview(label)
        label.snp.makeConstraints({ (maker) in
            maker.centerX.equalToSuperview()
            maker.height.equalTo(20)
            maker.width.equalTo(50)
            maker.top.equalToSuperview().offset(-26)
        })
        return label
     }()
    
    private lazy var indexLabel: UILabel = {
        let label = UILabel(frame: .zero)
        label.textAlignment = NSTextAlignment.center
        label.font = UIFont.systemFont(ofSize: 14)
        label.textColor = UIColor.white
        
        self.addSubview(label)
        label.snp.makeConstraints({ (maker) in
            maker.centerX.equalToSuperview()
            maker.centerY.equalToSuperview().offset(-7.0)
        })
        return label
    }()

    private lazy var headingImageView: UIImageView = {
        let imageView = UIImageView()
        //imageView.backgroundColor = UIColor.blue.withAlphaComponent(0.5)
        imageView.image = UIImage(named: "map_icon_angle")
        self.addSubview(imageView)
        let size = imageView.image!.size
        let sizeold = CGSize.init(width: 54, height: 60)
        imageView.snp.makeConstraints { (make) in
           // make.center.equalToSuperview()
            make.size.equalTo(sizeold)
            make.centerX.equalToSuperview()
            make.centerY.equalToSuperview().offset(10)
//            make.top.equalTo(self.snp.bottom).offset(-3rr0)
        }
        return imageView
    }()

    private lazy var cameraActionImageView: UIImageView = {
        let imageView = UIImageView()
        self.headingImageView.addSubview(imageView)
        imageView.snp.makeConstraints { (make) in
            make.center.equalToSuperview()
            make.width.height.equalTo(16)
        }
        return imageView
    }()
    
    private var handleRectOffRatio: CGPoint = CGPoint.zero
    
    override init(annotation: MKAnnotation?, reuseIdentifier: String?) {
        super.init(annotation: annotation, reuseIdentifier: reuseIdentifier)
        isDraggable = false
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override var annotation: MKAnnotation? {
        didSet {
            updateAnnotationIfNeeded()
        }
    }
    
    override var isSelected: Bool {
        didSet {
            stateChanged()
        }
    }
    
    func stateChanged() {
        guard let markAnnotation = annotation as? MissionMarkPointAnnotation else { return }
        if markAnnotation.isCircleIcon {
            capLabel.isHidden = true
            indexLabel.isHidden = true
            headingImageView.isHidden = true
            cameraActionImageView.isHidden = true
            if markAnnotation.isHidden {
                image = nil
            } else {
              updateMarkImage(false)
            }
        } else {
            capLabel.isHidden = false
            indexLabel.isHidden = false
            headingImageView.isHidden = false
            cameraActionImageView.isHidden = false
            sendSubviewToBack(headingImageView)
            updateMarkImage(true)
            updateCapValue(markAnnotation.capValue)
            updateHeading(markAnnotation.headingAngle)
            updateCameraAction(markAnnotation.cameraAction,
                               markAnnotation.headingAngle)
        }
        if markAnnotation.isPolygonSE {
            capLabel.isHidden = true
            indexLabel.isHidden = true
            headingImageView.isHidden = true
            cameraActionImageView.isHidden = true
            updateMarkImage(true)
        }

        if markAnnotation.isBreakPoint {
            capLabel.isHidden = true
            indexLabel.isHidden = true
            headingImageView.isHidden = true
            cameraActionImageView.isHidden = true
            updateBreakPointMarkImage()
        }
        
        updateContenOff()
        
    }
    
    /// 更新飞机朝向
    private func updateHeading(_ headingAngle: CGFloat) {
        headingImageView.layer.transform = CATransform3DIdentity
        let rotation = CATransform3DRotate(CATransform3DIdentity,
                                           headingAngle,
                                           0,
                                           0,
                                           1)
        let translation = CATransform3DTranslate(rotation, 0, -height, 0)
        headingImageView.layer.transform = translation
    }
    
    
    private func updateCameraAction(_ cameraAction: CameraAction,
                                    _ headingAngle: CGFloat) {
        if cameraAction == .takePhoto {
            cameraActionImageView.image = UIImage(named: "map_icon_takephoto")
        } else if cameraAction == .recordVideo {
            cameraActionImageView.image = UIImage(named: "map_icon_startrecord")
        } else if cameraAction == .stopRecordVideo {
            cameraActionImageView.image =  UIImage(named: "map_icon_stoprecord")
        } else {
            cameraActionImageView.image = nil
        }
        updateCameraHeading(headingAngle)
    }
    
    private func updateCameraHeading(_ headingAngle: CGFloat) {
        cameraActionImageView.layer.transform = CATransform3DIdentity
        let rotation = CATransform3DRotate(CATransform3DIdentity,
                                           -headingAngle, 0, 0, 1)
        cameraActionImageView.layer.transform = rotation
    }
    
    private func updateMarkImage(_ isWaypoint: Bool) {
        if isWaypoint {
            if isSelected {
                image = UIImage(named: "map_btn_waypoint_pre")
                indexLabel.font = UIFont.systemFont(ofSize: 18)
            } else {
                image = UIImage(named: "map_btn_waypoint_def")
                indexLabel.font = UIFont.systemFont(ofSize: 14)
            }
        } else {
            if isSelected {
                image = UIImage(named: "map_btn_coordinates_sel")
            } else {
                image = UIImage(named: "map_btn_coordinates_def")
            }
        }
    }
    
    private func updateBreakPointMarkImage() {
        image = UIImage.init(named: "breakPointIcon")
//        indexLabel.font = UIFont.font(ofType: ATFontCN.semibold, ofSize: 14)

    }
    
    func updateAnnotationIfNeeded() {
        guard let markAnnotation = annotation as? MissionMarkPointAnnotation else { return }
        isSelected = markAnnotation.isSelected
        indexLabel.isHidden = markAnnotation.isIndexLabHidden || markAnnotation.isBreakPoint
        let isLast = markAnnotation.isLast
        if !markAnnotation.isIndexLabHidden {
            updateIndexText(markAnnotation.index + 1, isLast)
        }
        
        if markAnnotation.isBreakPoint {
            capLabel.isHidden = true
            indexLabel.isHidden = true
            headingImageView.isHidden = true
            cameraActionImageView.isHidden = true
            updateBreakPointMarkImage()
        }
        
        updateContenOff()
        
//        self.backgroundColor = UIColor.gray.withAlphaComponent(0.3)
    }
    
    func updateIndexText(_ index: Int, _ isLast: Bool = false, _ hiddenCameraAction: Bool = false) {
        if index == 1 {
            indexLabel.text = "S"
        } else if isLast == true || index == 0 {
            indexLabel.text = "E"
        } else {
            indexLabel.text = "\(index)"
        }
        if hiddenCameraAction {
            headingImageView.isHidden = true
            cameraActionImageView.isHidden = true
            capLabel.isHidden = true
        }
    }
    
    private func updateCapValue(_ value: Float) {
        
        let text = "A: " + "\(value)"
    
        let att = NSMutableAttributedString(string: text)
        att.addAttribute(NSAttributedString.Key.foregroundColor,
                         value: UIColor.lightGray,
                         range: NSMakeRange(0, 2))
        att.addAttribute(NSAttributedString.Key.foregroundColor,
                                value: UIColor.white,
                                range: NSMakeRange(2,
                                                   att.length - 2))
        att.addAttribute(NSAttributedString.Key.font,
                                value: UIFont.systemFont(ofSize: 10),
                                range: NSMakeRange(0, att.length))
        capLabel.attributedText = att
    }
    
    
    private func updateContenOff() {
        guard let markAnnotation = annotation as? MissionMarkPointAnnotation else { return }
        
        var needRectOffRatio = CGPoint.zero
        var needOff = true
        if markAnnotation.isCircleIcon {
            needOff = false
        }
        if markAnnotation.isBreakPoint {
            needOff = false
        }
        if needOff {
             needRectOffRatio = CGPoint.init(x: 0, y: 0.5)
        }
        
        if needRectOffRatio.equalTo(handleRectOffRatio) {
            return
        }
        
        let off = CGPoint.init(x: needRectOffRatio.x, y: needRectOffRatio.y)
        var size : CGSize = self.size
        if let image = self.image {
            size = image.size // self.size == image.size 在这种 mark 里面 自适应图片大小
        }
        self.centerOffset.y = -(size.height * off.y)
        handleRectOffRatio = needRectOffRatio
    }
}
