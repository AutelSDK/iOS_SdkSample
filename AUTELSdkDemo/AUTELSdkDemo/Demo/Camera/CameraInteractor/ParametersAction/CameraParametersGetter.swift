//
//  CameraParametersLoader.swift
//  AutelGen2
//
//  Created by Devin on 2017/10/16.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

/// Hero: 获取相机所有参数
class CameraParametersGetter {
    
    class func loadAllParameters() -> Void {
        getDisplayMode()
        getIrColor()
        getAebCount()
        getBurstCount()
        getTimeLapseInterval()
        getWorkMode()
        getAF()
        getMFAssistFocus()
        getObjectDistance()
        getPIV()
        getVideoStandard()
        getVideoResolutionAndFrameRate()
        getVideoFileFormat()
        getPhotoSize()
        getPhotoFileFormat()
        getPhotoFormatDelayShot()
        getExposure()
        getISO()
        getShutterSpeed()
        getWhiteBalance()
        getDehaze()
        getROI()
        getPhotoStyle()
        getExposureCompensation()
        getDigitalFilter()
        getVideoEncodingStandard()
        getDigitalZoom()
        getAperture()
        getAELock()
        getHistogram()
        getSpotMeteringArea()
        getCaptionEnable()
        getAntiFlicker()
        getStore()
        getGimbalLockState()
        //加载默认值
        loadDefaultValue()
    }
    
