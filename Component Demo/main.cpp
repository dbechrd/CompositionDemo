/*
My Awesome Component-based Engine
Date Created: 12-15-09
Author: Dan Bechard
Description: Main engine class
*/
#include <iostream>

#include "Mace.h"
#include "Entity.h"

#include "IPosition.h"
#include "IMove.h"
#include "IRotate.h"
#include "IRender.h"
#include "ICollide.h"

int main(int argc, char* args[])
{

	//Test entity
	Entity timmy;

	//Position
	timmy.AddComponent(CPOSITION);
	IPosition *pos = IPosition::GetRef(&timmy);

	if(pos != NULL) {
		pos->x = 0.2f;
		pos->scalex = 5.0f;
		pos->scalez = 10.0f;
	}

	//Rotation
	timmy.AddComponent(CROTATE);
	IRotate *rot = IRotate::GetRef(&timmy);

	if(rot != NULL) {
		rot->xRVel = 0.5f;
		rot->zRVel = 0.75f;
	}

	//Render
	timmy.AddComponent(CRENDER);
	IRender *ren = IRender::GetRef(&timmy);

	if(ren != NULL) {
		//ren->tex = OGL Texture;
	}

	if(ICollide::GetRef(&timmy) == NULL)
	{
		std::cout << "No Collision Component\n";
	}

	Mace engine;
	engine.Init();

	int frames = 0;
	while(engine.Quit() == false)
    {
		timmy.AddComponent(CCOLLIDE);
		timmy.RemoveComponent(CCOLLIDE);
		engine.HandleInput();
		engine.Update();
		frames++;
	}

    return 0;
}
