//
//  CameraCommandSender.swift
//  AutelGen2
//
//  Created by Devin on 2017/10/12.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

typealias ResultHandler = ((Error?) -> ())?

/// Hero: 应用层 调用 底层SDK 相机命令
class CameraCommandDeliver {
    
    private class var camera: AUTELBaseCamera? {
        get {
            return CameraConnection.shared.camera
        }
    }
    
    /// 切换工作模式
    ///
    ///   - Parameter workMode: @see AUTELCameraWorkMode
    ///   - result: 回调
    class func setWorkMode(_ workMode: AUTELCameraWorkMode, result: ResultHandler) {
        camera?.setCameraWorkMode(workMode, withCompletion: { result?($0) })
    }
    
    /// 获取当前相机工作模式
    ///
    /// - Parameter result: 回调
    class func getWorkMode(result: ((AUTELCameraWorkMode, Error?) -> Void)?) {
        camera?.getWorkMode(completion: { result?($0, $1) })
    }
    
    /// 获取当前相机工作图传模式
    ///
    /// - Parameter result: 回调
    class func getDisplayMode(result: ((AUTELCameraThermalDisplayMode, Error?) -> Void)?) {
        camera?.getThermalDisplayMode(completion: { result?($0, $1) })
    }
    
    /// 切换工作模式
    ///
    ///   - Parameter workMode: @see AUTELCameraWorkMode
    ///   - result: 回调
    class func setDisplayMode(_ displayMode: AUTELCameraThermalDisplayMode, result: ResultHandler) {
        camera?.setThermalDisplayMode(displayMode, withCompletion: { result?($0) })
    }
    
    /// 发送开始录像命令
    ///
    /// - Parameter result: 回调
    class func startRecording(result: ResultHandler) {
        camera?.startRecordVideo(completion: { result?($0) })
    }
    
    /// 发送结束录像命令
    ///
    /// - Parameter result: 回调
    class func stopRecording(result: ResultHandler) {
        camera?.stopRecordVideo(completion: { result?($0) })
    }
    
    /// 开始拍照
    ///
    /// - Parameter result: 回调
    class func takePhoto(result: ResultHandler) {
        camera?.startShootPhoto(completion: { result?($0) })
    }
    
    /// 停止拍照
    ///
    /// - Parameter result: 回调
    class func stopPhoto(result: ResultHandler) {
        camera?.stopShootPhoto(completion: { result?($0) })
    }
    
    /// 发送结束录像或者停止拍照命令
    ///
    /// - Parameter result: 回调
    class func stopCamera(result: ResultHandler) {
//        if CameraSystemState.shared.currentStatus() == .videoShooting {
            camera?.stopRecordVideo(completion: { result?($0) })
//        } else if CameraSystemState.shared.currentStatus() == .photoInterval
//            || CameraSystemState.shared.currentStatus() == .photoShooting
//            || CameraSystemState.shared.currentStatus() == .photoPrepared {
//            camera?.stopShootPhoto(completion: { result?($0) })
//        }
    }
    
    /// 恢复出厂设置
    ///
    /// - Parameter result: 回调
    class func loadFactorySettings(result: ResultHandler) {
        camera?.loadFactorySettings{ result?($0) }
    }
    
    /// 设置相机分辨率和帧率
    ///
    /// - Parameters:
    ///   - resolution: 支持的分辨率
    ///   - frameRate: 支持的帧率
    ///   - result: 回调
    class func setVideoResolution(_ resolution: AUTELCameraVideoResolution, andFrameRate rate: AUTELCameraVideoFrameRate, with result: ResultHandler) {
        camera?.setVideoResolution(resolution, andFrameRate: rate, withCompletion: {result?($0)})
    }
    
    /// 获取相机的分辨率和帧率
    ///
    /// - Parameter result: 回调
    class func getVideoResolutionAndFrameRate(result: ((AUTELCameraVideoResolution, AUTELCameraVideoFrameRate, Error?) -> ())?) {
        camera?.getVideoResolutionAndFrameRate(completion: { result?($0, $1, $2) })
    }
    
    /// 设置相机字幕功能的可用状态
    ///
    /// - Parameters:
    ///   - enabled: 可用状态
    ///   - result: 回调
    class func setVideoCaptionEnable(_ enabled: Bool, with result: ResultHandler) {
        camera?.setVideoCaptionEnabled(enabled, withCompletion: { result?($0) })
    }
    
