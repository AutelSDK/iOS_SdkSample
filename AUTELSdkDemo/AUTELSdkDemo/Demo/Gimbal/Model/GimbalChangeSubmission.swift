//
//  GimbalChangeSubmission.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/11/6.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

class GimbalChangeSubmission {

    /// 向云台发送命令设置云台参数
    ///
    /// - Parameters:
    ///   - mode: 旋转模式
    ///   - value: 值，当模式为速度时，值的有效范围为[-200, 200],当模式为角度时，值的有效范围为[-90, 0]
    class func updateGimbalWithMode(_ mode: AUTELGimbalRotationMode, andValue value: CGFloat, with result: ResultHandler) {
        GimbalConnection.shared.gimbal?.rotate(with: getRotationWithMode(mode, andValue: value)!, withCompletion: { (error) in
            if let err = error {
                print("rotate gimbal error: \(err.localizedDescription)")
                result?(err)
            } else {
                result?(nil)
            }
        })
    }

    /// 向云台发送命令设置云台参数
    ///
    /// - Parameters:
    ///   - mode: 旋转模式
    ///   - value: 值，当模式为速度时，值的有效范围为[-200, 200],当模式为角度时，值的有效范围为[-90, 0]
    class func updateGimbalWithMode(_ mode: AUTELGimbalRotationMode, andValue value: CGFloat) -> Void {
        guard let gimbalRotation = getRotationWithMode(mode, andValue: value) else { return }
        GimbalConnection.shared.gimbal?.rotate(with: gimbalRotation, withCompletion: { (error) in
            if let err = error {
                print("rotate gimbal error: \(err.localizedDescription)")
            }
        })
    }
    
    /// 根据云台设置模式和值，获取云台旋转对象
    ///
    /// - Parameters:
    ///   - mode: 旋转模式
    ///   - value: 模式对应的值
    /// - Returns: AUTELGimbalRotation?
    private class func getRotationWithMode(_ mode: AUTELGimbalRotationMode, andValue value: CGFloat) -> AUTELGimbalRotation? {
        let num = mode == .speed ? max(-100, min(100, value)) : max(-90, min(0, value))
        let rotation = AUTELGimbalRotation(pitchValue: num as NSNumber, rollValue: nil, yawValue: nil, mode: mode)
        return rotation
    }
    
}
