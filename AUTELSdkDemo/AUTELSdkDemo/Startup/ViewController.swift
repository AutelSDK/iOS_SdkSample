//  ViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/1.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit
import SnapKit



class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupSubView()
        listData = makeDisplayDatas()
    }
    
    //MARK: configs
    private func setupSubView() {
        
        view.addSubview(tableView)
        tableView.snp.makeConstraints { (make) in
            make.edges.equalToSuperview()
            make.size.equalToSuperview()
        }
    }
    
    func makeDisplayDatas() -> [[CellItem]] {
        
        let aircraftStatusItem = CellItem("AircraftStatus Demo", { [weak self] _ in
            guard let strongSelf = self else { return }
            let nav = UINavigationController(rootViewController: AircraftStatusViewController())
            nav.modalPresentationStyle = .fullScreen
            strongSelf.present(nav, animated: true, completion: nil)
        })
        
        let imageTransimissionItem = CellItem("Image Transimission Demo", { [weak self] _ in
            guard let strongSelf = self else { return }
            let nav = UINavigationController(rootViewController: ImageTransimissionViewController())
            nav.modalPresentationStyle = .fullScreen
            strongSelf.present(nav, animated: true, completion: nil)
        })
        
        let cameraItem = CellItem("Camera Demo", { [weak self] _ in
            guard let strongSelf = self else { return }
            let nav = UINavigationController(rootViewController: CameraActionsViewController())
            nav.modalPresentationStyle = .fullScreen
            strongSelf.present(nav, animated: true, completion: nil)
        })
        
        let missionItem = CellItem("Mission Demo", { [weak self] _ in
            guard let strongSelf = self else { return }
            let nav = UINavigationController(rootViewController: MissionManagerViewController())
            nav.modalPresentationStyle = .fullScreen
            strongSelf.present(nav, animated: true, completion: nil)
        })
        
        let gimbalItem = CellItem("Gimbal Demo", { [weak self] _ in
            guard let strongSelf = self else { return }
            let nav = UINavigationController(rootViewController: GimbalDemoViewController())
            nav.modalPresentationStyle = .fullScreen
            strongSelf.present(nav, animated: true, completion: nil)
        })
        
        let sendVirtualJoystickControlItem = CellItem("Send Virtual Joystick Control", { [weak self] _ in
            self?.sendVirtualJoystickControlCommand()
        })
        
        return [[aircraftStatusItem, imageTransimissionItem, cameraItem, missionItem, gimbalItem, sendVirtualJoystickControlItem]]

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
        let reuseID = NSStringFromClass(UITableViewCell.classForCoder())
        let cell = tableView.dequeueReusableCell(withIdentifier: reuseID, for: indexPath)
        
        let item = listData[indexPath.section][indexPath.row]
        cell.textLabel?.text = item.0
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        let item = listData[indexPath.section][indexPath.row]
        item.1?(indexPath)
        
    }
    
    //MARK: property
    private var listData: [[CellItem]] = []
    
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

extension ViewController {
    
    //MARK: - 发送虚拟摇杆按键指令
        
    private func sendVirtualJoystickControlCommand() {
                
        let model = AUTELRCVirtualJoystickControlModel.init()
        model.rightVerticalPole = 100
        model.generalKey = .undefined
        AirLinkConnection.shared.sendVirtualJoystickControlCommand(model) { [weak self] (error) in
            if let _ = error {
                DispatchQueue.main.async {
                    self?.view.makeToast("error:\(error?.localizedDescription ?? "nil")")
                }
            }
            
            DispatchQueue.main.async {
                self?.view.makeToast("发送虚拟摇杆按键指令成功")
            }
        }
    }
    
}
