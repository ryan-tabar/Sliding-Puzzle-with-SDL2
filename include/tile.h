#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "button.h"

class Tile: public Button {
    private:
        int mNumber;
        
    public:
        Tile(const SDL_Rect& rect, const SDL_Color& colour, TTF_Font* const font, const SDL_Color& mFontColour, const int number);

        int getXPosition();
        int getYPosition();
        void setPositionTo(const int x, const int y);
        bool moveTo(const int x, const int y);
        int getNumber();
        
};
