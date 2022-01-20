//
//  AUTELVideoFeed.h
//  AUTELSDK
//
//  Created by IOS on 2017/9/25.
//  Copyright © 2017年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum : NSUInteger {
    AutelH264EncodeFormat,
    AutelH265EncodeFormat,
} AutelVideoEncodeFormat;


@interface AUTELVideoDataPacket : NSObject

@property (nonatomic, assign, readonly)uint8_t *data;

@property (nonatomic, assign, readonly)size_t size;

@property (nonatomic, assign, readonly)int64_t pts;

@property (nonatomic, assign, readonly)int32_t width;

@property (nonatomic, assign, readonly)int32_t height;

@property (nonatomic, assign, readonly)int32_t keyFrame;

@property (nonatomic, assign, readonly)AutelVideoEncodeFormat videoFormat;

- (instancetype)initWithData:(uint8_t *)data withSize:(size_t)size withPts:(int64_t)pts;

- (instancetype)initWithData:(uint8_t *)data;

@end

@class AUTELVideoFeed;

@protocol AUTELVideoFeedListener <NSObject>

- (void)videoFeed:(AUTELVideoFeed *)feed didUpdateVideoData:(AUTELVideoDataPacket *)packet;

- (void)videoFeed:(AUTELVideoFeed *)feed didUpdateConnecteState:(BOOL)state;

@end

@interface AUTELVideoFeed : NSObject

+ (void)openVideoFeed;

+ (void)closeVideoFeed;

+ (void)addVideoFeedListener:(id<AUTELVideoFeedListener>)listener withQueue:(dispatch_queue_t)queue;

+ (void)removeVideoFeedListener:(id<AUTELVideoFeedListener>)listener;

@end
