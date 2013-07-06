#include <QTime>
#include <QDebug>

#include "Zufallsgenerator.h"

Zufallsgenerator::Zufallsgenerator()
:_m(2147483399)
,_a(40692)
,_q(52774)
,_r(3791)
{
	const QTime *time = new QTime(0, 0, 0, 0);
	QTime *currentTime = new QTime(QTime::currentTime());
	_currentSeed = time->msecsTo(*currentTime);
}

Zufallsgenerator::~Zufallsgenerator()
{
	
}

double Zufallsgenerator::generateRandomNumber()
{
	_hi = _currentSeed / _q;
	_lo = _currentSeed % _q;
	_test = _a * _lo - _r * _hi;
	if(_test > 0)
	{
		_currentSeed = _test;
	}
	else
	{
		_currentSeed = _test + _m;
	}
	double ret = static_cast<double>(_currentSeed) / _m;
	return ret;
}