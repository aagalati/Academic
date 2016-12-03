#include "stdafx.h"
#include "AttackObserver.h"
#include <iostream>


AttackObserver::AttackObserver() : Subject() {}


void AttackObserver::attacked(int d) {
	Notify(d);
}
