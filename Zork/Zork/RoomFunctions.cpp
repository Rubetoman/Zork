#include "stdafx.h"
#include "main.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void showLocations(string current) {
	int i = 1;
	cout << "1: Bedroom" << endl;
	cout << "2: Kitchen" << endl;
	cout << "3: Toilet" << endl;
	cout << "4: Entrance" << endl;
}

string move(string current) {

	int newLocationNum;
	string newLocation = current;
	//locations location;

	cout << "You are currently on the " << current << endl << "Where would you like to move to?:" << endl << endl;
	showLocations(current);
	cout << endl;

	// Get Input
	newLocationNum = getInput(1, 4);
	switch (newLocationNum)
	{
	case 1:
		newLocation = "bedroom";
		break;
	case 2:
		newLocation = "kitchen";
		break;
	case 3:
		newLocation = "toilet";
		break;
	case 4:
		newLocation = "entrance";
		break;
	default:
		break;
	}
	showLoadingText("Walking to " + newLocation);
	if (current != newLocation)
		cout << "You moved to the " << newLocation << "." << endl << endl;
	else
		cout << "You stayed on the " << newLocation << "." << endl << endl;

	//waitForInput();
	return newLocation;
}