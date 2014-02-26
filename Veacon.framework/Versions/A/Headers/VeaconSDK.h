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

@end

@interface VeaconSDK : NSObject
{
    id<VeaconDelegate> delegate;
}

@property (nonatomic,strong) id _delegate;

@property (strong, nonatomic) NSString *secretKey;

+ (VeaconSDK*) defaultVeaconSDK;

-(BOOL) initVeaconSDKWithSecret:(NSString*)secretKey;
-(BOOL) startVeaconService;
-(void) stopVeaconService;

-(BOOL) turnOnBeAVeacon;
-(void) turnOffBeAVeacon;
@end
