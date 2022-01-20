//
//  CameraProtocol.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/12.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK

protocol CameraProtocol: CheckProtocol {
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateConnectState connectState: AUTELCameraConnectState) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateRecordRecoverState recoverState: AUTELCameraRecordRecoverState) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didGenerateNewMediaFile newMedia: AUTELMedia!) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateSDCardState sdCardState: AUTELCameraSDCardState!) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateMMCState mmcState: AUTELCameraSDCardState!) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateSystemState systemState: AUTELCameraSystemBaseState!) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateParameters parameters: AUTELCameraParameters!, change: [AnyHashable : Array<Any>]!) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateCurrentExposureValues exposureParameters: AUTELCameraExposureParameters!) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateHistogramTotalPixels totalPixels: Int, andPixelsPerLevel pixelsArray: [Any]!) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateTimeLapseCaptured captureCount: Int, andCountDown timeInterval: TimeInterval) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateAutoFocusState focusState: AUTELCameraAFLensFocusState, andLensFocusAreaRowIndex rowIndex: Int, andColIndex colIndex: Int) -> ()
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateAeAfState state: Int) -> ()
}

extension CameraProtocol {
    func camera(_ camera: AUTELBaseCamera!, didUpdateConnectState connectState: AUTELCameraConnectState) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateRecordRecoverState recoverState: AUTELCameraRecordRecoverState) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didGenerateNewMediaFile newMedia: AUTELMedia!) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateSDCardState sdCardState: AUTELCameraSDCardState!) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateMMCState mmcState: AUTELCameraSDCardState!) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateSystemState systemState: AUTELCameraSystemBaseState!) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateParameters parameters: AUTELCameraParameters!, change: [AnyHashable : Array<Any>]!) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateCurrentExposureValues exposureParameters: AUTELCameraExposureParameters!) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateHistogramTotalPixels totalPixels: Int, andPixelsPerLevel pixelsArray: [Any]!) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateTimeLapseCaptured captureCount: Int, andCountDown timeInterval: TimeInterval) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateAutoFocusState focusState: AUTELCameraAFLensFocusState, andLensFocusAreaRowIndex rowIndex: Int, andColIndex colIndex: Int) -> () {
        
    }
    
    func camera(_ camera: AUTELBaseCamera!, didUpdateAeAfState state: Int) -> () {
        
    }
}
