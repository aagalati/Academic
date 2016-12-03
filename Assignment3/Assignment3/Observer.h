#pragma once
class Observer  //abstract class
{
public:
	~Observer();
	virtual void update() = 0; 
	virtual void update(int d) = 0;

protected:
	Observer();

};