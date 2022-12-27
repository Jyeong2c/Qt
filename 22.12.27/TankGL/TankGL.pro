QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets openglwidgets

CONFIG += c++17
TARGET = TankGL
TEMPLATE = app
#LIBS += -framework GLUT
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
windows{
    LIBS += -lopengl32 -lglu32 -lfreeglut -LC:\Users\KOSA\source\repos\Project5\lib\x64
    #C:\GLUT\ConsoleApplication1\lib\x64
#    LIBS += -framework GLUT
}