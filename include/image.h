#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include "mainHeader.h"

// Placeholder class to make images easier to use

class image {
private:
	SDL_Surface* imageSurface;
	SDL_Rect imageRect;
public:
	
	bool visible;
	const char* filePath;

	image(std::string filePath, int width, int height, int locX, int locY):
		imageSurface(NULL),
		imageRect{locX, locY, width, height},
		visible(true),
		filePath(filePath.c_str())
	{}

	void render(SDL_Renderer* renderer);

	void update(std::string filePath);

	bool isVisible() const;
};

#endif /* IMAGE_H */
