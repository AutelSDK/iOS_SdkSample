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

class MissionManagerViewController: BaseViewController, UITableViewDelegate, UITableViewDataSource {


    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupSubView()
        listData = makeDisplayDatas()
    }
    
    override func configNavigationItem() {
        super.configNavigationItem()
        navigationItem.title = "Mission Demo"
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
        let wpMissionItem = CellItem("Waypoint point Demo", { [weak self] _ in
            guard let strongSelf = self else { return }
            let nav = UINavigationController(rootViewController: WaypointDemoViewController())
            nav.modalPresentationStyle = .fullScreen
            strongSelf.present(nav, animated: true, completion: nil)
        })
        
        let orbitMissionItem = CellItem("Orbit Demo", { [weak self] _ in
            guard let strongSelf = self else { return }
            let nav = UINavigationController(rootViewController: OrbitDemoViewController())
            nav.modalPresentationStyle = .fullScreen
            strongSelf.present(nav, animated: true, completion: nil)
        })
        
        let trackMissionItem = CellItem("Track Demo", { [weak self] _ in
            guard let strongSelf = self else { return }
            strongSelf.view.makeToast("TO DO Track Demo")
        })
        
        return [[wpMissionItem, orbitMissionItem, trackMissionItem]]

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

