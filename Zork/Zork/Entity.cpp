#include "stdafx.h"
#include "Entity.h"


void Entity::setName(string name)
{
	this->name = name;
}

string Entity::getName() {
	if (!this->name.empty())
		return this->name;
	else
		return "null";
}
