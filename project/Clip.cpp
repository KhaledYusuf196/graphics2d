#include "stdafx.h"
#include "Clip.h"


void Clip::addFrameInput(Vector2d p)
{
	if (leftBottom.equals(Vector2d::init())) {
		leftBottom = p;
	}
	RightTop = p;
	if (leftBottom.x > RightTop.x) {
		float temp = leftBottom.x;
		leftBottom.x = RightTop.x;
		RightTop.x = temp;
	}
	if (leftBottom.y > RightTop.y) {
		float temp = leftBottom.y;
		leftBottom.y = RightTop.y;
		RightTop.y = temp;
	}
}

Clip::Clip(Vector2d p1, Vector2d p2)
{
	leftBottom = p1;
	RightTop = p2;
}

Clip::~Clip()
{
}
