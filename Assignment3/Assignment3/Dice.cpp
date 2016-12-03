#include "stdafx.h"
#include "Dice.h"

Dice::Dice()
{

	DiceObserver *di = new DiceObserver();
	diceObs = di;
	diceObs->Attach(this);

	current = 0;

}

int Dice::roll() {

	srand(time(NULL));
	current = std::rand() % 6 + 1;
	
	diceObs->diceRoll();
	return current;

}

void Dice::update() {

	std::cout << "you rolled a " << current << std::endl;

}

Dice::~Dice()
{
}
