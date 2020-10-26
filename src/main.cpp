//Using SDL and standard IO
#include<SDL.h>
#include<SDL_ttf.h>
#include<iostream>
#include "tile.h"

int main( int argc, char* args[] ) {
    // Screen dimensions
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGHT = 600;

    // Initialise SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL could not initialise! Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Intialise SDL_ttf
    if (TTF_Init() == -1) {
        std::cout << "SDL_ttf could not initialise! Error: " << TTF_GetError() << std::endl;
        return -1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Checkers", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL could not create window! Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        std::cout << "SDL could not create renderer! Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Load font for text
    const int fontSize = 30;
    TTF_Font* font = TTF_OpenFont("assets/octin sports free.ttf", fontSize);
    if (font == nullptr) {
        std::cout << "Failed to load font! Error: " << TTF_GetError() << std::endl;
        return -1;
    }

    // Testing
    SDL_Rect rect = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 50, 50};
    SDL_Color colour = {255, 123, 43, 255};
    Tile tile(&rect, &colour, "10", font, renderer);

    // Game loop variables
    bool stop = false;
    SDL_Event event;

    // Game loop
    while (!stop) {
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            // Handle quiting
            if (event.type == SDL_QUIT) {
                stop = true;
            }
        }

        // update
        tile.move(1, 1);

        // render
        // for each tile, 
            // if it needs to be re-rendered 
                // render it

        // Test render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        tile.render(renderer);

        // Update screen from backbuffer and clear backbuffer
        SDL_RenderPresent(renderer);
        
        // Slow down program
        SDL_Delay(20);

    }

    // Free textures
    tile.free();

    // Destroy renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;

    // Free font
    TTF_CloseFont(font);
    font = nullptr;

    // Quit SDL
    SDL_Quit();

    // Exit program
    std::cout << "Exiting program..." << std::endl;
    return 0;
}   