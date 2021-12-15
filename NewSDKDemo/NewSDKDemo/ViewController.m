//
//  ViewController.m
//  NewSDKDemo
//
//  Created by zhuyun on 2019/4/3.
//  Copyright © 2019 project. All rights reserved.
//

#import "ViewController.h"
#import <TeaSDK/ShowMilkCommon.h>
@interface ViewController ()<LgDelegate,SerDelegate,ReDelegate,UITableViewDelegate,UITableViewDataSource>{
    UITableView *demoTable;
    NSArray *dataSource;
    
    UITextView *msgView;
}
@property(nonatomic)BOOL loadDone;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor lightGrayColor];
//    UIImageView *image = [[UIImageView alloc]init];
//    image.image = [UIImage imageNamed:@"123"];
//    [self.view addSubview:image];
//    image.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height);
    
    
    
    [ShowMilkCommon shareInstance].ReDelegate = self;
    self.loadDone = NO;
    
    dataSource = @[@"Login没有UI,默认登陆",@"LoginUI",@"pay",@"bind",@"用户中心",
                   @"GM",@"五星好评",@"初始化激励广告",
                   @"展示激励广告",@"当前登录用户类型"];
    
    CGFloat width = [UIScreen mainScreen].bounds.size.width;
    CGFloat height = [UIScreen mainScreen].bounds.size.height;
    demoTable = [[UITableView alloc]init];
    demoTable.frame = CGRectMake(0,0, width *0.55,height *0.8);
    demoTable.center = self.view.center;
    demoTable.delegate = self;
    demoTable.dataSource = self;
    demoTable.layer.cornerRadius = 5;
    [self.view addSubview:demoTable];
    
    msgView = [[UITextView alloc]init];
    msgView.frame = CGRectMake(CGRectGetMaxX(demoTable.frame), CGRectGetMinY(demoTable.frame), width *0.2, height *0.8);
    msgView.layer.cornerRadius = 5;
    msgView.layer.borderColor = [[UIColor blackColor] CGColor];
    msgView.layer.borderWidth = 1;
    msgView.editable = NO;
    [self.view addSubview:msgView];
    
}
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    NSUInteger index = indexPath.row;
    [ShowMilkCommon shareInstance].delegate = self;
    if (index == 0) {
        [[ShowMilkCommon shareInstance] loginDefaultStyle];
        
    }

    if (index == 1) {
        [[ShowMilkCommon shareInstance] loginAutoIN:YES];
        
    }
    if (index == 2) {
        //这里填写正确的支付信息
        dispatch_queue_t concurrent1 = dispatch_queue_create("concurrent1", DISPATCH_QUEUE_CONCURRENT);
        dispatch_async(concurrent1, ^{
            NSInteger num = arc4random() % 100000 + 10000000000;
            NSString *order = [NSString stringWithFormat:@"%ld",num];
            [[ShowMilkCommon shareInstance] showMessage:@"com.dummy.th.29" orderNum:order Money:@"29.00" Ctext:@"qeqe" address:@"eqe"];
            [ShowMilkCommon shareInstance].SEDelegate = self;

        });
    }
    if (index == 3) {
        [[ShowMilkCommon shareInstance] bindingUser];
    }
    if (index == 4) {
        [[ShowMilkCommon shareInstance] userManager];
    }
    if (index == 5) {
        [[ShowMilkCommon shareInstance] contactGM];
    }
    if (index == 6) {
        [[ShowMilkCommon shareInstance] goToAppsDetail];
    }
    if (index == 7) {
        
    }
    if (index == 8) {
//        if (self.loadDone == NO) {
//            NSLog(@"等待视频加载完成");
//            return;
//        }
        [[ShowMilkCommon shareInstance] loadRewordVideo:@"cp传的扩展字段" sid:@"001" rid:@"0988e312312"];
    }
    if (index == 9) {
        LoginType type = [[ShowMilkCommon shareInstance] getLoginType];NSLog(@"type = %ld",type);
    }

}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return dataSource.count;
}
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 49;
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *myStr = @"ownStr";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:myStr];
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:myStr];
    }
    if (indexPath.row < dataSource.count) {
        cell.textLabel.text = dataSource[indexPath.row];
    }
    return cell;
}
//delegate
-(void)logSuccess:(NSString *)uid{
    NSLog(@"登陆成功返回uid=%@",uid);
    NSString *loginType = @"没有登录";
    LoginType type = [[ShowMilkCommon shareInstance] getLoginType];
    if (type == LoginTypeVisitor) {
        loginType = @"游客登陆";
    }
    if (type == LoginTypeNomal) {
        loginType = @"账号密码登陆";
    }
    if (type == LoginTypeApple) {
        loginType = @"苹果登陆";
    }
    if (type == LoginTypeFB) {
        loginType = @"FB登陆";
    }

    NSDate *date = [NSDate date];
    NSDateFormatter *f = [[NSDateFormatter alloc]init];
    f.timeStyle = NSDateFormatterLongStyle;
    NSString *str = [f stringFromDate:date];
    msgView.text = [NSString stringWithFormat:@"时间:%@\n\n登陆方式:%@\n\n登陆成功返回用户uid=%@",str,loginType,uid];
    NSLog(@"type = %ld",[[ShowMilkCommon shareInstance] getLoginType]);
    [[ShowMilkCommon shareInstance] FoxChecvbj03qfckfdgj045hDetfg0p3etfailServeaserIDh45ert:@"123444" Role:@"123213213" CompleteBlock:^(NSDictionary * _Nonnull result, NSString * _Nonnull state, NSString * _Nonnull errorFailCount) {
        NSLog(@"1232321");
    }];
    [[ShowMilkCommon shareInstance] enterGameEventRoleID:@"1" andSid:@"2" eventName:game_logined() count:@""];
}
-(void)logFail{
    NSLog(@"登陆失败");
    msgView.text = @"登陆失败";
}
-(void)serCode:(BackState)state{
    if (state == BackSuccess) {
        //success
        NSLog(@"支付成功");
        msgView.text = @"支付成功";
    }
    if (state == BackFail) {
        //fail
        NSLog(@"支付失败");
        msgView.text = @"支付失败";
    }
    if (state == Back_ing) {
        //支付ing
        NSLog(@"支付ing");
        msgView.text = @"支付ing";
    }
}

#pragma mark ReDelegate
///加载完成;
-(void)canShowRewardVideo{
//    self.loadDone = YES;
}
///播放错误
-(void)loadFailRewadVideo:(NSError *)error{
    NSLog(@"播放错误error = %@",error);
}
/// 正常播放完毕,应该在这里发放奖励
-(void)didReceiveRewadVideo{
    NSLog(@"播放完毕");
}
/// 视频已经被关闭
-(void)didCloseVideo{
    NSLog(@"关闭视频");
}
///视频已经打开
-(void)didOpenVideo{
    NSLog(@"已经打开");
}
///视频开始播放
-(void)beginVideo{
    NSLog(@"视频开始播放");
}
///视频播放完毕
-(void)endVideo{
    NSLog(@"视频播放完毕");
}
///视频播放完毕之后被点击
-(void)didClickVideo{
    NSLog(@"视频播放完毕之后被点击");}

@end
