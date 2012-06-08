#include "Mace.h"

#include "IPosition.h"
#include "IRotate.h"
#include "IMove.h"
#include "IRender.h"
#include "ICollide.h"

Mace::~Mace()
{
	SDL_Quit();
}

bool Mace::Quit()
{
	return quit;
}

void Mace::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WM_SetCaption("OpenGL Component System", NULL);
	SDL_EnableKeyRepeat(1, 100);

	//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_OPENGL);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Wireframe?
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT, GL_POINT);

	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing

	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);				// Really Nice Point Smoothing

	//glDisable(GL_DEPTH_TEST);

	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	//glDisable(GL_BLEND);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.25f);

	//Setup OGL Textures
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Mace::HandleInput()
{
	//Handle Input
    int mousex, mousey;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_SPACE:

                    break;
                case SDLK_UP:
                    
                    break;
                case SDLK_DOWN:
                    
                    break;
                case SDLK_LEFT:
                    
                    break;
                case SDLK_RIGHT:
                    
                    break;
                case SDLK_ESCAPE:
                    //Quit the program
                    quit = true;
                    break;
                default:
                    break;
            }
        } else if(event.type == SDL_KEYUP) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    
                    break;
                case SDLK_DOWN:
                    
                    break;
                case SDLK_LEFT:
                    
                    break;
                case SDLK_RIGHT:
                    
                    break;
				default:
					break;
            }
        }
        if(event.type == SDL_MOUSEMOTION) {
            SDL_GetMouseState(&mousex, &mousey);
		}
        if(event.type == SDL_MOUSEBUTTONDOWN) {
            //Left mouse button was pressed
            if(event.button.button == SDL_BUTTON_LEFT) {
                //Get the mouse offsets
                mousex = event.button.x;
                mousey = event.button.y;
            }
        }
        if(event.type == SDL_MOUSEBUTTONUP) {
            //Left mouse button was released
            if(event.button.button == SDL_BUTTON_LEFT) {

            }
        }
        if(event.type == SDL_QUIT) {
            //Quit the program
            quit = true;
        }
    }
}

void Mace::Update()
{
	//Reset OpenGL
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//Update component systems
	IRotate::UpdateSystem();
	IMove::UpdateSystem();
	ICollide::UpdateSystem();
	IRender::UpdateSystem();

	//Update the screen
	glFlush();
	SDL_GL_SwapBuffers();

    //Get Current Time and Change in Time
    newTime = SDL_GetTicks();
    deltaTime = newTime - oldTime;

    //Limit frame rate
    if(deltaTime < 1000 / 30) {
        SDL_Delay((1000 / 30) - deltaTime);
    }

    //Update old time variable for next frame
    oldTime = newTime;
}