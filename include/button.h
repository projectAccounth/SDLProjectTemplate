#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include "mainHeader.h"

enum textAlign {
    LEFT,
    CENTER,
    RIGHT
};

class textButton {
private:

public:
    // dimension, size, position and initial RGB color for the button
    SDL_Rect buttonRect;
    SDL_Color buttonColor;

    SDL_Color textColor; // color for textButton
    SDL_Texture* textTexture;
    SDL_Color hoverColor; // color for hovering

    TTF_Font* textFont; // font for the text in the textButton
    const char* text; // text for the textButton

    textAlign TextAlign;

    bool hovered;
    bool visible, active;
    std::function<void()> buttonAction;

    textButton(int x, int y, int w, int h,
        SDL_Color c, const char* t,
        SDL_Color tc, TTF_Font* f,
        textAlign align, SDL_Color hc)
        : buttonRect{ x, y, w, h },
        buttonColor(c),
        textColor(tc),
        textFont(f),
        text(t),
        TextAlign(align),
        textTexture(nullptr),
        hovered(false),
        hoverColor(hc),
        visible(true),
        active(true) {}
    /* you don't have to care much about these, this is just the constructor for the class */

    void loadText(SDL_Renderer* renderer);

    void render(SDL_Renderer* renderer);

    void setAction(std::function<void()> actionFunction);

    bool isClicked(int x, int y);

    void checkHover(int mouseX, int mouseY);

    bool isVisible() const;

    void toggleVisiblility(bool value);

    void handleEvents(SDL_Event& event);

    void toggleActive(bool value);

    // destructor for the class
    ~textButton() {}
};

class imageButton {
private:

public:
    // dimension, size, position and initial RGB color for the button
    SDL_Rect buttonRect;
       
    SDL_Texture* buttonTexture;
    SDL_Texture* hoverTexture; // texture for hovering, set hoverTexture to buttonTexture if you don't want hover.

    bool hovered;
    bool visible, active;
    std::function<void()> buttonAction;

    imageButton(int x, int y, int w, int h, SDL_Texture *is, SDL_Texture* ht)
        : buttonRect{ x, y, w, h },
        hovered(false),
        hoverTexture(ht),
        visible(true),
        active(true) {}
    /* you don't have to care much about these, this is just the constructor for the class */

    void render(SDL_Renderer* renderer);

    void setAction(std::function<void()> actionFunction);

    bool isClicked(int x, int y);

    void checkHover(int mouseX, int mouseY);

    bool isVisible() const;

    void toggleVisiblility(bool value);

    void handleEvents(SDL_Event& event);

    void toggleActive(bool value);

    // destructor for the class
    ~imageButton() {}
};


#endif /* BUTTON_H */

