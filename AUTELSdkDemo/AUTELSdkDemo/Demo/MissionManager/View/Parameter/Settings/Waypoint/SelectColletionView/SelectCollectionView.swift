//
//  SelectCollectionView.swift
//  AutelGen2
//
//  Created by Autel-Hero on 2019/9/30.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import UIKit

typealias SetMissionArrTupleHandler = ((selectArr: [Int], text: String)) -> (Void)

class SelectCollectionView: MenuBGView, UICollectionViewDataSource, UICollectionViewDelegate {

    let bgView = UIView()
    let contentView = UIView()
    let leftButton = UIButton()
    var collectionView: UICollectionView!
    let rightButton = UIButton()

    var subMenuTpye = MenuItemTpye.wayPointList

    let cellIdentifier = "SelectCollectionViewCell"

    var tuple: (select:[Int] , text: String, count: Int) = ([0, 1], "2", 5)
    var items: [(text: String, isSelected: Bool)] = []
    var curArrAndTextHandler: SetMissionArrTupleHandler?

    override init(frame: CGRect) {
        super.init(frame: frame)
        initView()
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    convenience init(menuItemTpye: MenuItemTpye) {
        self.init(frame: CGRect.zero)
        self.subMenuTpye = menuItemTpye
        self.updateDataSource()
    }

    func initView() {
        setUI()
    }

    func setUI(){
        addSubview(bgView)
        bgView.snp.makeConstraints { (maker) in
            maker.edges.equalToSuperview()
        }

        bgView.addSubview(contentView)
        contentView.snp.makeConstraints { (maker) in
            maker.edges.equalToSuperview()
        }


        contentView.addSubview(leftButton)
        leftButton.snp.makeConstraints { (maker) in
            maker.centerY.equalToSuperview()
            maker.left.equalToSuperview()
            maker.width.height.equalTo(30)
        }

        contentView.addSubview(rightButton)
        rightButton.snp.makeConstraints { (maker) in
            maker.centerY.equalToSuperview()
            maker.right.equalToSuperview()
            maker.width.height.equalTo(30)
        }

        let layout = UICollectionViewFlowLayout.init()
        layout.scrollDirection = .horizontal
        layout.itemSize = CGSize.init(width: 89, height: 46)
        layout.estimatedItemSize = CGSize.init(width: 89, height: 46)
        layout.minimumLineSpacing = 14

        collectionView = UICollectionView.init(frame: CGRect(x: 0, y: 0, width: 500, height: 46), collectionViewLayout: layout) // 370
        collectionView?.backgroundColor = UIColor.clear
        collectionView?.isScrollEnabled = true
        collectionView?.showsHorizontalScrollIndicator = false
        collectionView?.delegate = self
        collectionView?.dataSource = self
        // 注册cell
        collectionView?.register(UINib.init(nibName: cellIdentifier, bundle: nil), forCellWithReuseIdentifier: cellIdentifier)

        contentView.addSubview(collectionView)
        collectionView.snp.makeConstraints { (maker) in
            maker.left.equalTo(leftButton.snp.right)
            maker.right.equalTo(rightButton.snp.left)
            maker.top.bottom.equalToSuperview()
        }


        leftButton.tag = 2000
        rightButton.tag = 2001
        leftButton.setImage(UIImage(named: "pub_btn_left_disabled"), for: .normal)
        leftButton.setImage(UIImage(named: "pub_btn_left_highlight"), for: .selected)
        rightButton.setImage(UIImage(named: "pub_btn_right_disabled"), for: .normal)
        rightButton.setImage(UIImage(named: "pub_btn_right_highlight"), for: .selected)

        leftButton.addTarget(self, action: #selector(buttonClick(_:)), for: UIControl.Event.touchUpInside)
        rightButton.addTarget(self, action: #selector(buttonClick(_:)), for: UIControl.Event.touchUpInside)
    }

    func updateDataSource(with tupleData: (select:[Int] , text: String, count: Int) = ([], "none", 0)) {
        tuple = tupleData
        if subMenuTpye == .wayPointList {
            var isSelectAll = true
            for i in 0..<tuple.count {
                items = items + [(text: String(i + 1), isSelected: tuple.select.contains(i))]
                if !tuple.select.contains(i) {
                    isSelectAll = false
                }
            }
            if items.count > 0 {
                items.insert((text: "mission_all", isSelected: isSelectAll), at: 0)
            }
        } else if subMenuTpye == .interestList {
            for i in 0..<tuple.count {
                items = items + [(text: String(i + 1), isSelected: tuple.select.contains(i))]
            }
        } else if subMenuTpye == .altitudePriority {
            for i in 0..<tuple.count {
                items = items + [(text: AltitudePriority(rawValue: i-1)?.discription ?? AltitudePriority.medium.discription,
                                  isSelected: tuple.select.contains(i))]
            }
        } else if subMenuTpye == .headingDirection {
            for i in 0..<tuple.count {
                items = items + [(text: DroneHeadingControl(rawValue: i)?.discription ?? DroneHeadingControl.FOLLOW_WAYLINE_DIRECTION.discription,
                                  isSelected: tuple.select.contains(i))]
            }
        }
        collectionView.reloadData()
        showArrowButton()
    }

    func itemsToSelectArr() -> [Int] {
        var tmpItems = items
        if subMenuTpye == .wayPointList {
            tmpItems.remove(at: 0)
        }
        var array: [Int] = []
        for i in 0..<tmpItems.count {
            if  tmpItems[i].isSelected {
                array = array + [i]
            }
        }
        return array
    }

    deinit {
        print("SelectCollectionView deinit")
    }


    func numberOfSections(in collectionView: UICollectionView) -> Int {

        return 1
    }

    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return items.count
    }

    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: cellIdentifier, for: indexPath) as! SelectCollectionViewCell
        cell.load(items[indexPath.row])
        return cell
    }

    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        if items.count <= 0 { return }
        if subMenuTpye == .wayPointList {
            items[indexPath.row].isSelected = !items[indexPath.row].isSelected
            if indexPath.row == 0 {
                if items[0].isSelected {
                    for i in 0..<items.count {
                        items[i].isSelected = true
                    }
                } else {
                    for i in 0..<items.count {
                        items[i].isSelected = false
                    }
                }
            } else {
                var isSelectAll = true
                for i in 1..<items.count {
                    if !items[i].isSelected {
                        isSelectAll = false
                    }
                    items[0].isSelected = isSelectAll
                }

            }
            let arr = itemsToSelectArr()
            let text = arr.count == 0 ? "none": String(arr.count)
            curArrAndTextHandler?((selectArr: arr, text: text))
        } else if subMenuTpye == .interestList {
            if items.count == 1 {
                items[0].isSelected = !items[0].isSelected
            } else {
                for i in 0..<items.count {
                    if i == indexPath.row {
                        items[i].isSelected = !items[i].isSelected
                    } else {
                        items[i].isSelected = false
                    }
                }
            }
            let arr = itemsToSelectArr()
            let text = arr.count == 0 ? "none": "poi_title" + " " + String(arr[0] + 1).addZero
            curArrAndTextHandler?((selectArr: arr, text: text))
        } else if subMenuTpye == .altitudePriority || subMenuTpye == .headingDirection {
            for i in 0..<items.count {
                items[i].isSelected = false
            }
            items[indexPath.row].isSelected = true
            curArrAndTextHandler?((selectArr: [indexPath.row], text: items[indexPath.row].text))
        }
        collectionView.reloadData()
    }


    @objc func buttonClick(_ button: UIButton) {
        switch button.tag {
        case 2000:
            print("click \(button.tag)")
        case 2001:
            print("click \(button.tag)")
        default:
            print("click \(button.tag)")
        }
    }
}



