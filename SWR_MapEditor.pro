#-------------------------------------------------
#
# Project created by QtCreator 2015-04-12T23:53:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SWR_MapEditor
TEMPLATE = app


SOURCES += main/main.cpp \
    main/global.cpp \
    main/mainwindow.cpp \
    logic/logicgalaxy.cpp \
    logic/logicmap.cpp \
    logic/logicobject.cpp \
    logic/logicsystem.cpp \
    view/viewgalaxy.cpp \
    view/viewgraphicsscene.cpp \
    view/viewgraphicsview.cpp \
    view/viewnewmapdialog.cpp \
    view/viewsystem.cpp \
    view/viewobject.cpp

HEADERS  += main/global.h \
    main/mainwindow.h \
    logic/logicgalaxy.h \
    logic/logicmap.h \
    logic/logicobject.h \
    logic/logicsystem.h \
    view/viewgalaxy.h \
    view/viewgraphicsscene.h \
    view/viewgraphicsview.h \
    view/viewnewmapdialog.h \
    view/viewsystem.h \
    view/viewobject.h

QMAKE_CXXFLAGS += -std=c++11
