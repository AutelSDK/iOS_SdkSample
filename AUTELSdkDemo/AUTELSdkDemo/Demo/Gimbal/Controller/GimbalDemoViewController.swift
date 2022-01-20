//
//  CameraActionsViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2021/4/16.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit

class GimbalDemoViewController: BaseViewController, UITableViewDelegate, UITableViewDataSource {


    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupSubView()
        listData = makeDisplayDatas()
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
    
    deinit {
        print("\(self.classIdentifier) deinit")
    }
    
    override func configNavigationItem() {
        super.configNavigationItem()
        navigationItem.title = "Gimbal Demo"
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
        let changeGimbalPitchItem = CellItem("Update Gimbal pitch", { [weak self] _ in
            guard let strongSelf = self else { return }
            strongSelf.setGimbalPitch()
        })
        
        return [[changeGimbalPitchItem]]

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


extension GimbalDemoViewController {
    
    func setGimbalPitch() {
        GimbalChangeSubmission.updateGimbalWithMode(.absoluteAngle, andValue: -30)
    }
    
    
}


