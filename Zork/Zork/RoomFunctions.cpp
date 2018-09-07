#include "stdafx.h"
#include "main.h"
#include "Room.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void showRooms() {
	for (size_t i = 0; rooms.size() > i; i++) {
		cout << i + 1 << ": " << rooms[i].getName() << endl;
	}
}

Room move() {
	system("cls");		//Clean screen
	int newLocationNum;
	Room newRoom = currentRoom;

	cout << "You are currently on the " << currentRoom.getName() << endl << "Where would you like to move to?:" << endl << endl;
	showRooms();
	cout << endl;

	// Get Input
	newLocationNum = getInput(1, 5);
	switch (newLocationNum)
	{
	case 1:
		newRoom = rooms[0];
		break;
	case 2:
		newRoom = rooms[1];
		break;
	case 3:
		newRoom = rooms[2];
		break;
	case 4:
		newRoom = rooms[3];
		break;
	case 5:
		newRoom = rooms[4];
		break;
	default:
		break;
	}
	showLoadingText("Walking to " + newRoom.getName());
	if (currentRoom.getName() != newRoom.getName())
		cout << "You moved to the " << newRoom.getName() << "." << endl << endl;
	else
		cout << "You stayed on the " << newRoom.getName() << "." << endl << endl;

	//waitForInput();
	return newRoom;
}