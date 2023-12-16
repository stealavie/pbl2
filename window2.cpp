#include"Window.h"


SDL_Window* Window::window = SDL_CreateWindow("PBL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
SDL_Renderer* Window::renderer = SDL_CreateRenderer(window, -1, 0);
TTF_Font* Window::font = TTF_OpenFont("D:/SourceCodePro-Bold.ttf", 24);
SDL_Color Window::color{ 0,0,0,0 };

Window* Window::mainWindow = new MainWindow;
Window* Window::loginWindow = new LoginWindow;
Window* Window::Discoverwindow = new DiscoverWindow;
Window* Window::projectWindow = new ProjectWindow;
Window* Window::userWindow = new UserWindow;

Window* Window::faqWindow = new FaqWindow;
Window* Window::registerWindow = new RegisterWindow;
Window* Window::existedWindow = new ExistedWindow;
Window* Window::donecreateWindow = new DoneCreateWindow;
Window* Window::currentWindow = mainWindow;

Project* Window::currentProject = NULL;



Window::Window()
{
}

Window::~Window()
{
}

MainWindow::MainWindow()
{
	
}

void MainWindow::Enter()
{
	running = true;
	background = TextureManager::Texture("Image/MainTheme.png", renderer);
	Login_button = new Button(1100, 70, 100, 30, renderer, "Login");
	Explore_button = new Button(20, 70, 100, 30, renderer, "Explore");
	Register_button = new Button(1100, 170, 100, 30, renderer, "Register");
	Faq_button = new Button(1100, 680, 100, 30, renderer, "FAQs");
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
			Faq_button->HandleEvent(&event);
			Register_button->HandleEvent(&event);
		}
		if (Login_button->click)
		{
			currentWindow = loginWindow;
			running = false;
			continue;
		}
		else if (Explore_button->click)
		{
			currentWindow = Discoverwindow;
			running = false;
			continue;
		}
		else if (Faq_button->click)
		{
			currentWindow = faqWindow;
			running = false;
			continue;
		}
		else if (Register_button->click)
		{
			currentWindow = registerWindow;
			running = false;
			continue;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		Login_button->draw();
		Explore_button->draw();
		Faq_button->draw();
		Register_button->draw();
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
	std::cout << "out" << std::endl;
}

void MainWindow::Exit()
{
	MainWindow::~MainWindow();
}


LoginWindow::LoginWindow()
{
	

}

LoginWindow::~LoginWindow()
{
	SDL_DestroyTexture(background);
	std::cout << "out" << std::endl;
}

void LoginWindow::Exit()
{
	LoginWindow::~LoginWindow();
}

void LoginWindow::Enter()
{
	running = true;
	background = TextureManager::Texture("Image/LoginWindow.png", renderer);
	Return_button = new Button(40, 70, 100, 30, renderer, "Home");
	Username = new Button(372, 382, 100, 30, renderer, "Username");
	Password = new Button(372, 422, 100, 30, renderer, "Password");
	Login = new Button(500, 460, 100, 30, renderer, "LOGIN");
	b_password = new TextBox(renderer);
	b_username = new TextBox(renderer);
	User* p = new User;
	this->b_username->setPosition(490, 382);
	this->b_password->setPosition(490, 422);
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
		if (Login->click)
		{

			std::string m_username = b_username->getText();
			std::string m_password = b_password->getText();


			std::cout << m_username << ", " << m_password << std::endl;


			//Thực hiện kiểm tra xem User có tồn tại trong Trie không và kiểm tra password
			p->Load_data();
			bool user_a_exists = p->search(m_username);


			if (user_a_exists) {
				// Lấy thông tin của User a
				info* user_info = p->getInfo(m_username);

				// Kiểm tra password
				if (user_info && user_info->password == m_password) {
					std::cout << "login success" << std::endl;
					currentWindow = userWindow;
					running = false;
					continue;

				}
				else {
					std::cout << "incorrect password" << std::endl;

				}
			}
			else {
				std::cout << "invalid username or password" << std::endl;
				//continue;
				break;
			}

			// currentWindow = userWindow;
			// running = false;
			// continue;
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


UserWindow::UserWindow()
{}

UserWindow::~UserWindow()
{
	SDL_DestroyTexture(background);
	cb_country->~ComboBox();
	cb_gender->~ComboBox();
	std::cout << "out" << std::endl;
}

void UserWindow::Exit()
{
	UserWindow::~UserWindow();
}

void UserWindow::Enter()
{
	running = true;
	TTF_Font* Font = TTF_OpenFont("D:/SourceCodePro-Bold.ttf", 24);

	background = TextureManager::Texture("Image/UserTheme.png", renderer);

	logout = new Button(40, 70, 100, 30, renderer, "Logout");
	name = new Button(55, 330, 100, 30, renderer, "Name");
	age = new Button(55, 440, 100, 30, renderer, "Age");
	gender = new Button(350, 330, 100, 30, renderer, "Gender");
	country = new Button(350, 440, 100, 30, renderer, "Country");
	save = new Button(220, 580, 310, 30, renderer, "> Update Information <");

	b_name = new TextBox(renderer);
	b_age = new TextBox(renderer);

	cb_gender = new ComboBox(475, 330, 250, 100, Font, renderer);
	cb_country = new ComboBox(475, 440, 250, 100, Font, renderer);
	this->b_name->setPosition(130, 330);
	this->b_age->setPosition(130, 440);
}

void UserWindow::Update()
{
	SDL_StartTextInput();

	cb_gender->addItem("Male");
	cb_gender->addItem("Female");
	cb_gender->addItem("Prefer not to say");
	cb_country->addItem("Vietnam");
	cb_country->addItem("United States");
	cb_country->addItem("United Kingdoms");

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
			logout->HandleEvent(&event);
			save->HandleEvent(&event);

			b_name->handleEvent(&event);
			b_age->handleEvent(&event);

			cb_gender->handleEvent(&event);
			cb_country->handleEvent(&event);
		}
		if (logout->click)
		{
			currentWindow = loginWindow;
			running = false;
			continue;
		}
		if (save->click)
		{
			// currentWindow = loginWindow;
			// running = false;
			continue;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		logout->draw();
		name->draw();
		age->draw();
		gender->draw();
		country->draw();
		save->draw();
		b_name->render();
		b_age->render();
		cb_gender->draw(0, 255, 255);
		cb_country->draw(0, 255, 255);
		SDL_RenderPresent(renderer);
	}
	SDL_StopTextInput();
}




DiscoverWindow::DiscoverWindow()
{}

DiscoverWindow::~DiscoverWindow()
{}

void DiscoverWindow::Exit()
{
	SDL_DestroyTexture(background);
	delete show;
	delete on_where;
	delete sorted_by;
	//delete obj;
	std::cout << "out" << std::endl;
}

void DiscoverWindow::Enter()
{
	running = true;
	TTF_Font* Font = TTF_OpenFont("D:/SourceCodePro-Bold.ttf", 24);

	background = TextureManager::Texture("Image/ProjectTheme.png", renderer);
	return_main = new Button(1162, 40, 100, 30, renderer, "home");
	show_me = new Button(80, 85, 130, 100, renderer, "SHOW ME");
	on = new Button(370, 85, 130, 100, renderer, "PROJECT ON");
	sorted = new Button(695, 85, 130, 100, renderer, "SORTED BY");
	next = new Button(1000, 180, 100, 50, renderer, "NEXT");
	previous = new Button(82, 180, 100, 50, renderer, "PREVIOUS");
	show = new ComboBox(200, 85, 150, 100, Font, renderer);
	on_where = new ComboBox(530, 85, 150, 100, Font, renderer);
	sorted_by = new ComboBox(840, 85, 150, 100, Font, renderer);
	obj = new ProjectManagement;
}

void DiscoverWindow::Update()
{
	obj->loadProjects("films_test.csv");
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
			case SDL_MOUSEBUTTONDOWN:
			{
				currentProject = obj->getProjectByImage(renderer);
				break;
			}
			}
			return_main->HandleEvent(&event);
			show->handleEvent(&event);
			on_where->handleEvent(&event);
			sorted_by->handleEvent(&event);
			obj->HandleEvent(&event);
		
		}
		if (return_main->click)
		{
			currentWindow = mainWindow;
			running = false;
			continue;
		}
		if (obj->isclicked)
		{
			std::cout << currentProject->name << std::endl;
			std::cout << currentProject->description << std::endl;
			std::cout << currentProject->imagePath << std::endl;
			std::cout << currentProject->pledged << std::endl;

			currentWindow = projectWindow;
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
		next->draw();
		previous->draw();
		show->draw(0,255,255);
		on_where->draw(0, 255, 255);
		sorted_by->draw(0, 255, 255);
		
		obj->displayProjectsGrid(renderer, 82, 280, 1000, 400);
		SDL_RenderPresent(renderer);
		
	}
}


