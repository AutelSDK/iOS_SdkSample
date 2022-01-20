import UIKit
import SnapKit

protocol ExpandHeaderDelegate: AnyObject {
    func didTapSection(header: ExpandHeader, section: Int)
}

class ExpandHeader: UITableViewHeaderFooterView {

    weak var delegate: ExpandHeaderDelegate?
    var section = 0

    private lazy var sectionLabel: UILabel = {
        let label = UILabel()
        return label
    }()

    private lazy var arrowIcon: UIImageView = {
        let imageView = UIImageView()
        imageView.image = UIImage(named: "iconRightArrowGrey")
        imageView.contentMode = .scaleAspectFit
        imageView.transform = CGAffineTransform(rotationAngle: .pi / 2)
        return imageView
    }()

    public var isExpand: Bool = true {
        didSet {
            arrowIcon.transform = isExpand ? CGAffineTransform(rotationAngle: 3 * .pi / 2) : CGAffineTransform(rotationAngle: .pi / 2)
        }
    }

    override init(reuseIdentifier: String?) {
        super.init(reuseIdentifier: reuseIdentifier)
        setupUI()
        addGestureRecognizer(UITapGestureRecognizer(target: self, action: #selector(tapHeader(gestureRecognizer:))))
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    private func setupUI() {
        [sectionLabel, arrowIcon].forEach { addSubview($0) }

        sectionLabel.snp.makeConstraints { (make) in
            make.leading.equalToSuperview().inset(16)
            make.centerY.equalToSuperview()
        }

        arrowIcon.snp.makeConstraints { (make) in
            make.width.height.equalTo(10)
            make.centerY.equalTo(sectionLabel)
            make.trailing.equalToSuperview().inset(32)
            make.leading.greaterThanOrEqualTo(sectionLabel.snp.trailing).offset(16)
        }
    }

    @objc func tapHeader(gestureRecognizer: UITapGestureRecognizer) {
        guard let header = gestureRecognizer.view as? ExpandHeader else {
            return
        }
        delegate?.didTapSection(header: self, section: header.section)
    }

    func setHeaderTitle(_ title: String,
                        delegate: ExpandHeaderDelegate,
                        section: Int,
                        isExpand: Bool) {
        self.delegate = delegate
        self.section = section
        self.isExpand = isExpand
        sectionLabel.text = title.uppercased()
    }
}
