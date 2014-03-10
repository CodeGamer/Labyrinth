win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

DESTDIR = ../Bin

CONFIG += qt

QT += core gui widgets

#HEADERS += src/Try.h

#SOURCES += src/Test.cpp \
#		src/Try.cpp

#RESOURCES = Spielplan.qrc

CONFIG(debug, debug|release) {
	TARGET = SpielplanD
} else {
	TARGET = Spielplan
}