#pragma once

#include <QMainWindow>

#include "ui_CodeKnacker.h"

class CodeKnacker : public QMainWindow, public Ui::UI_CodeKnacker
{
	Q_OBJECT
	
	public:
		CodeKnacker(QMainWindow *parent = 0);
		~CodeKnacker();

	private:
};