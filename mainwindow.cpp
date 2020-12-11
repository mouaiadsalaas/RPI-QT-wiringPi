#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <QTextStream>
#include <QTime>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *mTimer = new QTimer(this);
/**********************/
/*****third step******/
/********************/
    //here we setup our library and set our pins mode then go to our slot functions
    wiringPiSetup();
    pinMode(5,OUTPUT);

    fd = wiringPiSPISetup(CHANNEL, 500000);
    fd_2 = wiringPiSPISetup(CHANNEL_2, 500000);

    connect(mTimer, SIGNAL(timeout()), this, SLOT(updateCaption()));
    mTimer->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ON_clicked()
{
    // our tx data is buffer[0]
    TX_buffer[0] = 0xF0;
    wiringPiSPIDataRW(CHANNEL_2, TX_buffer, 1);//send the buffer //our channel ,our data,how much bit

    digitalWrite(5,HIGH);

}

void MainWindow::on_OFF_clicked()
{
    // our tx data is buffer[0]


    digitalWrite(5,LOW);
    //sleep(5);
}

//function has been created for timer duty
void MainWindow::updateCaption()
{
    //RX_buffer[0] = 0x00;
    //coming data from spi bus is being written over the  same buffer (RX_buffer)
    wiringPiSPIDataRW(CHANNEL_2,RX_buffer, 2);
    timerCount++;
    qDebug() << "Timer = " << timerCount << " geln = "<< RX_buffer;
}


//this function has been created for showing time by using QTIME lib
void MainWindow::on_ShowTime_clicked()
{
    QTextStream out(stdout);

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    qDebug() << "Current date is: " << cd.toString();
    qDebug()<< "Current time is: " << ct.toString();
}
