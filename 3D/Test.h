#pragma once

#include <QMainWindow>
#include "ui_TicTacToe.h"

class Test : public QMainWindow, public Ui::Test
{
	Q_OBJECT
	
	public:
		Test(QMainWindow *parent = 0);
		~Test();

	private:
};