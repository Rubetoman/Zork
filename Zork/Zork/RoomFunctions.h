#ifndef ROOMFUNCTIONS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ROOMFUNCTIONS_H

#include <string>
#include <vector>
#include "main.h"

#pragma once

/*	Show names of the Rooms stored on rooms vector.
	They are shown followed by a number so the player inserts the number of the room desired.
*/
void showRooms();

/*	Prints out the name of the Items stored on the Room the player currently is.
	It is used to number and show the Items so the player can choose one of them.
*/
void showRoomItems();

/*	Looks for pickupable Items on the Room where the player is located.
	Lets the player to pick up one of the Items showed.
*/
void lookForItems();

/*	Change player position to another Room.
*/
Room move();

#endif