//
//  WaypointParameterViewModel.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/10.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation


@objc protocol WaypointParameterViewModelDelegate {
    func reloadParameterRows(at indexPaths: [IndexPath])
    func reloadTableViewSection(_ section: Int)
}

protocol WaypointParameterViewModelInterface {
    var delegate: WaypointParameterViewModelDelegate? {get set}
    init(delegate: WaypointParameterViewModelDelegate?)
}


class WaypointParameterViewModel: NSObject, UITableViewDelegate, UITableViewDataSource, WaypointParameterViewModelInterface {
    var models: [WayPointParameterSection] {
        loadData()
    }
    
    weak var delegate: WaypointParameterViewModelDelegate?
    required init(delegate: WaypointParameterViewModelDelegate?) {
        super.init()
        self.delegate = delegate
    }
    
    
    func loadData() -> [WayPointParameterSection] {
        guard let selectedIndex = WayPointManager.shared.selectedWaypointIndex else {
            return []
        }
        
        return [WayPointParameterSection(expand: true,
                                         section: "point" + " " + "\(selectedIndex + 1)",
                                         rows: [WayPointParameterCellModel(title: "Speed", value: "", type: .slider(type: .speedForWP)),
                                                WayPointParameterCellModel(title: "Height", value: "", type: .slider(type: .height)),
                                                WayPointParameterCellModel(title: "LatLon", value: "", type: .coordinate)])
                //                                              WayPointParameterSection(expand: true,
                //                                                                       section: "Action",
                //                                                                       rows: []
                //                                              )
        ]
    }
    
    func changeState(indexPath: IndexPath) -> Bool {
        let model = models[indexPath.section]
        let row = model.rows[indexPath.row]
        return true
    }
    
    func changeExpand(section: Int) {
        models[section].expand = !models[section].expand
    }
    
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell: WaypointParameterCell = tableView.dequeueReusableCell(for: indexPath)
        let section =  models[indexPath.section]
        let row = section.rows[indexPath.row]
        cell.setupCell(model: row)
        
        let rowType = row.type ?? .slider(type: .speedForWP)
        cell.setupSettinView(type: row.type ?? .slider(type: .speedForWP))
        switch rowType {
        case .slider:
            if case let MenuItemTpye.slider(type: sliderType) = rowType {
                switch sliderType {
                case .speedForWP:
                    cell.missionSliderView.setData(WaypointViewModel.getSpeed(at: indexPath.row).value,
                                                   with: .speedForWP)
                    cell.missionSliderView.newValueDidSetHandler = { value in
                        guard let idex = WayPointManager.shared.selectedWaypointIndex else { return }
                        WaypointViewModel.set(speed: value, at: idex)
                    }
                case .height:
                    cell.missionSliderView.setData(WaypointViewModel.getHeight(at: indexPath.row).value,
                                                   with: .height)
                    cell.missionSliderView.newValueDidSetHandler = { value in
                        guard let idex = WayPointManager.shared.selectedWaypointIndex else { return }
                        WaypointViewModel.set(height: value, at: idex)
                    }
                default: break
                }
                
            }
        case .interestList:
            print("HHH")
        case .coordinate:
            guard let coordinate = WayPointManager.shared.selectedWaypoint?.coordinate else {
                return cell
            }
            cell.latLonView.setCoordinate(coordinate, type: .WGS84)
            cell.latLonView.valueChangedHandler =  { latLonView in
                guard let coordinate = latLonView.coordinate_WGS84 else { return }
                WaypointViewModel.set(coordinate: coordinate)
            }
        default:
            print("HHH")
        }
        return cell
    }
    
    func menuCoordinateText(_ clo: CLLocationCoordinate2D?) -> String {
        guard let cl = clo else {
            return "N/A"
        }
        return String(format: "%.0f.-,%.0f.-", cl.latitude,cl.longitude)
    }
    
    public func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return models[section].expand ? models[section].rows.count : 0
    }

    public func numberOfSections(in tableView: UITableView) -> Int {
        return models.count
    }

    public func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 44.0
    }

    public func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        guard let header = tableView.dequeueReusableHeaderFooterView(withIdentifier: "ExpandHeader") as? ExpandHeader else { return nil }
        let model = models[section]
        header.setHeaderTitle(model.section,
                              delegate: self,
                              section: section,
                              isExpand: model.expand)
        return header
    }
}
extension WaypointParameterViewModel: ExpandHeaderDelegate {
    func didTapSection(header: ExpandHeader, section: Int) {
        changeExpand(section: section)
        delegate?.reloadTableViewSection(section)
    }
}
