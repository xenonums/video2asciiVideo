#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QIcon logo("icon1.ico");
    this->setWindowIcon(logo);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_selectButton_clicked()
{
    file_path = QFileDialog::getOpenFileName(this,tr("请选择视频文件"),"/.","txt files(*)");
    ui->lineEdit->setText(file_path);
}




void Widget::on_doButton_clicked()
{
    if(file_path.isEmpty())
    {
        QMessageBox::information(this, "提示","请先选择视频路径");
    }
    else
    {     
        Widget a;
        
        std::thread taskP(&Widget::BeAsic, &a, file_path);
        std::thread taskD(&Widget::BgMusic, &a, file_path);

        
        taskD.join();
        taskP.join();

    }
}

void replaceChar(std::string& str, char toReplace, char replacement) {
    std::replace(str.begin(), str.end(), toReplace, replacement);
}

void HideWindow() {
    HWND hwnd = GetForegroundWindow();	//获取程序启动时的窗口
    if (hwnd) {
        ::SendMessage(hwnd, WM_SYSCOMMAND, SC_MINIMIZE, NULL);;	//设置指定窗口的显示状态
    }
}

void Widget::BgMusic(QString file_path)
{
    // 获取控制台窗口
    char* ch;
    QByteArray ba = file_path.toLatin1();
    ch = ba.data();
    String vpath = ch;

    replaceChar(vpath, '/', '\\');
    const char* evpath = vpath.data();

    libvlc_instance_t* vlc_ins = NULL;
    libvlc_media_player_t* vlc_player = NULL;
    libvlc_media_t* vlc_media = NULL;

    const char* vlc_args[] =
    {
        "-I",
        "dummy",
        "--ignore-config",
        "--extraintf=logger",
        "--verbose=2",
        "--vout", "none"
    };
    
    // 创建一个VLC实例
    vlc_ins = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);
    if (vlc_ins != NULL)
    {
        // 创建一个VLC播放器
        vlc_player = libvlc_media_player_new(vlc_ins);
        if (vlc_player != NULL)
        {
            // 通过文件路径创建一个媒体实例,这里是我的测试文件
            vlc_media = libvlc_media_new_path(vlc_ins, evpath);
            if (vlc_media != NULL)
            {

                // 解析媒体实例
                libvlc_media_parse(vlc_media);
                // 获取媒体文件的播放长度,  返回 ms
                libvlc_time_t duration = libvlc_media_get_duration(vlc_media);

                // 此处是获取媒体包含多个的视频和音频轨以及其他类型的轨道信息
                libvlc_media_track_info_t* media_tracks = NULL;
                int trackCount = libvlc_media_get_tracks_info(vlc_media, &media_tracks);
                // 这里是释放内存，但我测试的时候会有问题，还没仔细研究是为何

                // 把打开的媒体文件设置给播放器
                libvlc_media_player_set_media(vlc_player, vlc_media);

                // 开始播放视频
                libvlc_media_player_play(vlc_player);
                HideWindow();
                // 这里仅是为了打印一些信息出来,20秒后退出
                time_t last_time = time(NULL);

                while ((time(NULL) < (last_time + 200)))
                {
                    Sleep(10);
                    // 获取当前播放位置
                    libvlc_time_t play_time = libvlc_media_player_get_time(vlc_player);
                    //printf("playing time : %lld ms\r", (__int64)(play_time));

                    // 获取媒体的状态
                    // libvlc_state_t media_state = libvlc_media_get_state(vlc_media);
                    // printf("\nmedia state : %d\n", (int)(media_state));
                }
                // 停止
                libvlc_media_player_stop(vlc_player);
                // 释放
                libvlc_media_release(vlc_media);
            }
            // 释放
            libvlc_media_player_release(vlc_player);
        }
        // 释放
        libvlc_release(vlc_ins);
        
    }
}

void Widget::BeAsic(QString file_path) {

    char*  ch;
    QByteArray ba = file_path.toLatin1();
    ch=ba.data();


    //创建指定大小窗口
    initgraph(WIDTH, HEIGHT);
    
    //打开视频
    VideoCapture video(ch);//读入文件
    //导入图像mat类型
    Mat img;  //存储视频每一帧
    Mat show;  //显示图像


    //获取视频帧率,长宽
    // double fps = video.get(cv::CAP_PROP_FPS);
    totalfps = (int)video.get(cv::CAP_PROP_FRAME_COUNT);

    //初始帧率
    originfps = totalfps / duration ;


    //准备替换的字符
    const char* str = " .,-l'`/:!1t+HT@$%&";//
    int length = strlen(str);
    int index = 0;      //下标

    String text;
    //设置替换文字样式(EASYX)
    settextstyle(9, 9, "楷体");
    setbkmode(TRANSPARENT);//去掉文字背景
    settextcolor(WHITE);

    //双缓冲绘图解决屏幕闪烁
    BeginBatchDraw();
    //

    while (1) {
        video >> img;   //流操作
        if (img.empty()) {
            break;
        }
        //调整图像属性
        cvtColor(img, img, COLOR_BGR2GRAY); //灰度图
        //resize(img, show, Size(), 0.6, 0.6);//调整大小
        cv::resize(img, img, Size(), 0.06, 0.06);

        cleardevice();
        //双循环读取mat数组
        for (int x = 0; x < img.rows;x++) {
            for (int y = 0; y < img.cols;y++) {
                int color = img.at<uchar>(x, y); //像素点颜色
                index = color / 256.0 * length;    //妙
                text += str[index];
            }

            outtextxy(0, x * textheight(str[index]), text.data());
            
            text.clear(); //生成一行消除一行
        }

        FlushBatchDraw(); // 显示每一帧

        waitKey(1000 / 52);

        //显示图像
        //imshow("图片", show );     

    }
    EndBatchDraw();
    //while (1);
    //关闭窗口
    closegraph();

}



