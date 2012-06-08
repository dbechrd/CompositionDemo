#pragma once

#include "Component.h"
#include <map>
#include "windows.h"
#include <GL/gl.h>

class IRender: public Component {
	public:
		static std::map<Entity*, IRender*> collection;
		static std::map<Entity*, IRender*>::iterator iter;

		static IRender *GetRef(Entity *entity);
		static void UpdateSystem();

		//OpenGL Texture
		GLuint tex;

		IRender(Entity *entity);
		~IRender();
		void Update();
};
