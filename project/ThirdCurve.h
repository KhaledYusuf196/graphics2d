#pragma once
#include "Drawing.h"
class ThirdCurve : public Drawing
{
protected:
	Vector2d start;
	Vector2d cstart;
	Vector2d cend;
	Vector2d end;
public:
	ThirdCurve(Vector2d p1 = Vector2d::init(), Vector2d p2 = Vector2d::init(), Vector2d p3 = Vector2d::init(), Vector2d p4 = Vector2d::init());
	~ThirdCurve();
};

