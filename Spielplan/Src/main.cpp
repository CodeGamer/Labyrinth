#include <QApplication>
#include "Manager.h"

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	Manager *manager = new Manager();
	manager->show();  
	
	return myApp.exec();
}