#pragma once
#include <vector>
#include <iostream>
class Map //change map name to grid or something, plan on using maps so less confusion
{
public:
	Map(int height, int width, bool blank);
	void fillMapRandom();
	bool checkValid(); //best to use recursion i think
	void printMap();
	void sizeMap();
	void setCell(int row, int col, int set);
	void setRow(int row, int set);
	void setCol(int col, int set);
	void addExtraRow(int set);
	void addExtraCol(int set);
	//~Map();
private:
	int _width;
	int _height;
	std::vector< std::vector<int> > _mapData;
};

