#include <qapplication.h>
#include <qlabel.h>

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	QLabel* myLabel = new QLabel("Hello Alpha");
	myLabel->resize(80, 30);
	myLabel->show();
	  
	return myApp.exec();
}