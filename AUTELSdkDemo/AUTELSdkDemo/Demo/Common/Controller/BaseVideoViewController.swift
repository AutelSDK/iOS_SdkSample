//
//  BaseVideoViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/1.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit
import AUTELWidget

enum ATViewType {
    case Console
    case EarthStation
}

class BaseVideoViewController: BaseViewController {
    
    var currentViewType: ATViewType = .Console
    

    override func viewDidLoad() {
        super.viewDidLoad()

//        configNavigationItem()
        setupSubviews()
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
    
    override func setupSubviews() {
        view.backgroundColor = UIColor.black
        view.addSubview(videoPlayView)
        videoPlayView.snp.makeConstraints { (make) in
            make.edges.equalToSuperview()
        }
    }
    
    
    
    var isPlaySetup = false

    lazy var videoPlayView : VideoOpenGLView = {
        let view = VideoOpenGLView.init()
        return view
    }()

    lazy var earthStationVC : EarthStationViewController = {
        let vc = EarthStationViewController.init()
        return vc
    }()

}


//** MARK:- VideoStreamPlay
extension BaseVideoViewController {
    
    /// start video stream
    func startPlay() {
        guard !self.isPlaySetup else {
            return
        }
        self.isPlaySetup = true
        print("VideoStreamPlayManager startPlay called")
        VideoStreamPlayManager.sharedInstance().setPlayView(to: videoPlayView)
        VideoStreamPlayManager.sharedInstance().insertNewFrameHandler = { [weak self] frame  in
            DispatchQueue.main.async {
                self?.view.makeToast("insertNewFrameHandler  width: \(frame.width)  height: \(frame.height) timeStamp: \(frame.timeStamp)")
            }
            
        }
    }
    
    /// stop video stream
    func stopPlay() {
        print("VideoStreamPlayManager stopPlay called")
        VideoStreamPlayManager.sharedInstance().stopPlayAndRemoveView()
        self.isPlaySetup = false
    }
}

