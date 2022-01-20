//
//  CameraParametersSetter.swift
//  AutelGen2
//
//  Created by Devin on 2017/10/18.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK


/// Hero: 设置相机所有参数
class CameraParametersSetter {
    
    /// 根据选中菜单项设置相机参数
    ///
    /// - Parameter menu: 选中菜单项
    class func setParameterWithMenu(_ menu: CameraMenuItem) -> () {
        //如果菜单不是最后一级，那么就不是真正设值的菜单
        if menu.isRoot() == false, let pair = menu.cameraParametersSetterOrder() {
            setParameterWithBranch(pair.branch, andValue: pair.value)
        }
    }
    
    /// 重置相机
    ///
    /// - Parameter result: 回调
    class func resetCamera(_ result: ResultHandler) -> Void {
        CameraCommandDeliver.loadFactorySettings { (error) in
            result?(error)
            //TODO:弹出提示
            if let err = error {
                logInfo("reset camera failure: \(err.localizedDescription)")
                if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {
                } else {
                    let _ = SystemMessageCenter.shared.insertAMessageEvent(type: MCMessageEventType.ResetCameraFail)
                }
            } else {
                printLog("send camera reset command success")
                CameraSystemState.shared.resetState()
                
                if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {
                } else {
                    let _ = SystemMessageCenter.shared.insertAMessageEvent(type: MCMessageEventType.ResetCameraSuccess)
                }
            }
            AutelRXShared.shared.cameraDidLoadFactorySettings.onNext(error == nil)
        }
    }
    
    /// 格式化SD卡
    ///
    /// - Parameter result: 回调
    class func formatSDCard(_ result: ResultHandler) -> Void {
        AutelRXShared.shared.formatState.onNext(.formatting)
        if let window = UIApplication.shared.keyWindow {
            MBProgressHUD.showAdded(to: window, animated: true)
        }
        CameraCommandDeliver.formatSDCard { (error) in
            result?(error)
            DispatchQueue.main.asyncAfter(deadline: .now() + 5.0) {
                //TODO:弹出提示
                if let err = error {
                    AutelRXShared.shared.formatState.onNext(.failure)
                    printLog("format sd card failure: \(err.localizedDescription)")
                } else {
                    AutelRXShared.shared.formatState.onNext(.succeed)
                    printLog("send format sd card command success")
            //                CameraSDCardState.shared.resetState()
                }
                if let window = UIApplication.shared.keyWindow {
                    MBProgressHUD.hideAllHUDs(for: window, animated: true)
                }
            }
            //保持一秒时间的格式化成功/失败的状态
            DispatchQueue.global().asyncAfter(deadline: .now() + 1.0, execute: {
                AutelRXShared.shared.formatState.onNext(.unknown)
            })
        }
    }
    
    /// 格式化EMMC
    ///
    /// - Parameter result: 回调
    class func formatEMMC(_ result: ResultHandler) -> Void {
        AutelRXShared.shared.formatState.onNext(.formatting)
        CameraCommandDeliver.formatEMMC { (error) in
            result?(error)
            //TODO:弹出提示
            if let err = error {
                AutelRXShared.shared.formatState.onNext(.failure)
                logInfo("format mmc card failure: \(err.localizedDescription)")
            } else {
                AutelRXShared.shared.formatState.onNext(.succeed)
                printLog("send format mmc card command success")
                //                CameraSDCardState.shared.resetState()
            }
            //保持一秒时间的格式化成功/失败的状态
            DispatchQueue.global().asyncAfter(deadline: .now() + 1.0, execute: {
                AutelRXShared.shared.formatState.onNext(.unknown)
            })
        }
    }
    
