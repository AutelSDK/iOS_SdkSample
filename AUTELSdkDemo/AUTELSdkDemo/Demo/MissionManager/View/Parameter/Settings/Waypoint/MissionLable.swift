//
//  MissionLable.swift
//  AutelGen2
//
//  Created by Autel-Hero on 2019/10/8.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import Foundation

class MissionLable: UILabel {

    override init(frame: CGRect) {
        super.init(frame: frame)
        self.textAlignment = .center
        self.textColor = UIColor.white
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

}

class MissionTextField: UITextField {
    
    
    
    let numRegularExpression = try? NSRegularExpression(pattern: "^\\-?(\\d*)$", options: .caseInsensitive)
    var parentViewType: UIView.Type?
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.textAlignment = .center
        self.textColor = UIColor.white
        self.keyboardType = .numberPad
        self.returnKeyType = .done
        self.adjustsFontSizeToFitWidth = true
        self.autocorrectionType = .no
        self.autocapitalizationType = .none
//        self.clearsOnInsertion = true
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
