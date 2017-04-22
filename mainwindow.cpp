#include "drawablearea.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _model = new Model();
//    std::cout<<typeid(_model)<<std::endl;
    DrawableArea* a = new DrawableArea(_model);
    this->setCentralWidget(a);
}

MainWindow::~MainWindow()
{
    delete ui;
}
