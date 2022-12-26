#include "widget.h"
#include <GL/glut.h>
#include <math.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
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

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
//============================================위치 이동=================
    //    GLfloat trans[16] = {
    //        1,0,0,0,
    //        0,1,0,0,
    //        0,0,1,0,
    //        0.5,0.5,0,1
    //    };
    //  glMultMatrixf(trans);
    //    glutWireTeapot(0.2);
    //    glPopMatrix();
    //    glFlush();
//=============================================크기======================
    //        GLfloat scale[16] = {
    //            1.5,0,0,0,
    //            0,1.5,0,0,
    //            0,0,1,0,
    //            0,0,0,1
    //        };
    //glMultMatrixf(scale);
    //    glutWireTeapot(0.2);
    //    glPopMatrix();
    //    glFlush();
//=======================================각도1===================================
    //    GLfloat cos1 = cos(45.0*3.14/180);
    //    GLfloat sin1 = sin(45.0*3.14/180);
    //    GLfloat rotate[16] = {
    //        cos1,sin1,0,0,
    //        -sin1,cos1,0,0,
    //        0,0,1,0,
    //        0,0,0,1
    //    };
    //    glMultMatrixf(rotate);
    //    glutWireTeapot(0.2);
    //    glPopMatrix();
    //    glFlush();

//=========================================각도2==================================
    //    GLfloat angle =45.0;
    //    GLfloat value = angle *M_PI/180;

    //    GLfloat rotate1[16] = {
    //        cos(value),-sin(value),0,0,
    //        sin(value),cos(value),0,0,
    //        0,0,1,0,
    //        0,0,0,1
    //    };
    //    glMultMatrixf(rotate1);
    //    glutWireTeapot(0.2);
    //    glPopMatrix();
    //    glFlush();
//========================================이동 크기(복합 변환)============
//    GLfloat transScale[16] = {
//        1.5,0,0,0,
//        0,1.5,0,0,
//        0,0,1,0,
//        0.5,0.5,0,1
//    };

//    glMultMatrixf(transScale);
//    glutWireTeapot(0.2);
//    glPopMatrix();
//    glFlush();
//=====================================찌그러진 주전자===================행렬식:(x'= x+0.5y)
    GLfloat sheer[16] = {
        1,0,0,0,
        0.5,1,0,0,
        0,0,1,0,
        0,0,0,1
    };

    glMultMatrixf(sheer);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();

}

