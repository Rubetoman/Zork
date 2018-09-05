#include "Entity.h"
#include <string>
#include <vector>
#pragma once
class Item : public Entity
{
protected:
	string description;
	vector<Item> compatibleItems;
public:
	void setDescription(string description);
	string getDescription();
	void setCompatibleItem(Item i);
	void setCompatibleItems(vector<Item> v);
	bool isCompatible(Item i);

};

