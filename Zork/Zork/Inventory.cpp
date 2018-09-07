#include "stdafx.h"
#include "Item.h"
#include "main.h"
#include "Room.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <Windows.h>
#include <limits>
#undef max

using namespace std;

void dropItem(int number) {
	showLoadingText("Droping item");
	cout << inventory[number].getName() << " dropped." << endl;
	currentRoom.setItem(inventory[number]);
	inventory.erase(inventory.begin() + number);
	Sleep(600);
}

void pickUpItem(int number) {
	Item pickedItem = currentRoom.getItems()[number];
	showLoadingText("Picking up item");
	cout << pickedItem.getName() << " dropped." << endl;
	inventory.push_back(pickedItem);
	currentRoom.getItems().erase(currentRoom.getItems().begin() + number);
	Sleep(600);
}

bool inInventory(Item i) {
	for (size_t j=0; inventory.size() > j; j++) {
		if (inventory[j].getName() == i.getName())
			return true;
	}
	return false;
}

int getItemNumberInInventory(string name) {
	for (size_t j=0; inventory.size() > j; j++) {
		if (inventory[j].getName() == name)
			return j;
	}
	return 0;
}
void showItemDescription(int number) {
	system("cls");		//Clean screen
	cout << inventory[number].getName() << ":" << endl << endl;
	cout << "     " << inventory[number].getDescription() << endl;
	waitForInput(true);
}

int showCombinableItems(Item i) {
	int k = 1;
	vector<Item> compatibleItems = i.getCompatibleItems();

	if (compatibleItems.size() < 1)
		return 0;
	for (size_t j = 0; compatibleItems.size() > j; j++) {
		if (inInventory(inventory[j])) {
			cout << k << ": " << compatibleItems[j].getName() << endl;
			k++;
		}
	}
	cout << k << ": Close list" << endl;
	return k;
}

string getCombinableItemName(Item i, int number) {
	int k = 1;
	vector<Item> compatibleItems = i.getCompatibleItems();
	if (compatibleItems.size() < 1) {
		cout << "None" << endl;
	}
	for (size_t j = 0; compatibleItems.size() > j; j++) {
		if (inInventory(inventory[j])) {
			if(k == number)
				return compatibleItems[j].getName();
			k++;
		}
	}
	return "";
}
void combineItems(int itemA, int itemB) {
	showLoadingText("Combining " + inventory[itemA].getName() + " with " + inventory[itemB].getName());
	Item combinedItem;
	combinedItem.setName(inventory[itemA].getName() + " + " + inventory[itemB].getName());
	combinedItem.setDescription(inventory[itemA].getName() + " combined with " + inventory[itemB].getName() + ".");
	inventory.push_back(combinedItem);
	inventory.erase(inventory.begin() + itemA);
	inventory.erase(inventory.begin() + itemB-1);
	cout << "Combined" << endl;
	waitForInput(false);
}
void chooseToCombine(int number) {
	int itemsCount = 0;
	int itemNumber;
	cout << "Compatible items: " << endl << endl;
	itemsCount = showCombinableItems(inventory[number]);
	if (itemsCount > 0) {	
		cout << "Which one do you want to combine?: " << endl << endl;
		itemNumber = getInput(1, itemsCount);
		string itemName = getCombinableItemName(inventory[number], itemNumber);
		combineItems(number, getItemNumberInInventory(itemName));
	}
	else {
		cout << "You can't combine this object with another you currently have. " << endl << endl;
		waitForInput(true);
	}
}

void manageItem(int itemNumber) {
	int selection;
	system("cls");		//Clean screen
	cout << "What do you want to do with the " << inventory[itemNumber].getName() << "?:" << endl << endl;
	cout << "1: Examine." << endl;
	cout << "2: Drop it." << endl;
	cout << "3: Combine it with another item." << endl;
	cout << "4: Go back." << endl << endl;
	// Get Input
	selection = getInput(1, 4);
	switch (selection)
	{
	case 1:
		showItemDescription(itemNumber);
		waitForInput(true);
		manageItem(itemNumber);
		break;
	case 2:
		system("cls");		//Clean screen
		dropItem(itemNumber);
		waitForInput(true);
		break;
	case 3:
		//Start to combine function
		chooseToCombine(itemNumber);
		break;
	case 4:
		return;
		break;
	default:
		break;
	}
}

void showPlayerItems() {
	size_t i = 0;
	for (i; inventory.size() > i; i++) {
		cout << i + 1 << ": " << inventory[i].getName() << endl;
	}
	cout << i + 1 << ": Close inventory" << endl;
}

void manageInventory() {
	int selectedItem = 0;
	system("cls");		//Clean screen
	cout << "Opening inventory";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << "." << endl << endl;
	Sleep(600);
	if (inventory.size() < 1) {
		cout << "Your inventory is empty." << endl << endl;
		waitForInput(true);
	}
	else {
		cout << "Inventory:" << endl;
		showPlayerItems();
		cout << endl << "Which item would you like to choose?:" << endl << endl;
		// Get Input
		selectedItem = getInput(1, inventory.size() + 1);
		if (selectedItem != inventory.size() + 1) {
			manageItem(selectedItem - 1);
			manageInventory();
			_getch();	// Avoid exiting function before calling manageInventory();
		}
	}
}

bool isItem(Item i) {
	for (size_t j = 0; inventory.size() > j; j++) {
		if (i.getName() == inventory[j].getName())
			return true;
	}
	return false;
}