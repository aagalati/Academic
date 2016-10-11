// Assignment 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Grid.h"

using namespace std;

int main()
{

	Grid mygrid(10, 10, false);
	mygrid.printMapValues();
	
	cout << endl;
	
	mygrid.printMapImage();

	cout << mygrid.checkValid() << endl;

	int quit; //to exit
	cout << "Type 0 to quit ";
	cin >> quit;

    return 0;
}

