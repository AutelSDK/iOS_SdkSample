//
//  CameraConnection.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/12.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

class CameraConnection: NSObject, AUTELBaseCameraDelegate {
    
    static let shared = CameraConnection()
    
    private var currentCamera: AUTELBaseCamera?
    
    
    private var queue: DispatchQueue = DispatchQueue(label: "com.autel.gen2.connection")
    
    private var protocols: [String: CameraProtocol] = [:]
    
    var camera: AUTELBaseCamera? {
        get {
            return currentCamera
        }
    }
    
    
    /// 私有初始化方法，防止外部调用
    private override init() {
        super.init()
    }
    
    /// 设置代理，强引用
    ///
    /// - Parameters:
    ///   - aProtocol: 实现CameraProtocol的对象
    ///   - key: 键值，默认为调用者文件名称
    func addProtocol(_ aProtocol: CameraProtocol, with key: String = #file) -> Void {
        queue.async{
            guard let file = (key as NSString).lastPathComponent.components(separatedBy: ".").first else { return }
            self.protocols[file] = aProtocol
        }
    }
    
    /// 根据键值删除协议，不要在dinit中调用该方法，原因是这里面是强引用，dinit方法根本不会走
    ///
    /// - Parameter key: 键值，默认为调用者文件名称
    func removeProtocol(with key: String = #file) -> Void {
        queue.async {
            guard let file = (key as NSString).lastPathComponent.components(separatedBy: ".").first else { return }
            self.protocols[file] = nil
        }
    }
    
    func connect(_ camera: AUTELBaseCamera?) -> Void {
        //每次都要更新代理，否则有问题！！！！！！！！！！！！1
        currentCamera?.delegate = nil
        currentCamera = camera
        currentCamera?.delegate = self

    }
    
    // MARK: - AUTELBaseCameraDelegate
    
    //连接状态
    func camera(_ camera: AUTELBaseCamera!, didUpdateConnectState connectState: AUTELCameraConnectState) {
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateConnectState: connectState)
            }
        }
        guard connectState == .connected else {
    
            return
        }
        connect(camera)
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateRecordRecoverState state: AUTELCameraRecordRecoverState) {
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateRecordRecoverState: state)
            }
        }
    }
    
    func camera(_ camera: AUTELBaseCamera!, didGenerateNewMediaFile newMedia: AUTELMedia!) {
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didGenerateNewMediaFile: newMedia)
            }
        }
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateSDCardState sdCardState: AUTELCameraSDCardState!) {
 
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateSDCardState: sdCardState)
            }
        }
    }
    
    
    /// MMC状态实时更新
    /// - Parameters:
    ///   - camera: 相机信息
    ///   - mmcState: 状态信息，注意：MMC也是使用AUTELCameraSDCardState，但MMC的isInserted还是指SD卡的插入状态，MMC不可用isInserted
    func camera(_ camera: AUTELBaseCamera!, didUpdateMMCState mmcState: AUTELCameraSDCardState!) {
 
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateMMCState: mmcState)
            }
        }
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateSystemState systemState: AUTELCameraSystemBaseState!) {

        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
//                guard aProtocol.isLoaded else { continue }
                aProtocol.camera(camera, didUpdateSystemState: systemState)
            }
        }
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateParameters parameters: AUTELCameraParameters!, change: [AnyHashable : Array<Any>]!) {
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateParameters: parameters, change: change)
            }
        }
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateCurrentExposureValues exposureParameters: AUTELCameraExposureParameters!) {
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateCurrentExposureValues: exposureParameters)
            }
        }
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateHistogramTotalPixels totalPixels: Int, andPixelsPerLevel pixelsArray: [Any]!) {
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateHistogramTotalPixels: totalPixels, andPixelsPerLevel: pixelsArray)
            }
        }
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateTimeLapseCaptured captureCount: Int, andCountDown timeInterval: TimeInterval) {
        //执行回调
        queue.async{
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateTimeLapseCaptured: captureCount, andCountDown: timeInterval)
            }
        }
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateAutoFocusState focusState: AUTELCameraAFLensFocusState, andLensFocusAreaRowIndex rowIndex: Int, andColIndex colIndex: Int) {
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateAutoFocusState: focusState, andLensFocusAreaRowIndex: rowIndex, andColIndex: colIndex)
            }
        }
    }
    
    @objc func camera(_ camera: AUTELBaseCamera!, didUpdateAeAfState state: Int) {
        print( "didUpdateAeAfState========================")
        //执行回调
        queue.async {
            for (_, aProtocol) in self.protocols {
                aProtocol.camera(camera, didUpdateAeAfState: state)
            }
        }
    }
    
}




