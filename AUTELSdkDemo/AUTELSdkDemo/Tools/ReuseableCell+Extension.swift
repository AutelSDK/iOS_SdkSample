import UIKit

extension UITableViewCell {

    @objc static var defaultReuseIdentifier: String {
        return String(describing: self)
    }
}

extension UITableViewHeaderFooterView {

    @objc static var defaultReuseIdentifier: String {
        return String(describing: self)
    }
}

extension UITableView {

    func register(_ cellClass: UITableViewCell.Type) {
        register(cellClass, forCellReuseIdentifier: cellClass.defaultReuseIdentifier)
    }

    func register(_ view: UITableViewHeaderFooterView.Type) {
        register(view, forHeaderFooterViewReuseIdentifier: view.defaultReuseIdentifier)
    }

    func registerNib<T: UITableViewCell>(_ cellType: T.Type) {
        register(UINib(nibName: T.defaultReuseIdentifier, bundle: nil), forCellReuseIdentifier: T.defaultReuseIdentifier)
    }

    public func dequeueReusableCell<CellClass: UITableViewCell>(for indexPath: IndexPath) -> CellClass {
        guard let cell = dequeueReusableCell(withIdentifier: CellClass.defaultReuseIdentifier, for: indexPath) as? CellClass else {
            fatalError("Cannot dequeueReusableCell of \(CellClass.self) type!")
        }
        return cell
    }

    func dequeueReusableCell<CellClass: UITableViewCell>(
        of classType: CellClass.Type,
        for indexPath: IndexPath,
        defaultCell: UITableViewCell? = nil,
        configure: (CellClass) -> Void = { _ in }) -> UITableViewCell {
        let cell = dequeueReusableCell(withIdentifier: CellClass.defaultReuseIdentifier, for: indexPath)
        if let typedCell = cell as? CellClass {
            configure(typedCell)
            return typedCell
        }
        return defaultCell ?? cell
    }
}
