#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

FOUNDATION_STATIC_INLINE NSString* FOXSDKVERSION(){
    NSString *VERSION = @"1.0.0";
    NSLog(@"TW__版本 = %@",VERSION);
    return VERSION;
}

//用户信息block处理
/*
 block说明
 接口正常       result不为空
 接口访问错误    state不为空
 接口访问超时    errorFailCount整数不为5
 */
typedef void(^CompleteResult)(NSDictionary * result,NSString * state,NSString * errorFailCount);


typedef NS_ENUM(NSInteger,payBackCode){
    payBackCode_success = 0,
    payBackCode_Paying,
    payBackCode_Fail,
};
//支付block处理
/*
 block说明
         储值行为非正常时   state!=nil
         储值行为正常时     state == nil
 */
typedef void(^payResult)(NSString * state,NSInteger payBackCode);


//http请求Block回调
typedef void(^RequestSuccess)(NSDictionary * request);
typedef void(^RequestFail)(NSString * detail,NSString * errorCode);
typedef void(^OnNetWork)(NSString * info, NSInteger httpType);

@interface FoxServer : NSObject

/*参数dict 传输例子@{ @"Client_id":@"1057",
                    @"Client_secret":@"DM2yxz2CJd80wecFLJYasg==",
                    @"AppleID":@"12345678",
                    @"Currency":@"USD",
 };
*/

@property (nonatomic,copy)NSDictionary * foxDict;

@property (nonatomic,strong)NSString * sdkUid;

@property (nonatomic,assign)int action_count;

+ (FoxServer *)getStartServer;


-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;



-(void)applicationDidBecomeActive:(UIApplication *)application;


- (BOOL) application:(UIApplication *)application
             openURL:(NSURL *)url
   sourceApplication:(NSString *)sourceApplication
          annotation:(id)annotation;

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options;

- (BOOL) continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray *))restorationHandler;


-(void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;



/*
 登陆接口传输
 参数 userid    用户名
     passWord  密码 (传未加密的原码)
 block说明
         userid   !=nil 表示登陆成功返回Uid
         state    !=nil 表示登陆失败返回错误码 根据错误码来调整UI
         httpType !=nil 表示登陆接口超时 调整UI
 */
-(void)strucknineonMondaymorning:(NSString *)userid PassWord:(NSString *)passWord Completion:(void(^)(NSString * state,NSString * userid,NSString * httpType))block;



/*
 注册接口传输
 参数   userid   用户名
       passWord 密码 (传未加密的原码)
       email    邮箱
 
 block说明
 userid   !=nil 表示登陆成功返回Uid
 state    !=nil 表示登陆失败返回错误码 根据错误码来调整UI
 httpType !=nil 表示登陆接口超时 调整UI
 */
-(void)FlintwinchOfTheCutDownAspect:(NSString *)userid PassWord:(NSString *)passWord Email:(NSString *)email Completion:(void(^)(NSString * state,NSString * userid,NSString * httpType))block;


//fb用户登录接口
// 当result值不为空时 接口正常返回
// 当errorCode不等于0的时候表示接口返回错误码
// 当httpType不等于0的时候表示接口超时并返回超时detail
-(void)sameAustereAirOfLuxuriousness:(NSDictionary *)fb_profile CompltBlock:(void(^)(NSDictionary * result,NSInteger errorCode,NSString * errorDetail,NSInteger httpType))block;



//角色检查接口 block说明请看5-10
-(void)SittingWithHerHandsLaid:(NSString *)sid Role:(NSString *)rid  useriid:(NSString *)userid CompleteBlock:(CompleteResult)block;



//内购支付接口
-(void)tallCabinetToweringBefore:(NSString *)sku userid:(NSString *)userid orderNum:(NSString *)order Money:(NSString *)money productName:(NSString *)name Ctext:(NSString *)ctext callBackAddress:(NSString *)address PayBlock:(payResult)block;


//公开http请求接口
- (void)openedaDrawerOrTwoLooked:(NSDictionary *)dict url:(NSString *)url successBlock:(RequestSuccess)success failBlock:(RequestFail)Fail netWorkBlock:(OnNetWork)network;


- (NSString *)inclinedToEnterUponBusiness:(NSString *)aes passWord:(NSString *)password;


//google登陆接口
//登陆成功返回result和fb接口处理一样 外部调用获得userid后请调用af统计登陆和注册事件
-(void)FoxloginGoogleWith:(NSString *)googleuid googleEmail:(NSString *)googleEmail gameid:(NSString *)gameid CompltBlock:(void(^)(NSDictionary * result,NSString *errorCode,NSString * errorDetail,NSInteger httpType))block;
#warning Update Message 增加内购回调地址

@end
