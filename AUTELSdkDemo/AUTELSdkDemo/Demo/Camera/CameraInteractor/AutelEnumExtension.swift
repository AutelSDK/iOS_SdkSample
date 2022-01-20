//
//  AutelEnumExtension.swift
//  AutelGen2
//
//  Created by Devin on 2017/10/30.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK


extension AUTELCameraPhotoAspectRatio {
    func displayName() -> String? {
        switch self {
        case .ratio640_512:
            return "640X512(4:3)"
        case .ratio4000_3000:
            return "4000X3000(4:3)"
        case .ratio4000_2250:
            return "4000X2250(16:9)"
        case .ratio1280_720:
            return "1280x720(16:9)"
        case .ratio1920_1080:
            return "1920x1080(16:9)"
        case .ratio2720_1528:
            return "2720x1528(16:9)"
        case .ratio3840_2160:
            return "3840X2160(16:9)"
        case .ratio5472_3076:
            return "5472x3076(16:9)"
        case .ratio5472_3648:
            return "5472x3648(3:2)"
        case .ratio5760_3240:
            return "5760x3240(3:2)"
        case .ratio8000_6000:
            return "8000x6000(4:3)"
        case .ratio7680_4320:
            return "7680x4320(16:9)"
        default:
            return nil
        }
    }
    
    static func initFromDisplayName(displayName: String) -> AUTELCameraPhotoAspectRatio {
        switch displayName {
        case "640X512(4:3)":
            return .ratio640_512
        case "4000X3000(4:3)":
            return .ratio4000_3000
        case "4000X2250(16:9)":
            return .ratio4000_2250
        case "1280x720(16:9)":
            return .ratio1280_720
        case "1920x1080(16:9)":
            return .ratio1920_1080
        case "2720x1528(16:9)":
            return .ratio2720_1528
            
            
        case "3840X2160(16:9)":
            return .ratio3840_2160
        case "5472x3076(16:9)":
            return .ratio5472_3076
        case "5472x3648(3:2)":
            return .ratio5472_3648
        case "5760x3240(3:2)":
            return .ratio5760_3240
        case "8000x6000(4:3)":
            return .ratio8000_6000
        case "7680x4320(16:9)":
            return .ratio7680_4320
        default:
            return .ratioUnknown
        }
    }
}

extension AUTELCameraPhotoBurstCount {
    func displayName() -> String? {
        switch self {
        case .count3:
            return "3"
        case .count5:
            return "5"
        case .count7:
            return "7"
        case .count10:
            return "10"
        case .count14:
            return "14"
        default:
            return nil
        }
    }
}

extension AUTELCameraPhotoAEBCaptureCount {
    func displayName() -> String? {
        switch self {
        case .count3:
            return "3"
        case .count5:
            return "5"
        default:
            return nil
        }
    }
}

extension AUTELCameraPhotoTimeLapseInterval {
    func displayName() -> String? {
        switch self {
        case .interval2:
            return "2s"
        case .interval5:
            return "5s"
        case .interval7:
            return "7s"
        case .interval10:
            return "10s"
        case .interval20:
            return "20s"
        case .interval30:
            return "30s"
        case .interval60:
            return "60s"
        default:
            return nil
        }
    }
}

extension AUTELCameraPhotoFileFormat {
    func displayName() -> String? {
        switch self {
        case .JPG:
            return "JPG"
        case .DNG:
            return "RAW"
        case .jpgAndDNG:
            return " RAW+JPG"
        default:
            return nil
        }
    }
}

extension AUTELCameraDelayShotPhotoFormat {
    func displayName() -> String? {
        switch self {
        case .none:
            return "不保存"
        case .JPG:
            return "JPG"
        case .DNG:
            return "RAW"
        default:
            return nil
        }
    }
}

extension AUTELCameraExposureMode {
    func displayName() -> String? {
        switch self {
        case .auto:
            return "A"
        case .manual:
            return "M"
        case .shutter:
            return "S"
        case .aperture:
            return "aperture_priority"
        default:
            return nil
        }
    }
}

extension AUTELCameraISO {
    func displayName() -> String? {
        switch self {
        case .ISO100:
            return "100"
        case .ISO200:
            return "200"
        case .ISO400:
            return "400"
        case .ISO800:
            return "800"
        case .ISO1600:
            return "1600"
        case .ISO3200:
            return "3200"
        case .ISO6400:
            return "6400"
        case .ISO12800:
            return "12800"
        default:
            return nil
        }
    }
}

