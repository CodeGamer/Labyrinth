#include <QApplication>
#include "CodeKnacker.h"

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	CodeKnacker *game = new CodeKnacker();
	game->show();  
	
	return myApp.exec();
}