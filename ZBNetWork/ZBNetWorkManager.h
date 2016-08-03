//
//  ZBNetWorkManager.h
//  ZBNetWork
//
//  Created by 张博 on 16/8/1.
//  Copyright © 2016年 张博. All rights reserved.
//

#import <Foundation/Foundation.h>
/*! 使用枚举NS_ENUM:区别可判断编译器是否支持新式枚举,支持就使用新的,否则使用旧的 */
typedef NS_ENUM(NSUInteger, ZBNetworkStatus)
{
    /*! 未知网络 */
    ZBNetworkStatusUnknown           = 0,
    /*! 没有网络 */
    ZBNetworkStatusNotReachable,
    /*! 手机自带网络 */
    ZBNetworkStatusReachableViaWWAN,
    /*! wifi */
    ZBNetworkStatusReachableViaWiFi
};

/*！定义请求类型的枚举 */
typedef NS_ENUM(NSUInteger, ZBHttpRequestType)
{
    /*! get请求 */
    ZBHttpRequest_Get = 0,
    /*! post请求 */
    ZBHttpRequest_Post,
    /*! put请求 */
    ZBHttpRequest_Put,
    /*! delete请求 */
    ZBHttpRequest_Delete
    
};

/*! 定义请求成功的block */
typedef void( ^ ZBResponseSuccess)(id response);
/*! 定义请求失败的block */
typedef void( ^ ZBResponseFail)(NSError *error);

/*! 定义上传进度block */
typedef void( ^ ZBUploadProgress)(int64_t bytesProgress,
                                  int64_t totalBytesProgress);
/*! 定义下载进度block */
typedef void( ^ ZBDownloadProgress)(int64_t bytesProgress,
                                    int64_t totalBytesProgress);

/*!
 *  方便管理请求任务。执行取消，暂停，继续等任务.
 *  - (void)cancel，取消任务
 *  - (void)suspend，暂停任务
 *  - (void)resume，继续任务
 */
typedef NSURLSessionTask ZBURLSessionTask;




@interface ZBNetWorkManager : NSObject

/*! 获取当前网络状态 */
@property (nonatomic, assign)   ZBNetworkStatus netWorkStatus;

/*!
 *  获得全局唯一的网络请求实例单例方法
 *
 *  @return 网络请求类ZBNetManager单例
 */
+ (instancetype)sharedZBNetManager;

/*!
 *  开启网络监测
 */
+ (void)go_startNetWorkMonitoring;

/*!
 *  网络请求方法,block回调
 *
 *  @param type         get / post
 *  @param urlString    请求的地址
 *  @param paraments    请求的参数
 *  @param successBlock 请求成功的回调
 *  @param failureBlock 请求失败的回调
 *  @param progress 进度
 */
+ (ZBURLSessionTask *)go_requestWithType:(ZBHttpRequestType)type
                           withUrlString:(NSString *)urlString
                          withParameters:(NSDictionary *)parameters
                        withSuccessBlock:(ZBResponseSuccess)successBlock
                        withFailureBlock:(ZBResponseFail)failureBlock
                                progress:(ZBDownloadProgress)progress;

/*!
 *  上传图片(多图)
 *
 *  @param operations   上传图片预留参数---视具体情况而定 可移除
 *  @param imageArray   上传的图片数组
 *  @param urlString    上传的url
 *  @param successBlock 上传成功的回调
 *  @param failureBlock 上传失败的回调
 *  @param progress     上传进度
 */
+ (ZBURLSessionTask *)go_uploadImageWithUrlString:(NSString *)urlString
                                       parameters:(NSDictionary *)parameters
                                   withImageArray:(NSArray *)imageArray
                                 withSuccessBlock:(ZBResponseSuccess)successBlock
                                  withFailurBlock:(ZBResponseFail)failureBlock
                               withUpLoadProgress:(ZBUploadProgress)progress;

/*!
 *  视频上传
 *
 *  @param operations   上传视频预留参数---视具体情况而定 可移除
 *  @param videoPath    上传视频的本地沙河路径
 *  @param urlString     上传的url
 *  @param successBlock 成功的回调
 *  @param failureBlock 失败的回调
 *  @param progress     上传的进度
 */
+ (void)go_uploadVideoWithUrlString:(NSString *)urlString
                         parameters:(NSDictionary *)parameters
                      withVideoPath:(NSString *)videoPath
                   withSuccessBlock:(ZBResponseSuccess)successBlock
                   withFailureBlock:(ZBResponseFail)failureBlock
                 withUploadProgress:(ZBUploadProgress)progress;

/*!
 *  文件下载
 *
 *  @param operations   文件下载预留参数---视具体情况而定 可移除
 *  @param savePath     下载文件保存路径
 *  @param urlString        请求的url
 *  @param successBlock 下载文件成功的回调
 *  @param failureBlock 下载文件失败的回调
 *  @param progress     下载文件的进度显示
 */
+ (ZBURLSessionTask *)go_downLoadFileWithUrlString:(NSString *)urlString
                                        parameters:(NSDictionary *)parameters
                                      withSavaPath:(NSString *)savePath
                                  withSuccessBlock:(ZBResponseSuccess)successBlock
                                  withFailureBlock:(ZBResponseFail)failureBlock
                              withDownLoadProgress:(ZBDownloadProgress)progress;





@end
