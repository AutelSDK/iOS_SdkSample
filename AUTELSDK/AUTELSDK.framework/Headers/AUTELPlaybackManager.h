//
//  AUTELPlaybackManager.h
//  AUTELSDK
//
//  Created by a15526 on 16/7/19.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AUTELPlaybackWorkState.h"
#import "AUTELPlaybackDef.h"
#import <AUTELSDK/AUTELCameraDef.h>

@class AUTELMedia;
@class AUTELPlaybackManager;
@class AVPlayerItem;
@class AUTELBaseCamera;
/**
 *  @brief The  block triggered at thumbnail image request or preview request.
 *
 *  请求到缩略图或者预览图将触发的block.
 */
typedef void (^_Nullable AUTELLowerResolutionImageCompletion)(UIImage *_Nullable image, NSError *_Nullable error);

/**
 *  @brief The block which reflects the deleting process.
 *
 *  删除文件过程中反映删除进度的block.
 */
typedef void (^_Nullable AUTELFileDeletingProgress)(NSUInteger deleteFileNo, NSUInteger expectedFileNo);

/**
 *  @brief he block which gives feedback on the files failed to be deleted after deleting a batch of files.
 *
 *  删除一批次文件后反馈此批次中删除失败的文件的block.T
 */
typedef void (^_Nullable AUTELFileDeleteListCompletion)(NSArray<AUTELMedia *> *_Nonnull successMedias);

/**
 *  @brief The block which gives feedback on the files failed to be deleted after deleting the whole files.
 *
 *  删除操作完成后返回删除失败的文件的block.
 */
typedef void (^_Nullable AUTELFileDeleteCompletion)(NSArray<AUTELMedia *> *_Nullable failedMedias, NSError *_Nullable error);

/**
 *  @brief The block triggered before downloading a file.
 *
 *  文件下载前触发的block.
 */
typedef void (^_Nullable AUTELFileDownloadPreparingBlock)(AUTELMedia *_Nullable media, AUTELDownloadFileType fileType,  BOOL skip);

/**
 *  @brief The block which reflects the progress of downloading files.
 *
 *  下载文件时返回进度的block.
 */
typedef void (^_Nullable AUTELFileDownloadProgressBlock)(int64_t totalBytesWritten, int64_t totalBytesExpectedToWrite);

/**
 *  @brief The block triggered when finishing downloading a file.
 *
 *  单个文件下载完成触发的block.
 */
typedef void (^_Nullable AUTELFileDownloadCompletionBlock)(NSURL *_Nullable fileLocation);

/**
 *  This protocol offers a delegate method to receive the updates on playback manager.
 *
 *  该协议提供了一个代理方法来接收回放管理者状态的更新.
 */
@protocol AUTELPlaybackDelegate <NSObject>

@optional

/**
 *  @brief This will be called when the camera playback state changes.
 *
 *  当相机回放状态发生改变时调用.
 *
 *  @param Playback State: playback operation (obtaining thumbnail/preview images, download, delete) is available only when the playbackState.state is AUTELPlaybackExecuteTaskIdle.
 *
 *  playbackState   回放状态, 只有当 playbackState.state 为 AUTELPlaybackExecuteTaskIdle 时才能进行回放操作(获取缩略图\预览图, 下载, 删除), 否则将会返回失败。
 *
 *  @see   AUTELPlaybackWorkState
 */
- (void)playbackManager:(AUTELPlaybackManager *_Nonnull)playbackManager didUpdatePlaybackState:(AUTELPlaybackWorkState *_Nonnull)playbackState;

@end

/**
 *  Playback manager mainly interacts with files taken and stored in the SD card, including obtaining all the files, thumbnail images, previews, deleting files, or downloading files from the SD card to mobile devices.
 *
 *  回放管理者主要与SD卡中设备拍摄的文件进行交互. 包括获取SD卡中所有文件、文件的缩略图\预览图、删除SD卡中文件以及下载SD卡中文件至移动设备.
 */
