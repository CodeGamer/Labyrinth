#pragma once

/* Qt */
#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

/* Spielplan */
#include "Mannschaft.h"

/* local */
#include "ui_Manager.h"

class Manager : public QMainWindow, public Ui::UI_Manager
{
	Q_OBJECT
	
	public:
		Manager(QMainWindow *parent = 0);
		~Manager();

		Q_SLOT void loadSpielplan();
		Q_SLOT void saveSpielplan();
		Q_SLOT void exitManager();
		Q_SLOT void loadMannschaftsliste();
		Q_SLOT void saveMannschaftsliste();
		Q_SLOT void editMannschaftsliste();

		Q_SLOT void listeMannschaftenChanged(QList<Mannschaft*> *liste);

		QList<Mannschaft*> *_listeMannschaften;

	private:
		QString _fileformat;
		bool loadFile(int i, QString filename);
		bool saveFile(int i, QString filename);
		Mannschaft* parseMannschaft(QXmlStreamReader &xml);
};