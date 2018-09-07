#ifndef ROOM_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ROOM_H

#include "Entity.h"
#include "Item.h"
#include <string>
#include <vector>
#pragma once
class Room : public Entity
{
protected:
	string description;
	vector<Item> items;
	vector<Room> connectedRooms;
public:
	void setDescription(string description);
	string getDescription();
	void setConnectedRoom(Room r);
	void setConnectedRooms(vector<Room> v);
	vector<Room> getConnectedRooms();
	bool isRoomConnected(Room r);
	void setItem(Item i);
	void setItems(vector<Item> v);
};

#endif