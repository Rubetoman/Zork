#include <string>
#pragma once

using namespace std;

/* Base class for classes that have a name as a variable.*/
class Entity
{
protected:
	string name;				// Name of the Entity.
public:
	void setName(string name);	// Sets the name variable of the Entity.
	string getName();			// Get the name variable of Entity.
};