extension Array where Element: Equatable {

    mutating func removeObject(_ item: Element) {
        self = self.filter { (currentItem: Element) -> Bool in
            return currentItem != item
        }
    }

}


// MARK: - UIScrollViewDelegate
extension SelectCollectionView: UIScrollViewDelegate {
    func scrollViewWillBeginDragging(_ scrollView: UIScrollView) {
        startScroll(scrollView)
    }

    func scrollViewWillBeginDecelerating(_ scrollView: UIScrollView) {
        startScroll(scrollView)
    }

    func scrollViewDidEndDecelerating(_ scrollView: UIScrollView) {
        stopScroll(scrollView)
    }

    func scrollViewDidEndDragging(_ scrollView: UIScrollView, willDecelerate decelerate: Bool) {
        stopScroll(scrollView)
    }

    /// 处理开始滚动时，显示左右两个箭头
    ///
    /// - Parameter scrollView: UIScrollView
    private func startScroll(_ scrollView: UIScrollView) -> Void {
        leftButton.isHidden = false
        rightButton.isHidden = false
    }

    /// 处理滚动结束后，左右两个箭头的显示状态
    ///
    /// - Parameter scrollView: UIScrollView
    private func stopScroll(_ scrollView: UIScrollView) -> Void {
        //滑到最右边
        if scrollView.contentSize.width - scrollView.width - scrollView.contentOffset.x < CGFloat.ulpOfOne {
            leftButton.isHidden = false
            rightButton.isHidden = true
        } else if scrollView.contentOffset.x < CGFloat.ulpOfOne {
            rightButton.isHidden = false
            leftButton.isHidden = true
        }
    }

    private func showArrowButton() {
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.15) {
            if self.collectionView.contentSize.width > self.collectionView.width {
                self.leftButton.isHidden = true
                self.rightButton.isHidden = false
            } else {
                self.rightButton.isHidden = true
                self.leftButton.isHidden = true
            }
        }
    }
}
