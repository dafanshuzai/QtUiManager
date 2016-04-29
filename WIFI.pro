#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T15:07:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WIFI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tmajor.cpp \
    tclass.cpp \
    tgroup.cpp \
    dbutil.cpp \
    addmajordialog.cpp \
    addclassdialog.cpp \
    addgroupdialog.cpp \
    tvo.cpp

HEADERS  += mainwindow.h \
    tmajor.h \
    tclass.h \
    tgroup.h \
    dbutil.h \
    addmajordialog.h \
    addclassdialog.h \
    addgroupdialog.h \
    tvo.h

FORMS    += mainwindow.ui \
    addmajordialog.ui \
    addclassdialog.ui \
    addgroupdialog.ui
