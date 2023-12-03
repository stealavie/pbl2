#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
#include<iostream>
#include<cstring>


class ComboBox
{
private:
    SDL_Rect rect;
    TTF_Font* font;
    SDL_Renderer* renderer;
    char** items;
    int numItems;
    int selected;
    int offset;
    bool isOpen;
    static const int itemHeight = 30;
public:
    ComboBox(int x, int y, int w, int h, TTF_Font* font, SDL_Renderer* renderer);
	~ComboBox();
    void addItem(const char* item);
	void handleEvent(SDL_Event* e);
    void draw();
};

