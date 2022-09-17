//
//  WaypointViewModel+Mission.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/10.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation
// MARK: - Check and start the mission
extension WaypointViewModel {
   
    func executeMission(_ missionId: Int, _ missionType: MissionType, completionHandler: @escaping (_ error: Error?) -> ()) {
        print("\nFlight steps for mission execution: 1. Check; 2. Start the mission\n");
        
        let mission = creatMissionForMC(missionType)
        
        let handler = DroneConnection.shared.drone?.mainController.navigationManager.waypointMissionHandler
        handler?.prepare(mission, withProgress: { (progress) in
            print("waypoint:\(progress)\n");
         

        }, withCompletion: { (error) in
            if let err = error {
                print("prepare waypoint mission error: " + err.localizedDescription);
                DispatchQueue.main.async {
          
                }
                return
            } else {
                DispatchQueue.main.async {
         
                }
            }

            DispatchQueue.main.asyncAfter(deadline: .now() + 1) {

                handler?.startMissionExecution(completion: { (error) in
                    if let err = error {
                        DispatchQueue.main.async {
                           print("2. Start the mission error: " + err.localizedDescription);
                        }
                           
                    } else {
                            
                        DispatchQueue.main.async {
                   
                       }
                    }
                    completionHandler(error)
                })
                
            }

        })
        
    }
    
    private func creatMissionForMC(_ missionType: MissionType) -> AUTELMCWaypointMission {
        let mission = AUTELMCWaypointMission()
        mission.missionId = 5
        let finishModeIndex = 0
        mission.finishMode = finishModeIndex == 0 ? .goHome : .hover
        mission.totalTimes = 41
        mission.totalDistance = 102
        mission.executeIndex = 0
        mission.executePhotos = 0
        
        mission.guid = "0fd18b3fca64b83089d5c9bad4420c94"//MD5字符串，字符串长度限制32
        mission.missionName = "Waypoint Mission"
       
        if missionType == .waypoint {
            mission.missionType = .waypoint
            mission.addGen2Waypoints(setWayPointForMC())
        } else {
            if missionType == .rectangle {
                mission.missionType = .rectangle
            } else {
                 mission.missionType = .polygon
            }

            mission.addGen2Waypoints(setMappingMissionForMC())
            mission.gridEnable = 0
            
//            var vertexList = [InterestPointModel]()
//            for (_, model) in MCMissionDataManager.shared.waypoints().enumerated() {
//                if let waypoint = model as? MappingVertexPoint {
//                    let copyModel = InterestPointModel()
//                    let coordinate = coordinateAntiCorrectIfNeeded(CLLocationCoordinate2DMake(waypoint.latitude, waypoint.longitude))
//                    copyModel.coord.latitude = coordinate.latitude
//                    copyModel.coord.longitude = coordinate.longitude
//                    copyModel.coord.altitude = CLLocationDegrees(waypoint.altitude)
//                    vertexList.append(copyModel)
//                }
//            }
//
//            mission.vertexList = vertexList
        }
        
        return mission
    }
    
    /// modelC测绘任务（矩形多边形）
    private func setMappingMissionForMC() -> [AUTELWaypointMC] {
        let items = [AUTELWaypointMC]()
//        for (index, coordinate) in MCMissionAnnotationManager.shared.algorithmCoordinates.enumerated() {
//            let mc = AUTELWaypointMC()
//            mc.style = .mapping
//            mc.coordinate = coordinateAntiCorrectIfNeeded(coordinate)
//            let altitude = MCMissionDataManager.shared.airline.taskList[0].mappingMission?.height
//            let speed = MCMissionDataManager.shared.airline.taskList[0].mappingMission?.speed
//            mc.altitude = Float(altitude ?? 60)
//            mc.speed = Float(speed ?? 5)
//            mc.userDefinedHeading = 0
//            mc.headingMode = AUTELWaypointHeadingMode.towardsNext
//
//            mc.groundlap = MCMissionDataManager.shared.airline.taskList[0].mappingMission?.groundResolution ?? 0.77
//            mc.headinglap = MCMissionDataManager.shared.airline.taskList[0].mappingMission?.courseRate ?? 80.0
//            mc.sidelap = MCMissionDataManager.shared.airline.taskList[0].mappingMission?.sideRate ?? 70.0
//            mc.headAngle = MCMissionDataManager.shared.airline.taskList[0].mappingMission?.courseAngle ?? 0
//            mc.cameraPitch = MCMissionDataManager.shared.airline.taskList[0].mappingMission?.pitchAngle ?? 90
//
//            if index < otherPathPlanningParaArr.count {
//                mc.curFlyTime = Float(Int32(otherPathPlanningParaArr[index].curFlyTime))
//                mc.curFlyDistance = Float(Int32(otherPathPlanningParaArr[index].curFlyDistance))
//            }
//
//            items.append(mc)
//        }
        
        return items
    }
    
