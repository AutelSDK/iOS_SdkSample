//
//  ToorBarAdding.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/14.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

protocol ToolBarAdding {
    var toolBar: ToolBar {get }
}

extension ToolBarAdding where Self: WaypointDemoViewController {
    func addToolBar(delegate: ToolBarDelegate) {
        view.addSubview(toolBar)
        toolBar.delegate = delegate
        print("toolBar = \(toolBar)")
        toolBar.snp.makeConstraints { (maker) in
            maker.top.equalTo(view.snpSafeAreaTop).offset(40)
            maker.left.equalToSuperview().offset(70)
            maker.height.equalTo(50)
        }
    }
}

extension WaypointDemoViewController: ToolBarAdding { }
