#include "Text_tex.h"


LTexture::LTexture()
{
    
    font = TTF_OpenFont("D:/SourceCodePro-Bold.ttf", 24);
        if (font == NULL)
        {
            std::cout << "Error:" << TTF_GetError() << std::endl;
        }
       this-> color={ 0,0,0,255};
    mTexture = NULL;
    this->Width = 0;
    this->Height = 0;
}

LTexture::~LTexture()
{
    free();
}

int LTexture::getHeight()
{
    return this->Height;
}

int LTexture::getWidth()
{
    return this->Width;
}


void LTexture::free()
{
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        
    }
}

void LTexture::render(int x, int y,SDL_Renderer* renderer)
{
    SDL_Rect renderQuad = { x, y, getWidth(), getHeight()};
    SDL_RenderCopy(renderer, mTexture,NULL, &renderQuad);
}



#if defined(SDL_TTF_MAJOR_VERSION)
bool LTexture::loadFromRenderedText(std::string textureText,SDL_Renderer* renderer)
{
    //Get rid of preexisting texture
    free();
    if (!textureText.empty())
    {
        //Render text surface
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), color);
        if (textSurface != NULL)
        {
            //Create texture from surface pixels
            mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if (mTexture == NULL)
            {
                std::cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
            }
            else
            {
                Width = textSurface->w;
                Height = textSurface->h;
            }

            //Get rid of old surface
            SDL_FreeSurface(textSurface);
        }
        else
        {
            std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        }
    }


    //Return success
    return true;
}
#endif
