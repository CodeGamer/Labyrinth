#pragma once

class Zufallsgenerator
{
	public:
		Zufallsgenerator();
		~Zufallsgenerator();
		
		double generateRandomNumber();

	private:
		int _currentSeed;
		const int _m;
		const int _a;
		const int _q;
		const int _r;
		int _hi;
		int _lo;
		int _test;
};