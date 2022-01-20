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
@property (nonatomic, copy) NSString *host;
/// 端口
@property (nonatomic, assign) NSInteger port;
/// 挂载点
@property (nonatomic, copy) NSString *mountpoint;

/// 差分用户名
@property (nonatomic, copy) NSString *userName;
/// 差分用户密码
@property (nonatomic, copy) NSString *password;

/// 初始化
- (instancetype)initWithHost:(NSString *)host
                        port:(NSInteger )port
                  mountpoint:(NSString *)mountpoint
                    userName:(NSString *)userName
                    password:(NSString *)password;

/// 按默认值初始化 - 仅用于测试！！
- (instancetype)initWithDefault;

@end

NS_ASSUME_NONNULL_END
