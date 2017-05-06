#pragma once
#include "Clip.h"
#include "DDALine.h"

class LineClip : public Clip
{
private:
	Vector2d start;
	Vector2d end;
	DDALine line;
	union OutCode
	{
		unsigned All : 4;
		struct { unsigned left : 1, top : 1, right : 1, bottom : 1; };
	};
	OutCode GetStartOutCode();
	OutCode GetEndOutCode();
	Vector2d intersectLeft();
	Vector2d intersectRight();
	Vector2d intersectTop();
	Vector2d intersectBottom();
public:
	LineClip(Vector2d p1 = Vector2d::init(), Vector2d p2 = Vector2d::init());
	void draw(HDC hdc, COLORREF c);
	void addInput(Vector2d p);
	bool validInput();
	void readFromFile(ifstream file);
	void writeIntoFile(ofstream file);
	~LineClip();
};
