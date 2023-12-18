#include"Button.h"


Button::Button(int x, int y, int w, int h, SDL_Renderer* ren, const char* Text):renderer(ren)
{
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    textColor = { 0,0,0 };
    font = TTF_OpenFont("C:/Users/USER/Desktop/pbl2/SourceCodePro-Bold.ttf", 24);
    if (!font)
    {
        std::cout << "cant open file" << TTF_GetError() << std::endl;
    }
    textSurface = TTF_RenderText_Solid(font, Text, textColor);
    if (!textSurface)
    {
        std::cout << "cant open surface" << TTF_GetError() << std::endl;
    }
    textTexture = SDL_CreateTextureFromSurface(ren, textSurface);
    int t_w = textSurface->w;
    int t_h = textSurface->h;
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = w;
    this->rect.h = h;

    this->textRect.x = rect.x;
    this->textRect.y = rect.y ;
    this->textRect.w = t_w;
    this->textRect.h = t_h;
}

Button::~Button()
{
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
}

void Button::HandleEvent(SDL_Event* e)
{

    int x, y;
    SDL_GetMouseState(&x, &y);

            if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
            {
                this->selected = true;
                if (e->type == SDL_MOUSEBUTTONDOWN)
                {
                    if (e->button.button == SDL_BUTTON_LEFT)
                    {
                        click = true;
                        std::cout << "clicked~<" << std::endl;
                    }
                }
            }
            else
            {
                this->selected = false;
                click = false;
            }
    
}

void Button::draw()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
    if (selected)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

}








