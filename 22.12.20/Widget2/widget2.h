#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

class Widget2 : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget2(QWidget *parent = nullptr);
    ~Widget2();

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
#endif // WIDGET2_H




