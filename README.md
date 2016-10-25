# XBQRCodeHandler
基于某位同道的代码添加扫描区域，抱歉不记得是哪位的了。。。。

效果图：
![image](https://github.com/huisedediao/XBQRCodeHandler/raw/master/exam.jpg)


实例代码：
#import "ViewController.h"
#import "XBQRCodeHandler.h"

@interface ViewController ()<XBQRCodeHandlerDelegate>
{
    XBQRCodeHandler *qrcodeH;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    //如果非透明模式，摄像机展示的画面为这里设置的rect
    //透明模式下，摄像机画面为参数一传的view
    qrcodeH=[[XBQRCodeHandler alloc] initInView:self.view withCameraPicFrame:CGRectMake(100, 100, 100, 100)];
    qrcodeH.delegate=self;
    qrcodeH.effectiveRect=CGRectMake(100.0/320, 100.0/568, 100.0/320, 100.0/568);
    //透明模式，除了有效范围，可以看见摄像机画面的其他内容
    qrcodeH.clearMode=YES;
    //开始扫描
    [qrcodeH startRunning];
}

-(void)qrCodeHandler:(XBQRCodeHandler *)qrCodeHandler MessageString:(NSString *)messageString
{
    NSLog(@"%@",messageString);
}
@end
