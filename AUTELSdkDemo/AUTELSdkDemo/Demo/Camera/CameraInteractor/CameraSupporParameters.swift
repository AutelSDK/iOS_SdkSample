//
//  CameraSupporParameters.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/13.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK


class CameraSupporParameters {
    
    private class var parameters: AUTELCameraParameters? {
        get {
            return CameraConnection.shared.camera?.parameters
        }
    }
    
    
    /// 请求支持的图片大小
    ///
    /// - Returns: [CameraMenuItem]?
    class func requestPhotoSizeWithItem() -> [String] {
        guard let numbers = parameters?.supportedCameraPhotoAspectRatioRange() else { return [] }
        var items: [String] = []
        for num in numbers.reversed() {
            let parameter = AUTELCameraPhotoAspectRatio(rawValue: UInt8(truncating: num))?.displayName() ?? ""
            items.append(parameter)
        }
        return items
    }
    
    /// 请求支持的拍照模式
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    class func requestCameraModeWithItem() -> [String]? {
        guard let numbers = parameters?.supportedCameraModeRange() else { return nil }
        var items: [String] = []
        for num in numbers {
            let parameter = AUTELCameraWorkMode(rawValue: UInt8(truncating: num))?.displayName() ?? ""
            items.append(parameter)
        }
        return items
        
    }
}
