//
//  VeaconSDKMapTableViewController.h
//  Veacon
//
//  Created by Furkan BAYRAKTAR on 11/9/15.
//  Copyright © 2015 Valensas. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VeaconMapViewController : UIViewController

@property (strong, nonatomic) NSString *titleString;

@property (strong, nonatomic) UIFont *titleFont;
@property (strong, nonatomic) UIFont *indicatorFont;

@property (strong, nonatomic) UIColor *titleTextColor;
@property (strong, nonatomic) UIColor *titleBackgroundColor;
@property (strong, nonatomic) UIColor *indicatorColor;
@property (strong, nonatomic) UIColor *indicatorSelectedColor;
@property (strong, nonatomic) UIColor *indicatorTextColor;
@property (strong, nonatomic) UIColor *indicatorSelectedTextColor;
@property (strong, nonatomic) UIColor *chevronDownColor;
@property (strong, nonatomic) UIColor *chevronRightColor;

@end