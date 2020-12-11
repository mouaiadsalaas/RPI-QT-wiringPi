#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/****************************/
/******second step***********/
/****************************/
//here we include our library
//then we go to ui and creat our buttons and slots
#include "wiringPi.h"
#include "wiringPiSPI.h"
#include <unistd.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ON_clicked();

    void on_OFF_clicked();

    void updateCaption();

    void on_ShowTime_clicked();

private:
    Ui::MainWindow *ui;
    int fd,fd_2, result;
    int rcv=0;
    unsigned char TX_buffer[100];
    unsigned char RX_buffer[100];
    static const int CHANNEL = 1;
    static const int CHANNEL_2 = 0;

    int timerCount =0;

};

#endif // MAINWINDOW_H
