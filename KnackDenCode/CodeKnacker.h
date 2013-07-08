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

		Q_SLOT void on_buttonGroupNumbers_buttonClicked(QAbstractButton *button);
		Q_SLOT void on_lineEditPassword_textChanged(const QString &text);
		Q_SLOT void on_codeLength_valueChanged(int codeLength);
		Q_SLOT void on_newStartButton_clicked();
		Q_SLOT void on_resetButton_clicked();

	private:
		Zufallsgenerator *_zufallsGenerator;
		QString _password;
		int _digits;
		QString generatePassword(int digits);
		void checkInput(QString input);
		void showLamp(int status);
};