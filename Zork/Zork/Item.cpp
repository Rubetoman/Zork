#include "stdafx.h"
#include "Item.h"


void Item::setDescription(string description) {
	this->description = description;
}

string Item::getDescription() {
	if (!this->description.empty())
		return this->description;
	return "";
}

void Item::setCompatibleItem(Item i) {
	this->compatibleItems.push_back(i);
}

void Item::setCompatibleItems(vector<Item> v) {
	for (size_t i = 0; i < v.size(); i++) {
		this->compatibleItems.push_back(v[i]);
	}
}

vector<Item> Item::getCompatibleItems() {
	return this->compatibleItems;
}

bool Item::isCompatible(Item i) {
	for (size_t j = 0; j < this->compatibleItems.size(); j++) {
		if (this->compatibleItems[j].name == i.name) {
			return true;
		}
	}
	return false;
}
