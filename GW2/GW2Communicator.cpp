#include <QTimer>
#include <QDebug>

#include "GW2Communicator.h"

GW2Communicator::GW2Communicator()
:a(0)
{
}

GW2Communicator::~GW2Communicator()
{

}

void GW2Communicator::startLoop()
{
	 QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(receiveEvents()));
     timer->start(1000);
}

void GW2Communicator::receiveEvents()
{
	QString eventString = QString::number(a);
	emit this->eventsReceived(eventString);
	a++;
}