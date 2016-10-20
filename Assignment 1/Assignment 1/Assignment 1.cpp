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
	mygrid.printMapValues();
	
	cout << endl;
	
	mygrid.printMapImage();

	cout << endl;

	cout << mygrid.checkValid() << endl;

	//mygrid.resizeMap(4, 4);
	//mygrid.setCell(1, 1, 7);

	//cout << endl;

	//mygrid.printMapValues();

	//cout << endl;

	//mygrid.printMapImage();

	//cout << mygrid.checkValid() << endl;

	//cout << mygrid.checkValid() << endl;

	int quit; //to exit
	cout << "Type 0 to quit ";
	cin >> quit;

    return 0;
}

