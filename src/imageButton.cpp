#include "../include/button.h"
#include "../include/mainHeader.h"

void imageButton::render(SDL_Renderer* renderer) {
    if (!isVisible()) {
        return;
    }
    SDL_Texture* finalTexture = hovered ? hoverTexture : buttonTexture;

    SDL_RenderCopy(renderer, finalTexture, nullptr, &buttonRect);

    SDL_DestroyTexture(finalTexture);
}

void imageButton::setAction(std::function<void()> actionFunction) {
    buttonAction = actionFunction;
}

bool imageButton::isClicked(int x, int y) {
    return (x > buttonRect.x &&
        x < (buttonRect.x + buttonRect.w) &&
        y > buttonRect.y &&
        y < (buttonRect.y + buttonRect.h));
}
// too lazy to remove these foos
void imageButton::checkHover(int mouseX, int mouseY) {
    hovered = isClicked(mouseX, mouseY);
}

bool imageButton::isVisible() const {
    return visible;
}
void imageButton::toggleVisiblility(bool value) {
    visible = value;
}
void imageButton::handleEvents(SDL_Event& e) {
    int x, y;
    SDL_PumpEvents();
    SDL_GetMouseState(&x, &y);

    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN && active) {
        if (x > buttonRect.x && x < (buttonRect.x + buttonRect.w) &&
            y > buttonRect.y && y < (buttonRect.y + buttonRect.h)) {
            hovered = true;
        }
        else {
            hovered = false;
        }

        // If mouse is clicked while hovering
        if (e.type == SDL_MOUSEBUTTONDOWN && hovered && active) {
            if (buttonAction) {
                std::cout << "Button clicked!" << std::endl;
                buttonAction();
            }
            else {
                std::cout << "No action assigned!" << std::endl;
            }
        }
    }
}

void imageButton::toggleActive(bool value) {
    active = value;
}
