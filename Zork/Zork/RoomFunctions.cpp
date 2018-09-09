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

/*	Show player's current Room, display rest of the rooms and move to the one choosen.
	If the player chooses the Room where he already is then print a message and don't change current Room.
*/
Room move() {
	system("cls");		//Clean screen
	int newLocationNum;
	Room newRoom = currentRoom;

	cout << "You are currently on the " << currentRoom.getName() << endl << "Where would you like to move to?:" << endl << endl;
	showRooms();
	cout << endl;

	newLocationNum = getInput(1, 5);	// Get Input.
	// Store the new Room choosen. A number is increased because they are shown starting at 1 and inside the vector they start in 0.
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

	return newRoom;
}