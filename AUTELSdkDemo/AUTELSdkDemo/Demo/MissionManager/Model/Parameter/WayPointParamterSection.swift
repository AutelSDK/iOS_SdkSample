//
//  WayPointParamterSection.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/10.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

protocol WayPointParameterCellSetting {
    var type: MenuItemTpye? {get set}
}

protocol WayPointParameterCellProtocl {
    var title: String {get set }
    var value: String {get set }
    
    init(title: String, value: String)
}

class WayPointParameterCellModel: WayPointParameterCellProtocl, WayPointParameterCellSetting {
    var type: MenuItemTpye?
    
    var value: String
    var title: String
    
    convenience init(title: String, value: String, type: MenuItemTpye? = nil) {
        self.init(title: title, value: value)
        self.type = type
    }
    required init(title: String, value: String) {
        self.title = title
        self.value = value
    }
}

class WayPointParameterSection {
    var expand: Bool
    let section: String
    let rows: [WayPointParameterCellModel]

    init(expand: Bool, section: String, rows: [WayPointParameterCellModel]) {
        self.expand = expand
        self.section = section
        self.rows = rows
    }
}
