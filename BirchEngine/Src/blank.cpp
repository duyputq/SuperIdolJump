/*



	SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
	Vector2D playerPos = player.getComponent<TransformComponent>().position;


		for (auto& c : colliders)
	{
		//Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
		SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(cCol, playerCol))
		{

			cout << "collider hit!" << endl;
			//player.getComponent<TransformComponent>().velocity * -1;
			if (keystates[SDL_SCANCODE_LEFT]) {
				playerPos.x = playerPos.x - 1;
			}
			if (keystates[SDL_SCANCODE_RIGHT]) {
				playerPos.x = playerPos.x + 1;
			}
			player.getComponent<TransformComponent>().position = playerPos;

		}
	}













*/