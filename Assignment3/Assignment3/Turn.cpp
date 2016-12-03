#include "stdafx.h"
#include "Turn.h"


Turn::Turn()
{
	PhaseObserver *di = new PhaseObserver();
	phaseObs = di;
	phaseObs->Attach(this);

}

void Turn::changeTurn(int t) {

	phaseObs->phaseChange(t);

}

void Turn::update(int d) {

	switch(d) {

	case 1: std::cout << "Your turn" << std::endl;
		break;
	case 2: std::cout << "Enemy turn" << std::endl;
		break;
	case 3: std::cout << "Game Loaded" << std::endl;
		break;
	case 4: std::cout << "Game is over!" << std::endl;
		break;
	}

}

Turn::~Turn()
{
}
