#include "stdafx.h"
#include "Item.h"
#include "main.h"
#include "Room.h"
#include "Inventory.h"
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
	cout << inventory.getItems()[number].getName() << " dropped." << endl;
	currentRoom.addItem(inventory.getItems()[number]);
	inventory.deleteItem(number);
	Sleep(600);
}

void pickUpItem(int number) {
	Item pickedItem = currentRoom.getItems()[number];
	showLoadingText("Picking up item");
	cout << pickedItem.getName() << " picked up." << endl;
	inventory.addItem(pickedItem);
	currentRoom.deleteItem(pickedItem);
	Sleep(600);
}

int getItemNumberInInventory(string name) {
	for (size_t j=0; inventory.getItems().size() > j; j++) {
		if (inventory.getItems()[j].getName() == name)
			return j;
	}
	return 0;
}
void showItemDescription(int number) {
	system("cls");		//Clean screen
	cout << inventory.getItems()[number].getName() << ":" << endl << endl;
	cout << "     " << inventory.getItems()[number].getDescription() << endl;
	waitForInput(true);
}

int showCombinableItems(Item i) {
	int k = 1;
	vector<Item> compatibleItems = i.getCompatibleItems();

	if (compatibleItems.size() < 1)
		return 0;
	for (size_t j = 0; compatibleItems.size() > j; j++) {
		if (inventory.hasItem(compatibleItems[j])) {
			cout << k << ": " << compatibleItems[j].getName() << endl;
			k++;
		}
	}
	if(k < 2)
		cout << "No combinable items." << endl;
	else
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
		if (inventory.hasItem(compatibleItems[j])) {
			if (k == number)
				return compatibleItems[j].getName();
			k++;
		}
	}
	return "";
}
void combineItems(int itemA, int itemB) {
	Item combinedItem;
	Item a = inventory.getItems()[itemA];
	Item b = inventory.getItems()[itemB];
	showLoadingText("Combining " + a.getName() + " with " + b.getName());
	combinedItem.setName(a.getName() + " + " + b.getName());
	combinedItem.setDescription(a.getName() + " combined with " + b.getName() + ".");
	inventory.addItem(combinedItem);
	inventory.deleteItem(inventory.getItemNumber(a));
	inventory.deleteItem(inventory.getItemNumber(b));
	cout << "Combined" << endl;
	waitForInput(false);
}

void chooseToCombine(int number) {
	int itemsCount = 0;
	int itemNumber;
	Item itemToComb = inventory.getItems()[number];
	cout << "Compatible items: " << endl << endl;
	itemsCount = showCombinableItems(itemToComb);
	if (itemsCount > 1) {	
		cout << "Which one do you want to combine?: " << endl << endl;
		itemNumber = getInput(1, itemsCount);
		if (itemNumber <= itemToComb.getCompatibleItems().size()) {
			string itemName = getCombinableItemName(itemToComb, itemNumber);
			combineItems(number, getItemNumberInInventory(itemName));
		}
		else {
			waitForInput(true);
		}
	}
	else {
		cout << "You can't combine this object with another you currently have. " << endl << endl;
		waitForInput(true);
	}
}

void manageItem(int itemNumber) {
	int selection;
	system("cls");		//Clean screen
	cout << "What do you want to do with the " << inventory.getItems()[itemNumber].getName() << "?:" << endl << endl;
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
	for (i; inventory.getItems().size() > i; i++) {
		cout << i + 1 << ": " << inventory.getItems()[i].getName() << endl;
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
	if (inventory.getItems().size() < 1) {
		cout << "Your inventory is empty." << endl << endl;
		waitForInput(true);
	}
	else {
		cout << "Inventory:" << endl;
		showPlayerItems();
		cout << endl << "Which item would you like to choose?:" << endl << endl;
		// Get Input
		selectedItem = getInput(1, inventory.getItems().size() + 1);
		if (selectedItem != inventory.getItems().size() + 1) {
			manageItem(selectedItem - 1);
			manageInventory();
			_getch();	// Avoid exiting function before calling manageInventory();
		}
	}
}