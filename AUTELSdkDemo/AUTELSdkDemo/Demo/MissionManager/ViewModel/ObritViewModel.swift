//
//  ObritViewModel.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/10.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation



class ObritViewModel: NSObject {
    
    enum ObritMissionStep {
        case idle
        case executingOrbitMission1
        case executingOrbitMission2
    }
    
    
    var missionStep = ObritMissionStep.idle
    
    var currentFlightMode: AUTELMainControllerFlightMode = AUTELMainControllerFlightMode.AutelMCFlightModeUnknow
    
    
}

extension ObritViewModel {
    
    func updateFlightMode(flightMode: AUTELMainControllerFlightMode) {
        currentFlightMode = flightMode
    }
    
    func missionDidStart() {
        if missionStep == .executingOrbitMission1 {
            print("OrbitMission1 did start")
            //开始录像
            startRecording()
        } else if missionStep == .executingOrbitMission2 {
            print("OrbitMission2 did start")
        }
    }
    
    func missionDidPause() {
        print("OrbitMission2 did pause")
    }
    
    func missionDidResume() {
        print("OrbitMission2 did resume")
    }
    
    func missionDidStop() {
        if missionStep == .executingOrbitMission1 {
            executeOrbitMission2 { (error) in
                
            }
        } else if missionStep == .executingOrbitMission2 {
            missionStep = .idle
            //停止录像
            stopRecording()
        }
    }
    
}


// MARK: - Check and start the mission
extension ObritViewModel {
   
    func executeOrbitMission(completionHandler: @escaping (_ error: Error?) -> ()) {
        
        //执行第一个 orbit misson
        self.executeOrbitMission1 { (error1) in
            
        }
    }
    
    func executeOrbitMission1(completionHandler: @escaping (_ error: Error?) -> ()) {
        print("OrbitMission1 开始执行")
        missionStep = .executingOrbitMission1
        
        //上传 orbit misson数据
        let orbitMission = AUTELOrbitMission.init()
        orbitMission.surroundRadius = 30
        orbitMission.orbitAltitude = 20
        orbitMission.hotPoint = CLLocationCoordinate2DMake(22.5984680, 113.9989462)
        orbitMission.heading = .towardsCenter
        orbitMission.turns = 1
        
        DroneConnection.shared.drone?.mainController.navigationManager.hotpointMissionHandler.prepare(orbitMission, withProgress: { (progress) in
            print("OrbitMission1 progress \(progress)")
        }, withCompletion: { (error) in
            print("准备OrbitMission1 完成 \(String(describing: error))")
            DroneConnection.shared.drone?.mainController.navigationManager.hotpointMissionHandler.startMissionExecution(completion: { (error) in
                print("OrbitMission1 开始执行 error = \(String(describing: error))")
                completionHandler(error)
            })
        })
    }
    
    func executeOrbitMission2(completionHandler: @escaping (_ error: Error?) -> ()) {
        print("OrbitMission2 开始执行")
        missionStep = .executingOrbitMission2
        
        //上传 orbit misson数据
        let orbitMission = AUTELOrbitMission.init()
        orbitMission.surroundRadius = 30
        orbitMission.orbitAltitude = 40
        orbitMission.hotPoint = CLLocationCoordinate2DMake(22.5984680, 113.9989462)
        orbitMission.heading = .towardsCenter
        orbitMission.turns = 1
        
        DroneConnection.shared.drone?.mainController.navigationManager.hotpointMissionHandler.prepare(orbitMission, withProgress: { (progress) in
            print("OrbitMission2 progress \(progress)")
        }, withCompletion: { (error) in
            print("准备OrbitMission2 完成 \(String(describing: error))")
            DroneConnection.shared.drone?.mainController.navigationManager.hotpointMissionHandler.startMissionExecution(completion: { (error) in
                print("OrbitMission2 开始执行 error = \(String(describing: error))")
                completionHandler(error)
            })
        })
    }
    
    func startRecording() {
        //发送命令
        CameraCommandDeliver.setWorkMode(.recordVideo) { [weak self] (error) in
            CameraCommandDeliver.startRecording { (error) in
                if let err = error {
                    print("start recording error: \(err.localizedDescription)")
                    return
                }
                print("startRecording")
            }
        }
    }
    
    func stopRecording() {
        //发送命令
        CameraCommandDeliver.stopRecording { (error) in
            if let err = error {
                print("stop recording error: \(err.localizedDescription)")
                return
            }
            print("stopRecording")
        }
    }
}

// MARK: - 执行暂停、继续、退出任务
extension ObritViewModel {
    
    /// Execute suspended mission
    func pauseMission(completionHandler: @escaping (_ error: Error?) -> ()) {
        DroneConnection.shared.drone?.mainController.navigationManager.hotpointMissionHandler.pauseMissionExecution(completion: { (error) in
            if let err = error {
                print("pause waypoint error: \(err.localizedDescription)")
                DispatchQueue.main.async {
                   
                }
            } else {

            }
            completionHandler(error)
        })
        
    }
    
    ///Execute continue mission
    func resumeMission(completionHandler: @escaping (_ error: Error?) -> ()) {

        DroneConnection.shared.drone?.mainController.navigationManager.hotpointMissionHandler.resumeMissionExecution(completion: { (error) in
            if let err = error {
                print("resume waypoint error: \(err.localizedDescription)")
                DispatchQueue.main.async {
                    
                }
            } else {

            }
            completionHandler(error)
        })
    }
    
    ///Perform exit mission
    func exitMission(completionHandler: @escaping (_ error: Error?) -> ()) {
        DroneConnection.shared.drone?.mainController.navigationManager.hotpointMissionHandler.stopMissionExecution(completion: { [weak self] (error) in
            guard let strongSelf = self else { return }
            if let err = error {
                DispatchQueue.main.async {
                    
                }
                print("exit waypoint mission error: \(err.localizedDescription)")
                
            } else {

            }
            completionHandler(error)
        })

    }
}

