#pragma once

// Include guard
#ifndef MAIN_HDR_H
#define MAIN_HDR_H

// These are the window width and height, can be changed
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// Includes for the program

#include <SDL.h>

#include <SDL_image.h>

#include <SDL_ttf.h>

#include <iostream>

// Include all files in order not to pollute the source files with includes

#include "Color3.h"

#include "handler.h"

#include "window.h"

// External symbol for mainWindow and mainRenderer
// in case you need to call it outside main.cpp
extern SDL_Window* mainWindow;
extern SDL_Renderer* mainRenderer;

#endif /* MAIN_HDR_H */
