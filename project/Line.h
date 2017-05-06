#pragma once
#include "Drawing.h"
class Line : public Drawing
{
protected:
	Vector2d start;
	Vector2d end;
public:
	void addInput(Vector2d);
	bool validInput();
	Line(Vector2d p1 = Vector2d::init(), Vector2d p2 = Vector2d::init());
	~Line();
};