#include "CodeKnacker.h"

CodeKnacker::CodeKnacker(QMainWindow *parent)
: QMainWindow(parent)
{
	setupUi(this);

	int digits = 3;
	generatePassword(digits);
	
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
//	newStartButton->setShortcut(QKeySequence(/8 )); //war ein Test, keine Ahnung, ob das funzt

}

CodeKnacker::~CodeKnacker()
{

}

void CodeKnacker::generatePassword(int digits)
{
	//generate Password to find
}

void CodeKnacker::on_lineEditPassword_textChanged(const QString &text)
{
	//mach was, wenn was eingegeben wird.
}

void CodeKnacker::showLamp(int status)
{
	//zeige ne Lampe abh�ngig vom Status
}
