#include "IPosition.h"
#include "BBox.h"

std::map<Entity*, IPosition*> IPosition::collection;
std::map<Entity*, IPosition*>::iterator IPosition::iter;
IPosition *IPosition::GetRef(Entity *entity)
{
	iter = collection.find(entity);
	if(iter != collection.end())
	{
		return iter->second;
	}
	return NULL;
}

void IPosition::UpdateSystem()
{
	if(collection.size() > 0)
	{
		for(iter = collection.begin(); iter != collection.end(); iter++)
		{
			iter->second->Update();
		}
	}
}

IPosition::IPosition(Entity *entity)
{
	parent = entity;
	collection[parent] = this;

	x = 0.0;
	y = 0.0;
	z = 0.0;

	scalex = 1.0;
	scaley = 1.0;
	scalez = 1.0;

	//bbox = new BBox(x, y, z, 0.25, 0.25, 0.25);
	bbox = new BBox(x, y, z);
}

IPosition::~IPosition()
{
	iter = collection.find(parent);
	collection.erase(iter);

	delete bbox;

	/*
    for(verticesIter = vertices.begin(); verticesIter != vertices.end(); verticesIter++) {
        delete (*verticesIter);
        (*verticesIter) = NULL;
    }
    vertices.clear();
	*/
}

/*
void IPosition::AddVertex(float nx, float ny, float nz, float nr, float ng, float nb, texCoord ntex)
{
    vertices.push_back(new Vertex(nx, ny, nz, nr, ng, nb, ntex));
}
*/

void IPosition::Update()
{

}

/*
SDL_Rect *IPosition::rect()
{
	return &rect;
}
*/