// Assignment 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Grid.h"

using namespace std;

int main()
{

	Grid mygrid(5, 5, false);
	mygrid.printMap();
	
	cout << endl;
	
	mygrid.setCell(2, 3, 7);
	mygrid.printMap();
	
	cout << endl;
	
	mygrid.resizeMap(4, 4);
	mygrid.printMap();
	
	cout << endl;
	
	mygrid.setCell(5, 6, 3);


	int quit; //to exit
	cout << "Type 0 to quit ";
	cin >> quit;

    return 0;
}

