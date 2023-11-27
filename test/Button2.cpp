#include"Button2.h"

SDL_Texture* Button::tex=NULL;

Button::Button(int x,int y,int w,int h,SDL_Renderer* ren,const char* file_location)
{
    if(!tex)
    {
        tex=TextureManager::Texture(file_location,ren);
    }
    drect.x=x;
    drect.y=y;
    drect.w=w;
    drect.h=h;
    srect.x=x;
    srect.y=y;
}

Button::~Button()
{
    SDL_DestroyTexture(tex);
}

void Button::update()
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect mouse;
    mouse.x=x;
    mouse.y=y;
    mouse.w=mouse.h=1;
    if(SDL_HasIntersection(&mouse,&drect))
    {
        this->selected=true;
        srect.x=0;
    }else
    {
        this->selected=false;
    }
}

void Button::draw(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren,tex,NULL,&drect);
}
