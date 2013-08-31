win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH +=.
INCLUDEPATH += ../EdenEngine/Include
INCLUDEPATH += "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
DEPENDPATH +=.

SOURCES += main.cpp \
		Test.cpp

HEADERS += Test.h

FORMS += Test.ui

LIBS += "-LC:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86"

CONFIG(debug, debug|release) {
	LIBS += -L../EdenEngine/Lib/Debug -lEdenEngineLibrary
	TARGET = 3DD
} else {
	LIBS += -L../EdenEngine/Lib/Release -lEdenEngineLibrary
	TARGET = 3D
}

# Workaround for a QMake bug to fix up the project names
win32:!Debug|Win32:!Release|Win32 {
    CONFIG -= debug
    CONFIG += release
} 