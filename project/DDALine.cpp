#include "stdafx.h"
#include "DDALine.h"


void DDALine::draw(HDC hdc,COLORREF c)
{
	if (start.equals(end))return;
	int dx = end.x - start.x;
	int dy = end.y - start.y;
	SetPixel(hdc, start.x, start.y, c);
	if (abs(dx) > abs(dy)) {
		int x = start.x, xinc = dx > 0 ? 1 : -1;
		double y = start.y, yinc = (double)dy / dx*xinc;
		while (x != end.x) {
			x += xinc;
			y += yinc;
			SetPixel(hdc, x+0.5, y+0.5, c);
		}
	}
	else {
		int y = start.y, yinc = dy > 0 ? 1 : -1;
		double x = start.x, xinc = (double)dx / dy*yinc;
		while (y != end.y) {
			x += xinc;
			y += yinc;
			SetPixel(hdc, x+0.5, y+0.5, c);
		}
	}
	end = start = Vector2d::init();
}

void DDALine::readFromFile(char file[])
{
	
}

void DDALine::writeIntoFile(char file[])
{
	
}


DDALine::DDALine(Vector2d p1, Vector2d p2):Line(p1,p2)
{
}
