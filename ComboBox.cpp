#define _CRT_SECURE_NO_WARNINGS

#include "ComboBox.h"
// #include <stdio.h>
// #include <string.h>
#include <cstring>
// #include <string>


ComboBox::ComboBox(int x, int y, int w, int h, TTF_Font* font, SDL_Renderer* renderer)
    : rect{ x, y, w, h }, font(font), renderer(renderer), numItems(0), selected(-1), offset(0), isOpen(false) 
{
    items = new char* [100];
    for (int i = 0; i <100; ++i)
    {
        items[i] = nullptr;
    }
}

ComboBox::~ComboBox()
{
    for (int i = 0; i < numItems; ++i) 
    {
        delete[] items[i];
    }
    delete[] items;
}

void ComboBox::addItem(const char* item) 
{
    if (numItems < 100) 
    {
        items[numItems] = new char[strlen(item) + 1];
        // strcpy_s(items[numItems], strlen(item) + 1, item);
        strcpy(items[numItems], item);
        ++numItems;
    }
}

void ComboBox::handleEvent(SDL_Event* e) 
{
    if (e->type == SDL_MOUSEBUTTONDOWN) 
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + (isOpen ? rect.h : itemHeight)) 
        {
            if (isOpen) 
            {
                selected = (y - rect.y) / itemHeight + offset;
                if (selected >= numItems) 
                {
                    selected = -1;
                }
            }
            isOpen = !isOpen;
        }
    }
    else if (e->type == SDL_MOUSEWHEEL && isOpen)
    {
        offset -= e->wheel.y;
        if (offset < 0) 
        {
            offset = 0;
        }
        else if (offset > numItems - rect.h / itemHeight) 
        {
            offset = numItems - rect.h / itemHeight;
        }
    }
}


void ComboBox::draw(int r, int g,int b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect renderRect = { rect.x, rect.y, rect.w, isOpen ? rect.h : itemHeight };
    SDL_RenderFillRect(renderer, &renderRect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &renderRect);

    SDL_Color textColor = { 0, 0, 0, 255 };
    if (isOpen) 
    {
        for (int i = offset; i < numItems && i < offset + rect.h / itemHeight; ++i) 
        {
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, items[i], textColor);
            if (textSurface == NULL)
            {
                std::cout << "error:" << TTF_GetError() << std::endl;
                return;
            }
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_Rect renderQuad = { rect.x, rect.y + (i - offset) * itemHeight, textSurface->w, textSurface->h };
            SDL_RenderCopy(renderer, textTexture, NULL, &renderQuad);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
        }
    }
    else if (selected != -1) 
    {
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, items[selected], textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect renderQuad = { rect.x, rect.y, textSurface->w, textSurface->h };
        SDL_RenderCopy(renderer, textTexture, NULL, &renderQuad);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
}

