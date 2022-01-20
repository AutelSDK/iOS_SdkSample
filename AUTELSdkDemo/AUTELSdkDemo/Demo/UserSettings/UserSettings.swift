//
//  UserSettings .swift
//  DS11WB
//
//  Created by A17230 on 2017/10/20.
//  Copyright © 2017年 autel. All rights reserved.
//

import UIKit
import RxSwift

enum SpeedUnit: String {
    case metricKmh = "Settings_General_Metric_KMS"
    case metricMs = "Settings_General_Metric_MS"
    case imperialMph = "Settings_General_Imperial_MPH"
}

enum UnitSystem: String {
    case metric = "m";
    case imperial = "ft"
}

enum AircraftCoordinateDisplayType: String {
    case none = "Settings_ShowAircraftCoordinate_None"
    case GPS = "Settings_ShowAircraftCoordinate_GPS"
    case UTM = "Settings_ShowAircraftCoordinate_UTM"
    case DMS = "Settings_ShowAircraftCoordinate_DMS"
}

@objcMembers
class UserSettings: NSObject {
    
    private let settings = "DefaultUserSettings"             // 图标配置文件
    
    static let shared: UserSettings = UserSettings()       // MARK:- 将类设计成单例
    
    let queue = DispatchQueue(label: "UserSettingQueue", attributes: .concurrent)

    private let unitSystemSubject = PublishSubject<UnitSystem>()
    
    /// subscribe unitSystemObservable to know unitSystem instantly.
    var unitSystemObservable: Observable<UnitSystem> {
        return unitSystemSubject.asObservable()
    }
    
    private let batteryWarningSubject = PublishSubject<[String: NSNumber]>()

    /// subscribe batteryWarningObservable to know battery warning percentage.
    var batteryWarningObservable: Observable<[String: NSNumber]> {
        return batteryWarningSubject.asObservable()
    }
    
    private let aircraftCoordinateSubject = PublishSubject<AircraftCoordinateDisplayType>()
    
    /// subscribe aircraftCoordinateObservable to know coordinate display type.
    var aircraftCoordinateObservable: Observable<AircraftCoordinateDisplayType> {
        return aircraftCoordinateSubject.asObservable()
    }
    
    private let calibrateMapCoordinatesSubject = PublishSubject<Bool>()
    
    /// subscribe calibrateMapCoordinatesObservable to know coordinate need to calibrate
    var calibrateCoordinateObservable:Observable<Bool> {
        return calibrateMapCoordinatesSubject.asObserver()
    }
    
    /// 读取默认的配置文件
    var configDict: [String : Any] {
        let filePath = Bundle.main.path(forResource: settings, ofType: "plist")
        return  NSDictionary(contentsOfFile:filePath!)! as! [String : Any]
    }
    
    /// 用户数据字典
    fileprivate (set) var userDict = [String : Any]()
    
