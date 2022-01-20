//
//  AUTELRTKModel.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/8/26.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 *  RTK working parameters.
 *
 *  RTK 工作参数
 */
@interface AUTELTransferAuthFlyzoneFileModel : NSObject

///latitude of auth-fly zone 授权区中心点纬度
@property (nonatomic, assign) float lattitude;

///longitude of auth-fly zone 授权区中心点经度
@property (nonatomic, assign) float longitude;

///授权区半径
@property (nonatomic, assign) float radius;

///允许飞行高度
@property (nonatomic, assign) float height;

///开始有效时间
@property (nonatomic, assign) int32_t s_time;

///结束有效时间
@property (nonatomic, assign) int32_t e_time;


//- (instancetype)initWithParam:(NSDictionary *)param;

@end


NS_ASSUME_NONNULL_END
