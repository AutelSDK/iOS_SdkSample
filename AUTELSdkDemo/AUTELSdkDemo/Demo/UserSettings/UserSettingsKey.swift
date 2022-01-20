//
//  UserConfigKey.swift
//  testMode
//
//  Created by A17230 on 2017/10/23.
//  Copyright © 2017年 autel. All rights reserved.
//

import UIKit

//  定义键值
let KuserDict               = "userDict"                //  用户数据
let KconfigVersion          = "configVersion"           // 用户数据版本号
let aircraftVersion         = "aircraftVersion"         // 当前飞机版本  0: evo   1: model-C  详情见DroneType
let KisNopopup              = "isNopopup"               // 2.是否Popup
let KunitType               = "unitType"                // 3.公英制
let Kgrid                   = "grid"                    // 4.网格线
let KcenterPoint            = "centerPoint"             // 5.中心点
let KisAFFocusAssist        = "isAFFocusAssist"         // 5.1 AF
let KisMFFocusAssist        = "isMFFocusAssist"         // 5.2 MF
let KisHistogram            = "isHistogram"             // 6.柱状图
let KisOverExposureWarning  = "isOverExposureWarning"   // 7.超出警告
let KisSubtitelAssFile      = "isSubtitelAssFile"       // 8.字幕
let KisAutoDownloadPhoto    = "isAutoDownloadPhoto"   // 7.自动下载照片开关
let KantiFlicker            = "antiFlicker"             // 9.闪烁
let KmodelVersion           = "modelVersion"            // 10.Model
let KcameraVersion          = "cameraVersion"           // 11.相机版本
let KisShowFlightRoute      = "isShowFlightRoute"       // 12.是否显示飞行器航线
let KmapType                = "mapType"                 // 13.地图类型
let KisCalibrateMapCoordinates = "isCalibrateMapCoordinates" //14.是否打开纠偏开关
let KgridStyle              = "gridStyle"                    //15.实际的网格线
let KcenterPointStyle       = "centerPointStyle"            //15.实际的中心点
let KisTipsForNoviceTrackForbidden = "isTipsForNoviceTrackForbidden"  //16.追踪新手提示是否禁止
let KisTipsForTrackNew = "isTipsForTrackNew"    //追踪新新手提示
let KisImageTransmission = "isImageTransmission"           //17.图传设置开关
let KlowBatteryWarning      = "lowBatteryWarning"           // 低电报警
let KcriticalBatteryWarning = "criticalBatteryWarning"      // 严重低电报警
let kvideoEncodingStandard  = "videoEncodingStandard"    //视频压缩标准
let kstore                  = "store"                    //存储位置
let kstoreRaw                  = "storeRaw"                    //存储位置
let KaircraftCoordinateType = "aircraftCoordinateType"
let kisRadarHidden = "isRadarHidden"        //雷达图是否隐藏了
let ksmartFlightMode = "smartFlightMode"     //智能飞行模式，DeviceWorkMode
let KMaxFlightSpeed = "maxFlightSpeed"      //最大水平速度限制
let KtempUnit = "tempUnit"      //温度单位

let kshouldShowManualFlyGuide       = "shouldShowManualFlyGuide"        //手动飞行
let kshouldShowManualFlySafeCheckGuide  = "kshouldShowManualFlySafeCheckGuide"   //手动飞行2

let KshouldShowWaypointGuide        = "shouldShowWaypointGuide"         //是否需要显示waypoint的指引
let KshouldShowOrbitGuide           = "shouldShowOrbitGuide"            //是否需要显示orbit的指引
let KshouldShowTrackGuide           = "shouldShowTrackGuide"            //是否需要显示智能追踪的指引
let KshouldShowTrackTripodGuide     = "shouldShowTrackTripodGuide"            //是否需要显示三角架追踪的指引
let KshouldShowTrackParallelGuide   = "shouldShowTrackParallelGuide"            //是否需要显示平行追踪的指引

let KshouldShowViewpointGuide       = "shouldShowViewPointGuide"        //是否需要显示指点飞行的指引
let kshouldShowTripodGuide          = "shouldShowTripodGuide"           //是否显示三脚架的引导
let kshouldShowPhotographerGuide    = "shouldShowPhotographerGuide"     //是否显示摄影师模式的引导
let kshouldShowGestureRecognitionGuide  = "shouldShowGestureRecognitionGuide"    //手势识别

let KshouldShowDelayShotGuide           = "shouldShowDelayShotGuide"            //是否需要显示延时摄影的指引
let KshouldShowOrbitDelayShotGuide      = "shouldShowOrbitDelayShotGuide"       //是否需要显示环绕延时摄影的指引

//一键短片
let kshouldShowDegree360Guide       = "shouldShowDegree360Guide"        //360度拍摄引导
let kshouldShowEpicGuide            = "shouldShowEpicGuide"             //远景
let kshouldShowRiseGuide            = "shouldShowRiseGuide"             //上升
let kshouldShowFadeawayGuide        = "shouldShowFadeawayGuide"         //渐远拍摄
let kshouldShowIntoskyGuide         = "shouldShowIntoskyGuide"          //冲天追踪
let kshouldShowAroundGuide          = "shouldShowAroundGuide"           //环绕追踪
let kshouldShowSpiralGuide          = "shouldShowSpiralGuide"           //螺旋追踪
let kshouldShowParabolaGuide        = "shouldShowParabolaGuide"         //抛物线
let kshouldShowAsteroidGuide        = "shouldShowAsteroidGuide"         //小行星
let kshouldShowBoomerangGuide       = "shouldShowBoomerangGuide"        //回旋镖

//let kAvoidanceSystemEnabled         = "avoidanceSystemEnabled"          //避障系统是否打开
let kLudicrousMode                  = "ludicrousMode"                   //狂暴是否打开

let kvoiceControlEnabled            = "voiceControlEnabled"             //语音控制开关
let kSpeechShouldSpeek              = "speechShouldSpeek"               //语音播报

let kCustomRCButtonAFuncType              = "CustomRCButtonAFuncType"               //自定义按钮A 功能类型
let kCustomRCButtonBFuncType              = "CustomRCButtonBFuncType"               //自定义按钮B 功能类型

/// 雷达感知距离
let kRadarRangeFloat              = "radarRangeFloat"
/// 雷达报警声开关
let kRadarRingEnabled             = "radarRingEnabled"

let kshouldShowLivingBtn       = "shouldShowLivingBtn"        //直播

///直播设置项
let kLiveSettingsItemsKey      = "LiveSettingsItemsKey"

/// 返航点设置提示
let kShouldShowHomePointMeKey = "kShouldShowHomePointMeKey"
let kShouldShowHomePointAirplaneKey = "kShouldShowHomePointAirplaneKey"
let kShouldShowHomePointCustomKey = "kShouldShowHomePointCustomKey"
