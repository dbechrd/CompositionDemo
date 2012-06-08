#pragma once

#include "Component.h"
#include <map>

class ICollide: public Component {
	public:
		static std::map<Entity*, ICollide*> collection;
		static std::map<Entity*, ICollide*>::iterator iter;

		static ICollide *GetRef(Entity *entity);
		static void UpdateSystem();

		ICollide(Entity *entity);
		~ICollide();
		void Update();
};
