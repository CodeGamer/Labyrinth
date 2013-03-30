win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

DESTDIR = ../Bin
INCLUDEPATH += .
DEPENDPATH +=.

SOURCES += main.cpp

CONFIG(debug, debug|release) {
	LIBS += -LE:\ThirdParty\qt-everywhere-opensource-src-5.0.1\qtbase\lib -lQt5Gui
	LIBS += -L../Bin -lBetaD
	TARGET = AlphaD
} else {
	LIBS += -LE:\ThirdParty\qt-everywhere-opensource-src-5.0.1\qtbase\lib -lQt5Gui
	LIBS += -L../Bin -lBeta
	TARGET = Alpha
}