#pragma once
#include "Vector2d.h"
#include <Windows.h>
using namespace std;

class Drawing
{
public:
	int priority;
	virtual void addInput(Vector2d) = 0;
	virtual void readFromFile(char file[]) = 0;
	virtual void writeIntoFile(char file[]) = 0;
	virtual void draw(HDC hdc,COLORREF c) = 0;
};
