//
//  AUTELBaseCamera+AUTELBaseCamera_ToolMethod.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/7/25.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <AUTELSDK/AUTELSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUTELBaseCamera (ToolMethod)

/**
*  @brief 解析照片分辨率
*
*  @param horizintal 传感器水平分辨率
*  @param vertical 传感器垂直分辨率
*  @return 解析结果
*/
+ (AUTELCameraPhotoAspectRatio)analyPhotoAspectRatioWithHorizintal:(NSString * _Nonnull)horizintal vertical:(NSString * _Nonnull)vertical;

@end

NS_ASSUME_NONNULL_END
