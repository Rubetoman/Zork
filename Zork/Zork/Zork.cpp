// Zork.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

using namespace std;
//enum locations { bedroom, kitchen, toilet, entrance};

void showLocations(string current) {
	int i = 1;
	/*for (int e = bedroom; e != entrance; e++){
		cout << i << ": " << e << endl;
	}*/
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
	cin >> newLocationNum;

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
	if (current != newLocation) 
		cout << "You moved to the " << newLocation << "." << endl << endl;
	else
		cout << "You stayed on the " << newLocation << "." << endl << endl;

	return newLocation;
}

void game() {
	int selection = 0;
	int actionsCount = 0;
	string currentLocation = "bedroom";

	system("cls");		//Clean screen

	// START & 1st SELECTION
	cout << "You wake up on your bed with the ringing of a telephone." << endl;
	while (currentLocation == "bedroom") {
		cout << "What would you like to do?" << endl << endl;
		cout << "1: Look for the phone" << endl;
		cout << "2: Move to another room" << endl;
		cout << "3: Stay on the bed" << endl;
		cout << "4: Open inventory" << endl << endl;
		cin >> selection;
		cout << endl;
		system("cls");		//Clean screen
		switch (selection)
		{
		case 1:
			cout << "Looking";
			Sleep(300);
			cout << ".";
			Sleep(300);
			cout << ".";
			Sleep(300);
			cout << "." << endl;
			Sleep(600);
			cout << "You start looking everywhere but you don't find it, the sound is comming from another room." << endl << endl;
			break;
		case 2:
			currentLocation = move(currentLocation);
			if (currentLocation != "toilet")
				cout << "The phone stills ringing." << endl;
			else
				cout << "The sound of the ringing is louder on this room." << endl;
			break;
		case 3:
			cout << "You decide to stay on the bed and ignore the call. Probably it is nothing important" << endl;
			cout << "\n                             THE END                           " << endl;
			cout << "\n----------------------Press any key to exit----------------------" << endl;
			return;
			break;
		default:
			break;
		}
		actionsCount++;
		if (actionsCount > 3) {
			cout << "The ringing ended so you return to bed. Probably it was nothing importan." << endl;
			cout << "\n                             THE END                           " << endl;
			cout << "\n----------------------Press any key to exit----------------------" << endl;
			return;
		}
	}
	

	// 2nd SELECTION
	while (currentLocation != "toilet") {
		cout << "What would you like to do?" << endl;
		cout << "1: Look for the phone" << endl;
		cout << "2: Move to another room" << endl;
		cout << "3: Open inventory" << endl << endl;
		cin >> selection;
		system("cls");		//Clean screen
		switch (selection)
		{
		case 1:
			cout << "Looking";
			Sleep(300);
			cout << ".";
			Sleep(300);
			cout << ".";
			Sleep(300);
			cout << "." << endl;
			Sleep(600);
			cout << "You start looking everywhere but you don't find it, the sound is comming from another room." << endl << endl;
			break;
		case 2:
			currentLocation = move(currentLocation);
			if (currentLocation != "toilet")
				cout << "The phone stills ringing." << endl;
			else
				cout << "The sound of the ringing is louder on this room." << endl;
			break;
		case 3:
			break;
		default:
			break;
		}
		actionsCount++;
		if (actionsCount > 6) {
			cout << "The ringing ended so you return to bed. Probably it was nothing important." << endl;
			cout << "\n                             THE END                           " << endl;
			cout << "\n----------------------Press any key to exit----------------------" << endl;
		}
	}

	//cout << "TOILET" << endl;

}

void mainMenu() {
	char name[50];
	int selection = 0;
	cout << "What is your name?" << endl;
	cin.getline(name, 50);
	cout << endl << "What do you want to do, " << name << "?" << endl;
	cout << "1: Play the game." << endl;
	cout << "2: Open README." << endl;
	cout << "3: Exit game." << endl << endl;
	cin >> selection;

	switch (selection)
	{
	case 1:
		cout << endl;
		game();
		break;
	case 2:
		cout << "Opening..." << endl;
		break;
	case 3:
		exit(0);
		break;
	default:
		break;
	}
	_getch();

}


int main()
{
	mainMenu();
	return 0;
}


