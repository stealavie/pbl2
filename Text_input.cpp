#include"Text_input.h"


TextInput::TextInput(SDL_Renderer* renderer, const char* file_location,const int& size, SDL_Color color, int x, int y)
        : renderer(renderer), color(color), x(x), y(y) 
{
    std::string input="";
    SDL_StartTextInput();
    font = TTF_OpenFont(file_location, size);
    if (!font) {
        std::cerr << "TTF_OpenFont failed: " << TTF_GetError() << std::endl;
        return;
    }
    flag = false;
}


 TextInput::~TextInput() 
{
        SDL_StopTextInput();
}


 void TextInput::handleEvent(SDL_Event* e,SDL_Window* window) 
 {
    while(flag)
    {
    while(SDL_PollEvent(e))
    {
    if (e->type == SDL_TEXTINPUT||e->type==SDL_KEYDOWN) 
    {
        system("cls");
        if(e->type==SDL_KEYDOWN&&e->key.keysym.sym==SDLK_BACKSPACE&&input.length()>0)
        {
            input=input.substr(0,input.length()-1);
        }
        else if(e->type==SDL_TEXTINPUT)
        input += e->text.text;
        std::cout<<input<<std::endl;
    }
    else if(e->type==SDL_MOUSEBUTTONDOWN)
        flag=false;
    }
    SDL_UpdateWindowSurface(window);
    }
}

void TextInput::draw() 
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, input.c_str(), color);
    if (!surface) {
        std::cerr << "TTF_RenderText_Solid failed: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    if (SDL_RenderCopy(renderer, texture, NULL, &dest) != 0) {
        std::cerr << "SDL_RenderCopy failed: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}


std::string TextInput::Get_input()
{
    return this->input;
}

void TextInput::setFlag(bool flag) 
{
    this->flag=flag;
}

bool TextInput::getFlag()
{
    return this->flag;
}