#include "stdafx.h"
#include "Vector2d.h"



Vector2d Vector2d::origin()
{
	return Vector2d(0,0);
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2d::~Vector2d()
{
}
