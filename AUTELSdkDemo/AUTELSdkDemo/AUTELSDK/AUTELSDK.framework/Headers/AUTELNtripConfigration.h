//
//  AUTELNtripConfigration.h
//  NtripDemo
//
//  Created by Deng.D on 2021/3/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUTELNtripConfigration : NSObject

/// 域名
/// host
@property (nonatomic, copy) NSString *host;

/// 端口
/// port
@property (nonatomic, assign) NSInteger port;

/// 挂载点
/// mountpoint
@property (nonatomic, copy) NSString *mountpoint;

/// 差分用户名
/// Differential username
@property (nonatomic, copy) NSString *userName;

/// 差分用户密码
/// Differential User Password
@property (nonatomic, copy) NSString *password;


/// 初始化
/// init
///
/// @param host 域名
/// @param port 端口
/// @param mountpoint 挂载点
/// @param userName 差分用户名
/// @param password 差分用户密码
- (instancetype)initWithHost:(NSString *)host
                        port:(NSInteger )port
                  mountpoint:(NSString *)mountpoint
                    userName:(NSString *)userName
                    password:(NSString *)password;

/// 按默认值初始化 - 仅用于测试！！
/// Initialize by default - just for testing! !
- (instancetype)initWithDefault;

@end

NS_ASSUME_NONNULL_END
