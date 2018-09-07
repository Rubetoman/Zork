#ifndef INVENTORY_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define INVENTORY_H
#pragma once

using namespace std;

void dropItem(int number);

void showItemDescription(int number);

void manageItem(int itemNumber);

void showPlayerItems();

void manageInventory();

bool isItem(Item i);

#endif

