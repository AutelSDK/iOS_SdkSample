//
//  Float+MeasuringUnit.swift
//  AutelGen2
//
//  Created by a15526 on 2017/12/11.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation

enum UnitType {
    case speed
    case distance
}

extension Float {
    func meterToKolimeter() -> Float {
        return self / 1000.0
    }
    
    func meterToFeet() -> Float {
        return self * 3.28
    }
    
    func feetToMeter() -> Float {
        return self / 3.28
    }
    
    func meterToMile() -> Float {
        return self * 0.0006213712
    }
    // meterPerSecondToKolimeterPerHour
    func mpsToKmph() -> Float {
        return self * 3600 / 1000.0
    }
    func kmphToMps() -> Float {
        return self * 1000.0 / 3600
    }
    func mphToMps() -> Float {
        return self / 3600 * 1000.0 / 0.6213712
    }
    // meterPerSecondToMilePerHour
    func mpsToMph() -> Float {
        return self * 3600 / 1000.0 * 0.6213712
    }
    
    func centigradeToFahrenhite() -> Float {
        return self * 1.8 + 32
    }
    
    func fahrenhiteToCentigrade() -> Float {
        return (self - 32) / 1.8
    }
    
    /// Format time interval to "00:00".
    ///
    /// - Returns: formated time string and unit string.
    func formatTimeInterval() -> (String, String) {
        var formatTime: String
        if self > 60 {
            let min = Int(self) / 60
            let sec = Int(self) % 60
            var minStr: String
            var secStr: String
            if min < 10 {
                minStr = "0" + min.description
            } else {
                minStr = min.description
            }
            if sec < 10 {
                secStr = "0" + sec.description
            } else {
                secStr = sec.description
            }
            return (minStr + ":" + secStr, MesuringUnit.minute.rawValue)
        } else {
            let sec = Int(self)
            if sec < 10 {
                formatTime = "00" + ":" + "0" + sec.description
            } else {
                formatTime = "00" + ":" + sec.description
            }
            return (formatTime, MesuringUnit.second.rawValue)
        }
    }
    
    /// Make the length be more shorter in the UI.
    ///
    /// - Returns: value and unit
    func lengthFitToUnitSystem() -> (Float, MesuringUnit)  {
        switch UserSettings.shared.unitSystem {
        case .metric:
            //** `1 km = 1000 m`, 4 digits of this value would be a little long in the UI. So make the number be more shorter.
            if self >= 1000 {
                return (self.meterToKolimeter(), MesuringUnit.kilometer)
            } else {
                return (self, MesuringUnit.meter)
            }
        case .imperial:
            //** `304 m = 1000 feet`, 4 digits of this value would be a little long in the UI. So make the number be more shorter.
            if self >= 304 {
                return (self.meterToMile(), MesuringUnit.mile)
            } else {
                return (self.meterToFeet(), MesuringUnit.feet)
            }
        }
    }
    
    // 单位保持米或者是英尺
    func lengthFitToMetricOrFeet() -> (Float, MesuringUnit) {
        switch UserSettings.shared.unitSystem {
        case .metric:
            return (self, MesuringUnit.meter)
        case .imperial:
            return (self.meterToFeet(), MesuringUnit.feet)
        }
    }
    
    /// Speed Unit. Fit to UserSettings.shared.speedUnit
    ///
    /// - Returns: value and unit
    func speedFitToUnitSystem() -> (Float, MesuringUnit) {
        switch UserSettings.shared.speedUnit {
        case .metricKmh:
            return (self.mpsToKmph(), MesuringUnit.kilometerPerHour)
        case .metricMs:
            return (self, MesuringUnit.meterPerSecond)
        case .imperialMph:
            return (self.mpsToMph(), MesuringUnit.milePerHour)
        }
    }
    
    func speedFitToUnitSystem(format:String) -> String {
         let valueTuple = self.speedFitToUnitSystem()
         return valueTuple.0.formatf(format: format) + valueTuple.1.rawValue
    }
    
    /// 单位转换后的值及所带的单位
    ///
    /// - Parameters:
    ///   - unit: UnitType
    ///   - precision: 精度
    /// - Returns: String
    func matchedTextWithUnit(_ unit: UnitType, ofPrecision precision: Int = 2, useAbbreviation flag: Bool = true) -> String {
        switch unit {
        case .speed:
            let pair = self.speedFitToUnitSystem()
            return pair.0.format(format: ".\(precision)") + "\(pair.1.rawValue)"
        case .distance:
            let pair = self.lengthFitToUnitSystem()
            return pair.0.format(format: ".\(precision)") + "\(pair.1.use(flag))"
        }
    }
    
    //热成像温度自动转换，热成像传过来的温度是摄氏度*10
    func fitTemUint10() -> Float {
        if UserSettings.shared.tempUint == "0" {
            return self/10
        } else {
            
            return (self/10).centigradeToFahrenhite()
        }
    }
    
    func fitTemUint() -> Float {
        if UserSettings.shared.tempUint == "0" {
            return self
        } else {
            
            return self.centigradeToFahrenhite()
        }
    }
}
