#pragma once

enum CTYPE{ CPOSITION, CROTATE, CMOVE, CRENDER, CCOLLIDE };

class Entity {
	public:
		Entity();
		~Entity();
		void AddComponent(CTYPE type);
		void RemoveComponent(CTYPE type);
};
