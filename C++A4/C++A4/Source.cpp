#pragma once
#include <iostream>
#include <string>
#include "Array.h"

struct Pos 
{
	float x, y, z;
};

enum Type
{
	Enemy,Ogre,Soldier
};

struct Entity
{
	Type type;
	Pos position;
	std::string str;
	int idx;
};

