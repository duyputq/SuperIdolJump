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
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 2;

	int speed = 1;
	float gravity = 2.1f;
	bool isJumping = false;

	//constuctor
	TransformComponent()
	{
		//position.x = 0.0f;
		//position.y = 0.0f;
		position.Zero();
	}

	TransformComponent(int sc)
	{
		//position.x = 0.0f;
		//position.y = 0.0f;
		position.Zero();
		/*#19*/
		//position.x = 400;
		//position.y = 320;

		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		//position.x = x;
		//position.y = y;
		position.Zero();

	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}
	//void init() override
	//{
	//	xpos = 0;
	//	ypos = 0;
	//}
	void init() override
	{
		//velocity.x = 0;
		//velocity.y = 0;
		velocity.Zero();
	}

	void update() override
	{
		//xpos++;
		//ypos++;
		/*#19 xoa dong nay*/
		//position.x += velocity.x * speed;
		//position.y += velocity.y * speed;

		if (isJumping)
		{
			velocity.y += gravity;
		}
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;

		if (position.y > 600)
		{
			position.y = 600;
			velocity.y = 0;
			isJumping = false;
		}

	}

	int x() { return xpos; }
	void x(int x) { xpos = x; }
	int y() { return ypos; }
	void y(int y) { ypos = y; }
	void setPos(int x, int y) { xpos = x; ypos = y; }


};