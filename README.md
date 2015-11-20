VEACON SDK
=========
Veacon is a low-powered, low-cost iBeacon transmitter that can notify nearby devices of its presence. Veacons turn any physical location into a beacon transmitting data to iOS devices. VeaconSDK provides the simplest way to you in order to connect your application to our veacon portal. For more information about Veacons please visit [veacon.com].

Current Version
----
0.3.2

Installation with CocoaPods
-----------
CocoaPods is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like VeaconSDK in your projects. You can add the following lines to your pod file. For more information please visit [CocoaPods].
#### Podfile

```podfile
pod 'VeaconSDK'
```
Requirements
-------
VeaconSDK requires devices that have Bluetooth 4.0 LE support and iOS 7.0 or above. Other devices that below this specification are not supported by VeaconSDK.

In order to use VeaconSDK, you must have an account on [Veacon Portal]. After you create your account, you can get your secret key from portal.

Usage
------
VeaconSDK contains a single .h file. Once you integrate the VeaconSDK to your project, you can start to use it by importing  VeaconSDK.h.
#### Initialization
Insert the import statement to your AppDelegate as following:
```c
#import <UIKit/UIKit.h>
#import <VeaconSDK.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, VeaconDelegate>

@property (strong, nonatomic) UIWindow *window;

@end
```
Now, we can initialize the VeaconSDK. In order to initialize VeaconSDK, you must have your secret key. In AppDelegate.m, locate the “application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)” method and add the initialization code as following:
```c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [VeaconSDK configureWithSecretKey:@"XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX"];

    //Your initialization code here...
    
    return YES;
}
```
Now, your application is ready to receive Veacon signals. The only thing you need to do in order to receive signals is enabling the detection mode.

There are a couple of optional configurations you can use in your entire application. You can open or close the logging mode and you can set a delegate object in order to receive custom actions you entered from the Veacon portal. You can also get notified when the user disables device’s Bluetooth.
#### Map Feature
Map feature is used to display a map and Veacon locations for indoor navigation. You can add maps to your project from [veacon.com]. To enable this feature on your iOS project, use the following lines:
```c
#import <Veacon/VeaconMapViewController.h>
```
```c
VeaconMapViewController *mapViewController = [VeaconMapViewController new];
[self.navigationController pushViewController:mapViewController animated:YES];
```
If any connection problem occurs or you do not have any maps created in Veacon portal, you can track these situations with the following delegate methods.
```c
- (void) veaconMapViewController:(VeaconMapViewController*)veaconMapViewController numberOfMapsInServiceResponse:(NSInteger)count;
- (void) veaconMapViewController:(VeaconMapViewController*)veaconMapViewController serviceRespondedWithErrorCode:(NSInteger)code;
```
#### Logging Mode
Logging mode is used for debugging. When the logging mode enabled, each time application sees a Veacon change around it, Veacon Portal sends a custom event which contains information about the Veacon. By this way, you can simply debug your application without creating scenarios on Veacon Portal.

In order to enable Logging mode, modify your code as following:
```c
[VeaconSDK setLoggingMode:YES];   
```
#### VeaconDelegate
You can implement the VeaconDelegate protocol in order to get custom actions you entered as scenario from Veacon Portal. To do so, add the following code to your application:
```c
@interface AppDelegate : UIResponder <UIApplicationDelegate, VeaconDelegate>
```
By implementing VeaconDelegate, you need to write two new functions to your application.

* -- (void) customVeaconAction:(NSString*)key data:(NSDictionary *)data;
* -- (void) bluetoothDisabledAction;

The following code simply handles the custom action comes from Logging Mode as an example.
```c
- (void)customVeaconAction:(NSString *)key data:(NSDictionary *)data{
    if ([key isEqualToString:@"log"]) {
        NSString *veaconName = [data valueForKeyPath:@"entry.veacon.name"];
        NSNumber *veaconId = [data valueForKeyPath:@"entry.veacon.sequence"];
        NSString *proximity = [data valueForKeyPath:@"entry.proximity"];
        
        NSLog(@"Veacon #%@ (%@) - %@", veaconId, veaconName, proximity);
    }
}
```
To handle Bluetooth changes, we implemented the second function which displays an alert view.
```c
- (void) bluetoothDisabledAction{
    UIAlertView *message = [[UIAlertView alloc]
                            
                            initWithTitle:@"VeaconSDK!"
                            message:@"Bluetooth is disabled. Veacon needs Bluetooth to be enabled."
                            delegate:nil
                            cancelButtonTitle:@"OK"
                            otherButtonTitles:nil];
    
    [message show];
}
```
#### Veacon Monitoring
In order to detect Veacons around your application, you need to start Veacon monitoring. Once you start monitoring, you will start to get actions that you defined in the Veacon Portal. If not, at least you will get logs if you enabled LoggingMode. To start or stop Veacon monitoring, add the following lines to your code:
```c
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
```
##### Important note: If your application uses geolocation features, because Apple restricts the total number of CLRegion objects that an application uses, monitoring may fail.
#### Veacon Mode
You may want to turn your device into a Veacon device. After you turn your device into a Veacon, you can assign scenarios to it from Veacon portal with its device name. In order to enable Veacon Mode, add the following lines of code to your application:
```c
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
```
##### Important Note: Veacon mode and monitoring cannot be run at the same time. You must check whether a mode is running or not and try to start a mode. Otherwise, you will get an error.
#### Error Handling
Because of the network communications, sometimes errors are sent through NSNotificationCenter. You can keep track of possible notifications as following:
```c
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(receiveVeaconModeUpdate:) name:VLVeaconModeUpdated object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(receiveVeaconNameUpdate:) name:VLVeaconNameUpdated object:nil];
}

- (void) receiveVeaconModeUpdate:(NSNotification *) notification{
    
    [self.beAVeaconSwitch setOn:NO animated:YES];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        UIAlertView *alert = [[UIAlertView alloc]
                              initWithTitle:@"Warning!"
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
```
Sample Project
----
You can find the sample project that is used to create this documentation under Example folder in this repository.
License
----
See LICENSE file

[veacon.com]:http://veacon.com
[Veacon Portal]:http://portal.veacon.com
[CocoaPods]:http://cocoapods.org
