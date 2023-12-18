#include "IMG_Tex.h"

IMG_Tex::IMG_Tex(SDL_Renderer* renderer, const char* file, int x, int y, int w, int h)
{
	Rect.x = x;
	Rect.y = y;
	Rect.w = w;
	Rect.h = h;
	IMG = TextureManager::Texture(file, renderer);
}

IMG_Tex::~IMG_Tex()
{
	SDL_DestroyTexture(IMG);
}

void IMG_Tex::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, IMG, NULL, &Rect);
}


SDL_Rect IMG_Tex::getRect() const
{
	return Rect;
}

void IMG_Tex::setPosition(int x, int y) 
{
	Rect.x = x;
	Rect.y = y;
}
