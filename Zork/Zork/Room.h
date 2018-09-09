#ifndef ROOM_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ROOM_H

#include "Entity.h"
#include "Item.h"
#include <string>
#include <vector>
#pragma once
/*	Room object that inherits from Entity.
	Is used for each location of the map and store on them useful variables.
*/
class Room : public Entity
{
protected:
	string description;			// Description of the room.
	vector<Item> items;			// Items stored on the room.
	vector<Room> connectedRooms;// Rooms that can be accessed from the room.
public:
	void setDescription(string description);	// Set a description for the Room.
	string getDescription();					// Get description of the Room.
	void setConnectedRoom(Room r);				// Set a Room connected.
	void setConnectedRooms(vector<Room> v);		// Set some Rooms connected.
	vector<Room> getConnectedRooms();			// Get a vector with Rooms connected.
	bool isRoomConnected(Room r);				// See if a room is connected.
	void addItem(Item i);						// Add an Item to the Room storage.
	void addItems(vector<Item> v);				// Add some Items to the Room storage.
	void deleteItem(Item i);					// Remove an Item from Room storage.
	vector<Item> getItems();					// Get a vector with all the Items stored on the Room.
	int getItemNumber(string name);				// Get an integer with a position of the Item passed by name.
};

#endif