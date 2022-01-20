//
//  WayPointParameterViewController.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/9.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation


class WayPointParameterViewController: BaseViewController {
    
    var callBack: (()->())?
    
    private lazy var viewModel = WaypointParameterViewModel(delegate: self)
    
    private lazy var tableView : UITableView = {
        let tableView = UITableView(frame: CGRect.zero, style: .plain)
        tableView.tableFooterView = UIView()
        tableView.register(WaypointParameterCell.self)
        tableView.register(ExpandHeader.self)
        tableView.delegate = viewModel
        tableView.dataSource = viewModel
        tableView.estimatedRowHeight = 44
        return tableView
    }()
    
    override func configNavigationItem() {
        super.configNavigationItem()
        navigationItem.title = "Waypoint Parameter"
    }
    
    override func dismissBtnClick() {
        super.dismissBtnClick()
        callBack?()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        view.addSubview(tableView)
        tableView.snp.makeConstraints { make in
            make.edges.equalTo(view.safeAreaLayoutGuide.snp.edges)
        }
        
    }
}

extension WayPointParameterViewController: WaypointParameterViewModelDelegate {
    func reloadTableViewSection(_ section: Int) {
        tableView.reloadSections([section], with: .automatic)
    }
    
    func reloadParameterRows(at indexPaths: [IndexPath]) {
        tableView.reloadRows(at: indexPaths, with: .automatic)
    }
}
