#pragma once

/* Qt */
#include <QObject>

class Mannschaft : public QObject
{
	Q_OBJECT

public:

	Mannschaft();
	Mannschaft(QString name, QString herkunft, bool hatSchiri);
	~Mannschaft();

	bool getSchiri();
	void setSchiri(bool b);

	Q_SIGNAL void hatSchiriChanged(bool b);

	QString _name;
	QString _herkunft;
	int _anzahlGeschiedsterSpiele;
	bool _hatSchiri;

private:

};
