#include "IRotate.h"

#include "IPosition.h"

#include <iostream>

std::map<Entity*, IRotate*> IRotate::collection;
std::map<Entity*, IRotate*>::iterator IRotate::iter;
IRotate *IRotate::GetRef(Entity *entity)
{
	iter = collection.find(entity);
	if(iter != collection.end())
	{
		return iter->second;
	}
	return NULL;
}

void IRotate::UpdateSystem()
{
	if(collection.size() > 0)
	{
		for(iter = collection.begin(); iter != collection.end(); iter++)
		{
			iter->second->Update();
		}
	}
}

IRotate::IRotate(Entity *entity)
{
	parent = entity;

	//Initialize attributes
	xRot = 0.0f;
	yRot = 0.0f;
	zRot = 0.0f;

	xRVel = 0.0f;
	yRVel = 0.0f;
	zRVel = 0.0f;

	//Add to collection
	collection[parent] = this;
}

IRotate::~IRotate(void)
{
	iter = collection.find(parent);
	collection.erase(iter);
}

void IRotate::Update()
{
	//Get parent entity's position
	IPosition *pos = IPosition::GetRef(parent);
	
	//Update rotation
	if(pos == NULL)
	{
		std::cout << "Error: An entity without a position component need not be rotated.\n";
		return;
	}

	xRot += xRVel;
	yRot += yRVel;
	zRot += zRVel;
}