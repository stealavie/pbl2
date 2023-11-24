#include"Text_input2.h"

Text_input::Text_input(int x, int y, int w, int h, SDL_Color color, TTF_Font* font)
        : rect{x, y, w, h}, color{color}, font{font}, textSurface{nullptr}, textTexture{nullptr}, text{""} 
{}

 Text_input::~Text_input() 
 {
        if (textSurface) 
        {
            SDL_FreeSurface(textSurface);
        }
        if (textTexture) 
        {
            SDL_DestroyTexture(textTexture);
        }
}

void Text_input::handleEvent(SDL_Event* e) 
{
    if (e->type == SDL_TEXTINPUT) 
    {
        text += e->text.text;
        updateTexture();
    }
    else if(e->type==SDL_KEYDOWN&&e->key.keysym.sym==SDLK_BACKSPACE&&text.length()>0)
    {
        text=text.substr(0,text.length()-1);
    }
}


void Text_input::updateTexture() 
{
    if (textSurface) 
    {
        SDL_FreeSurface(textSurface);
    }
    if (textTexture) 
    {
        SDL_DestroyTexture(textTexture);
    }
    textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    textTexture = SDL_CreateTextureFromSurface(SDL_GetRenderer(SDL_GetWindowFromID(1)), textSurface);
}

void Text_input::render() 
{
    SDL_RenderCopy(SDL_GetRenderer(SDL_GetWindowFromID(1)), textTexture, NULL, &rect);
}


void Text_input::setClicked(bool flag)
{
    this->flag=flag;
}

bool Text_input::isClicked()
{
    return this->flag;
}
