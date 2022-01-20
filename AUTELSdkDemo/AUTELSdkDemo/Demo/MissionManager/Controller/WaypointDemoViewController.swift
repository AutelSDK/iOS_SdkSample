//
//  WaypointDemoViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/7.
//  Copyright © 2020 AUTEL. All rights reserved.
//

extension Notification.Name {
    static let wayPointMarkAnnotationViewDidMoved = Notification.Name("wayPointAnnotationViewDidMoved")
    static let wayPointAddAnnotationViewDidMoved = Notification.Name("wayPointAddAnnotationViewDidMoved")
    static let addAnnotationViewDidTap = Notification.Name("addAnnotationViewDidTap")
    static let wayPointMarkAnnotationViewDidTap = Notification.Name("wayPointMarkAnnotationViewDidTap")
}

import UIKit
class WaypointDemoViewController: MissionBaseViewController, UIGestureRecognizerDelegate, ToolBarDelegate, WaypointViewModelDelegate {
    private lazy var vm = WaypointViewModel(delegate: self)
    
    var mapView: MKMapView {
        return earthStationVC.mapView
    }
    
    var toolBar: ToolBar = ToolBar(with: ToolBarType.missionWaypoint)

    override func viewDidLoad() {
        super.viewDidLoad()
        addMapTapGesture()
        addToolBar(delegate: vm)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
    }
    
    override func dismissBtnClick() {
        super.dismissBtnClick()
        vm.mapView_clear(mapView: mapView)
    }
    
    deinit {
        print("ImageTransimissionViewController deinit")
        removeNotifications()
    }
    
    override func configNavigationItem() {
        super.configNavigationItem()
        navigationItem.title = "Waypoint Mission Demo"
        
        let settingBtn = UIButton(type: .custom)
        settingBtn .setTitle("Setting", for: .normal)
//        switchBtn .setTitleColor(UIColor.black, for: .normal)
        settingBtn.addTarget(self,action:#selector(showParameterSetting), for: .touchUpInside)
        navigationItem.rightBarButtonItem = UIBarButtonItem(customView: settingBtn)
    }
    
    
    override func setupSubviews() {
        super.setupSubviews()
        addNotifications()
    }
    
    
    
    //MARK: - Parameter
    @objc func showParameterSetting() {
        let wayPointParameterViewController = WayPointParameterViewController()
        wayPointParameterViewController.callBack = {[weak self] in
            guard let self = self else { return }
            print("wayPointParameterViewController Call back reload Some Data in \(self.description)")
            self.vm.mapView_updateAddIcons(mapView: self.mapView)
            self.vm.mapView_updateConnectLines(mapView: self.mapView)
            self.vm.mapview_update_heightLable(waypoint: WayPointManager.shared.selectedWaypointIndex, mapView: self.mapView)
        }
        let nav = UINavigationController(rootViewController: wayPointParameterViewController)
        present(nav, animated: true, completion: nil)
    }
    //MARK: - MapView
    func addMapTapGesture() {
        let mapTapGesture =  UITapGestureRecognizer(target: self, action: #selector(mapViewDidTap(_:)))
        mapTapGesture.delegate = self
        mapView.addGestureRecognizer(mapTapGesture)
    }
    
    @objc func mapViewDidTap(_ gesture: UITapGestureRecognizer) {
        guard gesture.state == .ended else { return }
        vm.add(element: vm.missionStatus, touchPoint: gesture.location(in: mapView), mapView: mapView)
    }
    
    func wayPointMarkAnnotationViewDidMoved(notification: Notification){
        vm.mapView_update_wayPointMarkAnnotationViewDidMoved(notification: notification)
    }
    
    func addAnnotationViewDidTap(notification: Notification) {
        vm.mapView_update_addAnnotationViewDidTap(notification: notification)
    }
    func wayPointMarkAnnotationViewDidTap(notification: Notification) {
        vm.mapView_update_wayPointMarkAnnotationViewDidTap(notification: notification)
    }
    
    // VM delegate
    func deleteSelectedElemet() {
        vm.mapView_remove_selectedElement(missinStatus: vm.missionStatus, mapView: mapView)
    }
    
    func switchViewType() {
        switchBtnClick()
    }
    
    func showAlert(_ alert: UIAlertController) {
        self.present(alert, animated:  true , completion:  nil )
    }
    
    //MARK: - Action
    override func startBtnClick(_ sender: UIButton) {
        print("startBtnClick")
        vm.executeMission(5, .waypoint) { (error) in
            if let _ = error {
                print("executeMission failed ")
            } else {
                print("executeMission succeed ")
            }
        }
        
   }
   
    override func stopBtnClick(_ sender: UIButton) {
       print("stopBtnClick")
        vm.exitMission{ (error) in
            
        }
   }
   
    override func pauseBtnClick(_ sender: UIButton) {
       print("pauseBtnClick")
        vm.pauseMission{ (error) in
            
        }
   }
   
    override func resumeBtnClick(_ sender: UIButton) {
       print("resumeBtnClick")
        vm.resumeMission{ (error) in
            
        }
   }
    
    // MARK: - Notification
    @objc func recive(notification: Notification) {
        switch notification.name {
        case .wayPointMarkAnnotationViewDidMoved:
            wayPointMarkAnnotationViewDidMoved(notification: notification)
        case .addAnnotationViewDidTap:
            addAnnotationViewDidTap(notification: notification)
        case .wayPointMarkAnnotationViewDidTap:
            wayPointMarkAnnotationViewDidTap(notification: notification)
            
        default:
            break
        }
    }
    func addNotifications() {
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(recive(notification:)),
                                               name: NSNotification.Name.wayPointMarkAnnotationViewDidMoved,
                                               object: nil)
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(recive(notification:)),
                                               name: NSNotification.Name.wayPointAddAnnotationViewDidMoved,
                                               object: nil)
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(recive(notification:)),
                                               name: NSNotification.Name.addAnnotationViewDidTap,
                                               object: nil)
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(recive(notification:)),
                                               name: NSNotification.Name.wayPointMarkAnnotationViewDidTap,
                                               object: nil)
    }
    
    func removeNotifications() {
        NotificationCenter.default.removeObserver(self, name: NSNotification.Name.wayPointMarkAnnotationViewDidMoved, object: nil)
        NotificationCenter.default.removeObserver(self, name: NSNotification.Name.wayPointAddAnnotationViewDidMoved, object: nil)
        NotificationCenter.default.removeObserver(self, name: NSNotification.Name.addAnnotationViewDidTap, object: nil)
        NotificationCenter.default.removeObserver(self, name: NSNotification.Name.wayPointMarkAnnotationViewDidTap, object: nil)
    }
    

}

