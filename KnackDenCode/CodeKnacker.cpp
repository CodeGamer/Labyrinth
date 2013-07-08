#include <QDebug>
#include "qmath.h"

#include "CodeKnacker.h"

CodeKnacker::CodeKnacker(QMainWindow *parent)
: QMainWindow(parent)
{
	setupUi(this);

	_zufallsGenerator = new Zufallsgenerator();

	on_codeLength_valueChanged(codeLength->value());
	
	button0->setShortcut(QKeySequence("0"));
	button1->setShortcut(QKeySequence("1"));
	button2->setShortcut(QKeySequence("2"));
	button3->setShortcut(QKeySequence("3"));
	button4->setShortcut(QKeySequence("4"));
	button5->setShortcut(QKeySequence("5"));
	button6->setShortcut(QKeySequence("6"));
	button7->setShortcut(QKeySequence("7"));
	button8->setShortcut(QKeySequence("8"));
	button9->setShortcut(QKeySequence("9"));
	//newStartButton->setShortcut(QKeySequence(...)); Qt::Key enum: http://qt-project.org/doc/qt-4.8/qt.html#Key-enum
	resetButton->setShortcut(QKeySequence(Qt::Key_Backspace));
}

CodeKnacker::~CodeKnacker()
{

}

void CodeKnacker::on_buttonGroupNumbers_buttonClicked(QAbstractButton *button)
{
	//qDebug() << "Button" << button << "clicked";
	lineEditPassword->setText(lineEditPassword->text() + button->text());
}

void CodeKnacker::on_lineEditPassword_textChanged(const QString &text)
{
	//qDebug() << "Text changed:" << text;
	if(text.length() == _digits)
	{
		checkInput(text);
	}
}

void CodeKnacker::on_codeLength_valueChanged(int codeLength)
{
	_digits = codeLength;
	lineEditPassword->setMaxLength(codeLength);
	newStartButton->click();
}

void CodeKnacker::on_newStartButton_clicked()
{
	_password = generatePassword(_digits);
	resetButton->click();
	// reset lamp
}

void CodeKnacker::on_resetButton_clicked()
{
	labelDebug->setText("Password: " + _password);
	lineEditPassword->setText("");
}

QString CodeKnacker::generatePassword(int digits)
{
	int rand = static_cast< int >(_zufallsGenerator->generateRandomNumber() * pow(10.0,digits));
	QString pw = QString::number(rand);
	while(pw.length() != digits)
	{
		pw = "0" + pw;
	}
	return pw;
}

void CodeKnacker::checkInput(QString input)
{
	if(input == _password)
	{
		labelDebug->setText("Code richtig!");
		// showLamp(0); // grüne Lampe
	}
	else
	{
		labelDebug->setText("Code falsch!");
		// check for correct numbers on false place // gelbe Lampe
		// otherwise // rote Lampe
	}
}

void CodeKnacker::showLamp(int status)
{
	qDebug() << "showLamp(" << status << ")";
	//TODO
}