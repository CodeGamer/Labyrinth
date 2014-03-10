win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

DESTDIR = ../Bin

CONFIG += qt

QT += core gui widgets

HEADERS += src/Mannschaft.h

SOURCES += src/Mannschaft.cpp #\
#			src/Try.cpp

#RESOURCES = Spielplan.qrc

CONFIG(debug, debug|release) {
	TARGET = SpielplanD
} else {
	TARGET = Spielplan
}