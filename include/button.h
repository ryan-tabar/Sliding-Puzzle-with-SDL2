#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "userInterface.h"

// Currently empty class but still used just incase button classs requires additional functionalities
class Button : public UserInterface {
    private:

    public:
        Button(const SDL_Rect& rect, const SDL_Color& colour, TTF_Font* const font, const SDL_Color& fontColour);
        

};