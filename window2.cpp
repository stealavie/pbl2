#include"window2.h"

SDL_Window* Window::window=SDL_CreateWindow("PBL2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,0);
SDL_Renderer* Window::renderer=SDL_CreateRenderer(window,-1,0);

Window* Window::mainWindow=new MainWindow;
Window* Window::loginWindow=new LoginWindow;
Window* Window::currentWindow= mainWindow; 
Window* Window::projectWindow=new ProjectWindow;
// TTF_Font* Window::font=TTF_OpenFont("font/SourceCodePro-Bold.ttf",16);
SDL_Color Window::color={255,0,0};

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
    Login_button=new Button(1100,50,100,50,"Image/Button2.png",renderer);
    Explore_button=new Button(0,320,300,292,"Image/Button3.png",renderer);
    
}

MainWindow::~MainWindow()
{
    SDL_DestroyTexture(background);

}

LoginWindow::LoginWindow()
{
    obj=new Trie();
    background=TextureManager::Texture("Image/LoginWindow.png",renderer);
    Return_button=new Button(380,50,520,100,"Image/Image_to_return_main.png",renderer);
    Username=new Button(200,580,200,50,"Image/Username.png",renderer);
    Password=new Button(200,630,200,50,"Image/Password.png",renderer);
    Login=new Button(220,690,100,50,"Image/Login_button.png",renderer);
    // Username_input=new TextInput(renderer,"font/SourceCodePro-Bold.ttf",16,color,410,580);
    // Password_input=new TextInput(renderer,"font/SourceCodePro-Bold.ttf",16,color,410,580);
}

LoginWindow::~LoginWindow()
{
    SDL_DestroyTexture(background);

}

void LoginWindow::Enter()
{
    running=true;
    Username_input=new TextInput(renderer,"font/SourceCodePro-Bold.ttf",16,color,410,580);
    Password_input=new TextInput(renderer,"font/SourceCodePro-Bold.ttf",16,color,410,580);
}

void LoginWindow::Update()
{
    this->obj->Load_data();
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
                
                if(this->Return_button->handleEvent(&event)) 
                    {
                        std::cout<<"clicked"<<std::endl;
                        currentWindow=mainWindow; 
                        running=false;
                    }
                else if(this->Username->handleEvent(&event))
                    {
                        std::cout<<"clicked"<<std::endl;
                        Username_input->setFlag(true);
                        Password_input->setFlag(false);
                    }
                    else if(this->Password->handleEvent(&event))
                    {
                        std::cout<<"clicked"<<std::endl;
                        Password_input->setFlag(true);
                        Username_input->setFlag(false);
                    }
                    else if(this->Login->handleEvent(&event))
                    {
                        if(this->obj->search(u_Username))
                        {
                        string temp=this->obj->getInfo(u_Username)->password;
                        if(temp==u_Password)
                        {
                            std::cout<<"Login success!"<<std::endl;
                            currentWindow=mainWindow;
                            running=false;
                        }
                        }
                    }
                    break;
                }

                case SDL_TEXTINPUT:
                {
                if(this->Username_input->getFlag())
                    {
                        std::cout<<"Nhap Username:";
                        Username_input->handleEvent(&event,window);
                        this->u_Username=Username_input->Get_input();
                    }
                else if(this->Password_input->getFlag())
                    {
                        std::cout<<"Nhap Password:";
                        Password_input->handleEvent(&event,window);
                        this->u_Password=Password_input->Get_input();
                    }
                    break;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,background,NULL,NULL);
        Return_button->draw(renderer);
        Username->draw(renderer);
        Password->draw(renderer);
        Login->draw(renderer);
        SDL_RenderPresent(renderer);
    }
}


void LoginWindow::Exit()
{
}


ProjectWindow::ProjectWindow()
{
    background=TextureManager::Texture("Image/ProjectTheme.png",renderer);
    return_main=new Button(380,50,520,100,"Image/Image_to_return_main.png",renderer);
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
        SDL_RenderPresent(renderer);
    }
}


void ProjectWindow::Exit()
{

}