    /// 设置定时拍间隔，不会更新拍照模式
    ///
    /// - Parameter value: 定时拍枚举原始值
    class func setTimeLapseInterval(_ value: UInt8) -> () {
        guard let interval = AUTELCameraPhotoTimeLapseInterval(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .photoTiming)
        CameraCommandDeliver.setTimeLapseInterval(interval, with: { (intervalError) in
            if let err = intervalError {
                logInfo("set timing interval error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.photoTiming)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .photoTiming)
        })
    }
    
    /// 根据分支设置相机参数值
    ///
    /// - Parameters:
    ///   - branch: 操作分支
    ///   - value: 实际值
    class func setParameterWithBranch(_ branch: CameraMenuBranch, andValue value: UInt8) -> () {
        printLog("======= = 根据分支 \(branch.displayName()) value \(value) 设置相机参数值 ")
        switch branch {
        case .workMode:
            setWorkModeWithValue(value)
            updateAEAFLockedEnable()
        case .photoAeb:
            setAebWorkModeWithCount(value)
        case .photoBurst:
            setBurstWorkModeWithCount(value)
        case .photoTiming:
             setTimeLapseWorkModeWithInterval(value)
             CameraParametersGetter.getTimeLapseInterval()
        case .hdr:
            setHDRWorkMode(value)
        case .mfnr:
            setMFNRWorkMode(value)
        case.photoSize:
            setPhotoSizeWithValue(value)
            updateAEAFLockedEnable()
        case .photoFormat:
            setPhotoFileFormatWithValue(value)
        case .exposureMode:
            exposureModeWillChange()
            setExposureModeWithValue(value)
            exposureModeDidChange()
        case .iso:
            setISOWithValue(value)
        case .exposureCompensation:
            setExposureCompensationWithValue(value)
        case .whiteBalance:
            setWhiteBalanceWithValue(value)
        case .wbCustom:
            setCustomWhiteBalanceWithValue(value)
        case .digitalFilter:
            setDigitalFilterWithValue(value)
        case .style:
            setPhotoStyleWithValue(value)
        case .styleCustom:
            setCustomPhotoStyleWithValue(Int(value))
        case .sharpness, .contrast, .saturation, .hue:
             setPhotoStyleParamWithValue(value, forBranch: branch)
        case .videoStandard:
            setVideoStandartWithValue(value)
//            CameraParametersGetter.getVideoResolutionAndFrameRate()
        case .videoFormat:
            setVideoFileFormatWithValue(value)
        case .videoResolution:
            setVideoResolutionWithValue(value)
            updateAEAFLockedEnable()
        case .frameRate:
            setVideoFrameRateWithValue(value)
        case .digitalZoom:
            setDigitalZoomScaleWithValue(value)
        case .aeLock:
            setAELockWithValue(value)
        case .af:
            focusModeWillChange()
            setAF(value)
            focusModeDidChange()
        case .mfFocusAssist:
            setMfFocusAssistWithValue(value)
        case .spotCol:
            setSpotColWithValue(value)
        case .spotRow:
            setSpotRowWithValue(value)
        case .spotCoordinate:
            setSpotCoordinate()
        case .histogram:
            setHistogramWithValue(value)
        case .shutterSpeed:
            setShutterSpeedWithValue(value)
        case .aperture:
            setApertureWithValue(value)
        case .piv:
            setPIVWithValue(value)
        case .antiFlicker:
            setAntiFilckerWithValue(value)
        case .captionEnable:
            setCaptionEnabledWithValue(value)
        case .encodingFormat:
            setVideoEncodingStandard(value)
        case .store:
            setStore(value)
        case .display:
            setDisplayModeWithValue(value)
        case .irColor:
            setIrColor(value)
        case .gimbalLockState:
            setGimbalLockStateWithValue(value)
        case .photoFormatDelayShot:
             setPhotoFormatDelayShotWithValue(value)

        default:
            return
        }
    }
    
    /// 设置相机工作模式
    ///
    /// - Parameter value: 工作模式可用的原始值
   private class func setDisplayModeWithValue(_ value: UInt8) -> () {
       guard let displayMode = AUTELCameraThermalDisplayMode(rawValue: value) else { return }
       CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .display)
        printLog("----- - \(value)")
       CameraCommandDeliver.setDisplayMode(displayMode) { (error) in
           if let err = error {
               printLog("----- - set display error: \(err.localizedDescription)")
               CameraSelection.shared.rollback(.display)
               return
           }
        printLog("----- - set display success: \(value)")
        CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .display)
        // 请求相机所有设定参数
        CameraParametersGetter.loadAllParameters()
        var tmpIndex = Int(value)
        if displayMode == AUTELCameraThermalDisplayMode.infraredRadiation {
            tmpIndex = DisplayModeIndex.infrared
            CameraParametersGetter.getVideoResolutionAndFrameRate()
            CameraParametersGetter.getPhotoSize()
        } else if displayMode == AUTELCameraThermalDisplayMode.picturePicture {
            tmpIndex = DisplayModeIndex.pIP
            CameraParametersGetter.getVideoResolutionAndFrameRate()
            CameraParametersGetter.getPhotoSize()
        } else if displayMode == AUTELCameraThermalDisplayMode.visible {
            tmpIndex = DisplayModeIndex.visible
        }
        CameraSystemState.shared.displayModeIndex = tmpIndex
        AutelRXShared.shared.displayModeIndex.onNext(tmpIndex)
        }
   }
    
    /// 设置相机工作模式
    ///
    /// - Parameter value: 工作模式可用的原始值
    private class func setWorkModeWithValue(_ value: UInt8) -> () {
        guard let workMode = AUTELCameraWorkMode(rawValue: value) else { return }
        let oldMode = CameraSystemState.shared.workMode
        if workMode.category != oldMode.category && oldMode.category != .unknown {
            CameraSystemState.shared.isStateChanging = true
        }
        //拍照模式
        if workMode.category == .photo {
            var successHandler: ((UInt8) -> ())? = nil
            var num: UInt8 = 0
            switch workMode {
            case .captureAEB:
                successHandler = setAebWorkModeWithCount(_:)
                num = CameraSelection.shared.valueWith(.photoAeb).set.digitalValue() ?? AUTELCameraPhotoAEBCaptureCount.count3.rawValue
            case .captureBurst:
                successHandler = setBurstWorkModeWithCount(_:)
                num = CameraSelection.shared.valueWith(.photoBurst).set.digitalValue() ?? AUTELCameraPhotoBurstCount.count5.rawValue
            case .captureInterval:
                successHandler = setTimeLapseWorkModeWithInterval(_:)
                num = CameraSelection.shared.valueWith(.photoTiming).set.digitalValue() ?? AUTELCameraPhotoTimeLapseInterval.interval5.rawValue
            case .captureHDR:
                successHandler = setHDRWorkMode(_:)
            case .captureMFNR:
                successHandler = setMFNRWorkMode(_:)
            default:
                successHandler = setSingleCaptureWorkMode(_:)
            }
            successHandler?(num)
        } else {
            //录像模式
            CameraCommandDeliver.setWorkMode(workMode, result: { (error) in
                CameraSystemState.shared.isStateChanging = false
                if let err = error {
                    logInfo("set video mode error: \(err.localizedDescription)")
                    return
                }
            })
        }
    }
    
