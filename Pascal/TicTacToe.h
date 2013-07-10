#pragma once

#include <QMainWindow>
#include "ui_TicTacToe.h"

class TicTacToe : public QMainWindow, public Ui::TicTacToe
{
	Q_OBJECT
	
	public:
		TicTacToe(QMainWindow *parent = 0);
		~TicTacToe();

		Q_SLOT void on_buttonNewGame_clicked();
		Q_SLOT void on_buttonExit_clicked();
		Q_SLOT void on_gameField_buttonClicked(QAbstractButton *button);
		
	private:
		int _currPlayer;
		QString _turnIndicator;
		QImage *_player1;
		QImage *_player2;
		int _score1;
		int _score2;

		void printInfo(QString string);
		void switchPlayer();
		bool checkWin();
		bool full();
};