#include "tile.h"

Tile::Tile(SDL_Rect* rect, SDL_Color* colour, const char* number, TTF_Font* font, SDL_Renderer* renderer) 
    : mRect(*rect), mColour(*colour), mNumber(number), mFont(font), mFontRect({0, 0, 0, 0}),
    mTexture(nullptr) {

    // Create text texture from c string to display number
    SDL_Color fontColour = {0, 0, 0, 255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, number, fontColour);
    if (textSurface == nullptr) {
        std::cout << "Unable to render text surface! Error: " << TTF_GetError() << std::endl; 
    } else {
        mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == nullptr) {
            std::cout << "Unable to create texture form rendered text! Error: " << SDL_GetError() << std::endl;
        } else {
            mFontRect.w = textSurface->w;
            mFontRect.h = textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    }
    centerText();
}

void Tile::centerText() {
    // Center text on tile
    mFontRect.y = mRect.y + 0.5 * (mRect.h - mFontRect.h);
	mFontRect.x = mRect.x + 0.5 * (mRect.w - mFontRect.w);
}

void Tile::move(int dx, int dy) {
    mRect.x += dx;
    mRect.y += dy;
    centerText();
}

void Tile::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, mColour.r, mColour.g, mColour.b, mColour.a);
    SDL_RenderFillRect(renderer, &mRect);

    SDL_RenderCopy(renderer, mTexture, nullptr, &mFontRect);
}

void Tile::free() {
    if (mTexture != nullptr)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
}