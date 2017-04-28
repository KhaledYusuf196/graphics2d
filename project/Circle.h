#pragma once
#include "Drawing.h"
class Circle : public Drawing
{
private:
	int radius;
	Vector2d origin;
public:
	virtual void readFromFile() = 0;
	virtual void writeIntoFile() = 0;
	virtual void draw() = 0;
	Circle(Vector2d origin ,int radius = 0);
	~Circle();
};

