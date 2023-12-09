#pragma once
#include"TextureManagement.h"
class IMG_Tex
{
	SDL_Rect Rect;
	SDL_Texture* IMG=NULL;
public:
	IMG_Tex(SDL_Renderer* renderer, const char* file, int x, int y, int w, int h);
	~IMG_Tex();
	virtual void draw(SDL_Renderer* renderer);
	SDL_Rect getRect() const;
	void setPosition(int x, int y);
};

