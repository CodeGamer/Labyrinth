#include <QApplication>
#include "TicTacToe.h"

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	Test *game = new Test();
	game->show();  
	
	return myApp.exec();
}