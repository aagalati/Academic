/*Assignment 3 -  Adam Galati 26944094

This program uses various observers to track game actions.
The logger currently outputs into the command prompt because the action will happen in the GUI in the main game later on.
The program implements a crude version of dice, map, character and turn/game phase, meaning it uses some very basic functions that
are not that developped, however they still implement the observer pattern for their required function. 
This program was meant to be made to be very easy to implement as a part of the larger DnD project.

*/

#include "stdafx.h"
#include "Dice.h"
#include "Character.h"
#include "Map.h"
#include "Turn.h"
#include <iostream>

void main()
{

	Dice *dice = new Dice();

	Character *dood = new Character();

	Map *place = new Map();

	Turn *turn = new Turn();

	//very basic way of turn based gameplay, this is hard coded but in the game this will be done automatically
	//this way of implementation is to  mimic the expected gameplay

	turn->changeTurn(3);
	turn->changeTurn(1);
	dice->roll();
	place->move(1);
	dood->attack();
	turn->changeTurn(2);
	place->move(2);
	turn->changeTurn(1);
	dice->roll();
	place->move(1);
	dood->attack();
	turn->changeTurn(2);
	place->move(2);
	dood->dmgTaken(10);
	turn->changeTurn(1);
	dice->roll();
	place->move(1);
	dood->attack();
	turn->changeTurn(2);
	place->move(2);
	dood->dmgTaken(10);
	turn->changeTurn(1);
	dice->roll();
	place->move(1);
	turn->changeTurn(4);



	int t;
	std::cin >> t;


}

