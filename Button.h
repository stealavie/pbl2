#pragma once
#include <iostream>
#include"TextureManagement.h"
class Button {
    private:
    SDL_Rect rect;
    SDL_Texture* obj;
    public:
    Button(int, int, int, int,const char*,SDL_Renderer*);

    bool handleEvent(SDL_Event*);

    void draw(SDL_Renderer*);

    SDL_Texture* getTex();

    SDL_Rect getRect();

    ~Button();

};