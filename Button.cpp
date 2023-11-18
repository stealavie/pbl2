#include"Button.h"

Button::Button(int x,int y,int w,int h,const char* file_location,SDL_Renderer* ren) : rect{x, y, w, h},obj(nullptr) 
{
    if(!obj)
    {
        obj=TextureManager::Texture(file_location,ren);
    }
}

bool Button::handleEvent(SDL_Event* e) 
{
        if(e->type == SDL_MOUSEBUTTONDOWN) 
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if(x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) 
            {
                return true;
            }
        }
        return false;
}

void Button::draw(SDL_Renderer* renderer) 
{
        SDL_RenderCopy(renderer,obj,NULL,&rect);
}

SDL_Texture* Button::getTex()
{
    return this->obj;
}

SDL_Rect Button::getRect()
{
    return this->rect;
}

Button::~Button()
{
    SDL_DestroyTexture(obj);
}