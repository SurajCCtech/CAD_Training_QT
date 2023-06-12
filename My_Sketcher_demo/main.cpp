#include "My_Sketcher_demo.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    My_Sketcher_demo w;
    w.setWindowTitle("Sketcher");
    w.resize(1080, 720);
    w.show();
    //w.resize(w.sizeHint());
    //int desktopArea = QApplication::desktop()->width() 
    //                * QApplication::desktop()->height();
    //int widgetArea = w.width() * w.height();
    ////w.setCentralWidget(&w);
    //w.setWindowTitle("Sketcher");
    //if (((float)widgetArea / (float)desktopArea) < 0.75f)
    //    w.show();
    //else
    //    w.showMaximized();

    return a.exec();
}
