#include "drawablearea.h"
#include <QPainter>
#include <QTimer>
#include <iostream>

DrawableArea::DrawableArea(QWidget *parent) : QWidget(parent)
{    
    // Setting a repeating timer that calls LCM on each robot.
    _timer = new QTimer(this);
    _model = NULL;
}

DrawableArea::~DrawableArea()
{
    _timer = 0;
    delete _timer;
    _model = 0;
    delete _model;
}

void DrawableArea::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);

    // Drawing robots on screen
    if(_model) DrawRobots(&p);
}

void DrawableArea::Run(int fps)
{
    _isPaused = false;
    _timer->start(fps);
}

void DrawableArea::Pause(int fps)
{
    if(_isPaused) {
        _timer->start(fps);
    }
    else {
        _timer->stop();
    }
    _isPaused = !_isPaused;
}

void DrawableArea::Stop()
{
    _isPaused = true;
    _timer->stop();
}

void DrawableArea::SetModel(Model *model)
{
    _isPaused = false;
    _model = model;

    QObject::connect(_timer, SIGNAL(timeout()), this, SLOT(timeOut()));

    foreach (Robot* robot, _model->protocol()->robots()) {
        QObject::connect(robot, SIGNAL(lightChanged()), this, SLOT(update()));
        QObject::connect(robot, SIGNAL(positionChanged()), this, SLOT(update()));
//        robot->LCM();
    }
}

void DrawableArea::DrawRobots(QPainter *p)
{
    foreach (Robot* robot, _model->protocol()->robots()) {
        std::string light = robot->getLight();
        if(light == "Off") {
            p->setBrush(Qt::gray);
        } else if(light == "Red") {
            p->setBrush(Qt::red);
        } else if(light == "Blue") {
            p->setBrush(Qt::blue);
        } else if(light == "Green") {
            p->setBrush(Qt::green);
        }

        // Map values from  model to window => model doesn't depend on view.
        // Y = (X-A)/(B-A) * (D-C) + C
//        int x = robot->getPos().x/(double)200 * this->width();
//        int y = robot->getPos().y/(double)200 * this->height();
//        std::cout<<this->width() << robot->getPos().x << " " << " " <<x <<" "<<y<<std::endl;
//        p->drawEllipse(x, y, robot->_size, robot->_size);
//        p.drawEllipse(robot->getPos().x, robot->getPos().y, 25, 25);
        p->drawEllipse(robot->getPos().x, robot->getPos().y, robot->_size, robot->_size);
//        p.drawRect(robot->getPos().x, robot->getPos().y, 5, 5);
    }
}

void DrawableArea::timeOut()
{
//    std::cout << "timeOut called" << std::endl;
    foreach (Robot* robot, _model->protocol()->robots()) {
        robot->LCM();
    }
}