    /// 获取相机字幕功能的可用状态
    ///
    /// - Parameter result: 回调
    class func getVideoCaption(result: ((Bool, Error?) -> ())?) {
        camera?.getVideoCaptionEnabled(completion: { result?($0, $1)})
    }
    
    /// 设置视频文件格式
    ///
    /// - Parameters:
    ///   - format: 支持的视频格式
    ///   - result: 回调
    class func setVideoFileFormat(_ format: AUTELCameraVideoFileFormat, with result: ResultHandler) {
        camera?.setVideoFileFormat(format, withCompletion: { result?($0) })
    }
    
    /// 获取当前相机的录像文件格式
    ///
    /// - Parameter result: 回调
    class func getVideoFileFormat(result: ((AUTELCameraVideoFileFormat, Error?) -> ())?) {
        camera?.getVideoFileFormat(completion: { result?($0, $1) })
    }
    
    /// 设置视频制式
    ///
    /// - Parameters:
    ///   - standard: 支持的视频制式
    ///   - result: 回调
    class func setVideoStandard(_ standard: AUTELCameraVideoStandard, with result: ResultHandler) {
        camera?.setVideoStandard(standard, withCompletion: { result?($0) })
    }
    
    /// 回去当前视频制式
    ///
    /// - Parameter result: 回调
    class func getVideoStandard(result: ((AUTELCameraVideoStandard, Error?) -> ())?) {
        camera?.getVideoStandard(completion: { result?($0, $1) })
    }
    
    /// 设置拍照图片尺寸
    ///
    /// - Parameters:
    ///   - size: 支持的图片尺寸
    ///   - result: 回调
    class func setPhotoSize(_ size: AUTELCameraPhotoAspectRatio, with result: ResultHandler) {
        camera?.setPhotoRatio(size, withCompletion: { result?($0) })
    }
    
    /// 获取图片尺寸
    ///
    /// - Parameter result: 回调
    class func getPhotoSize(result: ((AUTELCameraPhotoAspectRatio, Error?) -> ())?) {
        camera?.getPhotoRatio(completion: { result?($0, $1) })
    }
    
    /// 设置图片格式
    ///
    /// - Parameters:
    ///   - format: 支持的图片格式
    ///   - result: 回调
    class func setPhotoFileFormat(_ format: AUTELCameraPhotoFileFormat, with result: ResultHandler) {
        camera?.setPhotoFileFormat(format, withCompletion: { result?($0) })
    }
    
    /// 获取图片格式
    ///
    /// - Parameter result: 回调
    class func getPhotoFileFormat(result: ((AUTELCameraPhotoFileFormat, Error?) -> ())?) {
        camera?.getPhotoFileFormat(completion: { result?($0, $1) })
    }
    
    /// 设置连拍张数
    ///
    /// - Parameters:
    ///   - count: 支持的连拍张数
    ///   - result: 回调
    class func setBurstCount(_ count: AUTELCameraPhotoBurstCount, with result: ResultHandler) {
        camera?.setPhotoBurstCount(count, withCompletion: { result?($0) })
    }
    
    /// 设置burst模式下连拍张数
    ///
    /// - Parameters:
    ///   - count: 支持的连拍张数
    ///   - result: 回调
    class func setBurstWorkModeWithCount(_ count: AUTELCameraPhotoBurstCount, with result: ResultHandler) {
        camera?.setWorkModeToBurstWith(count, withCompletion: { result?($0) })
    }
    
    /// 获取连拍张数
    ///
    /// - Parameter result: 回调
    class func getBurstCount(result: ((AUTELCameraPhotoBurstCount, Error?) -> ())?) {
        camera?.getPhotoBurstCount(completion: { result?($0, $1) })
    }
    
    /// 设置aeb连拍张数
    ///
    /// - Parameters:
    ///   - count: 支持的连拍张数
    ///   - result: 回调
    class func setAebCount(_ count: AUTELCameraPhotoAEBCaptureCount, with result: ResultHandler) {
        camera?.setPhotoAEBCaptureCount(count, withCompletion: { result?($0) })
    }
    
    /// 设置aeb模式下连拍张数
    ///
    /// - Parameters:
    ///   - count: 支持的连拍张数
    ///   - result: 回调
    class func setAebWorkModeWithCount(_ count: AUTELCameraPhotoAEBCaptureCount, with result: ResultHandler) {
        camera?.setWorkModeToAEBWith(count, withCompletion: { result?($0) })
    }
    
