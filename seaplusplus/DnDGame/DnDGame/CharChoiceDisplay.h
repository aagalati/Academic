#pragma once
#include "Display.h"
#include "GameButton.h"
#include "EditCharDisplay.h"
#include "Character.h"

class CharChoiceDisplay :
	public Display
{
public:

	CharChoiceDisplay();
	Character * getChar();
	void choiceDisplay();
	void drawButtons();
	~CharChoiceDisplay();
	void run();
	void update();
	void openAll();
	void openEdit();
	void buttonAction(int x, int y, bool isclick);

	int getExitType();

private:

	int numofbuttons;
	Character* ch;
	std::vector < GameButton* > buttons;

};



