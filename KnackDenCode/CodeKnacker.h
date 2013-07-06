#pragma once

#include <QMainWindow>
#include "Zufallsgenerator.h"
#include "ui_CodeKnacker.h"

class CodeKnacker : public QMainWindow, public Ui::UI_CodeKnacker
{
	Q_OBJECT
	
	public:
		CodeKnacker(QMainWindow *parent = 0);
		~CodeKnacker();

		Q_SLOT void on_buttonGroupNumbers_buttonClicked(QAbstractButton * button);

	private:
		Zufallsgenerator *_zufallsGenerator;
		void generatePassword(int digits);
		void on_lineEditPassword_textChanged(const QString &text);
		void showLamp(int status);
};