#include "widget2.h"

Widget2::Widget2(QWidget *parent)
    : QOpenGLWidget(parent)
{
    rectPosX =0.0f;
    rectPosY =0.0f;
    rectSize =250;

    xStep =5.0f;
    yStep =5.0f;

    setWindowTitle("Hello OpenGL");
    resize(600,600);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),SLOT(timerFunction()));
    timer->start(1000/60);

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
    windowWidth = w;
    windowHeight =h;

    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

//    glOrtho(-1*w, w,-1*h,h,-1.0,1.0);
//    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
    glOrtho(-1,1,-1,1,-1,1);
}
void Widget2::paintGL()
{
    GLushort arPat[] = {0xaaaa,0xaaaa,0xaaaa,0xaaaa,
                       0x33ff,0x33ff,0x33ff,0x57ff,0x57ff};
    GLint arFac[] ={1,2,3,4,1,2,3,1,2};

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,1.0,1.0);


//=================================점 색상 이어주고 사이값 그라데이션 ======================
//    glBegin(GL_POLYGON);

//    glVertex2f(0.0,0.6);
//    glColor3f(1.0,0.0,0.0);
//    glVertex2f(-0.6,0.0);
//    glVertex2f(-0.4,-0.6);
//    glColor3f(0.0,1.0,0.0);
//    glVertex2f(0.4,-0.6);
//    glColor3f(0.0,0.0,1.0);
//    glVertex2f(0.6,0.0);
//    glEnd();
//================================점 찍기====================================
//    glPointSize(10.0);
//    glEnable(GL_POINT_SMOOTH);      //안티에이징 -> 모서리 부분을 둥글게 깍는다
//    glBegin(GL_POINTS);

//    glVertex2f(0.0,0.5);
//    glVertex2f(-0.5,-0.5);
//    glVertex2f(0.5,-0.5);

//    glEnd();
//======================================선그리기================================
//    glBegin(GL_LINES);
//    GLfloat x = -0.8;
//    GLfloat y = 0.4;
//    for(int i =0; i<6; i++){
//        glVertex2f(x,y);
//        x += 0.3;
//        y *= -1;
//    };

//    glEnd();

//======================================원그리기===============================
//    glLineWidth(20.0);
//    glEnable(GL_LINE_SMOOTH);
//    double rad =0.5;
//    glBegin(GL_LINE_LOOP);
//    for(int i =0; i<360;i++){
//        double angle, x,y;
//        angle = i*3.141592/180;
//        x= rad *cos(angle);
//        y= rad*sin(angle);
//        glVertex2f(x,y);
//    }
//    glEnd();

//=======================================선 굵기====================================
//    GLfloat w =1,x;
//    for(x =0.8; x>0.2; x-=0.2){
//        glLineWidth(w++);
//        glBegin(GL_LINES);
//        glVertex2f(x,0.2);
//        glVertex2f(x,0.8);

//        glEnd();
//    }

//    GLfloat w1 =1,y;
//    for(y =0.8; y>-0.8; y-=0.2){
//        glLineWidth(w1++);      //선 굵기 증가
//        glBegin(GL_LINES);      //라인 시작
//        glVertex2f(-0.8,y);     //x = -0.8 y는 감소
//        glVertex2f(0.8,y);      //x = -0.8 y는 감소

//        glEnd();
//    }
//=======================================점선===============================

    glEnable(GL_LINE_STIPPLE);
    GLfloat y;
    GLint idx =0;
    for(y =0.8; y>-0.8; y-=0.2){
        glLineStipple(arFac[idx],arPat[idx]);
        glBegin(GL_LINES);      //라인 시작
        glVertex2f(-0.8,y);     //x = -0.8 y는 감소
        glVertex2f(0.8,y);      //x = -0.8 y는 감소
        glEnd();

        idx++;
    }

    glEnd();
    glFlush();
}

void Widget2::timerFunction()
{
    if(rectPosX >windowWidth -rectSize || rectPosX < -windowWidth)
        xStep = -xStep;
    if(rectPosY >windowHeight || rectPosY < -windowHeight +rectSize)
        yStep = -yStep;

    rectPosX += xStep;
    rectPosY += yStep;

    if(rectPosX >(windowWidth -rectSize + xStep))
        rectPosX = windowWidth -rectSize-1;
    else if(rectPosX < -(windowWidth + xStep))
        rectPosX = -windowWidth -1;

    if(rectPosY >(windowHeight + yStep))
        rectPosY = windowHeight-1;
    else if(rectPosY < -(windowHeight-rectSize + yStep))
        rectPosY = -windowHeight +rectSize-1;

    repaint();
}
