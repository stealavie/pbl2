#include"TextureManagement.h"
#include<iostream>
class Button
{
    public:
    static SDL_Texture* tex;
    SDL_Rect srect;
    SDL_Rect drect;
    bool selected=false;
    Button(int,int,int,int,SDL_Renderer*,const char*);
    ~Button();
    void update();
    void draw(SDL_Renderer*);
};