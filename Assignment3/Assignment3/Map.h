#pragma once
#include "Observer.h"
#include "MoveObserver.h"

class Map :
	public Observer
{
public:
	Map();
	void move(int chartype);
	void update() {};
	void update(int d);
	~Map();

private:

	MoveObserver *moveObs;

};

