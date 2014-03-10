win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

DESTDIR = ../Bin

QT += core gui widgets

CONFIG += qt

HEADERS += Src/Manager.h \
		Src/Mannschaft.h

SOURCES += Src/main.cpp \
		Src/Manager.cpp \
		Src/Mannschaft.cpp

FORMS += Forms/Manager.ui

#RESOURCES = Spielplan.qrc

CONFIG(debug, debug|release) {
	TARGET = SpielplanD
} else {
	TARGET = Spielplan
}