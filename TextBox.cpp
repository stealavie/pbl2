#include "TextBox.h"


TextBox::TextBox(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    font = TTF_OpenFont("C:/Users/USER/Desktop/pbl2/SourceCodePro-Bold.ttf", 24);
    if (font == NULL)
    {
        std::cout << "Error:" << TTF_GetError() << std::endl;
    }
    this->color = { 0,0,0,255 };
    box = { 0, 0, 200, 30 };
    isSelected = false;
    text = "";
    textTexture = LTexture();
}

TextBox::~TextBox()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    textTexture.free();
}

void TextBox::setPosition(int x, int y)
{
    box.x = x;
    box.y = y;
}

void TextBox::handleEvent(SDL_Event* e)
{
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if (mouseX >= box.x && mouseX <= box.x + box.w &&
            mouseY >= box.y && mouseY <= box.y + box.h)
        {
            isSelected = true;
        }
        else
        {
            isSelected = false;
        }
    }
    else if (e->type == SDL_KEYDOWN && isSelected)
    {
        if (e->key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
        {
            text.pop_back();
        }
        else if (e->key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
        {
            SDL_SetClipboardText(text.c_str());
        }
        else if (e->key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
        {
            char* tempText = SDL_GetClipboardText();
            text = tempText;
            SDL_free(tempText);
        }

        // Thêm điều kiện chờ để tránh xử lý sự kiện nhiều lần
        SDL_Delay(150);
    }
    else if (e->type == SDL_TEXTINPUT && isSelected)
    {
        if (box.w > 0)
        {
            if (textTexture.loadFromRenderedText(text,renderer))
            {
                if (textTexture.getWidth() >= box.w - 10)
                {
                    text = text.substr(1);
                }

                text += e->text.text;
                temp_text = text;
            }
            else
            {
                // Handle error loading text texture
                std::cerr << "Failed to load text texture!\n";
            }
        }
    }
}

void TextBox::renderText()
{
    if (text != "")
    {
        SDL_Color textColor = { 0, 0, 0, 0xFF };
        textTexture.loadFromRenderedText(text,renderer);
        textTexture.render(box.x + 5, box.y,renderer);
    }

}

void TextBox::render()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &box);
    renderText();
    if (isSelected)
    {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderDrawRect(renderer, &box);
    }
}

std::string TextBox::getText() const
{
    return this->temp_text;
}



