//
//  AUTELCameraSettingModel.h
//  AUTELSDK
//
//  Created by zhiganglet on 2020/9/29.
//  Copyright © 2020 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
*  The file system format of the current storage device.
*
*   当前存储设备文件系统格式。
*/
typedef NS_ENUM(uint8_t, AUTELCameraStorageFileFormat) {
    /// SD Fat32
    AUTELCameraStorageFileFormatSDFat32 = 0,
    /// EMMC Fat32
    AUTELCameraStorageFileFormatEMMCFat32 = 1,
    /// SD exFat
    AUTELCameraStorageFileFormatSDExFat = 2,
    
};

NS_ASSUME_NONNULL_BEGIN

@interface AUTELCameraRecordPacketModel : NSObject

/**
*  @brief The file system format of the current storage device.
*
*  当前存储设备文件系统格式。
*/
@property (nonatomic, assign) AUTELCameraStorageFileFormat fileFormat;

/**
 *  @brief RecordPacket
 *
 *  当前录像文件分段打包大小（单位M），如果StorageFormat为SD卡Fat32或EMMC Fat32时，固定为3500M；如果为SD卡exFat格式时，可配置文件分段大小，如果为0表示不分段，默认分段3500M.
 */
@property (nonatomic) int recordPacket;

- (instancetype)initWithParam:(NSDictionary *)param;

@end

NS_ASSUME_NONNULL_END
