#pragma once

#include "Component.h"
#include <map>

class IRotate: public Component {
	public:
		static std::map<Entity*, IRotate*> collection;
		static std::map<Entity*, IRotate*>::iterator iter;

		static IRotate *GetRef(Entity *entity);
		static void UpdateSystem();

		//Rotation
        float xRot;
        float yRot;
        float zRot;

		//Rotational Velocity
        float xRVel;
        float yRVel;
        float zRVel;

		IRotate(Entity *entity);
		~IRotate();
		void Update();
};
