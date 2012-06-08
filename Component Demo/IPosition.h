#pragma once

#include "Component.h"
#include <map>
class BBox;

class IPosition: public Component {
	public:
		static std::map<Entity*, IPosition*> collection;
		static std::map<Entity*, IPosition*>::iterator iter;

		static IPosition *GetRef(Entity *entity);
		static void UpdateSystem();

		//Location
        float x;
        float y;
        float z;

		//Scale
		float scalex;
		float scaley;
		float scalez;

		//Bounding Box
		BBox *bbox;

		IPosition(Entity *entity);
		~IPosition();
		void Update();
};