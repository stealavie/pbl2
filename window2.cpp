#include"Window.h"


SDL_Window* Window::window = SDL_CreateWindow("PBL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
SDL_Renderer* Window::renderer = SDL_CreateRenderer(window, -1, 0);
TTF_Font* Window::font = TTF_OpenFont("D:/SourceCodePro-Bold.ttf", 24);
SDL_Color Window::color{ 0,0,0,0 };

Window* Window::mainWindow = new MainWindow;
Window* Window::loginWindow = new LoginWindow;
Window* Window::currentWindow = mainWindow;
Window* Window::projectWindow = new ProjectWindow;

Window::Window()
{
}

Window::~Window()
{
}

MainWindow::MainWindow()
{
	background = TextureManager::Texture("D:/Image/Image/MainTheme.png", renderer);
	Login_button = new Button(1100, 70, 100, 30, renderer, "Login");
	Explore_button = new Button(20, 70, 100, 30, renderer, "Explore");
}

void MainWindow::Enter()
{
	running = true;
}

void MainWindow::Update()
{
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
			{
				shutdown();
				break;
			}
			}
			Login_button->HandleEvent(&event);
			Explore_button->HandleEvent(&event);
		}
		if (Login_button->click)
		{
			currentWindow = loginWindow;
			running = false;
			continue;
		}
		else if (Explore_button->click)
		{
			currentWindow = projectWindow;
			running = false;
			continue;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		Login_button->draw();
		Explore_button->draw();
		
		SDL_RenderPresent(renderer);
	}
}

void Window::shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

MainWindow::~MainWindow()
{
	SDL_DestroyTexture(background);

}

LoginWindow::LoginWindow()
{
	background = TextureManager::Texture("D:/Image/Image/LoginWindow.png", renderer);
	Return_button = new Button(40, 70, 100, 30, renderer, "Home");
	Username = new Button(372, 382, 100, 30, renderer, "Username");
	Password = new Button(372, 422, 100, 30, renderer, "Password");
	Login = new Button(500, 460, 100, 30, renderer, "LOGIN");
	b_password = new TextBox(renderer);
	b_username = new TextBox(renderer);
}

LoginWindow::~LoginWindow()
{
	SDL_DestroyTexture(background);

}

void LoginWindow::Enter()
{
	running = true;
	this->b_password->setPosition(490, 382);
	this->b_username->setPosition(490, 422);
}

void LoginWindow::Update()
{
	SDL_StartTextInput();
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
			{
				shutdown();
				break;
			}
			}
			Return_button->HandleEvent(&event);
			Login->HandleEvent(&event);
			b_password->handleEvent(&event);
			b_username->handleEvent(&event);
		}
		if (Return_button->click)
		{
			currentWindow = mainWindow;
			running = false;
			continue;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		Return_button->draw();
		Username->draw();
		Password->draw();
		Login->draw();
		b_username->render();
		b_password->render();
		SDL_RenderPresent(renderer);
	}
	SDL_StopTextInput();
}



ProjectWindow::ProjectWindow()
{
	
	TTF_Font* Font = TTF_OpenFont("D:/SourceCodePro-Bold.ttf", 24);
	
	background = TextureManager::Texture("D:/Image/Image/ProjectTheme.png", renderer);
	return_main = new Button(1162, 40, 100, 30,  renderer, "home");
	show_me= new Button(80, 85, 130, 100, renderer, "SHOW ME");
	on= new Button(370, 85, 130, 100, renderer, "PROJECT ON");
	sorted= new Button(695, 85, 130, 100, renderer, "SORTED BY");
	show = new ComboBox(200,85,150,100,Font,renderer);
	on_where= new ComboBox(530, 85, 150, 100, Font, renderer);
	sorted_by= new ComboBox(840, 85, 150, 100, Font, renderer);
}

ProjectWindow::~ProjectWindow()
{
	SDL_DestroyTexture(background);
}

void ProjectWindow::Enter()
{
	running = true;
}

void ProjectWindow::Update()
{
	show->addItem("TRENDING");
	show->addItem("ART");
	show->addItem("FILM");
	show->addItem("JUST OUT");
	on_where->addItem("earth");
	on_where->addItem("siuuu");
	on_where->addItem("siuuu");
	on_where->addItem("yay");
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
			{
				shutdown();
				break;
			}
			}
			return_main->HandleEvent(&event);
			show->handleEvent(&event);
			on_where->handleEvent(&event);
			sorted_by->handleEvent(&event);
		}
		if (return_main->click)
		{
			currentWindow = mainWindow;
			running = false;
			continue;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		return_main->draw();
		show_me->draw();
		on->draw();
		sorted->draw();
		show->draw(0,255,255);
		on_where->draw(0, 255, 255);
		sorted_by->draw(0, 255, 255);
		SDL_RenderPresent(renderer);
	}
}
