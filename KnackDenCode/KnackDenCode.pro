win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH +=.
DEPENDPATH +=.

SOURCES += main.cpp \
		CodeKnacker.cpp \
		Zufallsgenerator.cpp

HEADERS += CodeKnacker.h \
		Zufallsgenerator.h

FORMS += CodeKnacker.ui

CONFIG(debug, debug|release) {
	TARGET = CodeKnackerD
} else {
	TARGET = CodeKnacker
}

# Workaround for a QMake bug to fix up the project names
win32:!Debug|Win32:!Release|Win32 {
    CONFIG -= debug
    CONFIG += release
} 