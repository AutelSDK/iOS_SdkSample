//
//  AUTELNtripClient.h
//  NtripDemo
//
//  Created by Deng.D on 2021/3/13.
//

#import <Foundation/Foundation.h>


/**
 *  Define Ntrip RTK error
 *
 *  定义Ntrip RTK错误
 */
typedef NS_ENUM(uint8_t, AUTELNtripClientError) {
    /**
     *  @brief 没有异常
    */
    AUTELNtripClientErrorNone = 0,
    /**
     *  @brief Auth认证失败
     */
    AUTELNtripClientErrorAuthFailure  = 1,
    /**
     *  @brief 连接挂载点失败！
     */
    AUTELNtripClientErrorConnectFailure  = 2,
    /**
     *  @brief 获取挂载点失败
     */
    AUTELNtripClientErrorfetchMountpointsFailure  = 3,

};

/// 获取挂载点回调
typedef void (^ClientFetchMountpointsBlock)(NSArray <NSString*>* _Nullable mountpoints, NSError * _Nullable error);
/// 连接挂载点回调
typedef void (^ClientConnectedMountpointBlock)(NSError * _Nullable error);
/// 收到差分数据(String)的回调
typedef void (^ClientReceivedDataBlock)(NSString *_Nullable _NuntripClienttring);



@class AUTELNtripConfigration;
@class AUTELNtripClient;

@protocol AUTELNtripClientDelegate <NSObject>

@optional

- (void)clientConnectHost:(NSError *_Nullable)error;

- (void)clientDisconnectedHost:(NSError *_Nullable)error;


/// Ntrip client给飞控数据（0x420）：  二进制数据，APP需转发给飞控
/// @param ntripClient  客户端管理类
/// @param data 二进制数据
- (void)ntripClient:(AUTELNtripClient *_Nonnull)ntripClient didReceiveDiffData:(NSData *_Nonnull)data;;


@end


@interface AUTELNtripClient : NSObject

/// 初始化
- (instancetype _Nonnull )initWithConfig:(AUTELNtripConfigration * _Nonnull)config delegate:(id<AUTELNtripClientDelegate>_Nullable)delegate;

/// 是否已连接
- (BOOL)isConnected;

/// 拉取挂载点
- (void)fetchMountpointsWithConfig:(AUTELNtripConfigration * _Nonnull)config completion:(ClientFetchMountpointsBlock _Nullable )block;

/// 连接挂载点：必须输入挂载点
/// -error = nil : 成功
/// -error.code = -1 : 认证失败（用户过期）
/// -error.code = 0 : 认证失败（其它）
- (void)connectWithConfig:(AUTELNtripConfigration * _Nonnull)config completion:(ClientConnectedMountpointBlock _Nullable )block;

/// 发送数据data
- (void)sendData:(NSData *_Nonnull)data;

/// 发送数据string
- (void)sendString:(NSString *_Nonnull)string;

/// 断开连接
- (void)disconnect;

/// 差分Data -> String
- (NSString * _Nonnull)diffStringFor:(NSData *_Nonnull)data;

@end

