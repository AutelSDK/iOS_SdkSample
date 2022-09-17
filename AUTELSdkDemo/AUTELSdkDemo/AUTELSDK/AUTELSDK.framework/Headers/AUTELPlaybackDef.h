//
//  AUTELPlaybackDef.h
//  AUTELSDK
//
//  Created by a15526 on 16/7/21.
//  Copyright © 2016年 Autel. All rights reserved.
//

#ifndef AUTELPlaybackDef_h
#define AUTELPlaybackDef_h


/**
*  Download file resolution types.
*
*  下载文件的分辨率类型。
*/
typedef NS_ENUM(NSInteger, AUTELPlaybackResolutionType) {
    /**
    *  @brief Thumbnail.
    *
    *  缩略图。
    */
    AUTELPlaybackResolutionTypeThumbnail,
    /**
    *  @brief Preview.
    *
    *  预览图。
    */
    AUTELPlaybackResolutionTypePreview,
    /**
    *  @brief Original image/Original video.
    *
    *  原图/原视频。
    */
    AUTELPlaybackResolutionTypeOriginal,
    /**
    *  @brief Unknown.
    *
    *  未知。
    */
    AUTELPlaybackResolutionTypeUnknown
};


/**
*  Download file types.
*
*  下载文件的类型。
*/
typedef NS_ENUM(NSInteger, AUTELDownloadFileType) {
    /**
    *  @brief Image file
    *
    *  图片文件
    */
    AUTELDownloadFileTypePhoto,
    /**
    *  @brief RAW file
    *
    *  RAW格式文件
    */
    AUTELDownloadFileTypeRAWDNG,
    /**
    *  @brief 640*512 video file
    *
    *  分辨率为640*512的视频文件
    */
    AUTELDownloadFileTypeVideo640X512,
    /**
    *  @brief 720P video file
    *
    *  分辨率为720P的视频
    */
    AUTELDownloadFileTypeVideo720P,
    /**
    *  @brief 1080P video file
    *
    *  分辨率为1080P的视频
    */
    AUTELDownloadFileTypeVideo1080P,
    /**
    *  @brief 2.7K video file
    *
    *  分辨率为2.7K的视频
    */
    ATUELDownloadFileTypeVideo2704P,
    /**
    *  @brief  2.7K video file
    *
    *  分辨率为2.7K的视频
    */
    ATUELDownloadFileTypeVideo2720P,
    /**
    *  @brief 4K video file
    *
    *  分辨率为4K的视频
    */
    AUTELDownloadFileTypeVideo4K,
    /**
    *  @brief 4K+ video file
    *
    *  分辨率为4K+的视频
    */
    AUTELDownloadFileTypeVideo4KP,
    /**
    *  @brief  6K video file
    *
    *  分辨率为6K的视频
    */
    AUTELDownloadFileTypeVideo6K,
    /**
    *  @brief 8K video file
    *
    *  分辨率为8K的视频
    */
    AUTELDownloadFileTypeVideo8K,
    /**
    *  @brief File format unknown
    *
    *  文件格式未知
    */
    AUTELDownloadFileTypeUnknown
};

/**
*  Get the file list type.
*
*  获取文件列表类型。
*/
typedef NS_ENUM(NSInteger, AUTELGetFileListType) {
    /**
    *  @brief Image file
    *
    * List of all files
    */
    AUTELGetFileListTypeAll = 0,
    
    /**
    *  @brief Video file list
    *
    *  视频文件列表
    */
    AUTELGetFileListTypeVideo = 1,
    
    /**
    *  @brief Picture file list
    *
    *  图片文件列表
    */
    AUTELGetFileListTypePhoto = 2,
};

/**
*  The resolution type of the downloaded video file.
*
*  下载视频文件的分辨率类型。
*/
typedef NS_ENUM(NSInteger, AUTELDownloadVideoResolutionType) {
    /**
    *  @brief Original video.
    *
    *  原视频。
    */
    AUTELDownloadVideoResolutionTypeOriginal = 0,
    
    /**
    *  @brief Thumbnail.
    *
    *  缩略视频。
    */
    AUTELDownloadVideoResolutionTypeThumbnail = 1,
    
    /**
    *  @brief Unknown.
    *
    *  未知。
    */
    AUTELDownloadVideoResolutionTypeUnknown
};


#endif /* AUTELPlaybackDef_h */
