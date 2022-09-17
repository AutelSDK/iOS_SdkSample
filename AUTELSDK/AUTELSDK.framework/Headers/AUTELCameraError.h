//
//  AUTELCameraError.h
//  AUTELSDK
//
//  Created by Autel on 15/10/22.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#define UNKNOWN_ERROR @"UNKNOWN_ERROR"                                        //-1
#define SESSION_START_FAIL @"SESSION_START_FAIL"                              //-3
#define INVALID_TOKEN @"INVALID_TOKEN"                                        //-4
#define REACH_MAX_CLNT @"REACH_MAX_CLNT"                                      //-5
#define JSON_PACKAGE_ERROR @"JSON_PACKAGE_ERROR"                              //-7
#define JSON_PACKAGE_TIMEOUT @"JSON_PACKAGE_TIMEOUT"                          //-8
#define JSON_SYNTAX_ERROR @"JSON_SYNTAX_ERROR"                                //-9
#define INVALID_OPTION_VALUE @"INVALID_OPTION_VALUE"                          //-13
#define INVALID_OPERATION @"INVALID_OPERATION"                                //-14
#define HDMI_INSERTED @"HDMI_INSERTED"                                        //-16
#define NO_MORE_SPACE @"NO_MORE_SPACE"                                        //-17
#define CARD_PROTECTED @"CARD_PROTECTED"                                      //-18
#define PIV_NOT_ALLOWED @"PIV_NOT_ALLOWED"                                    //-20
#define SYSTEM_BUSY @"SYSTEM_BUSY"                                            //-21
#define APP_NOT_READY @"APP_NOT_READY"                                        //-22
#define OPERATION_UNSUPPORTED @"OPERATION_UNSUPPORTED"                        //-23
#define INVALID_TYPE @"INVALID_TYPE"                                          //-24
#define INVALID_PARAM @"INVALID_PARAM"                                        //-25
#define INVALID_PATH @"INVALID_PATH"                                          //-26
#define AUTEL_ERROR_UNDEFINED @"AUTEL_ERROR_UNDEFINED"                        //-100
#define AUTEL_ERROR_TIMEOUT @"AUTEL_ERROR_TIMEOUT"                            //-101
#define AUTEL_ERROR_NOTSUPPORT @"AUTEL_ERROR_NOTSUPPORT"                      //-102
#define AUTEL_ERROR_INVALIDPARAMETER @"AUTEL_ERROR_INVALIDPARAMETER"          //-103
#define AUTEL_ERROR_INVALIDCONNECT @"AUTEL_ERROR_INVALIDCONNECT"              //-104
#define AUTEL_ERROR_REMOVEDFROMQUEUE @"CODE_AUTEL_ERROR_REMOVEDFROMQUEUE"     //-105

#define CODE_UNKNOWN_ERROR -1
#define CODE_SESSION_START_FAIL -3
#define CODE_INVALID_TOKEN -4
#define CODE_REACH_MAX_CLNT -5
#define CODE_JSON_PACKAGE_ERROR -7
#define CODE_JSON_PACKAGE_TIMEOUT -8
#define CODE_JSON_SYNTAX_ERROR -9
#define CODE_INVALID_OPTION_VALUE -13
#define CODE_INVALID_OPERATION -14
#define CODE_HDMI_INSERTED -16
#define CODE_NO_MORE_SPACE -17
#define CODE_CARD_PROTECTED -18
#define CODE_PIV_NOT_ALLOWED -20
#define CODE_SYSTEM_BUSY -21
#define CODE_APP_NOT_READY -22
#define CODE_OPERATION_UNSUPPORTED -23
#define CODE_INVALID_TYPE -24
#define CODE_INVALID_PARAM -25
#define CODE_INVALID_PATH -26
#define CODE_AUTEL_ERROR_UNDEFINED -100
#define CODE_AUTEL_ERROR_TIMEOUT -101
#define CODE_AUTEL_ERROR_NOTSUPPORT -102
#define CODE_AUTEL_ERROR_INVALIDPARAMETER -103
#define CODE_AUTEL_ERROR_INVALIDCONNECT -104
#define CODE_AUTEL_ERROR_REMOVEDFROMQUEUE -105
#define CODE_AUTEL_ERROR_SDCARDERROR -106

@interface AUTELCameraError : NSError
{
    NSString *_content;                //错误内容
    NSString *_errorDescription;       //错误描述
    
}
@property (assign,nonatomic,readonly) int errorCode;

/**
 *  Error description.
 */
@property (strong,nonatomic,readonly) NSString *errorDescription;

+ (instancetype)errorWithErrorCode:(int)errorCode;

- (id)initWithErrorCode:(int)errCode;

-(void) setErrorDescription:(NSString *)errorDescription;

@end
