#include "stdafx.h"
#include "PhaseObserver.h"


PhaseObserver::PhaseObserver() : Subject() {}

void PhaseObserver::phaseChange(int t) {
	Notify(t);
}
