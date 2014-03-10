#pragma once

#include <QMainWindow>

#include "ui_Manager.h"

class Manager : public QMainWindow, public Ui::UI_Manager
{
	Q_OBJECT
	
	public:
		Manager(QMainWindow *parent = 0);
		~Manager();

	private:
};