
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
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
    LoginTypeFB//FB登录
};
@protocol LgDelegate,SerDelegate;
@interface ShowMilkCommon : NSObject
//NSDictionary *initDict = @{@"Client_id": @"1046",
//@"Client_secret": @"jHm90pQBwp8BDie8KLqixw==",
//@"AppleID": @"1239295387",
//@"Domain_Dev": @"api",
//@"Domain_Dis": @"api",
//@"Language": @"Auto",
//@"Currency": @"USD"
//};
//msgDic参数例子
@property(nonatomic,copy)NSDictionary *mgDic;
@property(nonatomic,readonly)NSString *UID;
@property(nonatomic,weak)id<LgDelegate>delegate;
@property(nonatomic,weak)id<SerDelegate>SEDelegate;
+(ShowMilkCommon *)shareInstance;
//在游戏登录界面传YES,在游戏里面切换账号传NO
-(void)loginAutoIN:(BOOL)isAuto;//展示登陆界面
-(void)hdLgView;//移除登陆和注册界面
-(void)reAutoLg;//移除自动登陆操作
-(void)bindingUser;//游客绑定ID成为新的账号,只有当前登录的账号为游客才会有界面弹出;
-(LoginType)getLoginType;//获取当前登录用户类型;
-(void)contactGM;//联系客服请在(登录)和(调用角色检查接口↓)后调用
-(BOOL)goToAppsDetail;//跳转APPSTORE评价
-(void)activThisAPP;
//其他接口
-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
-(void)applicationDidBecomeActive:(UIApplication *)application;
-(BOOL)application:(UIApplication *)application
             openURL:(NSURL *)url
   sourceApplication:(NSString *)sourceApplication
          annotation:(id)annotation;
-(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options;
-(BOOL)continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray *))restorationHandler;
//z
-(void)showMessage:(NSString *)sku orderNum:(NSString *)order Money:(NSString *)money Ctext:(NSString *)ctext address:(NSString *)address;
//角色检查接口
-(void)FoxChecvbj03qfckfdgj045hDetfg0p3etfailServeaserIDh45ert:(NSString *)sid Role:(NSString *)rid CompleteBlock:(CompleteResult)block;
//公开http请求接口
- (void)FoxOpcv032enThesdfn9e42Requessdf921dtPdsf9arm2wednovas:(NSDictionary *)dict url:(NSString *)url successBlock:(RequestSuccess)success failBlock:(RequestFail)Fail netWorkBlock:(OnNetWork)network;
- (NSString *)FoxAesHaner5ftj0q3edleStringgf3qwmdp0:(NSString *)aes passWord:(NSString *)password;
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
NS_ASSUME_NONNULL_END
