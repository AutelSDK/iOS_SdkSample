//
//  MissionSliderView.swift
//  AutelGen2
//
//  Created by Autel-Hero on 2019/9/25.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import UIKit

typealias SetMissionTupleHandler = ((curValue: String, text: String)) -> (Void)
typealias SetNewValueHandler = (Float) -> (Void)
typealias SetTouchDragHandler = (Bool) -> (Void)

class MissionSliderView: MenuBGView {


    let miniLable = MissionLable()
    let maxLable = MissionLable()
    let slider = UISlider()
    let valueLable = MissionTextField()
    private(set) var helpBtn: UIButton = {
        let btn = UIButton.init(type: .custom)
        btn.backgroundColor = UIColor.red
        return btn
    }()
    var helpBtnAction:((_ btn:UIButton)->())?
    
    var format = ""
//    var minValue: Float = 0
//    var maxValue: Float = 0
//    var currentValue: Float = 0
    var curValueAndTextHandler: SetMissionTupleHandler? //当前值改变多次调用 完成后调用curValueAndTextFinishHandler
    var curValueAndTextFinishHandler: SetMissionTupleHandler?  //当前值完成设置 slidet拖动或者别的
    var newValueDidSetHandler: SetNewValueHandler?  // same as curValueAndTextHandler
    var newValueFinishSetHandler: SetNewValueHandler? // same as curValueAndTextFinishHandler
    
    var touchDidChangeBlock: SetTouchDragHandler?
    private(set) var isDraging:Bool = false

    
    var unit = ""
    var unitType: MCUnitType = .other

//    var maxHeight: Float = 120
//    var maxSpeed: Float = 10
//    var missionSliderType = MissionSliderType.height

    let timer = GCDTimer()
    var sliderIsTouchInside = false {
        didSet {
            // 最后改为 false 没有j点击
            if sliderIsTouchInside != oldValue && !sliderIsTouchInside {
                sliderTouchExit(slider)
            }
        }
    }

