#include "stdafx.h"
#include "Vector2d.h"
#include <cmath>



bool Vector2d::equals(Vector2d p)
{
	return p.x == x && p.y == y;
}

Vector2d Vector2d::init()
{
	return Vector2d(-1,-1);
}

Vector2d Vector2d::operator+(Vector2d p)
{
	return Vector2d(x+p.x,y+p.y);
}

Vector2d Vector2d::operator-(Vector2d p)
{
	return Vector2d(x-p.x,y-p.y);
}

Vector2d Vector2d::operator*(float n)
{
	return Vector2d(n*x,n*y);
}

float Vector2d::magnitude()
{
	return sqrt(x*x + y*y);
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2d::~Vector2d()
{
}
