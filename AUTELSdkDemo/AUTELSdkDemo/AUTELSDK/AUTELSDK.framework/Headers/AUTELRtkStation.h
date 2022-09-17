//
//  AUTELRtkStation.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/10/29.
//  Copyright © 2020 AUTEL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


@class AUTELRtkStation;
@class AUTELRtkStationLocationStatus;

@protocol AUTELRtkStationDelegate <NSObject>

/// 地面基站位置信息上报
/// @param rtkStation RTK基站管理类
/// @param status 基站位置信息
- (void)rtkStation:(AUTELRtkStation *_Nonnull)rtkStation didUpdateStationStatus:(AUTELRtkStationLocationStatus *_Nonnull)status;

@optional

/// 地面基站连接状态发送改变
/// @param rtkStation RTK基站管理类
/// @param status 连接状态
- (void)rtkStation:(AUTELRtkStation *_Nonnull)rtkStation didConnectionStatusChanged:(AUTELDeviceConnectionStatus)status;

/// 地面站给飞控数据（0x420）：  二进制数据，APP需转发给飞控
/// @param rtkStation RTK基站管理类
/// @param data 二进制数据
- (void)rtkStation:(AUTELRtkStation *_Nonnull)rtkStation didReceiveDiffData:(NSData *_Nonnull)data;

@end


/// RTK基站管理类
@interface AUTELRtkStation : NSObject

@property (nonatomic, weak) id<AUTELRtkStationDelegate> _Nullable delegate;


- (id _Nonnull )init;

/// 建立基站连接
- (BOOL)connect;


/// 连接状态
- (BOOL)isConnected;

/// 断开基站连接
- (void)disconnect;



//升级接口

- (void)getFirmwareInfoWithCompletion:(void (^_Nullable)(NSArray<NSDictionary*>* _Nullable firmwareInfo, NSError * _Nullable error))block;

- (void)startFirmwareUpdataWithInfor:(NSString * _Nonnull)filepath
                            filesize:(NSUInteger)filesize
                      withCompletion:(AUTELCompletionBlock)block;

- (void)updateFirmwareWithInfor:(NSDictionary * _Nonnull)infor
               withFirmwareName:(NSString *_Nonnull)fileName
                   withProgress:(AUTELProgressHandler)progress
                 withCompletion:(AUTELCompletionBlock)block;

/// 设置RTK基站坐标
/// @param coordinate 坐标
/// @param altitude 高度
/// @param block 结果回调
- (void)setStationLocation:(CLLocationCoordinate2D)coordinate
                  altitude:(float)altitude
            withCompletion:(AUTELCompletionBlock)block;

/// 设置RTK WIFI密码
/// @param password WIFI密码
/// @param block 结果回调
- (void)setStationRouteWifiPassword:(NSString *)password withCompletion:(AUTELCompletionBlock)block;

/// 重置RTK WIFI出厂密码
/// @param password WIFI密码
/// @param block 结果回调
- (void)retSetStationRouteWifiPasswordCompletion:(AUTELCompletionBlock)block;

@end
