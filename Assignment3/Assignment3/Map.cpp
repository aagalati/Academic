#include "stdafx.h"
#include "Map.h"
#include  <iostream>

Map::Map()
{

	MoveObserver *di = new MoveObserver();
	moveObs = di;
	moveObs->Attach(this);

}

void Map::move(int chartype) {

	moveObs->moved(chartype);

}

void Map::update(int d) {

	switch (d) {
	case 1: std::cout << "Your character moved" << std::endl;
		break;
	case 2: std::cout << "Enemy moved" << std::endl;
		break;
	}

}

Map::~Map()
{
}
