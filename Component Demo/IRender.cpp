#include "IRender.h"
#include "IPosition.h"
#include "IRotate.h"
#include "Vertex.h"
#include "BBox.h"
#include <vector>
#include <iostream>

std::map<Entity*, IRender*> IRender::collection;
std::map<Entity*, IRender*>::iterator IRender::iter;
IRender *IRender::GetRef(Entity *entity)
{
	iter = collection.find(entity);
	if(iter != collection.end())
	{
		return iter->second;
	}
	return NULL;
}

void IRender::UpdateSystem()
{
	if(collection.size() > 0)
	{
		for(iter = collection.begin(); iter != collection.end(); iter++)
		{
			iter->second->Update();
		}
	}
}

IRender::IRender(Entity *entity)
{
	parent = entity;
	collection[parent] = this;
	tex = NULL;
}

IRender::~IRender(void)
{
	iter = collection.find(parent);
	collection.erase(iter);

	if(tex != NULL) {
        glDeleteTextures(1, &tex);
    }
}

void IRender::Update()
{
	//Get parent entity's position
	IPosition *pos = IPosition::GetRef(parent);
	if(pos == NULL) {
		std::cout << "Warning: No position component found.  Entity rendered at the origin.\n";
	}else{
		glTranslatef(pos->x, pos->y, pos->z);
	}


	//Get parent entity's rotation
	IRotate *rot = IRotate::GetRef(parent);
	if(rot != NULL) {
		glRotatef(rot->xRot, 1.0f, 0.0f, 0.0f);
		glRotatef(rot->yRot, 0.0f, 1.0f, 0.0f);
		glRotatef(rot->zRot, 0.0f, 0.0f, 1.0f);
	}

	std::vector<Vertex*> *vertices = &pos->bbox->vertices;

	if(!(*vertices).empty()) {
		glBegin(GL_QUADS);
			for(std::vector<Vertex*>::iterator verticesIter = (*vertices).begin(); verticesIter != (*vertices).end(); verticesIter++) {
				glColor3f((*verticesIter)->R(), (*verticesIter)->G(), (*verticesIter)->B());
				glVertex3f((*verticesIter)->X()*pos->scalex, (*verticesIter)->Y()*pos->scaley, (*verticesIter)->Z()*pos->scalez);
			}
		glEnd();
	}

	/*
	glBegin(GL_QUADS);

		glColor3f(0.5f, 0.0f, 1.0f);
		glVertex3f(-0.5f,-0.5f, 0.0f);

		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.0f);

		glColor3f(0.5f, 0.0f, 0.5f);
		glVertex3f(0.5f, 0.5f, 0.0f);

		glColor3f(0.5f, 0.8f, 0.3f);
		glVertex3f(0.5f,-0.5f, 0.0f);

	glEnd();
	*/
}