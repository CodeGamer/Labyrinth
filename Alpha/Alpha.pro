win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

CONFIG += qt

SOURCES += main.cpp

CONFIG(debug, debug|release) {
	LIBS += -lBetaD
	TARGET = AlphaD
} else {
	LIBS += -lBeta
	TARGET = Alpha
}