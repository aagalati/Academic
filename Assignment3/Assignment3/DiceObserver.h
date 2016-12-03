#pragma once
#include "Subject.h"
#include <iostream>

class DiceObserver :
	public Subject
{
public:
	DiceObserver();
	void diceRoll();
};

