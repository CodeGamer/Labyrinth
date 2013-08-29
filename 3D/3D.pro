win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH +=.
DEPENDPATH +=.

SOURCES += main.cpp \
		Test.cpp

HEADERS += Test.h

FORMS += Test.ui

CONFIG(debug, debug|release) {
	TARGET = 3DD
} else {
	TARGET = 3D
}

# Workaround for a QMake bug to fix up the project names
win32:!Debug|Win32:!Release|Win32 {
    CONFIG -= debug
    CONFIG += release
} 