extension AUTELCameraAperture {
    func displayName() -> String? {
        switch self {
        case .f1p8:
            return "F1.8"
        case .f2p0:
            return "F2.0"
        case .f2p2:
            return "F2.2"
        case .f2p5:
            return "F2.5"
        case .f2p8:
            return "F2.8"
        case .f3p2:
            return "F3.2"
        case .f3p5:
            return "F3.5"
        case .f4p0:
            return "F4.0"
        case .f4p5:
            return "F4.5"
        case .f5p0:
            return "F5.0"
        case .f5p6:
            return "F5.6"
        case .f6p3:
            return "F6.3"
        case .f7p1:
            return "F7.1"
        case .f8p0:
            return "F8.0"
        case .f9p0:
            return "F9.0"
        case .F10:
            return "F10"
        case .F11:
            return "F11"
        default:
            return nil
        }
    }
}

extension AUTELCameraExposureCompensation {
    func displayName() -> String? {
        switch self {
        case .N30:
            return "-3.0"
        case .N27:
            return "-2.7"
        case .N23:
            return "-2.3"
        case .N20:
            return "-2.0"
        case .N17:
            return "-1.7"
        case .N13:
            return "-1.3"
        case .N10:
            return "-1.0"
        case .N07:
            return "-0.7"
        case .N03:
            return "-0.3"
        case .N00:
            return "± 0"
        case .P03:
            return "+0.3"
        case .P07:
            return "+0.7"
        case .P10:
            return "+1.0"
        case .P13:
            return "+1.3"
        case .P17:
            return "+1.7"
        case .P20:
            return "+2.0"
        case .P23:
            return "+2.3"
        case .P27:
            return "+2.7"
        case .P30:
            return "+3.0"
        default:
            return nil
        }
    }
}

extension AUTELCameraWhiteBalance {
    func displayName() -> String? {
        switch self {
        case .auto:
            return "Auto"
        case .cloudy:
            return "Cloudy"
        case .sunny:
            return "Sunny"
        case .fluorescent:
            return "Fluorescent"
        case .incandescent:
            return "Incandescent"
        case .custom:
            return "Custom"
        default:
            return nil
        }
    }
    
    func isCustom() -> Bool {
        return self == .custom
    }
}

extension AUTELCameraPhotoStyle {
    func displayName() -> String? {
        switch self {
        case .standard:
            return "Std"//"Std. ±0 ±0 ±0"
        case .landScape:
            return "Land"//"Land. +1 +1 ±0"
        case .soft:
            return "Soft"//"Soft. -1 ±0 ±0"
        case .custom:
            return "Custom"
        default:
            return nil
        }
    }
    
    func isCustom() -> Bool {
        return self == .custom
    }
}

extension AUTELCameraDigitalFilter {
    func displayName() -> String? {
        switch self {
        case .none:
            return "Normal"
        case .log:
            return "Log"
        case .vivid:
            return "Vivid"
        case .blackAndWhite:
            return "B & W"
        case .art:
            return "Art"
        case .film:
            return "Film"
        case .beach:
            return "Beach"
        case .dream:
            return "Dream"
        case .classic:
            return "Classic"
        case .nostalgic:
            return "Nostalgic"
        default:
            return nil
        }
    }
}

extension AUTELCameraIrColorType {
    func displayName() -> String? {
        switch self {
        case .whiteHot:
            return "whitehot"
        case .blackHot:
            return "blackhot"
        case .rainBow:
            return "rainbow"
//        case .raingHC:
//            return "rainghc"
        case .ironBow:
            return "ironbow"
        case .lava:
            return "lava"
        case .arctic:
            return "arctic"
        case .glowBow:
            return "glowbow"
        case .gradedFire:
            return "gradedfire"
        case .hotTest:
            return "hottest"
        default:
            return nil
        }
    }
}

extension AUTELCameraVideoStandard {
    func displayName() -> String? {
        switch self {
        case .PAL:
            return "PAL"
        case .NTSC:
            return "NTSC"
        default:
            return nil
        }
    }
}

extension AUTELCameraLensFocusMode {
    func displayName() -> String? {
        switch self {
        case .auto:
            return "af"
        case .manual:
            return "mf"
        default:
            return nil
        }
    }
}

extension AUTELCameraVideoFileFormat {
    func displayName() -> String? {
        switch self {
        case .MP4:
            return "MP4"
        case .MOV:
            return "MOV"
        default:
            return nil
        }
    }
}

extension AUTELCameraVideoResolution {
    func displayName() -> String? {
        switch self {
        case .resolution640x512:
            return "640x512"
        case .resolution1280x720:
            return "720P(1280X720)"
        case .resolution1920x1080:
            return "1080P(1920X1080)"
        case .resolution2704x1520:
            return "2.7K(2704x1520)"
        case .resolution2720x1528:
            return "2.7K(2720x1528)"
        case .resolution2720x1530:
            return "2.7K(2720x1530)"
        case .resolution3840x2160:
            return "4K(3840x2160)"
        case .resolution4096x2160:
            return "4K+(4096x2160)"
        case .resolution4800x2700:
            return "5K(4800x2700)"
        case .resolution5472x3076:
            return "6K(5472x3076)"
        case .resolution5760x3240:
            return "6K(5760x3240)"
        case .resolution7680x4320:
            return "8K(7680x4320)"
        default:
            return nil
        }
    }
}

