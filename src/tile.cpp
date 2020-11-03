#include "tile.h"

Tile::Tile(const SDL_Rect& rect, const SDL_Color& colour, TTF_Font* const font, const SDL_Color& fontColour, const int number) 
    : UserInterface(rect, colour, font, fontColour),
      mNumber(number) {
    
}

int Tile::getXPosition() {
    return mRect.x;
}

int Tile::getYPosition() {
    return mRect.y;
}                                                                                                                                                                                                                                                                      

bool Tile::moveTo(const int x, const int y) {
    // Move tile to target x and y position by delta amount (+1 or -1)
    // Keep moving until tile is on target
    if (mRect.x != x) {
        const int delta = (x - mRect.x > 0) ? 1 : -1;
        mRect.x += delta;
        mFontRect.x += delta;
        return false;
    } 

    if (mRect.y != y) {
        const int delta = (y - mRect.y > 0) ? 1 : -1;
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

int Tile::getNumber() {
    return mNumber;
}
