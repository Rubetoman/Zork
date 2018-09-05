#ifndef MAIN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MAIN_H

#include <string>
#include <vector>
#include "Item.h"
#include "Inventory.h"
#pragma once
using namespace std;

extern vector<Item> inventory;
	
void showLocations(string current);

int getInput(int min, int max);

void waitForInput();

string move(string current);

void game();

void initialization();

void mainMenu();

#endif
