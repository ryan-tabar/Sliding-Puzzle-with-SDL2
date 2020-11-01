#include <SDL.h>
#include <SDL_ttf.h>
#include <time.h>

class Stopwatch {
    private:
        SDL_Rect mRect;
        SDL_Color mColour;

        SDL_Rect mFontRect;
        SDL_Texture* mTexture;
    public:
        Stopwatch();

        void calculateTime();
        void loadTexture();
        
}