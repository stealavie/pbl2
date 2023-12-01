#include"window2.h"

SDL_Window* Window::window=SDL_CreateWindow("PBL2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,0);
SDL_Renderer* Window::renderer=SDL_CreateRenderer(window,-1,0);

Window* Window::mainWindow=new MainWindow;
Window* Window::loginWindow=new LoginWindow;
Window* Window::currentWindow= mainWindow; 
Window* Window::projectWindow=new ProjectWindow;
TTF_Font* Window::font=TTF_OpenFont("font/SourceCodePro-Bold.ttf",16);
SDL_Color Window::color={0,0,0};


Window::Window()
{
}

Window::~Window()
{
}

void MainWindow::Enter()
{
   running=true;
}

void MainWindow::Update()
{
    while(running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                {
                shutdown();

                }
                case SDL_MOUSEBUTTONDOWN:
                {         
                
                if(this->Login_button->handleEvent(&event)) 
                    {
                        std::cout<<"clicked"<<std::endl;
                        currentWindow=loginWindow; 
                        running=false;
                    }
                else if(this->Explore_button->handleEvent(&event))
                    {
                        std::cout<<"clicked"<<std::endl;  
                        currentWindow=projectWindow; 
                        running=false;
                    }
                    break;
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,background,NULL,NULL);
        Explore_button->draw(renderer);
        Login_button->draw(renderer);
        // Explore_button->draw(renderer);
        SDL_RenderPresent(renderer);
    }
}

void MainWindow::Exit()
{
   

}

void Window::shutdown()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

MainWindow::MainWindow()
{
    background=TextureManager::Texture("Image/MainTheme.png",renderer);
    Login_button=new Button(1100,50,100,43,"Image/Button2.png",renderer);
    Explore_button=new Button(70,50,127,43,"Image/Button3.png",renderer);
    
}

MainWindow::~MainWindow()
{
    SDL_DestroyTexture(background);

}

LoginWindow::LoginWindow()
{
    obj=new Trie();
    background=TextureManager::Texture("Image/LoginWindow.png",renderer);
    Return_button=new Button(70,50,133,43,"Image/menu_login.png",renderer);
    Username=new Button(300,350,200,50,"Image/Username.png",renderer);
    Password=new Button(300,400,200,50,"Image/Password.png",renderer);
    Login=new Button(615,470,100,50,"Image/Login_button.png",renderer);
    Username_input = new Text_input(410, 580, 100, 50, color, font);
    Password_input = new Text_input(410, 640, 100, 50, color, font);
}

LoginWindow::~LoginWindow()
{
    SDL_DestroyTexture(background);

}

void LoginWindow::Enter()
{
    running=true;
}

// void LoginWindow::Update()
// {
//     this->obj->Load_data();
//     bool login_flag=false;
//     bool pass_flag=false;
//     while(running)
//     {
//         SDL_Event event;
//         while(SDL_PollEvent(&event))
//         {
//             switch(event.type)
//             {
//                 case SDL_QUIT:
//                 {
//                 shutdown();

//                 }
//                 case SDL_MOUSEBUTTONDOWN:
//                 {         
                
//                 if(this->Return_button->handleEvent(&event)) 
//                     {
//                         std::cout<<"clicked"<<std::endl;
//                         currentWindow=mainWindow; 
//                         running=false;
//                     }
//                 else if(this->Username->handleEvent(&event))
//                     {
//                         std::cout<<"clicked"<<std::endl;
//                         SDL_StartTextInput();
//                     }
//                     else if(this->Password->handleEvent(&event))
//                     {
//                         std::cout<<"clicked"<<std::endl;
//                         SDL_StartTextInput();
//                     }
//                     else if(this->Login->handleEvent(&event))
//                     {
//                         if(this->obj->search(u_Username))
//                         {
//                         string temp=this->obj->getInfo(u_Username)->password;
//                         if(temp==u_Password)
//                         {
//                             std::cout<<"Login success!"<<std::endl;
//                             currentWindow=mainWindow;
//                             running=false;
//                         }
//                         }
//                     }
//                     break;
//                 }

//                 case SDL_TEXTINPUT:
//                 {
//                 if(SDL_IsTextInputActive())
//                     {
//                         Username_input->handleEvent(&event);
//                        Password_input->handleEvent(&event);
//                     }
//                     break;
//                 }
//             }
//         }
//         SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer,background,NULL,NULL);
//         Return_button->draw(renderer);
//         Username->draw(renderer);
//         Password->draw(renderer);
//         Login->draw(renderer);
//         Username_input->render();
//         Password_input->render();
//         SDL_RenderPresent(renderer);
//     }
// }
void LoginWindow::Update()
{
    // Other code...

    bool textInputActive = false;  // Flag to track if any text input should be active

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {

                case SDL_MOUSEBUTTONDOWN:
                {
                    if (this->Return_button->handleEvent(&event))
                    {
                        std::cout << "Return button clicked" << std::endl;
                        currentWindow = mainWindow;
                        running = false;
                    }
                    else if (this->Username->handleEvent(&event))
                    {
                        std::cout << "Username button clicked" << std::endl;
                        textInputActive = true;
                        Username_input->setClicked(true);
                        Password_input->setClicked(false);
                    }
                    else if (this->Password->handleEvent(&event))
                    {
                        std::cout << "Password button clicked" << std::endl;
                        textInputActive = true;
                        Password_input->setClicked(true);
                        Username_input->setClicked(false);
                    }
                    else if (this->Login->handleEvent(&event))
                    {
                        // Handle login button click
                        if (this->obj->search(u_Username))
                        {
                            std::string temp = this->obj->getInfo(u_Username)->password;
                            if (temp == u_Password)
                            {
                                std::cout << "Login success!" << std::endl;
                                currentWindow = mainWindow;
                                running = false;
                            }
                        }
                    }
                    break;
                }

                case SDL_KEYDOWN:
                {
                    if (textInputActive)
                    {
                        if (Username_input->isClicked())
                        {
                            Username_input->handleEvent(&event);
                        }
                        else if (Password_input->isClicked())
                        {
                            Password_input->handleEvent(&event);
                        }
                    }
                    break;
                }

                case SDL_KEYUP:
                {
                    // Handle key release events if needed
                    break;
                }
            }
        }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    Return_button->draw(renderer);
    Username->draw(renderer);
    Password->draw(renderer);
    Login->draw(renderer);
    Username_input->render();
    Password_input->render();
    SDL_RenderPresent(renderer);
    }
}


