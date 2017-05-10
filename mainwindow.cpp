#include "drawablearea.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _drawableArea = new DrawableArea();
    this->centralWidget()->setLayout(ui->verticalLayout);
    this->centralWidget()->layout()->addWidget(_drawableArea);
//    _drawableArea->setFixedSize(this->width(),this->height());
//    this->setCentralWidget(a);
}

MainWindow::~MainWindow()
{
    delete ui;
    _drawableArea = 0;
    delete _drawableArea;
    _model = 0;
    delete _model;
}

void MainWindow::on_startBtn_clicked()
{
//    std::cout<<this->width()<<this->height()<<std::endl;
    _model = new Model(_drawableArea->width(), _drawableArea->height());
    _drawableArea->SetModel(_model);
    _drawableArea->Run(ui->fpsSlider->value());
}

void MainWindow::on_pauseBtn_clicked()
{
    _drawableArea->Pause(ui->fpsSlider->value());
}

void MainWindow::on_fpsSlider_valueChanged(int value)
{
    _drawableArea->Stop();
}