extension AUTELCameraVideoFrameRate {
    func displayName() -> String? {
        switch self {
        case .rate9fps:
            return "9FPS"
        case .rate24fps:
            return "24FPS"
        case .rate25fps:
            return "25FPS"
        case .rate30fps:
            return "30FPS"
        case .rate48fps:
            return "48FPS"
        case .rate50fps:
            return "50FPS"
        case .rate60fps:
            return "60FPS"
        case .rate120fps:
            return "120FPS"
        case .rate240fps:
            return "240FPS"
        default:
            return nil
        }
    }
}

extension AUTELCameraWorkMode {
    
    enum ModeCategory: String {
        case photo
        case video
        case unknown
    }
    
    func displayName() -> String? {
        switch self {
        case .captureAEB:
            return "Aeb"
        case .captureBurst:
            return "Burst"
        case .captureSingle:
            return "Single shot"
        case .captureInterval:
            return "Timelapse"
        case .recordVideo:
            return "Record"
        case .captureMFNR:
            return "Hyperlight"
        default:
            return nil
        }
    }
    
    static func initFromDisplayName(displayName: String) -> AUTELCameraWorkMode {
        switch displayName {
        case "Aeb":
            return .captureAEB
        case "Burst":
            return .captureBurst
        case "Single shot":
            return .captureSingle
        case "Timelapse":
            return .captureInterval
        case "Record":
            return .recordVideo
        case "Hyperlight":
            return .captureMFNR
        default:
            return .unknown
        }
    }
    
    /// 所属类别
    var category: ModeCategory {
        get {
            switch self {
            case .captureAEB, .captureBurst, .captureSingle, .captureInterval, .capturePanorama, .captureMovingTimeLapse, .captureHDR, .captureMFNR:
                return .photo
            case .recordVideo, .recordVideoLooping, .recordVideoSlowMotion:
                return .video
            default:
                return .unknown
            }
        }
    }
    
    var branch: CameraMenuBranch {
        get {
            switch self {
            case .captureAEB:
                return CameraMenuBranch.photoAeb
            case .captureBurst:
                return CameraMenuBranch.photoBurst
            case .captureInterval:
                return CameraMenuBranch.photoTiming
            default:
                return CameraMenuBranch.unknown
            }
        }
    }
}

extension AUTELCameraShutterSpeed {
    func displayName() -> String? {
        switch self {
        case .speed1_8000:
            return "1/8000"
        case .speed1_6000:
            return "1/6000"
        case .speed1_5000:
            return "1/5000"
        case .speed1_4000:
            return "1/4000"
        case .speed1_3200:
            return "1/3200"
        case .speed1_2500:
            return "1/2500"
        case .speed1_2000:
            return "1/2000"
        case .speed1_1600:
            return "1/1600"
        case .speed1_1250:
            return "1/1250"
        case .speed1_1000:
            return "1/1000"
        case .speed1_800:
            return "1/800"
        case .speed1_640:
            return "1/640"
        case .speed1_500:
            return "1/500"
        case .speed1_400:
            return "1/400"
        case .speed1_320:
            return "1/320"
        case .speed1_240:
            return "1/240"
        case .speed1_200:
            return "1/200"
        case .speed1_160:
            return "1/160"
        case .speed1_120:
            return "1/120"
        case .speed1_100:
            return "1/100"
        case .speed1_80:
            return "1/80"
        case .speed1_60:
            return "1/60"
        case .speed1_50:
            return "1/50"
        case .speed1_40:
            return "1/40"
        case .speed1_30:
            return "1/30"
        case .speed1_25:
            return "1/25"
        case .speed1_20:
            return "1/20"
        case .speed1_15:
            return "1/15"
        case .speed1_12p5:
            return "1/12.5"
        case .speed1_10:
            return "1/10"
        case .speed1_8:
            return "1/8"
        case .speed1_6p25:
            return "1/6.25"
        case .speed1_5:
            return "1/5"
        case .speed1_4:
            return "1/4"
        case .speed1_3:
            return "1/3"
        case .speed1_2p5:
            return "1/2.5"
        case .speed1_2:
            return "1/2"
        case .speed1_1p67:
            return "1/1.67"
        case .speed1_1p25:
            return "1/1.25"
        case .speed1p0:
            return "1\""
        case .speed1p3:
            return "1.3\""
        case .speed1p6:
            return "1.6\""
        case .speed2p0:
            return "2.0\""
        case .speed2p5:
            return "2.5\""
        case .speed3p0:
            return "3.0\""
        case .speed3p2:
            return "3.2\""
        case .speed4p0:
            return "4.0\""
        case .speed5p0:
            return "5.0\""
        case .speed6p0:
            return "6.0\""
        case .speed8p0:
            return "8.0\""
        case .speed9p0:
            return "9.0\""
        case .speed10p0:
            return "10.0\""
        case .speed13p0:
            return "13.0\""
        case .speed15p0:
            return "15.0\""
        case .speed20p0:
            return "20.0\""
        case .speed25p0:
            return "25.0\""
        case .speed30p0:
            return "30.0\""
        default:
            return nil
        }
    }
    
