#ifndef DRAWABLEAREA_H
#define DRAWABLEAREA_H

#include <QWidget>

#include <Model/model.h>

class DrawableArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawableArea(QWidget *parent = 0);
    ~DrawableArea();
    void paintEvent(QPaintEvent *e);
    void Run(int fps);
    void Pause(int fps);
    void Stop();
    void SetModel(Model* model);

private:
    void DrawRobots(QPainter* p);

public:
    Model* _model;
    QTimer* _timer;

private:
    bool _isPaused;


private slots:
    void timeOut();
};

#endif // DRAWABLEAREA_H
