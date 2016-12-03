#include "stdafx.h"
#include "MoveObserver.h"


MoveObserver::MoveObserver() : Subject() {}


void MoveObserver::moved(int d) {
	Notify(d);
}
