//
//  UILabel+ChangeLineSpacing.h
//  wangdai
//
//  Created by 抬头看见柠檬树 on 2017/3/31.
//  Copyright © 2017年 孙波. All rights reserved.
//

#import <UIKit/UIKit.h>

#define UILABEL_LINE_SPACE 33 * SCALE_SCREEN_W // 行间距具体的数值

@interface UILabel (ChangeLineSpacing)

/**
 设置行间距。注意！这个方法需要在Label显示出来以后调用才管用

 @param label 要设置行间距的label
 @param str label的文字
 @param font label的字体
 */
+ (void)setLabelSpace:(UILabel *)label withValue:(NSString *)str withFont:(UIFont *)font;


/**
 计算设置过行间距的Label的高度，与上个方法配套

 @param str label的文字
 @param font label的字体
 @param width label的宽度
 @return label的高度
 */
+ (CGFloat)getSpaceLabelHeight:(NSString*)str withFont:(UIFont*)font withWidth:(CGFloat)width;
@end
