#include "stdafx.h"
#include "Grid.h"
#include <iostream>
#include <vector>

using namespace std;

Grid::Grid(int width, int height, bool blank) //constructor
{
	_width = width;
	_height = height;
	sizeMap();
	if (!blank) fillMapRandom();

}

void Grid::fillMapRandom()
{

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			_gridData[i][j] = rand() % 3;
		}
	}

}


bool Grid::checkValid() {
	return false;
}

void Grid::printMap() {


	for (int i = 0; i < _height - 2; i++) { //loop to create a header for the grid
		if (i == (_height / 2) - 1 && _height%2 == 0) //different formatting for odd and even
			cout << "Current Map----";
		else if (i == (_height / 2) - 1 && _height % 2 == 1)
			cout << "--Current Map--";
		else
			cout << "-----";
	}

	cout << endl;

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			cout << "| " << _gridData[i][j] << " |";
		}
		cout << endl;
		for (int i = 0; i < _height; i++) {
			cout << "-----";
		}
		cout << endl;
	}


}

void Grid::setCell(int row, int col, int set) {

	if (row <= _width && col <= _height)
		_gridData[row][col] = set;
	else {
		cout << "Error: Cell doesn't exist in the map (out of bounds)" << endl;
		cout << "       Cell (" << row << "," << col << ") is not in the map" << endl;
	}
}

void Grid::sizeMap() {

	_gridData.resize(_width); //sizing 2D vector to correct size
	for (int i = 0; i < _width; i++)
		_gridData[i].resize(_height);

}

void Grid::resizeMap(int width, int height) {

	_width = width;
	_height = height;
	sizeMap();

}


/*Grid::~Grid()
{
}*/
