# -------------------------------------------------
# Project created by QtCreator 2015-03-15T23:51:02
# -------------------------------------------------
QT += sql
QT -= gui
TARGET = SendMail
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += src/main.cpp \
    src/cprtfcdatabase.cpp
HEADERS += src/cprtfcdatabase.h
unix {
    UI_DIR = build/ui
    OBJECTS_DIR = build/obj
    MOC_DIR = build/moc
}
use_real_mysql {
    SOURCES += src/qsql_mysql.cpp
    HEADERS += src/qsql_mysql.h
    DEFINES += USE_REAL_MYSQL_CONNECTION
    LIBS += -L/usr/lib/mysql \
        -L/usr/lib64/mysql \
        -lmysqlclient
}
