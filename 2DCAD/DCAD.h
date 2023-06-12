#ifndef _DCAD_H
#define _DCAD_H

#include <QtWidgets/QMainWindow>
#include <QObject>
#include "openGLWindow.h"
#include "ui_DCAD.h"

class DCAD : public QMainWindow
{
    Q_OBJECT

public:
    DCAD(QWidget *parent = nullptr);
    ~DCAD();

    QList<QString> lineNames;
    int linecount = 1;
    //QStandardItemModel* model;

private:
    Ui::DCADClass ui;
    OpenGLWindow* openglWindow;

//private slots:
};


#endif