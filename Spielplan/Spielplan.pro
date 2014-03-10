win32:TEMPLATE = vcapp
!win32:TEMPLATE = app

DESTDIR = ../Bin

QT += core gui widgets

CONFIG += qt

HEADERS += Src/Manager.h \
		Src/MannschaftEditor.h \
		Src/MannschaftListeEditor.h \
		Src/Mannschaft.h

SOURCES += Src/main.cpp \
		Src/Manager.cpp \
		Src/MannschaftEditor.cpp \
		Src/MannschaftListeEditor.cpp \
		Src/Mannschaft.cpp

FORMS += Forms/Manager.ui \
		Forms/MannschaftEditor.ui \
		Forms/MannschaftListeEditor.ui

#RESOURCES = Spielplan.qrc

CONFIG(debug, debug|release) {
	TARGET = SpielplanD
} else {
	TARGET = Spielplan
}