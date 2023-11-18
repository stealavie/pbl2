#include"TextureManagement.h"

SDL_Texture* TextureManager::Texture(const char* file_location,SDL_Renderer* ren)
{
    SDL_Surface* surface;
    surface=IMG_Load(file_location);
    SDL_Texture* tex;
    tex= SDL_CreateTextureFromSurface(ren,surface);
    return tex;
}

