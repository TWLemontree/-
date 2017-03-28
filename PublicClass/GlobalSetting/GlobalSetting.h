//
//  GlobalSetting.h
//  公共类，小数据保存类
//
//  Created by 孙波 on 15/12/6.
//  Copyright © 2015年 sunny. All rights reserved.
//

#define kInterFaceAddress   @"interface"
#define kResourceFile       @"resourecFile"

#define kDToken             @"DeviceToken"

#define KPhoneNum           @"PhoneNum"
#define KUserName           @"userName"
#define KUserUid            @"userUid"

#import <Foundation/Foundation.h>

#define MainUrl @"MainUrl"

@interface GlobalSetting : NSObject

/**
 *  返回一个全局设置的类的单例
 *
 *  @return 单例
 */
+(GlobalSetting *)shareGlobalSettingInstance;

/**正则验证手机号*/
+ (BOOL)regularOfPhone:(NSString *)phone;

/**将色值转化成image对象*/
+ (UIImage *)imageWithColor:(UIColor *)color;


/**
 *  移除UserDefaults
 */
-(void)removeUserDefaultsValue;


/*!
 *  @brief  根据键值返回数据
 *
 *  @param key 键值
 *
 *  @return 返回的值
 */
- (id)readUserDefaultsValueWith:(NSString *)key;


/**设置推送的token值*/
-(void) setDeviceToken:(NSString *)token;

/**获取推送的token值*/
-(NSString *) getDeviceToken;


/**设置用户的Uid*/
- (void)setUserUid:(NSString *)uid;

/**读取用户Uid*/
- (NSString *)getUserUid;

/**设置用户的昵称*/
-(void)setUserName:(NSString *)userName;

/**读取用户昵称*/
-(NSString *)getUserName;


/**设置用户手机号*/
- (void)setPhoneNum:(NSString *)phone;

/**取得用户手机号*/
- (NSString *)getPhoneNum;


- (void)writeData:(id)data plistName:(NSString *)plistName;

- (id)readDataWithName:(NSString *)plistName;

- (void)clearPlistData;


@end
