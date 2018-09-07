// Zork.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Item.h"
#include "main.h"
#include "Inventory.h"
#include "Room.h"
#include "RoomFunctions.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <Windows.h>
#include <limits>
#undef max

using namespace std;
vector<Item> inventory;
Room bedroom;
Room livingRoom;
Room kitchen;
Room toilet;
Room entrance;
Room currentRoom;
vector<Room> rooms;
bool exitApp = false;
char name[50];

int getInput(int min, int max) {
	int input;
	cout << " >> ";
	while (!(cin >> input) || (input < min || input > max)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Insert a single number to choose one of the options provided:" << endl;
	}
	return input;
}

void waitForInput(bool back) {
	if(back)
		cout << "\n<----------------------Press any key to go back---------------------->" << endl;
	else
		cout << "\n<----------------------Press any key to go continue---------------------->" << endl;
	_getch();
}

void showLoadingText(string text)
{
	cout << text;
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << "." << endl;
	Sleep(600);
}
void game() {
	int selection = 0;
	int actionsCount = 0;
	currentRoom = bedroom;

	system("cls");		//Clean screen

	// START & 1st SELECTION
	cout << "You wake up on your bed with the ringing of a telephone." << endl;
	while (currentRoom.getName() == bedroom.getName()){
		cout << "What would you like to do?" << endl << endl;
		cout << "1: Look for the phone" << endl;
		cout << "2: Move to another room" << endl;
		cout << "3: Stay on the bed" << endl;
		cout << "4: Open inventory" << endl << endl;
		// Get Input
		selection = getInput(1, 4);
		cout << endl;
		system("cls");		//Clean screen
		switch (selection)
		{
		case 1:
			showLoadingText("Looking");
			cout << "You start looking everywhere but you don't find it, the sound is comming from another room." << endl << endl;
			waitForInput(false);
			break;
		case 2:
			currentRoom = move();
			if (currentRoom.getName() != toilet.getName())
				cout << "The phone stills ringing." << endl;
			else
				cout << "The sound of the ringing is louder on this room." << endl;
			waitForInput(false);
			break;
		case 3:
			system("cls");		//Clean screen
			cout << "You decide to stay on the bed and ignore the call. Probably it is nothing important" << endl;
			cout << "\n                             THE END                           " << endl;
			cout << "\n----------------------Press any key to exit----------------------" << endl;
			_getch();
			exitApp = true;
			return;
			break;
		case 4:
			manageInventory();
		default:
			actionsCount--;
			break;
		}
		actionsCount++;
		system("cls");		//Clean screen
	}
	

	// 2nd SELECTION
	while (currentRoom.getName() != toilet.getName()) {
		cout << "What would you like to do?" << endl;
		cout << "1: Look for the phone" << endl;
		cout << "2: Move to another room" << endl;
		cout << "3: Open inventory" << endl << endl;
		// Get Input
		selection = getInput(1, 3);
		system("cls");		//Clean screen
		switch (selection)
		{
		case 1:
			showLoadingText("Looking");
			cout << "You start looking everywhere but you don't find it, the sound is comming from another room." << endl << endl;
			break;
		case 2:
			currentRoom = move();
			if (currentRoom.getName() != toilet.getName())
				cout << "The phone stills ringing." << endl;
			else
				cout << "The sound of the ringing is louder on this room." << endl;
			break;
		case 3:
			manageInventory();
			break;
		default:
			break;
		}
		actionsCount++;
	}
	/*
	while (inventory) {
		cout << "What would you like to do?" << endl;
		cout << "1: Look for the phone" << endl;
		cout << "2: Move to another room" << endl;
		cout << "3: Open inventory" << endl << endl;
		// Get Input
		selection = getInput(1, 3);
		system("cls");		//Clean screen
		switch (selection)
		{
		case 1:
			showLoadingText("Looking");
			cout << "You start looking everywhere but you don't find it, the sound is comming from another room." << endl << endl;
			break;
		case 2:
			currentRoom = move();
			if (currentRoom.getName() != toilet.getName())
				cout << "The phone stills ringing." << endl;
			else
				cout << "The sound of the ringing is louder on this room." << endl;
			break;
		case 3:
			manageInventory();
			break;
		default:
			break;
		}
		actionsCount++;
	}*/
}

void openFile(string fileName) {
	std::ifstream f(fileName + ".txt");

	if (f.is_open())
		std::cout << f.rdbuf();
	else
		cout << fileName << ".txt couldn't be found." << endl;
	waitForInput(true);
}

void initialization() {
	// Initialize items
	Item laptop;
	Item battery;
	laptop.setName("Laptop");
	laptop.setDescription("Your laptop");
	battery.setName("Battery");
	battery.setDescription("Looks like a battery for a laptop");
	battery.setCompatibleItem(laptop);
	laptop.setCompatibleItem(battery);
	inventory.push_back(laptop);
	inventory.push_back(battery);

	// Initialize rooms
	bedroom.setName("Bedroom");
	livingRoom.setName("Living Room");
	kitchen.setName("Kitchen");
	toilet.setName("Toilet");
	entrance.setName("Entrance");
	bedroom.setDescription("Your bedroom, here you spend most of the time studying or playing videogames.");
	livingRoom.setDescription("The place where you spend time with your family or playing your console on the big TV.");
	kitchen.setDescription("No one can remember when was the last time you used the kitchen for something futher than eating. Really you shoul start learning how to cook.");
	toilet.setDescription("Just a common toilet.");
	entrance.setDescription("The first place you put foot on when enter your house, is full of regretable pictures of you as a child.");
	rooms.push_back(bedroom);
	rooms.push_back(livingRoom);
	rooms.push_back(kitchen);
	rooms.push_back(toilet);
	rooms.push_back(entrance);
	bedroom.setConnectedRooms(rooms);
}

void mainMenu() {
	initialization();
	int selection = 0;
	cout << "What do you want to do?" << endl;
	cout << "1: Play the game." << endl;
	cout << "2: Open README." << endl;
	cout << "3: Exit game." << endl << endl;
	// Get Input
	selection = getInput(1, 3);
	switch (selection)
	{
	case 1:
		cout << endl;
		cout << "What is your name?" << endl;
		cin.getline(name, 50);
		game();
		break;
	case 2:
		system("cls");		//Clean screen
		showLoadingText("Opening");
		openFile("../../README");
		_getch();
		system("cls");		//Clean screen
		break;
	case 3:
		exitApp = true;
		break;
	default:
		break;
	}
}


int main()
{
	mainMenu();
	if (!exitApp)
		main();
	return 0;
}


