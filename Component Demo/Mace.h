/*
My Awesome Component-based Engine
Date Created: 12-15-09
Author: Dan
Description: Main engine class
*/
#pragma once

#include "SDL.h"

class Mace{
	private:

		//Screen attributes
		const int SCREEN_WIDTH;
		const int SCREEN_HEIGHT;
		const int SCREEN_BPP;

		//Program variables
		bool quit;
		int oldTime;
		int newTime;
		int deltaTime;

		//SDL Event
		SDL_Event event;

	public:

		Mace(int screenWidth = 640, int screenHeight = 480, int screenBPP = 32):
			SCREEN_WIDTH(screenWidth),
			SCREEN_HEIGHT(screenHeight),
			SCREEN_BPP(screenBPP),
			quit(false),
			oldTime(SDL_GetTicks()) {}
		~Mace();

		//Quit Accessor
		bool Quit();

		//Engine Initialization
		void Init();

		//Input
		void HandleInput();

		//Update
		void Update();

};
