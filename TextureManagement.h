#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
class TextureManager
{
    public:
    static SDL_Texture* Texture(const char*,SDL_Renderer*);
};