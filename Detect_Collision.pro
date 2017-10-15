#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T22:03:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Detect_Collision
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        mainwindow.cpp \
    area.cpp \
    CCircle.cpp \
    CCollidingPair.cpp \
    CObject.cpp \
    CPoint.cpp \
    CRectangle.cpp \
    CScene.cpp \
    CSection.cpp \
    CTrapeze.cpp \
    CTriangle.cpp \
    QTriangle.cpp \
    QRectangle.cpp \
    main.cpp


HEADERS  += mainwindow.h \
    area.h \
    CCircle.h \
    CCollidingPair.h \
    CObject.h \
    CPoint.h \
    CRectangle.h \
    CScene.h \
    CSection.h \
    CShape.h \
    CTrapeze.h \
    CTriangle.h \
    Statics.h \
    QTriangle.h \
    QRectangle.h

FORMS    += mainwindow.ui

DISTFILES +=
