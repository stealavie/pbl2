#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include<iostream>
class TextInput 
{
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Color color;
    std::string input;
    int x, y;
    bool flag;
public:

    TextInput(SDL_Renderer*, const char*,const int&, SDL_Color, int, int);
        
    ~TextInput();

    void handleEvent(SDL_Event*,SDL_Window*);

    void draw();

    std::string Get_input();

    void setFlag(bool);

    bool getFlag();
};