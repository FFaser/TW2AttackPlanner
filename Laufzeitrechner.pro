#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T14:36:26
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Laufzeitrechner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datamodel.cpp \
    dorf.cpp \
    customdelegate.cpp \
    dorfparser.cpp \
    inputdialog.cpp \
    myfileio.cpp \
    dorfdatabase.cpp \
    calculatedistance.cpp \
    tabledatamodel.cpp \
    tablecustomdelegate.cpp \
    moderatormodel.cpp \
    moderatordelegate.cpp \
    moderatordialog.cpp \
    myenumhelper.cpp \
    clickableicon.cpp \
    clickableiconholder.cpp \
    tablevieweditor.cpp \
    markdelegateitem.cpp \
    dorfmapdialog.cpp

HEADERS  += mainwindow.h \
    datamodel.h \
    dorf.h \
    customdelegate.h \
    dorfparser.h \
    inputdialog.h \
    myfileio.h \
    dorfdatabase.h \
    calculatedistance.h \
    tabledatamodel.h \
    tablecustomdelegate.h \
    moderatormodel.h \
    moderatordelegate.h \
    moderatordialog.h \
    myenumhelper.h \
    clickableicon.h \
    clickableiconholder.h \
    tablevieweditor.h \
    markdelegateitem.h \
    dorfmapdialog.h

FORMS    += mainwindow.ui \
    inputdialog.ui \
    moderatordialog.ui \
    dorfmapdialog.ui
