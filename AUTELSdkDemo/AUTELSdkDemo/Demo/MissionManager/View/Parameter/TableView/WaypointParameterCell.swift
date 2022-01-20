//
//  WaypointParameteCell.swift
//  AUTELSdkDemo
//
//  Created by Autel on 2021/7/10.
//  Copyright © 2021 AUTEL. All rights reserved.
//

import Foundation

protocol WaypointParameteCellCollectable {
    var selectCollectionView: SelectCollectionView {get }
}
extension WaypointParameteCellLatLonable where Self: WaypointParameterCell {
    func setupCollectionView() {
        contentView.addSubview(selectCollectionView)
        selectCollectionView.snp.makeConstraints { make in
            make.width.equalTo(300)
            make.center.equalTo(contentView)
            make.height.equalTo(100)
            make.top.equalTo(contentView).offset(10)
            make.bottom.equalTo(contentView).offset(-10)
        }
        selectCollectionView.updateDataSource(with: ([1], "1", 2))
    }
}

protocol WaypointParameteCellLatLonable {
    var latLonView: SubMenuLongAndLatEditorView {get }
}
extension WaypointParameteCellLatLonable where Self: WaypointParameterCell {
    func setupLatLonView() {
        contentView.addSubview(latLonView)
        latLonView.contentView.backgroundColor = contentView.backgroundColor
        latLonView.latLab.text = "Latitude"
        latLonView.longLab.text = "Lontitude"
        latLonView.snp.makeConstraints { make in
            make.width.equalTo(300)
            make.right.equalTo(valueLable.snp.left).offset(-50)
            make.height.equalTo(60)
            make.top.equalTo(contentView).offset(10)
            make.bottom.equalTo(contentView).offset(-10)
        }
    }
}

protocol WaypointParameteCellSliderable {
    var missionSliderView: MissionSliderView {get }
}
extension WaypointParameteCellSliderable where Self: WaypointParameterCell {
    func setupMissionSliderView() {
        contentView.addSubview(missionSliderView)
        missionSliderView.backgroundColor = contentView.backgroundColor
        missionSliderView.snp.makeConstraints { make in
            make.left.equalTo(titleLable.snp.right).offset(50)
            make.right.equalTo(valueLable.snp.left).offset(-50)
            make.height.equalTo(45)
            make.top.equalTo(contentView).offset(10)
            make.bottom.equalTo(contentView).offset(-10)
        }
    }
}

class WaypointParameterCell: UITableViewCell, WaypointParameteCellSliderable, WaypointParameteCellLatLonable {
    lazy var selectCollectionView: SelectCollectionView = { SelectCollectionView() }()
    lazy var latLonView: SubMenuLongAndLatEditorView = { SubMenuLongAndLatEditorView() }()
    lazy var missionSliderView: MissionSliderView = { MissionSliderView() }()
    let titleLable: UILabel = {
        let lable = UILabel()
        return lable
    }()
    let valueLable: UILabel = {
        let lable = UILabel()
        return lable
    }()
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        setup()
        selectionStyle = .none
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func setup() {
        setupCell()
    }
    
    private func setupCell() {
        [titleLable, valueLable].forEach{
            contentView.addSubview($0)
        }
        titleLable.snp.makeConstraints { make in
            make.centerY.equalTo(contentView)
            make.left.equalTo(contentView).offset(10)
        }
        valueLable.snp.makeConstraints { make in
            make.centerY.equalTo(contentView)
            make.right.equalTo(contentView).offset(-10)
        }
    }
    
    
    func setupCell(model: WayPointParameterCellModel) {
        titleLable.text = model.title
        valueLable.text = model.value
    }
    
    func setupSettinView(type: MenuItemTpye) {
        missionSliderView.removeFromSuperview()
        latLonView.removeFromSuperview()
        selectCollectionView.removeFromSuperview()
        
        switch type {
        case .slider:
            setupMissionSliderView()
        case .coordinate:
            setupLatLonView()
        case .interestList:
            setupCollectionView()
        default:
            break
        }
    }
   
}

