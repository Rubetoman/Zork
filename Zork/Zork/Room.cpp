#include "stdafx.h"
#include "Item.h"
#include "Room.h"
#include <iostream>


void Room::setDescription(string description) {
	this->description = description;
}

string Room::getDescription() {
	return this->description;
}

/*	Check that the Room isn't already on the vector and add it.
*/
void Room::setConnectedRoom(Room r) {
	bool already = false;
	for (size_t i = 0; this->connectedRooms.size() > i; i++) {
		if (this->connectedRooms[i].getName() == r.getName()) {
			already = true;
			cout << r.getName() << " is already on the connectedRooms vector." << endl;
		}
	}
	if (!already)
		this->connectedRooms.push_back(r);
}

/*	Loop through vector of Rooms, check that each Room isn't already on the vector and add them.
*/
void Room::setConnectedRooms(vector<Room> v) {
	bool already = false;
	for (size_t j = 0; v.size() > j; j++) {
		for (size_t i = 0; this->connectedRooms.size() > i; i++) {
			if (this->connectedRooms[i].getName() == v[j].getName()) {
				already = true;
				cout << v[j].getName() << " is already on the connectedRooms vector." << endl;
			}
		}
		if (!already)
			this->connectedRooms.push_back(v[j]);
	}
}

vector<Room> Room::getConnectedRooms() {
	if (this->connectedRooms.empty())
		cout << "There are no rooms connected." << endl;
	return this->connectedRooms;
}

bool Room::isRoomConnected(Room r) {
	for (size_t i = 0; this->connectedRooms.size() > i; i++) {
		if (this->connectedRooms[i].getName() == r.getName())
			return true;
	}
	return false;
}

void Room::addItem(Item i) {
	this->items.push_back(i);
}

void Room::addItems(vector<Item> v) {
	for (size_t i = 0; i < v.size(); i++) {
		this->items.push_back(v[i]);
	}
}

void Room::deleteItem(Item i) {
	this->items.erase(this->items.begin() + this->getItemNumber(i.getName()));
}

vector<Item> Room::getItems() {
	if (this->items.empty())
		cout << "There are no pickable items on the room" << endl;
	return this->items;
}

int Room::getItemNumber(string name) {
	for (size_t j = 0; this->items.size() > j; j++) {
		if (this->items[j].getName() == name)
			return j;
	}
	return -1;
}


