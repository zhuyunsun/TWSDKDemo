//
//  ViewController.m
//  NewSDKDemo
//
//  Created by zhuyun on 2019/4/3.
//  Copyright © 2019 project. All rights reserved.
//

#import "ViewController.h"
#import <TeaSDK/ShowMilkCommon.h>
@interface ViewController ()<LgDelegate,SerDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CGFloat count = 70;
    self.view.backgroundColor = [UIColor blackColor];
    UIImageView *image = [[UIImageView alloc]init];
    image.image = [UIImage imageNamed:@"123"];
    [self.view addSubview:image];
    image.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height);
    
    UIButton *showLogin = [UIButton buttonWithType:UIButtonTypeCustom];
    showLogin.frame = CGRectMake(0, 0, 80, 35);
    showLogin.center = CGPointMake(self.view.center.x, self.view.center.y - count *2);
    showLogin.backgroundColor = [UIColor whiteColor];
    [showLogin setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [showLogin setTitle:@"Login" forState:UIControlStateNormal];
    [showLogin addTarget:self action:@selector(loginAction) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:showLogin];
    
    UIButton *payButton = [UIButton buttonWithType:UIButtonTypeCustom];
    payButton.frame = CGRectMake(0, 0, 80, 35);
    payButton.center = CGPointMake(self.view.center.x, self.view.center.y - 70);
    payButton.backgroundColor = [UIColor whiteColor];
    [payButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [payButton setTitle:@"pay" forState:UIControlStateNormal];
    [payButton addTarget:self action:@selector(payAction) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:payButton];
    
    
    //游客绑定ID成为新的账号;
    UIButton *bindButton = [UIButton buttonWithType:UIButtonTypeCustom];
    bindButton.frame = CGRectMake(0, 0, 80, 35);
    bindButton.center = CGPointMake(self.view.center.x, self.view.center.y);;
    bindButton.backgroundColor = [UIColor whiteColor];
    [bindButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [bindButton setTitle:@"bind" forState:UIControlStateNormal];
    [bindButton addTarget:self action:@selector(bindButtonAction) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:bindButton];
    
    
    
    UIButton *gmButton = [UIButton buttonWithType:UIButtonTypeCustom];
    gmButton.frame = CGRectMake(0, 0, 180, 35);
    gmButton.center = CGPointMake(self.view.center.x - 100, self.view.center.y + count);;
    gmButton.backgroundColor = [UIColor whiteColor];
    [gmButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [gmButton setTitle:@"manager" forState:UIControlStateNormal];
    [gmButton addTarget:self action:@selector(gmButtonAction) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:gmButton];
    
    UIButton *gmButton1 = [UIButton buttonWithType:UIButtonTypeCustom];
    gmButton1.frame = CGRectMake(0, 0, 80, 35);
    gmButton1.center = CGPointMake(self.view.center.x + 100, self.view.center.y + count);;
    gmButton1.backgroundColor = [UIColor whiteColor];
    [gmButton1 setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [gmButton1 setTitle:@"GM" forState:UIControlStateNormal];
    [gmButton1 addTarget:self action:@selector(gmAction) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:gmButton1];

    
    UIButton *niceButton = [UIButton buttonWithType:UIButtonTypeCustom];
    niceButton.frame = CGRectMake(0, 0, 80, 35);
    niceButton.center = CGPointMake(self.view.center.x, self.view.center.y + count *2);;
    niceButton.backgroundColor = [UIColor whiteColor];
    [niceButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [niceButton setTitle:@"五星好评" forState:UIControlStateNormal];
    [niceButton addTarget:self action:@selector(niceButtonAction) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:niceButton];

}
-(void)gmAction{
    [[ShowMilkCommon shareInstance] contactGM];
}
-(void)niceButtonAction{
    [[ShowMilkCommon shareInstance] goToAppsDetail];
}
-(void)gmButtonAction{
    [[ShowMilkCommon shareInstance] userManager];
}
-(void)bindButtonAction{
    [[ShowMilkCommon shareInstance] bindingUser];
}
-(void)loginAction{
    //    [[ShowLogin shareInstance] removeAutoLogin];
    [[ShowMilkCommon shareInstance] loginAutoIN:YES];
    [ShowMilkCommon shareInstance].delegate = self;
}
-(void)payAction{
    //这里填写正确的支付信息
    NSString *oderNumber = [NSString stringWithFormat:@"%u",arc4random() % 10000 + 100000000];
    dispatch_queue_t concurrent1 = dispatch_queue_create("concurrent1", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(concurrent1, ^{
        [[ShowMilkCommon shareInstance] showMessage:@"com.th.zgws.89" orderNum:oderNumber Money:@"6" Ctext:@"qeqe" address:@"eqe"];
        [ShowMilkCommon shareInstance].SEDelegate = self;

    });

}
//delegate
-(void)logSuccess:(NSString *)uid{
    NSLog(@"登陆成功返回uid=%@",uid);
    NSLog(@"type = %ld",[[ShowMilkCommon shareInstance] getLoginType]);
    [[ShowMilkCommon shareInstance] FoxChecvbj03qfckfdgj045hDetfg0p3etfailServeaserIDh45ert:@"123444" Role:@"123213213" CompleteBlock:^(NSDictionary * _Nonnull result, NSString * _Nonnull state, NSString * _Nonnull errorFailCount) {
        NSLog(@"1232321");
    }];
}
-(void)logFail{
    NSLog(@"登陆失败");
}

-(void)serCode:(BackState)state{
    if (state == BackSuccess) {
        //success
    }
    if (state == BackFail) {
        //fail
    }
    if (state == Back_ing) {
        //支付ing
    }
}
@end
