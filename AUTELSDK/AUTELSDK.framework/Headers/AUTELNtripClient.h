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
     *  @brief No error 没有异常
    */
    AUTELNtripClientErrorNone = 0,
    /**
     *  @brief Authentication failed  Auth认证失败
     */
    AUTELNtripClientErrorAuthFailure  = 1,
    /**
     *  @brief Failed to connect to mount point! 连接挂载点失败！
     */
    AUTELNtripClientErrorConnectFailure  = 2,
    /**
     *  @brief Failed to get mount point 获取挂载点失败
     */
    AUTELNtripClientErrorfetchMountpointsFailure  = 3,

};

/// 获取挂载点回调
/// Get mount point callback
typedef void (^ClientFetchMountpointsBlock)(NSArray <NSString*>* _Nullable mountpoints, NSError * _Nullable error);

/// 连接挂载点回调  AUTELCompletionBlock
/// Connection mount point callback AUTELCompletionBlock
//typedef void (^ClientConnectedMountpointBlock)(NSError * _Nullable error);

/// 收到差分数据(String)的回调
/// Callback for receiving differential data (String)
typedef void (^ClientReceivedDataBlock)(NSString *_Nullable _NuntripClienttring);



@class AUTELNtripConfigration;
@class AUTELNtripClient;

@protocol AUTELNtripClientDelegate <NSObject>

@optional


/// Client Connect Host
/// 客户端连接主机
///
/// @param error 错误
- (void)clientConnectHost:(NSError *_Nullable)error;

/// Client Disconnect Host
/// 客户端不连接主机
///
/// @param error 错误
- (void)clientDisconnectedHost:(NSError *_Nullable)error;


/// Ntrip client给飞控数据（0x420）：  二进制数据，APP需转发给飞控
/// Ntrip client to flight control data (0x420): binary data, APP needs to forward to flight control
///
/// @param ntripClient  客户端管理类
/// Client management class
///
/// @param data 二进制数据
/// binary data
- (void)ntripClient:(AUTELNtripClient *_Nonnull)ntripClient didReceiveDiffData:(NSData *_Nonnull)data;;


@end


@interface AUTELNtripClient : NSObject

/// 初始化
/// init
- (instancetype _Nonnull )initWithConfig:(AUTELNtripConfigration * _Nonnull)config delegate:(id<AUTELNtripClientDelegate>_Nullable)delegate;

/// 是否已连接
/// Is Connected
- (BOOL)isConnected;

/// 拉取挂载点
/// pull mount point
/// @param config AUTELNtripConfigration
/// @param block commpete callback
- (void)fetchMountpointsWithConfig:(AUTELNtripConfigration * _Nonnull)config completion:(ClientFetchMountpointsBlock _Nullable )block;

/// 连接挂载点：必须输入挂载点
/// -error = nil : 成功
/// -error.code = -1 : 认证失败（用户过期）
/// -error.code = 0 : 认证失败（其它）
///
/// /// Connect to the mount point: the mount point must be entered
/// -error = nil : success
/// -error.code = -1 : Authentication failed (user expired)
/// -error.code = 0 : authentication failed (other)
///
/// @param config AUTELNtripConfigration
/// @param block Completion Block
- (void)connectWithConfig:(AUTELNtripConfigration * _Nonnull)config completion:(AUTELCompletionBlock _Nullable )block;

/// 发送数据data
/// senf data
- (void)sendData:(NSData *_Nonnull)data;

/// 发送数据string
/// senf string data
- (void)sendString:(NSString *_Nonnull)string;

/// 断开连接 disconnect
- (void)disconnect;

/// 断开连接 disconnect
/// @param block Completion block
- (void)disconnectWithCompletion:(AUTELCompletionBlock _Nullable )block;

/// 差分Data -> String
/// Differential Data -> String
///
/// @param data 数据
- (NSString * _Nonnull)diffStringFor:(NSData *_Nonnull)data;

@end

