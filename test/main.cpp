// #include"window2.h"
// #include<SDL2/SDL_ttf.h>
// int main(int argc,char** argv)
// {
//     if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//     std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
//     return 1;
// }

// if (TTF_Init() == -1) {
//     std::cerr << "TTF_Init failed: " << TTF_GetError() << std::endl;
//     return 1;
// }

//     while(true)
//     {
//     Window::currentWindow->Enter();
//     Window::currentWindow->Update();
    
//     }

//     TTF_Quit();
//     SDL_Quit();
//     return 0;
// }


#include"Button2.h"

int main(int argc,char** argv)
{
    SDL_Window* window=nullptr;
    SDL_Renderer* renderer;
    Button* button=new Button(200,200,200,100,renderer,"Image/Button.png");
    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
    renderer=SDL_CreateRenderer(window,-1,0);
    SDL_RenderClear(renderer);
    button->draw(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    window=nullptr;
    SDL_Quit();
    return 0;
}







