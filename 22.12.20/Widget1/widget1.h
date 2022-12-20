#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>


class Widget1 : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    Widget1(QWidget *parent = nullptr);
    ~Widget1();

    GLfloat rectPosX;
    GLfloat rectPosY;
    GLfloat rectSize;

    GLfloat xStep;
    GLfloat yStep;

    GLfloat windowWidth;
    GLfloat windowHeight;

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);
public slots:
    void timerFunction();
};
#endif // WIDGET1_H



