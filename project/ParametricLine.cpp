#include "stdafx.h"
#include "ParametricLine.h"



void ParametricLine::draw(HDC hdc, COLORREF c)
{
	if (start.equals(end))return;
	int dx = end.x - start.x;
	int dy = end.y - start.y;
	float n = 1.0f/max(abs(dx), abs(dy));
	Vector2d p;
	for (float i = 0; i <= 1;i+=n) {
		p = start + (end - start)*i;
		SetPixel(hdc, p.x+0.5, p.y+0.5, c);
	}
	end = start = Vector2d::init();
}

void ParametricLine::readFromFile(char file[])
{
}

void ParametricLine::writeIntoFile(char file[])
{
}

ParametricLine::ParametricLine(Vector2d p1, Vector2d p2):Line(p1,p2)
{
}


