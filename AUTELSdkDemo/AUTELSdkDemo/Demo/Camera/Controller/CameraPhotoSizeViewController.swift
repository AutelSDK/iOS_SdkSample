//
//  MissionBaseViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/7.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit
import XLActionController


class CameraPhotoSizeViewController: BaseVideoViewController {
    
    
    let btnWidth = 99
    let btnHeight = 32
    

    override func viewDidLoad() {
        super.viewDidLoad()
        
        getParameter()
        
        setCameraPhotoMode()
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
        print("\(self.classIdentifier) deinit")
    }
    
    override func configNavigationItem() {
        super.configNavigationItem()
        navigationItem.title = "CameraPhotoSize Setting Demo"
    }
    
    @objc func rightItemClick() {
        print("rightItemClick")
    }
    
    override func setupSubviews() {
        super.setupSubviews()
        
        view.addSubview(setPhotoSizeButton)
        setPhotoSizeButton.snp.makeConstraints { (make) in
            make.centerX.equalToSuperview()
            make.bottom.equalTo(view.safeAreaLayoutGuide.snp.bottom).offset(-30)
            make.height.equalTo(btnHeight)
        }
    }
    
    
    //MARK: Action
    @objc func settingBtnClick(_ sender: UIButton) {
        if sender.tag == 1001 {
            startBtnClick(sender)
        }
    }
    
    //MARK: Action
   func startBtnClick(_ sender: UIButton) {
       print("startBtnClick")
    
        if let unwrapParameters = supporParameters() {
            let actionSheet = TwitterActionController()
            actionSheet.headerData = "Camera PhotoSize"
            for string in unwrapParameters {
                let action = Action(ActionData(title: string), style: .default, handler: { action in
                   
                    if let name = action.data?.title {
                        self.setParameter(name)
                    }
                })
                actionSheet.addAction(action)
            }
            
            present(actionSheet, animated: true, completion: nil)
        } else {
            self.view.makeToast("NO Parameters")
        }
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
    lazy var setPhotoSizeButton : UIButton = {
        return creatButton(title: "PhotoSize", tag: 1001)
    }()

}


extension CameraPhotoSizeViewController {
    
    func getParameter() {
        CameraCommandDeliver.getPhotoSize { [weak self] (mode, error) in
            guard let strongSelf = self else { return }
            if let name = mode.displayName() {
                DispatchQueue.main.async {
                    if let _ = error {
                        strongSelf.view.makeToast("getPhotoSize to \(name) failed")
                    } else {
                        strongSelf.setPhotoSizeButton.setTitle(name, for: .normal)
                        strongSelf.setPhotoSizeButton.sizeToFit()
                    }
                }
            }
        }
    }
    
    func supporParameters() -> [String]? {
        return CameraSupporParameters.requestPhotoSizeWithItem()
    }
    
    func setParameter(_ name: String) {
        CameraCommandDeliver.setPhotoSize(AUTELCameraPhotoAspectRatio.initFromDisplayName(displayName: name)) { [weak self] (error) in
            guard let strongSelf = self else { return }
            DispatchQueue.main.async {
                if let _ = error {
                    strongSelf.view.makeToast("setPhotoSize to \(name) failed")
                } else {
                    strongSelf.view.makeToast("setPhotoSize to \(name) successful")
                    strongSelf.setPhotoSizeButton.setTitle(name, for: .normal)
                }
            }
        }
    }
    
    
    func setCameraPhotoMode() {
        CameraCommandDeliver.setWorkMode(.captureSingle) { [weak self] (error) in
            
        }
    }
}
