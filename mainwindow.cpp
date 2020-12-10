#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/**********************/
/*****third step******/
/********************/
    //here we setup our library and set our pins mode then go to our slot functions
    wiringPiSetup();
    pinMode(5,OUTPUT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ON_clicked()
{
    digitalWrite(5,HIGH);
}

void MainWindow::on_OFF_clicked()
{
    digitalWrite(5,LOW);
}
