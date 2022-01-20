//
//  AUTELObject.h
//  AUTELSDK
//
//  Created by IOS on 15/11/12.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AUTELError;

/**
 *  Remote execute result callback. To show result of the async operation after completion.
 *  
 *  远程执行结果回调方法。用于展示异步方法完成后的结果。
 *
 *  @param error    Result of the async operation after completion. User should always check the error's code to see whether the operation is execut succeed. if error.errorCode not equal to ERR_Succeeded then chekc the error description to see the reason why the operation failed.
 *
 *  异步操作完成后返回的结果。用户需要通过检查 `error` 的 `code` 参数来判断操作是否成功。如果错误码不等于 ERR_Succeeded,就需要通过 `error` 的 `description` 参数来获取操作失败的原因。
 */
typedef void (^_Nullable AUTELExecuteResultBlock)(AUTELError *_Nullable error);

/**
 *  Completion block for asynchronous operations. This completion block is used for methods that return at an unknown future time.
 *
 *  异步操作的完成 block。
 *
 *  @param error Error object if an error occured during async operation. nil if no error occurred.
 */
typedef void (^_Nullable AUTELCompletionBlock)(NSError *_Nullable error);

/**
 *  Returns the progress status from 0.0 to 100.0
 *  返回一个0.0~100.0进度的block
 */
typedef void (^_Nullable AUTELProgressHandler)(float progress);

@interface AUTELObject : NSObject

@end
