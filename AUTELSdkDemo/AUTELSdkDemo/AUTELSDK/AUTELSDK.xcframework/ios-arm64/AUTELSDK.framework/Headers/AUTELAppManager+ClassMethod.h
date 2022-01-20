//
//  AUTELAppManager+ClassMethod.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/5/27.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELSDK.h>
#import <AUTELSDK/AUTELLinkGen2.h>

@class AUTELAircraftGPSRecordInfo;

NS_ASSUME_NONNULL_BEGIN

@interface AUTELAppManager (ClassMethod)

#pragma mark 以下接口仅内部使用，不对外发布

//For internal use only
+ (void)requestIDRFrame:(int)flage;

//For internal use only
+ (void)getAirplaneGPSRecordInfoWithCompletion:(void (^_Nullable)(NSArray <AUTELAircraftGPSRecordInfo *> * _Nullable recordInfos, NSError * _Nullable error))block;

//For internal use only
+ (void)updateFirmwareWithInfor:( NSDictionary * _Nonnull)infor
               withFirmwareName:( NSString * _Nonnull)fileName
                   withProgress:(void (^_Nullable)(NSUInteger progress))progress
                 withCompletion:(AUTELCompletionBlock _Nullable)block;

//For internal use only
+ (void)updateFirmwareWithInfor:( NSDictionary * _Nonnull)infor
                     updateType:(AUTELFirmwareUpdateTyp)type
               withFirmwareName:( NSString * _Nonnull)fileName
                   withProgress:(void (^_Nullable)(NSUInteger progress))progress
                 withCompletion:(AUTELCompletionBlock _Nullable)block;

//For internal use only
+ (void)bindingAirRemoteRole:(AUTELRCPairingRole)role deviceType:(AUTELRCPairingDeviceType)deviceType withCompletion:(AUTELCompletionBlock)block;

@end



NS_ASSUME_NONNULL_END