    func floatValue() -> Float? {
        switch self.rawValue {
        case AUTELCameraShutterSpeed.speed1_8000.rawValue..<AUTELCameraShutterSpeed.speed1_2.rawValue:
            return 0.5
        case AUTELCameraShutterSpeed.speed1_2.rawValue..<AUTELCameraShutterSpeed.speed1p0.rawValue:
            return 1.0
        default:
            return self.displayName().flatMap({ (text) -> Float? in
                return Float(text.dropLast().lowercased())
            })
        }
    }
}

extension AUTELCameraAntiFlicker {
    func displayName() -> String {
        switch self {
        case .flicker50Hz:
            return "50Hz"
        case .flicker60Hz:
            return "60Hz"
        case .flickerAuto:
            return "Auto"
        case .flickerClose:
            return "Turn Off"
        case .flickerUnknown:
            return "unknown"
        }
    }
}

extension AUTELCameraPictureInVideoInterval {
    func displayName() -> String? {
        switch self {
        case .interval5s:
            return "5S"
        case .interval10s:
            return "10S"
        case .interval30s:
            return "30S"
        case .interval60s:
            return "60S"
        default:
            return "Manual"
        }
    }
}

extension AUTELCameraVideoFileCompressionStandard {
    func displayName() -> String {
        switch self {
        case .H264:
            return "H.264"
        case .H265:
            return "H.265"
        default:
            return "unknown"
        }
    }
}


extension AUTELCameraStorageType {
    func displayName() -> String {
        switch self {
        case .sdCard:
            return "SD Card"
        case .EMMC:
            return "Flash Card"
        default:
            return "unknown"
        }
    }
}

extension AUTELRCControlStyle {
    func displayName() -> String? {
        switch self {
        case .RCControlStyleJapanese:
            return "Settings_RC_mode1"
        case .RCControlStyleAmerican:
            return "Settings_RC_mode2"
        case .RCControlStyleChinese:
            return "Settings_RC_mode3"
        case .RCControlStyleError:
            return "Settings_RC_modeError"
        case .RCControlStyleUnknown:
            print("Failed to obtain remote control mode N/A")
            return "N/A"
        }
    }
}

extension AUTELMainControllerFlightMode {
    func displayName() -> String {
        switch self {
        case .AutelMCFlightModeDisarm:
            return "Disarm"
        case .AutelMCFlightModeLanded:
            return "Landed"
        case .AutelMCFlightModeLanding:
            return "Landing"
        case .AutelMCFlightModeTakeoff:
            return "Take Off"
        case .AutelMCFlightModeAttitude:
            return "Attitude"
        case .AutelMCFlightModeGPS:
            return "GPS"
        case .AutelMCFlightModeIOC:
            return "IOC"
        case .AutelMCFlightModeManualGoHome, .AutelMCFlightModeFailSaveGoHome, .AutelMCFlightModeWaypointGoHome, .AutelMCFlightModeLowBattreyGoHome, .AutelMCFlightModeSmartLowBatteryGoHome:
            return "Go Home"
        case .AutelMCFlightModeFailSaveHover:
            return "Hover"
        case .AutelMCFlightModeFollowMePause, .AutelMCFlightModeHotpointPause, .AutelMCFlightModeWaypointPause, .AutelMCFlightModeRectanglePause, .AutelMCFlightModePolygonPause:
            return "Pause"
        case .AutelMCFlightModeWaypoint:
            return "Waypoint"
        case .AutelMCFlightModeRectangle, .AutelMCFlightModePolygon:
        return "Misstion Fly"
        case .AutelMCFlightModeFollowMe:
            return "Follow Me"
        case .AutelMCFlightModeHotpoint:
            return "Hot Point"
        default:
            return "Unknown"
        }
    }
}

extension AUTELNavigationMissionFinishMode {
    func mirroredValue() -> Int {
        switch self {
        case .hover:
            return 0
        case .goHome:
            return 1
        case .land:
            return 2
        case .goFirstWaypoint:
            return 3
        default:
            return 0
        }
    }
}

extension AUTELWaypointHeadingMode {
    func mirroredValue() -> Int {
        switch self {
        case .towardsNext:
            return 0
//        case .initial:
        case .freedom:
            return 1
        case .custom:
            return 2
        default:
            return 0
        }
    }
}


