#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
#include<iostream>

class Tile {
    private:
        SDL_Rect mRect;
        SDL_Color mColour;

        const char* mNumber;
        SDL_Rect mFontRect;
        TTF_Font* mFont;
        SDL_Texture* mTexture;

    public:
        Tile(SDL_Rect* rect, SDL_Color* colour, const char* number, TTF_Font* font, SDL_Renderer* renderer);

        void centerText();
        void move(int dx, int dy);
        void render(SDL_Renderer* renderer);
        void free();
};
