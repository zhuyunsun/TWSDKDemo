#import <Foundation/Foundation.h>
#import "UIImageView+WebCache.h"
#import "SDAnimatedImageRep.h"
#import "SDImageCache.h"
#import "SDImageCacheConfig.h"
#import "SDWebImageCoder.h"
#import "SDWebImageCoderHelper.h"
#import "SDWebImageCodersManager.h"
#import "SDWebImageCompat.h"
#import "SDWebImageDownloader.h"
#import "SDWebImageDownloaderOperation.h"
#import "SDWebImageFrame.h"
#import "SDWebImageGIFCoder.h"
#import "SDWebImageImageIOCoder.h"
#import "SDWebImageManager.h"
#import "SDWebImageOperation.h"
#import "SDWebImagePrefetcher.h"
#import "SDWebImageTransition.h"


@interface DINProject : NSObject
@property (nonatomic)BOOL isTW;
@property(nonatomic,assign)BOOL fromHanguo;//是否是给韩国用的SDK
+ (DINProject *)defaultManager;

- (void)openTheImSeverAction:(NSString *)gameid roleid:(NSString *)roleid serverid:(NSString *)serverid userid:(NSString *)userid;

@end
