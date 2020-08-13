#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia/qmediaplayer.h>
#include "QDebug"
#include "qlabel.h"
#include <QBitmap>
#include <QThread>
#include "mywork.h"
#include <QMovie>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mos->installEventFilter(this);

    ui->logo->setScaledContents(true);
    QMovie *movie = new QMovie("C:\\itcast\\day4\\mjq3\\logo.gif");
    ui->logo->setMovie(movie);
    movie->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //判断选择的歌曲
    int choice;
    if(ui->rb1->isChecked())
    {
        choice = Song::DHT;
    }

    if(ui->rb2->isChecked())
    {
        choice = Song::MJQ;
    }

    //播放音乐
    QMediaPlayer * player = new QMediaPlayer;
    //设置音乐
    switch(choice)
    {
    case 0:
        player->setMedia(QUrl::fromLocalFile("C:\\itcast\\day4\\mjq3\\sf.mp3"));
        break;
    case 1:
        player->setMedia(QUrl::fromLocalFile("C:\\itcast\\day4\\mjq3\\在人间.mp3"));
        break;
    }
//    player->setMedia(QUrl::fromLocalFile(":/music/在人间.mp3"));
    player->setVolume(50);
    player->play();

    //鼠标样式
    QBitmap bitmap("C:\\itcast\\day4\\mjq3\\hitman1.png");
    QCursor cursor(bitmap); //-1 -1表示鼠标热点在中心点
    setCursor(cursor); //设置自定义的鼠标样式

    //跳转页面
    ui->stackedWidget->setCurrentIndex(1);
}


    //重写蚊子label点击事件
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->mos)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            qDebug()<<"hello";
            QMediaPlayer * player = new QMediaPlayer;
            player->setVolume(50);
            player->setMedia(QUrl::fromLocalFile("C:\\itcast\\day4\\mjq3\\hit.mp3"));
            player->play();

            srand(time(NULL));
            ui->mos->move(rand()%500, rand()%500);
        }
        else
        {
            return false;
        }
    }
}
