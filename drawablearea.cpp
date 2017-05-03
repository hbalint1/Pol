#include "drawablearea.h"

#include <QPainter>

DrawableArea::DrawableArea(QWidget *parent) : QWidget(parent)
{

}

DrawableArea::DrawableArea(Model* model)
{
    _model = model;
    foreach (Robot* robot, _model->protocol()->robots()) {
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
