//
//  SubMenuLongAndLatEditorView.swift
//  AutelGen2
//
//  Created by Autel-190215 on 2020/6/12.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit

class SubMenuLongAndLatEditorView: UIView {
    
    typealias callBack = (SubMenuLongAndLatEditorView) -> (Void)
    
    var valueChangedHandler: callBack?
        
    let contentView = UIView()
    
    let longLab = UILabel()
    let longInput = ATTextField()
    
    let latLab = UILabel()
    let latInput = ATTextField()
        
    /// 地球坐标系
    private(set) var coordinate_WGS84: CLLocationCoordinate2D?
    /// 火星坐标系
    private(set) var coordinate_Org: CLLocationCoordinate2D?
    private(set) var coordinate_OrgType: CoordinateType = mapUseCoordinateType()
    
    private var inputCoordinate: CLLocationCoordinate2D? {
        
        var coordinate:CLLocationCoordinate2D? = kCLLocationCoordinate2DInvalid
        if let text = longInput.text , let v = Double(text) {
            coordinate?.longitude = v
        }else{
            return nil
        }
        if let text = latInput.text , let v = Double(text) {
           coordinate?.latitude = v
        }else{
            return nil
        }
        return coordinate
    }
        
   private let applyBtn = UIButton()
    
    
    /// 设置坐标
    func setCoordinate(_ coordinate:CLLocationCoordinate2D, type:CoordinateType) {
        coordinate_Org = coordinate
        coordinate_OrgType = type
        let fixCoordinate = coordinate2Coordinate(coordinate: coordinate, type: type, targetType: .WGS84)
        coordinate_WGS84 = fixCoordinate
        
        longInput.text = String(format: "%.9f", fixCoordinate.longitude)//String("\(fixCoordinate.longitude)")
        latInput.text = String(format: "%.9f", fixCoordinate.latitude)//String("\(fixCoordinate.latitude)")
    }
    
    /// 设置地球坐标
    private func setCoordinateWGS84(_ coordinate:CLLocationCoordinate2D ,upUI:Bool = true) {
        coordinate_WGS84 = coordinate
        
        if upUI {
            longInput.text = String(format: "%.9f", coordinate.longitude)
            latInput.text = String(format: "%.9f", coordinate.latitude)
        }
        
        let fixCoordinate = coordinate2Coordinate(coordinate: coordinate, type: .WGS84, targetType: coordinate_OrgType)
        coordinate_Org = fixCoordinate
    
    }


        override init(frame: CGRect) {
            super.init(frame: frame)
            initView()
        }

        required init?(coder aDecoder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }

        override func layoutSubviews() {
            super.layoutSubviews()
            contentView.roundCorners(corners: [.topLeft, .topRight], radius: 5.0)
        }
        
        convenience init() {
            self.init(frame: CGRect.zero)
            initView()
        }

        func initView() {
            
            addSubview(contentView)
                contentView.backgroundColor = UIColor.init(hexFromString: "3D3D3D", alpha: 0.85)
                contentView.snp.makeConstraints { (maker) in
                      maker.edges.equalToSuperview()
            }
            
            contentView.addSubview(longLab)
            contentView.addSubview(longInput)
            contentView.addSubview(latLab)
            contentView.addSubview(latInput)
            
                      
            //107
            latLab.snp.makeConstraints { (maker) in
               maker.left.equalToSuperview().offset(10)
                maker.bottom.equalTo(latInput.snp.top).offset(-6)
           }
            latInput.snp.makeConstraints { (maker) in
                maker.left.equalToSuperview().offset(10)
                maker.bottom.equalTo(self.snp.bottom).offset(-7)
                maker.height.equalTo(22)
            }
                  
            longLab.snp.makeConstraints { (maker) in
                maker.left.equalTo(longInput).offset(10)
                maker.top.equalTo(latLab)
            }
            longInput.snp.makeConstraints { (maker) in
                maker.right.equalToSuperview().offset(-10)
                maker.top.equalTo(longLab.snp.bottom).offset(6)
                maker.height.equalTo(22)
                maker.left.equalTo(latInput.snp.right).offset(10)
                maker.width.equalTo(latInput.snp.width)
            }

            longLab.textColor = UIColor.wordColor
            longLab.font = UIFont.systemFont(ofSize: 6, weight: .regular)
            longLab.textAlignment = .left
            
            latLab.text = "latitudeLabel"
            latLab.textColor = UIColor.wordColor
            latLab.font = UIFont.systemFont(ofSize: 6, weight: .regular)
            latLab.textAlignment = .left
            
            applyBtn.setTitle("应用", for: .normal)
            
            latInput.textColor = UIColor.wordColor
            latInput.font = UIFont.systemFont(ofSize: 12, weight: .regular)
            latInput.textInsets = UIEdgeInsets.init(top: 0, left: 5, bottom: 0, right: 0)
            latInput.adjustsFontSizeToFitWidth = true
            
            longInput.textColor = UIColor.wordColor
            longInput.font = UIFont.systemFont(ofSize: 12, weight: .regular)
            longInput.textInsets = UIEdgeInsets.init(top: 0, left: 5, bottom: 0, right: 0)
            longInput.adjustsFontSizeToFitWidth = true
            
            latInput.layer.borderColor = UIColor.separatorLineColor2.cgColor
            latInput.layer.borderWidth = 0.5
            latInput.layer.cornerRadius = 2
            latInput.addTarget(self, action: #selector(valueTextEndEdit(_:)), for: .editingDidEnd)
            
            longInput.layer.borderColor = UIColor.separatorLineColor2.cgColor
            longInput.layer.borderWidth = 0.5
            longInput.layer.cornerRadius = 2
            longInput.addTarget(self, action: #selector(valueTextEndEdit(_:)), for: .editingDidEnd)
            
            latInput.delegate = self
            longInput.delegate = self
        }

        
     @objc func applyBtnClick(_ sender: UIButton) {
            actionSetCoordinate()
    }
    
     private func actionSetCoordinate(){
        if updateCoordinateFromInput() {
            valueChangedHandler?(self)
        }
    }
    
    private  func updateCoordinateFromInput() -> Bool {
           if let coordinate = inputCoordinate , CLLocationCoordinate2DIsValid(coordinate){
               setCoordinateWGS84(coordinate,upUI: false)
               return true
            }
           return false
    }
   
        

}


extension SubMenuLongAndLatEditorView : UITextFieldDelegate {


//    @available(iOS 10.0, *)
//    optional func textFieldDidEndEditing(_ textField: UITextField, reason: UITextField.DidEndEditingReason) {
//
//    }
    
        @objc
        func textFieldShouldReturn(_ textField: UITextField) -> Bool {
              textField.endEditing(false)
              return true
        }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        actionSetCoordinate()
    }
        
    
    @objc private func valueTextEndEdit(_ textFied: UITextField) {

    }
    
}

