//
//  AUTELCameraObject.h
//  AUTELSDK
//
//  Created by Autel on 15/10/21.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTELCameraObject.h"
#import "AUTELSDK/AUTELCameraError.h"
#import "AUTELCameraSettingsDef.h"

typedef void(^AUTELResultBlock) (AUTELCameraError *error);
typedef void(^AUTELStringResultBlock) (NSString *result,AUTELCameraError *error);
typedef void(^AUTELParamResultBlock) (CameraPhotoSizeType res,AUTELCameraError *error);
typedef void(^AUTELOptionsResultBlock) (NSArray *resArr,AUTELCameraError *error);
typedef void(^AUTELListResultBlock) (NSDictionary *listArr,AUTELCameraError *error);

@interface AUTELCameraObject : NSObject
{
    __block NSNumber  *_cameraTpye;
    AUTELCameraStreamConnectState _connectState;
}
@property(nonatomic, assign) AUTELCameraStreamConnectState cameraStreamConnectState;
//@property(atomic, retain) NSNumber *cameraType;

/**
 *  从短路径，拼接出完整路径
 *  例如: DCIM/102MEDIA/MAX_0097.JPG
 *  得到: http://192.168.1.11/thumbnail?path=/DCIM/102MEDIA/MAX_0097.JPG
 */
- (NSString *)imageObsoluteStringForShortString:(NSString *)shortString;





/**
 * 字典转字符串
 *
 * @param json json转成的字典
 *
 * @return 字符串用于发送给相机的命令
 **/
- (NSString *)convertJsonDictToString:(NSDictionary *)json;

/**
 * json字符串转字典
 *
 * @param jsonInString jsonInString相机返回数据转换的字符串
 *
 * @return 字典用于相机返回数据处理
 **/
- (NSDictionary *)convertStringToDictionary:(NSString *)jsonInString;

/**
 * 将接收到的相机data数据转成字符串
 *
 * @param data 相机返回的数据
 *
 * @return 字符串NSData转换的
 **/
- (NSString *)convertReceiveDataToString:(NSData *)data;
- (NSMutableArray *)convertReceiveDataToStringArr:(NSString *)data;
/**
 *  比较两个版本号
 *
 *  @param version1 版本号1
 *  @param version2 版本号2
 *
 *  @return 0:两个版本号相等; 1:version1比version2新; -1:version1比version2旧
 **/
- (int) compareVersionWithSource:(NSString *)version1 WithDes:(NSString *)version2;
@end
