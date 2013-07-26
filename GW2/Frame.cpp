#include <QDebug>

#include "Frame.h"

Frame::Frame()
: offset(0,0)
{
	communicator = new GW2Communicator();
	bool ok = QObject::connect(communicator, SIGNAL(eventsReceived(QString)), this, SLOT(setEventLabel(QString)));
	if(!ok)
	{
		qDebug() << "Error...connection failed";
	}

	this->setStyleSheet("background:transparent;");
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
	setupUi(this);

	communicator->startLoop();
}

Frame::~Frame()
{

}

void Frame::setEventLabel(QString events)
{
	this->LabelEvents->setText(events);
}

// "offset" is a member variable of type QPoint
void Frame::mousePressEvent(QMouseEvent* event)
{
	event->accept(); // do not propagate
    if (isWindow())
        offset = event->globalPos() - pos();
    else
        offset = event->pos();
}

void Frame::mouseMoveEvent(QMouseEvent* event)
{
    event->accept(); // do not propagate
    if (isWindow())
        move(event->globalPos() - offset);
    else
        move(mapToParent(event->pos() - offset));
}

void Frame::mouseReleaseEvent(QMouseEvent* event)
{
    event->accept(); // do not propagate
    offset = QPoint();
}