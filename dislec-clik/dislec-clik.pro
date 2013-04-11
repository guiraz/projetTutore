#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T14:44:44
#
#-------------------------------------------------

QT       += core gui sql

TARGET = dislec-clik
TEMPLATE = app


SOURCES +=  source/main.cpp\
            source/db.cpp \
            source/view.cpp \
            source/model.cpp \
            source/viewconnection.cpp \
            source/controller.cpp

HEADERS  += \
            source/db.h \
            source/view.h \
            source/model.h \
            source/viewconnection.h \
            source/controller.h

OBJECTS_DIR = build/object

MOC_DIR = build/moc

QMAKE_DISTCLEAN = -r build/ \
                  dislec-clik.pro.user

OTHER_FILES += \
    images/dislekclik.png