ProjectWindow::ProjectWindow()
{}

ProjectWindow::~ProjectWindow()
{}

void ProjectWindow::Enter()
{
	running = true;
	background = TextureManager::Texture("Image/projecttheme2resize.png", renderer);
	back = new Button(10, 10, 100, 50, renderer, "BACK");
	TTF_Font* Font = TTF_OpenFont("D:/SourceCodePro-Bold.ttf", 24);
	if (currentProject != NULL) {
		project_img = new IMG_Tex(renderer, currentProject->imagePath.c_str(), 170, 192, 600, 300);
		box_description = new Text(renderer, Font, (currentProject->description), 830, 192, 400, 300, 380, 380, 20);

		description = new LTexture;
		description->loadFromRenderedText(currentProject->name, renderer);
	}
}

void ProjectWindow::Update()
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
			box_description->HandleEvent(&event);
			back->HandleEvent(&event);
		}
		if (back->click)
		{
			currentWindow = Discoverwindow;
			currentProject = NULL;
			running = false;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		project_img->draw(renderer);
		box_description->draw();
		description->render(300, 100, renderer);
		back->draw();
		SDL_RenderPresent(renderer);
	}
}

void ProjectWindow::Exit()
{
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(project_img->getTex());
	std::cout << "out" << std::endl;
}

