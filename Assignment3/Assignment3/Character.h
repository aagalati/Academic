
#include "Observer.h"
#include "AttackObserver.h"
class Character :
	public Observer
{
public:
	Character();
	void attack();
	void dmgTaken(int d);
	void update(int d);
	~Character();
	void update();

private:

	AttackObserver *attackObs;
	int dmg;
};
