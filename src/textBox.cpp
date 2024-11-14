#include "../include/textBox.h"

void textBox::render(SDL_Renderer* renderer) {
    if (!isVisible()) {
        return;
    }
    // Checking whether the text is empty or not to prevent problematic stuff

    SDL_SetRenderDrawColor(renderer, boxColor.r, boxColor.g, boxColor.b, boxColor.a);

    SDL_RenderFillRect(renderer, &textBoxRect);

    if (text.empty()) {
        return;
    }
    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    textSurface = TTF_RenderText_Blended(textFont, text.c_str(), textColor);

    if (textSurface == nullptr) {
        std::cout << "Text surface is NULL" << "\n";
        return;
    }

    // now you can convert it into a texture
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    if (textTexture == nullptr) {
        std::cout << "Text is NULL" << "\n";
        return;
    }

    SDL_Rect* textRect = nullptr;

    textRect->x = textBoxRect.x;
    textRect->y = textBoxRect.y + (textBoxRect.h / 2) - textSurface->h / 2;
    textRect->w = textSurface->w;
    textRect->h = textSurface->h;

    SDL_RenderCopy(renderer, textTexture, NULL, textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void textBox::update(SDL_Renderer* renderer, const char* textToUpdate) {
    text = textToUpdate;
    render(renderer);
}

bool textBox::isVisible() const {
    return visible;
}

void textBox::toggleVisibility(bool value) {
    visible = value;
}