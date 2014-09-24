#-------------------------------------------------
#
# Project created by QtCreator 2014-09-24T05:13:50
#
#-------------------------------------------------

QT       += core gui sql webkit
QT       += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = apr_Wiz
TEMPLATE = app


SOURCES += main.cpp\
        apr_wiz.cpp \
    coldel.cpp \
    comboboxdelegate.cpp \
    datedelegate.cpp

HEADERS  += apr_wiz.h \
    coldel.h \
    comboboxdelegate.h \
    datedelegate.h

FORMS    += apr_wiz.ui
