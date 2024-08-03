#include "Collision.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
	if (
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.w >= recB.y &&
		recB.y + recB.w >= recA.y
		)
	{
		return true;
	}

	return false;
}


