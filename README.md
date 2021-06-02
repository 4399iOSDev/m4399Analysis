

# m4399Analysis

## 1. 安装

- 将`m4399Analysis.xcframework`引入工程

- 在**General**->**Framworks, Libraries, and Embedded Content**中将`m4399Analysis.xcframework`设置为**Embed&Sign**，如下图：

  ![image-20210218172029216](./img/image-20210218172029216.png)

##2. 使用

### 2.1 导入

- Swift : `import m4399Analysis`
- Objc : `#import <m4399Analysis/FAAnalysisManager.h>`

### 2.2 使用

####2.2.1 合规文案

您需要在《隐私政策》中告知用户集成了4399数据分析SDK，可以参考以下文案：

> “我们使用了4399数据分析SDK，采集您的 IDFA 信息，用于统计分析您在 App 内的使用效果。”

#### 2.2.2 初始化

- objective-c

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // 判断是否第一次打开 App，如果是进入隐私协议相关代码
    if (<#第一次打开 App || 非第一次打开 App 但尚未同意用户协议#>) {
        // 隐私协议弹窗相关逻辑
        if (<#同意用户协议#>) {
           // vid设置
                [FAAnalysisManager shareManager].vid = @"vid";
                // 媒体ID设置
                [FAAnalysisManager shareManager].mediaID = @"mediaId";
        }
    } else {
             // vid设置
            [FAAnalysisManager shareManager].vid = @"vid";
            // 媒体ID设置
            [FAAnalysisManager shareManager].mediaID = @"mediaId"; 
    }
        ...
    return YES;
}
```

- swift

```swift
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    // 判断是否第一次打开 App，如果是进入隐私协议相关代码
    if (<#第一次打开 App || 非第一次打开 App 但尚未同意用户协议#>) {
        // 隐私协议弹窗相关逻辑
        if (<#同意用户协议#>) {
            // vid设置
                    FAAnalysisManager.share().vid = "vid"
                    // 媒体ID设置
                        FAAnalysisManager.share().mediaID = "mediaId"
        }
    } else {
        // vid设置
            FAAnalysisManager.share().vid = "vid"
            // 媒体ID设置
                FAAnalysisManager.share().mediaID = "mediaId"
    }
        ...
    return true
}
```

#### 2.2.3 发送埋点

以发送一个**download**事件为例，其中包含**gameId**和**gameName**

- objective-c

```objective-c
[[FAAnalysisManager shareManager] sendEvent:@"download" withAttributed:@{@"gameId": @1, @"gameName": @"test"}];
```

- swift

```swift
FAAnalysisManager.share().sendEvent("download", withAttributed: ["gameId" : 1, "gameName" : "test"])
```

#### 2.2.4 用户登录

- objective-c

```objective-c
[FAAnalysisManager shareManager].uid = @"uid";
```

- swift 

```swift
FAAnalysisManager.share().uid = "uid"
```

为了准确记录登录用户的行为信息，建议在以下时机各调用一次:

- 用户在注册成功时
- 用户登录成功时

- 已登录用户每次启动 App 时

#### 2.2.5 AB测试

以获取一个**expParam**实验参数为例，其中**defaultValue**为变量默认值、**timeoutMillSecond**为超时时间、**result**为获取结果

- objective-c

```objective-c
//读取本地缓存，缓存不存在时使用默认值
id result = [[FAAnalysisManager shareManager] fetchCacheABTest:@"expParam" defaultValue:defaultValue];

//忽略本地缓存，从服务端获取数据
[[FAAnalysisManager shareManager] asyncFetchABTest:@"expParam" defaultValue:defaultValue timeoutMillSecond:timeoutMillSecond completionHandler:^(id  _Nullable result) {
    //TODO:业务代码
}];

//优先读取本地缓存，缓存不存在时从服务端获取数据
[[FAAnalysisManager shareManager] fastFetchABTest:@"expParam" defaultValue:defaultValue timeoutMillSecond:timeoutMillSecond completionHandler:^(id  _Nullable result) {
    //TODO:业务代码
}];
```

- swift 

```swift
//读取本地缓存，缓存不存在时使用默认值
let result = FAAnalysisManager.share().fetchCacheABTest("expParam", defaultValue: defaultValue)

//忽略本地缓存，从服务端获取数据
FAAnalysisManager.share().asyncFetchABTest("expParam", defaultValue: defaultValue, timeoutMillSecond: timeoutMillSecond) { (result) in
    //TODO:业务代码
}

//优先读取本地缓存，缓存不存在时从服务端获取数据
FAAnalysisManager.share().fastFetchABTest("expParam", defaultValue: defaultValue, timeoutMillSecond: timeoutMillSecond) { (result) in
    //TODO:业务代码
}
```

## Author

hecong@4399inc.com

## License

m4399Analysis is available under the MIT license. See the LICENSE file for more info.

