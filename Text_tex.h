#pragma once
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

class LTexture 
{
public:
    LTexture();
    ~LTexture();

    bool loadFromRenderedText(std::string textureText, SDL_Renderer* renderer);
    void free();
    void render(int x, int y,SDL_Renderer* renderer);
    int getWidth();
    int getHeight();
    

private:
    TTF_Font* font;
    SDL_Color color;
    SDL_Texture* mTexture;
    int Width;
    int Height;
};

