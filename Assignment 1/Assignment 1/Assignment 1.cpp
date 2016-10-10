// Assignment 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Map.h"

using namespace std;

int main()
{

	Map mymap(5, 5, false);
	mymap.printMap();

	int quit; //to exit
	cout << "Type 0 to quit";
	cin >> quit;

    return 0;
}

