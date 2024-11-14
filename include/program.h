#pragma once

// Include guard
#ifndef PROGRAM_H
#define PROGRAM_H

#include "mainHeader.h"

class Program {
public:
	// The function responsible for creating the renderer, is called in the createWindow() function
	SDL_Renderer* createRenderer(SDL_Window* targetWindow);
	// The function responsible for initializing the program and creating the Window and the renderer
	SDL_Window* createWindow(int height, int width, bool isFullScreen, const char* title);
	// The function responsible for rendering whatever that is supposed to be rendered on the window
	void renderWindow(SDL_Renderer* renderer, SDL_Color color);
	// Called on program exit
	void onQuit(SDL_Window* window, SDL_Renderer* renderer);

	// All program controls go here
	void programControls();

	bool processEvent();
};

#endif /* PROGRAM_H */
