#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <time.h>
#include <iostream>
#include "userInterface.h"

class Stopwatch : public UserInterface {
    private:
        time_t mStartTime;
        char mElapsedTime[80];

    public:
        Stopwatch(const SDL_Rect& rect, const SDL_Color& colour, TTF_Font* const font, const SDL_Color& fontColour);

        void start();
        void calculateTime(SDL_Renderer* const renderer);
        
};