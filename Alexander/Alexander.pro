win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH +=.
DEPENDPATH +=.

SOURCES += main.cpp \
		Mini.cpp

HEADERS += Mini.h

FORMS += Mini.ui

CONFIG(debug, debug|release) {
	TARGET = AlexanderD
} else {
	TARGET = Alexander
}

# Workaround for a QMake bug to fix up the project names
win32:!Debug|Win32:!Release|Win32 {
    CONFIG -= debug
    CONFIG += release
} 