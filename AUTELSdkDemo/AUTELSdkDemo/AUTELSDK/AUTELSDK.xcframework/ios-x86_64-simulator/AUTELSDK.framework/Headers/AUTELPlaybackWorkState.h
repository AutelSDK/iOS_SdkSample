//
//  AUTELPlaybackWorkState.h
//  AUTELSDK
//
//  Created by a15526 on 16/7/20.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A playback state represents a task that the Playback manager is executing.
 *
 *  代表回放管理者当前进行的任务的回放状态。
 */
typedef NS_ENUM(NSInteger, AUTELPlaybackExecuteTaskState) {
    /**
    *  @brief  Retrieving the file list.
    *
    *  正在获取文件列表。
    */
    AUTELPlaybackExecuteTaskFetchingFileList,
    /**
    *  @brief  Retrieving the file thumbnail.
    *
    *  正在获取文件缩略图。
    */
    AUTELPlaybackExecuteTaskFetchingThumbnail,
    /**
    *  @brief  Retrieving the file preview.
    *
    *  正在获取文件预览图。
    */
    AUTELPlaybackExecuteTaskFetchingPreview,
    /**
    *  @brief  Retrieving the original file.
    *
    *  正在下载原文件。
    */
    AUTELPlaybackExecuteTaskDownloading,
    /**
    *  @brief  Deleting the file.
    *
    *  正在删除文件。
    */
    AUTELPlaybackExecuteTaskDeleting,
    /**
    *  @brief  Idle state.
    *
    *  空闲状态。
    */
    AUTELPlaybackExecuteTaskIdle
};

/**
 *  Playback work state mainly updates on current operation.
 *
 *  该类管理回放状态, 主要反馈当前正在进行的操作。
 */
@interface AUTELPlaybackWorkState : NSObject

/**
 *  @brief A playback state represents a task that the Playback manager is executing.
 *
 *  返回代表回放管理者当前进行的任务的状态。
 */
@property (nonatomic, readonly) AUTELPlaybackExecuteTaskState state;

@end
