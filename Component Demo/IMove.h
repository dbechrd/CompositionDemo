#pragma once

#include "Component.h"
#include <map>

class IMove: public Component {
	public:
		static std::map<Entity*, IMove*> collection;
		static std::map<Entity*, IMove*>::iterator iter;

		static IMove *GetRef(Entity *entity);
		static void UpdateSystem();

		//Velocity
		float xVel;
		float yVel;
		float zVel;

		//Acceleration
		float xAccel;
		float yAccel;
		float zAccel;

		IMove(Entity *entity);
		~IMove();
		void Update();
};
