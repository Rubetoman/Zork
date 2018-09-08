#include "stdafx.h"
#include "Inventory.h"
#include <iostream>


int Inventory::getItemNumber(Item i) {
	for (size_t j = 0; this->items.size() > j; j++) {
		if (i.getName() == this->items[j].getName())
			return j;
	}
	cout << "Item: " << i.getName() << "isn't contained on inventory" << endl;
	return -1;
}

int Inventory::getItemNumber(string name) {
	for (size_t j = 0; this->items.size() > j; j++) {
		if (name == this->items[j].getName())
			return j;
	}
	cout << "Item: " << name << "isn't contained on inventory" << endl;
	return -1;
}

void Inventory::addItem(Item i) {
	this->items.push_back(i);
}

void Inventory::addItems(vector<Item> v) {
	for (size_t i = 0; v.size(); i++) {
		this->items.push_back(v[i]);
	}
}

void Inventory::deleteItem(size_t number) {
	if (number > this->items.size() || number < 0)
		cout << "Number of the item out of range. Must be a number between 0 and " << this->items.size() << "." << endl;
	else
		this->items.erase(this->items.begin() + number);
}

bool Inventory::hasItem(Item i) {
	for (size_t j = 0; this->items.size() > j; j++) {
		if (i.getName() == this->items[j].getName())
			return true;
	}
	return false;
}

void Inventory::deleteItem(Item i) {
	int itemNum = this->getItemNumber(i);
	if (itemNum > 0)
		this->items.erase(this->items.begin() + itemNum);

}

bool Inventory::hasItem(string i) {
	for (size_t j = 0; this->items.size() > j; j++) {
		if (this->items[j].getName() == i)
			return true;
	}
	return false;
}

vector<Item> Inventory::getItems() {
	return this->items;
}
