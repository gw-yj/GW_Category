//
//  UIView+GWTools.h
//  Pocket
//
//  Created by gw on 2020/9/1.
//  Copyright © 2020 tiens. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

///是否有安全区域 iphoneX以上版本
#define IS_HAS_SafeArea_GW [[NSUserDefaults standardUserDefaults] boolForKey:GW_HAS_SafeArea]
//是否是ipad
#define IS_PAD_GW ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
//是否是手机
#define IS_IPHONE_GW (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//底部tab高度
#define TabHeight_GW [[NSUserDefaults standardUserDefaults] doubleForKey:GW_TAB_HEIGHT]
//底部tabbar高度
#define TabbarHeight_GW [[NSUserDefaults standardUserDefaults] doubleForKey:GW_TAB_BAR_HEIGHT]
//导航栏高度
#define NavHeight_GW [[NSUserDefaults standardUserDefaults] doubleForKey:GW_NAV_HEIGHT]
//导航栏navbar高度
#define NavBarHeight_GW [[NSUserDefaults standardUserDefaults] doubleForKey:GW_NAV_BAR_HEIGHT]
//状态栏高度
#define StatusBarHeight_GW [[NSUserDefaults standardUserDefaults] doubleForKey:GW_STATUS_HEIGHT]
//home indicator（home指示器）
#define HomeIndicatorHeight_GW [[NSUserDefaults standardUserDefaults] doubleForKey:GW_HOME_INDICATOR_HEIGHT]
//横屏状态下左右安全边距
#define Landscape_SafeArea_Width_GW  [[NSUserDefaults standardUserDefaults] doubleForKey:GW_Landscape_SafeArea_Width]
//按像素适配
#define GWWidthPX(x) (IS_PAD_GW ? ceil([UIScreen mainScreen].bounds.size.width*(x)/768) : ceil([UIScreen mainScreen].bounds.size.width*(x)/375))

//是否有安全区域
static NSString *const GW_HAS_SafeArea = @"GW_HAS_SafeArea";
//横屏状态下左右安全边距
static NSString *const GW_Landscape_SafeArea_Width = @"GW_Landscape_SafeArea_Width";
//底部指示器高度
static NSString *const GW_HOME_INDICATOR_HEIGHT = @"GW_HOME_INDICATOR_HEIGHT";
//导航栏高度
static NSString *const GW_NAV_HEIGHT = @"GW_NAV_HEIGHT";
//导航栏-navbar高度
static NSString *const GW_NAV_BAR_HEIGHT = @"GW_NAV_BAR_HEIGHT";
//导航栏-状态栏高度
static NSString *const GW_STATUS_HEIGHT = @"GW_STATUS_HEIGHT";
//底部tab高度
static NSString *const GW_TAB_HEIGHT = @"GW_TAB_HEIGHT";
//底部tabbar高度
static NSString *const GW_TAB_BAR_HEIGHT = @"GW_TAB_BAR_HEIGHT";


@interface UIView (GWTools)

@end



#pragma mark - layer - 圆角
@interface UIView (GWLayer)


/// 绘制frame
/// @param frame frame
/// @param name layer名称
- (void)GWLayerOnlyRect:(CGRect)frame
              layerName:(NSString * _Nullable)name;

/**
设置指定位置的圆角

@param rectCorner 圆角位置(该变量可使用或运算，用于同时设置多个圆角)
@param radius 圆角半径
@param name 给子layer命名,防止重复设置增加开销
*/
- (UIBezierPath *)GWLayerOnlyRoundedCorners:(UIRectCorner)rectCorner
                     cornerRadius:(CGFloat)radius
                        layerName:(NSString * _Nullable)name;


/// 画border
/// @param borderWidth  border宽
/// @param borderColor  border颜色
/// @param fillColor  border填充颜色
/// @param name layer名称
/// @param path 贝塞尔路径  如果为nil，则按照frame进行绘制

- (void)GWLayerOnlyBorderWidth:(CGFloat)borderWidth
               borderColor:( UIColor * _Nullable )borderColor
                 fillColor:(UIColor * _Nullable)fillColor
                 layerName:(NSString * _Nullable)name
                bezierPath:(UIBezierPath * _Nullable)path;
/**
 设置指定位置的圆角和border样式

 @param rectCorner 圆角位置(该变量可使用或运算，用于同时设置多个圆角)
 @param radius 圆角半径
 @param borderWidth 边框宽度
 @param borderColor 边框颜色
 @param fillColor 填充色
 @param name 给子layer命名,防止重复设置增加开销
 */
- (void)GWLayerRoundedCorners:(UIRectCorner)rectCorner
               cornerRadius:(CGFloat)radius
                borderWidth:(CGFloat)borderWidth
                borderColor:( UIColor * _Nullable )borderColor
                  fillColor:(UIColor * _Nullable)fillColor
                  layerName:(NSString * _Nullable)name;


/// 移除指定layer
/// @param name layer名称
- (void)GWLayerRemove:(NSString *)name;
@end

#pragma mark - view - Present
@interface UIView (Present)

//弹出一个类似present效果的窗口
- (void)presentView:(UIView*)view animated:(BOOL)animated complete:(void(^)(void)) complete;

//获取一个view上正在被present的view
- (UIView *)presentedView;

//移除present出去的窗口
- (void)dismissPresentedView:(BOOL)animated complete:(void(^)(void)) complete;

//这个是被present的窗口本身的方法
//如果自己是被present出来的，消失掉
- (void)hideSelf:(BOOL)animated complete:(void(^)(void)) complete;

@end

NS_ASSUME_NONNULL_END
