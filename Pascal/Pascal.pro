win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH +=.
DEPENDPATH +=.

SOURCES += main.cpp \
		TicTacToe.cpp

HEADERS += TicTacToe.h

FORMS += TicTacToe.ui

RESOURCES = Pascal.qrc

CONFIG(debug, debug|release) {
	TARGET = PascalD
} else {
	TARGET = Pascal
}

# Workaround for a QMake bug to fix up the project names
win32:!Debug|Win32:!Release|Win32 {
    CONFIG -= debug
    CONFIG += release
} 