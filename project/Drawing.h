#pragma once
#include "Vector2d.h"
#include <Windows.h>
#include <fstream>

using namespace std;

class Drawing
{
public:
	int priority;
	virtual void addInput(Vector2d) = 0;
	virtual bool validInput() = 0;
	virtual void readFromFile(ifstream file) = 0;
	virtual void writeIntoFile(ofstream file) = 0;
	virtual void draw(HDC hdc,COLORREF c) = 0;
};
