#pragma once
#include <vector>
#include <iostream>
class Grid //change map name to grid or something, plan on using maps so less confusion
{
public:

	Grid(int width, int height, bool blank);
	void fillMapRandom();
	bool checkValid();
	bool checkValid(int row, int col, int dir); //best to use recursion i think
	void printMapValues();
	void printMapImage();
	void printMapImage(int row, int col);
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
	int _entrance_row;
	int _entrance_col;
	int _exit_row;
	int _exit_col;

	std::vector< std::vector<int> > _gridData;
};

