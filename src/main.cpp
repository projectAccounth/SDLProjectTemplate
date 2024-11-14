// C++ SDL2 Template for Visual Studio 2022

#include "../include/mainHeader.h"

// Declaration and assignment of the main window
// and the main renderer
SDL_Window* mainWindow = NULL;
SDL_Renderer* mainRenderer = NULL;

// This will be the main color of the window
SDL_Color windowColor = {255, 255, 255 ,255};


// The main function, the entry point function of the program
int main(int argc, char* argv[]) {

	Program program;

	// Initialize the program
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	// This will create a window with a title of "Program",
	// with a size of WINDOW_WIDTH and
	// WINDOW_HEIGHT, which can be later edited in mainHeader.h
	mainWindow = program.createWindow(WINDOW_HEIGHT, WINDOW_WIDTH, 0, "Program");

	mainRenderer = program.createRenderer(mainWindow);
	
	// The boolean that indicates whether the program is running or not
	bool isRunning = true;

	while (isRunning) {
		// processEvent() is a boolean function which will return the value
		// of isRunning indicating whether the program is running or not
		isRunning = program.processEvent();
		// This is the function which is responsible for
		// rendering the objects on window
		program.renderWindow(mainRenderer, windowColor);
	}
	// This function is called on program exit
	program.onQuit(mainWindow, mainRenderer);

	return 0;
}