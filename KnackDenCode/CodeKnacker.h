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

		void generatePassword(int digits);
		void on_lineEditPassword_textChanged(const QString &text);
		void showLamp(int status);
};