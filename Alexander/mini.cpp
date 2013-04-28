#include "Mini.h"

Mini::Mini(QMainWindow *parent)
: QMainWindow(parent)
{
	setupUi(this);
	LabelValueTau->setText("0");
	_enabled = true;
	_leftPressed = false;
	_rightPressed = false;
	_l1 = new QIcon("L1.png");
	_l2 = new QIcon("L2.png");
	_r1 = new QIcon("R1.png");
	_r2 = new QIcon("R2.png");

	_win = new QIcon("win.png");
	_loose = new QIcon("loose.png");

	ButtonLeft->setIcon(*_l1);
	ButtonRight->setIcon(*_r1);
}

Mini::~Mini()
{

}

void Mini::on_SliderTau_valueChanged(int value)
{
	LabelValueTau->setText(QString::number(value));
	if(value == 100)
	{
		_enabled = false;
		ButtonLeft->setIcon(*_loose);
		ButtonRight->setIcon(*_win);
	}
	else if(value == -100)
	{
		_enabled = false;
		ButtonLeft->setIcon(*_win);
		ButtonRight->setIcon(*_loose);
	}
}

void Mini::keyPressEvent(QKeyEvent *keyEvent)
{
	switch(tolower(keyEvent->key()))
	{
		case 'a':
			if(_leftPressed)
			{
				on_ButtonLeft_released();
				_leftPressed = false;
			}
			else
			{
				on_ButtonLeft_pressed();
				_leftPressed = true;
			}
			break;
		case 'l':
			if(_rightPressed)
			{
				on_ButtonRight_released();
				_rightPressed = false;
			}
			else
			{
				on_ButtonRight_pressed();
				_rightPressed = true;
			}
			break;
	}
}

void Mini::on_ButtonLeft_pressed()
{
	if(_enabled)
	{
		ButtonLeft->setIcon(*_l2);
		SliderTau->setValue(SliderTau->value() - 10);
	}
}

void Mini::on_ButtonRight_pressed()
{
	if(_enabled)
	{
		ButtonRight->setIcon(*_r2);
		SliderTau->setValue(SliderTau->value() + 10);
	}
}

void Mini::on_ButtonLeft_released()
{
	if(_enabled)
	{
		ButtonLeft->setIcon(*_l1);
	}
}

void Mini::on_ButtonRight_released()
{
	if(_enabled)
	{
		ButtonRight->setIcon(*_r1);
	}
}


void Mini::on_ButtonReset_clicked()
{
	ButtonLeft->setIcon(*_l1);
	ButtonRight->setIcon(*_r1);
	SliderTau->setValue(0);
	_enabled = true;
}