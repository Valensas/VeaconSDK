//
//  VeaconSDK.h
//  Veacon
//
//  Created by Furkan BAYRAKTAR on 2/1/14.
//  Copyright (c) 2014 Valensas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@protocol VeaconDelegate <NSObject>
@required
- (void) customVeaconAction:(NSString*)key data:(NSDictionary *)data;
@optional
- (void) bluetoothDisabledAction;
@end

@interface VeaconSDK : NSObject<CLLocationManagerDelegate, CBPeripheralManagerDelegate>

extern NSString * const VLVeaconModeUpdated;
extern NSString * const VLVeaconNameUpdated;
extern NSString * const VLVeaconName;

+ (void) configureWithSecretKey:(NSString*)secretKey;

+ (BOOL) startVeaconMonitoring:(NSError**)error;
+ (void) stopVeaconMonitoring;
+ (BOOL) isMonitoringActive;

+ (BOOL) startVeaconMode:(NSError**)error;
+ (void) stopVeaconMode;
+ (BOOL) isVeaconModeActive;

+ (BOOL) loggingMode;
+ (void) setLoggingMode:(BOOL)logging;

+ (void) setLanguagePreferences:(NSArray*)languagePreferences;

+ (void) setUserId:(NSString*)userId andInfo:(NSDictionary*)userInfo;

+ (void) setDelegate:(id<VeaconDelegate>)delegate;

@end
