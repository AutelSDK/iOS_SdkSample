//
//  BaseViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/1.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit
import AUTELWidget

typealias CellItem = (String, ((IndexPath) -> Void)?)


class BaseViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()

        configNavigationItem()
        setupSubviews()
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
    
    func configNavigationItem() {
        navigationItem.title = "Demo"
        
        let dismissBtn = UIButton(type: .custom)
        dismissBtn .setTitle("back", for: .normal)
//        dismissBtn .setTitleColor(UIColor.black, for: .normal)
        dismissBtn.addTarget(self,action:#selector(dismissBtnClick), for: .touchUpInside)
        navigationItem.leftBarButtonItem = UIBarButtonItem(customView: dismissBtn)
    }
    
    func setupSubviews() {
        view.backgroundColor = UIColor.black
    }
    
    deinit {
        print("\(self.classIdentifier) deinit")
    }
    
    @objc func dismissBtnClick() {
        self.dismiss(animated: true, completion: nil)
    }
    
}


