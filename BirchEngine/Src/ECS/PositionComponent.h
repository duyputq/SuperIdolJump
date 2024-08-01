#pragma once

#include "Components.h"

class PositionComponent : public Component
{
private:
	int xpos;
	int ypos;

public:
	//constuctor
	PositionComponent()
	{
		xpos = 100;
		ypos = 500;
	}

	PositionComponent(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	//void init() override
	//{
	//	xpos = 0;
	//	ypos = 0;
	//}

	void update() override
	{
		xpos++;
		ypos++;
	}

	int x() { return xpos; }
	void x(int x) { xpos = x; }
	int y() { return ypos; }
	void y(int y) { ypos = y; }
	void setPos(int x, int y) { xpos = x; ypos = y; }


};