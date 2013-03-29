win32:TEMPLATE = vclib
!win32:TEMPLATE = lib

SOURCES += worker.cpp

HEADERS += worker.h

CONFIG(debug, debug|release) {
	TARGET = BetaD
} else {
	TARGET = Beta
}