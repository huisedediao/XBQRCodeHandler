//
//  XBQRCodeHandler.h
//  二维码
//
//  Created by XXB on 16/9/27.
//  Copyright © 2016年 XXB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class XBQRCodeHandler;

@protocol XBQRCodeHandlerDelegate <NSObject>

- (void)qrCodeHandler:(XBQRCodeHandler *)qrCodeHandler MessageString:(NSString *)messageString;

@end

@interface XBQRCodeHandler : NSObject

#pragma mark -- 生成二维码
/**
 *  生成二维码
 */
+ (UIImage *)createQRCodeForString:(NSString *)qrString withImageViewSize:(CGSize)size;


#pragma mark -- 识别二维码
/**
 *  识别图片二维码
 */
+ (NSString *)recognizedQRCodeOfImage:(UIImage *)image complete:(void (^)(NSString * messageString,BOOL success))complete;


#pragma mark -- 扫描二维码

/**
 *  参数一：展示在哪个view上
 *  参数而：摄像机画面的展示frame
 */
- (instancetype)initInView:(UIView *)superView withCameraPicFrame:(CGRect)frame;


/** 
 *  @brief 扫描识别之后会自动关闭，继续扫描请重新打开 
 *  开始扫描
 */
- (void)startRunning;

/**
 *  结束扫描
 */
- (void)stopRunning;


/**
 *  透明模式，除了有效扫描范围，还显示相机画面内的其他内容
 */
@property (nonatomic, assign) BOOL clearMode;

/**
 *  有效的扫描范围比例
 *  透明模式下才有效果，非透明模式下，有效范围为摄像机画面范围
 *  例如（0.2，0.2，0.5，0.6），距离左边，距离上边，宽的比例，高的比例
 */
@property (nonatomic,assign) CGRect effectiveRect;

@property (nonatomic, assign) id<XBQRCodeHandlerDelegate> delegate;

@property (nonatomic,strong) CALayer *backgroundLayer;
@end
