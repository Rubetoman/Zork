#include "stdafx.h"
#include "Item.h"
#include "Room.h"
#include <iostream>


void Room::setDescription(string description) {
	this->description = description;
}

string Room::getDescription() {
	if (!this->description.empty())
		return this->description;
}

void Room::setConnectedRoom(Room r) {
	bool already = false;
	for (int i = 0; this->connectedRooms.size() > i; i++) {
		if (this->connectedRooms[i].getName() == r.getName()) {
			already = true;
			cout << r.getName() << " is already on the connectedRooms vector." << endl;
		}
	}
	if (!already)
		this->connectedRooms.push_back(r);
}

void Room::setConnectedRooms(vector<Room> v) {
	bool already = false;
	for (int j = 0; v.size() > j; j++) {
		for (int i = 0; this->connectedRooms.size() > i; i++) {
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
	if (!this->connectedRooms.empty())
		return this->connectedRooms;
}
bool Room::isRoomConnected(Room r) {
	for (int i = 0; this->connectedRooms.size() > i; i++) {
		if (this->connectedRooms[i].getName() == r.getName())
			return true;
	}
	return false;
}

void Room::setItem(Item i) {
	this->items.push_back(i);
}

void Room::setItems(vector<Item> v) {
	for (int i = 0; i < v.size(); i++) {
		this->items.push_back(v[i]);
	}
}


