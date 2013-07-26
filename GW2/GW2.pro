win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH +=.
DEPENDPATH +=.

SOURCES += main.cpp \
		Frame.cpp \
		GW2Communicator.cpp

HEADERS += Frame.h \
		GW2Communicator.h

FORMS += Frame.ui

RESOURCES = GW2.qrc

CONFIG(debug, debug|release) {
	TARGET = GW2_OverlayD
} else {
	TARGET = GW2_Overlay
}

# Workaround for a QMake bug to fix up the project names
win32:!Debug|Win32:!Release|Win32 {
    CONFIG -= debug
    CONFIG += release
} 