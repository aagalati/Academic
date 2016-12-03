#pragma once
#include "Observer.h"
#include "PhaseObserver.h"
#include <iostream>

class Turn :
	public Observer
{
public:
	Turn();
	void changeTurn(int t);
	void update() {};
	void update(int d);
	~Turn();

private:

	PhaseObserver *phaseObs;

};

