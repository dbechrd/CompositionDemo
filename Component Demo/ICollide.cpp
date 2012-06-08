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

/*
bool AABBCollision(Collidable *body1, Collidable *body2, Vector2 &normal)
{
	// The normal vector has to be reset every time this function is called.
	// At this point we do not know which of its components will change to push the object being collided with.
	// The other component is always zero.
	normal.x = 0;
	normal.y = 0;

	Vector2 distance, absDistance;

	// xMag and yMag represent the magnitudes of the x and y components of the normal vector.
	float xMag, yMag;

	// Calculate the difference in position of the two rectangles.
	distance = body2->position - body1->position;

	// xAdd is the combined half-widths of the two rectangles.
	// yAdd is the combined half-heights of the two rectangles.
	float xAdd = ((body1->size.x * body1->scale.x) + (body2->size.x * body2->scale.x)) / 2.0f;
	float yAdd = ((body1->size.y * body1->scale.y) + (body2->size.y * body2->scale.y)) / 2.0f;

	//printf("body1.size %f, %f\n", body1->size.x, body1->size.y);
	//   printf("body2.size %f, %f\n", body2->size.x, body2->size.y);

	// Calculate absDistance, according to distance.
	// This will actually be used to determine whether or not the two rectangles are colliding.
	(distance.x < 0) ? absDistance.x = distance.x * -1 : absDistance.x = distance.x;
	(distance.y < 0) ? absDistance.y = distance.y * -1 : absDistance.y = distance.y;

	// The two rectangles are not colliding if both of the following statements evaluate to false:
	// 1. The distance between their x position is less than their combined half-widths.
	// 2. The distance between their y position is less than their combined half-heights.
	// So return false as soon as we know there's no collision!
	if(!((absDistance.x < xAdd) && (absDistance.y < yAdd))) return false;

	// Otherwise, there is a collision:

	// The magnitude of the normal vector is determined by the overlap in the rectangles.
	xMag = xAdd - absDistance.x;
	yMag = yAdd - absDistance.y;

	// Only adjust the normal vector in the direction of the least significant overlap.
	if(xMag < yMag)
		normal.x = (distance.x > 0) ? xMag : -xMag;
	else
		normal.y = (distance.y > 0) ? yMag : -yMag;

	return true;
}
*/