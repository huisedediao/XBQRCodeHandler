# XBQRCodeHandler
基于某位同道的代码添加扫描区域，抱歉不记得是哪位的了。。。。
<br>
##效果图：<br>
![image](https://github.com/huisedediao/XBQRCodeHandler/raw/master/exam.png)<br>
<br><br>

实例代码：<br>
<br>
##扫描二维码
\#import "ViewController.h"<br>
\#import "XBQRCodeHandler.h"<br>
<br>
@interface ViewController ()<XBQRCodeHandlerDelegate><br>
{<br>
    XBQRCodeHandler *qrcodeH;<br>
}<br>
@end<br>
<br>
@implementation ViewController<br>
<br>
\- (void)viewDidLoad {<br>
    [super viewDidLoad];<br>
<br>
    //如果非透明模式，摄像机展示的画面为这里设置的rect<br>
    //透明模式下，摄像机画面为参数一传的view<br>
    qrcodeH=[[XBQRCodeHandler alloc] initInView:self.view withCameraPicFrame:CGRectMake(100, 100, 100, 100)];<br>
    qrcodeH.delegate=self;<br>
    qrcodeH.effectiveRect=CGRectMake(100.0/320, 100.0/568, 100.0/320, 100.0/568);<br>
    //透明模式，除了有效范围，可以看见摄像机画面的其他内容<br>
    qrcodeH.clearMode=YES;<br>
    //开始扫描<br>
    [qrcodeH startRunning];<br>
}<br>
<br>
-(void)qrCodeHandler:(XBQRCodeHandler *)qrCodeHandler MessageString:(NSString *)messageString<br>
{<br>
    NSLog(@"%@",messageString);<br>
}<br>
@end<br>
<br><br><br><br><br>
##识别二维码<br>
\//参数1：二维码图片<br>
\//参数2：完成识别后的回调<br>
\+ (NSString *)recognizedQRCodeOfImage:(UIImage *)image complete:(void (^)(NSString * messageString,BOOL success))complete;<br>
