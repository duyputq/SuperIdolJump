#pragma once


#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
private:
	int xpos;
	int ypos;


public:
	Vector2D velocity;
	Vector2D position;
	//float gravity = 4.3f;
	bool isJumping = false;
	bool isAir = true;
	bool isMain = true;


	int height = 32;
	int width = 32;
	int scale = 2;

	int speed = 1;


	//constuctor
	TransformComponent()
	{
		position.Zero();
	}

	TransformComponent(int sc)
	{

		position.Zero();


		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		position.x = x;
		position.y = y;
		//position.Zero();

	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	void init() override
	{


		velocity.Zero();
	}

	void update() override
	{

		if (isMain) {
			position.y += velocity.y;
			position.x += velocity.x;
		}



	}

	int x() { return xpos; }
	void x(int x) { xpos = x; }
	int y() { return ypos; }
	void y(int y) { ypos = y; }
	void setPos(int x, int y) { xpos = x; ypos = y; }


};