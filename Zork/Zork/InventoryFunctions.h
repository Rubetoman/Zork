#ifndef INVENTORYFUNCTIONS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define INVENTORYFUNCTIONS_H

#include "Item.h"
#pragma once

using namespace std;

void dropItem(int number);

void pickUpItem(int number);

void showItemDescription(int number);

void manageItem(int itemNumber);

void showPlayerItems();

void manageInventory();

#endif

