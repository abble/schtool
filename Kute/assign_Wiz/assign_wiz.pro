#-------------------------------------------------
#
# Project created by QtCreator 2014-09-17T12:54:13
#
#-------------------------------------------------

QT       += core gui sql webkit
QT       += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = assign_wiz
TEMPLATE = app


SOURCES += main.cpp\
        assign_wiz.cpp \
    comboboxdelegate.cpp \
    datedelegate.cpp \
    coldel.cpp

HEADERS  += assign_wiz.h \
    comboboxdelegate.h \
    datedelegate.h \
    coldel.h

FORMS    += assign_wiz.ui
