#include "widget.h"
#include <GL/glut.h>


#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle =0,yAngle =0,zAngle =0;
    setWindowTitle("OpenGL GLU3D");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);
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

    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glRotatef(xAngle,1.0f,0.0f,0.0f);
    glRotatef(yAngle,0.0f,1.0f,0.0f);
    glRotatef(xAngle,0.0f,0.0f,1.0f);

    GLUquadricObj * pQuad;
    pQuad = gluNewQuadric();
    gluQuadricDrawStyle(pQuad,GLU_LINE);

    gluSphere(pQuad,0.3,20,20);
    glColor3f(0.0f, 0.0f, 1.0f);
// 와이어 큐브
    glPushMatrix();
    glTranslatef(-0.6,0.6,0.0);
//    glutWireCube(0.4);
    gluCylinder(pQuad,0.2,0.2,0.5,20,20);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 1.0f);
// 와이어 구
    glPushMatrix();
    glTranslatef(-0.6,-0.6,0.0);
    //glutSolidSphere(0.3,20,20);
    gluCylinder(pQuad,0.2,0.2,0.5,20,20);
    glPopMatrix();

    //와이어 원뿔
    glPushMatrix();
    glTranslatef(0.6,-0.6,0.0);
    gluDisk(pQuad,0.0,0.3,10,10);
    glPopMatrix();

    //와이어 도너츠
    glPushMatrix();
    glTranslatef(0.6,-0.6,0.0);
//    glutWireTorus(0.1,0.2,20,20);
    gluDisk(pQuad, 0.0,0.3,10,10);
    glPopMatrix();

    gluDeleteQuadric(pQuad);
    glPopMatrix();
    glFlush();
}

