#include "../include/image.h"

void image::render(SDL_Renderer* renderer) {
	if (!isVisible()) return;

	imageSurface = IMG_Load(filePath);
	if (imageSurface == nullptr) {
		std::cout << "A problem occurred when trying to create image. Error: " << SDL_GetError() << '\n';
		return;
	}
	
	SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);

	SDL_RenderCopy(renderer, imageTexture, NULL, &imageRect);

	SDL_FreeSurface(imageSurface);

	SDL_DestroyTexture(imageTexture);
}

void image::update(std::string str) {
	filePath = str.c_str();
}

bool image::isVisible() const { return visible; }