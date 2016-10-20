#include "stdafx.h"
#include "Grid.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

Grid::Grid(int width, int height, bool blank) //constructor
{
	_width = width;  //set values 
	_height = height;
	sizeMap();
	if (!blank) fillMapRandom(); //if the user wants the map to be blank then the map is not filled randomly

}

void Grid::fillMapRandom()  //this method fills the map randomly with walls, objects and open spaces
{
	srand( time(NULL) );  //using srand for random numbers everytime

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			_gridData[i][j] = rand() % 3;
		}
	}
	
	_entrance_col = rand() % _width;  //randomizing entrances and exits
	_entrance_row = rand() % _height;

	do {  //exit cannot = entrance
		_exit_col = rand() % _width;
		_exit_row = rand() % _height;
	} while (_entrance_col == _exit_col && _entrance_row == _exit_row);


	_gridData[_entrance_col][_entrance_row] = -1;
	_gridData[_exit_col][_exit_row] = -2;

}

bool Grid::checkValid() {

	return checkValid(_entrance_col, _entrance_row, 0);

}

bool Grid::checkValid(int row, int col, int dir) { //this code will sometimes overflow, i have yet to fix this

	cout << "Checking at (" << row << "," << col << ") = " << _gridData[row][col] << endl;
	
	
	int t; //testing purposes
	cin >> t;

	if (_gridData[row][col] == -2) { //base case, if exit is found, return true
		cout << "Found the exit, returning true" << endl;
		return true;
	}
	else if (_gridData[row][col] == 1) { //case that there is a wall we return false
		cout << "Wall in the way, returning false" << endl;
		return false;
	}
	else {
			cout << "Checking empty space at (" << row << "," << col << ")" << endl;  //this code is for testing purposes
			printMapImage(row, col);

			cout << "Direction = " << dir << endl;

			if (col != 0 && dir != 2) {  //Checking left
				cout << "Going left" << endl; //debugging purposes
				if (checkValid(row, col - 1, 1))
					return true;
			}

			if (col != _width - 1 && dir != 1) { //checking right
				cout << "Going right" << endl;  //debugging purposes
				if (checkValid(row, col + 1, 2))
					return true;
			}

			if (row != 0 && dir != 3) { //checking up
				cout << "Going up" << endl; //debugging purposes
				if (checkValid(row - 1, col, 4))
					return true;
			}

			if (row != _height - 1 && dir != 4) { //checking down
				cout << "Going down" << endl; //debugging purposes
				if (checkValid(row + 1, col, 3))
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


void Grid::printMapImage() {  //prints the map as an image, Wall = $ = 1, Open space = " " = 0, Object = O = 2, Door = D = -1 or -2

	for (int i = 0; i < _height + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers

		cout << "#";

		for (int j = 0; j < _height; j++) {
			switch (_gridData[i][j]) {

				case 0: cout << " "; //open space
						break;
				case 1: cout << "#"; //wall
						break;
				case 2: cout << "O"; //object
						break;
				default: cout << "D"; //door
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

void Grid::printMapImage(int row, int col) {  //this overloaded version of print map image is for debugging checkValid() it allows me to see where it is checking with the $ symbol

	for (int i = 0; i < _height + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers

		cout << "#";

		for (int j = 0; j < _height; j++) {
			if (i == row && j == col)
				cout << "$";
			else {
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

		}

		cout << "#" << endl;

	}

	for (int i = 0; i < _height + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

}

void Grid::setCell(int row, int col, int set) {  //set a cell as a desired col and  row

	if (col <= _width && row <= _height)
		_gridData[col][row] = set;
	else {
		cout << "Error: Cell doesn't exist in the map (out of bounds)" << endl;
		cout << "       Cell (" << col << "," << row << ") is not in the map" << endl;
	}

	//checkValid(); //after we make a switch we must check if this switch was valid

}

void Grid::sizeMap() {  //changing the size of the map

	_gridData.resize(_width); //sizing 2D vector to correct size
	for (int i = 0; i < _width; i++)
		_gridData[i].resize(_height);

	//checkValid(); //we must check if this change is valid

}

void Grid::resizeMap(int width, int height) {

	_width = width;
	_height = height;
	sizeMap();

}


/*Grid::~Grid()
{
}*/
