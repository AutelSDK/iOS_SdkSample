//
//  WayPointViewModel+ToolBar.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/14.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation
// MARK: - ToorBar
extension WaypointViewModel: ToolBarDelegate {
    func toolBarDidClickedItem(_ toolBar:ToolBar ,itemTag:Int ,itemIsSelected:Bool) {
        let tag = ToolBarItemTag.init(rawValue: itemTag)
        switch tag {
        case .wapPointButton:
            missionStatus = .addWaypoint
        case .interestButton:
            missionStatus = .addPointOfInterest
        case .deleteAllButton:
            deleteClick()
        case .cameraButton:
            switchClick()
        default:
            print("")
        }
    }
    
    func switchClick() {
        delegate?.switchViewType()
    }
    
    func deleteClick() {
        delegate?.deleteSelectedElemet()
    }
}
