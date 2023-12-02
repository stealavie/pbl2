#pragma once

#include"Button.h"
#include"TextBox.h"

class Window 
{
public:
    static SDL_Renderer* renderer;
    static SDL_Window* window;
    static TTF_Font* font;
    static SDL_Color color;
    SDL_Texture* background;
    virtual void Enter() = 0;
    virtual void Update() = 0;
    bool running = false;
    void shutdown();
    Window();
    virtual ~Window();
    static Window* mainWindow;
    static Window* loginWindow;
    static Window* currentWindow;
    static Window* projectWindow;
};

class MainWindow : public Window
{
private:
    Button* Login_button, * Explore_button;
public:
    void Enter();
    void Update();
    MainWindow();
    virtual ~MainWindow();
};


class LoginWindow : public Window
{
private:
    Button* Return_button, * Password, * Username, * Login;
    std::string u_Username, u_Password;
    TextBox* b_username, * b_password;
public:
    void Enter();
    void Update();

    LoginWindow();
    virtual ~LoginWindow();
};


class  ProjectWindow : public Window
{
private:
    Button* return_main, * Trending_button, * Nearly_button,
        * JustLaunch_button, * Everything_button;
public:
    void Enter();
    void Update();

    ProjectWindow();

    virtual ~ProjectWindow();
};




