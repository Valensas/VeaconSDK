//
//  VeaconSDK.h
//  Veacon
//
//  Created by Furkan BAYRAKTAR on 2/1/14.
//  Copyright (c) 2014 Valensas. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol VeaconDelegate <NSObject>
@required
- (void) customVeaconAction:(NSString*)key data:(NSDictionary *)data;
@optional
- (void) bluetoothDisabledAction;
@end

@interface VeaconSDK : NSObject

+ (void) configureWithSecretKey:(NSString*)secretKey;

+ (BOOL) startVeaconMonitoring:(NSError**)error;
+ (void) stopVeaconMonitoring;
+ (BOOL) isMonitoringActive;

+ (BOOL) startVeaconMode:(NSError**)error;
+ (void) stopVeaconMode;

+ (BOOL) loggingMode;
+ (void) setLoggingMode:(BOOL)logging;

+ (void) setDelegate:(id<VeaconDelegate>)delegate;

@end
