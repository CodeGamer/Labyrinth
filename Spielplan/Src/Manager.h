#pragma once

#include <QMainWindow>

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

	private:
};