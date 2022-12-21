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
    GLboolean bEdge;
private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // WIDGET2_H
