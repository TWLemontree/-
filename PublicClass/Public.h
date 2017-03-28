//
//  Public.h
//  aoyouHH
//
//  Created by 孙波 on 15/4/21.
//  Copyright (c) 2016年 孙波. All rights reserved.
//

#ifndef wangdai_Public_h
#define wangdai_Public_h

#import "ModelRequestResult.h"
#import "BaseViewController.h"
#import "BaseWMPageController.h"
#import "baseNavigationViewController.h"

#import "AppDelegate.h"
#import <MJExtension/MJExtension.h>
#import "LToast.h"
#import "SDCycleScrollView.h"
#import <Masonry.h>
#import "SVProgressHUD.h"
#import "WMPageController.h"
#import "MBProgressHUD.h"
#import "MJRefreshNormalHeader.h"
#import "MJRefreshAutoNormalFooter.h"

#import "KINWebBrowserViewController.h"

#import "GlobalSetting.h"

//请求数据
#import "NetworkSingleton.h"

#import <UMMobClick/MobClick.h>     //友盟+
#import "TalkingData.h"             //talkingData统计

#import "UIColor+Hex.h"             //16位颜色

/**列表分页的个数*/
#define K_List_limit_Count                  10

// 屏宽比上设计图宽的比例（量出的尺寸直接乘以该比例即可）
#define SCALE_SCREEN_W (CGFloat)screen_width/1080.0

// 1.判断是否为iOS7
#define iOS7 ([[UIDevice currentDevice].systemVersion doubleValue] >= 7.0)

// 2.获得RGB颜色
#define RGBA(r, g, b, a)                    [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r, g, b)                        RGBA(r, g, b, 1.0f)

// 随机色
#define RandomColor                 RGB(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))
//新添加的
#define kNavTitleFontSize 18
#define RADIUS (screen_width+10)/6


/**APP的主题色调-主题颜色-蓝色*/
#define K_Main_Theme_Color          RGB(0,122,251)

/**APP主题按钮颜色-蓝色-浅*/
#define K_Main_Button_Color         RGB(11,130,254)//RGB(0,133,251)

/**APP统一页面背景色*/
#define K_Background_Color          [UIColor colorWithHexString:@"#eeeeee"]

/***************标签颜色*******************/
#define K_TONG_GUO_COLOR            RGB(141, 203, 255)

#define K_FANG_KUAN_COLOR           RGB(132, 210, 155)

#define K_E_DU_COLOR                RGB(255, 144, 148)


#define K_TEXT_FONT_LIGHT_BK        RGB(50, 50, 50)             //字体黑





#define navigationBarColor RGB(0, 195, 151)//RGB(33, 192, 174)

#define otherNavigationBarColor RGB(0,195,151)

#define KTextGrayLLColor RGB(170,170,170)

#define separaterColor RGB(235, 235, 235)

#define KTextGrayColor RGB(100,100,100)

#define kThemeColor RGB(222, 45, 35)

#define KTextGrayLightColor RGB(80,80,80)

// 3.是否为4inch
#define fourInch ([UIScreen mainScreen].bounds.size.height == 568)

// 4.屏幕大小尺寸
#define screen_width [UIScreen mainScreen].bounds.size.width
#define screen_height [UIScreen mainScreen].bounds.size.height

//重新设定view的Y值
#define setFrameY(view, newY) view.frame = CGRectMake(view.frame.origin.x, newY, view.frame.size.width, view.frame.size.height)
#define setFrameX(view, newX) view.frame = CGRectMake(newX, view.frame.origin.y, view.frame.size.width, view.frame.size.height)
#define setFrameH(view, newH) view.frame = CGRectMake(view.frame.origin.x, view.frame.origin.y, view.frame.size.width, newH)
#define setFrameW(view, newW) view.frame = CGRectMake(view.frame.origin.x, view.frame.origin.y, newW, view.frame.size.height)


//取view的坐标及长宽
#define W(view)                     view.frame.size.width
#define H(view)                     view.frame.size.height
#define X(view)                     view.frame.origin.x
#define Y(view)                     view.frame.origin.y

//ScrollView的ContentSize的长宽
#define ScrollViewC_H(view)         view.contentSize.height
#define ScrollViewC_W(view)         view.contentSize.width

//contentOffset的坐标
#define contentOffset_Y(view)       view.contentOffset.y
#define contentOffset_X(view)       view.contentOffset.x

#define ViewBottomY(view)           Y(view)+H(view)
#define ViewWidthX(view)            X(view)+W(view)

//5.常用对象
#define APPDELEGATE                 ((AppDelegate *)[UIApplication sharedApplication].delegate)
#define APP_WIN                     [[[UIApplication sharedApplication] delegate] window]


#define GlobalSettingShare          [GlobalSetting shareGlobalSettingInstance]

//6.经纬度
#define LATITUDE_DEFAULT 34.684702
#define LONGITUDE_DEFAULT 112.415595

//默认城市地区
#define K_administrativeArea        @"河南省"
#define K_locality                  @"洛阳市"
#define K_subLocality               @"涧西区"

//用户图标等级最大的图标是多少？
#define KmaxUserLevelNum            6

//7.
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define screenH ([UIScreen mainScreen].bounds.size.height)
//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"line%d content:%s\n",__LINE__,[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
//fprintf(stderr,"\nfunction:%s line:%d content:%s", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif

//新Bug打印机制，主要负责网络访问的参数、URL、结果等。
//----------------------下面↓----------------------------
#if DEBUG
#define NETLog(showText,FORMAT,...) fprintf(stderr,"line%d content:\n\n----------------%s↓----------------\n%s\n----------------%s↑----------------\n\n",__LINE__,[showText UTF8String],[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String],[showText UTF8String]);
//#define NETLog(showText,FORMAT,...) nil

#else
#define NETLog(showText,FORMAT,...) nil
#endif
//----------------------上面↑----------------------------

//----------------------其他----------------------------

// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

#endif
