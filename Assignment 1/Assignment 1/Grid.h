#pragma once
#include <vector>
#include <iostream>
class Grid //change map name to grid or something, plan on using maps so less confusion
{
public:
	Grid(int width, int height, bool blank);
	void fillMapRandom();
	bool checkValid(); //best to use recursion i think
	void printMap();
	void sizeMap();
	void resizeMap(int width, int height);
	void setCell(int row, int col, int set);
	void setRow(int row, int set);
	void setCol(int col, int set);
	void addExtraRow(int set);
	void addExtraCol(int set);
	void getWidth();
	void getHeight();
	//~Grid();
private:
	int _width;
	int _height;
	std::vector< std::vector<int> > _gridData;
};