    /// 获取aeb连拍张数
    ///
    /// - Parameter result: 回调
    class func getAebCount(result: ((AUTELCameraPhotoAEBCaptureCount, Error?) -> ())?) {
        camera?.getPhotoAEBCaptureCount(completion: { result?($0, $1) })
    }
    
    /// 设置定时拍间隔
    ///
    /// - Parameters:
    ///   - interval: 支持的拍摄间隔
    ///   - result: 回调
    class func setTimeLapseInterval(_ interval: AUTELCameraPhotoTimeLapseInterval, with result: ResultHandler) {
        camera?.setPhotoTimeLapseInterval(interval, withCompletion: { result?($0) })
    }
    
    /// 设置定时拍模式的定时拍间隔
    ///
    /// - Parameters:
    ///   - count: 支持的间隔
    ///   - result: 回调
    class func setTimeLapseWorkModeWithInterval(_ interval: AUTELCameraPhotoTimeLapseInterval, with result: ResultHandler) {
        camera?.setWorkModeToTimeLapseWith(interval, withCompletion: { result?($0) })
    }
    
    /// 获取定时拍间隔
    ///
    /// - Parameter result: 回调
    class func getTimeLapseInterval(result: ((AUTELCameraPhotoTimeLapseInterval, Error?) -> ())?) {
        camera?.getPhotoTimeLapseInterval(completion: { result?($0, $1) })
    }
    
    /// 设置曝光模式
    ///
    /// - Parameters:
    ///   - mode: 支持的曝光模式
    ///   - result: 回调
    class func setExposureMode(_ mode: AUTELCameraExposureMode, with result: ResultHandler) {
        camera?.setExposureMode(mode, withCompletion: {result?($0) })
    }
    
    /// 获取曝光模式
    ///
    /// - Parameter result: 回调
    class func getExposure(result: ((AUTELCameraExposureMode, Error?) -> ())?) {
        camera?.getExposureMode(completion: {result?($0, $1) })
    }
    
    
    /// 设置 AF
    ///
    /// - Parameters:
    ///   - mode: 对焦模式
    ///   - result: 回调
    class func setAF(_ mode: AUTELCameraLensFocusMode, with result: ResultHandler) {
        camera?.setLensFocusMode(mode, withCompletion: {result?($0) })
    }
    
    /// 获取 AF
    ///
    /// - Parameter result: 回调
    class func getAF(result: ((AUTELCameraLensFocusMode, Error?) -> ())?) {
        camera?.getLensFocusMode(completion: {result?($0, $1) })
    }
    
    /// 设置 AF
    ///
    /// - Parameters:
    ///   - mode: 对焦模式
    ///   - result: 回调
    class func setAF(_ mode: AUTELCameraAFLensFocusMode, row: Int, col: Int, with result: ResultHandler) {
        camera?.setAFLensFocusMode(mode, andLensFocusAreaRowIndex: row, andColIndex: col, withCompletion: {result?($0) })
    }
    
    /// 获取 AF
    ///
    /// - Parameter result: 回调
    class func getAF(result: ((AUTELCameraAFLensFocusMode, Int, Int, Error?) -> ())?) {
        camera?.getAFLensFocusModeAndLensFocusArea(completion: {result?($0, $1, $2, $3) })
    }
    
    /// 设置物距 setObjectDistance
    ///
    /// - Parameters:
    ///   - distance: 物距
    ///   - result: 回调
    class func setObjectDistance(_ distance: Int, with result: ResultHandler) {
        camera?.setObjectDistance(distance, withCompletion: {result?($0) })
    }
    
    /// getObjectDistance
    ///
    /// - Parameter result: 回调
    class func getObjectDistance(result: ((Int, Error?) -> ())?) {
        camera?.getObjectDistance(completion: {result?($0, $1) })
    }
    
    /// 设置MF辅助变焦
    ///
    /// - Parameters:
    ///   - enabled: Bool
    ///   - result: 回调
    class func setMFAssistFocus(_ enabled: Int, with result: ResultHandler) {
        camera?.setMFAssistFocusEnable(enabled, withCompletion: { result?($0) })
    }
   
