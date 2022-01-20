//
//  MissionManagerViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/7.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit
import SnapKit
import Toast_Swift

typealias AircraftStatusCellItem = (String, String, ((IndexPath) -> Void)?)

class AircraftStatusViewController: BaseViewController, UITableViewDelegate, UITableViewDataSource {

    var parameters = AircraftStatusParameters()

    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupSubView()
        listData = makeDisplayDatas()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        // 开始接收数据源并刷新 UI, 重新开始订阅告警消息
        super.viewWillAppear(animated)

        self.registerProtocol()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        // 停止接收数据源停止刷新 UI,,还要取消订阅告警消息
        super.viewWillDisappear(animated)
        print("\(self.classIdentifier).viewWillDisappear")
        self.removeProtocol()
 
    }
    
    deinit {
        print("\(self.classIdentifier) deinit")
    }
    
    override func configNavigationItem() {
        super.configNavigationItem()
        navigationItem.title = "AircraftStatus Demo"
    }
    
    //MARK: configs
    private func setupSubView() {
        
        view.addSubview(tableView)
        tableView.snp.makeConstraints { (make) in
            make.edges.equalToSuperview()
            make.size.equalToSuperview()
        }
    }

    private func initializeSDCardState() {
        CameraConnection.shared.camera?.getSDCardInfo(completion:
            { (sdCardState, error) in
                if error == nil {
                    if let sdState = sdCardState {
                        self.parameters.isSDInsert = sdState.isInserted
                        self.parameters.isSDFull = sdState.isFull
                        self.parameters.isSDInitializing = sdState.isInitializing
                        self.parameters.isSDInvalidFormat = sdState.isInvalidFormat
                        self.parameters.SDhasError = sdState.hasError
                        self.parameters.remainSDCapacity = Float(sdState.remainingSpaceInMegaBytes)
                        self.updateUI()
                    }
                } else {
                    print("Failed to get sd card information")
                }
        })
    }
    
    func makeDisplayDatas() -> [[AircraftStatusCellItem]] {
        let wpMissionItem = AircraftStatusCellItem("Drone connected state", parameters.droneConnectedState, { [weak self] _ in
            guard let strongSelf = self else { return }

        })
        
//        let compassItem = AircraftStatusCellItem("Compass", parameters.compassStatus, { [weak self] _ in
//            guard let strongSelf = self else { return }
//            strongSelf.view.makeToast("TO DO Orbit Demo")
//        })
        
        let flightModeItem = AircraftStatusCellItem("FlightMode", parameters.mainModeStatus, { [weak self] _ in
            guard let strongSelf = self else { return }
          
        })
        
        let visionItem = AircraftStatusCellItem("Vision", parameters.visionStatus, { [weak self] _ in
            guard let strongSelf = self else { return }
       
        })
        
//        let rcModeItem = AircraftStatusCellItem("RCMode", parameters.RCMode.displayName()!, { [weak self] _ in
//            guard let strongSelf = self else { return }
//            strongSelf.view.makeToast("TO DO Track Demo")
//        })
        
        let rcBatteryItem = AircraftStatusCellItem("RCBattery", "\(parameters.remainRCBattery) %", { [weak self] _ in
            guard let strongSelf = self else { return }

        })
        
        let aircraftBatteryItem = AircraftStatusCellItem("AircraftBattery", parameters.droneBatteyState, { [weak self] _ in
            guard let strongSelf = self else { return }
         
        })
        
        let aircraftBatteryTemperatureItem = AircraftStatusCellItem("AircraftBatteryTemperature", parameters.unitBatteryTem, { [weak self] _ in
            guard let strongSelf = self else { return }
       
        })
        
//        let videoItem = AircraftStatusCellItem("Video", parameters.radioSignalStatus, { [weak self] _ in
//            guard let strongSelf = self else { return }
//            strongSelf.view.makeToast("TO DO Track Demo")
//        })
        
        let gimbalItem = AircraftStatusCellItem("Gimbal", parameters.gimbalStatus, { [weak self] _ in
            guard let strongSelf = self else { return }
  
        })
        
        let SDCardItem = AircraftStatusCellItem("SDCard", parameters.SDCardStatus, { [weak self] _ in
            guard let strongSelf = self else { return }

        })
        
        let flashItem = AircraftStatusCellItem("Flash memory", parameters.EMMCStatus, { [weak self] _ in
            guard let strongSelf = self else { return }

        })
        
        
        return [[wpMissionItem, flightModeItem, visionItem, rcBatteryItem, aircraftBatteryItem, aircraftBatteryTemperatureItem, gimbalItem, SDCardItem, flashItem]]

    }
    
    //MARK: tableView
    func numberOfSections(in tableView: UITableView) -> Int {
        return listData.count
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        let sectionDatas = listData[section]
        return sectionDatas.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell: UITableViewCell? = nil
        cell = tableView.dequeueReusableCell(withIdentifier: "value1cell")
        if cell == nil {
            cell = UITableViewCell(style: .value1, reuseIdentifier: "value1cell")
        }
        
        let item = listData[indexPath.section][indexPath.row]
        cell?.textLabel?.text = item.0
        cell?.detailTextLabel?.text = item.1
        
        return cell!
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        let item = listData[indexPath.section][indexPath.row]
        item.2?(indexPath)
        
    }
    
    //MARK: property
    private var listData: [[AircraftStatusCellItem]] = []
    
    lazy var tableView: UITableView = {
        let table = UITableView(frame: CGRect(), style: .plain)
        table.delegate = self
        table.dataSource = self
        table.rowHeight = 50
//        table.backgroundColor = UIColor.white
        table.register(UITableViewCell.classForCoder(), forCellReuseIdentifier: NSStringFromClass(UITableViewCell.classForCoder()))
        table.tableFooterView = UIView()
        return table
        
    }()
}




