#-------------------------------------------------
#
# Project created by QtCreator 2014-09-24T06:00:29
#
#-------------------------------------------------

QT       += core gui sql webkit
QT       += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets		

TARGET = art_Wiz
TEMPLATE = app

SOURCES += main.cpp\
        art_wiz.cpp \
    coldel.cpp \
    comboboxdelegate.cpp

ICON = art_Wiz.ico

RC_FILE = art_Wiz.rc

HEADERS  += art_wiz.h \
    coldel.h \
    comboboxdelegate.h

FORMS    += art_wiz.ui
