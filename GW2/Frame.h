#pragma once

#include <QMouseEvent>

#include "GW2Communicator.h"

#include "ui_Frame.h"

class Frame : public QWidget, public Ui::UI_Frame
{
	Q_OBJECT
	
	public:
		Frame();
		~Frame();

		void mousePressEvent(QMouseEvent* event);
		void mouseMoveEvent(QMouseEvent* event);
		void mouseReleaseEvent(QMouseEvent* event);

		Q_SLOT void setEventLabel(QString events);

		GW2Communicator *communicator;
		QPoint offset;
};