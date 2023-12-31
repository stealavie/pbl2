#pragma once
#include"Text_tex.h"

class TextBox
{
public:
    TextBox(SDL_Renderer* renderer);
    ~TextBox();

    void setPosition(int x, int y);
    void handleEvent(SDL_Event* e);
    void render();

    std::string getText() const;

private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Color color;
    SDL_Rect box;
    std::string text;
    bool isSelected;
    LTexture textTexture;

    std::string temp_text;

    void renderText();
};
