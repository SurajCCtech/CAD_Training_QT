#include "DCAD.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DCAD w;
    w.setWindowTitle("2DCAD App");
    w.show();
    return a.exec();
}