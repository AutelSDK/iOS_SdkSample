//
//  CameraMenuItemPicker.swift
//  AutelGen2
//
//  Created by Devin on 2017/10/28.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK


/// Hero: 获取相机SDK返回各个子菜单 或者 上层自定义
class CameraMenuItemPicker {
    
    private class var parameters: AUTELCameraParameters? {
        get {
            return CameraConnection.shared.camera?.parameters
        }
    }
    
    /// 根据菜单对象请求子菜单列表
    ///
    /// - Parameter menu: 菜单对象
    class func requestSubMenuWithMenu(_ menu: CameraMenuItem) -> Void {
        guard case let .branch(branch) = menu.style else { return }
        guard let children = requestSubMenuWithBranch(branch, forMenu: menu) else { return }
        menu.setChildren(children.isEmpty ? nil : children)
    }
    
    /// 请求参数范围
    ///
    /// - Parameters:
    ///   - branch: 所属菜单
    ///   - menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestSubMenuWithBranch(_ branch: CameraMenuBranch, forMenu menu: CameraMenuItem) -> [CameraMenuItem]? {
        switch branch {
        case .photoFormat:
            return requestPhotoFormatWithItem(menu)
        case .videoFormat:
            return requestVideoFormatWithItem(menu)
        case .photoSize:
            return requestPhotoSizeWithItem(menu)
        case .exposureMode:
            return requestExposureModeWithItem(menu)
        case .iso:
            return requestISOWithItem(menu)
        case .exposureCompensation:
            return requestExposureCompensationWithItem(menu)
        case .whiteBalance:
            return requestWhiteBalanceWithItem(menu)
        case .style:
            return requestPhotoStyleWithItem(menu)
        case .workMode:
            return requestPhotoModeWithItem(menu)
        case .af:
            return requestAFWithItem(menu)
        case .irColor:
            return requestIrColorWithItem(menu)
        case .digitalFilter:
            return requestDigitalFilterWithItem(menu)
        case .videoStandard:
            return requestVideoStandardWithItem(menu)
        case .videoResolution:
            return requestVideoResolutionWithItem(menu)
        case .frameRate:
            return requestVideoFrameRateWithItem(menu)
        case .digitalZoom:
            return requestDidigalZoomScaleWithItem(menu)
        case .photoBurst:
            return requestBurstPhotoWithItem(menu)
        case .photoAeb:
            return requestAEBPhotoWithItem(menu)
        case .photoTiming:
            return requestTimingPhotoWithItem(menu)
        case .wbCustom:
            return requestCustomWhiteBalanceWithItem(menu)
        case .shutterSpeed:
            return requestShutterSpeedWithItem(menu)
        case .aperture:
            return requestApertureWithItem(menu)
        case .piv:
            return requestPictureInVideoWithItem(menu)
        case .gimbalAngle:
            return requestGimbalAngleWithItem(menu)
        case .styleCustom:
            return requestCustomStyleWithItem(menu)
        case .sharpness, .saturation, .contrast, .hue:
            return requestCustomStyleParamsWithItem(menu)
        case .photoFormatDelayShot:
            return requestPhotoFormatDelayShotOpsWithItem(menu)
        default:
            return nil
        }
    }
    
    /// 请求支持的图片大小
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestPhotoSizeWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraPhotoAspectRatioRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers.reversed() {
            let data = CameraMenuItem(style: .leaf(num.uint8Value))
            data.parent = menu
            items.append(data)
        }
        return items
    }


    /// 请求支持的图片大小
    ///
    /// - Returns: [CameraMenuItem]?
    class func requestPhotoSizeWithItem() -> [String] {
        guard let numbers = parameters?.supportedCameraPhotoAspectRatioRange() else { return [] }
        var textArr: [String] = []
        for num in numbers.reversed() {
            textArr = textArr + [String((AUTELCameraPhotoAspectRatio(rawValue: UInt8(truncating: num))?.displayName() ?? "").prefix(9))]
        }
        return textArr
    }
    
    /// 请求支持的拍照模式
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestPhotoModeWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let _ = parameters?.supportedCameraModeRange() else { return nil }
        //单拍
        let single = CameraMenuItem(style: .leaf(AUTELCameraWorkMode.captureSingle.rawValue))
        single.parent = menu
        //burst
        let burst = CameraMenuItem(style: .branch(.photoBurst))
        burst.parent = menu
        //aeb
        let aeb = CameraMenuItem(style: .branch(.photoAeb))
        aeb.parent = menu
        //timing
        let timing = CameraMenuItem(style: .branch(.photoTiming))
        timing.parent = menu
        //HDR
