#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Model/model.h"
#include "drawablearea.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startBtn_clicked();

    void on_pauseBtn_clicked();

    void on_fpsSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Model* _model;
    DrawableArea* _drawableArea;
};

#endif // MAINWINDOW_H