    /// 设置aeb工作模式并设置连拍数量
    ///
    /// - Parameter value: aeb连拍枚举原始值
    private class func setAebWorkModeWithCount(_ value: UInt8) -> () {
        guard let count = AUTELCameraPhotoAEBCaptureCount(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .photoAeb)
        CameraSelection.shared.setUploadValue(.branch(.photoAeb), forBranch: .workMode)
        CameraCommandDeliver.setAebWorkModeWithCount(count, with: { (error) in
            CameraSystemState.shared.isStateChanging = false
            if let err = error {
                logInfo("set aeb count error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.photoAeb)
//                CameraSelection.shared.rollback(.workMode)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .photoAeb)
            CameraSelection.shared.setDownloadValue(.branch(.photoAeb), forBranch: .workMode)
            CameraSystemState.shared.lastPhotoMode = .aeb(count)

            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, .captureAEB))
                
            }
            
            CameraSystemState.shared.workMode = .captureAEB
            
            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {
                //do nothing
            } else {
                CameraParametersGetter.getExposure()
            }
            
            AutelRXShared.shared.updateMenu.onNext(true)
        })
    }
    
    /// 设置burst工作模式并设置连拍数量
    ///
    /// - Parameter value: 连拍枚举原始值
    private class func setBurstWorkModeWithCount(_ value: UInt8) -> () {
        guard let count = AUTELCameraPhotoBurstCount(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .photoBurst)
        CameraSelection.shared.setUploadValue(.branch(.photoBurst), forBranch: .workMode)
        CameraCommandDeliver.setBurstWorkModeWithCount(count) { (error) in
            CameraSystemState.shared.isStateChanging = false
            if let err = error {
                logInfo("set burst count error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.photoBurst)
//                CameraSelection.shared.rollback(.workMode)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .photoBurst)
            CameraSelection.shared.setDownloadValue(.branch(.photoBurst), forBranch: .workMode)
            CameraSystemState.shared.lastPhotoMode = .burst(count)

            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, .captureBurst))
                
            }
            AutelRXShared.shared.updateMenu.onNext(true)
            CameraSystemState.shared.workMode = .captureBurst
        }
    }
    
    /// 设置单拍模式
    ///
    /// - Parameter value: UInt8，有默认值，可以不设
    private class func setSingleCaptureWorkMode(_ value: UInt8 = 0) -> () {
        CameraSelection.shared.setUploadValue(.leaf(AUTELCameraWorkMode.captureSingle.rawValue), forBranch: .workMode)
        CameraCommandDeliver.setWorkMode(.captureSingle, result: { (singleError) in
            CameraSystemState.shared.isStateChanging = false
            if let err = singleError {
                logInfo("set single mode error: \(err.localizedDescription)")
//                CameraSelection.shared.rollback(.workMode)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(AUTELCameraWorkMode.captureSingle.rawValue), forBranch: .workMode)
            CameraSystemState.shared.lastPhotoMode = .single
            CameraSystemState.shared.workMode = .captureSingle
            AutelRXShared.shared.updateMenu.onNext(true)
            if Int(truncating: UserSettings.shared.currentAircraftVersion) != DroneType.modelB.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, .captureSingle))
            }
        })
    }

    /// 设置HDR模式
    ///
    /// - Parameter value: UInt8，有默认值，可以不设
    private class func setHDRWorkMode(_ value: UInt8 = 0) -> () {
        CameraSelection.shared.setUploadValue(.leaf(AUTELCameraWorkMode.captureHDR.rawValue), forBranch: .workMode)
        CameraCommandDeliver.setWorkMode(.captureHDR, result: { (singleError) in
            CameraSystemState.shared.isStateChanging = false
            if let err = singleError {
                logInfo("set HDR mode error: \(err.localizedDescription)")
                //                CameraSelection.shared.rollback(.workMode)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(AUTELCameraWorkMode.captureHDR.rawValue), forBranch: .workMode)
            CameraSystemState.shared.lastPhotoMode = .hdr
        })
    }

    /// 设置夜拍模式
    ///
    /// - Parameter value: UInt8，有默认值，可以不设
    private class func setMFNRWorkMode(_ value: UInt8 = 0) -> () {
        CameraSelection.shared.setUploadValue(.leaf(AUTELCameraWorkMode.captureMFNR.rawValue), forBranch: .workMode)
        CameraCommandDeliver.setWorkMode(.captureMFNR, result: { (singleError) in
            CameraSystemState.shared.isStateChanging = false
            if let err = singleError {
                logInfo("set mfnr mode error: \(err.localizedDescription)")
                //                CameraSelection.shared.rollback(.workMode)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(AUTELCameraWorkMode.captureMFNR.rawValue), forBranch: .workMode)
            CameraSystemState.shared.lastPhotoMode = .mfnr
            CameraSystemState.shared.workMode = .captureMFNR
//曝光模式 跟HDR AEB 夜拍 模式没关系 20200305              CameraParametersGetter.getExposure()
            CameraParametersGetter.getPhotoFileFormat()
            AutelRXShared.shared.updateMenu.onNext(true)
            if Int(truncating: UserSettings.shared.currentAircraftVersion) != DroneType.modelB.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, .captureMFNR))
            }
        })
    }

    /// 设置定时拍工作模式并设置定时拍间隔
    ///
    /// - Parameter value: 定时拍枚举原始值
    private class func setTimeLapseWorkModeWithInterval(_ value: UInt8) -> () {
        guard let interval = AUTELCameraPhotoTimeLapseInterval(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .photoTiming)
        CameraSelection.shared.setUploadValue(.branch(.photoTiming), forBranch: .workMode)
        CameraCommandDeliver.setTimeLapseWorkModeWithInterval(interval, with: { (intervalError) in
            CameraSystemState.shared.isStateChanging = false
            if let err = intervalError {
                logInfo("set timing interval error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.photoTiming)
//                CameraSelection.shared.rollback(.workMode)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .photoTiming)
            CameraSelection.shared.setDownloadValue(.branch(.photoTiming), forBranch: .workMode)
            CameraSystemState.shared.lastPhotoMode = .timing(interval)

            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, .captureInterval))
                
            }
            AutelRXShared.shared.updateMenu.onNext(true)
            CameraSystemState.shared.workMode = .captureInterval
        })
    }
    
    /// 设置图片尺寸
    ///
    /// - Parameter value: 尺寸枚举原始值
    private class func setPhotoSizeWithValue(_ value: UInt8) -> () {
        guard let size = AUTELCameraPhotoAspectRatio(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .photoSize)
        CameraCommandDeliver.setPhotoSize(size) { (error) in
            if let err = error {
                logInfo("set photo size error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.photoSize)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .photoSize)

            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                 AutelRXShared.shared.isHDRBtnIsHidden.onNext((size, nil))
            }
        }
    }
    
    /// 设置图片格式
    ///
    /// - Parameter value: 图片格式枚举原始值
    private class func setPhotoFileFormatWithValue(_ value: UInt8) -> () {
        guard let format = AUTELCameraPhotoFileFormat(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .photoFormat)
        CameraCommandDeliver.setPhotoFileFormat(format) { (error) in
            if let err = error {
                logInfo("set photo file format error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.photoFormat)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .photoFormat)
            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, nil))
            }
        }
    }
    
    /// 设置图片格式
     ///
     /// - Parameter value: 图片格式枚举原始值
     private class func setPhotoFormatDelayShotWithValue(_ value: UInt8) -> () {
        
         guard let format = AUTELCameraDelayShotPhotoFormat(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .photoFormatDelayShot)
        DroneConnection.shared.drone?.mainController.navigationManager.delayShotMissionHandler.setCameraDelayShotKeepPhoto(format, withCompletion: { (error) in
                if let err = error {
                    logInfo("delayShot set photo file format error: \(err.localizedDescription)")
                    CameraSelection.shared.rollback(.photoFormatDelayShot)
                    return
                }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .photoFormatDelayShot)
//                         if DroneConnection.shared.isModelB() {
//
//                         } else if DroneConnection.shared.isModelC() {
//                             AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, nil))
//                         }
        })

     }
    
    /// 设置曝光模式
    ///
    /// - Parameter value: 曝光模式枚举原始值
    private class func setExposureModeWithValue(_ value: UInt8) -> () {
        guard let mode = AUTELCameraExposureMode(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .exposureMode)
        CameraCommandDeliver.setExposureMode(mode) { (error) in
            if let err = error {
                logInfo("set exposure mode error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.exposureMode)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .exposureMode)
            
            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {
                //do nothing
            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, nil))
            }
        }
    }
    
    /// 设置ISO
    ///
    /// - Parameter value: ISO的枚举原始值
    private class func setISOWithValue(_ value: UInt8) -> () {
        guard let iso = AUTELCameraISO(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .iso)
        CameraCommandDeliver.setISO(iso) { (error) in
            if let err = error {
                logInfo("set ISO error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.iso)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .iso)
        }
    }
    
    /// 设置光圈
    ///
    /// - Parameter value: 光圈的枚举原始值
    private class func setApertureWithValue(_ value: UInt8) -> () {
        guard let aperture = AUTELCameraAperture(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .aperture)
        CameraCommandDeliver.setAperture(aperture, with: { (error) in
            if let err = error {
                logInfo("set 光圈 error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.aperture)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .aperture)
        })

    }
    
    /// 设置曝光补偿
    ///
    /// - Parameter value: 曝光补偿枚举原始值
    private class func setExposureCompensationWithValue(_ value: UInt8) -> () {
        guard let compensation = AUTELCameraExposureCompensation(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .exposureCompensation)
        CameraCommandDeliver.setExposureCompensation(compensation) { (error) in
            if let err = error {
                logInfo("set exposure compensation error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.exposureCompensation)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .exposureCompensation)
        }
    }
    
    /// 设值自定义白平衡
    ///
    /// - Parameter value: 色温的有效值
    private class func setCustomWhiteBalanceWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .wbCustom)
        //设置白平衡
        setWhiteBalanceWithValue(AUTELCameraWhiteBalance.custom.rawValue)
    }
    
    /// 设置白平衡
    ///
    /// - Parameter value: 白平衡枚举原始值
    private class func setWhiteBalanceWithValue(_ value: UInt8) -> () {
        guard let wb = AUTELCameraWhiteBalance(rawValue: value) else { return }
//        let colorTemperature = CameraSelection.shared.valueWith(.wbCustom).set.digitalValue() ?? 20
        guard let colorTemperature = CameraSelection.shared.valueWith(.wbCustom).set.digitalValue() else { return }
        if wb.isCustom() {
//            guard let _ = CameraSelection.shared.valueWith(.wbCustom).set.digitalValue() else { return }
            CameraSelection.shared.setUploadValue(.branch(.wbCustom), forBranch: .whiteBalance)
        } else {
            CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .whiteBalance)
        }
        CameraCommandDeliver.setWhiteBalance(wb, andColorTemperature: colorTemperature) { (error) in
            if let err = error {
                logInfo("set white balance error: \(err.localizedDescription)")
                if wb.isCustom() {
                    CameraSelection.shared.rollback(.wbCustom)
                }
                CameraSelection.shared.rollback(.whiteBalance)
                return
            }
            if wb.isCustom() {
                CameraSelection.shared.setDownloadValue(.branch(.wbCustom), forBranch: .whiteBalance)
                //将色温值设为自定义白平衡的值
                CameraSelection.shared.setDownloadValue(.leaf(colorTemperature), forBranch: .wbCustom)
            } else {
                CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .whiteBalance)
            }
        }
    }
    
    class func shouldSetWhiteBalanceWithCustomValue() -> Bool {
        guard let _ = CameraSelection.shared.valueWith(.wbCustom).set.digitalValue() else { return false}
        return true
    }
    
    /// 设置数码滤波
    ///
    /// - Parameter value: 数码滤波枚举原始值
    private class func setDigitalFilterWithValue(_ value: UInt8) -> () {
        guard let filter = AUTELCameraDigitalFilter(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .digitalFilter)
        CameraCommandDeliver.setDigitalFilter(filter) { (error) in
            if let err = error {
                logInfo("set digital filter error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.digitalFilter)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .digitalFilter)
        }
    }

    /// 设置伪彩
    ///
    /// - Parameter value: 数码滤波枚举原始值
    private static var setIrColorOpId  = 0
    private class func setIrColor(_ value: UInt8) -> () {
        guard let irColor = AUTELCameraIrColorType(rawValue: value) else { return }
        setIrColorOpId  = setIrColorOpId + 1
        let opId = setIrColorOpId
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .irColor)
        CameraCommandDeliver.setIrColor(irColor) { (error) in
            if let err = error {
                logInfo("set irColor error: \(err.localizedDescription)")
                if opId == setIrColorOpId {
                    CameraSelection.shared.rollback(.irColor)
                }
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .irColor)
        }
    }
    
    /// 设置图像风格的自定义参数
    ///
    /// - Parameters:
    ///   - value: 参数值
    ///   - branch: 参数所属分支
    private class func setPhotoStyleParamWithValue(_ value: UInt8, forBranch branch: CameraMenuBranch) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: branch)
        setPhotoStyleWithValue(AUTELCameraPhotoStyle.custom.rawValue)
    }
    
    /// 设置图像风格
    ///
    /// - Parameter value: 图像风格枚举原始值
    class func setPhotoStyleWithValue(_ value: UInt8) -> () {
        guard let style = AUTELCameraPhotoStyle(rawValue: value) else { return }
        //更新主菜单
        let photoStyle: CameraMenuStyle = style.isCustom() ? .branch(.styleCustom) : .leaf(style.rawValue)
        CameraSelection.shared.setUploadValue(photoStyle, forBranch: .style)
        //发消息给摄像头
        //sharpness ，contrast ，saturation hue， 实际上在 style == styleCustom 才生效 或者说是才有意义。
        let (sharpness,contrast,saturation,hue) = customPhotoStyleSelectionDidSetValue()
        
        CameraCommandDeliver.setPhotoStyle(style, sharpness: sharpness, contrast: contrast, saturation: saturation, andHue: hue) { (error) in
            if let err = error {
                logInfo("set photo style error: \(err.localizedDescription)")
                if style.isCustom() {
                    CameraSelection.shared.rollback(.sharpness)
                    CameraSelection.shared.rollback(.contrast)
                    CameraSelection.shared.rollback(.saturation)
                    CameraSelection.shared.rollback(.hue)
                }
                CameraSelection.shared.rollback(.style)
                return
            }
            if style.isCustom() {
                CameraSelection.shared.setDownloadValue(.leaf(sharpness.toUInt8()), forBranch: .sharpness)
                CameraSelection.shared.setDownloadValue(.leaf(contrast.toUInt8()), forBranch: .contrast)
                CameraSelection.shared.setDownloadValue(.leaf(saturation.toUInt8()), forBranch: .saturation)
                CameraSelection.shared.setDownloadValue(.leaf(hue.toUInt8()), forBranch: .hue)
            }
            let photoStyle: CameraMenuStyle = style.isCustom() ? .branch(.styleCustom) : .leaf(style.rawValue)
            CameraSelection.shared.setDownloadValue(photoStyle, forBranch: .style)
        }
    }
    
    class func customPhotoStyleSelectionDidSetValue() -> (sharpness:Int8,contrast:Int8,saturation:Int8,hue:Int8) {
        let sharpness = CameraSelection.shared.valueWith(.sharpness).set.digitalValue()?.toInt8() ?? 0
        let contrast = CameraSelection.shared.valueWith(.contrast).set.digitalValue()?.toInt8() ?? 0
        let saturation = CameraSelection.shared.valueWith(.saturation).set.digitalValue()?.toInt8() ?? 0
        let hue = CameraSelection.shared.valueWith(.hue).set.digitalValue()?.toInt8() ?? 0
        return (sharpness,contrast,saturation,hue)
    }
    
    class func shouldPhotoStyleWithCustomValue() -> Bool {
//        if  let _ = CameraSelection.shared.valueWith(.sharpness).set.digitalValue() ,
//               let _ = CameraSelection.shared.valueWith(.contrast).set.digitalValue(),
//               let _ = CameraSelection.shared.valueWith(.saturation).set.digitalValue(),
//               let _ = CameraSelection.shared.valueWith(.hue).set.digitalValue(){
//            return true
//        }
         return true
    }
    
//   与 CameraMenuItemPicker requestCustomStyleWithItem 一一对应
    class func setCustomPhotoStyleWithValue(_ index: Int) -> () {
        guard index >= 0 && index < 4 else {
            return
        }
        let branch: CameraMenuBranch = [.sharpness, .contrast, .saturation, .hue][index]
        let value: CameraMenuStyle = .branch(branch)
        CameraSelection.shared.setUploadValue(value, forBranch: .styleCustom)
        CameraSelection.shared.setDownloadValue(value, forBranch: .styleCustom)
    }
    
    /// 设置视频制式
    ///
    /// - Parameter value: 视频制式枚举原始值
    private class func setVideoStandartWithValue(_ value: UInt8) -> () {
        guard let standard = AUTELCameraVideoStandard(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .videoStandard)
        CameraCommandDeliver.setVideoStandard(standard) { (error) in
            if let err = error {
                logInfo("set video standard error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.videoStandard)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .videoStandard)
        }
    }
    
    /// 设置视频文件格式
    ///
    /// - Parameter value: 视频文件格式枚举原始值
    private class func setVideoFileFormatWithValue(_ value: UInt8) -> () {
        guard let format = AUTELCameraVideoFileFormat(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .videoFormat)
        CameraCommandDeliver.setVideoFileFormat(format) { (error) in
            if let err = error {
                logInfo("set video file format error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.videoFormat)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .videoFormat)
        }
    }
    
    /// 设置视频分辨率
    ///
    /// - Parameter value: 视频分辨率枚举原始值
    private class func setVideoResolutionWithValue(_ value: UInt8) -> () {
        guard let resolution = AUTELCameraVideoResolution(rawValue: value) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .videoResolution)
        //获取当前分辨率下最大的帧率
        let dict = CameraConnection.shared.camera?.parameters.supportedVideoResolutionAndFrameRateRange()
        guard let maxFrameRate = dict?.first(where: { (key, _) -> Bool in
            return key.uint8Value == value
        })?.value.last?.uint8Value else { return }
        setVideoFrameRateWithValue(maxFrameRate)
    }
    
    /// 设置视频帧率
    ///
    /// - Parameter value: 视频帧率枚举原始值
    private class func setVideoFrameRateWithValue(_ value: UInt8) -> () {
        // 去掉这段代码, 如果两个分辨率的最大帧率是一致的,那么会造成在这两种分辨率之前切换,起始并没有发送设置分辨率和帧率的命令
        // 即 bug IDG2-934 的原因
//        //如果新值和旧值不相等则更新，这里主要是打破循环调用
//        guard value != CameraSelection.shared.valueWith(.frameRate).set.digitalValue() else { return }
        guard let frameRate = AUTELCameraVideoFrameRate(rawValue: value) else { return }
        guard let resValue = CameraSelection.shared.valueWith(.videoResolution).set.digitalValue() else { return }
        guard let resolution = AUTELCameraVideoResolution(rawValue: resValue) else { return }
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .frameRate)
        CameraCommandDeliver.setVideoResolution(resolution, andFrameRate: frameRate) { (error) in
            if let err = error {
                logInfo("set video resolution error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.frameRate)
                CameraSelection.shared.rollback(.videoResolution)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .frameRate)
            CameraSelection.shared.setDownloadValue(.leaf(resValue), forBranch: .videoResolution)

            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHiddenForVideo.onNext((resolution, frameRate))
            }
        }
    }
    
    /// 设置数码变焦
    ///
    /// - Parameter value: 数码变焦值
    private class func setDigitalZoomScaleWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .digitalZoom)
        var tmpValue: Float = 1.0
        if CameraSystemState.shared.displayModeIndex == DisplayModeIndex.infrared || (DroneConnection.shared.drone?.camera.isEarlyThanModelC ?? false) {
            tmpValue = Float(value / 10)
        } else {
            tmpValue = Float(Double(value) / 10.0)
        }
        CameraCommandDeliver.setDigitalZoomScale(tmpValue) { (error) in
            if let err = error {
                logInfo("set digital zoom scale error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.digitalZoom)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .digitalZoom)
        }
    }
    
    /// 设置AELock
    ///
    /// - Parameter value: 锁住状态
    private class func setAELockWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .aeLock)
        let isLocked = value == 1
        CameraCommandDeliver.setAELock(isLocked) { (error) in
            if let err = error {
                logInfo("set ae lock error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.aeLock)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .aeLock)
        }
    }
    
    /// 设置 AF || MF
    ///
    /// - Parameter value:
    class func setAF(_ value: UInt8) -> () {
        printLog("set af value \(value)")
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .af)
        var model = AUTELCameraLensFocusMode.manual
        if value == FocusValue.mfValue {
            model = AUTELCameraLensFocusMode.manual
        } else if value == FocusValue.afValue {
            model = AUTELCameraLensFocusMode.AFC
        }
        CameraCommandDeliver.setAF(model) { (error) in
            if let err = error {
                logInfo("set af error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.af)
                return
            }
            if value >= FocusValue.afValue {
                FocusEventObservable.shared.focesOperate.onNext(value)
                CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .af)
            }
        }
        
//        if value <= FocusValue.infinityValue {
//            CameraCommandDeliver.setObjectDistance(value == FocusValue.infinityValue ? -1 : Int(value)) { (error) in
//                if let err = error {
//                    printLog("set setObjectDistance: \(err.localizedDescription)")
//                    CameraSelection.shared.rollback(.af)
//                    return
//                }
//                FocusEventObservable.shared.focesOperate.onNext(value)
//                CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .af)
//            }
//        }
    }
    
    /// 设置AF XY
    ///
    /// - Parameter value:
    class func setAF(row: Int, col: Int) -> () {
        guard let value = CameraSelection.shared.valueWith(.af).get.digitalValue() else { return }
//        let model = value == 0 ? AUTELCameraLensFocusMode.auto : AUTELCameraLensFocusMode.manual
        CameraCommandDeliver.setAF(.spot, row: row, col: col) { (error) in
            if let err = error {
                logInfo("set af xy error: \(err.localizedDescription)")
                return
            }
        }
    }

    /// 设置MF XY
        ///
        /// - Parameter value:
        class func setMF(row: Int, col: Int) -> () {
            CameraCommandDeliver.setMF(row: row, col: col) { (error) in
                if let err = error {
                    logInfo("set MF xy error: \(err.localizedDescription)")
                    return
                }
            }
        }
    
    class func setMfFocusAssistWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .mfFocusAssist)
        CameraCommandDeliver.setMFAssistFocus(Int(value)) { (error) in
            if let err = error {
                logInfo("set MFAssistFocus enabled error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.mfFocusAssist)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .mfFocusAssist)
        }
    }

    /// 设置ROI XY
    ///
    /// - Parameter value:
    class func setROI(row: Int, col: Int) -> () {
        CameraCommandDeliver.setROIAreaAtRow(UInt8(row), andCol: UInt8(col)) { (error) in
            if let err = error {
                logInfo("set ROI xy error: \(err.localizedDescription)")
                return
            }
        }
    }
    
    /// 设置抗闪烁
    ///
    /// - Parameter value: 抗闪烁值
    private class func setAntiFilckerWithValue(_ value: UInt8) -> () {
        guard let antiFlicker = AUTELCameraAntiFlicker(rawValue: value) else { return }
        var num = value
        if !CameraAvailabilityChecker.isAntiFlickerAvailableWithValue(value) {
            num = AUTELCameraAntiFlicker.flicker60Hz.rawValue
            let _ = SystemMessageCenter.shared.insertAMessageEvent(type: MCMessageEventType.FrameRateOver100ParameterChange)
        }
        CameraSelection.shared.setUploadValue(.leaf(num), forBranch: .antiFlicker)
        CameraCommandDeliver.setAntiFlicker(antiFlicker) { (error) in
            if let err = error {
                logInfo("set anti flicker error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.antiFlicker)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .antiFlicker)
        }
    }
    
    /// 设置点测光的列序号
    ///
    /// - Parameter value: 列序号
    private class func setSpotColWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .spotCol)
    }
    
    /// 设置点测光的横序号
    ///
    /// - Parameter value: 横序号
    private class func setSpotRowWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .spotRow)
    }
    
    /// 设置点测光坐标
    private class func setSpotCoordinate() {
        guard let row = CameraSelection.shared.valueWith(.spotRow).set.digitalValue() else { return }
        guard let col = CameraSelection.shared.valueWith(.spotCol).set.digitalValue() else { return }
        CameraCommandDeliver.setSpotMeteringAreaAtRow(row, andCol: col) { (error) in
            if let err = error {
                logInfo("set spot metering error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.spotCol)
                CameraSelection.shared.rollback(.spotRow)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(col), forBranch: .spotCol)
            CameraSelection.shared.setDownloadValue(.leaf(row), forBranch: .spotRow)
        }
    }
    
    /// 设置直方图可用状态
    ///
    /// - Parameter value: 是否可用
    private class func setHistogramWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .histogram)
        let enabled = value == 1 ? true : false
        CameraCommandDeliver.setHistogram(enabled) { (error) in
            if let err = error {
                logInfo("set histogram enabled error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.histogram)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .histogram)
        }
    }

    /// 设置透雾
    ///
    /// - Parameter enabled: 是否可用
    class func setDehaze(enabled: Bool, and value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(enabled ? 1 : 0), forBranch: .dehaze)
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .dehazeValue)
        let switchStatus = enabled ? AUTELCameraSwitchStatus.enable : AUTELCameraSwitchStatus.disable
        CameraCommandDeliver.setDehaze(switchStatus, and: value) { (error) in
            if let err = error {
                logInfo("set histogram enabled error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.dehaze)
                CameraSelection.shared.rollback(.dehazeValue)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .dehaze)
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .dehazeValue)
        }
    }

    /// 设置ROI
    ///
    /// - Parameter enabled: 是否可用
    class func setROI(enabled: Bool, and value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(enabled ? 1 : 0), forBranch: .roi)
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .roiValue)
        let switchStatus = enabled ? AUTELCameraSwitchStatus.enable : AUTELCameraSwitchStatus.disable
        CameraCommandDeliver.setROI(switchStatus, and: value) { (error) in
            if let err = error {
                logInfo("set histogram enabled error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.roi)
                CameraSelection.shared.rollback(.roiValue)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .roi)
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .roiValue)
        }
    }
    
    /// 设置快门速度
    ///
    /// - Parameter value: 速度枚举原始值
    private class func setShutterSpeedWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .shutterSpeed)
        guard let speed = AUTELCameraShutterSpeed(rawValue: value) else { return }
        CameraCommandDeliver.setShutterSpeed(speed) { (error) in
            if let err = error {
                logInfo("set shutter speed error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.shutterSpeed)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .shutterSpeed)
        }
    }
    
    /// 设置PIV
    ///
    /// - Parameter value: piv枚举原始值
    private class func setPIVWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .piv)
        guard let interval = AUTELCameraPictureInVideoInterval(rawValue: value) else { return }
        CameraCommandDeliver.setPIV(value != UInt8.max, interval: interval, with: { (error) in
            if let err = error {
                logInfo("set piv error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.piv)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .piv)
        })
    }
    
    /// 设置字幕
    ///
    /// - Parameter value: UInt8
    private class func setCaptionEnabledWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .captionEnable)
        let enabled = value == 1 ? true : false
        CameraCommandDeliver.setVideoCaptionEnable(enabled) { (error) in
            if let err = error {
                logInfo("set caption enabled error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.captionEnable)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .captionEnable)
        }
    }
    
    /// 设置视频文件压缩标准
    ///
    /// - Parameter value: UInt8
    private class func setVideoEncodingStandard(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .encodingFormat)
        guard let standard = AUTELCameraVideoFileCompressionStandard(rawValue: value) else { return }
        CameraCommandDeliver.setVideoEncodingStandard(standard) { (error) in
            if let err = error {
                logInfo("set video encoding standard error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.encodingFormat)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .encodingFormat)
        }
    }
    
    /// 储存位置
    ///
    /// - Parameter value: UInt8
    private class func setStore(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .store)
        guard let type = AUTELCameraStorageType(rawValue: value) else { return }
        CameraCommandDeliver.setStore(type) { (error) in
            if let err = error {
                logInfo("set store error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.store)
                return
            }
            UserSettings.shared.storeRaw = Int(value)
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .store)
            AutelRXShared.shared.cameraStoreState.onNext((isCameraConnected: true, isInserted: true, isFull: false))
        }
    }
    
    class func setGimbalLockStateWithValue(_ value: UInt8) -> () {
        CameraSelection.shared.setUploadValue(.leaf(value), forBranch: .gimbalLockState)
        guard let status = AUTELCameraGimbalLockState(rawValue: value) else { return }
        CameraCommandDeliver.setGimbalLockState(status) { (error) in
            if let err = error {
                logInfo("set GimbalLockState enabled error: \(err.localizedDescription)")
                CameraSelection.shared.rollback(.gimbalLockState)
                return
            }
            CameraSelection.shared.setDownloadValue(.leaf(value), forBranch: .gimbalLockState)
        }
    }

    /// 取消AE锁
    ///
    private class func updateAEAFLockedEnable() -> () {
        
        if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
            CameraSpotHandler.noteAFAEEnableSign(.af_ae_unLock_backCenter) //说是 modelc 要动画 😑
        }else{
            CameraSpotHandler.noteAFAEEnableSign(.af_ae_unLock)
        }
    }
    
    private class func exposureModeWillChange() -> () {
        CameraSpotHandler.noteAFAEEnableSign(.exposureMode_willChange)
    }
    private class func exposureModeDidChange() -> () {
        CameraSpotHandler.noteAFAEEnableSign(.exposureMode_didChange)
    }
    private class func focusModeWillChange() -> () {
        CameraSpotHandler.noteAFAEEnableSign(.focusMode_willChange)
    }
    private class func focusModeDidChange() -> () {
        CameraSpotHandler.noteAFAEEnableSign(.focusMode_didChange)
    }
}
