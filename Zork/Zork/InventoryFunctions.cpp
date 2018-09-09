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
	showLoadingText("Dropping item");					// Print "Dropping..."
	cout << inventory.getItems()[number].getName() << " dropped." << endl;
	currentRoom.addItem(inventory.getItems()[number]);	// Add Item to the Room Items vector.
	inventory.deleteItem(number);						// Delete Item from Inventory.
	Sleep(600);											// Give time to player to read.
}

/* The player choose an Item by the position inside the Inventory */
void pickUpItem(int number) {
	Item pickedItem = currentRoom.getItems()[number];	// Get the Item selected by the position.
	showLoadingText("Picking up item");					// Print "Picking up item..."
	cout << pickedItem.getName() << " picked up." << endl;
	inventory.addItem(pickedItem);						// Add Item to the Inventory.
	currentRoom.deleteItem(pickedItem);					// Delete Item from the Room Items vector.
	Sleep(600);											// Give time to player to read.
}

void showItemDescription(int number) {
	system("cls");		//Clean screen
	cout << inventory.getItems()[number].getName() << ":" << endl << endl;
	cout << "     " << inventory.getItems()[number].getDescription() << endl;
	waitForInput(true);	// Wait for the player key press.
}

/*	Get the list of compatible Items from the Item given and print them one by one with the position number +1 so it starts in 1
	At the end another option is provided to close list without combining any Items.
	If there are no compatible Items print a message.
	Returns an Integer with the number of options provided.
*/
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
	cout << k << ": Close list" << endl;
	return k;
}

/* Look for the Item on the position given and print the name */
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

/*	Look for both Items on the Inventory by position.
	Create a new Item, add it to the Inventory and delete the other two from Inventory.
	The name of the new Item will be the name of the of the first one followed by a " + " and the name of the second one.
	The description of the new Item will be the name of the first one followed by a " combined with " and the name of the second one.
*/
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
	waitForInput(false);								// Wait for the player key press.
}

/*	Get the first Item choosen by his position on the Inventory vector and show the ones compatible
	If there are no Items compatible on the Inventory a message is displayed.
*/
void chooseToCombine(int number) {
	int itemsCount = 0;
	size_t itemNumber;
	Item itemToComb = inventory.getItems()[number];
	cout << "Compatible items: " << endl << endl;
	itemsCount = showCombinableItems(itemToComb);
	if (itemsCount > 1) {	
		cout << "Which one do you want to combine?: " << endl << endl;
		itemNumber = getInput(1, itemsCount);
		if (itemNumber <= itemToComb.getCompatibleItems().size()) {
			string itemName = getCombinableItemName(itemToComb, itemNumber);
			combineItems(number, inventory.getItemNumber(itemName));
		}
		else {
			waitForInput(true);	// Wait for the player key press.
		}
	}
	else {
		cout << "You can't combine this object with another you currently have. " << endl << endl;
		waitForInput(true);	// Wait for the player key press.
	}
}

void manageItem(int itemNumber) {
	int selection;
	system("cls");				//Clean screen.
	cout << "What do you want to do with the " << inventory.getItems()[itemNumber].getName() << "?:" << endl << endl;
	cout << "1: Examine." << endl;
	cout << "2: Drop it." << endl;
	cout << "3: Combine it with another item." << endl;
	cout << "4: Go back." << endl << endl;
	selection = getInput(1, 4);	// Get Input.
	switch (selection)
	{
	case 1:	// Examine.
		showItemDescription(itemNumber);
		waitForInput(true);
		manageItem(itemNumber);
		break;
	case 2:	// Drop Item.
		system("cls");				//Clean screen.
		dropItem(itemNumber);
		waitForInput(true);			// Wait for the player key press.
		break;
	case 3:	// Combine Items.
		chooseToCombine(itemNumber);//Start to combine function, choose the other Item to combine.
		break;
	case 4:	// Go back.
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
	system("cls");							// Clean screen.
	showLoadingText("Opening inventory");	// Print "Opening inventory...".
	// Check if Inventory is empty.
	if (inventory.getItems().size() < 1) {
		cout << "Your inventory is empty." << endl << endl;
		waitForInput(true);	// Wait for the player key press.
	}
	else {
		cout << "Inventory:" << endl;
		showPlayerItems();	// Print Items names.
		cout << endl << "Which item would you like to choose?:" << endl << endl;
		// Get Input.
		selectedItem = getInput(1, inventory.getItems().size() + 1);
		if (selectedItem != inventory.getItems().size() + 1) {
			manageItem(selectedItem - 1);
			manageInventory();
			_getch();	// Avoid exiting function before calling manageInventory().
		}
	}
}