//
//  Constant.h
//  标准公共类/接口类
//
//  Created by 孙波 on 15/7/13.
//  Copyright (c) 2016年 孙波. All rights reserved.
//

#ifndef meituan_Constant_h
#define meituan_Constant_h

/**重新登陆标示符*/
#define KTRY_LOGIN_INFO            @"TRY_LOGIN_INFO"

/**个人中心本地数据文件名称*/
#define KSHOP_CENTER_FILES_NAME    @"shop_center_data.plist"

/**首页筛选框的数据*/
#define K_HOME_DROP_DOWN_LIST_DATA @"HomeDropDownListData"

/**通用密码串*/
#define KTongYong_MIMA             @"WangDaiJuHe2017!@#$"

/**友盟+统计APP_KEY*/
#define UMENG_APPKEY               @"58aceb67f43e48451e0007db"


/**talkingdata统计appkey*/
#define K_TAIKINGDATA_APPKEY       @"1F658B40DA3F4AF38AFDCCCB6B6A4DB9"

/**注册登录的协议*/
#define K_LOGIN_XIE_YI_URL         @"http://117.158.178.194:81/index.php/api/sys/agreement"

/**基础请求地址*/
#define KBASE_URL                  @"http://117.158.178.194:81/Api"//@"http://172.16.1.114:81/Api"


/**信用卡网页地址*/
#define KCREDIT_CARD_URL           @"http://channel.haodai.com/Mobile/creditcard/ref/hd_11011935"

/**合并参数使用*/
#define K_ADD_ALL_URL(canshu)      [NSString stringWithFormat:@"%@%@",K_WEB_BASE_URL,canshu]


/****************************************我的****************************************/
#define K_Feed_Back_URL            @"sys/feedback"                          //意见反馈

#define K_Send_Msg                 @"sys/sendSms"                           //发送短信验证码

#define K_User_Login               @"user/login"                            //用户登录

#define K_User_Logout              @"user/logout"                           //用户注销

#define K_RECORD_LIST_URL          @"user/myloan"                           // 申请贷款记录

//图片上传、临时地址
#define K_IMAGE_FILEUP             @"http://www.baidu.com"


/****************************************主页****************************************/
#define K_SELLER_LIST_URL          @"loan/getlist"                          //借款商列表

#define K_SELLER_GETINFO_URL       @"loan/getinfo"                          //借款商信息

#define K_APPLY_LOAN_URL           @"user/apply_loan"                       //申请贷款

#endif
