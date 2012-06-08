#include "Entity.h"
#include "IPosition.h"
#include "IRotate.h"
#include "IMove.h"
#include "IRender.h"
#include "ICollide.h"

Entity::Entity()
{
	//Add default components
}

Entity::~Entity()
{
	//Clean up components
	//TODO: Only search map for components we know exist
	//		(track currently attached components)
	delete IPosition::collection[this];
	delete IRotate::collection[this];
	delete IMove::collection[this];
	delete IRender::collection[this];
	delete ICollide::collection[this];
	IPosition::collection.erase(this);
	IRotate::collection.erase(this);
	IMove::collection.erase(this);
	IRender::collection.erase(this);
	ICollide::collection.erase(this);
}

void Entity::AddComponent(CTYPE type)
{
	//Add to collection
	switch(type)
	{
		case CPOSITION:
			IPosition::collection[this] = new IPosition(this);
			break;
		case CROTATE:
			IRotate::collection[this] = new IRotate(this);
			break;
		case CMOVE:
			IMove::collection[this] = new IMove(this);
			break;
		case CRENDER:
			IRender::collection[this] = new IRender(this);
			break;
		case CCOLLIDE:
			ICollide::collection[this] = new ICollide(this);
			break;
	}
}

void Entity::RemoveComponent(CTYPE type)
{
	//Remove from collection
	switch(type)
	{
		case CPOSITION:
			delete IPosition::collection[this];
			IPosition::collection.erase(this);
			break;
		case CROTATE:
			delete IRotate::collection[this];
			IRotate::collection.erase(this);
			break;
		case CMOVE:
			delete IMove::collection[this];
			IMove::collection.erase(this);
			break;
		case CRENDER:
			delete IRender::collection[this];
			IRender::collection.erase(this);
			break;
		case CCOLLIDE:
			delete ICollide::collection[this];
			ICollide::collection.erase(this);
			break;
	}
}