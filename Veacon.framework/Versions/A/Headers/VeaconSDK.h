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
- (void) customVeaconAction:(NSString*)key data:(NSString *)data;
@optional
- (void) didBluetoothDisabled;
@end

@interface VeaconSDK : NSObject

@property (nonatomic, weak) id<VeaconDelegate> delegate;

+ (void) configureWithSecretKey:(NSString*)secretKey;

+ (BOOL) startVeaconMonitoring:(NSError**)error;
+ (void) stopVeaconMonitoring;
+ (BOOL) isMonitoringActive;

+ (BOOL) startVeaconMode:(NSError**)error;
+ (void) stopVeaconMode;

@end