    /// 获取MF辅助变焦
    ///
    /// - Parameter result: 回调
    class func getMFAssistFocus(result: ((Int, Error?) -> ())?) {
        camera?.getMFAssistFocusEnable(completion: { result?($0, $1) })
    }

    /// 设置 AF
    ///
    /// - Parameters:
    ///   - mode: 对焦模式
    ///   - result: 回调
    class func setMF(row: Int, col: Int, with result: ResultHandler) {
        camera?.setMFSportAreaRowIndex(row, andColIndex: col, withCompletion: {result?($0) })
    }

    /// 设置ISO
    ///
    /// - Parameters:
    ///   - iso: 支持的ISO设置
    ///   - result: 回调
    class func setISO(_ iso: AUTELCameraISO, with result: ResultHandler) {
        camera?.setISO(iso, withCompletion: { result?($0) })
    }
    
    /// 获取ISO
    ///
    /// - Parameter result: 回调
    class func getISO(result: ((AUTELCameraISO, Error?) -> ())?) {
        camera?.getISOWithCompletion({ result?($0, $1) })
    }
    
    /// 设置快门速度
    ///
    /// - Parameters:
    ///   - speed: 支持的快门速度
    ///   - result: 回调
    class func setShutterSpeed(_ speed: AUTELCameraShutterSpeed, with result: ResultHandler) {
        camera?.setShutterSpeed(speed, withCompletion: { result?($0) })
    }
    
    /// 获取快门速度
    ///
    /// - Parameter result: 回调
    class func getShutterSpeed(result: ((AUTELCameraShutterSpeed, Error?) -> ())?) {
        camera?.getShutterSpeed(completion: { result?($0, $1) })
    }


    /// 设置HDR
    ///
    /// - Parameters:
    ///   - enable: T/F
    ///   - result: 回调
    class func setPhotoRatio(_ ratio: AUTELCameraPhotoAspectRatio, _ enable: Bool, with result: ResultHandler) {
        camera?.setPhotoRatio(ratio, hdrEnable: enable, withCompletion: { result?($0) })
    }

    /// 获取HDR状态
    ///
    /// - Parameter result: 回调
    class func getHDREnable(result: ((Bool, Error?) -> ())?) {
        camera?.getPhotoRatioHDREnabled(completion: { result?($0, $1) })
    }

    /// 设置HDR 录像模式
    ///
    /// - Parameters:
    ///   - enable: T/F
    ///   - result: 回调
    class func setHDRForVideo(_ videoResolution: AUTELCameraVideoResolution, _ videoFrameRate: AUTELCameraVideoFrameRate, _ enable: Bool, with result: ResultHandler) {
        camera?.setVideoResolution(videoResolution, andFrameRate: videoFrameRate, hdrEnable: enable, withCompletion: { result?($0) })
    }

    /// 获取HDR状态 录像模式
    ///
    /// - Parameter result: 回调
    class func getHDREnableForVideo(result: ((Bool, Error?) -> ())?) {
        camera?.getVideoHDREnabled(completion: { result?($0, $1) })
    }


    /// 设置AE锁
    ///
    /// - Parameters:
    ///   - isLock: 锁住状态
    ///   - result: 回调
    class func setAELock(_ isLocked: Bool, with result: ResultHandler) {
        camera?.setAELock(isLocked, withCompletion: { result?($0) })
    }
    
    /// 获取AE锁
    ///
    /// - Parameter result: 回调
    class func getAELock(result: ((Bool, Error?) -> ())?) {
        camera?.getAELock(completion: { result?($0, $1) })
    }
    
    /// 设置点测光坐标
    ///
    /// - Parameters:
    ///   - row: 行数：[1,15]
    ///   - col: 列数：[1,23]
    ///   - result: 回调
    class func setSpotMeteringAreaAtRow(_ row: UInt8, andCol col: UInt8, with result: ResultHandler) {
        camera?.setSpotMeteringAreaRowIndex(row, andColIndex: col, withCompletion: { result?($0) })
    }
    
    /// 获取点测光位置
    ///
    /// - Parameter result: 回调
    class func getSpotMeteringArea(result: ((UInt8, UInt8, Error?) -> ())?) {
        camera?.getSpotMeteringAreaRowIndexAndColIndex(completion: { result?($0, $1, $2) })
    }

