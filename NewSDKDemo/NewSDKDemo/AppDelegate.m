//
//  AppDelegate.m
//  NewSDK1
//
//  Created by zhuyun on 2019/4/1.
//  Copyright © 2019 project. All rights reserved.
//

#import "AppDelegate.h"
#import <TeaSDK/ShowMilkCommon.h>
#import "ViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
//    NSDictionary *initDict = @{@"Client_id": @"1094700",
//                               @"Client_secret": @"L6JMm3XBGpKdPQMqtLoNEA==",
//                               @"AppleID": @"1524404900",
//                               @"Language": @"TH",
//                               @"Currency": @"USD",
//                               @"RewardKey":@"f1a2ca89"
//                               };
//
    NSDictionary *initDict = @{@"Client_id": @"1095700",
                               @"Client_secret": @"lzFj4bQac1DfHDSSVLyyWg==",
                               @"AppleID": @"1540545758",
                               @"Language": @"TH",
                               @"Currency": @"USD",
                               @"RewardKey":@"f1a2ca89"
                               };
    [[ShowMilkCommon shareInstance] ironSourceInitRewardKey:@"ef32b641"];
    [ShowMilkCommon shareInstance].mgDic = initDict;
    [[ShowMilkCommon shareInstance] application:application didFinishLaunchingWithOptions:launchOptions];
    ViewController *VC = [[ViewController alloc]init];
    self.window.rootViewController = VC;

    return YES;
}

//fb1464411776911449
- (void)applicationDidBecomeActive:(UIApplication *)application {

    //Track Installs
    [[ShowMilkCommon shareInstance] applicationDidBecomeActive:application];
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    return [[ShowMilkCommon shareInstance] application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options
{
    return [[ShowMilkCommon shareInstance] application:app openURL:url options:options];
}

- (BOOL) application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray *_Nullable))restorationHandler
{
    [[ShowMilkCommon shareInstance] continueUserActivity:userActivity restorationHandler:restorationHandler];
    return YES;
}
-(void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken{
    [[ShowMilkCommon shareInstance] application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error{
    NSLog(@"通知error = %@",error);
}
@end
