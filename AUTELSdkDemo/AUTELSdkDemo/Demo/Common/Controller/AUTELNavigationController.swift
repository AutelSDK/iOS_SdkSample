//
//  AUTELNavigationController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/1.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation

class AUTELNavigationController: UINavigationController, UIGestureRecognizerDelegate, UINavigationControllerDelegate {
    override func viewDidLoad() {
        super.viewDidLoad()
        
        delegate = self
        interactivePopGestureRecognizer?.delegate = self
    }
    
    func gestureRecognizerShouldBegin(_ gestureRecognizer: UIGestureRecognizer) -> Bool {
        if gestureRecognizer == navigationController?.interactivePopGestureRecognizer {
            return viewControllers.count > 1
        } else {
            return true
        }
    }
    
    func navigationController(_ navigationController: UINavigationController, didShow viewController: UIViewController, animated: Bool) {
        interactivePopGestureRecognizer?.isEnabled = viewControllers.count > 1
    }
}
