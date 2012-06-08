#pragma once

class Entity;

class Component {
	protected:
		Entity *parent;
	public:
		virtual void Update()=0;
};
