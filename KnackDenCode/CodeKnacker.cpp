#include <QDebug>

#include "CodeKnacker.h"

CodeKnacker::CodeKnacker(QMainWindow *parent)
: QMainWindow(parent)
{
	setupUi(this);

	_zufallsGenerator = new Zufallsgenerator();
	qDebug() << QString::number(_zufallsGenerator->generateRandomNumber());

	int digits = 3;
	generatePassword(digits);
}

CodeKnacker::~CodeKnacker()
{

}

void CodeKnacker::generatePassword(int digits)
{
	//generate Password to find
	//qsrand(QTime::currentTime().msec());
	QString test = qrand();
	labelDebug->setText(test);
}

void CodeKnacker::on_lineEditPassword_textChanged(const QString &text)
{
	//mach was, wenn was eingegeben wird.
}

void CodeKnacker::showLamp(int status)
{
	//zeige ne Lampe abhängig vom Status
}