@interface AUTELPlaybackManager : NSObject

@property (nonatomic, strong) NSString * _Nonnull cameraAddress;

/**
*  @brief The current storage device type of PlaybackManager, EVO 2 supports both SD Card and Flash Card.
*
*  当前PlaybackManager的存储设备类型,EVO 2同时支持SD Card和Flash Card.
*
*  @see AUTELCameraStorageType
*/
@property (nonatomic, readonly) AUTELCameraStorageType storageType;

/**
 *  @brief The number of media files (including photos and videos) in SD card.
 *
 *  SD卡中设备拍摄的所有媒体文件的数量, 包括图片和视频.
 */
@property (nonatomic, readonly) NSInteger numberOfTotalMedia;

/**
 *  @brief The local storage path for downloaded original files and the property cannot be nil.
 *
 *  原始文件下载到本地的存储路径, 使用下载原文件接口时, 该属性不可为空.
 */
@property (nonatomic, copy) NSString *_Nonnull downloadDirectory;

/**
 *  @brief Delegate of AUTELPlaybackManager.
 *
 *  AUTELPlaybackManager的代理.
 */
@property (nonatomic, weak) id <AUTELPlaybackDelegate> _Nullable delegate;

/**
 *  @brief current camera.
 */
@property (weak, nonatomic, weak) AUTELBaseCamera *_Nullable camera;

// initWithStorageType For internal use only
- (instancetype  _Nonnull )initWithStorageType:(AUTELCameraStorageType)StorageType;

/**
 *  @brief Get SD card file list in pages.
 *
 *  分页获取SD卡文件列表.
 *
 *  @param offset The starting subscript of the requested file list. The first file is subscripted as zero.
 *
 *  请求文件列表的起始下标, 下标为 0 表示第一个文件.
 *
 *  @param count  The number of files requested.
 *
 *  请求文件的个数.
 *
 *  @param block  xecution results callback. Request succeeds and returns SD card file list when error is nil. Objectis in mediaList are kind of class AUTELMedia.
 *
 *  执行结果回调, error为nil则请求成功并返回文件列表, mediaList中的数据是 AUTELMedia 类型.E
 *
 *  @note If the subscript of the last file outnumbers the actual number of files in SD card, then the number of files in the returned file list will be equal to the actual number of files.
 *
 *  若count大于500, 相机只会按count为500进行处理, 若请求的最后一个文件的下标值大于SD卡中实际文件总个数, 将会按照实际存在的文件数量返回文件列表.
 */
- (void)fetchMediaFileListFromOffset:(NSUInteger)offset
                           fileCount:(NSUInteger)count
                      withCompletion:(void (^_Nonnull)(NSArray<AUTELMedia *> *_Nullable mediaList, NSError *_Nullable error))block;

/**
 *  @brief Get SD card file list in pages.
 *
 *  分页获取SD卡文件列表.
 *
 *  @param offset The starting subscript of the requested file list. The first file is subscripted as zero.
 *
 *  请求文件列表的起始下标, 下标为 0 表示第一个文件.
 *
 *  @param count  The number of files requested.
 *
 *  请求文件的个数.
 *
 *  @param fileType  Get the file list type.
 *
 *  获取文件列表类型.
 *
 *  @param block  xecution results callback. Request succeeds and returns SD card file list when error is nil. Objectis in mediaList are kind of class AUTELMedia.
 *
 *  执行结果回调, error为nil则请求成功并返回文件列表, mediaList中的数据是 AUTELMedia 类型.E
 *
 *  @note If the subscript of the last file outnumbers the actual number of files in SD card, then the number of files in the returned file list will be equal to the actual number of files.
 *
 *  若count大于500, 相机只会按count为500进行处理, 若请求的最后一个文件的下标值大于SD卡中实际文件总个数, 将会按照实际存在的文件数量返回文件列表.
 */
