#include "stdafx.h"
#include "ThirdCurve.h"


ThirdCurve::ThirdCurve(Vector2d p1, Vector2d p2, Vector2d p3, Vector2d p4)
{
	start = p1;
	cstart = p2;
	cend = p3;
	end = p4;
}

ThirdCurve::~ThirdCurve()
{
}
