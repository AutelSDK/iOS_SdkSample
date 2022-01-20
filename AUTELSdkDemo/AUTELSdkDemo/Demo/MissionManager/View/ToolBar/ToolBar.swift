//
//  ToolBar.swift
//  AutelGen2
//
//  Created by Autel-Hero on 2019/10/8.
//  Copyright © 2019 AUTEL. All rights reserved.
//


enum ToolBarType: String {
    case missioCamera //航点飞行任务执行中（没有使用）
    case missionWaypoint              //任务飞行的航点飞行
    case missionWaypointForFly        //航点飞行任务执行中（没有使用）
    case rectangle  //任务飞行的rectangle
    case polygon  //任务飞行的rectangle
    case obliquePhoto  //倾斜摄影
}

enum ToolBarItemTag : Int {
     case none = 0
    
     //shouleSelected
    
     case wapPointButton = 901
     case wapPointFlyButton = 902
     case interestButton = 903

     //noSelected
     case airLineButton = 905
     case reverseButton = 906
     case deleteAllButton = 907
     case saveButton = 908
     case moreButton = 909
    case cameraButton = 911
    
    
    //未使用-未知逻辑
    case taskButton = 899
    case trackButton = 900
    case landingPointButton = 904
    case gimbalButton = 910
    
    case settingButton = 912
    
    case reNameButton = 913
    
     case line = 11111
}

@objc protocol ToolBarDelegate {
    @objc optional func toolBarDidClickedItem(_ toolBar:ToolBar ,itemTag:Int ,itemIsSelected:Bool)
}

class ToolBar: MenuBGView {
    weak var delegate: ToolBarDelegate?
    var selectedItemTag : ToolBarItemTag = .none
    private(set) var barType : ToolBarType!

    private let toolBar = UIView()
    private let airLineButton = UIButton()
    
    private let wapPointButton = UIButton()
    private let wapPointFlyButton = UIButton()
    private let interestButton = UIButton()
   
    private let lineButton = UIButton()
    private let lineButton1 = UIButton()
    private let reverseButton = UIButton()
    private let deleteAllButton = UIButton()
    private let saveButton = UIButton()
    private let reNameButton = UIButton()
    private let moreButton = UIButton()
 
   
    private let landingPointButton = UIButton()
    private let taskButton = UIButton()
    private let trackButton = UIButton()

    private let gimbalButton = UIButton()
    private let cameraButton = UIButton()
    private let settingButton = UIButton()
    
    private var buttonArray = [UIButton()]
    

