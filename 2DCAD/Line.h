#ifndef _LINE_H
#define _LINE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include "openGLWindow.h"

class Line :public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    Line(QWidget* parent = nullptr);

    void initializeGL() override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram* m_program;
    QOpenGLBuffer m_vbo;
    bool m_isLineDrawn;
    QVector2D m_lineStart;
    QVector2D m_lineEnd;

    void createLine();

};


#endif

