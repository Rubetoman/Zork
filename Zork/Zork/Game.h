#pragma once

#include "stdafx.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void mainMenu();

	//Accessors
	inline bool getPlaying() const { return this->playing; }

	//Modifiers

private:
	int choice;
	bool playing;
};

