#include "widget.h"
#include <GL/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{

    red =green = blue = 0.2;
    xAngle =yAngle =zAngle =0;

    setWindowTitle("OpenGL Pyramid3D");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,0.0);
}
void Widget::resizeGL(int w, int h)
{

    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1,1,-1,1,-1,1);
}
void Widget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    //    glMatrixMode(GL_MODELVIEW);


    //조명 모델 설정
    glEnable(GL_LIGHTING);
    GLfloat arLight[]= {red,green,blue,1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,arLight);

    glPushMatrix();
    glRotatef(xAngle,1.0f,0.0f,0.0f);
    glRotatef(yAngle,0.0f,1.0f,0.0f);
    glRotatef(zAngle,0.0f,0.0f,1.0f);

    glutSolidTeapot(0.5);
    glPopMatrix();

    glFlush();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);

    switch(event->key()){




    case Qt::Key_A:
        yAngle += 2;
        break;
    case Qt::Key_S:
        yAngle -= 2;
        break;
    case Qt::Key_D:
        xAngle += 2;
        break;
    case Qt::Key_F:
        xAngle -= 2;
        break;
    case Qt::Key_G:
        zAngle += 2;
        break;
    case Qt::Key_H:
        zAngle -= 2;
        break;
    case Qt::Key_J:
        xAngle=yAngle=zAngle = 0.0;
        break;
    case Qt::Key_1:
        red += 0.1;
        break;
    case Qt::Key_2:
        red -= 0.1;
        break;
    case Qt::Key_3:
        green += 0.1;
        break;
    case Qt::Key_4:
        green -= 0.1;
        break;
    case Qt::Key_5:
        blue += 0.1;
        break;
    case Qt::Key_6:
        blue -= 0.1;
        break;
    case Qt::Key_7:
        red=green= blue = 0.5;
        break;
    };

    QString str = QString("(%.0f,%.0f,%.0f)""(%.1f,%.1f,%.1f)").arg(xAngle).arg(yAngle).arg(zAngle).arg(red).arg(green).arg(blue);
    setWindowTitle(str);
    update();
}
