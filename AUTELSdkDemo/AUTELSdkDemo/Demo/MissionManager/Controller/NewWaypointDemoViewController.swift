//
//  NewWaypointMissionViewController.swift
//  AUTELSdkDemo
//
//  Created by jiangguoxi on 20.5.23.
//  Copyright © 2023 AUTEL. All rights reserved.
//

import UIKit
import Toaster

class NewWaypointDemoViewController: MissionBaseViewController {
    
    var drone: AUTELDrone? {
        return DroneConnection.shared.drone
    }
    
    var waypointHandler: AUTELWaypointMissionHandler? {
        return drone?.mainController.navigationManager.waypointMissionHandler
    }
    
    var outputModel: AUTELPathPlanningOutputModel?

    override func viewDidLoad() {
        super.viewDidLoad()

    }
    

    func pathPlan() {
        let inputModel = createWaypoints()
        outputModel = AUTELMissionPathPlanTool.wayPointPathConvert(inputModel)
        Toast(text: "plan resut:\(outputModel?.flyTime)").show()
        
    }
    
    override func pauseBtnClick(_ sender: UIButton) {
        waypointHandler?.pauseMissionExecution(completion: { err in
            
        })
    }
    
    override func stopBtnClick(_ sender: UIButton) {
        waypointHandler?.stopMissionExecution(.goHome)
    }
    
    override func resumeBtnClick(_ sender: UIButton) {
        waypointHandler?.resumeMissionExecution(completion: { err in
            
        })
    }
    
    override func startBtnClick(_ sender: UIButton) {
        
        pathPlan()
        
        let mission = AUTELConvertFileMissionMode()
        mission.guid = String(Int(Date().timeIntervalSinceReferenceDate)) as NSString
        mission.missionId = 1
        mission.finishMode = 1
        mission.totalTimes = Int32(outputModel?.flyTime ?? 0)
        mission.totalDistance = Int32(outputModel?.flyLength ?? 0)
        
        mission.altitudeType = 0 //航点高度类型：0是相对高度，1是海拔高度
        mission.lostConnectAction = AUTELPathPlanningLostActionType.continue
        mission.lines = outputModel?.lineInfos ?? [] //执行的航线信息
        
        let path = AUTELMissionPathPlanTool.mcMissionConvert(toFile: mission) ?? ""

        waypointHandler?.uploadMissionFile(path, withProgress: { progress in
            Toast(text: "upload progress:\(progress)").show()
        }, withCompletion: {[weak self] err in
            Toast(text: "upload complete:Err:\(err)").show()

            if err == nil {
                self?.waypointHandler?.startMissionExecution(completion: { err in
                    Toast(text: "start mission err:\(err?.localizedDescription)").show()
                })
            }
        })
        
    }
    
    func createWaypoints() -> AUTELWayPointPathInputModel {
        
        var coors: [AUTELPathCoordinate3D] = [
            AUTELPathCoordinate3D(CLLocationCoordinate2D(latitude: 22.2333332, longitude: 113.2233222), altitude: 60),
            AUTELPathCoordinate3D(CLLocationCoordinate2D(latitude: 22.2333432, longitude: 113.2232322), altitude: 60),
            AUTELPathCoordinate3D(CLLocationCoordinate2D(latitude: 22.2333532, longitude: 113.2233422), altitude: 60)]
        var points = coors.enumerated().map { (idx: Int, coor: AUTELPathCoordinate3D) -> AUTELWayPointPathModel in
            var model = AUTELWayPointPathModel()
            model.latitude = coor.latitude
            model.longitude = coor.longitude
            model.altitude = CLLocationDegrees(coor.altitude)
            model.speed = 8
            model.radius = idx == 1 ? 20.0 : 0
            model.heading_Mode = 1
            
            model.interestingPoint = AUTELPathCoordinate3D(CLLocationCoordinate2D(latitude: 22.2335532, longitude: 113.2235422), altitude: 50)
            
            let action = AUTELPathPlanningAction()
            action.droneYaw = 30
            action.gimbalPitch = 90
            action.cameraInterval = 10
            action.actionTimeLen = 0
            action.cameraActionType = Int32(CameraAction.distanceTakePhoto.rawValue)
            action.triggerMode = 0
            model.missionActions = [action]
            return model
        }
        
        let inputModel = AUTELWayPointPathInputModel()
        inputModel.homeLLA = coors.first!
        inputModel.uavIniLLA = coors.first!
        
        inputModel.taskCompAct = 1
        
        inputModel.vertexArr = points
        
        return inputModel
    }
    
}

