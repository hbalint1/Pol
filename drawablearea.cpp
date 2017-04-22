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
    foreach (Robot robot, _model->_robots) {
        p.drawRect(robot._x, robot._y, 5, 5);
    }
}
