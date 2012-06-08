#include "IMove.h"
#include "IPosition.h"
#include <iostream>

std::map<Entity*, IMove*> IMove::collection;
std::map<Entity*, IMove*>::iterator IMove::iter;
IMove *IMove::GetRef(Entity *entity)
{
	iter = collection.find(entity);
	if(iter != collection.end())
	{
		return iter->second;
	}
	return NULL;
}

void IMove::UpdateSystem()
{
	if(collection.size() > 0)
	{
		for(iter = collection.begin(); iter != collection.end(); iter++)
		{
			iter->second->Update();
		}
	}
}

IMove::IMove(Entity *entity)
{
	parent = entity;

	//Initialize attributes
	xVel = 0.0f;
	yVel = 0.0f;
	zVel = 0.0f;

	xAccel = 0.0f;
	yAccel = 0.0f;
	zAccel = 0.0f;

	//Add to collection
	collection[parent] = this;
}

IMove::~IMove(void)
{
	iter = collection.find(parent);
	collection.erase(iter);
}

void IMove::Update()
{
	//Get parent entity's position
	IPosition *pos = IPosition::GetRef(parent);
	
	//Update position
	if(pos == NULL)
	{
		std::cout << "Error: An entity without a position component cannot be moved.\n";
		return;
	}

	xVel += xAccel;
	yVel += yAccel;
	zVel += zAccel;

	pos->x += xVel;
	pos->y += yVel;
	pos->z += zVel;
}