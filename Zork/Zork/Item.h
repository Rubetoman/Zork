#include "Entity.h"
#include <string>
#include <vector>
#pragma once
class Item : public Entity
{
protected:
	string description;				// Description of the Item. Will be shown when examining the Item.
	vector<Item> compatibleItems;	// Items that can be combined with it.
public:
	void setDescription(string description);	// Set a description for the Item.
	string getDescription();					// Get the description of the Item.
	void setCompatibleItem(Item i);				// Set an Item compatible to combine it.
	void setCompatibleItems(vector<Item> v);	// Set some Items compatible to combine them with it.
	vector<Item> getCompatibleItems();			// Get a vector with all the compatible Items.
	bool isCompatible(Item i);					// Check if an Item is compatible to combine them.
};

