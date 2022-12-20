#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

class widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();
private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);
};
#endif // WIDGET_H
