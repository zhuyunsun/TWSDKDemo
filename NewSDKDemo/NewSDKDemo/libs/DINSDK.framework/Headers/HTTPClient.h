#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, HTTPClientResponseType) {
    HTTPClientResponseTypeNone = 0,//未知错误
    HTTPClientResponseTypeSuccess = 1,//响应成功
    HTTPClientResponseTypeServerError = 2,//服务器错误
    HTTPClientResponseTypeNetworkError = 3,//无网络，或网络超时
    HTTPClientResponseTypeForbidden = 4//服务器拒绝访问
};

@interface HTTPClient : NSObject

@property (strong, nonatomic, readonly) NSURL *baseURL;
@property (strong, nonatomic, readonly) NSOperationQueue *operationQueue;

- (id)initWithBaseURL:(NSURL *)baseURL
       operationQueue:(NSOperationQueue *)operationQueue;
- (void)postWithParams:(NSDictionary *)params
    complete:(void (^)(HTTPClientResponseType, NSData *data, NSError *error, NSInteger))completionBlock;

@end
