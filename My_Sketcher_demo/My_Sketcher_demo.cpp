#include "My_Sketcher_demo.h"
#include <Qmessagebox.h>
#include "LineDialog.h"

My_Sketcher_demo::My_Sketcher_demo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(3, 3);
    

    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    //context->makeCurrent();
    openGLfunctions = context->functions();

}

My_Sketcher_demo::~My_Sketcher_demo()
{}


void My_Sketcher_demo::initializeGL()
{
    
}

void My_Sketcher_demo::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void My_Sketcher_demo::paintGL()
{
    glClearColor(0.10f, 0.28f, 0.39f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void My_Sketcher_demo::resizeEvent(QResizeEvent* revent)
{
    
}

void My_Sketcher_demo::paintEvent(QPaintEvent* pevent)
{
    paintGL();
    
}

void My_Sketcher_demo::on_PBLine_clicked()
{
    //QPushButton *PBLine = new QPushButton("Open Dialog", this);
    //connect(PBLine, &QPushButton::clicked, this, &MainWindow::openDialog);
    connect(ui.PBLine, &QPushButton::clicked, this, &My_Sketcher_demo::openDialog);
}

void My_Sketcher_demo::on_PBExit_clicked()
{
    connect(ui.PBExit, &QPushButton::clicked, this, &My_Sketcher_demo::close);
}

void My_Sketcher_demo::openDialog()
{
    LineDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Retrieve values from line dialog
        QString start_x = dialog.start_x_edit->text();
        QString start_y = dialog.start_y_edit->text();
        QString end_x = dialog.end_x_edit->text();
        QString end_y = dialog.end_y_edit->text();

        // Process the line data as required
        // ...

        // Example: Display the coordinates
        QMessageBox::information(this, "Line Coordinates", QString("Start: (%1, %2)\nEnd: (%3, %4)").arg(start_x, start_y, end_x, end_y));
    }
}

