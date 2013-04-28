#include <QApplication>
#include "Mini.h"

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	Mini *myGame = new Mini();
	myGame->show();  
	
	return myApp.exec();
}