//        let hdr = CameraMenuItem(style: .leaf(AUTELCameraWorkMode.captureHDR.rawValue))
//        hdr.parent = menu
        //纯净夜拍
        let mfnr = CameraMenuItem(style: .leaf(AUTELCameraWorkMode.captureMFNR.rawValue))
        mfnr.parent = menu
        if CameraSystemState.shared.displayModeIndex < DisplayModeIndex.visible {
             return [single, burst, timing]
        }
        if !(DroneConnection.shared.drone?.camera.isEarlyThanModelC ?? false) {
            return [single, burst, timing, aeb, mfnr]
        } else {
            return [single, burst, timing, aeb]
        }
    }
    
    /// 请求支持的AF
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestAFWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        var items: [CameraMenuItem] = []
        let af = CameraMenuItem(style: .leaf(UInt8(FocusValue.afValue)))
        af.parent = menu
        items.append(af)
        let mf = CameraMenuItem(style: .leaf(UInt8(FocusValue.mfValue)))
        mf.parent = menu
        items.append(mf)
//        for i in 1...50 {
//            let item = CameraMenuItem(style: .leaf(UInt8(i)))
//            item.parent = menu
//            items.append(item)
//        }
//        let infinite = CameraMenuItem(style: .leaf(UInt8(FocusValue.infinityValue)))
//        infinite.parent = menu
//        items.append(infinite)
        return items
    }
    
    /// 请求伪彩
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestIrColorWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraIrColor() else { return nil }
        let values = numbers.map{ $0.uint8Value }.sorted(by: < )
        var items: [CameraMenuItem] = []
        for num in values {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求连拍张数
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestBurstPhotoWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraPhotoBurstCountRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers {
            let data = CameraMenuItem(style: .leaf(num.uint8Value))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求AEB连拍张数
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestAEBPhotoWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraPhotoAEBCaptureCountRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers {
            let data = CameraMenuItem(style: .leaf(num.uint8Value))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求定时拍支持的间隔
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestTimingPhotoWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraTimeLapseIntervalRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers {
            let data = CameraMenuItem(style: .leaf(num.uint8Value))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求图片格式
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestPhotoFormatWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraPhotoFileFormatRange() else { return nil }
        let values = numbers.map{ $0.uint8Value }.sorted(by: < )
        var items: [CameraMenuItem] = []
        for num in values {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    private class func requestPhotoFormatDelayShotOpsWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        
        let values = [AUTELCameraDelayShotPhotoFormat.none.rawValue,
                      AUTELCameraDelayShotPhotoFormat.JPG.rawValue,
                      AUTELCameraDelayShotPhotoFormat.DNG.rawValue]
        var items: [CameraMenuItem] = []
        for num in values {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求曝光模式
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestExposureModeWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraExposureModeRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers {
            let data = CameraMenuItem(style: .leaf(num.uint8Value))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求感光度ISO
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestISOWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraISORange() else { return nil }
        let values = numbers.map{ $0.uint8Value }.sorted(by: < )
        var items: [CameraMenuItem] = []
        for num in values {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求当前曝光模式下曝光补偿
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestExposureCompensationWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraExposureCompensationRange() else { return nil }
        let values = numbers.map{ $0.uint8Value }.sorted(by: < )
        var items: [CameraMenuItem] = []
        for num in values {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求白平衡
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestWhiteBalanceWithItem(_ menu: CameraMenuItem) ->[CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraWhiteBalanceRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers {
            guard let wb = AUTELCameraWhiteBalance(rawValue: num.uint8Value) else { continue }
            var data: CameraMenuItem
            if wb.isCustom() {
                data = CameraMenuItem(style: .branch(.wbCustom))
            } else {
                data = CameraMenuItem(style: .leaf(num.uint8Value))
            }
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求照片风格
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestPhotoStyleWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraPhotoStyleRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers {
            guard let photoStyle = AUTELCameraPhotoStyle(rawValue: num.uint8Value) else { continue }
            var data: CameraMenuItem
            if photoStyle == .custom {
                data = CameraMenuItem(style: .branch(.styleCustom))
            } else {
                data = CameraMenuItem(style: .leaf(num.uint8Value))
            }
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求数码滤波
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestDigitalFilterWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraDigitalFilterRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers {
            let data = CameraMenuItem(style: .leaf(num.uint8Value))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求视频制式
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestVideoStandardWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard var numbers = parameters?.supportedCameraVideoStandardRange() else { return nil }
        numbers.sort { (num1, num2) -> Bool in
            return num1.uint8Value > num2.uint8Value
        }
        var items: [CameraMenuItem] = []
        for num in numbers {
            let data = CameraMenuItem(style: .leaf(num.uint8Value))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求视频文件格式
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestVideoFormatWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraVideoFileFormatRange() else { return nil }
        var items: [CameraMenuItem] = []
        for num in numbers {
            let data = CameraMenuItem(style: .leaf(num.uint8Value))
            data.parent = menu
            items.append(data)
        }
        return items
    }

    /// 请求支持的图片大小
    ///
    /// - Returns: [String]
    class func requestVideoFormatWithItem() -> [String] {
        guard let numbers = parameters?.supportedCameraVideoFileFormatRange() else { return [] }
        var textArr: [String] = []
        for num in numbers.reversed() {
            textArr = textArr + [String((AUTELCameraVideoFileFormat(rawValue: UInt8(truncating: num))?.displayName() ?? ""))]
        }
        return textArr
    }
    
    /// 请求视频分辨率
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestVideoResolutionWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedVideoResolutionAndFrameRateRange() else { return nil }
        var items: [CameraMenuItem] = []
        let keys = numbers.keys.map({$0.uint8Value}).sorted(by: >)
        for num in keys {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求视频帧率
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestVideoFrameRateWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedVideoResolutionAndFrameRateRange() else { return nil }
        //获取当前选中的resolution
        guard let resolution = CameraSelection.shared.valueWith(.videoResolution).set.digitalValue() else { return nil }
        guard let frameRateList = numbers[NSNumber(value: resolution)] else { return nil }
        var items: [CameraMenuItem] = []
        let list = frameRateList.reversed().map({$0.uint8Value}).sorted(by: >)
        for num in list {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求数码变焦范围
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestDidigalZoomScaleWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let dict = parameters?.supportedCameraDigitalZoomScaleRange() else { return nil }
        guard let max = dict["Max"]?.uint8Value else { return nil }
        guard let min = dict["Min"]?.uint8Value else { return nil }
        var items: [CameraMenuItem] = []
        for num in min ... max {
            let data = CameraMenuItem(style: .leaf(num * 10))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求支持的色温范围
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestCustomWhiteBalanceWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let dict = parameters?.supportedCameraWhiteBalanceCustomColorTemperatureRange() else { return nil }
        guard let step = dict["Step"]?.uint8Value else { return nil }
        guard let max = dict["Max"]?.uint8Value else { return nil }
        guard let min = dict["Min"]?.uint8Value else { return nil }
        var num = min
        var items: [CameraMenuItem] = []
        repeat {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
            num += step
        } while num <= max
        return items
    }
    
    /// 请求支持的快门速度
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns:  [CameraMenuItem]?
    private class func requestShutterSpeedWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraShutterSpeedRange() else { return nil }
        var items: [CameraMenuItem] = []
        let values = numbers.map({$0.uint8Value}).sorted(by: <)
        for num in values {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求支持的光圈参数
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns:  [CameraMenuItem]?
    private class func requestApertureWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraApertureRange() else { return nil }
        var items: [CameraMenuItem] = []
        let values = numbers.map({$0.uint8Value}).sorted(by: <)
        for num in values {
            let data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求PIV的设置参数
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestPictureInVideoWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        guard let numbers = parameters?.supportedCameraPictureInVideoIntervalRange() else { return nil}
        var items: [CameraMenuItem] = []
        //设置手动模式
        var data = CameraMenuItem(style: .leaf(UInt8.max))
        data.parent = menu
        items.append(data)
        //设置自动模式
        let values = numbers.map{ $0.uint8Value }.sorted(by: < )
        for num in values {
            data = CameraMenuItem(style: .leaf(num))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求照片风格
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestCustomStyleWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        //锐度
        let sharpness = CameraMenuItem(style: .branch(.sharpness))
        sharpness.parent = menu
        //对比度
        let contrast = CameraMenuItem(style: .branch(.contrast))
        contrast.parent = menu
        //饱和度
        let saturation = CameraMenuItem(style: .branch(.saturation))
        saturation.parent = menu
        return [sharpness, contrast, saturation]
    }
    
    /// 请求自定义风格的参数范围，适用于锐度、对比度、饱和度和hue
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestCustomStyleParamsWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        var items: [CameraMenuItem] = []
        for num in -3...3 {
            let data = CameraMenuItem(style: .leaf(Int8(num).toUInt8()))
            data.parent = menu
            items.append(data)
        }
        return items
    }
    
    /// 请求云台角度
    ///
    /// - Parameter menu: 所属菜单
    /// - Returns: [CameraMenuItem]?
    private class func requestGimbalAngleWithItem(_ menu: CameraMenuItem) -> [CameraMenuItem]? {
        var items: [CameraMenuItem] = []
        for num in [0, 30, 45, 50, 60, 90] {
            let data = CameraMenuItem(style: .leaf(UInt8(num)))
            data.parent = menu
            items.append(data)
        }
        return items
    }
}
