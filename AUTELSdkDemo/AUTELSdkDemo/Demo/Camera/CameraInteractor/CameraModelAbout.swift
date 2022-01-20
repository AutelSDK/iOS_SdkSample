//
//  CameraModelAbout.swift
//  AutelGen2
//
//  Created by Devin on 2017/10/27.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

/// 相机可以 使用 ParametersAction 设置、获取 的参数
enum CameraMenuBranch: String {
    case photoFormat = "photo format"
    case videoFormat = "video format"
    /// 拍照分辨率
    case photoSize = "size"
    case workMode = "mode"
    /// 曝光模式
    case exposureMode = "exposure"
    /// 感光度
    case iso = "iso"
    /// 曝光补偿
    case exposureCompensation = "ev"

    case digitalFilter = "color"
    case videoStandard = "standard"
    /// 视频分辨率
    case videoResolution = "resolution"
    /// 视频帧率
    case frameRate = "frame rate"
    /// 数码变焦 af & ae
    case digitalZoom = "digital zoom"
    case piv = "piv"
    /// 快门速度
    case shutterSpeed = "shutter"

    case hdr = "hdr"
    case mfnr = "mfnr"
    case irColor = "ir color"  // 对应 "menu": "ir color",
    case overlapOffset
    case display
    /// 拍照模式- 连拍
    case photoBurst = "burst"
    /// 拍照模式- AEB（自动包围曝光）
    case photoAeb = "aeb"
    /// 拍照间隔
    case photoTiming = "timelapse"
    
    //------ 白平衡
    /// 白平衡
    case whiteBalance = "wb"
    /// 白平衡-自定义
    case wbCustom = "wb custom"
    //------
    
    case encodingFormat

    case dehaze
    case dehazeValue
    case roiValue
    case roi
    
    /// 对焦模式
    case af
    /// aeaf 锁
    case aeLock
    /// 点测光行数[1...15]
    case spotRow
    /// 点测光列数[1...23]   xt701 [1...17]
    case spotCol
    /// 点测光
    case spotCoordinate
    /// 光圈
    case aperture
    
    //----- 拍照风格
    /// 拍照风格
    case style
    /// 拍照风格-自定义 （锐度-饱和度-对比度-色度）值 不应该记录感觉
    case styleCustom = "style custom"
    //下面是个的值需要将Int8转换成UInt8后存储，方式: v' = v - Int8.min，使用时需要还原成Int8
    /// 拍照风格-自定义-锐度 (拍照风格-自定义 定义的自定义风格成员 在 style == styleCustom 时才有效 其实名称应该叫 styleCustomSharpness 晕各种名称太无语了)
    case sharpness
    /// 拍照风格-自定义-对比度 (拍照风格-自定义)
    case contrast
    /// 拍照风格-自定义-饱和度  (拍照风格-自定义)
    case saturation
    /// 拍照风格-自定义-色度  (拍照风格-自定义)
    case hue
    //----- 拍照风格
    
    //相机设置
    case grid
    case centerPoint
    case antiFlicker
    case captionEnable
    case histogram
    case afFocusAssist
    case mfFocusAssist
    case store
    case gimbalLockState//云台锁定状态
    
    //延时摄影拍照格式 特殊的菜单，云台角度
    case gimbalAngle = "gimbal"
    
    /// 延时摄影拍照格式
    case photoFormatDelayShot = "phofor delayshot"
    
    case unknown
}


//MARK: 其他一些控件或h功能 需要的扩展 临时放置

//MARK: MCMessageEvent


//MARK: - 图传尺寸比例定义  临时放 。。。

//AutelRXShared.shared.renderSize.
enum CameraVideoRenderRatio {
    case ratio16_9
    case ratio4_3
}

