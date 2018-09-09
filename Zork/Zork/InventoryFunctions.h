#ifndef INVENTORYFUNCTIONS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define INVENTORYFUNCTIONS_H

#include "Item.h"
#pragma once

using namespace std;

/*	Drop an Item of the player's Inventory on the room the player currently is located.
	The Item is deleted from player's Inventory and stored at the end of the Room Items vector.
*/
void dropItem(int number);

/*	Pick up an Item from the Room the player is located and add it to the player's Inventory.
	The Item is removed from the Items vector of the Room and added at the end of the player Inventory.
*/
void pickUpItem(int number);

/*	Shows the description variable of an Item.
	It's called when the player chooses to examine the Item.
	It calls to WaitForInput to give time to the player to read the description.
*/
void showItemDescription(int number);

/*	Prints the names of the Items that can be combined with the Item given and are stored on the player's Inventory.
	It's needed so the player can choose the Item to combine with the one selected before.
*/
int showCombinableItems(Item i);

/*	Get the name of a combinable Item with the one given. 
	The combinable Item will be the one on the position given as an Integer.
	It's used because the player chooses the Item by position and not by name.
*/
string getCombinableItemName(Item i, int number);

/*	Combine two Items chosen by the position inside the Inventory into a new Item alone.
*/
void combineItems(int itemA, int itemB);

/*	Manages the selection of the Item to combine with the one already provided.
*/
void chooseToCombine(int number);

/*	Manages the Item selected by the player.
	Lets the player examine, drop and combine the Item selected from the Inventory.
*/
void manageItem(int itemNumber);

/*	Prints out the name of the Items stored on player's Inventory.
	It is used to number and show the Items so the player can choose one of them.
*/
void showPlayerItems();

/*	Function used to manage the Items inside player's Inventory.
	Lets the player choose between all the Items inside the Inventory.
*/
void manageInventory();

#endif

