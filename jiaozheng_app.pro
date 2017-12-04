#-------------------------------------------------
#
# Project created by QtCreator 2016-12-20T15:16:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jiaozheng_app
TEMPLATE = app

SOURCES += main.cpp\
    func.cpp \
    mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

INCLUDEPATH += D:/opencv3.3.1/opencv_use/include\
               D:/opencv3.3.1/opencv_use/include/opencv\
               D:/opencv3.3.1/opencv_use/include/opencv2
LIBS += -L D:/opencv3.3.1/opencv_use/lib/libopencv_*.a

