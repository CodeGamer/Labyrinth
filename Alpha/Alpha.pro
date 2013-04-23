win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH +=.
DEPENDPATH +=.

SOURCES += main.cpp

CONFIG(debug, debug|release) {
	LIBS += -L../Bin -lBetaD
	TARGET = AlphaD
} else {
	LIBS += -L../Bin -lBeta
	TARGET = Alpha
}

# Workaround for a QMake bug to fix up the project names
win32:!Debug|Win32:!Release|Win32 {
    CONFIG -= debug
    CONFIG += release
} 