#pragma once

#include <QMainWindow>
#include <QKeyEvent>

#include "ui_Mini.h"

class Mini : public QMainWindow, public Ui::UI_Mini
{
	Q_OBJECT
	
	public:
		Mini(QMainWindow *parent = 0);
		~Mini();

		void keyPressEvent(QKeyEvent *keyEvent);

		Q_SLOT void on_SliderTau_valueChanged(int value);
		Q_SLOT void on_ButtonLeft_pressed();
		Q_SLOT void on_ButtonRight_pressed();
		Q_SLOT void on_ButtonLeft_released();
		Q_SLOT void on_ButtonRight_released();
		Q_SLOT void on_ButtonReset_clicked();

	private:
		bool _enabled;
		bool _leftPressed;
		bool _rightPressed;
		QIcon *_l1;
		QIcon *_l2;
		QIcon *_r1;
		QIcon *_r2;
		QIcon *_win;
		QIcon *_loose;
};