    /// 当前飞机版本  0: evo   1: model-C  详情见DroneType
    var currentAircraftVersion: NSNumber {
        get{
            return queue.sync {
                return userDict[aircraftVersion] as! NSNumber
            }
        }
        set{
            queue.async(flags: .barrier) {
                self.userDict[aircraftVersion] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 2.不再显示
    var isNopopup: Bool {
        get{
            return queue.sync {
                return userDict[KisNopopup] as! Bool
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KisNopopup] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 3.英公制
    private var unitType: String {
        get{
            return queue.sync {
                return userDict[KunitType] as! String
            }
            
        }
        set{
            queue.async(flags: .barrier) {
                self.userDict[KunitType] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 3.1.英公制
    var speedUnit: SpeedUnit {
        get{
            return SpeedUnit(rawValue: unitType)!
        }
        
        set{
            self.unitType = newValue.rawValue
            self.unitSystemSubject.onNext(self.unitSystem)
        }
    }
    
    var unitSystem: UnitSystem {
        switch speedUnit {
        case .metricKmh, .metricMs:
            return .metric
        case .imperialMph:
            return .imperial
        }
    }
    //公英制bool类型
    var isMetric: Bool {
        get{
            switch speedUnit {
            case .metricKmh, .metricMs:
                return true
            case .imperialMph:
                return false
            }
        }
    }
    
    /// 4.网格线
    var grid: String {
        get{
            return queue.sync {
                return userDict[Kgrid] as! String
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[Kgrid] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 5.中心点
    var centerPoint: String {
        get{
            return queue.sync {
                return userDict[KcenterPoint] as! String
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KcenterPoint] = newValue
                self.saveUserDict()
            }
        }
    }

    /// 5.1 AF
    var isAFFocusAssist: Bool {
        get{
            return queue.sync {
                return userDict[KisAFFocusAssist] as! Bool
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KisAFFocusAssist] = newValue
                self.saveUserDict()
            }
        }
    }

    /// 5.2 MF
    var isMFFocusAssist: Bool {
        get{
            return queue.sync {
                return userDict[KisMFFocusAssist] as! Bool
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KisMFFocusAssist] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 6.柱状图
    var isHistogram: Bool {
        get{
            return queue.sync {
                return userDict[KisHistogram] as! Bool
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KisHistogram] = newValue
                self.saveUserDict()
            }
        }
    }
    /// 7.超出警告
    var isOverExposureWarning: Bool {
        get{
            return queue.sync {
                return userDict[KisOverExposureWarning] as! Bool
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KisOverExposureWarning] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 8.字幕
    var isSubtitelAssFile: Bool {
        get{
            return queue.sync {
                return userDict[KisSubtitelAssFile] as! Bool
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KisSubtitelAssFile] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 7.自动下载照片
    var isAutoDownloadPhoto: Bool {
        get{
            return queue.sync {
                return userDict[KisAutoDownloadPhoto] as! Bool
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KisAutoDownloadPhoto] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 9.闪烁
    var antiFlicker: String {
        get{
            return queue.sync {
                return userDict[KantiFlicker] as! String
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KantiFlicker] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 10.ModelVersion
    var modelVersion: String {
        get{
            return queue.sync {
                return userDict[KmodelVersion] as! String
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KmodelVersion] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 11.相机版本
    var cameraVersion: String {
        get{
            return queue.sync {
                return userDict[KcameraVersion] as! String
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KcameraVersion] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 12.是否打开纠偏开关
    var isCalibrateMapCoordinates:Bool {

        get {
//            let para = userDict[KisCalibrateMapCoordinates]
//            return para! as! Bool
            if NSTimeZone.local.description.contains("Asia/Chongqing") || NSTimeZone.local.description.contains("Asia/Harbin") || NSTimeZone.local.description.contains("Asia/Shanghai") || NSTimeZone.local.description.contains("Asia/Beijing") {
                return true
            }
            return false
        }
        set {

            queue.async(flags: .barrier) {
                self.userDict[KisCalibrateMapCoordinates] = newValue
                self.saveUserDict()
            }
            calibrateMapCoordinatesSubject.onNext(newValue)
        }
    }
    
    /// 13.是否显示航线
    var isShowFlightRoute:Bool {
        get{
            return queue.sync {
                return userDict[KisShowFlightRoute] as! Bool
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KisShowFlightRoute] = newValue
                self.saveUserDict()
            }
        }
    }

    /// 14.地图类型
    var mapType:NSNumber {
        get{
            return queue.sync {
                return userDict[KmapType] as! NSNumber
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KmapType] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 15.网格线
    var gridStyle: String {
        get{
            return queue.sync {
                return userDict[KgridStyle] as! String
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KgridStyle] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 15.网格线
    var centerPointStyle: String {
        get{
            return queue.sync {
                return userDict[KcenterPointStyle] as! String
            }
        }
        set{
            queue.async(flags: .barrier) {
                self.userDict[KcenterPointStyle] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 16.是否禁止显示追踪的新手提示
    var isTipsForNoviceTrackForbidden: Bool {
        get {
            return queue.sync {
                return userDict[KisTipsForNoviceTrackForbidden] as! Bool
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KisTipsForNoviceTrackForbidden] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 16.是否禁止显示追踪的新手提示
    var isTipsForTrackNew: Bool {
        get {
            return queue.sync {
                return userDict[KisTipsForTrackNew] as! Bool
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KisTipsForTrackNew] = newValue
                self.saveUserDict()
            }
        }
    }
    
    
    /// 17.图传设置开关
    var isImageTransmission: Bool {
        get {
            return queue.sync {
                return userDict[KisImageTransmission] as! Bool
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KisImageTransmission] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 18.低电量报警
    var lowBatteryWarning: NSNumber {
        get {
            return queue.sync {
                return userDict[KlowBatteryWarning] as! NSNumber
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KlowBatteryWarning] = newValue
                self.saveUserDict()
            }
            batteryWarningSubject.onNext(batteryWarning)
        }
    }
    
    // 19.严重低电量报警
    var criticalBatteryWarning: NSNumber {
        get {
            return queue.sync {
                return userDict[KcriticalBatteryWarning] as! NSNumber
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KcriticalBatteryWarning] = newValue
                self.saveUserDict()
            }
            batteryWarningSubject.onNext(batteryWarning)
        }
    }
    
    /// 9.闪烁
    var videoEncodingStandard: String {
        get{
            return queue.sync {
                return userDict[kvideoEncodingStandard] as! String
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kvideoEncodingStandard] = newValue
                self.saveUserDict()
            }
        }
    }


    /// 存储位置
    var store: String {
        get{
            return queue.sync {
                return userDict[kstore] as! String
            }
        }
        set{
            queue.async(flags: .barrier) {
                self.userDict[kstore] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 温度单位
    var tempUint: String {
        get{
            return queue.sync {
                return userDict[KtempUnit] as! String
            }
        }
        set{
            queue.async(flags: .barrier) {
                self.userDict[KtempUnit] = newValue
                self.saveUserDict()
            }
        }
    }

    /// 存储位置枚举raw
    var storeRaw: Int {
        get{
            return queue.sync {
                return userDict[kstoreRaw] as! Int
            }
        }
        set{
            queue.async(flags: .barrier) {
                self.userDict[kstoreRaw] = newValue
                self.saveUserDict()
            }
        }
    }


    private var batteryWarning: [String: NSNumber] {
        return [KlowBatteryWarning: lowBatteryWarning,
                KcriticalBatteryWarning: criticalBatteryWarning]
    }
    
    // 20.飞行器位置显示类型
    var aircraftCoordinateType: AircraftCoordinateDisplayType {
        get {
//            objc_sync_enter(self)//????
//            let para = userDict[KaircraftCoordinateType]
//            objc_sync_exit(self)
//            if let coor = para as? String, let coordinate = AircraftCoordinateDisplayType(rawValue: coor) {
//                return coordinate
//            } else {
//                return AircraftCoordinateDisplayType.none
//            }
            
            return queue.sync {
                let para = userDict[KaircraftCoordinateType]
                if let coor = para as? String, let coordinate = AircraftCoordinateDisplayType(rawValue: coor) {
                    return coordinate
                } else {
                    return AircraftCoordinateDisplayType.none
                }
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KaircraftCoordinateType] = newValue.rawValue
                self.saveUserDict()
            }
            self.aircraftCoordinateSubject.onNext(newValue)
        }
    }

//    var maxFlightSpeed: CGFloat {
//        get{
//            return queue.sync {
//                return userDict[KMaxFlightSpeed] as? CGFloat ?? 5.0
//            }
//        }
//        set{
//            queue.async(flags: .barrier) {
//                self.userDict[KMaxFlightSpeed] = newValue
//                self.saveUserDict()
//            }
//        }
//    }
    
    var radarRingEnabled: Bool {
        get{
            return queue.sync {
                let para = userDict[kRadarRingEnabled]
                return (para as? Bool) ?? true//默认打开
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kRadarRingEnabled] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 语音助手
    var voiceControlEnabled: Bool {
        get{
            return queue.sync {
                let para = userDict[kvoiceControlEnabled]
                return (para as? Bool) ?? false//默认关闭
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kvoiceControlEnabled] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 语音播报
    var speechShouldSpeek: Bool {
          get{
              return queue.sync {
                  let para = userDict[kSpeechShouldSpeek]
                  return (para as? Bool) ?? true
              }
          }
          
          set{
              queue.async(flags: .barrier) {
                  self.userDict[kSpeechShouldSpeek] = newValue
                  self.saveUserDict()
              }
          }
      }
    
    var isRadarHidden: Bool {
        get {
            return queue.sync {
                return userDict[kisRadarHidden] as! Bool
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kisRadarHidden] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 自定义按钮A 功能类型
    var customRCButtonAFuncType:NSNumber {
        get{
            return queue.sync {
                let param = userDict[kCustomRCButtonAFuncType]
                if let para = param as? NSNumber {
                    return para
                }
                return NSNumber.init(value: 0)
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kCustomRCButtonAFuncType] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 自定义按钮B功能类型
    var customRCButtonBFuncType:NSNumber {
        get{
            return queue.sync {
                let param = userDict[kCustomRCButtonBFuncType]
                if let para = param as? NSNumber {
                    return para
                }
                return NSNumber.init(value: 0)
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kCustomRCButtonBFuncType] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// 雷达感知距离
    var radarRange:Float {
        get{
            return queue.sync {
                let param = userDict[kRadarRangeFloat]
                if let para = param as? NSNumber {
                    return para.floatValue
                }
                return 10
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kRadarRangeFloat] = NSNumber(value: newValue)
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowWaypointGuide: Bool {
        get{
            return queue.sync {
                let para = userDict[KshouldShowWaypointGuide]
                return (para as? Bool) ?? true
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[KshouldShowWaypointGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowManualFlyGuide: Bool {
        get{
            return queue.sync {
                let para = userDict[kshouldShowManualFlyGuide]
                return (para as? Bool) ?? true
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowManualFlyGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowManualFlySafeCheckGuide: Bool {
        get{
            return queue.sync {
                let para = userDict[kshouldShowManualFlySafeCheckGuide]
                return (para as? Bool) ?? true
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowManualFlySafeCheckGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowGestureRecognitionGuide: Bool {
        get{
            return queue.sync {
                let para = userDict[kshouldShowGestureRecognitionGuide]
                return (para as? Bool) ?? true
            }
        }
        
        set{
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowGestureRecognitionGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowOrbitGuide: Bool {
        get {
            return queue.sync {
                return (userDict[KshouldShowOrbitGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KshouldShowOrbitGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowTrackGuide: Bool {
        get {
            return queue.sync {
                return (userDict[KshouldShowTrackGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KshouldShowTrackGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
//    是否需要显示三角架追踪的指引
    var shouldShowTrackTripodGuide: Bool {
           get {
               return queue.sync {
                   return (userDict[KshouldShowTrackTripodGuide] as? Bool) ?? true
               }
           }
           set {
               queue.async(flags: .barrier) {
                   self.userDict[KshouldShowTrackTripodGuide] = newValue
                   self.saveUserDict()
               }
           }
       }
    
    //是否需要显示平行追踪的指引
    var shouldShowTrackParallelGuide: Bool {
             get {
                 return queue.sync {
                     return (userDict[KshouldShowTrackParallelGuide] as? Bool) ?? true
                 }
             }
             set {
                 queue.async(flags: .barrier) {
                     self.userDict[KshouldShowTrackParallelGuide] = newValue
                     self.saveUserDict()
                 }
             }
         }
    
    var shouldShowViewpointGuide: Bool {
        get {
            return queue.sync {
                return (userDict[KshouldShowViewpointGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KshouldShowViewpointGuide] = newValue
                self.saveUserDict()
            }
        }
    }

    var shouldShowTripodGuide: Bool {
        get {
            return false
        }
    }

    var shouldShowPhotographerGuide: Bool {
        get {
            return false
        }
    }
    
     //延时摄影
    var shouldShowDelayShotGuide: Bool {
        get {
            return queue.sync {
                return (userDict[KshouldShowDelayShotGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KshouldShowDelayShotGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowOrbitDelayShotGuide: Bool {
        get {
            return queue.sync {
                return (userDict[KshouldShowOrbitDelayShotGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[KshouldShowOrbitDelayShotGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    //一键短片
    var shouldShowDegree360Guide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowDegree360Guide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowDegree360Guide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowEpicGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowEpicGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowEpicGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowRiseGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowRiseGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowRiseGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowFadeawayGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowFadeawayGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowFadeawayGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowIntoskyGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowIntoskyGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowIntoskyGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowAroundGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowAroundGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowAroundGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowSpiralGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowSpiralGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowSpiralGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowParabolaGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowParabolaGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowParabolaGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowAsteroidGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowAsteroidGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowAsteroidGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowBoomerangGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowBoomerangGuide] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowBoomerangGuide] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowLivingBtn: Bool {
        get {
            return queue.sync {
                return (userDict[kshouldShowLivingBtn] as? Bool) ?? false
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kshouldShowLivingBtn] = newValue
                self.saveUserDict()
            }
        }
    }
    
    ///直播设置项
    var liveSettingsItems: [String: Any] {
        get {
            return queue.sync {
                return (userDict[kLiveSettingsItemsKey] as? [String: Any]) ?? [:]
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kLiveSettingsItemsKey] = newValue
                self.saveUserDict()
            }
        }
    }
    
    /// home点设置
    var shouldShowHomePointMeGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kShouldShowHomePointMeKey] as? Bool) ?? false
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kShouldShowHomePointMeKey] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowHomePointAirplaneGuide: Bool {
        get {
            return queue.sync {
                return (userDict[kShouldShowHomePointAirplaneKey] as? Bool) ?? false
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kShouldShowHomePointAirplaneKey] = newValue
                self.saveUserDict()
            }
        }
    }
    
    var shouldShowHomePointCustomGuide: Bool {
        get {
            return queue.sync {
                /** 默认为true */
                return (userDict[kShouldShowHomePointCustomKey] as? Bool) ?? true
            }
        }
        set {
            queue.async(flags: .barrier) {
                self.userDict[kShouldShowHomePointCustomKey] = newValue
                self.saveUserDict()
            }
        }
    }
    
//    var avoidanceSystemEnabled:Bool {
//        get {
//            return queue.sync {
//                return (userDict[kAvoidanceSystemEnabled] as? Bool) ?? true
//            }
//        }
//        set {
//            queue.async(flags: .barrier) {
//                self.userDict[kAvoidanceSystemEnabled] = newValue
//                self.saveUserDict()
//            }
//        }
//    }
    
    private override init() {
        super.init()
        let dict = UserDefaults.standard.dictionary(forKey: KuserDict)
        if dict != nil && dict?.count != 0 {
            // 拿出UserDefault中的字典进行取值
//            print(dict)
            for (key , value) in dict!
            {
            userDict[key] = value
            }
        }else{
            // 用户第一次安装
            for (key , value) in configDict
            {
                userDict[key] = value
                print("final add = \(key) - \(value)")
            }
            saveUserDict()
        }
        /*
        let userVersion = userDict.object(forKey: KconfigVersion)
        let proVersion = configDict.object(forKey: KconfigVersion) as! NSNumber
        
        if userVersion != nil {
            let tempVersion = userVersion as! NSNumber
            if tempVersion == proVersion{
                print("Version SAME, Return Back")
                return
            }else{
                userDict.setValue(proVersion, forKey: KconfigVersion) // Update NEW Version
                saveUserDict()
            }
        }
         */
        // 取出当前用户所有的KEY值
        let allKeys = userDict.keys
        for (key, value) in configDict
        {
            var i : Int = 0
            for userKey in allKeys
            {
                //  如果用户已经有值 直接进入下一个KEY比较
                if String(describing: key) == String(describing: userKey){
                    break
                }
                if i == (allKeys.count - 1){
                    // 遍历到最后一个KEY依然没有值，添加默认值
                    userDict[key] = value
                    saveUserDict()
//                    print("last add = \(key) - \(value)")
                    break
                }
                i = i + 1
            }
        }
    }
    
    //看不懂的方法 。。。。读代码效果和 resetAllDefConfig 一样 后半部分的代码是垃圾无效代码，不会改变配置
    func reset() {
        // 复位 用户第一次安装
        for (key , value) in configDict
        {
            userDict[key] = value
            print("final add = \(key) - \(value)")
        }
        saveUserDict()
            /*
            let userVersion = userDict.object(forKey: KconfigVersion)
            let proVersion = configDict.object(forKey: KconfigVersion) as! NSNumber

            if userVersion != nil {
                let tempVersion = userVersion as! NSNumber
                if tempVersion == proVersion{
                    print("Version SAME, Return Back")
                    return
                }else{
                    userDict.setValue(proVersion, forKey: KconfigVersion) // Update NEW Version
                    saveUserDict()
                }
            }
             */
            // 取出当前用户所有的KEY值
            let allKeys = userDict.keys
            for (key, value) in configDict
            {
                var i : Int = 0
                for userKey in allKeys
                {
                    //  如果用户已经有值 直接进入下一个KEY比较
                    if String(describing: key) == String(describing: userKey){
                        break
                    }
                    if i == (allKeys.count - 1){
                        // 遍历到最后一个KEY依然没有值，添加默认值
                        userDict[key] = value
                        saveUserDict()
    //                    print("last add = \(key) - \(value)")
                        break
                    }
                    i = i + 1
                }
            }
    }
    
    private func resetUserConfig(keys:[String]) {
        for key  in keys {
            if let def = configDict[key] { //有默认值回默认值
                userDict[key] = def
            } else {
                userDict.removeValue(forKey: key) // 无则删除。nil即为默认或者 get 方法有默认值
            }
        }
        saveUserDict()
    }
    
    // 复位 用户第一次安装
    private func resetAllUserConfig() {
          userDict.removeAll()
          resetAllDefConfig()
    }
    
    private func resetAllDefConfig() {
          for (key , value) in configDict {
              userDict[key] = value
          }
          saveUserDict()
    }
    
    private func joinDefConfig() {
         // 复位 用户第一次安装
          for (key , value) in configDict {
            guard let _ = userDict[key] else {
                continue
            }
            userDict[key] = value
        }
    }
    
    /// UserDefault 归档
    private func saveUserDict() {
        UserDefaults.standard.set(userDict, forKey: KuserDict)
        UserDefaults.standard.synchronize()
//      print("userDict = \(userDict)")
    }

    func fitModelC() {
        if Int(truncating: UserSettings.shared.currentAircraftVersion) != DroneType.modelB.rawValue {
            if UserSettings.shared.antiFlicker == "Auto" {
                UserSettings.shared.antiFlicker = "Turn Off"
            }
        }
    }

    func resetAboutCamera() {
        UserSettings.shared.grid = "Img_camera_setting_none_0"
        UserSettings.shared.centerPoint = "Img_camera_setting_none_0"

        UserSettings.shared.isOverExposureWarning = false
        UserSettings.shared.isSubtitelAssFile = false
        UserSettings.shared.isAutoDownloadPhoto = false
    }
    
    

    
    //云台微调标志位
    var adjustGimbalRoll = false
    
    //退出移除监听标志位
    var needToReomveFromRouter = false
    
    var delayShotInterval:Float = 2
    
    ///是否是SD卡存储
    var isSDCardPlayback: Bool {
        var ret = true
        if Int(truncating: currentAircraftVersion) == DroneType.modelC.rawValue {
            if storeRaw != Int(AUTELCameraStorageType.sdCard.rawValue) {
                ret = false
            }
        }
        return ret
    }

}
