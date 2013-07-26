#include <QApplication>
#include "Frame.h"

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	Frame *app = new Frame();
	app->show();  
	
	return myApp.exec();
}