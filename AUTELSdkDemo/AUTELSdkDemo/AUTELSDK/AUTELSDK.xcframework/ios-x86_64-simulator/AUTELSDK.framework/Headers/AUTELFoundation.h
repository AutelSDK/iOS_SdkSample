//
//  AUTELFoundation.h
//  AUTELSDK
//
//  Created by IOS on 15/11/15.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Availability.h>

#ifdef __cplusplus
#define AUTEL_API_EXTERN       extern "C" __attribute__((visibility ("default")))
#else
#define AUTEL_API_EXTERN       extern __attribute__((visibility ("default")))
#endif

#define AUTEL_API_DEPRECATED __attribute__ ((__deprecated__))