    override init(frame: CGRect) {
        super.init(frame: frame)
        initView()
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    convenience init() {
        self.init(frame: CGRect.zero)
        initView()
    }

    func initView() {
   
        miniLable.adjustsFontSizeToFitWidth = true
        maxLable.adjustsFontSizeToFitWidth = true
        
        addSubview(valueLable)
        valueLable.addTarget(self, action: #selector(valueTextEndEdit(_:)), for: .editingDidEnd)
        valueLable.delegate = self
        addSubview(miniLable)
        miniLable.textColor = UIColor(hexFromString: "FFFFFF", alpha: 0.5)
        addSubview(maxLable)
        maxLable.textColor = UIColor(hexFromString: "FFFFFF", alpha: 0.5)
        slider.setThumbImage(UIImage(named: "blue_slider"), for: .normal)
        slider.minimumTrackTintColor = SettingsBlue
        slider.maximumTrackTintColor = SettingsSliderGray
        slider.addTarget(self, action: #selector(sliderTouchIn(_:)), for: .touchDown)
        slider.addTarget(self, action: #selector(sliderTouchExit(_:)), for: .touchUpOutside)
//        slider.addTarget(self, action: #selector(sliderTouchExit(_:)), for: .touchUpInside)
        slider.addTarget(self, action: #selector(sliderValueChanged(_:)), for: .valueChanged)
        addSubview(slider)
        timer.start(milliseonds: 200, repeats: true) { [weak self] in
            guard let strongSelf = self else { return }
            if strongSelf.sliderIsTouchInside != strongSelf.slider.isTouchInside {
                strongSelf.sliderIsTouchInside = strongSelf.slider.isTouchInside
            }
        }
        valueLable.snp.makeConstraints { (maker) in
              maker.centerY.equalToSuperview()
              maker.left.equalToSuperview().offset(5)
              maker.width.equalTo(60)
        }
        miniLable.snp.makeConstraints { (maker) in
              maker.centerY.equalToSuperview()
              maker.left.equalTo(valueLable.snp.right)
              maker.width.equalTo(30)
        }
        slider.snp.makeConstraints { (maker) in
             maker.centerY.equalToSuperview()
             //.offset(2) Fix: MOD-4933 APP 界面 刻度球 与刻度左侧数值显示重叠
             maker.left.equalTo(miniLable.snp.right).offset(2)
             maker.right.equalTo(maxLable.snp.left)
        }
        maxLable.snp.makeConstraints { (maker) in
            maker.centerY.equalToSuperview()
            maker.right.equalToSuperview()
            maker.width.equalTo(50)
        }
     
    }
    
    func setupHelpButton(_ action:((_ button: UIButton)->())?) {
        let btn = UIButton.init(type: .custom)
        addSubview(btn)
        btn.snp.makeConstraints({ (maker) in
            maker.centerY.equalToSuperview()
            maker.right.equalToSuperview().offset(-10)
            maker.size.equalTo(CGSize.init(width: 20, height: 20))
        })
        btn.setImage(UIImage(named: "mission_submenu_问号"), for: .normal)
        maxLable.snp.remakeConstraints { (maker) in
            maker.centerY.equalToSuperview()
            maker.right.equalTo(btn.snp.left).offset(-5)
            maker.width.equalTo(50)
        }
        btn.addTarget(self, action: #selector(helpbuttonClick(_:)), for: .touchUpInside)
        helpBtn = btn
        helpBtnAction = action
    }
     @objc func helpbuttonClick(_ button: UIButton) {
        self.helpBtnAction?(button)
    }

    func setData(_ curValue: String, with missionSliderType: MissionSliderType) {
        if let format = missionSliderType.dic["format"] {
            self.format = format
        } else {
            self.format = ""
        }

        if let unit = missionSliderType.dic["unit"] {
            self.unit = unit
            if unit == "m" {
                unitType = .lenght
            } else if unit == "m/s" {
                unitType = .speed
            } else {
                unitType = .other
            }
        } else {
            self.unit = ""
            unitType = .other
        }

        if let minValue = missionSliderType.dic["minValue"] {
            slider.minimumValue = Float(minValue)!
//            self.minValue = roundf(slider.minimumValue)
            miniLable.text = minValue.deal(with: unitType)
            
            if slider.minimumValue < 0 {
                valueLable.keyboardType = .numbersAndPunctuation
            }else{
                valueLable.keyboardType = .numberPad
            }
        }

        if let maxValue = missionSliderType.dic["maxValue"] {
            slider.maximumValue = Float(maxValue)!
//            self.maxValue = roundf(slider.maximumValue)
            maxLable.text = maxValue.deal(with: unitType)
        }

        if curValue != "N/A" {
            if let curValueFloat = Float(curValue) {
                slider.value = curValueFloat
//                currentValue = curValueFloat
            }
        } else {
            slider.value = slider.minimumValue
        }
        /// slider.value 是用 m/s 单位 但是显示要用设置的系统单位
        valueLable.text = showTextByUnitSystem(value: slider.value, format: format, unitType: unitType, unit: unit)
    }
    
    func setData2(_ curValue: Float, max:Float? ,min:Float?, valueformat:String = "", unit:String = "") {
        self.format = valueformat
        self.unit = unit
        if unit == "m" {
            unitType = .lenght
        } else if unit == "m/s" {
            unitType = .speed
        } else {
            unitType = .other
        }
        if let minValue = min {
            slider.minimumValue = minValue
            miniLable.text = showTextByUnitSystem(value: minValue, format: format, unitType: unitType, unit: unit)
            
            //恶心 Fix: MOD-4308 新建航点任务时，飞行高度、飞行速度输入框中可输入字符 “-”
            if slider.minimumValue < 0 {
                valueLable.keyboardType = .numbersAndPunctuation
            }else{
                valueLable.keyboardType = .numberPad
            }
        }
        if let maxValue = max {
            slider.maximumValue = maxValue
            maxLable.text = showTextByUnitSystem(value: maxValue, format: format, unitType: unitType, unit: unit)
        }
        
        slider.value = curValue
        valueLable.text = showTextByUnitSystem(value:curValue, format: format, unitType: unitType, unit: unit)
    }

    func update(curValue: String = "", maxValue: String = "") {
        
        var curV = slider.value
                
        if let maxValuef = Float(maxValue) {
            
            slider.maximumValue = maxValuef
//            self.maxValue = roundf(slider.maximumValue)
            maxLable.text = maxValue.deal(with: unitType)
            if maxValuef < curV {
                curV = maxValuef
            }
        }
        
        if curValue != "" {
             if curValue != "N/A" {
                 if let curValueFloat = Float(curValue) {
                     curV = curValueFloat
                 }
             } else {
                 curV = slider.minimumValue
             }
        }
        
        self.updateCurValue(adjustValueRoundMaxMin(curV))
    }
    
    @discardableResult
    fileprivate func updateCurValue(_ curValue: Float ) -> Bool {
        let minValue = slider.minimumValue
        let maxValue = slider.maximumValue
        guard curValue >= minValue && curValue <= maxValue else {
            return false
        }
        if  slider.value != curValue { //currentValue != curValue ||  slider.value != curValue
//            currentValue = curValue
            slider.value = curValue
            valueLable.text = showTextByUnitSystem(value: curValue, format: format, unitType: unitType, unit: unit)
            return true
        }
        return false
    }
    
    fileprivate func adjustValueRoundMaxMin(_ mValue: Float ) -> Float  {
            let minValue = slider.minimumValue
            let maxValue = slider.maximumValue
           var value = mValue
           if mValue < minValue && ceilf(mValue) >= minValue {
               value = minValue
           }
           if mValue > maxValue && floorf(mValue) <= maxValue {
               value = maxValue
          }
          return value
    }
    
    /// 当前单位的整数值
    fileprivate func curentBaseIntValue() -> Float {
        
        if case .other = unitType {
             return roundf(slider.value)
        }
        if let text = valueLable.text , text.count > 1 {
           let txt = text.prefix(while: { (chr) -> Bool in
                return chr.isNumber
            })
            if let mValue  = String(txt).dealToMetricf(with: unitType){
                return self.adjustValueRoundMaxMin(mValue)
            }
        }
        return slider.value
    }
    
    //MARK: - callBack
    fileprivate  func valueDidChanged() {
        let baseValue = curentBaseIntValue()
        newValueDidSetHandler?(baseValue)
        curValueAndTextHandler?((baseValue.formatf(format: "%f"), valueLable.text!))
    }
    
    fileprivate  func valueDidFinishChanged() {
        let baseValue = curentBaseIntValue()
        newValueFinishSetHandler?(baseValue)
        curValueAndTextFinishHandler?((baseValue.formatf(format: "%f"), valueLable.text!))
    }
    
    //MARK: - Slider events
    @objc private func sliderValueChanged(_ sender: UISlider) {
        if sliderIsTouchInside != sender.isTouchInside {
            sliderIsTouchInside = sender.isTouchInside
        }
//        currentValue = roundf(slider.value)
        valueLable.text = showTextByUnitSystem(value: slider.value, format: format, unitType: unitType, unit: unit)
        self.valueDidChanged()
    }

    @objc private func sliderTouchExit(_ sender: UISlider) {
        self.valueDidFinishChanged()
//        if currentValue > maxHeight && missionSliderType == .height {
//            SystemMessageCenter.shared.insertAMessageEvent(type: MCMessageEventType.overMaxHeihght)
//        }
        isDraging = false
        touchDidChangeBlock?(false)
    }
    
    @objc private func sliderTouchIn(_ sender: UISlider) {
        isDraging = true
        touchDidChangeBlock?(true)
    }

//    func getMaxData() {
//        MainControllerConnection.shared.mainCtl?.flightLimitation.getMaxFlightHeight(completion: {[weak self]  (maxAltitude, error) in
//            if let err = error {
//            } else {
//                self?.maxHeight = maxAltitude
//            }
//        })
//
//        MainControllerConnection.shared.mainCtl?.flightLimitation.getMaxFlightHorizontalSpeed(completion: {[weak self]  (maxSpeed, error) in
//            if let err = error {
//            } else {
//                if maxSpeed > 10.1 {
//                    self?.maxSpeed = 10
//                } else {
//                    self?.maxSpeed = maxSpeed
//                }
//            }
//        })
//    }
}

// MARK: - UITextFieldDelegate  valueText
extension MissionSliderView: UITextFieldDelegate {
    
    @objc
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
          textField.endEditing(false)
          return true
    }
    
    @objc
    func textFieldDidBeginEditing(_ textField: UITextField) {
        if let text = textField.text , text.count > 1 {
              let txt = text.prefix(while: { (chr) -> Bool in
                   return chr.isNumber
               })
              textField.text = String(txt)
        }
    }
    
    @objc
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
//        if range.length == 1 , string.count == 0 {
//            dPrint("didInput del")
//            if let text = textField.text , text.count > 1 {
//               let txt = text.prefix(while: { (chr) -> Bool in
//                    return chr.isNumber
//                })
//                textField.text = String(txt)
//                return false
//            }
//        }
        if  textField is MissionTextField {
            guard let text = textField.text as NSString? else {
                  valueTextDidChanged(string)
                  return true
            }
             
            let checkStr = text.replacingCharacters(in: range, with: string)
            
            if let regexp = (textField as! MissionTextField).numRegularExpression {
                let ran = NSMakeRange(0, checkStr.count)
                let result = regexp.matches(in: checkStr,
                                                        options: NSRegularExpression.MatchingOptions.reportProgress,
                                                        range: ran)
                let rs = result.count > 0
                if rs {
                    valueTextDidChanged(checkStr)
                }
                return rs
            }
            
            valueTextDidChanged(checkStr)
            
          }
          return true
    }
    
    private func valueTextDidChanged(_ txt: String?) {
        if let text = txt , let curValue  = text.dealToMetricf(with: unitType){
            
            let minValue = slider.minimumValue
            let maxValue = slider.maximumValue
            if curValue >= minValue && curValue <= maxValue  {
                valueLable.textColor = UIColor.wordColor
            }else{
                 valueLable.textColor = UIColor.red
            }
        }
    }
    
    @objc private func valueTextEndEdit(_ textFied: UITextField) {
        let currentValue = slider.value
        if let text = textFied.text , let mValue  = text.dealToMetricf(with: unitType){
            
            //处理边缘条件
            let value = self.adjustValueRoundMaxMin(mValue)
            //当前单位转 m/s 然后再传出去
            if self.updateCurValue(value) {
                self.valueDidChanged()
                self.valueDidFinishChanged()
                return
            }
        }
        valueLable.text = showTextByUnitSystem(value: currentValue, format: format, unitType: unitType, unit: unit)
        valueLable.textColor = UIColor.wordColor
    }
    
    
}

