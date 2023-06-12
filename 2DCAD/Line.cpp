#include "Line.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QMouseEvent>



static const char* vertexShaderSource =
"attribute highp vec4 posAttr;\n"
"attribute lowp vec4 colAttr;\n"
"varying lowp vec4 col;\n"
"uniform highp mat4 matrix;\n"
"void main() {\n"
"   col = colAttr;\n"
"   gl_Position = matrix * posAttr;\n"
"}\n";

static const char* fragmentShaderSource =
"varying lowp vec4 col;\n"
"void main() {\n"
"   gl_FragColor = col;\n"
"}\n";


Line::Line(QWidget* parent) : QOpenGLWidget(parent), m_program(nullptr), m_isLineDrawn(false)
{
}



//void Line::Render()
//{
//    const qreal retinaScale = devicePixelRatio();
//    glViewport(0, 0, width() * retinaScale, height() * retinaScale);
//
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    m_program->bind();
//
//    QMatrix4x4 matrix;
//    // Same matrix transformation code as before
//
//    m_program->setUniformValue(m_matrixUniform, matrix);
//
//    // Draw the line if it's drawn
//    if (m_isLineDrawn)
//    {
//        GLfloat vertices[] = {
//            m_lineStart.x(), m_lineStart.y(),
//            m_lineEnd.x(), m_lineEnd.y()
//        };
//
//        GLfloat colors[] = {
//            1.0f, 0.0f, 0.0f,
//            0.0f, 1.0f, 0.0f
//        };
//
//        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
//        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);
//
//        glEnableVertexAttribArray(0);
//        glEnableVertexAttribArray(1);
//
//        glDrawArrays(GL_LINES, 0, 2);
//
//        glDisableVertexAttribArray(1);
//        glDisableVertexAttribArray(0);
//    }
//
//    m_program->release();
//
//    ++m_frame;
//}
//
//void Line::mousePressEvents(QMouseEvent* event)
//{
//    if (event->button() == Qt::LeftButton)
//    {
//        if (!m_isLineDrawn)
//        {
//            // Set the line start position
//            m_lineStart = QVector2D(event->localPos());
//            m_isLineDrawn = true;
//        }
//        else
//        {
//            // Set the line end position
//            m_lineEnd = QVector2D(event->localPos());
//            m_isLineDrawn = false;
//        }
//
//      
//    }
//}



void Line::initializeGL()
{

	initializeOpenGLFunctions();


	m_program = new QOpenGLShaderProgram(this);
	m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	m_program->link();
	m_posAttr = m_program->attributeLocation("posAttr");
	m_colAttr = m_program->attributeLocation("colAttr");
	m_matrixUniform = m_program->uniformLocation("matrix");
}

void Line::paintGL()
{
	/*glClear(GL_COLOR_BUFFER_BIT);
	m_program->bind();

	m_vbo.bind();
	m_program->enableAttributeArray(m_posAttr);
	m_program->setAttributeBuffer(m_posAttr, GL_FLOAT, 0, 2, 0);
	glDrawArrays(GL_LINES, 0, 2);
	m_program->disableAttributeArray(m_posAttr);
	m_vbo.release();

	m_program->release();*/


	const qreal retinaScale = devicePixelRatio();
	glViewport(0, 0, width() * retinaScale, height() * retinaScale);

	glClear(GL_COLOR_BUFFER_BIT);

	m_program->bind();

	QMatrix4x4 matrix;
	// Same matrix transformation code as before

	m_program->setUniformValue(m_matrixUniform, matrix);

	// Draw the line if it's drawn
	if (m_isLineDrawn)
	{
		GLfloat vertices[] = {
			m_lineStart.x(), m_lineStart.y(),
			m_lineEnd.x(), m_lineEnd.y()
		};

		GLfloat colors[] = {
			1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f
		};

		glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
		glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glDrawArrays(GL_LINES, 0, 2);

		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(0);
	}

	m_program->release();

	// ++m_frame;
}

void Line::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		if (!m_isLineDrawn)
		{
			// Set the line start position
			m_lineStart = QVector2D(event->localPos());
			m_isLineDrawn = true;
		}
		else
		{
			// Set the line end position
			m_lineEnd = QVector2D(event->localPos());
			m_isLineDrawn = false;
		}




		createLine();
		update();
	}

	//if (event->button() == Qt::LeftButton)
	//{
	//	// Update line coordinates based on mouse click position
	//	float x = event->x();
	//	float y = height() - event->y(); // Flip the y-coordinate

	//	if (!m_isLineDrawn)
	//	{
	//		Line newLine;
	//		newLine.startX = -1.0f + (2.0f * x / width());
	//		newLine.startY = -1.0f + (2.0f * y / height());
	//		newLine.endX = newLine.startX;
	//		newLine.endY = newLine.startY;
	//		lines.push_back(newLine);

	//		m_isLineDrawn = true;
	//	}
	//	else
	//	{
	//		Line& currentLine = lines.back();
	//		currentLine.endX = -1.0f + (2.0f * x / width());
	//		currentLine.endY = -1.0f + (2.0f * y / height());
	//		m_isLineDrawn = false;
	//	}
	//}

	update(); // Trigger a repaint
}
void Line::createLine()
{
	QVector<QVector2D> vertices;

	if (m_isLineDrawn)
	{
		vertices.append(m_lineStart);
		vertices.append(m_lineEnd);
	}

	m_vbo.create();
	m_vbo.bind();
	m_vbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector2D));
	m_vbo.release();
}