// MARK: - Status
extension AircraftStatusViewController:
    DroneProtocol,
    MainControllerProtocol,
    RemoteControllerProtocol,
    BatteryProtocol,
    CameraProtocol,
    GimbalProtocol,
FlightAssistantProtocol {
    
    func updateUI() {
        listData = makeDisplayDatas()
        DispatchQueue.main.async {
            self.tableView.reloadData()
        }
        
    }
    fileprivate func registerProtocol() {
        DroneConnection.shared.addProtocol(self)
        MainControllerConnection.shared.addProtocol(self)
        RemoteControllerConnection.shared.addProtocol(self)
        BatteryConnection.shared.addProtocol(self)
        CameraConnection.shared.addProtocol(self)
        GimbalConnection.shared.addProtocol(self)
        FlightAssistantConnection.shared.addProtocol(self)
       
    }
    
    fileprivate func removeProtocol() {
        DroneConnection.shared.removeProtocol()
        MainControllerConnection.shared.removeProtocol()
        RemoteControllerConnection.shared.removeProtocol()
        BatteryConnection.shared.removeProtocol()
        CameraConnection.shared.removeProtocol()
        GimbalConnection.shared.removeProtocol()
        FlightAssistantConnection.shared.removeProtocol()
    }
    
    //** MARK: - DroneProtocol
    func device(_ device: AUTELDevice!,
                didConnectionStatusChanged status: AUTELDeviceConnectionStatus) {
        if status == .ConnectionBroken {
            parameters.isDeviceConnected = false
        } else {
            parameters.isDeviceConnected = true
        }
        self.updateUI()
    }
    
    // 飞控参数
    func mainController(_ mc: AUTELDroneMainController!, didUpdate state: AUTELMCSystemState!) {
        //** 更新状态
        if let fcState = state {
            parameters.isDeviceConnected = true
            parameters.gpsSignalStrength = fcState.gpsSignalLevel
            let flightMode = fcState.mainMode
            if parameters.flightMode != flightMode {
                parameters.flightMode = flightMode
                self.updateUI()
            }
        }
    }
    
    // 飞机电池
    func battery(_ battery: AUTELBattery!, didUpdataState state: AUTELBatteryState!) {
        let batteryRemain = state.remainPowerPercent
        let batteryTemp = state.batteryTemperature
        let batteryDiff = state.isBatteryVoltageDiff
        
        var updateUIFlag = false
        
        if batteryDiff != parameters.droneBatteryVoltageDiff {
            parameters.droneBatteryVoltageDiff = batteryDiff
             updateUIFlag = true
        }
        if batteryRemain != parameters.remainDroneBattery {
            parameters.remainDroneBattery = Int(batteryRemain)
            updateUIFlag = true
        }
        if batteryTemp != parameters.batteryTem {
            parameters.batteryTem = batteryTemp
            updateUIFlag = true
        }
        
        if updateUIFlag {
            self.updateUI()
        }
    }
    
    // 遥控器
    func remoteController(_ rc: AUTELRemoteController!, didUpdateRCState rcState: AUTELRCState) {
        // ** RC电池电量
        let batteryRemain = rcState.rcBatteryInfo.mRemainPowerPercent
        if batteryRemain != parameters.remainRCBattery {
            parameters.remainRCBattery = Int(batteryRemain)
            self.updateUI()
        }
    }
    
    // Gimbal
    func gimbalController(_ controller: AUTELDroneGimbal!, didUpdate gimbalState: AUTELDroneGimbalState!) {
        var updateUIFlag = false
        if parameters.isGimbalCalibrating != gimbalState.isCalibrating {
            parameters.isGimbalCalibrating = gimbalState.isCalibrating
            updateUIFlag = true
        }
        if parameters.isGimbalSleepForNoAttitude != gimbalState.isSleepForNoAttitude {
            parameters.isGimbalSleepForNoAttitude = gimbalState.isSleepForNoAttitude
            updateUIFlag = true
        }
        if parameters.isGimbalSleepForRollReachMax != gimbalState.isSleepForRollReachMax {
            parameters.isGimbalSleepForRollReachMax = gimbalState.isSleepForRollReachMax
            updateUIFlag = true
        }
        if parameters.isGimbalRollReachMax != gimbalState.isRollReachMax {
            parameters.isGimbalRollReachMax = gimbalState.isRollReachMax
            updateUIFlag = true
        }
        
        if updateUIFlag {
            self.updateUI()
        }
    }
    
    // SD 卡剩余容量
    func camera(_ camera: AUTELBaseCamera!, didUpdateSDCardState sdCardState: AUTELCameraSDCardState!) {
        
        var updateUIFlag = false
        
        if parameters.isSDInsert != sdCardState.isInserted {
            parameters.isSDInsert = sdCardState.isInserted
            updateUIFlag = true
        }
        if parameters.isSDFull != sdCardState.isFull {
            parameters.isSDFull = sdCardState.isFull
            updateUIFlag = true
        }
        if parameters.isSDInitializing != sdCardState.isInitializing {
            parameters.isSDInitializing = sdCardState.isInitializing
            updateUIFlag = true
        }
        if parameters.isSDInvalidFormat != sdCardState.isInvalidFormat {
            parameters.isSDInvalidFormat = sdCardState.isInvalidFormat
            updateUIFlag = true
        }
        if parameters.SDhasError != sdCardState.hasError {
            parameters.SDhasError = sdCardState.hasError
            updateUIFlag = true
        }
        if parameters.remainSDCapacity != Float(sdCardState.remainingSpaceInMegaBytes) {
            parameters.remainSDCapacity = Float(sdCardState.remainingSpaceInMegaBytes)
            updateUIFlag = true
        }
        
        if updateUIFlag {
            self.updateUI()
        }
    }
    
    // EMMC 卡剩余容量
    func camera(_ camera: AUTELBaseCamera!, didUpdateMMCState mmcState: AUTELCameraSDCardState!) {
        
        var updateUIFlag = false
        
        //注意：MMC也是使用AUTELCameraSDCardState，但MMC的isInserted还是指SD卡的插入状态，MMC不可用isInserted
//        if parameters.isEMMCInsert != mmcState.isInserted {
//            parameters.isEMMCInsert = mmcState.isInserted
//            updateUIFlag = true
//        }
        if parameters.isEMMCFull != mmcState.isFull {
            parameters.isEMMCFull = mmcState.isFull
            updateUIFlag = true
        }
        if parameters.isEMMCInitializing != mmcState.isInitializing {
            parameters.isEMMCInitializing = mmcState.isInitializing
            updateUIFlag = true
        }
        if parameters.isEMMCInvalidFormat != mmcState.isInvalidFormat {
            parameters.isEMMCInvalidFormat = mmcState.isInvalidFormat
            updateUIFlag = true
        }
        if parameters.EMMChasError != mmcState.hasError {
            parameters.EMMChasError = mmcState.hasError
            updateUIFlag = true
        }
        if parameters.remainEMMCCapacity != Float(mmcState.remainingSpaceInMegaBytes) {
            parameters.remainEMMCCapacity = Float(mmcState.remainingSpaceInMegaBytes)
            updateUIFlag = true
        }
        
        if updateUIFlag {
            self.updateUI()
        }
    }

    func flightAssistant(_ assistant: AUTELFlightAssistant!, didUpdateVisionControlState state: AUTELVisionControlState!) {
        var updateUIFlag = false
        //modelB协议
        if parameters.isForwardVisionModuleAbnormal != state.isForwardVisionModuleAbnormal {
            parameters.isForwardVisionModuleAbnormal = state.isForwardVisionModuleAbnormal
            updateUIFlag = true
        }
        if parameters.isDownwardVisionModuleAbnormal != state.isDownwardVisionModuleAbnormal {
            parameters.isDownwardVisionModuleAbnormal = state.isDownwardVisionModuleAbnormal
            updateUIFlag = true
        }
        
        //modelC协议
        //十二路传感器异常情况
        if parameters.isFrontLeftVisualSensorAbnormal != state.isFrontLeftVisualSensorAbnormal {
            parameters.isFrontLeftVisualSensorAbnormal = state.isFrontLeftVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isFrontRightVisualSensorAbnormal != state.isFrontRightVisualSensorAbnormal {
            parameters.isFrontRightVisualSensorAbnormal = state.isFrontRightVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isBackLeftVisualSensorAbnormal != state.isBackLeftVisualSensorAbnormal {
            parameters.isBackLeftVisualSensorAbnormal = state.isBackLeftVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isBackRightVisualSensorAbnormal != state.isBackRightVisualSensorAbnormal {
            parameters.isBackRightVisualSensorAbnormal = state.isBackRightVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isDownLeftVisualSensorAbnormal != state.isDownLeftVisualSensorAbnormal {
            parameters.isDownLeftVisualSensorAbnormal = state.isDownLeftVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isDownRightVisualSensorAbnormal != state.isDownRightVisualSensorAbnormal {
            parameters.isDownRightVisualSensorAbnormal = state.isDownRightVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isRightLeftVisualSensorAbnormal != state.isRightLeftVisualSensorAbnormal {
            parameters.isRightLeftVisualSensorAbnormal = state.isRightLeftVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isRightRightVisualSensorAbnormal != state.isRightRightVisualSensorAbnormal {
            parameters.isRightRightVisualSensorAbnormal = state.isRightRightVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isLeftLeftVisualSensorAbnormal != state.isLeftLeftVisualSensorAbnormal {
            parameters.isLeftLeftVisualSensorAbnormal = state.isLeftLeftVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isLeftRightVisualSensorAbnormal != state.isLeftRightVisualSensorAbnormal {
            parameters.isLeftRightVisualSensorAbnormal = state.isLeftRightVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isUpLeftVisualSensorAbnormal != state.isUpLeftVisualSensorAbnormal {
            parameters.isUpLeftVisualSensorAbnormal = state.isUpLeftVisualSensorAbnormal
            updateUIFlag = true
        }
        if parameters.isUpRightVisualSensorAbnormal != state.isUpRightVisualSensorAbnormal {
            parameters.isUpRightVisualSensorAbnormal = state.isUpRightVisualSensorAbnormal
            updateUIFlag = true
        }
        
        
        if updateUIFlag {
            self.updateUI()
        }
    }
}


