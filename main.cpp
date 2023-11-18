#include"window2.h"
#include<SDL2/SDL_ttf.h>
int main(int argc,char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
}

if (TTF_Init() == -1) {
    std::cerr << "TTF_Init failed: " << TTF_GetError() << std::endl;
    return 1;
}

    while(true)
    {
    Window::currentWindow->Enter();
    Window::currentWindow->Update();
    
    }

    TTF_Quit();
    SDL_Quit();
    return 0;
}


// #include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>

// int main(int argc, char* argv[]) {
//     SDL_Init(SDL_INIT_VIDEO);
//     TTF_Init();

//     SDL_Window* window = SDL_CreateWindow("Welcome Text", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
//     SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

//     TTF_Font* font = TTF_OpenFont("font/SourceCodePro-Bold.ttf", 24);  // Specify your font path here
//     SDL_Color color = {255, 255, 255};  // White color

//     SDL_Surface* surface = TTF_RenderText_Solid(font, "Welcome!", color);
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

//     SDL_Rect dst;
//     dst.x = 320;
//     dst.y = 240;
//     SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);

//     SDL_RenderCopy(renderer, texture, NULL, &dst);
//     SDL_RenderPresent(renderer);

//     SDL_Delay(5000);  // Wait for 3 seconds

//     SDL_DestroyTexture(texture);
//     SDL_FreeSurface(surface);
//     TTF_CloseFont(font);
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);

//     TTF_Quit();
//     SDL_Quit();

//     return 0;
// }


