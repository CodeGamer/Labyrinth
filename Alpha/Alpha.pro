win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

SOURCES += main.cpp

CONFIG(debug, debug|release) {
	LIBS += -L../BetaD
	TARGET = AlphaD
} else {
	LIBS += -L../Beta
	TARGET = Alpha
}