#include "widget2.h"

Widget2::Widget2(QWidget *parent)
    : QOpenGLWidget(parent)
{
    bEdge = GL_FALSE;

    setWindowTitle("OpenGL EdgeFlag3D");
    resize(600,600);

}

Widget2::~Widget2()
{
}

void Widget2::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,0.0);
}
void Widget2::resizeGL(int w, int h)
{

    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1,1,-1,1,-1,1);
}
void Widget2::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glEdgeFlag(TRUE);

    glBegin(GL_TRIANGLES);
    if(bEdge)
        glEdgeFlag(TRUE);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.5,0.5);

    if(bEdge)
        glEdgeFlag(FALSE);
    glVertex2f(-0.5,-0.5);

    glVertex2f(0.0,0.0);
    if(bEdge)
        glEdgeFlag(TRUE);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);

    if(bEdge)
        glEdgeFlag(FALSE);
    glVertex2f(0.0,0.0);
    if(bEdge)
        glEdgeFlag(TRUE);
    glVertex2f(-0.5,-0.5);
    if(bEdge)
        glEdgeFlag(FALSE);
    glVertex2f(0.5,-0.5);

    glEnd();
    glFlush();
}


void Widget2::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        bEdge =GL_TRUE;
        break;
    case Qt::Key_Down:
        bEdge =GL_FALSE;
        break;
    };
    update();
}
