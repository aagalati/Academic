#pragma once
#include "Observer.h"
#include "DiceObserver.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::rand;

class Dice :
	public Observer
{
public:
	Dice();
	int roll();
	~Dice();
	void update();
	void update(int d) {};

private: 

	int current;
	DiceObserver *diceObs;

};

