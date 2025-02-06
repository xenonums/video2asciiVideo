#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QFontMetrics>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <easyx.h>
//music
#include <windows.h>
#include <vlc/vlc.h>
#include <time.h>
//delete?
#include <mmsystem.h>
#pragma comment(lib,"WinMM.Lib")
#include<tchar.h>
#include <thread>


using namespace cv;
using namespace std;


#define WIDTH 960
#define HEIGHT 640

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();



private slots:
    void on_selectButton_clicked();

    void on_doButton_clicked();


private:
    Ui::Widget *ui;

    QString file_path;

    libvlc_time_t duration;

    double totalfps;

    double originfps;


    void BeAsic(QString file_path);

    void BgMusic(QString file_path);
};
#endif // WIDGET_H