FaqWindow::FaqWindow()
{}

FaqWindow::~FaqWindow()
{
	SDL_DestroyTexture(background);
	returnmain->~Button();
	std::cout << "out" << std::endl;
}

void FaqWindow::Exit()
{
	FaqWindow::~FaqWindow();
}

void FaqWindow::Enter()
{
	running = true;
	TTF_Font* Font = TTF_OpenFont("D:/SourceCodePro-Bold.ttf", 24);

	background = TextureManager::Texture("Image/faq_theme.png", renderer);
	returnmain = new Button(55, 40, 100, 30, renderer, "home");
}

void FaqWindow::Update()
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
			returnmain->HandleEvent(&event);
		}
		if (returnmain->click)
		{
			currentWindow = mainWindow;
			running = false;
			continue;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		returnmain->draw();
		SDL_RenderPresent(renderer);
	}
}


RegisterWindow::RegisterWindow()
{}

RegisterWindow::~RegisterWindow()
{
	SDL_DestroyTexture(background);
	Return_button->~Button();
	Username->~Button();
	Password->~Button();
	Create->~Button();
	b_password->~TextBox();
	b_username->~TextBox();
	std::cout << "out" << std::endl;

}

void RegisterWindow::Exit()
{
	RegisterWindow::~RegisterWindow();
}

void RegisterWindow::Enter()
{
	running = true;
	background = TextureManager::Texture("Image/register_theme.png", renderer);
	Return_button = new Button(40, 70, 100, 30, renderer, "Home");
	Username = new Button(372, 382, 100, 30, renderer, "Username");
	Password = new Button(372, 422, 100, 30, renderer, "Password");
	Create = new Button(500, 460, 100, 30, renderer, "CREATE");
	b_password = new TextBox(renderer);
	b_username = new TextBox(renderer);
	User* p = new User;
	this->b_username->setPosition(490, 382);
	this->b_password->setPosition(490, 422);
}

void RegisterWindow::Update()
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
			Create->HandleEvent(&event);
			b_password->handleEvent(&event);
			b_username->handleEvent(&event);
		}
		if (Return_button->click)
		{
			currentWindow = mainWindow;
			running = false;
			continue;
		}
		if (Create->click)
		{

			std::string m_username = b_username->getText();
			std::string m_password = b_password->getText();


			std::cout << m_username << ", " << m_password << std::endl;


			//Thực hiện kiểm tra xem User có tồn tại trong Trie không và kiểm tra password
			p->Load_data();
			bool user_a_exists = p->search(m_username);


			if (user_a_exists) {
				currentWindow = existedWindow;
				running = false;
				continue;
			}
			else {
				info* info_p = new info;
				info_p->password = m_password;
				p->Insert(m_username, m_password);
				p->Load_data();
				p->update_data();

				currentWindow = donecreateWindow;
				running = false;
				continue;
			}

		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		Return_button->draw();
		Username->draw();
		Password->draw();
		Create->draw();
		b_username->render();
		b_password->render();
		SDL_RenderPresent(renderer);
	}
	SDL_StopTextInput();
}


ExistedWindow::ExistedWindow()
{}

ExistedWindow::~ExistedWindow()
{
	SDL_DestroyTexture(background);
	ok->~Button();
	std::cout << "out" << std::endl;
}

void ExistedWindow::Exit()
{
	ExistedWindow::~ExistedWindow();
}

void ExistedWindow::Enter()
{
	running = true;
	background = TextureManager::Texture("Image/register_existed.png", renderer);
	ok = new Button(55, 40, 100, 30, renderer, "home");
}

void ExistedWindow::Update()
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
			ok->HandleEvent(&event);
		}
		if (ok->click)
		{
			currentWindow = mainWindow;
			running = false;
			continue;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		ok->draw();
		SDL_RenderPresent(renderer);
	}
}


DoneCreateWindow::DoneCreateWindow()
{}

DoneCreateWindow::~DoneCreateWindow()
{
	SDL_DestroyTexture(background);
	ok->~Button();
	std::cout << "out" << std::endl;
}

void DoneCreateWindow::Exit()
{
	DoneCreateWindow::~DoneCreateWindow();
}

void DoneCreateWindow::Enter()
{
	running = true;
	background = TextureManager::Texture("Image/register_done.png", renderer);
	ok = new Button(55, 40, 100, 30, renderer, "home");
}

void DoneCreateWindow::Update()
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
			ok->HandleEvent(&event);
		}
		if (ok->click)
		{
			currentWindow = mainWindow;
			running = false;
			continue;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		ok->draw();
		SDL_RenderPresent(renderer);
	}
}
