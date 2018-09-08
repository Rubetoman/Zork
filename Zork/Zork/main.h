#ifndef MAIN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MAIN_H

#include <string>
#include <vector>
#include "Item.h"
#include "Inventory.h"
#include "InventoryFunctions.h"
#include "Room.h"
#pragma once
using namespace std;

// Global variables
extern Inventory inventory;		// Inventory of the player: contains all picked up objects.
extern Room bedroom;			/* Rooms declarations*/
extern Room livingRoom;
extern Room kitchen;
extern Room toilet;
extern Room entrance;
extern Room currentRoom;		// Room where the player currently is.
extern vector<Room> rooms;		// Vector with all the rooms on the current map.

/*  Gets player Input introduced on the console in form of integer.
	The range for the integer must be declared by passing minimum and maximum values.
	The options provided to player are always numbered and the player will Input the number of the option choosen.
*/
int getInput(int min, int max);

/*	Waits for the player to press any key on the keyboard.
	Shows a message that depends on the boolean: true-> back, false-> continue.
	This gives time for the player to read what is printed by the application.
*/
void waitForInput(bool back);

/*	Animation for the text displayed.
	Prints the string passed as an agument followed by three dots with some time between.
	Gives the player the impression that something is being computed and gives time between actions.
*/
void showLoadingText(string text);

/*	Controlls the main structure of the game.
	Shows options of each room and class other functions to manage the gameplay.
*/
void game();

/*	Initializes all the variables and objects for the game.
*/
void initialization();

/*	Shows text of the file whose name is passed as an argument.
	If the .txt file it's on a different folder give the path also. 
	Used to show title and README.
*/
void openFile(string fileName);

/* Main menu to choose between play the game, open README or exit.
*/
void mainMenu();

#endif
