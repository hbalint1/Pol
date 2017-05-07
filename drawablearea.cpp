#include "drawablearea.h"
#include <QPainter>
#include <QTimer>
#include <iostream>

DrawableArea::DrawableArea(QWidget *parent) : QWidget(parent)
{
}

DrawableArea::DrawableArea(Model* model)
{
    _model = model;

    // Setting a repeating timer that calls LCM on each robot.
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timeOut()));
    timer->start(1000);

    foreach (Robot* robot, _model->protocol()->robots()) {
        QObject::connect(robot, SIGNAL(lightChanged()), this, SLOT(update()));
        QObject::connect(robot, SIGNAL(positionChanged()), this, SLOT(update()));
        robot->LCM();
    }
}

void DrawableArea::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);

    // Drawing robots on screen
    foreach (Robot* robot, _model->protocol()->robots()) {
        std::string light = robot->getLight();
        if(light == "Off") {
            p.setBrush(Qt::gray);
        } else if(light == "Red") {
            p.setBrush(Qt::red);
        } else if(light == "Blue") {
            p.setBrush(Qt::blue);
        } else if(light == "Green") {
            p.setBrush(Qt::green);
        }

        p.drawRect(robot->getPos().x, robot->getPos().y, 5, 5);
    }
}

void DrawableArea::timeOut()
{
    std::cout << "timeOut called" << std::endl;
    foreach (Robot* robot, _model->protocol()->robots()) {
        robot->LCM();
    }
}
