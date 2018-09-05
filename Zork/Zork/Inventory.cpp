#include "stdafx.h"
#include "Item.h"
#include "main.h"
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
	cout << "Droping item" << endl;
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << "." << endl;
	Sleep(300);
	cout << inventory[number].getName() << " dropped." << endl;
	Sleep(600);
	inventory.erase(inventory.begin() + number);
}

void showItemDescription(int number) {
	system("cls");		//Clean screen
	cout << inventory[number].getName() << ":" << endl << endl;
	cout << "     " << inventory[number].getDescription() << endl;
	waitForInput();
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
		waitForInput();
		manageItem(itemNumber);
		break;
	case 2:
		system("cls");		//Clean screen
		dropItem(itemNumber);
		waitForInput();
		break;
	case 3:
		//Start to combine function
		break;
	case 4:
		return;
		break;
	default:
		break;
	}
}


void showPlayerItems() {
	int i = 0;
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
		waitForInput();
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