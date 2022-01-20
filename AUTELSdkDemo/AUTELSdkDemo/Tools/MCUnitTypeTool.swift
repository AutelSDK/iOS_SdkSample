//
//  MCUnitTypeTool.swift
//  AutelGen2
//
//  Created by Autel-190215 on 2020/3/17.
//  Copyright © 2020 AUTEL. All rights reserved.
//

//Float+MeasuringUnit.swift

enum MCUnitType {
    case lenght
    case speed
    case temp
    case other
}

extension String {
    
    //MARK: 单位转化
    
    func deal(with unitType: MCUnitType) -> String {
        if unitType == .lenght || unitType == .speed {
            return getStringRound2IntBySystemUnit(value: Float(self) ?? 0, unitType: unitType)
        }
        return self
    }
    
    func dealToMetricf(with unitType: MCUnitType) -> Float? {
        return dealToSystemUnit(unitType)
    }
    
    
    func dealToSystemUnit(_ unitType: MCUnitType) -> Float? {
        if unitType == .lenght {
                   switch UserSettings.shared.unitSystem {
                   case .metric:
                       return Float(self)
                   case .imperial:
                       return Float(self)?.feetToMeter()
                   }
               } else if unitType == .speed {
                   switch UserSettings.shared.speedUnit {
                   case .imperialMph:
                       return Float(self)?.mphToMps()
                   case .metricKmh:
                       return Float(self)?.kmphToMps()
                   case .metricMs:
                       return Float(self)
                   }
               }else if unitType == .temp {
                
                if UserSettings.shared.tempUint != "0" { //华摄氏度要转换成成摄氏度才能上传给设备
                    return Float(self)?.fahrenhiteToCentigrade()
                } else {
                    return Float(self)
                }
               }else {
                return Float(self)
               }
    }
    
    func getStringRound2IntBySystemUnit(value: Float, unitType: MCUnitType) -> String {
        //String(format: format, self) 本身就有四舍五入
        return getStringBySystemUnit(value: value, format: "%.0f", unitType: unitType)
    }
    
    func getStringBySystemUnit(value: Float, format: String = "%.1f", unitType: MCUnitType) -> String {
        if unitType == .lenght {
            switch UserSettings.shared.unitSystem {
            case .metric:
                return value.formatf(format: format) + "m"
            case .imperial:
                return value.meterToFeet().formatf(format: format) + "ft"
            }
        } else if unitType == .speed {
            switch UserSettings.shared.speedUnit {
            case .imperialMph:
                return value.mpsToMph().formatf(format:format) + "mph"
            case .metricKmh:
                return value.mpsToKmph().formatf(format:format) + "km/h"
            case .metricMs:
                return value.formatf(format: format) + "m/s"
            }
        } else {
            return value.formatf(format: format)
        }
    }
}

/// 请使用 vauleBySystemUnit2  或者 vauleBySystemUnit 例子:  let (v,u) = value.vauleBySystemUnit2(unit) +  v.formatf(format: "%.0f") + u
func showTextByUnitSystem(value: Float, format: String = "", unitType: MCUnitType, unit: String = "") -> String {
    if unitType == .lenght || unitType == .speed {
        return getStringRound2IntBySystemUnit(value: value, unitType: unitType)
    } else {
        if format == "" {
            return String(roundf(value).format(format: ".0")) + unit
        } else {
            return String(format: format, value) + unit
        }
    }
}

func getStringRound2IntBySystemUnit(value: Float, unitType: MCUnitType) -> String {
    //String(format: format, self) 本身就有四舍五入
    return getStringBySystemUnit(value: value, format: "%.0f", unitType: unitType)
}
func getStringBySystemUnit(value: Float, format: String = "%.1f", unitType: MCUnitType) -> String {
    if unitType == .lenght {
        switch UserSettings.shared.unitSystem {
        case .metric:
            return value.formatf(format: format) + "m"
        case .imperial:
            return value.meterToFeet().formatf(format: format) + "ft"
        }
    } else if unitType == .speed {
        switch UserSettings.shared.speedUnit {
        case .imperialMph:
            return value.mpsToMph().formatf(format:format) + "mph"
        case .metricKmh:
            return value.mpsToKmph().formatf(format:format) + "km/h"
        case .metricMs:
            return value.formatf(format: format) + "m/s"
        }
    } else {
        return value.formatf(format: format)
    }
}
