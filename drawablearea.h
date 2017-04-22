#ifndef DRAWABLEAREA_H
#define DRAWABLEAREA_H

#include <QWidget>

#include <Model/model.h>

class DrawableArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawableArea(QWidget *parent = 0);
    DrawableArea(Model* model);
    void paintEvent(QPaintEvent *e);
    Model* _model;
};

#endif // DRAWABLEAREA_H
