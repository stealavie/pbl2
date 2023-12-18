#pragma once
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include"TextureManagement.h"
class Button
{
    SDL_Renderer* renderer;
    SDL_Texture* textTexture=NULL;
    SDL_Surface* textSurface=NULL;
    SDL_Rect rect, textRect;
    SDL_Color textColor;
    TTF_Font* font;
public:
    bool selected = false;
    bool click = false;
    Button(int, int, int, int, SDL_Renderer*,const char*);
    ~Button();
    void HandleEvent(SDL_Event*);

    void draw();
};


