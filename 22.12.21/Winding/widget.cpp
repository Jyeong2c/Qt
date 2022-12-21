#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    bCullFace = GL_FALSE;
    bCcwFront = GL_TRUE;
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

    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1,1,-1,1,-1,1);
}
void Widget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    if(bCullFace){
        glEnable(GL_CULL_FACE);
    }
    else{
        glDisable(GL_CULL_FACE);
    }

    glPushMatrix( );
        glTranslatef(-0.5f, 0.0f, 0.0f);
        // CCW
        glBegin(GL_POLYGON);
          glVertex2f(0.0, 0.5);
          glVertex2f(-0.4, -0.5);
          glVertex2f(0.4, -0.5);
        glEnd( );

        glTranslatef(1.0f, 0.0f, 0.0f);
        // CW
        glBegin(GL_POLYGON);
          glVertex2f(0.0, 0.5);
          glVertex2f(0.4, -0.5);
          glVertex2f(-0.4, -0.5);
        glEnd( );
        glPopMatrix( );

//    glFrontFace(bCcwFront?GL_CCW:GL_CW);
//    //CCW
//    glBegin(GL_POLYGON);
//    glVertex2f(-0.5,0.5);
//    glVertex2f(-0.9,-0.5);
//    glVertex2f(-0.1,-0.5);
//    glEnd();

//    //CW
//    glBegin(GL_POLYGON);
//    glColor3f(1,1,0);
//    glVertex2f(0.5,0.5);
//    glVertex2f(0.9,-0.5);
//    glVertex2f(0.1,-0.5);

//    glEnd();
//    glFlush();
}


void Widget::keyPressEvent(QKeyEvent *event)
{

    switch(event->key()){
    case Qt::Key_Up:
        bCullFace=GL_TRUE;
        break;
    case Qt::Key_Down:
        bCullFace =GL_FALSE;
        break;
    case Qt::Key_Left:
        bCcwFront =GL_TRUE;
        break;
    case Qt::Key_Right:
        bCcwFront =GL_FALSE;
        break;

    };

//    QString str = QString("Pyramid3D : x: %1,y: %2,z: %3").arg(xAngle).arg(yAngle).arg(zAngle);
    QString str= QString("Cull : %s, Front : %s").arg(bCullFace ? "ON":"OFF").arg( bCcwFront ? "CCW":"CW");
    setWindowTitle(str);
    update();
}