    /// 设置热成像位置
    ///
    /// - Parameters:
    ///   - x: -5 - 5
    ///   - y: -5 - 5
    ///   - result: 回调
    class func setIrPosition(_ x: Int, and y: Int, with result: ResultHandler) {
        camera?.setIrPositionDeltaX(x, deltaY: y, withCompletion: { result?($0) })
    }

    /// 获取热成像位置
    ///
    /// - Parameters:
    ///   - x: -5 - 5
    ///   - y: -5 - 5
    ///   - result: 回调
    class func getIrPosition(result: ((Int, Int, Error?) -> ())?) {
        camera?.getIrPosition(completion: { result?($0, $1, $2) })
    }

    /// 设置伪彩
    ///
    /// - Parameters:
    ///   - filter: 支持的数码滤波
    ///   - result: 回调
    class func setIrColor(_ irColor: AUTELCameraIrColorType, with result: ResultHandler) {
        camera?.setIrColor(irColor, withCompletion: { result?($0) })
    }

    /// 获取伪彩
    ///
    /// - Parameter result: 回调
    class func getIrColor(result: ((AUTELCameraIrColorType, Error?) -> ())?) {
        camera?.getIrColor(completion: { result?($0, $1) })
    }

    /// 设置FFC
    ///
    /// - Parameters:
    ///   - enabled: Bool
    ///   - result: 回调
    class func setFFC(with result: ResultHandler) {
        camera?.setIrFlushShutterWithCompletion(result)
    }
    
    /// 设置曝光补偿
    ///
    /// - Parameters:
    ///   - compension: 支持的曝光波长
    ///   - result: 回调
    class func setExposureCompensation(_ compension: AUTELCameraExposureCompensation, with result: ResultHandler) {
        camera?.setExposureCompensation(compension, withCompletion: { result?($0) })
    }
    
    /// 获取曝光补偿
    ///
    /// - Parameter result: 回调
    class func getExposureCompensation(result: ((AUTELCameraExposureCompensation, Error?) -> ())?) {
        camera?.getExposureCompensation(completion: { result?($0, $1) })
    }

    /// 设置白平衡
    ///
    /// - Parameters:
    ///   - whiteBalance: 支持的白平衡
    ///   - colorTemperature: 色温：[20,100]，实际色温值 colorTemperature (K) = colorTemperature * 100,例如色温值为50，表示真实色温值为 5000K。
    ///   - result: 回调
    class func setWhiteBalance(_ whiteBalance: AUTELCameraWhiteBalance, andColorTemperature colorTemperature: UInt8, with result: ResultHandler) {
        camera?.setWhiteBalance(whiteBalance, andColorTemperature: colorTemperature, withCompletion: { result?($0) })
    }
    
    /// 获取白平衡
    ///
    /// - Parameter result: 回调
    class func getWhiteBalance(result: ((AUTELCameraWhiteBalance, UInt8, Error?) -> ())?) {
        camera?.getWhiteBalanceAndColorTemperature(completion: { result?($0, $1, $2) })
    }

    /// 设置透雾
    ///
    /// - Parameters:
    ///   - switchStatus: 透雾开发
    ///   - strength: 透雾强度：0到10
    ///   - result: 回调
    class func setDehaze(_ switchStatus: AUTELCameraSwitchStatus, and strength: UInt8, with result: ResultHandler) {
        camera?.setDehazeSetting(switchStatus, withStrength: strength, withCompletion: { result?($0) })
    }

    /// 获取透雾
    ///
    /// - Parameter result: 回调
    class func getDehaze(result: ((AUTELCameraSwitchStatus, UInt8, Error?) -> ())?) {
        camera?.getDehazeSetting(completion: { result?($0, $1, $2) })
    }

    /// 设置ROI
    ///
    /// - Parameters:
    ///   - switchStatus: ROI开发
    ///   - strength: 透雾强度：0到10
    ///   - result: 回调
    class func setROI(_ switchStatus: AUTELCameraSwitchStatus, and strength: UInt8, with result: ResultHandler) {
        camera?.setImageRoiSetting(switchStatus, withStrength: strength, withCompletion: { result?($0) })
    }

    /// 获取ROI
    ///
    /// - Parameter result: 回调
    class func getROI(result: ((AUTELCameraSwitchStatus, UInt8, Error?) -> ())?) {
        camera?.getImageRoiSetting(completion: { result?($0, $1, $2) })
    }

