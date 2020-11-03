#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "userInterface.h"

class Button : public UserInterface {
    private:

    public:
        Button(const SDL_Rect& rect, const SDL_Color& colour, TTF_Font* const font, const SDL_Color& fontColour);


};