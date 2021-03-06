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

bool exitApp = false;		// When true exit app.
char name[50];				// Name of the player.

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
		cout << "\n<----------------------Press any key to continue---------------------->" << endl;
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
			_getch();
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
		
		selection = getInput(1, 3);	// Get Input.
		system("cls");				// Clean screen.
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
			system("cls");	//Clean screen.
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

		selection = getInput(1, 3);	// Get Input.
		system("cls");				// Clean screen.
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
			system("cls");	//Clean screen.
			break;
		default:
			break;
		}
	}

	// 3rd SELECTION
	cout << endl << "The phone is showing a call from a number you can't recognize." << endl;
	cout << "What would you like to do?" << endl << endl;
	cout << "1: Pick up the phone." << endl;
	cout << "2: Hang up the telephone." << endl << endl;

	selection = getInput(1, 2);	// Get Input.
	system("cls");				// Clean screen.
	switch (selection)
	{
	case 1: // Pick up.
		system("cls");			// Clean screen.
		cout << "???: Hello, I'm talking with " << name << "?" << endl << endl;
		Sleep(1200);
		cout << "                                                      " << name << ": Hi, yes." << endl << endl;
		Sleep(1800);
		cout << "???: My name is Maria, you send us your acceptance proposal" << endl;
		cout << "     for our Master degree on Videogame Design." << endl;
		Sleep(1800);
		cout << "     Is that right?" << endl<< endl;
		Sleep(1800);
		cout << "                                                      " << name << ": Yes, I sent it a week ago. It's everything right?" << endl << endl;
		Sleep(1800);
		cout << "Maria: Yes, everything is fine. " << endl; 
		Sleep(1200);
		cout << "       Now you need to complete the access C++ test to show your knowledge." << endl;
		Sleep(1600);
		cout << "       I will send it to you today and you have to send it back next Monday. Ok?" << endl << endl;
		Sleep(1800);
		cout << "                                                      " << name << ": Ok, I will complete it and send it as soon as posible." << endl << endl;
		Sleep(1800);
		cout << "Maria: Alright, bye." << endl << endl;
		Sleep(1800);
		cout << "                                                      " << name << ": Bye." << endl << endl;
		Sleep(1200);
		cout << "                               CALL ENDED         " << endl;
		waitForInput(false);
		_getch();
		break;
	case 2:	// Hang up.
		system("cls");			//Clean screen.
		cout << "It's too early in the morning for attending calls. You hang up the phone and go back to bed ignoring the call." << endl;
		cout << "\n                             THE END                           " << endl;
		cout << "\n----------------------Press any key to exit----------------------" << endl;
		_getch();				// Wait without message.
		exitApp = true;			// Close app.
		return;
		break;
	default:
		break;
	}

	// 4th SELECTION
	while (!inventory.hasItem("Laptop + Battery") && !inventory.hasItem("Battery + Laptop")) {
		system("cls");				// Clean screen.
		if(!inventory.hasItem("Laptop") && !inventory.hasItem("Laptop + Battery") && !inventory.hasItem("Battery + Laptop"))
			cout << "I should get my laptop to take a look to the test. It should be on the living room." << endl << endl;
		cout << "What would you like to do?" << endl;
		cout << "1: Look for objects" << endl;
		cout << "2: Move to another room" << endl;
		cout << "3: Open inventory" << endl << endl;

		selection = getInput(1, 3);	// Get Input.
		system("cls");				// Clean screen.
		switch (selection)
		{
		case 1:
			lookForItems();
			break;
		case 2:
			currentRoom = move();
			break;
		case 3:
			manageInventory();
			system("cls");		// Clean screen.
			break;
		default:
			break;
		}
	}
	cout << "You switched on the laptop and opened the email sended by Maria." << endl;
	openFile("Mail");
	showLoadingText("Opening email");
	waitForInput(false);
	_getch();
	system("cls");		// Clean screen.
	cout << "After reading the email it looks like you have to program a game similar to Zork on one week." << endl;
	Sleep(1800);
	cout << "What a bad time for it, you just happend to be on hollidays on another country and you are not returning home untill two weeks." << endl;
	Sleep(300);
	waitForInput(false);
	_getch();
	system("cls");		// Clean screen.
	cout << "After some days of hard work " << name << " made this game." << endl;
	Sleep(1800);
	cout << "Now it's time to wait for the University to decide whether " << name << " was accepted or not" << endl << endl;
	Sleep(1800);
	cout << "Game made by Ruben Crispin" << endl;
	cout << "\n                             THE END                           " << endl;
	cout << "\n----------------------Press any key to exit----------------------" << endl;
	_getch();
	exitApp = true;			// Close app.
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
	laptop.setDescription("Your laptop. The battery is not inserted so it will not switch on.");
	battery.setName("Battery");
	battery.setDescription("Looks like a battery for a laptop");
	battery.setCompatibleItem(laptop);
	telephone.setName("Telephone");
	telephone.setDescription("It's an andrIOs smartphone.");
	laptop.setCompatibleItem(battery);
	//inventory.addItem(laptop);
	//inventory.addItem(battery);

	// Initialize rooms
	bedroom.setName("Bedroom");
	livingRoom.setName("Living Room");
	kitchen.setName("Kitchen");
	toilet.setName("Toilet");
	entrance.setName("Entrance");
	bedroom.setDescription("Your bedroom, here you spend most of the time studying or playing videogames.");
	livingRoom.setDescription("The place where you spend time with your family or playing your console on the big TV.");
	kitchen.setDescription("No one can remember when was the last time you used the kitchen for something futher than eating. Really, you shoul start learning how to cook.");
	toilet.setDescription("Just a common toilet.");
	entrance.setDescription("The first place you put foot on when enter your house, is full of regretable pictures of you as a child.");
	bedroom.addItem(battery);
	livingRoom.addItem(laptop);
	toilet.addItem(telephone);
	rooms.push_back(bedroom);
	rooms.push_back(livingRoom);
	rooms.push_back(kitchen);
	rooms.push_back(toilet);
	rooms.push_back(entrance);
	bedroom.setConnectedRooms(rooms);
}

void mainMenu() {
	cout << "What is your name?" << endl;
	cin.getline(name, 10);
	system("cls");					// Clean screen.
	openFile("TitleScreen");		// Open .txt with the title of the game.
	int selection = 0;				// Integer to store player Input. 
	cout << "What do you want to do?" << endl;
	cout << "1: Play the game." << endl;
	cout << "2: Open README." << endl;
	cout << "3: Exit game." << endl << endl;
	selection = getInput(1, 3);		// Get Input.
	switch (selection)
	{
	case 1: // Play game.
		initialization();			// Initialize game variables.
		cout << endl;
		game();
		break;
	case 2: // Show README.
		system("cls");		// Clean screen.
		showLoadingText("Opening");
		openFile("../../README");
		waitForInput(true);	// Wait for the player key press.
		system("cls");		//Clean screen
		break;
	case 3: // Exit.
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


