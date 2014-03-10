win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

DESTDIR = ../Bin

CONFIG += qt

QT += core gui widgets

HEADERS += src/Manager.h

SOURCES += src/main.cpp \
		src/Manager.cpp

#Forms += src/Manager.ui

#RESOURCES = Spielplan.qrc

CONFIG(debug, debug|release) {
	TARGET = SpielplanD
} else {
	TARGET = Spielplan
}