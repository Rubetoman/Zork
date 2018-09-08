#ifndef INVENTORY_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define INVENTORY_H

#include "Entity.h"
#include "Item.h"
#include <string>
#include <vector>

#pragma once

class Inventory : public Entity
{
protected:
	vector<Item> items;				
public:
	int getItemNumber(Item i);
	int getItemNumber(string name);
	void addItem(Item i);
	void addItems(vector<Item> v);
	void deleteItem(Item i);
	void deleteItem(size_t number);
	bool hasItem(Item i);
	bool hasItem(string i);
	vector<Item> getItems();
};

#endif