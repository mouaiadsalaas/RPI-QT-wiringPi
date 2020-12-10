#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/****************************/
/******second step***********/
/****************************/
//here we include our library
//then we go to ui and creat our buttons and slots
#include "wiringPi.h"

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
