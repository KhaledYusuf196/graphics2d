#pragma once
class Vector2d
{

public:
	float x;
	float y;
	static Vector2d origin();
	Vector2d(float x=0.0,float y=0.0);
	~Vector2d();
};

