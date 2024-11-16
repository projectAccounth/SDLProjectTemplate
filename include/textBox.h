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
    textAlign xAlign;
    textAlign yAlign;

    std::vector<std::string> lines;

    int lineHeight() const;

    std::vector<std::string> splitTextIntoLines(std::string &text, int maxWidth);

public:
    SDL_Rect textBoxRect;
    SDL_Color boxColor;
    std::string text;

    SDL_Color textColor;
    textBox(SDL_Rect br, SDL_Color bc, std::string t,
            SDL_Color tc, TTF_Font* tf,
            textAlign alignX, textAlign alignY) :
        textBoxRect(br),
        boxColor(bc),
        text(t),
        textColor(tc),
        textFont(tf),
        visible(true),
        xAlign(alignX),
        yAlign(alignY) {}

    void render(SDL_Renderer* renderer);

    void update(SDL_Renderer* renderer, const char* textToUpdate);

    bool isVisible() const;

    void toggleVisibility(bool value);

    ~textBox() {}
};

#endif /* TEXTBOX_H */