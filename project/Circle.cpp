#include "stdafx.h"
#include "Circle.h"





void Circle::addInput(Vector2d p)
{
	if (origin.equals(Vector2d::init())) {
		origin = p;
	}
	if (radius = 0) {
		radius = (p - origin).magnitude();
	}
}

Circle::Circle(Vector2d origin, int radius)
{
	this->origin = origin;
	this->radius = radius;
}

Circle::~Circle()
{
}
