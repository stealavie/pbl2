#pragma once
#include"TextureManagement.h"
#include"Button.h"
#include<iostream>
#include"Text_input.h"
#include"Trie.h"
class Window
{
    public:
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    SDL_Texture* background;
    virtual void Enter()=0;
    virtual void Update()=0;
    virtual void Exit()=0;
    bool running=false;
    void shutdown();
    Window();
    virtual ~Window();
    static Window* mainWindow;
    static Window* loginWindow;
    static Window* currentWindow;
    static Window* projectWindow;
    static TTF_Font* font;
    static SDL_Color color;
};

class MainWindow : public Window
{
    private:
    Button* Login_button,*Explore_button;
    public:
    void Enter();
    void Update();
    void Exit();
    MainWindow();
    virtual ~MainWindow(); 
};


class LoginWindow : public Window
{
    private:
    Button* Return_button,*Password,*Username,*Login;
    TextInput* Username_input,*Password_input;
    std::string u_Username,u_Password;
    Trie* obj;
    public:
    void Enter();
    void Update();
    void Exit();
    LoginWindow();
    virtual ~LoginWindow(); 
};


class  ProjectWindow : public Window
{
    private:
    Button* return_main;
    public:
    void Enter();
    void Update();
    void Exit();
    ProjectWindow();
    
    virtual ~ProjectWindow();
};


