#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include <vector>

using namespace std;

Map::Map(int width, int height, bool blank) //constructor
{
	_width = width;
	_height = height;
	sizeMap();
	if (!blank) fillMapRandom();

}


void Map::fillMapRandom()
{

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			_mapData[i][j] = rand() % 3;
		}
	}

}


bool Map::checkValid() {
	return false;
}

void Map::printMap() {


	for (int i = 0; i < _height - 2; i++) {
		if (i == (_height / 2) - 1 && _height%2 == 0)
			cout << "Current Map----";
		else if (i == (_height / 2) - 1 && _height % 2 == 1)
			cout << "--Current Map--";
		else
			cout << "-----";
	}

	cout << endl;

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			cout << "| " << _mapData[i][j] << " |";
		}
		cout << endl;
		for (int i = 0; i < _height; i++) {
			cout << "-----";
		}
		cout << endl;
	}


}

void Map::sizeMap() {

	_mapData.resize(_width); //sizing 2D vector to correct size
	for (int i = 0; i < _width; i++)
		_mapData[i].resize(_height);

}

/*Map::~Map()
{
}*/
