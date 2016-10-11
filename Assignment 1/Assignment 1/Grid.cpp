#include "stdafx.h"
#include "Grid.h"
#include <iostream>
#include <vector>
#include <ctime>

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
	srand( time(NULL) );

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			_gridData[i][j] = rand() % 3;
		}
	}
	
	_gridData[rand() % _width][rand() % _height] = -1;
	_gridData[rand() % _width][rand() % _height] = -2;

}

bool Grid::checkValid() {

	cout << "Finding entrance..." << endl;

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			if (_gridData[i][j] == -1) {
				cout << "Start checking if map is valid..." << endl;
				return checkValid(i, j, 0);
			}
		}
	}

}

bool Grid::checkValid(int row, int col, int dir) {

	cout << "Checking at (" << row << "," << col << ") = " << _gridData[row][col] << endl;
	//int t;
	//cin >> t;

	if (_gridData[row][col] == -2) {
		cout << "Found the exit, returning true" << endl;
		return true;
	}
	else if (_gridData[row][col] == 1) {
		cout << "Wall in the way, returning false" << endl;
		return false;
	}
	else {
		cout << "Checking empty space at (" << row << "," << col << ")" << endl;

		if (col != 0 && dir != 2) {
			cout << "Going left" << endl;
			if (checkValid(row, col - 1, 1))
				return true;
		}

		if (col != _width - 1 && dir != 1) {
			cout << "Going right" << endl;
			if (checkValid(row, col + 1, 2))
				return true;
		}

		if (row != 0 && dir != 4) {
			cout << "Going up" << endl;
			if (checkValid(row - 1, col, 3))
				return true;
		}

		if (row != _height - 1 && dir != 3) {
			cout << "Going down" << endl;
			if (checkValid(row + 1, col, 4))
				return true;
		}
	}

	return false;
}

void Grid::printMapValues() {


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


void Grid::printMapImage() {

	for (int i = 0; i < _height + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers

		cout << "#";

		for (int j = 0; j < _height; j++) {
			switch (_gridData[i][j]) {

				case 0: cout << " ";
						break;
				case 1: cout << "#";
						break;
				case 2: cout << "O";
						break;
				default: cout << "D";
						 break;

			}

		}

		cout << "#" << endl;

	}

	for (int i = 0; i < _height + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

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
