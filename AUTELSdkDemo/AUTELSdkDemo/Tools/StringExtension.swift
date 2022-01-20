//
//  StringExtension.swift
//  AutelGen2
//
//  Created by Sreekanth Ruthala on 10/30/17.
//  Copyright © 2017 AUTEL. All rights reserved.
//

import Foundation
let AUTELSignKey = "b7022c97a7d8c9fc47b2c14b8b375a9e"
extension String {

    static func notApplicable() -> String {
        return NSLocalizedString("Not_Applicable", comment: "")
    }

   
    
    /** 中文和表情占2字符,其余都为1 */
    var charCount: Int{
        var count = 0
        let str = NSString(string: self)
        for index in 0..<str.length {
            let code = str.character(at: index)
            if code > 0x4e00 && code <= 0x9fa5 {
                count += 2
            }else{
                count += 1
            }
        }
        return count
    }
}


extension Notification.Name {
    static let IsMiniMap = Notification.Name(rawValue: "IsMiniMap")
}





extension String {
    var addZero: String {
        get {
            switch self {
            case "1", "2", "3", "4", "5", "6", "7", "8", "9":
                return "0" + self
            default:
                return self
            }
        }
    }

    func contains(array: [String]) -> Bool {
        var text = self
        let reg = ".*([A-Z]|[a-z])+.*"
        let pre = NSPredicate(format: "SELF MATCHES %@", reg)
        if pre.evaluate(with: text) {
            text = text.lowercased()
        }
        for i in 0..<array.count {
            let result = text.contains(array[i])
            if result { return true }
        }
        return false
    }

}

