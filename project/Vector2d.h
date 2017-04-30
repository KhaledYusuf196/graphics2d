#pragma once
class Vector2d
{

public:
	float x;
	float y;
	bool equals(Vector2d);
	static Vector2d init();
	Vector2d operator+(Vector2d);
	Vector2d operator-(Vector2d);
	Vector2d operator*(float);
	float magnitude();
	Vector2d(float x=0.0,float y=0.0);
	~Vector2d();
};

