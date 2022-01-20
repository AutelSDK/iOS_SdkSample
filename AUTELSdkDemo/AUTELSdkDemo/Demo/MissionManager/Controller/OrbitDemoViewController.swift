//
//  OrbitDemoViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/7.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit



class OrbitDemoViewController: MissionBaseViewController {
    
    var vm = ObritViewModel()
    
    var currentMissionStatus: AUTELHotPointMissionStatus?
    
    override func viewDidLoad() {
        super.viewDidLoad()

    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.registerProtocol()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        print("\(self.classIdentifier).viewWillDisappear")
        self.removeProtocol()
    }
    
    deinit {
        print("\(self.classIdentifier).deinit")
    }
    
    override func configNavigationItem() {
        super.configNavigationItem()
        navigationItem.title = "Orbit Mission Demo"
        
        let switchBtn = UIButton(type: .custom)
        switchBtn .setTitle("switch", for: .normal)
//        switchBtn .setTitleColor(UIColor.black, for: .normal)
        switchBtn.addTarget(self,action:#selector(switchBtnClick), for: .touchUpInside)
        navigationItem.rightBarButtonItem = UIBarButtonItem(customView: switchBtn)
    }
    
    
    override func setupSubviews() {
        super.setupSubviews()
        
    }
    
    
    //MARK: Action
    override func startBtnClick(_ sender: UIButton) {
        print("startBtnClick")
        
        vm.executeOrbitMission { (error) in
            print("executeOrbitMission")
        }
   }
   
    override func stopBtnClick(_ sender: UIButton) {
       print("stopBtnClick")
        vm.exitMission { (error) in
            
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
    
  
    private func registerProtocol() {
        MainControllerConnection.shared.addProtocol(self)
        AUTELNavigationDelegateConnection.shared.addProtocol(self)
    }
    
    private func removeProtocol() {
        MainControllerConnection.shared.removeProtocol()
        AUTELNavigationDelegateConnection.shared.removeProtocol()
    }
}


// MARK: - MainControllerProtocol
extension OrbitDemoViewController: MainControllerProtocol {
    
    @objc func mainController(_ mc: AUTELDroneMainController!, didUpdate state: AUTELMCSystemState!) {
        vm.updateFlightMode(flightMode: state.flightMode)
    }
    
}

// MARK: - AUTELNavigationDelegate
extension OrbitDemoViewController: AUTELNavigationDelegate {
    
    func onNavigationMissionStatusChanged(_ missionStatus: AUTELMissionProgressStatus) {
        DispatchQueue.main.async {
           
            if let orbitState = missionStatus as? AUTELHotPointMissionStatus {
                self.printMissionStatus(orbitState)
                if let oldOrbitState = self.currentMissionStatus {
                    if orbitState.execState == .hotPointMissionExecuteStateMoving
                        && oldOrbitState.execState == .hotPointMissionExecuteStateInitializing {
                        print("mission start")
                        self.vm.missionDidStart()
                    }
                } else {
                    if orbitState.execState == .hotPointMissionExecuteStateMoving {
                        print("mission start")
                        self.vm.missionDidStart()
                    }
                }
                
                if let oldOrbitState = self.currentMissionStatus {
                    if orbitState.execState == .hotPointMissionExecuteStatePause
                        && oldOrbitState.execState == .hotPointMissionExecuteStateMoving {
                        print("mission pause")
                        self.vm.missionDidPause()
                    }
                }
                
                if let oldOrbitState = self.currentMissionStatus {
                    if orbitState.execState == .hotPointMissionExecuteStateMoving
                        && oldOrbitState.execState == .hotPointMissionExecuteStatePause {
                        print("mission resume")
                        self.vm.missionDidResume()
                    }
                }
                
                if let oldOrbitState = self.currentMissionStatus {
                    if orbitState.execState == .hotPointMissionExecuteStateFinish
                        && oldOrbitState.execState == .hotPointMissionExecuteStateMoving {
                        print("mission stop")
                        self.vm.missionDidStop()
                    }
                }

                self.currentMissionStatus = orbitState
            }
             
        }
    }
    
    func printMissionStatus(_ orbitState: AUTELHotPointMissionStatus) {
        print("\n\rhotPoint.execState: \(orbitState.execState.rawValue)")
        print("hotPoint.latitude: \(orbitState.hotPoint.latitude)")
        print("hotPoint.longitude: \(orbitState.hotPoint.longitude)")
        print("altitude: \(orbitState.altitude)")
        print("currentRadius: \(orbitState.currentRadius)")
        print("speed: \(orbitState.speed)")
        print("hotpointType: \(orbitState.hotpointType)")
    }
    
}
