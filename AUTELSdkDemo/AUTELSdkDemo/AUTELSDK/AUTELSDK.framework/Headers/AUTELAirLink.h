//
//  AUTELAirLink.h
//  AUTELSDK
//
//  Created by IOS on 2016/12/7.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AUTELAirLink;
@class AUTELDevice;
@class AUTELLinkGen2;

@protocol AUTELAirLinkDelegate <NSObject>

/**
 callback from airlink that did update connect state

 @param link AUTELAirLink
 @param connected whether to connect the device
 */
- (void)airLink:(AUTELAirLink *)link didUpdateConnecteState:(BOOL)connected;

@end

/**
*
*  Obtain current state of the AirLink.
*
*  通过 AUTELAirLink 类，可以获取到通信链路的连接状态
*
*/

@interface AUTELAirLink : NSObject


/**
*  @brief  Delegate instance. Obtain airLink status  through delegate callback.
*
*  代理实例，通过代理回调方法，可以获取连接状态
*
*  @see AUTELAirLinkDelegate
*/
@property (weak, nonatomic) id<AUTELAirLinkDelegate> delegate;

/**
 provides the status of connection
 */
@property (weak, nonatomic, readonly) AUTELDevice *device;

/**
 Whether to support the second generation of airlink
 */
@property (nonatomic, readonly) BOOL isLinkGen2Supported;

/**
 Whether to connect the device
 */
@property (nonatomic, readonly) BOOL isConnected;

/**
 The second generation airlink object
 */
@property (nonatomic, readonly) AUTELLinkGen2 *linkGen2;

@end
