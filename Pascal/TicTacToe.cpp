#include <QFile>

#include "TicTacToe.h"

TicTacToe::TicTacToe(QMainWindow *parent)
: QMainWindow(parent)
{
	setupUi(this);

	TicTacToe::setWindowIcon(QIcon(":/images/tictactoe.ico"));

	_currPlayer = 2;
	_turnIndicator = turnPlayer1->text();
	turnPlayer1->setText("");
	turnPlayer2->setText("");
	_player1 = new QImage(":/images/player1.png");
	_player2 = new QImage(":/images/player2.png");
	if(QFile("player1.png").exists())
	{
		_player1 = new QImage("player1.png");
	}
	if(QFile("player2.png").exists())
	{
		_player2 = new QImage("player2.png");
	}
	iconPlayer1->setPixmap(QPixmap::fromImage(*_player1));
	iconPlayer1->setScaledContents(true);
	iconPlayer2->setPixmap(QPixmap::fromImage(*_player2));
	iconPlayer2->setScaledContents(true);
	_score1 = 0;
	_score2 = 0;

	QListIterator<QAbstractButton *> i(gameField->buttons());
	while (i.hasNext())
		i.next()->setEnabled(false);
}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::on_buttonNewGame_clicked()
{
	QListIterator<QAbstractButton *> i(gameField->buttons());
	while (i.hasNext())
	{
		QAbstractButton *qab = i.next();
		qab->setEnabled(true);
		qab->setIcon(QIcon());
		qab->setWhatsThis("");
	}
	buttonNewGame->setEnabled(false);
	switchPlayer();
}

void TicTacToe::on_buttonExit_clicked()
{
	exit(0);
}

void TicTacToe::on_gameField_buttonClicked(QAbstractButton *button)
{
	switch(_currPlayer)
	{
	case 1:
		button->setIcon(QPixmap::fromImage(*_player1));
		button->setWhatsThis("1");
		break;
	case 2:
		button->setIcon(QPixmap::fromImage(*_player2));
		button->setWhatsThis("2");
		break;
	}
	button->setEnabled(false);
	bool won = checkWin();
	if(won || full())
	{
		if(won)
		{
			QListIterator<QAbstractButton *> i(gameField->buttons());
			while (i.hasNext())
			{
				QAbstractButton *qab = i.next();
				qab->setEnabled(false);
			}
			switch(_currPlayer)
			{
			case 1:
				scorePlayer1->setText(QString::number(++_score1));
				printInfo("Player 1 wins!");
				break;
			case 2:
				scorePlayer2->setText(QString::number(++_score2));
				printInfo("Player 2 wins!");
				break;
			}
		}
		turnPlayer1->setText("");
		turnPlayer2->setText("");
		buttonNewGame->setEnabled(true);
	}
	else
	{
		switchPlayer();
	}
}

void TicTacToe::printInfo(QString string)
{
	info->setText(string);
}

void TicTacToe::switchPlayer()
{
	switch(_currPlayer)
	{
	case 1:
		turnPlayer1->setText("");
		turnPlayer2->setText(_turnIndicator);
		printInfo("Player 2s turn...");
		_currPlayer = 2;
		break;
	case 2:
		turnPlayer1->setText(_turnIndicator);
		turnPlayer2->setText("");
		printInfo("Player 1s turn...");
		_currPlayer = 1;
		break;
	}
}

bool TicTacToe::checkWin()
{
	QString f1 = field1->whatsThis();
	QString f2 = field2->whatsThis();
	QString f3 = field3->whatsThis();
	QString f4 = field4->whatsThis();
	QString f5 = field5->whatsThis();
	QString f6 = field6->whatsThis();
	QString f7 = field7->whatsThis();
	QString f8 = field8->whatsThis();
	QString f9 = field9->whatsThis();

	if(f1 != "" && f1 == f2 && f1 == f3)
		return true;
	if(f4 != "" && f4 == f5 && f4 == f6)
		return true;
	if(f7 != "" && f7 == f8 && f7 == f9)
		return true;
	if(f1 != "" && f1 == f4 && f1 == f7)
		return true;
	if(f2 != "" && f2 == f5 && f2 == f8)
		return true;
	if(f3 != "" && f3 == f6 && f3 == f9)
		return true;
	if(f1 != "" && f1 == f5 && f1 == f9)
		return true;
	if(f3 != "" && f3 == f5 && f3 == f7)
		return true;

	return false;
}

bool TicTacToe::full()
{
	QListIterator<QAbstractButton *> i(gameField->buttons());
	while(i.hasNext())
	{
		QAbstractButton *qab = i.next();
		if(qab->isEnabled())
		{
			return false;
		}
	}
	printInfo("Tie, play a new game!");
	return true;
}