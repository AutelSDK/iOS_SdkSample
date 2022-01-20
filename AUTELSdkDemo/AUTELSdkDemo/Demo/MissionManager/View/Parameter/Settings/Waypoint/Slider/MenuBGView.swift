//
//  MenuBGView.swift
//  AutelGen2
//
//  Created by Autel-Hero on 2019/9/30.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import Foundation

class MenuBGView: UIView {
    
    var radius:CGFloat = 5.0

    override init(frame: CGRect) {
        super.init(frame: frame)
        initBGView()
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        fatalError("init(coder:) has not been implemented")
    }

    convenience init() {
        self.init(frame: CGRect.zero)
        initBGView()
    }

    func initBGView() {
        backgroundColor = UIColor(fromHex: 0x3D3D3D, alpha: 0.25)
        //        let blurEffect: UIBlurEffect = UIBlurEffect.init(style: .dark)
        //        let blurView: UIVisualEffectView = UIVisualEffectView.init(effect: blurEffect)
        //        addSubview(blurView)
        //        blurView.snp.makeConstraints({ (maker) in
        //            maker.edges.equalToSuperview()
        //        })
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        roundCorners(corners: [.topLeft, .topRight, .bottomLeft, .bottomRight], radius: radius)
    }


}



