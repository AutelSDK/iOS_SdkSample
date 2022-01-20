//
//  AUTELCameraResponseOperation.h
//  AUTELSDK
//
//  Created by Autel on 15/10/22.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import "AUTELCameraObject.h"
#import "MessageQueue.h"

@interface AUTELCameraResponseOperation : AUTELCameraObject
{
    MessageQueue *_messageQueue;
    NSDictionary *_dictionary;
}
//- (id)initWithDelegate:(id)delegate delegateQueue:(dispatch_queue_t)dq;
- (id)initWithDelegate:(id)delegate delegateQueue:(dispatch_queue_t)dq parserQueue:(dispatch_queue_t)pq;

//- (void)setDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;

/**
 * Asynchronously parses the given data.
 * The delegate methods will be dispatch_async'd as events occur.
 **/
- (void)parseData:(NSDictionary *)dictionay WithMessageQueue:(MessageQueue *)queue;

@end

#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@protocol AUTELCameraParserDelegate

@optional
- (void)autelParser:(AUTELCameraResponseOperation *)sender didFail:(NSError *)error;

- (void)autelParserDidParseData:(AUTELCameraResponseOperation *)sender;
@end