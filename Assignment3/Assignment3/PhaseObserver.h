#pragma once
#include "Subject.h"
class PhaseObserver :
	public Subject
{
public:
	PhaseObserver();
	void phaseChange(int t);
};

