#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>

class Text_input
{
    private:
    SDL_Rect rect;
    SDL_Color color;
    TTF_Font* font;
    SDL_Surface* textSurface;
    SDL_Texture* textTexture;
    std::string text;
    bool flag;
    public:
     Text_input(int, int, int, int, SDL_Color, TTF_Font*);
    ~Text_input();
    void handleEvent(SDL_Event*);

    void updateTexture();

    void render();

    void setClicked(bool);

    bool isClicked();
};
