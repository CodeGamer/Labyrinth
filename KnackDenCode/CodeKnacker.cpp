#include "CodeKnacker.h"

CodeKnacker::CodeKnacker(QMainWindow *parent)
: QMainWindow(parent)
{
	setupUi(this);

	int digits = 3;
	generatePassword(digits);

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
	//zeige ne Lampe abhängig vom Status
}

void CodeKnacker::on_buttonGroupNumbers_buttonClicked(QAbstractButton * button)
{
	labelDebug->text = "Button " + button + "clicked."
}