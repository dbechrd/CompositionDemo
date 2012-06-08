#include "ICollide.h"

std::map<Entity*, ICollide*> ICollide::collection;
std::map<Entity*, ICollide*>::iterator ICollide::iter;
ICollide *ICollide::GetRef(Entity *entity)
{
	iter = collection.find(entity);
	if(iter != collection.end())
	{
		return iter->second;
	}
	return NULL;
}

void ICollide::UpdateSystem()
{
	if(collection.size() > 0)
	{
		for(iter = collection.begin(); iter != collection.end(); iter++)
		{
			iter->second->Update();
		}
	}
}

ICollide::ICollide(Entity *entity)
{
	parent = entity;
	collection[parent] = this;
}

ICollide::~ICollide(void)
{
	iter = collection.find(parent);
	collection.erase(iter);
}

void ICollide::Update()
{
}