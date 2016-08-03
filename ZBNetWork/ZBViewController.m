//
//  ZBViewController.m
//  ZBNetWork
//
//  Created by 张博 on 16/8/2.
//  Copyright © 2016年 张博. All rights reserved.
//

#import "ZBViewController.h"
#import "ZBNetWorkManager.h"
@interface ZBViewController () {
    UIButton *_TestBtn;
}

@end
@implementation ZBViewController

-(void)viewDidLoad {
    self.view.backgroundColor = [UIColor cyanColor];
    self.navigationController.title = @"test";
    
    //开启网络监听
    [ZBNetWorkManager go_startNetWorkMonitoring];
    [self testMyNetWorK];
}

- (void)testMyNetWorK {
    _TestBtn = [UIButton new];
    _TestBtn.frame = CGRectMake((self.view.frame.size.width - 44 ) /2, (self.view.frame.size.height - 44 ) /2, 44, 44);
    [_TestBtn setTitle:@"Start" forState:UIControlStateNormal];
    [_TestBtn setBackgroundColor:[UIColor redColor]];
    _TestBtn.titleLabel.textColor = [UIColor grayColor];
    [_TestBtn addTarget:self action:@selector(StartSendRequest) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_TestBtn];
}

- (void)StartSendRequest {
    [ZBNetWorkManager go_requestWithType:ZBHttpRequest_Get withUrlString:@"video/home/1-10.html" withParameters:nil withSuccessBlock:^(id response) {
        NSDictionary *dic = [NSDictionary dictionaryWithDictionary:response];
        NSLog(@"%@",dic);
    } withFailureBlock:^(NSError *error) {
        
    } progress:^(int64_t bytesProgress, int64_t totalBytesProgress) {
        
    }];
}

@end
