#pragma once

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "mainHeader.h"

class textBox {
private:
    TTF_Font* textFont;
    SDL_Surface* textSurface;
    SDL_Texture* textTexture;
    bool visible;
public:

    SDL_Rect textBoxRect;
    SDL_Color boxColor;
    std::string text;

    SDL_Color textColor;
    textBox(SDL_Rect br, SDL_Color bc, std::string t, SDL_Color tc, TTF_Font* tf) :
        textBoxRect(br),
        boxColor(bc),
        text(t),
        textColor(tc),
        textFont(tf),
        visible(true) {}

    void render(SDL_Renderer* renderer);

    void update(SDL_Renderer* renderer, const char* textToUpdate);

    bool isVisible() const;

    void toggleVisibility(bool value);

    ~textBox() {}
};

#endif /* TEXTBOX_H */