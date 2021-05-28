//
//  FALocalStorage.h
//  4399Analysis
//
//  Created by 何聪 on 2019/7/24.
//

#import <Foundation/Foundation.h>
#import "FAAnalysisConfig.h"

static NSString * _Nullable FAAnalysisVersion = @"0.3.4";

@interface FAAnalysisManager : NSObject

/**
 用户登陆ID
 */
@property (nonatomic, copy) NSString * _Nullable uid;

/**
 游客ID
 */
@property (nonatomic, copy) NSString * _Nonnull vid;

/**
 app相关属性
 */
@property (nonatomic, strong) NSDictionary * _Nullable appInfo;

/// 环境字段(开发或者发布环境)
@property (nonatomic, copy) NSString * _Nullable env;

/// UA
@property (nonatomic, copy) NSString * _Nullable useragent;

/**
 媒体id
 */
@property (nonatomic, copy) NSString * _Nonnull mediaID;

/**
 是否对数据进行Gzip压缩(默认为YES）
 */
@property (nonatomic, assign) BOOL isGzip;

/**
 是否对数据进行加密（默认为NO，后台还未完成加密开发）
 */
@property (nonatomic, assign) BOOL isEncrypt;

/**
 是否需要打印出事件内容,默认为YES
 */
@property (nonatomic, assign) BOOL debug;

@property (nonatomic, strong) FAAnalysisConfig * _Nullable config;


+ (instancetype _Nonnull )shareManager;

- (void)sendEvent:(nonnull NSString *)event withAttributed: (nonnull NSDictionary *)attributed;

- (id _Nonnull)fetchCacheABTest:(NSString *_Nonnull)paramName defaultValue:(id _Nonnull )defaltValue;

- (void)asyncFetchABTest:(NSString *_Nonnull)paramName defaultValue:(id _Nonnull)defaltValue timeoutMillSecond:(int) timeoutMillSecond completionHandler:(void(^_Nonnull)(id _Nullable result)) completionHandler;

- (void)fastFetchABTest:(NSString *_Nonnull)paramName defaultValue:(id _Nonnull)defaltValue timeoutMillSecond:(int) timeoutMillSecond completionHandler:(void(^_Nonnull)(id _Nullable result)) completionHandler;

/**
 开始计算事件时长
 调用了这个方法的事件发送时会自动添加event_duration属性

 @param event 需要添加的事件名称
 */
- (void)startTrackEvent: (nonnull NSString *)event;

- (NSString * _Nonnull)getBaseInfo;

/**
 获取所有字段信息，通过base64+gzip压缩返回
 */
- (NSData * _Nonnull)getBasicInfo;

/**
 获取指定字段信息，通过base64+gzip压缩返回
 */
- (NSData * _Nonnull)getBasicInfo:(NSSet * _Nullable)keys;

- (NSDictionary * _Nonnull)getABTestParmDic;

@end
