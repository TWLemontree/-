//
//  GlobalSetting.m
//  公共类，小数据保存类
//
//  Created by 孙波 on 15/12/6.
//  Copyright © 2015年 sunny. All rights reserved.
//

#import "GlobalSetting.h"

static GlobalSetting *globalSetting;

@implementation GlobalSetting

+(GlobalSetting *)shareGlobalSettingInstance{
    if (!globalSetting) {
        globalSetting = [[self alloc] init];
    }
    return globalSetting;
}

+ (BOOL)regularOfPhone:(NSString *)phone{
    /**
     * 手机号码
     * 移动：134[0-8],135,136,137,138,139,150,151,157,158,159,182,187,188,177
     * 联通：130,131,132,152,155,156,185,186
     * 电信：133,1349,153,180,189,181
     */
    NSString * MOBILE = @"^1(3[0-9]|5[0-35-9]|8[025-9])\\d{8}$";
    /**
     10         * 中国移动：China Mobile
     11         * 134[0-8],135,136,137,138,139,150,151,157,158,159,182,187,188
     12         */
    NSString * CM = @"^1(34[0-8]|(3[5-9]|5[017-9]|8[2378]|77)\\d)\\d{7}$";
    /**
     15         * 中国联通：China Unicom
     16         * 130,131,132,152,155,156,185,186
     17         */
    NSString * CU = @"^1(3[0-2]|5[256]|8[56])\\d{8}$";
    /**
     20         * 中国电信：China Telecom
     21         * 133,1349,153,180,189,181
     22         */
    NSString * CT = @"^1((33|53|8[019])[0-9]|349)\\d{7}$";
    /**
     25         * 大陆地区固话及小灵通
     26         * 区号：010,020,021,022,023,024,025,027,028,029
     27         * 号码：七位或八位
     28         */
    // NSString * PHS = @"^0(10|2[0-5789]|\\d{3})\\d{7,8}$";
    
    NSPredicate *regextestmobile = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", MOBILE];
    NSPredicate *regextestcm = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CM];
    NSPredicate *regextestcu = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CU];
    NSPredicate *regextestct = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CT];
    
    if (([regextestmobile evaluateWithObject:phone] == YES)
        || ([regextestcm evaluateWithObject:phone] == YES)
        || ([regextestct evaluateWithObject:phone] == YES)
        || ([regextestcu evaluateWithObject:phone] == YES))
    {
        return YES;
    }
    else
    {
        return NO;
    }
}


/**将色值转化成image对象*/

+ (UIImage *)imageWithColor:(UIColor *)color {
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return image;
}


- (id)readUserDefaultsValueWith:(NSString *)key
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    id string = [userDefaults stringForKey:key];
    return string;
}

-(void)setMainUrl:(NSString *)url
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:url forKey:MainUrl];
    [userDefaults synchronize];
}


-(void)removeUserDefaultsValue{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    
    [userDefaults synchronize];
}

-(void) setInterfaceAddress:(NSString *)address
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:address forKey:kInterFaceAddress];
    [userDefaults synchronize];
}

-(NSString *)getInterfaceAddress
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    return [userDefaults valueForKey:kInterFaceAddress];
}

-(void) setResourceFile:(NSString *)address
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:address forKey:kResourceFile];
    [userDefaults synchronize];
}

-(NSString *)getResourceFile
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    return [userDefaults valueForKey:kResourceFile];
}

-(void)setDeviceToken:(NSString *)token
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:token forKey:kDToken];
    [userDefaults synchronize];
}

-(NSString *)getDeviceToken
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    if ([userDefaults valueForKey:kDToken] == nil) {
        return @"";
    }
    return [userDefaults valueForKey:kDToken];
}


/**设置的名字*/
-(void)setUserName:(NSString *)userName
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:userName forKey:KUserName];
    [userDefaults synchronize];
}

/**读取的名字*/
-(NSString *)getUserName
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    return [userDefaults valueForKey:KUserName];
}


/**设置手机号*/
- (void)setPhoneNum:(NSString *)phone
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:phone forKey:KPhoneNum];
    [userDefaults synchronize];
}

/**取得手机号*/
- (NSString *)getPhoneNum
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    return [userDefaults valueForKey:KPhoneNum];
}

/**设置用户的Uid*/
- (void)setUserUid:(NSString *)uid
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:uid forKey:KUserUid];
    [userDefaults synchronize];
}

/**读取用户Uid*/
- (NSString *)getUserUid
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    return [userDefaults valueForKey:KUserUid];
}

- (void)writeData:(id)data plistName:(NSString *)plistName
{
    
    NSString *fileName = [[self applicationDocumentsDirectory] stringByAppendingString:[NSString stringWithFormat:@"/%@",plistName]];
    [data writeToFile:fileName atomically:YES];
}

- (id)readDataWithName:(NSString *)plistName
{
    NSString *fileName = [[self applicationDocumentsDirectory] stringByAppendingString:[NSString stringWithFormat:@"/%@",plistName]];
    NSDictionary *data = [[NSDictionary alloc] initWithContentsOfFile:fileName];
    if (data == nil) {
        NSMutableArray *array = [[NSMutableArray alloc] initWithContentsOfFile:fileName];
        if (array == nil) {
            return nil;
        }
        return array;
    }
    return data;
}

- (void)clearPlistData {
    //清除plist文件，可以根据我上面讲的方式进去本地查看plist文件是否被清除
    NSFileManager *fileMger = [NSFileManager defaultManager];
    
    NSString *xiaoXiPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)objectAtIndex:0]stringByAppendingPathComponent:@"userDic.plist"];
    
    //如果文件路径存在的话
    BOOL bRet = [fileMger fileExistsAtPath:xiaoXiPath];
    
    if (bRet) {
        
        NSError *err;
        
        [fileMger removeItemAtPath:xiaoXiPath error:&err];
    }
}

- (NSString *)applicationDocumentsDirectory
{
    NSArray *path = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *plistPath = [path objectAtIndex:0];
    return plistPath;
}


@end
