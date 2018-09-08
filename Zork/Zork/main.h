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

extern Inventory inventory;
extern Room bedroom;
extern Room livingRoom;
extern Room kitchen;
extern Room toilet;
extern Room entrance;
extern Room currentRoom;
extern vector<Room> rooms;

int getInput(int min, int max);

void waitForInput(bool back);

void showLoadingText(string text);

void game();

void initialization();

void mainMenu();

#endif
