CONFIG += qt

QT += core gui sql widgets

TARGET = dislec-clik
TEMPLATE = app


SOURCES +=  source/main.cpp\
            source/db.cpp \
            source/view.cpp \
            source/model.cpp \
            source/viewconnection.cpp \
            source/controller.cpp \
            source/modelconnection.cpp \
            source/viewnewuser.cpp \
            source/modelnewuser.cpp

HEADERS  += source/db.h \
            source/view.h \
            source/model.h \
            source/viewconnection.h \
            source/controller.h \
            source/modelconnection.h \
            source/viewnewuser.h \
            source/modelnewuser.h

OTHER_FILES += images/dislekclik.png

DESTDIR = "$$_PRO_FILE_PWD_"
OBJECTS_DIR = build/object
MOC_DIR = build/moc

QMAKE_DISTCLEAN = -rf build/ \
                  dislec-clik.pro.user \
                  db/
