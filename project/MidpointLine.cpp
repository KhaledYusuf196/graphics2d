#include "stdafx.h"
#include "MidpointLine.h"

void MidpointLine::draw(HDC hdc, COLORREF c)
{
	if (start.x > end.x) {
		Vector2d temp = end;
		end = start;
		start = temp;
	}
	Vector2d d (end.x - start.x, end.y - start.y);
	Vector2d current = start;
	SetPixel(hdc, current.x, current.y, c);
	if (d.y >= 0) {
		if (d.x > d.y) {
			float di = 0.5*d.x - d.y;
			while (!current.equals(end)) {
				if (di > 0) {
					di -= d.y;
					current = current + Vector2d(1, 0);
					SetPixel(hdc, current.x + 0.5, current.y + 0.5, c);
				}
				else {
					di += d.x - d.y;
					current = current + Vector2d(1, 1);
					SetPixel(hdc, current.x + 0.5, current.y + 0.5, c);
				}
			}
		}
		else {
			float di = d.x - 0.5 * d.y;
			while (!current.equals(end)) {
				if (di > 0) {
					di += d.x - d.y;
					current = current + Vector2d(1, 1);
					SetPixel(hdc, current.x + 0.5, current.y + 0.5, c);
				}
				else {
					di += d.x;
					current = current + Vector2d(0, 1);
					SetPixel(hdc, current.x + 0.5, current.y + 0.5, c);
				}
			}
		}

	}
	else {
		if (d.x > -d.y) {
			float di = 0.5*d.x + d.y;
			while (!current.equals(end)) {
				if (di > 0) {
					di += d.y;
					current = current + Vector2d(1, 0);
					SetPixel(hdc, current.x + 0.5, current.y + 0.5, c);
				}
				else {
					di += d.x + d.y;
					current = current + Vector2d(1, -1);
					SetPixel(hdc, current.x + 0.5, current.y + 0.5, c);
				}
			}
		}
		else {
			float di = d.x + 0.5 * d.y;
			while (!current.equals(end)) {
				if (di > 0) {
					di += d.x + d.y;
					current = current + Vector2d(1, -1);
					SetPixel(hdc, current.x + 0.5, current.y + 0.5, c);
				}
				else {
					di += d.x;
					current = current + Vector2d(0, -1);
					SetPixel(hdc, current.x + 0.5, current.y + 0.5, c);
				}
			}
		}
	}
	end = start = Vector2d::init();
}

void MidpointLine::readFromFile(ifstream file)
{
	file.read((char*)this, sizeof(MidpointLine));
}

void MidpointLine::writeIntoFile(ofstream file)
{
	file.write((char*)this, sizeof(MidpointLine));
}

MidpointLine::MidpointLine(Vector2d p1, Vector2d p2):Line(p1,p2)
{
}
