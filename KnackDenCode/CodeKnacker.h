#pragma once

#include <QMainWindow>

#include "ui_CodeKnacker.h"

class CodeKnacker : public QMainWindow, public UI_CodeKnacker
{
	Q_OBJECT
	
	public:
		CodeKnacker(QMainWindow *parent = 0);
		~CodeKnacker();
		
		//TODO

	private:
		//TODO
};