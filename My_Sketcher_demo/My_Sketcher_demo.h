#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qopenglwidget.h>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <GL/GLU.h>
#include "ui_My_Sketcher_demo.h"
#include <QMouseEvent>
#include <QInputDialog>
#include <QPointF>

class My_Sketcher_demo : public QMainWindow
{
    Q_OBJECT

public:
    My_Sketcher_demo(QWidget *parent = nullptr);
    ~My_Sketcher_demo();

private slots:
    void on_PBLine_clicked();
    void on_PBExit_clicked();

private:
    Ui::My_Sketcher_demoClass ui;
    void openDialog();

public:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void resizeEvent(QResizeEvent* revent);
    void paintEvent(QPaintEvent* pevent);
    
private:
    QOpenGLContext* context;
    QOpenGLFunctions* openGLfunctions;
    QPoint startPoint;
    QPoint endPoint;
    bool drawing;

};
