#-------------------------------------------------
#
# Project created by QtCreator 2017-02-07T10:01:49
#
#-------------------------------------------------

QT += core gui printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OmegaSis
TEMPLATE = app
QTPLUGIN += qsqlmysql

SOURCES += main.cpp\
    mainwindow.cpp \
    frmclientes.cpp \
    funcoes.cpp \
    frmlocalizar.cpp \
    frmos.cpp \
    frmrelatorio.cpp \
    frmopsrelatorio.cpp \
    conexao.cpp \
    frmcontaspagar.cpp

HEADERS  += mainwindow.h \
    frmclientes.h \
    funcoes.h \
    frmlocalizar.h \
    conexao.h \
    frmos.h \
    frmrelatorio.h \
    frmopsrelatorio.h \
    frmcontaspagar.h

FORMS    += mainwindow.ui \
    frmclientes.ui \
    frmlocalizar.ui \
    frmos.ui \
    frmrelatorio.ui \
    frmopsrelatorio.ui \
    frmcontaspagar.ui
QT += sql