// MARK: - AUTELNavigationDelegate

extension WaypointDemoViewController {
    
    func onNavigationMissionStatusChanged(_ missionStatus: AUTELMissionProgressStatus!) {
        guard DroneConnection.shared.isConnected() else {
            return
        }
        
//            DispatchQueue.main.async {
//
//                if let oldMissionStatus = self.currentMissionProgressStatus as? AUTELWaypointMissionStatus ,let mcMissionEarthCtl = self.earthVC {
//
//                    if let newMissionStatus = missionStatus as? AUTELWaypointMissionStatus {
//
//                        if newMissionStatus.execState == .pause {
//                            if mcMissionEarthCtl.currentMissionStatus != .pause {
//                                MCMissionManager.shared.missionStatus.onNext(.pause)
//                                mcMissionEarthCtl.missionTipsStatus = .pause
//                                let txt = local(text: "Toast_Message_Mission_Pause_Success") as NSString
//                                ToastManager.shared.show(title: txt as String)
////                                SystemMessageCenter.shared.insertAMessageEvent(type: MCMessageEventType.AircraftPauseSuccessForMission)
//                            }
//                        } else if newMissionStatus.execState == .moving {
//                            if mcMissionEarthCtl.currentMissionStatus != .flying {
//                                MCMissionManager.shared.missionStatus.onNext(.flying)
//                            }
//
//                            if oldMissionStatus.execState == .pause {
//                                //从暂停恢复时特殊处理
//                                let txt = local(text: "Toast_Message_Mission_Resume_Success") as NSString
//                                ToastManager.shared.show(title: txt as String)
////                                SystemMessageCenter.shared.insertAMessageEvent(type: MCMessageEventType.AircraftResumeSuccessForMission)
//    //                            if self.currentMode == .missionWaypoint {
//    //                                self.mcMissionEarthCtl().missionTipsStatus = .inWayPointMisstion
//    //                                let string = "going to way point".fLocal("MissionFilght") + "\(newMissionStatus.targetWaypointIndex)"
//    //                                MCMissionManager.shared.tips.onNext(string)
//    //                                SpeechManager.shared.speak(text: string, clear: true)
//    //                            } else {
//    //                                self.mcMissionEarthCtl().missionTipsStatus = .inMappingMisstion
//    //                            }
//                            } else if AutelMCState.shared.flightMode == .AutelMCFlightModeTakeoff {
//                                if mcMissionEarthCtl.missionTipsStatus != .takeOff {
//    //                                self.mcMissionEarthCtl().missionTipsStatus = .takeOff
//                                }
//                            }
//
//                        } else if newMissionStatus.execState == .goHome {
//                            if mcMissionEarthCtl.currentMissionStatus != .missionGoHome {
//                                MCMissionManager.shared.missionStatus.onNext(.missionGoHome)
//                                mcMissionEarthCtl.missionTipsStatus = .goToLanding
//                            }
//                        } else if newMissionStatus.execState == .landing {
//                            mcMissionEarthCtl.missionTipsStatus = .landing
//                        } else if newMissionStatus.execState == .finish {
//                            mcMissionEarthCtl.missionTipsStatus = .finish
//                            if mcMissionEarthCtl.currentMissionStatus != .preview {
//                                MCMissionManager.shared.missionStatus.onNext(.preview)
//                                if (oldMissionStatus.execState == .goHome) {
//    //                                MCMissionManager.shared.missionStatus.onNext(.missionFinish)
////                                    SystemMessageCenter.shared.insertAMessageEvent(type: MCMessageEventType.AircraftFinishSuccessForMission)
//                                    let txt = local(text: "Toast_Message_Mission_Finish_Success") as NSString
//                                    ToastManager.shared.show(title: txt as String)
//                                } else {
//                                    //任务被中断退出
//                                    let txt = local(text: "Toast_Message_Mission_Exit_Success") as NSString
//                                    ToastManager.shared.show(title: txt as String)
////                                    SystemMessageCenter.shared.insertAMessageEvent(type: MCMessageEventType.AircraftExitSuccessForMission)
//                                }
//
//                                self.saveMissionMisstionFinish()
//                            }
//                        }
//                    }
//                }
//
//                self.currentMissionProgressStatus = missionStatus
//            }
        }
    
    
}
