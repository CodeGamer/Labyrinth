#pragma once

#include <QObject>

class GW2Communicator : public QObject 
{
	Q_OBJECT
	
	public:
		GW2Communicator();
		~GW2Communicator();

		void startLoop();
		Q_SIGNAL void eventsReceived(QString events);
		Q_SLOT void receiveEvents();

		int a;
};