    /// 设置ROI坐标
    ///
    /// - Parameters:
    ///   - row: 行数：[0,100]
    ///   - col: 列数：[0,100]
    ///   - result: 回调
    class func setROIAreaAtRow(_ row: UInt8, andCol col: UInt8, with result: ResultHandler) {
        camera?.setImageRoiAreaRowIndex(row, andColIndex: col, withCompletion: { result?($0) })
    }
    
    /// 设置抗闪烁
    ///
    /// - Parameters:
    ///   - antiFlicker: 支持的抗闪烁模式
    ///   - result: 回调
    class func setAntiFlicker(_ antiFlicker: AUTELCameraAntiFlicker, with result: ResultHandler) {
        camera?.setAntiFlicker(antiFlicker, withCompletion: { result?($0) })
    }
    
    /// 获取抗闪烁模式
    ///
    /// - Parameter result: 回调
    class func getAntiFlicker(result: ((AUTELCameraAntiFlicker, Error?) -> ())?) {
        camera?.getAntiFlicker(completion: { result?($0, $1) })
    }
    
    /// 设置照片风格，锐度、对比度、饱和度以及色度
    ///
    /// - Parameters:
    ///   - style: 支持的照片风格
    ///   - sharpness: 锐度
    ///   - contrast: 对比度
    ///   - saturation: 饱和度
    ///   - hue: 色度
    ///   - result: 回调
    class func setPhotoStyle(_ style: AUTELCameraPhotoStyle, sharpness: Int8, contrast: Int8, saturation: Int8, andHue hue: Int8, with result: ResultHandler) {
        camera?.setPhotoStyle(style, andSharpness: sharpness, andContrast: contrast, andSaturation: saturation, andHue: hue, withCompletion: { result?($0) })
    }
    
    /// 获取照片风格，锐度、对比度、饱和度以及色度
    ///
    /// - Parameter result: 回调
    class func getPhotoStyle(result: ((AUTELCameraPhotoStyle, Int8, Int8, Int8, Int8, Error?) -> ())?) {
        camera?.getPhotoStyleAndSharpnessAndContrastAndSaturationAndHue(completion: { result?($0, $1, $2, $3, $4, $5) })
    }
    
    /// 设置数码滤波
    ///
    /// - Parameters:
    ///   - filter: 支持的数码滤波
    ///   - result: 回调
    class func setDigitalFilter(_ filter: AUTELCameraDigitalFilter, with result: ResultHandler) {
        camera?.setDigitalFilter(filter, withCompletion: { result?($0) })
    }
    
    /// 获取数码滤波
    ///
    /// - Parameter result: 回调
    class func getDigitalFilter(result: ((AUTELCameraDigitalFilter, Error?) -> ())?) {
        camera?.getDigitalFilter(completion: { result?($0, $1) })
    }
    
    /// 设置光圈值
    ///
    /// - Parameters:
    ///   - aperture: 支持的光圈值
    ///   - result: 回调
    class func setAperture(_ aperture: AUTELCameraAperture, with result: ResultHandler) {
        camera?.setAperture(aperture, withCompletion: { result?($0) })
    }
    
    /// 获取光圈值
    ///
    /// - Parameter result: 回调
    class func getAperture(result: ((AUTELCameraAperture, Error?) -> ())?) {
        camera?.getApertureWithCompletion({ result?($0, $1) })
    }
    
    /// 获取系统时间
    ///
    /// - Parameter result: 回调
    class func getSystemDateAndTime(result: ((String?, TimeInterval, Error?) -> ())?) {
        camera?.getSystemDataAndTime(completion: { result?($0, $1, $2) })
    }
    
    /// 设置数码变焦倍数，内部已经做了支持性判断
    ///
    /// - Parameters:
    ///   - scale: 支持的变焦倍数
    ///   - result: 回调
    class func setDigitalZoomScale(_ scale: Float, with result: ResultHandler) {
        if let _ =  camera?.isDigitalZoomScaleSupported() {
            camera?.setDigitalZoomScale(scale, withCompletion: { result?($0) })
        }
    }
    
    /// 获取数码变焦的倍数，内部已经做了支持性判断
    ///
    /// - Parameter result: 回调
    class func getDigitalZoomScale(result: ((Float, Error?) -> ())?) {
        if let _ = camera?.isDigitalZoomScaleSupported() {
            camera?.getDigitalZoomScale(completion: { result?($0, $1) })
        }
    }
    
