#pragma once
#include "Line.h"
class ParametricLine : public Line
{
public:
	void draw(HDC, COLORREF c);
	void readFromFile(char file[]);
	void writeIntoFile(char file[]);
	ParametricLine(Vector2d p1 = Vector2d::init(), Vector2d p2 = Vector2d::init());
};

