#include "stdafx.h"
#include "Character.h"
#include <iostream>


Character::Character()
{
	AttackObserver *ch = new AttackObserver();
	attackObs = ch;
	attackObs->Attach(this);

	dmg = 10;


}


void Character::attack() {
	attackObs->attacked(1);
}

void Character::dmgTaken(int  d) {
	attackObs->attacked(2);
}

void Character::update(){ }

void Character::update(int d) {

	switch (d) {
	case 1: std::cout << "Your character is attacking for " << dmg << " damage!" << std::endl;
		break;
	case 2: std::cout << "You have been attacked!" << std::endl;
		break;
	}

}

Character::~Character()
{
}
