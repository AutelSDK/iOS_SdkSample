//
//  MissionBaseViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/7.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit



class MissionBaseViewController: BaseVideoViewController {
    
    let btnWidth = 99
    let btnHeight = 32
    

    override func viewDidLoad() {
        super.viewDidLoad()

    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        startPlay()
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        stopPlay()
    }
    
    deinit {
        print("MissionBaseViewController deinit")
    }
    
    override func configNavigationItem() {
        super.configNavigationItem()
        navigationItem.title = "Waypoint Mission Demo"
        
        let switchBtn = UIButton(type: .custom)
        switchBtn .setTitle("switch", for: .normal)
//        switchBtn .setTitleColor(UIColor.black, for: .normal)
        switchBtn.addTarget(self,action:#selector(switchBtnClick), for: .touchUpInside)
        navigationItem.rightBarButtonItem = UIBarButtonItem(customView: switchBtn)
    }
    
    @objc func switchBtnClick() {
        if currentViewType == .Console {
            currentViewType = .EarthStation
            view.sendSubviewToBack(videoPlayView)
        } else {
            currentViewType = .Console
            view.sendSubviewToBack(earthStationVC.view)
        }
    }
    
    override func setupSubviews() {
        super.setupSubviews()
        
        view.addSubview(earthStationVC.view)
        earthStationVC.view.snp.makeConstraints { (make) in
            make.edges.equalToSuperview()
            make.size.equalToSuperview()
        }
        addChild(earthStationVC)
        currentViewType = .EarthStation
        
        view.addSubview(stopButton)
        stopButton.snp.makeConstraints { (make) in
            make.right.equalTo(view.snp.centerX).offset(-10)
            make.bottom.equalTo(view.safeAreaLayoutGuide.snp.bottom).offset(-30)
            make.width.equalTo(btnWidth)
            make.height.equalTo(btnHeight)
        }
        
        view.addSubview(startButton)
        startButton.snp.makeConstraints { (make) in
            make.right.equalTo(stopButton.snp.left).offset(-20)
            make.bottom.equalTo(view.safeAreaLayoutGuide.snp.bottom).offset(-30)
            make.width.equalTo(btnWidth)
            make.height.equalTo(btnHeight)
        }
        
        view.addSubview(pauseButton)
        pauseButton.snp.makeConstraints { (make) in
            make.left.equalTo(view.snp.centerX).offset(10)
            make.bottom.equalTo(view.safeAreaLayoutGuide.snp.bottom).offset(-30)
            make.width.equalTo(btnWidth)
            make.height.equalTo(btnHeight)
        }
        
        view.addSubview(resumeButton)
        resumeButton.snp.makeConstraints { (make) in
            make.left.equalTo(pauseButton.snp.right).offset(20)
            make.bottom.equalTo(view.safeAreaLayoutGuide.snp.bottom).offset(-30)
            make.width.equalTo(btnWidth)
            make.height.equalTo(btnHeight)
        }
    }
    
    
    //MARK: Action
    @objc func settingBtnClick(_ sender: UIButton) {
        if sender.tag == 1001 {
            startBtnClick(sender)
        } else if sender.tag == 1002 {
            stopBtnClick(sender)
        } else if sender.tag == 1003 {
            pauseBtnClick(sender)
        } else if sender.tag == 1004 {
            resumeBtnClick(sender)
        }
    }
    
    //MARK: Action
   func startBtnClick(_ sender: UIButton) {
       print("startBtnClick")
   }
   
   func stopBtnClick(_ sender: UIButton) {
       print("stopBtnClick")
   }
   
   func pauseBtnClick(_ sender: UIButton) {
       print("pauseBtnClick")
   }
   
   func resumeBtnClick(_ sender: UIButton) {
       print("resumeBtnClick")
   }
    
    func creatButton(title: String, tag: Int) -> UIButton {
        let button = UIButton.init(type: .custom)
        button.setTitle(title, for: .normal)
        button.titleLabel?.font = UIFont.systemFont(ofSize: 15)
//        button.setTitleColor(UIColor.white, for: .normal)
        button.setBackgroundImage(UIImage.imageWithUIColor(color: UIColor.init(fromHex: 0x007AFF, alpha: 0.9)), for: .normal)
        button.layer.cornerRadius = 4
        button.layer.masksToBounds = true
        button.tag = tag
        button.addTarget(self, action: #selector(settingBtnClick(_:)), for: .touchUpInside)
        return button
    }
    
    //MARK: lazy var
    lazy var startButton : UIButton = {
        return creatButton(title: "Start🚁", tag: 1001)
    }()
    
    lazy var stopButton : UIButton = {
        return creatButton(title: "Stop", tag: 1002)
    }()
    
    lazy var pauseButton : UIButton = {
        return creatButton(title: "Pause", tag: 1003)
    }()
    
    lazy var resumeButton : UIButton = {
        return creatButton(title: "Resume", tag: 1004)
    }()

}
