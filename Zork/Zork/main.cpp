// Zork.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "main.h"
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
Inventory inventory;
Room bedroom;
Room livingRoom;
Room kitchen;
Room toilet;
Room entrance;
Room currentRoom;
vector<Room> rooms;

bool exitApp = false;	// When true exit app.
char name[50];			// Name of the player.

/*	Loops untill player inserts Input in the console.
	Ignores everything that is not an integer inside range
*/
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

/* Uses _getch() function to wait untill player presses a key.
*/
void waitForInput(bool back) {
	if(back)
		cout << "\n<----------------------Press any key to go back---------------------->" << endl;
	else
		cout << "\n<----------------------Press any key to go continue---------------------->" << endl;
	_getch();
}

/*	Animation for the text passed as an argument.
*/
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
	int selection = 0;		// Integer to store player Input.
	currentRoom = bedroom;	// Set current room.
	system("cls");			// Clean screen.

	// START & 1st SELECTION
	cout << "You wake up on your bed with the ringing of a telephone." << endl;
	while (currentRoom.getName() == bedroom.getName()){
		cout << "What would you like to do?" << endl << endl;
		cout << "1: Look for the phone" << endl;
		cout << "2: Move to another room" << endl;
		cout << "3: Stay on the bed" << endl;
		cout << "4: Open inventory" << endl << endl;

		selection = getInput(1, 4);		// Get Input.
		cout << endl;
		system("cls");					//Clean screen
		switch (selection)
		{
		case 1:	// Look for telephone.
			showLoadingText("Looking");
			cout << "You start looking everywhere but you don't find it, the sound is comming from another room." << endl << endl;
			waitForInput(false);	// Wait for the player key press.
			break;
		case 2:	// Move to another room.
			currentRoom = move();
			if (currentRoom.getName() != toilet.getName())	// Moved to the toilet (where the telephone is).
				cout << "The phone stills ringing." << endl;
			else
				cout << "The sound of the ringing is louder on this room." << endl;
			waitForInput(false);	// Wait for the player key press.
			break;
		case 3:	// Stay in bed (Alt. ending)
			system("cls");			//Clean screen.
			cout << "You decide to stay on the bed and ignore the call. Probably it is nothing important" << endl;
			cout << "\n                             THE END                           " << endl;
			cout << "\n----------------------Press any key to exit----------------------" << endl;
			_getch();				// Wait without message.
			exitApp = true;			// Close app.
			return;
			break;
		case 4:
			manageInventory();
			system("cls");			//Clean screen.
		default:
			break;
		}
		system("cls");				//Clean screen.
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
			system("cls");		//Clean screen
			break;
		default:
			break;
		}
	}
	
	while (!inventory.hasItem("Telephone")) {
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
			cout << "You found your telephone, weird place to be..." << endl;
			pickUpItem(currentRoom.getItemNumber("Telephone"));
			showLoadingText("");
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
			system("cls");		//Clean screen
			break;
		default:
			break;
		}
	}

	cout << "DIALOGUE" << endl;
	waitForInput(true);	// Wait for the player key press.
}

void openFile(string fileName) {
	std::ifstream f(fileName + ".txt");

	if (f.is_open())
		std::cout << f.rdbuf();
	else
		cout << fileName << ".txt couldn't be found." << endl;
}

void initialization() {
	// Initialize inventory
	inventory.setName("PlayerInventory");
	// Initialize items
	Item laptop, battery, telephone;
	laptop.setName("Laptop");
	laptop.setDescription("Your laptop");
	battery.setName("Battery");
	battery.setDescription("Looks like a battery for a laptop");
	battery.setCompatibleItem(laptop);
	telephone.setName("Telephone");
	telephone.setDescription("It's an andrIOs smartphone.");
	laptop.setCompatibleItem(battery);
	inventory.addItem(laptop);
	inventory.addItem(battery);

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
	toilet.addItem(telephone);
	rooms.push_back(bedroom);
	rooms.push_back(livingRoom);
	rooms.push_back(kitchen);
	rooms.push_back(toilet);
	rooms.push_back(entrance);
	bedroom.setConnectedRooms(rooms);
}

void mainMenu() {
	openFile("TitleScreen");	// Open .txt with the title of the game.
	initialization();			// Initialize game variables.
	int selection = 0;			// Integer to store player Input. 
	cout << "What do you want to do?" << endl;
	cout << "1: Play the game." << endl;
	cout << "2: Open README." << endl;
	cout << "3: Exit game." << endl << endl;
	selection = getInput(1, 3);		// Get Input.
	switch (selection)
	{
	case 1:
		cout << endl;
		/*cout << "What is your name?" << endl;
		cin.getline(name, 50);*/
		game();
		break;
	case 2:
		system("cls");		//Clean screen.
		showLoadingText("Opening");
		openFile("../../README");
		waitForInput(true);	// Wait for the player key press.
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


