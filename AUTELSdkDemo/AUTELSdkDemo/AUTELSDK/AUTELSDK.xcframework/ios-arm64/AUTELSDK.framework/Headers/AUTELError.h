//
//  AUTELError.h
//  AUTELSDK
//
//  Created by IOS on 15/11/12.
//  Copyright © 2015年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>
#define ERR_Succeeded                         0x00

#define ERR_NotSupport                        0x01
#define ERR_NotActivation                     0x02
#define ERR_ActivationFailed                  0x03
#define ERR_NoPermission                      0x04
#define ERR_MotorWorking                      0x05
#define ERR_NotFly                            0x06
#define ERR_MotoNotWork                       0x07
#define ERR_CompassError                      0x08

#define ERR_InvalidSSID                       0x10
#define ERR_SendFailed                        0x11
#define ERR_ConnectFailed                     0x12
#define ERR_InvalidParameter                  0x13
#define ERR_CommandExecuteFailed              0x14
#define ERR_VersionNotCompatible              0x15

#define ERR_TooCloseToHomePoint               0xA0
#define ERR_FollowTargetTooFar                0xB0
#define ERR_FollowGPSLost                     0xB1
#define ERR_FollowGimbalPitch                 0xB2

#define ERR_RCModeError                       0xD0
#define ERR_MCModeError                       0xD1
#define ERR_IOCWorking                        0xD2
#define ERR_MissionNotInit                    0xD3
#define ERR_MissionNotExist                   0xD4
#define ERR_MissionConflict                   0xD5
#define ERR_MissionEstimateTimeTooLong        0xD6
#define ERR_HighPriorityMissionExecuting      0xD7
#define ERR_GpsSignalWeak                     0xD8
#define ERR_LowBattery                        0xD9
#define ERR_AircraftNotInTheAir               0xDA
#define ERR_MissionParamInvalid               0xDB
#define ERR_MissionConditionNotSatisfied      0xDC
#define ERR_MissionAcrossNoFlyZone            0xDD
#define ERR_HomePointInvalid                  0xDE
#define ERR_AircraftInNoFlyZone               0xDF

#define ERR_AltitudeTooHigh                   0xC0
#define ERR_AltitudeTooLow                    0xC1
#define ERR_MissionRadiusInvalid              0xC2
#define ERR_MissionSpeedTooLarge              0xC3
#define ERR_MissionEntryPointInvalid          0xC4
#define ERR_MissionHeadingModeInvalid         0xC5
#define ERR_MissionResumeFailed               0xC6
#define ERR_MissionRadiusOverLimit            0xC7
#define ERR_NavigationNotSupport              0xC8
#define ERR_MissionTooFar                     0xC9
#define ERR_MissionIsRunning                  0xCA
#define ERR_WaypointNumberOver                0xCB
#define ERR_MissionRadiusOverLimit_POI        0xCC

#define ERR_NotSupportedCommand               0xE0
#define ERR_Timeout                           0xE1
#define ERR_MemoryAllocFailed                 0xE2
#define ERR_InvalidCommand                    0xE3
#define ERR_NotSupportNow                     0xE4
#define ERR_TimeNotSync                       0xE5
#define ERR_ParameterSetFailed                0xE6
#define ERR_ParameterGetFailed                0xE7
#define ERR_SDCardNotInserd                   0xE8
#define ERR_SDCardFull                        0xE9
#define ERR_SDCardError                       0xEA
#define ERR_SensorError                       0xEB
#define ERR_SystemError                       0xEC
#define ERR_NotDefined                        0xFF

#define ERR_InvalidData                       0x100
#define ERR_NetworkAbortByApp                 0x101
#define ERR_NetworkAbortByServer              0x102

#define ERR_WaypointError                     0x103
#define ERR_WaypointParamError                0x104
#define ERR_WaypointBusyError                 0x104

#define ERR_FollowMeFinishModeError           0x105
#define ERR_NotInGPSMode                      0x106
#define ERR_InNoFlyZone                       0x107
#define ERR_HotpointInvalid                   0x108
#define ERR_NewHomePointTooFarAway            0x109

@class AUTELError;

extern AUTELError *AUTELErrorFor(NSUInteger errorCode);

@interface AUTELError : NSObject<NSCopying> {
    NSUInteger _code;
    NSString *_content;
}
/**
 *  Error code.
 */
@property (assign,nonatomic,readonly) NSUInteger errorCode;

/**
 *  Error description.
 */
@property (strong,nonatomic,readonly) const NSString *errorDescription;


/// creat error with  Error code.
/// @param errorCode Error code.
+ (instancetype)errorWithErrorCode:(NSUInteger)errorCode;


/// init error with  Error code.
/// @param errCode Error code.
- (id)initWithErrorCode:(NSUInteger)errCode;


/// set error description
/// @param errorDescription  error description
-(void) setErrorDescription:(const NSString *)errorDescription;

@end

#define NewErrorObject(code) [[AUTELError alloc] initWithErrorCode:(code)]