    override init(frame: CGRect) {
        super.init(frame: frame)
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    convenience init(with toolBarType: ToolBarType) {
        self.init(frame: CGRect.zero)
        initView(with: toolBarType)
    }

    func initView(with toolBarType: ToolBarType = .missionWaypoint) {
        barType = toolBarType
        setButtonStyle()
        setToolBar(with: toolBarType)
    }

    func setButtonStyle() {
        taskButton.tag = ToolBarItemTag.taskButton.rawValue
        trackButton.tag = ToolBarItemTag.trackButton.rawValue
        wapPointFlyButton.tag = ToolBarItemTag.wapPointFlyButton.rawValue
        wapPointButton.tag = ToolBarItemTag.wapPointButton.rawValue
        interestButton.tag = ToolBarItemTag.interestButton.rawValue
        landingPointButton.tag = ToolBarItemTag.landingPointButton.rawValue
        
        airLineButton.tag = ToolBarItemTag.airLineButton.rawValue
        reverseButton.tag = ToolBarItemTag.reverseButton.rawValue
        deleteAllButton.tag = ToolBarItemTag.deleteAllButton.rawValue
        saveButton.tag = ToolBarItemTag.saveButton.rawValue
        reNameButton.tag = ToolBarItemTag.reNameButton.rawValue
        moreButton.tag = ToolBarItemTag.moreButton.rawValue
        
        gimbalButton.tag = ToolBarItemTag.gimbalButton.rawValue
        cameraButton.tag = ToolBarItemTag.cameraButton.rawValue
        settingButton.tag = ToolBarItemTag.settingButton.rawValue

        lineButton.tag = ToolBarItemTag.line.rawValue
        lineButton.isUserInteractionEnabled = false
        lineButton.setImage(UIImage(named: "buttonLine"), for: .normal)
        lineButton1.tag = ToolBarItemTag.line.rawValue
        lineButton1.isUserInteractionEnabled = false
        lineButton1.setImage(UIImage(named: "buttonLine"), for: .normal)
        
        taskButton.setImage(UIImage(named: "toolbar_btn_tracking_def"), for: .normal)
        taskButton.setImage(UIImage(named: "toolbar_btn_tracking_pre"), for: .selected)
        trackButton.setImage(UIImage(named: "toolbar_btn_tracking_def"), for: .normal)
        trackButton.setImage(UIImage(named: "toolbar_btn_tracking_pre"), for: .selected)
        
        wapPointButton.setImage(UIImage(named: "toolbar_btn_waypoint_def"), for: .normal)
        wapPointButton.setImage(UIImage(named: "toolbar_btn_waypoint_pre"), for: .selected)
        wapPointFlyButton.setImage(UIImage(named: "toolbar_btn_flypoint_def"), for: .normal)
        wapPointFlyButton.setImage(UIImage(named: "toolbar_btn_flypoint_pre"), for: .selected)

        interestButton.setImage(UIImage(named: "toolbar_btn_poi_def"), for: .normal)
        interestButton.setImage(UIImage(named: "toolbar_btn_poi_pre"), for: .selected)
      
        reverseButton.setImage(UIImage(named: "toolbar_btn_se_def"), for: .normal)
        reverseButton.setImage(UIImage(named: "toolbar_btn_se_pre"), for: .highlighted)
        
        deleteAllButton.setImage(UIImage(named: "toolbar_btn_delete_def"), for: .normal)
        deleteAllButton.setImage(UIImage(named: "toolbar_btn_delete_pre"), for: .highlighted)
        
        saveButton.setImage(UIImage(named: "toolbar_btn_save_def"), for: .normal)
        saveButton.setImage(UIImage(named: "toolbar_btn_save_pre"), for: .highlighted)
        
        reNameButton.setImage(UIImage(named: "toolbar_btn_name_def"), for: .normal)
        reNameButton.setImage(UIImage(named: "toolbar_btn_name_pre"), for: .highlighted)
        
        moreButton.setImage(UIImage(named: "toolbar_btn_list_def"), for: .normal)
        moreButton.setImage(UIImage(named: "toolbar_btn_list_pre"), for: .highlighted)
        
        gimbalButton.setImage(UIImage(named: "toolbar_btn_cloudplatform_def"), for: .normal)
        gimbalButton.setImage(UIImage(named: "toolbar_btn_cloudplatform_pre"), for: .selected)
        
        cameraButton.setImage(UIImage(named: "toolbar_btn_cameraparameters_def"), for: .normal)
        cameraButton.setImage(UIImage(named: "toolbar_btn_cameraparameters_pre"), for: .selected)
        
        settingButton.setImage(UIImage(named: "toolbar_btn_camerasetting_def"), for: .normal)
        settingButton.setImage(UIImage(named: "toolbar_btn_camerasetting_pre"), for: .selected)
    }

    // 配置工具条
    func setToolBar(with toolBarType: ToolBarType = .missionWaypoint) {
        if toolBarType == .missionWaypoint {
            selectedItemTag = .wapPointButton
            wapPointButton.isSelected = true
            airLineButton.setImage(UIImage(named: "toolbar_btn_route_def"), for: .normal)
            airLineButton.setImage(UIImage(named: "toolbar_btn_route_pre"), for: .selected)
            buttonArray = [cameraButton, lineButton, deleteAllButton]
        } else if toolBarType == .missionWaypointForFly {
            airLineButton.setImage(UIImage(named: "toolbar_btn_route_def"), for: .normal)
            airLineButton.setImage(UIImage(named: "toolbar_btn_route_pre"), for: .selected)
            buttonArray = [taskButton, interestButton,
                           lineButton,
                           saveButton, moreButton]
        } else if toolBarType == .rectangle {
            airLineButton.setImage(UIImage(named: "toolbar_btn_rectangular _def"), for: .normal)
            airLineButton.setImage(UIImage(named: "toolbar_btn_rectangular _pre"), for: .selected)
            buttonArray = [airLineButton,
                           cameraButton,
                           lineButton,
                           deleteAllButton,
                           saveButton,
                           reNameButton]    //    , saveButton, moreButton]
        } else if toolBarType == .polygon {
            airLineButton.setImage(UIImage(named: "toolbar_btn_polygon_def"), for: .normal)
            airLineButton.setImage(UIImage(named: "toolbar_btn_polygon_pre"), for: .selected)
            buttonArray = [airLineButton,
                           cameraButton,
                           lineButton,
                           deleteAllButton,
                           saveButton,
                           reNameButton]    //    , saveButton, moreButton]
        } else if toolBarType == .obliquePhoto {
               airLineButton.setImage(UIImage(named: "toolbar_btn_polygon_def"), for: .normal)
               airLineButton.setImage(UIImage(named: "toolbar_btn_polygon_pre"), for: .selected)
               buttonArray = [airLineButton,
                              cameraButton,
                              lineButton,
                              deleteAllButton,
                              saveButton,
                              reNameButton]    //    , saveButton, moreButton]
        } else { // 相机UI
            buttonArray = [gimbalButton, cameraButton, moreButton]
//            buttonArray = [trackButton, lineButton, gimbalButton, cameraButton, settingButton]    //    , moreButton]
//            buttonArray = [gimbalButton, cameraButton, settingButton]    //    , moreButton]
        }

        addSubview(toolBar)
        toolBar.backgroundColor = UIColor.white
        toolBar.snp.makeConstraints { (maker) in
            maker.edges.equalToSuperview()
        }
        for (i, btn) in buttonArray.enumerated() {
            toolBar.addSubview(btn)
            btn.addTarget(self, action: #selector(buttonClick(_:)), for: UIControl.Event.touchUpInside)
            btn.snp.makeConstraints { (maker) in
                maker.height.equalTo(39)
                if btn.tag != ToolBarItemTag.line.rawValue {
                    maker.width.equalTo(39)
                } else {
                    maker.width.equalTo(19) // 线加上空白部分 23 - 4
                }
                if i == 0 {
                    maker.left.equalToSuperview().offset(10)
                } else {
                    maker.left.equalTo(buttonArray[i - 1].snp.right).offset(2)
                }
                if i == buttonArray.count - 1 {
                     maker.right.equalToSuperview().offset(-10)
                }
                maker.centerY.equalToSuperview()
            }
        }
    }
    
    func shouldWidth() -> Float {
        let lineCount = buttonArray.filter { (btn) -> Bool in
            btn.tag ==  ToolBarItemTag.line.rawValue
        }.count
        return Float((buttonArray.count - lineCount) * 39 + lineCount * 19 + (buttonArray.count - 1) * 2  + 10 * 2)
    }

    @objc func buttonClick(_ button: UIButton) {
        
        let tag = ToolBarItemTag.init(rawValue: button.tag) ?? .line
        let shouldSelected = button.tag < ToolBarItemTag.airLineButton.rawValue
        
        if shouldSelected {
            
            for btn in buttonArray {
                if button.tag >= ToolBarItemTag.airLineButton.rawValue { break }
                btn.isSelected = false
            }
            
            button.isSelected = true
            self.selectedItemTag = tag
        }
        
        delegate?.toolBarDidClickedItem?(self, itemTag: tag.rawValue, itemIsSelected: button.isSelected)
    
    }
}

