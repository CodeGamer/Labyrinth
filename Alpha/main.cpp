#include <QApplication>
#include <QLabel>
#include "../Beta/worker.h"

int main(int argc, char* argv[])
{
	Worker *myWorker = new Worker();
	QApplication myApp(argc, argv);
	QLabel* myLabel = new QLabel(myWorker->_text);
	myLabel->resize(80, 30);
	myLabel->show();
	  
	return myApp.exec();
}