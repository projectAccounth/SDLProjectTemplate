#pragma once

// Include guard
#ifndef PROGRAM_H
#define PROGRAM_H

#include "mainHeader.h"

class Program {
public:
	// Creates the renderer
	SDL_Renderer* createRenderer(SDL_Window* targetWindow);

	// The function responsible for initializing the program and creating the window
	SDL_Window* createWindow(int height, int width, bool isFullScreen, const char* title);

	// Called on program exit
	void onQuit(SDL_Window* window, SDL_Renderer* renderer);

	// All program controls go here
	void programControls();

	bool processEvent();
};

#endif /* PROGRAM_H */
