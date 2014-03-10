/* local */
#include "Mannschaft.h"

Mannschaft::Mannschaft(QString name, QString herkunft, bool hatSchiri)
: _name(name)
, _herkunft(herkunft)
{
	setSchiri(hatSchiri);
	_anzahlGeschiedsterSpiele = 0;
}

Mannschaft::~Mannschaft()
{

}

bool Mannschaft::getSchiri()
{
	return _hatSchiri;
}

void Mannschaft::setSchiri(bool b)
{
	_hatSchiri = b;
	Q_EMIT hatSchiriChanged(b);
}