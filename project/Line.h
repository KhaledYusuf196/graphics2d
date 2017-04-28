#pragma once
#include "Drawing.h"
class Line : public Drawing
{
protected:
	Vector2d start;
	Vector2d end;
public:
	virtual void readFromFile() = 0;
	virtual void writeIntoFile() = 0;
	virtual void draw() = 0;
	Line(Vector2d p1, Vector2d p2);
	~Line();
};