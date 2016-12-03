#pragma once
#include "Subject.h"
class MoveObserver :
	public Subject
{
public:
	MoveObserver();
	void moved(int d);
};

