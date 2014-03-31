//
//  VLTableViewController.m
//  VeaconSDKDemo
//
//  Created by Furkan BAYRAKTAR on 3/28/14.
//  Copyright (c) 2014 Valensas. All rights reserved.
//

#import "VLTableViewController.h"

@interface VLTableViewController ()

@end

@implementation VLTableViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(receiveVeaconModeUpdate:) name:VLVeaconModeUpdated object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(receiveVeaconNameUpdate:) name:VLVeaconNameUpdated object:nil];
}

- (void) receiveVeaconModeUpdate:(NSNotification *) notification{
    
    [self.beAVeaconSwitch setOn:NO animated:YES];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning!"
                                                        message:[[notification userInfo] objectForKey:NSLocalizedDescriptionKey]
                                                       delegate:self
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
        [alert show];
    });
}

- (void) receiveVeaconNameUpdate:(NSNotification *) notification{
    
    NSLog(@"Your device has been added to Veacon Portal as %@",[[notification userInfo] objectForKey:VLVeaconName]);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(section==0){
        return 1;
    }else{
        return 2;
    }
}

- (IBAction)logging:(id)sender {
    
    UISwitch *s = (UISwitch*)sender;
    
    [VeaconSDK setLoggingMode:[s isOn]];
    
}

- (IBAction)monitoring:(id)sender {
    
    UISwitch *s = (UISwitch*)sender;
    
    if([s isOn] && ([VeaconSDK isMonitoringActive] || [VeaconSDK isVeaconModeActive])){
        [s setOn:NO animated:YES];
    }else{
        
        NSError *err = nil;
        if([s isOn]){
            [VeaconSDK startVeaconMonitoring:&err];
        }else{
            [VeaconSDK stopVeaconMonitoring];
        }
        if(err){
            NSLog(@"%@",err);
        }
    }
}

- (IBAction)beAVeacon:(id)sender {
    UISwitch *s = (UISwitch*)sender;
    
    if([s isOn] && ([VeaconSDK isMonitoringActive] || [VeaconSDK isVeaconModeActive])){
        [s setOn:NO animated:YES];
    }else{
        
        NSError *err = nil;
        if([s isOn]){
            [VeaconSDK startVeaconMode:&err];
        }else{
            [VeaconSDK stopVeaconMode];
        }
        if(err){
            NSLog(@"%@",err);
        }
    }
}

@end
