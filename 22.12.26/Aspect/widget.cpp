#include "widget.h"
#include <GL/glu.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    Action = 1;

    setWindowTitle("OpenGL Pyramid3D");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,1.0);
}
void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    if(h==0)return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspect = (GLfloat)w/(GLfloat)h;
    if(w>h){
        glOrtho(-1.0*aspect,1.0*aspect,-1.0,1.0,1.0,-1.0);

    }else{
        glOrtho(-1.0,1.0,-1.0/aspect,1.0/aspect,1.0,-1.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void Widget::paintGL()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0.0,1.0,0.0);
    glRectf(-1.0,1.0,1.0,-1.0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,0.5);
    glVertex2f(-0.5,-0.5);
     glVertex2f(0.5,-0.5);
    glEnd();
    glFlush();
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);



    switch(event->key()){
    case Qt::Key_1:
        Action =1;
        break;
    case Qt::Key_2:
        Action =2;
        break;
    case Qt::Key_3:
        Action =3;
        break;
    case Qt::Key_4:
        Action =4;
        break;
    };

    resize(width(),height());

    update();
}
