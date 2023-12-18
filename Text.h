#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<string>

class Text
{
	int x,y, w, h;
	SDL_Renderer* renderer;
	TTF_Font* font;
	std::string text;
	int scrollPosition = 0;
	bool isClickScrollBar = false;
	int Text_area_w, Text_area_h;
	int Scroll_speed = 20;
	int Scroll_width;
public:
	Text(SDL_Renderer* renderer, TTF_Font* font, const std::string& text,
		int x,int y,int w,int h,int Text_area_w,int Text_area_h,int Scroll_width);
	~Text();
	void RenderTextWithScrolling(const std::string& text, int maxWidth, int maxHeight, int yoff);
	void RenderScrollBar(int totalHeight);
	void HandleEvent(SDL_Event* e);
	void draw();
};

