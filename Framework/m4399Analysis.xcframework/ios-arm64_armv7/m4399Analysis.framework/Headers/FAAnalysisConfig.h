//
//  FAAnalysisConfig.h
//  m4399Analysis
//
//  Created by 何聪 on 2019/9/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FAAnalysisConfig : NSObject<NSCoding>

/// 缓冲区大小（条数）
@property (nonatomic, assign) NSInteger flushBuffSize;

/// 缓冲区间隔（时间）
@property (nonatomic, assign) NSInteger flushInterval;

/// 进入后台后多久发送进入后台事件
@property (nonatomic, assign) NSInteger sessionInterval;

@property (nonatomic, strong) NSArray *events;

@property (nonatomic, assign) BOOL verifyVid;

@property (nonatomic, assign) BOOL autoTrace;

@property (nonatomic, assign) BOOL debuggable;

@property (nonatomic, assign) BOOL useHeartbeat;

- (instancetype)initWithDic: (NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
