#include "stdafx.h"
#include "LineClip.h"


LineClip::OutCode LineClip::GetStartOutCode()
{
	OutCode out;
	out.All = 0;
	if (start.x<leftBottom.x)out.left = 1; else if (start.x>RightTop.x)out.right = 1;
	if (start.y>RightTop.y)out.top = 1; else if (start.y<leftBottom.y)out.bottom = 1;
	return out;
}

LineClip::OutCode LineClip::GetEndOutCode()
{
	OutCode out;
	out.All = 0;
	if (end.x<leftBottom.x)out.left = 1; else if (end.x>RightTop.x)out.right = 1;
	if (end.y>RightTop.y)out.top = 1; else if (end.y<leftBottom.y)out.bottom = 1;
	return out;
}

Vector2d LineClip::intersectLeft()
{
	return Vector2d(leftBottom.x, start.y + (leftBottom.x - start.x)*(end - start).y / (end - start).x); 
}

Vector2d LineClip::intersectRight()
{
	return Vector2d(RightTop.x, start.y + (RightTop.x - start.x)*(end - start).y / (end - start).x);
}

Vector2d LineClip::intersectTop()
{
	return Vector2d(start.x+(RightTop.y-start.y)*(end - start).x / (end - start).y,RightTop.y);
}

Vector2d LineClip::intersectBottom()
{
	return Vector2d(start.x + (leftBottom.y - start.y)*(end - start).x / (end - start).y, leftBottom.y);
}

LineClip::LineClip(Vector2d p1, Vector2d p2):Clip(p1, p2)
{
	start = Vector2d::init();
	end = Vector2d::init();
	line = DDALine(start,end);
}

void LineClip::draw(HDC hdc, COLORREF c)
{
	OutCode out1 = GetStartOutCode();
	OutCode out2 = GetEndOutCode();
	while ((out1.All || out2.All) && !(out1.All & out2.All))
	{
		if (out1.All) {
			if (out1.left)start = intersectLeft();
			else if (out1.bottom)start = intersectBottom();
			else if (out1.top)start = intersectTop();
			else start = intersectRight();
			out1 = GetStartOutCode();
		}
		else {
			if (out2.left)end = intersectLeft();
			else if (out2.bottom)end = intersectBottom();
			else if (out2.top)end = intersectTop();
			else end = intersectRight();
			out2 = GetEndOutCode();
		}
	}
	if (!out1.All && !out2.All) {
		MoveToEx(hdc, start.x, start.y, NULL);
		LineTo(hdc, end.x, end.y);
	}
	start = end = Vector2d::init();

}

void LineClip::addInput(Vector2d p)
{
	if (leftBottom.equals(RightTop)) {
		addFrameInput(p);
	}
	else {
		if (end.equals(start)) {
			end = p;
		}
		if (start.equals(Vector2d::init())) {
			start = p;
		}
	}
}

bool LineClip::validInput()
{
	return !start.equals(end);
}

void LineClip::readFromFile(ifstream file)
{
	file.read((char*)this, sizeof(LineClip));
}

void LineClip::writeIntoFile(ofstream file)
{
	file.write((char*)this, sizeof(LineClip));
}

LineClip::~LineClip()
{
}
