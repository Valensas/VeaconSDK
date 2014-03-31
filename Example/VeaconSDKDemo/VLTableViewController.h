//
//  VLTableViewController.h
//  VeaconSDKDemo
//
//  Created by Furkan BAYRAKTAR on 3/28/14.
//  Copyright (c) 2014 Valensas. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VeaconSDK.h>

@interface VLTableViewController : UITableViewController
@property (weak, nonatomic) IBOutlet UISwitch *monitoringSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *beAVeaconSwitch;

- (IBAction)logging:(id)sender;
- (IBAction)monitoring:(id)sender;
- (IBAction)beAVeacon:(id)sender;

@end
