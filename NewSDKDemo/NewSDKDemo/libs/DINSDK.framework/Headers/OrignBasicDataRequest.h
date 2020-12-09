#import <Foundation/Foundation.h>
#import "HTTPClient.h"

typedef void(^SuccessBlock)(NSDictionary *result);
typedef void(^FailedBlock)(NSString *info, NSString *errorCode);
typedef void(^NetworkErrorBlock)(NSString *info, HTTPClientResponseType httpType);

@interface OrignBasicDataRequest : NSObject

+ (void) requestWithParams:(NSDictionary *)params urlString:(NSString *)url successBlock:(SuccessBlock)success failedBlock:(FailedBlock)failed networkError:(NetworkErrorBlock)networkError;

+ (void) requestWithParams:(NSDictionary *)params urlString:(NSString *)url operationQueue:(NSOperationQueue *)operationQueue successBlock:(SuccessBlock)success failedBlock:(FailedBlock)failed networkError:(NetworkErrorBlock)networkError;

@end