void LoginWindow::Exit()
{
}


ProjectWindow::ProjectWindow()
{
    background=TextureManager::Texture("Image/ProjectTheme.png",renderer);
    return_main=new Button(70,50,133,43,"Image/Image_to_return_main.png",renderer);
    Trending_button=new Button(93,150,400,100,"Image/Trending.png",renderer);
    Nearly_button=new Button(93,250,400,100,"Image/Nearly.png",renderer);
    JustLaunch_button=new Button(93,350,400,100,"Image/Just launch.png",renderer);
    Everything_button=new Button(93,450,400,100,"Image/everything.png",renderer);
}

ProjectWindow::~ProjectWindow()
{
    SDL_DestroyTexture(background);
}

void ProjectWindow::Enter()
{
    running=true;
}


void ProjectWindow::Update()
{
    while(running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                {
                shutdown();

                }
                case SDL_MOUSEBUTTONDOWN:
                {         
                if(this->return_main->handleEvent(&event))
                    {
                        std::cout<<"clicked"<<std::endl;  
                        currentWindow=mainWindow; 
                        running=false;
                    }
                    break;
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,background,NULL,NULL);
        return_main->draw(renderer);
        Trending_button->draw(renderer);
        Nearly_button->draw(renderer);
        JustLaunch_button->draw(renderer);
        Everything_button->draw(renderer);
        SDL_RenderPresent(renderer);
    }
}


void ProjectWindow::Exit()
{

}




