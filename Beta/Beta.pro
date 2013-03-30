win32:TEMPLATE = vclib
!win32:TEMPLATE = lib

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH += .
DEPENDPATH +=.

HEADERS += worker.h

SOURCES += worker.cpp

CONFIG(debug, debug|release) {
	TARGET = BetaD
} else {
	TARGET = Beta
}