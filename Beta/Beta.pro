win32:TEMPLATE = vclib
!win32:TEMPLATE = lib

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH +=.
DEPENDPATH +=.

HEADERS += worker.h

SOURCES += worker.cpp

CONFIG(debug, debug|release) {
	TARGET = BetaD
} else {
	TARGET = Beta
}

# Workaround for a QMake bug to fix up the project names
win32:!Debug|Win32:!Release|Win32 {
    CONFIG -= debug
    CONFIG += release
} 