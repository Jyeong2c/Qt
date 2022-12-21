#ifndef WIDGET3_H
#define WIDGET3_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

class Widget3 : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget3(QWidget *parent = nullptr);
    ~Widget3();
    GLfloat alpha;
    GLenum src;
    GLenum dest;

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // WIDGET3_H
