//
//  AUTELMedia.h
//  AUTELSDK
//
//  Created by a15526 on 16/7/19.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELCameraDef.h"

/**
 *  媒体文件类型
 *
 *  Media types.
 */
typedef NS_ENUM(NSInteger, AUTELMediaType) {
    /**
     *  Unknown.
     */
    AUTELMediaTypeUnknown,
    /**
     *  JPEG.
     */
    AUTELMediaTypeJPEG,
    /**
     *  RAW.
     */
    AUTELMediaTypeRAW,
    /**
     *  MP4.
     */
    AUTELMediaTypeMP4,
    /**
     *  MOV.
     */
    AUTELMediaTypeMOV,
    /**
     *  M4V.
     */
    AUTELMediaTypeM4V
};

typedef NS_ENUM(NSInteger, AUTELCameraPanoramaType) {
    ///非全景照片
    AUTELCameraPanoramaTypeNo = 0,
    ///横拍
    AUTELCameraPanoramaTypeLandscape,
    ///竖拍
    AUTELCameraPanoramaTypePortrait,
    ///广角
    AUTELCameraPanoramaTypeWideAngle,
    ///球形
    AUTELCameraPanoramaTypeSpherical,
    
};

/**
 *  该类描述SD卡中多媒体文件的基本属性.
 *
 *  This class contains information about a multi-media file on the SD card.
 */
@interface AUTELMedia : NSObject<NSCopying, NSCoding>

/**
 *  @brief 媒体文件名.
 *
 *  Returns the name of the media file.
 */
@property (nonatomic, readonly) NSString *fileName;

/**
 *  @brief 媒体文件在SD卡中的存放路径.
 *
 *  Returns the file path of the media file in SD card.
 */
@property (nonatomic, readonly) NSString *filePath;



/**
 *  @brief 媒体文件创建时间, 格式为: yyyy-MM-dd HH:mm:ss.
 *
 *  Returns the time when the media file was created as a string in
 *  the format "yyyy-MM-dd HH:mm:ss".
 */
@property (nonatomic, readonly) NSString *timeCreated;

/**
 *  @brief 媒体文件下标, 新拍摄的文件排放在前.
 *
 *  Returns the index of the media file. The latest taken file will be lined in the front.
 */
@property (nonatomic, readonly) NSUInteger mediaIndex;

/**
 *  @brief 媒体文件的字节大小.
 *
 *  Returns the size, in bytes, of the media file.
 */
@property (nonatomic, readonly) long long fileSizeInBytes;

/**
 *  @brief 媒体文件的类型.
 *
 *  Returns the type of media file.
 */
@property (nonatomic, readonly) AUTELMediaType mediaType;

/**
 *  @brief 媒体文件的唯一标识符.
 *
 *  Returns the unique identifier of media file.
 */
@property (nonatomic, readonly) NSString *uniqueID;

/**
 视频时长
 */
@property (nonatomic, assign) NSUInteger videoDuration;

/**
 @brief 视频文件的分辨率, 图片文件无分辨率该值为`AUTELCameraVideoResolutionUnknown`, 视频文件初始值也为`AUTELCameraVideoResolutionUnknown`, 当请求过该文件的缩略图后, 该值才有意义。
 
 Returns the resolution of video file.
 */
@property (nonatomic, readonly) AUTELCameraVideoResolution videoResolution;

/**
 Returns the video framerate of video file.
 */
@property (nonatomic, readonly) AUTELCameraVideoFrameRate videoFrameRate;

/**
 @brief 视频文件的压缩标准
 
 Returns the  compreassion standar of video file.
 */
@property (nonatomic, readonly) AUTELCameraVideoFileCompressionStandard videoCompressionStandard;

/**
 @brief 全景照片类型
 
 Returns the  Types of panoramic photos.
 */
@property (nonatomic, assign) AUTELCameraPanoramaType panoramaType;

@end
