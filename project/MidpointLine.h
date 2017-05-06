#pragma once
#include "Line.h"
class MidpointLine :public Line
{
public:
	void draw(HDC, COLORREF c);
	void readFromFile(ifstream file);
	void writeIntoFile(ofstream file);
	MidpointLine(Vector2d p1 = Vector2d::init(), Vector2d p2 = Vector2d::init());
};

