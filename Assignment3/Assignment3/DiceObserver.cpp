#include "stdafx.h"
#include "DiceObserver.h"


DiceObserver::DiceObserver() : Subject() {}


void DiceObserver::diceRoll() {
	Notify();
}