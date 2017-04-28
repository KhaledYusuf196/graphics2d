#pragma once
#include "Vector2d.h"
#include <Windows.h>
using namespace std;

class Drawing
{
public:
	int priority;
	virtual void readFromFile(char file[]) = 0;
	virtual void writeIntoFile(char file[]) = 0;
	virtual void draw(HDC) = 0;
};
