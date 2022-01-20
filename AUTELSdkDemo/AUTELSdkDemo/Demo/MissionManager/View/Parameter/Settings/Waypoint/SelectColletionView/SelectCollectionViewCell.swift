//
//  SelectCollectionViewCell.swift
//  AutelGen2
//
//  Created by Autel-Hero on 2019/9/30.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import UIKit

class SelectCollectionViewCell: UICollectionViewCell {

    @IBOutlet weak var bgView: UIView!

    @IBOutlet weak var img: UIImageView!
    @IBOutlet weak var valueLabel: UILabel!

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code

        img.image = UIImage(named: "disselected_gray")
    }

    deinit {
    }


    /// 加载数据
    ///
    /// - Parameter item: 数据模型
    func load(_ tuple: (text: String, isSelected: Bool)) -> Void {
        valueLabel.text = tuple.text.addZero
        if tuple.isSelected {
            img.image = UIImage(named: "selected_blue")
        } else {
            img.image = UIImage(named: "disselected_gray")
        }
    }

}
