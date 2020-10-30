#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

class Tile {
    private:
        int mNumber;

        SDL_Rect mRect;
        SDL_Color mColour;

        SDL_Rect mFontRect;
        SDL_Texture* mTexture;

        void centerText();
    public:
        Tile(const SDL_Rect& rect, const SDL_Color& colour, const int number, TTF_Font* const font, SDL_Renderer* const renderer);

        int getXPosition();
        int getYPosition();
        void setPositionTo(const int x, const int y);
        bool moveTo(const int x, const int y);
        bool isMouseInside(const int x, const int y) const;
        int getNumber();
        void render(SDL_Renderer* const renderer) const;
        void free();
};
