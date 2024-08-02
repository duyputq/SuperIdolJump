#pragma once

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
private:
	int xpos;
	int ypos;

public:
	Vector2D position;

	//constuctor
	TransformComponent()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent(int x, int y)
	{
		position.x = x;
		position.y = y;
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