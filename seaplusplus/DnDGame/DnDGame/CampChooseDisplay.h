#pragma once
#include "Display.h"
#include "GameButton.h"
#include "BuilderDisplay.h"
#include "Grid.h"

class CampChooseDisplay :
	public Display

{
public:

	CampChooseDisplay();
	void choiceDisplay();
	void drawButtons();
	~CampChooseDisplay();
	void run();
	void update();
	void openAll();
	void openEdit();
	std::vector<Grid*> getGrid();
	void buttonAction(int x, int y, bool isclick);

	int getExitType();

private:

	int numofbuttons;

	std::vector < Grid* > gridlist;

	std::vector < GameButton* > buttons;

};


