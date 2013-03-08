#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T14:44:44
#
#-------------------------------------------------

QT       += core gui sql

TARGET = dislec-clik
TEMPLATE = app


SOURCES +=  source/main.cpp\
            source/mainwindow.cpp \
            source/db.cpp

HEADERS  += source/mainwindow.h \
            source/db.h

OBJECTS_DIR = build/object

MOC_DIR = build/moc

QMAKE_DISTCLEAN = -r build/ \
                  dislec-clik.pro.user
