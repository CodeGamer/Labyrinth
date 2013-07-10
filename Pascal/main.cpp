#include <QApplication>
#include "TicTacToe.h"

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	TicTacToe *game = new TicTacToe();
	game->show();  
	
	return myApp.exec();
}