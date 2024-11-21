// C++ SDL2 Template for Visual Studio 2022

#include "../include/mainHeader.h"
#include "../include/button.h"
#include "../include/textBox.h"
#include "../include/buttonManager.h"
#include "../include/program.h"

SDL_Window* mainWindow = NULL;
SDL_Renderer* mainRenderer = NULL;

// window's color, change please
SDL_Color windowColor = {255, 255, 255 ,255};

int main(int argc, char* argv[]) {

	Program program;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	/*
		Things like font creation go here
	*/

	// Creating a 640x480 window (at least with the default template setting)
	mainWindow = program.createWindow(WINDOW_HEIGHT, WINDOW_WIDTH, 0, "Program");

	mainRenderer = program.createRenderer(mainWindow);

	bool isRunning = true;

	while (isRunning) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			isRunning = program.processEvent(e);

			// button events, etc. go here

		}
		
		SDL_SetRenderDrawColor(mainRenderer, windowColor.r, windowColor.g, windowColor.b, windowColor.a);
		SDL_RenderClear(mainRenderer);

		// Things that need to be rendered go here

		SDL_RenderPresent(mainRenderer);
	}
	program.onQuit(mainWindow, mainRenderer);

	return 0;
}