    /// 获取工作模式
    class func getWorkMode() -> Void {
        CameraCommandDeliver.getWorkMode { (workMode, error) in
            if let err = error {
                printLog("get camera work mode failure.\(err.localizedDescription)")
                return
            }
            printLog("get camera work mode success -> \(workMode)")
            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, workMode))
            }
            //只处理图片相关
            switch workMode {
            case .captureAEB:
                CameraSelection.shared.setDownloadValue(.branch(.photoAeb), forBranch: .workMode)
                CameraSelection.shared.setUploadValue(.branch(.photoAeb), forBranch: .workMode)
            case .captureBurst:
                CameraSelection.shared.setDownloadValue(.branch(.photoBurst), forBranch: .workMode)
                CameraSelection.shared.setUploadValue(.branch(.photoBurst), forBranch: .workMode)
            case .captureInterval:
                CameraSelection.shared.setDownloadValue(.branch(.photoTiming), forBranch: .workMode)
                CameraSelection.shared.setUploadValue(.branch(.photoTiming), forBranch: .workMode)
            case .captureSingle:
                CameraSelection.shared.setDownloadValue(.leaf(AUTELCameraWorkMode.captureSingle.rawValue), forBranch: .workMode)
                CameraSelection.shared.setUploadValue(.leaf(AUTELCameraWorkMode.captureSingle.rawValue), forBranch: .workMode)
            case .captureHDR:
                CameraSelection.shared.setDownloadValue(.leaf(AUTELCameraWorkMode.captureHDR.rawValue), forBranch: .workMode)
                CameraSelection.shared.setUploadValue(.leaf(AUTELCameraWorkMode.captureHDR.rawValue), forBranch: .workMode)
            case .captureMFNR:
                CameraSelection.shared.setDownloadValue(.leaf(AUTELCameraWorkMode.captureMFNR.rawValue), forBranch: .workMode)
                CameraSelection.shared.setUploadValue(.leaf(AUTELCameraWorkMode.captureMFNR.rawValue), forBranch: .workMode)
            default:
                return
            }
        }
    }
    
    /// 获取红外模式
    class func getDisplayMode() -> Void {
        CameraCommandDeliver.getDisplayMode { (displayMode, error) in
            if let err = error {
                printLog("get displayMode mode failure.\(err.localizedDescription)")
                return
            }
            printLog("get displayMode mode success -> \(displayMode)")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(displayMode.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .display)
            CameraSelection.shared.setUploadValue(style, forBranch: .display)
            
            
            var tmpIndex = DisplayModeIndex.visible
            if displayMode == AUTELCameraThermalDisplayMode.infraredRadiation {
                tmpIndex = DisplayModeIndex.infrared
            } else if displayMode == AUTELCameraThermalDisplayMode.picturePicture {
                tmpIndex = DisplayModeIndex.pIP
            } else if displayMode == AUTELCameraThermalDisplayMode.visible {
                tmpIndex = DisplayModeIndex.visible
            }
            CameraSystemState.shared.displayModeIndex = tmpIndex
            AutelRXShared.shared.displayModeIndex.onNext(tmpIndex)
        }
    }
    
    /// 获取连拍数量
    class func getBurstCount() -> Void {
        CameraCommandDeliver.getBurstCount { (count, error) in
            if let err = error {
                printLog("get burst count error:\(err.localizedDescription)")
                return
            }
            printLog("get burst count success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(count.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .photoBurst)
            CameraSelection.shared.setUploadValue(style, forBranch: .photoBurst)
        }
    }
    
    /// 获取aeb连拍数量
    class func getAebCount() -> Void {
        CameraCommandDeliver.getAebCount { (count, error) in
            if let err = error {
                printLog("get aeb count error:\(err.localizedDescription)")
                return
            }
            printLog("get aeb count success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(count.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .photoAeb)
            CameraSelection.shared.setUploadValue(style, forBranch: .photoAeb)
        }
    }
    
    /// 获取定时拍间隔
    class func getTimeLapseInterval() -> Void {
        CameraCommandDeliver.getTimeLapseInterval { (interval, error) in
            if let err = error {
                printLog("get time lapse interval error: \(err.localizedDescription)")
                return
            }
            printLog("get time lapse success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(interval.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .photoTiming)
            CameraSelection.shared.setUploadValue(style, forBranch: .photoTiming)
        }
    }
    
    /// 获取视频分辨率和帧率
    class func getVideoResolutionAndFrameRate() -> Void {
        CameraCommandDeliver.getVideoResolutionAndFrameRate { (resolution, frameRate, error) in
            if let err = error {
                printLog("get video resolution error: \(err.localizedDescription)")
                return
            }
            printLog("get video resolution success resolution >>> \(resolution.rawValue)")
            //相机连上后，第一次请求默认上传和下载值相同
            var style: CameraMenuStyle = .leaf(resolution.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .videoResolution)
            CameraSelection.shared.setUploadValue(style, forBranch: .videoResolution)
            style = .leaf(frameRate.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .frameRate)
            CameraSelection.shared.setUploadValue(style, forBranch: .frameRate)

            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHiddenForVideo.onNext((resolution, frameRate))
            }
        }
    }
    
    /// 获取字幕支持
    class func getCaptionEnable() -> Void {
        CameraCommandDeliver.getVideoCaption { (enabled, error) in
            if let err = error {
                printLog("get caption enable error: \(err.localizedDescription)")
                return
            }
            printLog("get caption enable success")
            let value: UInt8 = enabled ? 1 : 0
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(value)
            CameraSelection.shared.setDownloadValue(style, forBranch: .captionEnable)
            CameraSelection.shared.setUploadValue(style, forBranch: .captionEnable)
        }
    }
    
    /// 获取视频文件格式
    class func getVideoFileFormat() -> Void {
        CameraCommandDeliver.getVideoFileFormat { (format, error) in
            if let err = error {
                printLog("get video file format error: \(err.localizedDescription)")
                return
            }
            printLog("get video file format success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(format.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .videoFormat)
            CameraSelection.shared.setUploadValue(style, forBranch: .videoFormat)
            
        }
    }
    
    /// 获取视频制式
    class func getVideoStandard() -> Void {
        CameraCommandDeliver.getVideoStandard { (standard, error) in
            if let err = error {
                printLog("get video standard error: \(err.localizedDescription)")
                return
            }
            printLog("get video standard success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(standard.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .videoStandard)
            CameraSelection.shared.setUploadValue(style, forBranch: .videoStandard)
        }
    }
    
    /// 获取图片尺寸
    class func getPhotoSize() -> Void {
        CameraCommandDeliver.getPhotoSize { (size, error) in
            if let err = error {
                printLog("get photo size error: \(err.localizedDescription)")
                return
            }
            printLog("get photo size success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(size.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .photoSize)
            CameraSelection.shared.setUploadValue(style, forBranch: .photoSize)
            
            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, nil))
            }
        }
    }
    
    /// 获取图片文件格式
    class func getPhotoFileFormat() -> Void {
        CameraCommandDeliver.getPhotoFileFormat { (format, error) in
            if let err = error {
                printLog("get photo file format error: \(err.localizedDescription)")
                return
            }
            printLog("get photo file format success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(format.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .photoFormat)
            CameraSelection.shared.setUploadValue(style, forBranch: .photoFormat)
            
            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, nil))
            }
        }
    }
    
    class func getPhotoFormatDelayShot() -> Void {
    
        DroneConnection.shared.drone?.mainController.navigationManager.delayShotMissionHandler.getCameraDelayShotKeepPhoto(completion: { (format, error) in
               if let err = error {
                   printLog("delayShot get photo file format error: \(err.localizedDescription)")
                   return
               }
               printLog("delayShot get photo file format success")
                let style: CameraMenuStyle = .leaf(format.rawValue)
                 CameraSelection.shared.setDownloadValue(style, forBranch: .photoFormatDelayShot)
                 CameraSelection.shared.setUploadValue(style, forBranch: .photoFormatDelayShot)
            
            //            if DroneConnection.shared.isModelB() {
            //
            //            } else if DroneConnection.shared.isModelC() {
            //                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, nil))
            //            }
            
        })

    }
    
    
    /// 获取曝光模式
    class func getExposure() -> Void {
        CameraCommandDeliver.getExposure { (exposure, error) in
            if let err = error {
                printLog("get exposure error: \(err.localizedDescription)")
                return
            }
            printLog("get exposure success \(exposure.rawValue)")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(exposure.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .exposureMode)
            CameraSelection.shared.setUploadValue(style, forBranch: .exposureMode)
            
            if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {

            } else if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelC.rawValue {
                AutelRXShared.shared.isHDRBtnIsHidden.onNext((nil, nil))
            }
        }
    }
    
    /// 获取 AF
    class func getAF() -> Void {
        CameraCommandDeliver.getAF { (afModel, error) in
            if let err = error {
                printLog("get af error: \(err.localizedDescription)")
                return
            }
            printLog("get af success \(afModel)")
            //相机连上后，第一次请求默认上传和下载值相同
            if afModel == .AFC {
                FocusEventObservable.shared.focesOperate.onNext(UInt8(FocusValue.afValue))
                let style: CameraMenuStyle = .leaf(UInt8(FocusValue.afValue))
                CameraSelection.shared.setDownloadValue(style, forBranch: .af)
                CameraSelection.shared.setUploadValue(style, forBranch: .af)
            } else if afModel == .manual {
                FocusEventObservable.shared.focesOperate.onNext(UInt8(FocusValue.mfValue))
                let style: CameraMenuStyle = .leaf(UInt8(FocusValue.mfValue))
                CameraSelection.shared.setDownloadValue(style, forBranch: .af)
                CameraSelection.shared.setUploadValue(style, forBranch: .af)
//                getObjectDistance()
            }

        }
    }

    /// 获取 物距
    class func getObjectDistance() -> Void {
        // TODO: Hero - 处理无穷大
        CameraCommandDeliver.getObjectDistance { (distance, error) in
            if let err = error {
                printLog("get distance error: \(err.localizedDescription)")
                return
            }
            printLog("get distance success")
            //相机连上后，第一次请求默认上传和下载值相同
//            let style: CameraMenuStyle = .leaf(UInt8(distance))
//            CameraSelection.shared.setDownloadValue(style, forBranch: .af)
//            CameraSelection.shared.setUploadValue(style, forBranch: .af)
        }
    }
    
    
    class func getMFAssistFocus() -> Void {
        CameraCommandDeliver.getMFAssistFocus { (enable, error) in
            if let err = error {
                printLog("get MFAssistFocus error: \(err.localizedDescription)")
                return
            }
            printLog("get MFAssistFocus success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(UInt8(enable))
            CameraSelection.shared.setDownloadValue(style, forBranch: .mfFocusAssist)
            CameraSelection.shared.setUploadValue(style, forBranch: .mfFocusAssist)
        }
    }
    
    /// 获取感光度
    class func getISO() -> Void {
        CameraCommandDeliver.getISO { (iso, error) in
            if let err = error {
                printLog("get iso error: \(err.localizedDescription)")
                return
            }
            printLog("get iso success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(iso.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .iso)
            CameraSelection.shared.setUploadValue(style, forBranch: .iso)
        }
    }
    
    /// 获取快门速度
    class func getShutterSpeed() -> Void {
        CameraCommandDeliver.getShutterSpeed { (speed, error) in
            if let err = error {
                printLog("get shutter speed error: \(err.localizedDescription)")
                return
            }
            printLog("get shutter speed success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(speed.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .shutterSpeed)
            CameraSelection.shared.setUploadValue(style, forBranch: .shutterSpeed)
        }
    }
    
    /// 获取曝光补偿
    class func getExposureCompensation() -> Void {
        CameraCommandDeliver.getExposureCompensation { (compensation, error) in
            if let err = error {
                printLog("get exposure compensation error: \(err.localizedDescription)")
                return
            }
            printLog("get exposure success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(compensation.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .exposureCompensation)
            CameraSelection.shared.setUploadValue(style, forBranch: .exposureCompensation)
        }
    }
    
    /// 获取点测光位置
    private class func getSpotMeteringArea() -> Void {
        CameraCommandDeliver.getSpotMeteringArea { (row, col, error) in
            if let err = error {
                printLog("get sopt meter area error: \(err.localizedDescription)")
                return
            }
            printLog("get sopt meter area success")
            //相机连上后，第一次请求默认上传和下载值相同
            var style: CameraMenuStyle = .leaf(row)
            CameraSelection.shared.setDownloadValue(style, forBranch: .spotRow)
            CameraSelection.shared.setUploadValue(style, forBranch: .spotRow)
            style = .leaf(col)
            CameraSelection.shared.setDownloadValue(style, forBranch: .spotCol)
            CameraSelection.shared.setUploadValue(style, forBranch: .spotCol)
        }
    }
    
    /// 获取白平衡
    class func getWhiteBalance() -> Void {
        CameraCommandDeliver.getWhiteBalance { (wb, colorTemperature, error) in
            if let err = error {
                printLog("get white balance error: \(err.localizedDescription)")
                return
            }
            printLog("get white balance success")
            //相机连上后，第一次请求默认上传和下载值相同
            var style: CameraMenuStyle = .leaf(colorTemperature)
            CameraSelection.shared.setDownloadValue(style, forBranch: .wbCustom)
            CameraSelection.shared.setUploadValue(style, forBranch: .wbCustom)
            style = wb.isCustom() ? .branch(.wbCustom) : .leaf(wb.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .whiteBalance)
            CameraSelection.shared.setUploadValue(style, forBranch: .whiteBalance)
        }
    }

    /// 获取透雾
    class func getDehaze() -> Void {
        CameraCommandDeliver.getDehaze { (switchStatus, strength, error) in
            if let err = error {
                printLog("get Dehaze error: \(err.localizedDescription)")
                return
            }
            printLog("get Dehaze success")
            //相机连上后，第一次请求默认上传和下载值相同
            var style: CameraMenuStyle = .leaf(switchStatus.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .dehaze)
            CameraSelection.shared.setUploadValue(style, forBranch: .dehaze)
            style = .leaf(strength)
            CameraSelection.shared.setDownloadValue(style, forBranch: .dehazeValue)
            CameraSelection.shared.setUploadValue(style, forBranch: .dehazeValue)
        }
    }

    /// 获取ROI
    class func getROI() -> Void {
        CameraCommandDeliver.getROI { (switchStatus, strength, error) in
            if let err = error {
                printLog("get ROI error: \(err.localizedDescription)")
                return
            }
            printLog("get ROI success")
            //相机连上后，第一次请求默认上传和下载值相同
            var style: CameraMenuStyle = .leaf(switchStatus.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .roi)
            CameraSelection.shared.setUploadValue(style, forBranch: .roi)
            style = .leaf(strength)
            CameraSelection.shared.setDownloadValue(style, forBranch: .roiValue)
            CameraSelection.shared.setUploadValue(style, forBranch: .roiValue)
        }
    }

    
    /// 获取抗闪烁模式
    private class func getAntiFlicker() -> Void {
        CameraCommandDeliver.getAntiFlicker { (antiFlicker, error) in
            if let err = error {
                printLog("get anti flicker error: \(err.localizedDescription)")
                return
            }
            printLog("get anti flicker success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(antiFlicker.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .antiFlicker)
            CameraSelection.shared.setUploadValue(style, forBranch: .antiFlicker)
        }
    }

    /// 获取储存位置
    private class func getStore() -> Void {
        CameraCommandDeliver.getStore { (cameraStorageType, error) in
            if let err = error {
                printLog("get store error: \(err.localizedDescription)")
                if Int(truncating: UserSettings.shared.currentAircraftVersion) == DroneType.modelB.rawValue {
                    UserSettings.shared.storeRaw = Int(AUTELCameraStorageType.sdCard.rawValue)
                } else {
                    //do nothing
                }
                return
            }
            printLog("get store success========= =1=")
            DispatchQueue.main.async {
                UserSettings.shared.storeRaw = Int(cameraStorageType.rawValue)
            }
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(cameraStorageType.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .store)
            CameraSelection.shared.setUploadValue(style, forBranch: .store)
        }
    }
    
    class func getGimbalLockState() -> Void {
        CameraCommandDeliver.getGimbalLockState { (lockState, error) in
            if let err = error {
                printLog("get gimbalLockState error: \(err.localizedDescription)")
                return
            }
            printLog("get gimbalLockState success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(UInt8(lockState.rawValue))
            CameraSelection.shared.setDownloadValue(style, forBranch: .gimbalLockState)
            CameraSelection.shared.setUploadValue(style, forBranch: .gimbalLockState)
        }
    }

    /// 获取照片风格
    class func getPhotoStyle() -> Void {
        CameraCommandDeliver.getPhotoStyle { (style, sharpness, contrast, saturation, hue, error) in
            if let err = error {
                printLog("get photo style error: \(err.localizedDescription)")
                return
            }
            printLog("get photo style success")
            //相机连上后，第一次请求默认上传和下载值相同
            var value: CameraMenuStyle = .leaf(sharpness.toUInt8())
            CameraSelection.shared.setDownloadValue(value, forBranch: .sharpness)
            CameraSelection.shared.setUploadValue(value, forBranch: .sharpness)
            value = .leaf(contrast.toUInt8())
            CameraSelection.shared.setDownloadValue(value, forBranch: .contrast)
            CameraSelection.shared.setUploadValue(value, forBranch: .contrast)
            value = .leaf(saturation.toUInt8())
            CameraSelection.shared.setDownloadValue(value, forBranch: .saturation)
            CameraSelection.shared.setUploadValue(value, forBranch: .saturation)
            value = .leaf(hue.toUInt8())
            CameraSelection.shared.setDownloadValue(value, forBranch: .hue)
            CameraSelection.shared.setUploadValue(value, forBranch: .hue)
            
            if style == .custom {
//                value = .branch(.sharpness)
//                CameraSelection.shared.setDownloadValue(value, forBranch: .styleCustom)
//                CameraSelection.shared.setUploadValue(value, forBranch: .styleCustom)
                let value: CameraMenuStyle = .branch(.styleCustom)
                CameraSelection.shared.setDownloadValue(value, forBranch: .style)
                CameraSelection.shared.setUploadValue(value, forBranch: .style)
            } else {
                let value: CameraMenuStyle = .leaf(style.rawValue)
                CameraSelection.shared.setDownloadValue(value, forBranch: .style)
                CameraSelection.shared.setUploadValue(value, forBranch: .style)
            }
        }
    }
    
    /// 获取数码滤镜
    class func getDigitalFilter() -> Void {
        CameraCommandDeliver.getDigitalFilter { (filter, error) in
            if let err = error {
                printLog("get digital filter error: \(err.localizedDescription)")
                return
            }
            printLog("get digital filter success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(filter.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .digitalFilter)
            CameraSelection.shared.setUploadValue(style, forBranch: .digitalFilter)
        }
    }

    /// 获取伪彩
    class func getIrColor() -> Void {
        CameraCommandDeliver.getIrColor { (filter, error) in
            if let err = error {
                printLog("get ir color error: \(err.localizedDescription)")
                return
            }
            printLog("get ir color success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(filter.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .irColor)
            CameraSelection.shared.setUploadValue(style, forBranch: .irColor)
        }
    }
    
    /// 获取光圈值
    class func getAperture() -> Void {
        CameraCommandDeliver.getAperture { (aperture, error) in
            if let err = error {
                printLog("get aperture error: \(err.localizedDescription)")
                return
            }
            printLog("get aperture success")
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(aperture.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .aperture)
            CameraSelection.shared.setUploadValue(style, forBranch: .aperture)
        }
    }
    
    /// 获取数码变焦
    class func getDigitalZoom() -> Void {
        CameraCommandDeliver.getDigitalZoomScale { (scale, error) in
            if let err = error {
                printLog("get digital zoom sacle error: \(err.localizedDescription)")
                return
            }
            printLog("get digital zoom sacle success")
            //相机连上后，第一次请求默认上传和下载值相同
            let tmpScale = scale * 10
            let style: CameraMenuStyle = .leaf(UInt8(tmpScale))
            CameraSelection.shared.setDownloadValue(style, forBranch: .digitalZoom)
            CameraSelection.shared.setUploadValue(style, forBranch: .digitalZoom)
        }
    }
    
    /// 获取AE锁状态
    private class func getAELock() -> Void {
        CameraCommandDeliver.getAELock { (isLocked, error) in
            if let err = error {
                printLog("get ae lock error: \(err.localizedDescription)")
                return
            }
            printLog("get ae lock success")
            let value: UInt8 = isLocked ? 1 : 0
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(value)
            CameraSelection.shared.setDownloadValue(style, forBranch: .aeLock)
            CameraSelection.shared.setUploadValue(style, forBranch: .aeLock)
        }
    }
    
    /// 获取直方图的可用状态
    private class func getHistogram() -> Void {
        CameraCommandDeliver.getHistogram { (enabled, error) in
            if let err = error {
                printLog("get histogram enabled error: \(err.localizedDescription)")
                return
            }
            printLog("get histogram enabledsuccess")
            let value: UInt8 = enabled ? 1 : 0
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(value)
            CameraSelection.shared.setDownloadValue(style, forBranch: .histogram)
            CameraSelection.shared.setUploadValue(style, forBranch: .histogram)
        }
    }
    
    /// 获取PIV
    class func getPIV() -> Void {
        CameraCommandDeliver.getPIV { (autoEnabled, interval, error) in
            if let err = error {
                printLog("get piv error: \(err.localizedDescription)")
                return
            }
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(autoEnabled ? interval.rawValue : 0xff)
            CameraSelection.shared.setDownloadValue(style, forBranch: .piv)
            CameraSelection.shared.setUploadValue(style, forBranch: .piv)
        }
    }
    
    /// 获取视频文件压缩标准
    class func getVideoEncodingStandard() -> Void {
        CameraCommandDeliver.getVideoEncodingStandard { (standard, error) in
            if let err = error {
                printLog("get video encoding standard error: \(err.localizedDescription)")
                return
            }
            //相机连上后，第一次请求默认上传和下载值相同
            let style: CameraMenuStyle = .leaf(standard.rawValue)
            CameraSelection.shared.setDownloadValue(style, forBranch: .encodingFormat)
            CameraSelection.shared.setUploadValue(style, forBranch: .encodingFormat)
        }
    }
    
    /// 设置默认值
    private class func loadDefaultValue() -> Void {
        //设置sharpness
        CameraSelection.shared.setDownloadValue(.leaf(Int8(0).toUInt8()), forBranch: .sharpness)
        CameraSelection.shared.setUploadValue(.leaf(Int8(0).toUInt8()), forBranch: .sharpness)
        //设置contrast
        CameraSelection.shared.setDownloadValue(.leaf(Int8(0).toUInt8()), forBranch: .contrast)
        CameraSelection.shared.setUploadValue(.leaf(Int8(0).toUInt8()), forBranch: .contrast)
        //设置saturation
        CameraSelection.shared.setDownloadValue(.leaf(Int8(0).toUInt8()), forBranch: .saturation)
        CameraSelection.shared.setUploadValue(.leaf(Int8(0).toUInt8()), forBranch: .saturation)
        //设置hue
        CameraSelection.shared.setDownloadValue(.leaf(Int8(0).toUInt8()), forBranch: .hue)
        CameraSelection.shared.setUploadValue(.leaf(Int8(0).toUInt8()), forBranch: .hue)
    }
}
