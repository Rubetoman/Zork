#ifndef INVENTORY_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define INVENTORY_H

#include "Entity.h"
#include "Item.h"
#include <string>
#include <vector>

#pragma once

/*	Inventory object that inherits from Entity.
	Is used to store Items inside, mainly for the player inventory.
*/
class Inventory : public Entity
{
protected:
	vector<Item> items;				// Items stored on the Inventory.		
public:
	int getItemNumber(Item i);		// Get the number on the inventory of an Item.
	int getItemNumber(string name);	// Get the number on the inventory of an Item by its name.
	void addItem(Item i);			// Add an item to the Inventory.
	void addItems(vector<Item> v);	// Add some Items to the Inventory.
	void deleteItem(Item i);		// Deletes an Item from Inventory.
	void deleteItem(size_t number);	// Deletes an Item from the Inventory by passsing the number of the Item inside the Inventory.
	bool hasItem(Item i);			// Check whether an Item is located on the Inventory.
	bool hasItem(string i);			// Check whether an Item with the name given is located on the Inventory.
	vector<Item> getItems();		// Returns a vector with the Items located on the Inventory.
};

#endif