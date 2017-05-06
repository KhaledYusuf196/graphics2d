#include "stdafx.h"
#include "PointClip.h"


void PointClip::addInput(Vector2d p)
{
	if (leftBottom.equals(RightTop)) {
		addFrameInput(p);
	}
	else {
		point = p;
	}
}

bool PointClip::validInput() {
	return point.equals(Vector2d::init());
}

void PointClip::draw(HDC hdc, COLORREF c)
{
	if (point.x>leftBottom.x && point.y>leftBottom.y && point.x<RightTop.x && point.y<RightTop.y)
		SetPixel(hdc, point.x, point.y, c);
	point = Vector2d::init();
}

void PointClip::readFromFile(ifstream file)
{
	file.read((char*)this, sizeof(PointClip));
}

void PointClip::writeIntoFile(ofstream file)
{
	file.write((char*)this, sizeof(PointClip));
}

PointClip::PointClip(Vector2d p1, Vector2d p2):Clip(p1,p2)
{
}

PointClip::~PointClip()
{
}
