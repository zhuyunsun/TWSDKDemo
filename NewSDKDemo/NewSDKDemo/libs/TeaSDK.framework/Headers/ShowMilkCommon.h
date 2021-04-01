
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
UIKIT_STATIC_INLINE NSString *MY_SDK_VERSION(){
    return @"2.2.1";
}
/*
 block说明
 接口正常       result不为空
 接口访问错误    state不为空
 接口访问超时    errorFailCount整数不为5
 */
typedef void(^CompleteResult)(NSDictionary * result,NSString * state,NSString * errorFailCount);
//http请求Block回调
typedef void(^RequestSuccess)(NSDictionary * request);
typedef void(^RequestFail)(NSString * detail,NSString * errorCode);
typedef void(^OnNetWork)(NSString * info, NSInteger httpType);

typedef NS_ENUM(NSUInteger,BackState){
    BackSuccess = 0,
    Back_ing,
    BackFail,
};
typedef NS_ENUM(NSUInteger,LoginType){
    LoginTypeNone = 1,//没登录
    LoginTypeVisitor,//游客
    LoginTypeNomal,//正常登录
    LoginTypeFB,//FB登录
    LoginTypeApple//苹果登录
};
//打点事件,必接;eventName
UIKIT_STATIC_INLINE NSString* game_logined(){
    return @"game_login_completed";//点击选服界面登入游戏
}
UIKIT_STATIC_INLINE NSString* role_show(){
    return @"role_completed";//选择角色
}
UIKIT_STATIC_INLINE NSString* enter_show(){
    return @"game_completed";//进入游戏
}

@protocol LgDelegate,SerDelegate,ReDelegate;
@interface ShowMilkCommon : NSObject
@property(nonatomic,copy)NSDictionary *mgDic;
@property(nonatomic,readonly)NSString *UID;
@property(nonatomic,weak)id<LgDelegate>delegate;
@property(nonatomic,weak)id<SerDelegate>SEDelegate;
@property(nonatomic,weak)id<ReDelegate>ReDelegate;
+(ShowMilkCommon *)shareInstance;
-(void)loginAutoIN:(BOOL)isAuto;//展示登陆界面:在游戏登录界面传YES,在游戏里面切换账号传NO
-(void)hdLgView;//移除登陆和注册界面
-(void)reAutoLg;//移除自动登陆操作
-(void)bindingUser;//绑定接口:游客绑定,fb绑定,Apple绑定
-(void)userManager;//不是游客登录时,弹出用户中心(包含手机绑定和修改密码),游客状态登录该接口不会有操作
-(LoginType)getLoginType;//获取当前登录用户类型;
-(void)contactGM;//联系客服请在(登录)和(调用角色检查接口↓)后调用
-(BOOL)goToAppsDetail;//跳转APPSTORE评价
//其他接口
-(void)activThisAPP;
-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
-(void)applicationDidBecomeActive:(UIApplication *)application;
-(BOOL)application:(UIApplication *)application
             openURL:(NSURL *)url
   sourceApplication:(NSString *)sourceApplication
          annotation:(id)annotation;
-(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options;
-(BOOL)continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray *))restorationHandler;
//z   sku:内购ID,order:订单号,money:对应金额,ctext:扩展参数,adress:扩展参数 为空可传@""
-(void)showMessage:(NSString *)sku orderNum:(NSString *)order Money:(NSString *)money Ctext:(NSString *)ctext address:(NSString *)address;
//角色接口(角色进入游戏的时候调用,sid服务器id;rid,角色id)
-(void)FoxChecvbj03qfckfdgj045hDetfg0p3etfailServeaserIDh45ert:(NSString *)sid Role:(NSString *)rid CompleteBlock:(CompleteResult)block;
//公开http请求接口
- (void)FoxOpcv032enThesdfn9e42Requessdf921dtPdsf9arm2wednovas:(NSDictionary *)dict url:(NSString *)url successBlock:(RequestSuccess)success failBlock:(RequestFail)Fail netWorkBlock:(OnNetWork)network;
- (NSString *)FoxAesHaner5ftj0q3edleStringgf3qwmdp0:(NSString *)aes passWord:(NSString *)password;
//打点事件,count没有值得时候传@""
-(void)enterGameEventRoleID:(NSString *)rid andSid:(NSString *)sid eventName:(NSString *)event count:(NSString *)count;
//推送通知方法
-(void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

//激励广告的初始化,需要账号登录成功之后,在角色进入游戏的时候调用:sid服务器ID,rid角色ID
-(void)ironSourceInitSid:(NSString *)sid rid:(NSString *)rid;
//激励广告接口:需要canShowRewardVideo协议回调之后才可以调用该接口,placeName  CP透传参数
-(void)loadRewordVideo:(NSString *)placeName;
@end
//登陆状态的回调
@protocol LgDelegate <NSObject>
@optional
-(void)logSuccess:(NSString *)uid;
-(void)logFail;
@end
//z的回调
@protocol SerDelegate <NSObject>
@optional
-(void)serCode:(BackState)state;
@end

@protocol ReDelegate <NSObject>
@optional
/*
 初始化成功,加载完成;
 在这个方法回调之后再调用
 //激励广告接口
  -(void)loadRewordVideo:(NSString *)placeName;
 否则不会有展示
 */
-(void)canShowRewardVideo;
///播放错误
-(void)loadFailRewadVideo:(NSError *)error;
/// 正常播放完毕,应该在这里发放奖励
-(void)didReceiveRewadVideo;
/// 视频已经被关闭
-(void)didCloseVideo;
///视频已经打开
-(void)didOpenVideo;
///视频开始播放
-(void)beginVideo;
///视频播放完毕
-(void)endVideo;
///视频播放完毕之后被点击
-(void)didClickVideo;
@end
NS_ASSUME_NONNULL_END
