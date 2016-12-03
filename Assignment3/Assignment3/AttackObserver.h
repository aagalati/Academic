#pragma once
#include "Subject.h"
class AttackObserver :
	public Subject
{
public:
	AttackObserver();
	void attacked(int d);
};

