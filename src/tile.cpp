#include "tile.h"

Tile::Tile(const SDL_Rect& rect, const SDL_Color& colour, const int number, TTF_Font* const font, SDL_Renderer* const renderer) 
    : mRect(rect), mColour(colour), mNumber(number), mFontRect({0, 0, 0, 0}), mTexture(nullptr) {
    
    // Convert number to c style string
    const char* numberStr = std::to_string(number).c_str();

    // Create text texture from c string to display number
    SDL_Color fontColour = {0, 0, 0, 255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, numberStr, fontColour);
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

int Tile::getXPosition(){
    return mRect.x;
}

int Tile::getYPosition() {
    return mRect.y;
}

void Tile::centerText() {
    // Center text on tile
    mFontRect.y = mRect.y + 0.5 * (mRect.h - mFontRect.h);
	mFontRect.x = mRect.x + 0.5 * (mRect.w - mFontRect.w);
}                                                                                                                                                                                                                                                                            

bool Tile::moveTo(const int x, const int y) {
    int delta;

    if (mRect.x != x) {
        delta = (x - mRect.x > 0) ? 1 : -1;
        mRect.x += delta;
        mFontRect.x += delta;
        return false;
    } 

    if (mRect.y != y) {
        delta = (y - mRect.y > 0) ? 1 : -1;
        mRect.y += delta;
        mFontRect.y += delta;
        return false;
    }

    // Else return true as it has moved to the target position
    return true;
}

void Tile::setPositionTo(const int x, const int y) {
    mRect.x = x;
    mRect.y = y;

    centerText();
}

bool Tile::isMouseInside(const int x, const int y) const {
    // Assume mouse is inside tile
    bool inside = true;

   	// Mouse is left of the button
	if (x < mRect.x)
	{
		inside = false;
	}
	// Mouse is right of the button
	else if (x > mRect.x + mRect.w)
	{
		inside = false;
	}
	// Mouse above the button
	else if (y < mRect.y)
	{
		inside = false;
	}
	// Mouse below the button
	else if (y > mRect.y + mRect.h)
	{
		inside = false;
	}

    return inside;
}

int Tile::getNumber() {
    return mNumber;
}

void Tile::render(SDL_Renderer* const renderer) const {
    // Render tile
    SDL_SetRenderDrawColor(renderer, mColour.r, mColour.g, mColour.b, mColour.a);
    SDL_RenderFillRect(renderer, &mRect);

    // Render font
    SDL_RenderCopy(renderer, mTexture, nullptr, &mFontRect);
}

void Tile::free() {
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
}