    /// modelC航点
    private func setWayPointForMC() -> [AUTELWaypointMC] {
        var items = [AUTELWaypointMC]()
        
        typealias dataSetTuple = (curFlyTime: Float, curFlyDistance: Float, waypoint: WayPointModel)
        var dataSets = [dataSetTuple]()
        
        WayPointManager.shared.wayPoints.enumerated().forEach { (index, element) in
            let dataSetTuple = (Float(19*index), Float(36*index), element)
            dataSets.append(dataSetTuple)
        }
        

 
        for i in 0..<dataSets.count {
            let waypoint = AUTELWaypointMC()
            waypoint.coordinate = coordinateAntiCorrectIfNeeded(dataSets[i].waypoint.coordinate)
            waypoint.altitude = dataSets[i].waypoint.height
            waypoint.speed = dataSets[i].waypoint.speed
            waypoint.userDefinedHeading = 0
            waypoint.headingMode = .custom//自定义机头朝向
            waypoint.poiIndex = -1
            waypoint.curFlyTime = dataSets[i].curFlyTime
            waypoint.curFlyDistance = dataSets[i].curFlyDistance
            waypoint.style = .normal
            
           //set cameraPitch
            let pitch: Float = 45
            //set cameraYaw  机头方向
            let Yaw: Float = 45
            let actionPara = AUTELWaypointActionPara()
            actionPara.cameraPitch = pitch
            actionPara.cameraYaw = Yaw
            let action = AUTELWaypointAction()
            action.actionPara = actionPara
            waypoint.actions = [action]

            items.append(waypoint)
        }

        return items
    }
}

// MARK: - 执行暂停、继续、退出任务
extension WaypointViewModel {
    
    /// Execute suspended mission
    func pauseMission(completionHandler: @escaping (_ error: Error?) -> ()) {
        DroneConnection.shared.drone?.mainController.navigationManager.waypointMissionHandler.pauseMissionExecution(completion: { (error) in
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

        DroneConnection.shared.drone?.mainController.navigationManager.waypointMissionHandler.resumeMissionExecution(completion: { (error) in
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
        
        let alertController = UIAlertController (title: "Stop mission", message: "finish action?", preferredStyle: .alert)
        let hoverAction = UIAlertAction(title: "Hover", style: .default, handler: nil)
        let backAction =  UIAlertAction (title: "Go Home", style: .default, handler: { action in
            var wayPointMissionAction = WaypointMissionFinishAction.hover
            switch action.title {
            case "Hover": wayPointMissionAction = .hover
            case "Go Home": wayPointMissionAction = .goHome
            default: break
            }
            DroneConnection.shared.drone?.mainController.navigationManager.waypointMissionHandler.stopMissionExecution(wayPointMissionAction, withCompletion: { [weak self] (error) in
                guard let _ = self else { return }
                if let err = error {
                    DispatchQueue.main.async {
                        
                    }
                    print("exit waypoint mission error: \(err.localizedDescription)")
                    
                } else {
                    
                }
                completionHandler(error)
            })
        })
        alertController.addAction(hoverAction)
        alertController.addAction(backAction)
        
        delegate?.showAlert(alertController)
    }
}

