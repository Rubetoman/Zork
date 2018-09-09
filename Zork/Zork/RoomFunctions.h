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

/*	Change player position to another Room.
*/
Room move();

#endif