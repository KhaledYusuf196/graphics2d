#include "stdafx.h"
#include "ParametricLine.h"



void ParametricLine::draw(HDC hdc, COLORREF c)
{
	Vector2d d(end.x - start.x, end.y - start.y);
	float n = 1.0f/max(abs((int)d.x), abs((int)d.y));
	Vector2d p;
	for (float i = 0; i <= 1;i+=n) {
		p = start + (end - start)*i;
		SetPixel(hdc, p.x+0.5, p.y+0.5, c);
	}
	end = start = Vector2d::init();
}

void ParametricLine::readFromFile(ifstream file)
{
	file.read((char*)this, sizeof(ParametricLine));
}

void ParametricLine::writeIntoFile(ofstream file)
{
	file.write((char*)this, sizeof(ParametricLine));
}

ParametricLine::ParametricLine(Vector2d p1, Vector2d p2):Line(p1,p2)
{
}


