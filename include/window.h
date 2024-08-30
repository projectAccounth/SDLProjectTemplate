#pragma once

// Include guard
#ifndef WINDOW_H
#define WINDOW_H

#include "mainHeader.h"

// The function responsible for creating the renderer, is called in the createWindow() function
SDL_Renderer* createRenderer(SDL_Window *targetWindow);
// The function responsible for initializing the program and creating the Window and the renderer
void createWindow(int height, int width, bool isFullScreen, const char* title, SDL_Window* targetWindow, SDL_Renderer* targetRenderer);
// The function responsible for rendering whatever that is supposed to be rendered on the window
void renderWindow(SDL_Renderer* renderer, Color3 color);
// Called on program exit
void onQuit(SDL_Window* window, SDL_Renderer* renderer);

#endif /* WINDOW_H */
