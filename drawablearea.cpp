#include "drawablearea.h"

#include <QPainter>

DrawableArea::DrawableArea(QWidget *parent) : QWidget(parent)
{

}

DrawableArea::DrawableArea(Model* model)
{
    _model = model;
}

void DrawableArea::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::red);

    // Drawing robots on screen
    foreach (Robot* robot, _model->_robots) {
        p.drawRect(robot->x(), robot->y(), 5, 5);
    }
}
