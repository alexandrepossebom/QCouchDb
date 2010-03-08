# -------------------------------------------------
# Project created by QtCreator 2010-03-08T15:41:49
# -------------------------------------------------
QT -= gui
QT += network
TARGET = QCouchDb
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    couchutil.cpp
HEADERS += couchutil.h
LIBS += -lqjson
INCLUDEPATH += /usr/include/qjson/