- (void)fetchMediaFileListFromOffset:(NSUInteger)offset
                           fileCount:(NSUInteger)count
                            fileType:(AUTELGetFileListType)fileType
                      withCompletion:(void (^_Nonnull)(NSArray<AUTELMedia *> *_Nullable mediaList, NSError *_Nullable error))block;

/**
 *  @brief Get the corresponding thumbnail images.
 *
 *  获取文件的相应缩略图.
 *
 *  @param Media file.
 *  
 *  media 文件.
 *
 *  @param block Execution results callback.
 *
 *  执行结果回调.
 */
- (void)fetchThumbnailForMedia:(AUTELMedia *_Nonnull)media
                withCompletion:(AUTELLowerResolutionImageCompletion)block;

/**
 *  @brief Get the corresponding previews.
 *
 *  获取文件的相应预览图.
 *
 *  @note No previews for videos, but thumbnails.
 *
 *  视频文件无预览图, 只有缩略图.
 *
 *  @param media The media file.
 *
 *  media 文件.
 *
 *  @param block Execution results callback.
 *
 *  执行结果回调.
 */
- (void)fetchPreviewImageForMedia:(AUTELMedia *_Nonnull)media
                   withCompletion:(AUTELLowerResolutionImageCompletion)block;



/// Check whether there is a thumbnail video interface. Generally, there is no thumbnail video for 2.7K \ 4k video.
/// @param media The media file.
/// @param block Execution results callback,Return to AVPlayerItem for playing video online
- (void)playerItemForVideo:(AUTELMedia *_Nonnull)media
            withCompletion:(void (^_Nullable)(AVPlayerItem *_Nullable playerItem, BOOL isOriginalData, NSError * _Nullable error))block;


/**
 *  @brief Delete the files in SD card.
 *
 *  删除SD卡中的文件.
 *
 *  @discussion This method deletes all media files in batches. One batch consists of 25 images or a single video file. deleteListBlock returns the files failed to be deleted in every batch.
 *
 *  该方法将收到的所有 media 分批次进行删除,图片文件每50个为一个批次进行删除, 视频文件单个文件为一个批次进行删除, deleteListBlock 中返回了每个批次中删除失败的文件.
 *
 *  @param medias  All files that need to be deleted.
 *
 *  所有需要删除的文件.
 *
 *
 *  @param progressBlock   Deletion progress callback. deleteFileNo indicates the number of deleted files. expectedFileNo indicates the total number of files that need to be deleted.
 *
 *  删除进度回调, deleteFileNo 表示当前已删除完成的文件数, expectedFileNo 表示总的需要删除的文件数.
 *
 *  @param deleteListBlock Return result after deleting a batch of files. Files failed to be deleted will be placed in deleteFailures. If deleteFailures is nil, it means succeeded to delete all the files in this batch.
 *
 *  删除一个批次返回结果, 删除失败的文件将会放在 deleteFailures 表示的数组中, 若该数组为空则表示该批次中的全部文件删除成功.
 *
 *  @param deleteAllBlock  Deletion completion callback. If error occurs in the deleting process, error will be returned. If it proceeds well, then error is nil.
 *
 *  删除完成回调, 如果删除任务执行过程中出错将会返回error, 若整个删除过程进展顺利, 则error为nil.
 */
- (void)deleteMedia:(NSArray<AUTELMedia *> *_Nonnull)medias
       withProgress:(AUTELFileDeletingProgress)progressBlock
deleteListCompletion:(AUTELFileDeleteListCompletion)deleteListBlock
  overallCompletion:(AUTELFileDeleteCompletion)deleteAllBlock;



/// Delete the file
/// @param media This method delete one media file.
/// @param block Deletion completion callback. If error occurs in the deleting process, error will be returned. If it proceeds well, then error is nil.
- (void)deleteMediaItem:(AUTELMedia *_Nonnull)media
         withCompletion:(AUTELCompletionBlock)block;

/**
 *  @brief Cancel the current deleting task.
 *
 *  取消正在进行的删除任务.
 *
 *  @param completion Completion Block.
 *
 *  操作完成回调.
 */