    /// 设置piv
    ///
    /// - Parameters:
    ///   - enabled: 是否自动模式
    ///   - interval: 自动模式的间隔
    ///   - result: 回调
    class func setPIV(_ enabled: Bool, interval: AUTELCameraPictureInVideoInterval, with result: ResultHandler) {
        camera?.setPictureInVideoAutoEnable(enabled, andCapture: interval, withCompletion: { result?($0) })
    }
    
    /// 获取PIV
    ///
    /// - Parameter result: 回调
    class func getPIV(result: ((Bool, AUTELCameraPictureInVideoInterval, Error?) -> ())?) {
        camera?.getPictureInVideo(completion: { result?($0, $1, $2) })
    }
    
    /// 格式化SD卡
    ///
    /// - Parameter result: 回调
    class func formatSDCard(result: ResultHandler) {
        camera?.formatSDCard(completion: { result?($0) })
    }
    
    /// 格式化EMMC
    ///
    /// - Parameter result: 回调
    class func formatEMMC(result: ResultHandler) {
        camera?.formatMMC(completion: { result?($0) })
    }
    
    /// 获取SD卡的相关信息
    ///
    /// - Parameter result: 回调
    class func getSDCardInfo(result: ((AUTELCameraSDCardState?, Error?) -> ())?) {
        camera?.getSDCardInfo(completion: { result?($0, $1) })
    }
    
    /// 获取EMMC的相关信息
    ///
    /// - Parameter result: 回调
    class func getEMMCInfo(result: ((AUTELCameraSDCardState?, Error?) -> ())?) {
//        camera?.getMMCInfo(completion: { result?($0, $1) })
    }
    
    /// 获取相机设备信息
    ///
    /// - Parameter result: 回调
    class func getCameraDeviceInfo(result: ((Dictionary<AnyHashable, Any>?, Error?) -> ())?) {
        camera?.getDeviceInfo(completion: { result?($0, $1) })
    }
    
    /// 获取直方图的可用状态
    ///
    /// - Parameter result: 回调
    class func getHistogram(result: ((Bool, Error?) -> ())?) {
        camera?.getHistogramEnabled(completion: { result?($0, $1) })
    }
    
    /// 设置直方图的状态
    ///
    /// - Parameters:
    ///   - enabled: Bool
    ///   - result: 回调
    class func setHistogram(_ enabled: Bool, with result: ResultHandler) {
        camera?.setHistogramEnabled(enabled, withCompletion: { result?($0) })
    }
    
    /// 获取视频文件压缩标准
    ///
    /// - Parameter result: 回调
    class func getVideoEncodingStandard(result:((AUTELCameraVideoFileCompressionStandard, Error?) ->())?) {
        camera?.getVideoFileCompressionStandard({ result?($0, $1) })
    }
    
    /// 设置视频文件压缩标准
    ///
    /// - Parameters:
    ///   - standard: AUTELCameraVideoFileCompressionStandard
    ///   - result: 回调
    class func setVideoEncodingStandard(_ standard: AUTELCameraVideoFileCompressionStandard, with result: ResultHandler) {
        camera?.setVideoFileCompressionStandard(standard, withCompletion: { result?($0) })
    }
    
    /// 获取储存位置
    ///
    /// - Parameter result: 回调
    class func getStore(result:((AUTELCameraStorageType, Error?) ->())?) {
        camera?.getStorageType(completion: { result?($0, $1) })
    }
    
    /// 设置储存位置
    ///
    /// - Parameters:
    ///   - standard: AUTELCameraVideoFileCompressionStandard
    ///   - result: 回调
    class func setStore(_ type: AUTELCameraStorageType, with result: ResultHandler) {
        camera?.setCameraStorageType(type, withCompletion: { result?($0) })
    }
    
    
    /// 获取云台锁定状态
    ///
    /// - Parameter result: 回调
    class func getGimbalLockState(result:((AUTELCameraGimbalLockState, Error?) ->())?) {
        camera?.getGimbalLockState(completion: { result?($0, $1) })
    }
    
    /// 设置云台锁定状态
    ///
    /// - Parameters:
    ///   - standard: AUTELCameraVideoFileCompressionStandard
    ///   - result: 回调
    class func setGimbalLockState(_ state: AUTELCameraGimbalLockState, with result: ResultHandler) {
        camera?.setGimbalLockState(state, withCompletion: { result?($0) })
    }
}
