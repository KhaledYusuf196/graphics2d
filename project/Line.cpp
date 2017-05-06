#include "stdafx.h"
#include "Line.h"




Line::Line(Vector2d p1, Vector2d p2)
{
	start = p1;
	end = p2;
}

void Line::addInput(Vector2d p)
{
	if (end.equals(start)) {
		end = p;
	}
	if (start.equals(Vector2d::init())) {
		start = p;
	}
}

bool Line::validInput()
{
	return !end.equals(start);
}

Line::~Line()
{
}