- (void)cancelDeletingWithCompletion:(AUTELCompletionBlock)completion;

/**
 *  @brief Download original files from SD card.
 *
 *  下载SD卡中原始文件.
 *  
 *  @discussion when using this method to download original files in SD card, RAW files and videos whose resolution is above 1080p (not including 1080p) will not be downloaded. If error occurs in downloading process, overallCompletionBlock will be called and the error will be returned. If it proceeds well, overallCompletionBlock will be called without returning any errors.
 *
 *  该方法下载SD卡中原始文件, RAW 格式文件与 1080P 清晰度以上的视频文件(不包括 1080P 清晰度的视频)将不会被下载。若文件下载过程中产生错误, overallCompletionBlock 将会被调用并返回该错误, 若整个下载过程进行顺利, overallCompletionBlock 调用时无错误信息.
 *
 *  @param medias Files to be downloaded.
 *
 *  将要下载的文件.
 *
 *  @param prepareBlock Preparations before downloading: tell the name and type of the file to be downloaded. If it is a RAW file or a file whose resolution is above 1080p, then the value of skip will be YES, which means this file will not be downloaded.
 *
 *  下载每一个文件前的准备工作, 告知将要下载的文件的文件名与文件类型, 若该文件类型为 RAW 与 1080P清晰度以上, skip 的值将为 YES, 表示该文件不会被下载.
 *
 *  @param progressBlock  During the downloading process of each file, this block will be frequently called to give feedbacks on the real time downloading progress. totalBytesWritte indicates the total number of bytes transferred so far, and totalBytesExpectedToWrite indicates the expected length of the file.
 *
 *  在每个文件下载过程中, 该block将会被频繁调用以反馈下载的实时进度, totalBytesWitten表示文件已经下载的大小, totalBytesExpectedToWritte 表示文件的总大小.
 *
 *  @param fileCompletionBlock   The block which indicates succeeded to download a single file. FileLocation includes the local storage path of downloaded files.
 *
 *  单个文件下载完成的block, fileLocation含下载完成后文件保存在本地中的路径.
 *
 *  @param overallCompletionBlock Download completion callback.  If error occurs in the downloading process, error will be returned. If it proceeds well, then error is nil.
 *
 *  下载完成回调, 如果下载任务执行过程中出错将会返回error, 若整个删除过程进展顺利, 则error为nil.
 */
- (void)downloadMedia:(NSArray<AUTELMedia *> *_Nonnull)medias
      withPreparation:(AUTELFileDownloadPreparingBlock)prepareBlock
             progress:(AUTELFileDownloadProgressBlock)progressBlock
   downloadCompletion:(AUTELFileDownloadCompletionBlock)fileCompletionBlock
    overallCompletion:(AUTELCompletionBlock)overallCompletionBlock;


- (void)downloadMedia:(NSArray<AUTELMedia *> *_Nonnull)medias
             withType:(AUTELDownloadVideoResolutionType)resolutionType
      preparation:(AUTELFileDownloadPreparingBlock)prepareBlock
             progress:(AUTELFileDownloadProgressBlock)progressBlock
   downloadCompletion:(AUTELFileDownloadCompletionBlock)fileCompletionBlock
    overallCompletion:(AUTELCompletionBlock)overallCompletionBlock;



/**
 *  @brief Cancel the current downloading task.
 *
 *  取消正在进行的下载任务.
 *
 *  @param completion Completion Block.
 *
 *  操作完成回调.
 */
- (void)cancelDownloadingWithCompletion:(AUTELCompletionBlock)completion;

/// Is it Wimax Image Transmission?
/// 是否是酷芯图传
- (BOOL)isAirLinkWiMax;


/// Cancel all downloads <including thumbnails, high-resolution images>
/// 取消所有下载<包括缩略图、高清图>
- (void)cancelAllDownload;

/// Cancel download of all preview images
/// 取消所有预览图的下载
- (void)cancelPreviewDownload;
@end
