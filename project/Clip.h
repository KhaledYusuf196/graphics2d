#pragma once
#include "Drawing.h"
class Clip : public Drawing
{
protected:
	Vector2d leftBottom;
	Vector2d RightTop;
public:
	void addFrameInput(Vector2d p);
	Clip(Vector2d p1 = Vector2d::init(), Vector2d p2 = Vector2d::init());
	~Clip();
};

