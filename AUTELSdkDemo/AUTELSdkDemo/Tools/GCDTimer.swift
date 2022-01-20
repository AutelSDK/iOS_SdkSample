//
//  GCDTimer.swift
//  MTMTV
//
//  Created by Autel-iOS on 2019/7/1.
//  Copyright © 2019 AUTEL. All rights reserved.
//

import UIKit
    
private let timerQueue = DispatchQueue(label: "com.timer.queue", attributes: [])
    
final class GCDTimer: NSObject {
    
    private var timer: DispatchSourceTimer?
    
    private var timerCount: Int = 0
    
    var active: Bool {
        return timer != nil
    }
    
    deinit {
        cancel()
    }
    
    /// 启动一个毫秒级定时器
    /// - Parameters:
    ///   - interval: 毫秒
    ///   - repeats: 是否循环，默认否
    ///   - handler: 回调
    func start(milliseonds intervalInMilliseonds: Int, repeats: Bool = false, handler: @escaping () -> Void) {
        
        cancel()
        
        let timer = DispatchSource.makeTimerSource(queue: timerQueue)
        self.timer = timer
        
        timer.schedule(deadline: .now() + .milliseconds(intervalInMilliseonds), repeating: .milliseconds(intervalInMilliseonds))
        timer.setEventHandler { [weak self] in
            if !repeats {
                self?.cancel()
            }
            DispatchQueue.main.async(execute: handler)
        }
        timer.resume()
    }
    
    
    /// 启动一个秒级定时器
    /// - Parameters:
    ///   - interval: 秒
    ///   - repeats: 是否循环，默认否
    ///   - handler: 回调
    func start(_ interval: Int, repeats: Bool = false, handler: @escaping () -> Void) {
        
        cancel()
        
        let timer = DispatchSource.makeTimerSource(queue: timerQueue)
        self.timer = timer
        
        timer.schedule(deadline: .now() + .seconds(interval), repeating: .seconds(interval))
        timer.setEventHandler { [weak self] in
            if !repeats {
                self?.cancel()
            }
            DispatchQueue.main.async(execute: handler)
        }
        timer.resume()
    }
    
    
    /// 启动一个秒级定时器
    /// - Parameters:
    ///   - interval: 秒
    ///   - repeatCount: 指定重复次数
    ///   - handler: 回调
    func start(_ interval: Int, repeatCount: Int = 1, handler: @escaping (Int) -> Void) {
        
        cancel()
        
        let timer = DispatchSource.makeTimerSource(queue: timerQueue)
        self.timer = timer
        self.timerCount = 0
        
        timer.schedule(deadline: .now() + .seconds(interval), repeating: .seconds(interval))
        timer.setEventHandler { [weak self] in
            guard let strongSelf = self else {
                return
            }
            strongSelf.timerCount = strongSelf.timerCount+1
            if strongSelf.timerCount >= repeatCount {
                strongSelf.cancel()
            }
            DispatchQueue.main.async {
                handler(strongSelf.timerCount)
            }
        }
        timer.resume()
    }

    
    /// 取消定时器
    func cancel() {
        guard let timer = timer else { return }
        timer.cancel()
        self.timer = nil
    }
}
