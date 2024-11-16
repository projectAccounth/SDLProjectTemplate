// C++ SDL2 Template for Visual Studio 2022

#include "../include/mainHeader.h"
#include "../include/button.h"
#include "../include/textBox.h"
#include "../include/buttonManager.h"

// initialization
SDL_Window* mainWindow = NULL;
SDL_Renderer* mainRenderer = NULL;

// window's color, change please
SDL_Color windowColor = {255, 255, 255 ,255};

int main(int argc, char* argv[]) {

	Program program;

	// Initialize the program
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	/*
		Things like font creation go here
	*/

	// Creating a 640x480 window (at least with the default template setting)
	mainWindow = program.createWindow(WINDOW_HEIGHT, WINDOW_WIDTH, 0, "Program");

	mainRenderer = program.createRenderer(mainWindow);
	
	// The boolean that indicates whether the program is running or not
	bool isRunning = true;

	while (isRunning) {
		// processEvent() is a boolean function which will return the value
		// of isRunning indicating whether the program is running or not
		isRunning = program.processEvent();

		// Set a color for the renderer
		SDL_SetRenderDrawColor(mainRenderer, windowColor.r, windowColor.g, windowColor.b, windowColor.a);
		// Clear the renderer
		SDL_RenderClear(mainRenderer);

		// Things that need to be rendered go here

		// Make the renderer present
		SDL_RenderPresent(mainRenderer);
	}
	// This function is called on program exit
	program.onQuit(mainWindow, mainRenderer);

	return 0;
}