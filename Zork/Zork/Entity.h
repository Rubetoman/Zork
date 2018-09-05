#include <string>
#pragma once

using namespace std;

class Entity
{
protected:
	string name;
public:
	void setName(string name);
	string getName();
};

