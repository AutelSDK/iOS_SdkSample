//
//  WaypointViewModel.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/10.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation

@objc protocol WaypointViewModelDelegate {
    func deleteSelectedElemet()
    func switchViewType()
    func showAlert(_ alert: UIAlertController)
}

protocol WaypointViewModelInterface {
    var delegate: WaypointViewModelDelegate? {get set}
    init(delegate: WaypointViewModelDelegate?)
}

class WaypointViewModel: NSObject, WaypointViewModelInterface {

    weak var delegate: WaypointViewModelDelegate?
    var missionStatus: MCMissionStatus = .addWaypoint
    
    required init(delegate: WaypointViewModelDelegate?) {
        super.init()
        self.delegate = delegate
    }
}
