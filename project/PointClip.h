#pragma once
#include "Clip.h"
class PointClip : public Clip
{
private:
	Vector2d point;
public:
	void addInput(Vector2d p);
	bool validInput();
	void draw(HDC hdc, COLORREF c);
	void readFromFile(ifstream file);
	void writeIntoFile(ofstream file);
	PointClip(Vector2d p1 = Vector2d::init(), Vector2d p2 = Vector2d::init());
	~PointClip();
};

