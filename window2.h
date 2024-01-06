#pragma once

#include"Button.h"
#include"TextBox.h"
#include"ComboBox.h"
#include"Text.h"
#include"IMG_Tex.h"
#include"User.h"
#include"ProjectManagement.h"
#include"Text_tex.h"


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
    virtual void Exit() = 0;
    bool running = false;
    void shutdown();
    Window();
    virtual ~Window();
    static Window* mainWindow;
    static Window* loginWindow;
    static Window* currentWindow;
    static Window* Discoverwindow;
    static Window* projectWindow;
    static Project* currentProject;
    static Window* userWindow;
    static Window* faqWindow;
    static Window* registerWindow;
    static Window* existedWindow;
    static Window* donecreateWindow;
};

class MainWindow : public Window
{
private:
    Button* Login_button, * Explore_button, * Faq_button, * Register_button;
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
    Button* Return_button, * Password, * Username, * Login;
    User* p = new User();
    TextBox* b_username, * b_password;
protected:
    std::string u_Username, u_Password;
public:
    void Enter();
    void Update();
    void Exit();

    LoginWindow();
    virtual ~LoginWindow();
};


class  DiscoverWindow : public Window
{
private:
    Button* return_main, * show_me, * on,
        * sorted, * next, * previous;
    ComboBox* show;
    ProjectManagement* obj;

    
public:
    void Enter();
    void Update();
    void Exit();

    DiscoverWindow();

    virtual ~DiscoverWindow();
};


class ProjectWindow : public Window
{
    Text* box_description;
    IMG_Tex* project_img;
    LTexture* description;
    Button* back;
public:
    void Enter();
    void Update();
    void Exit();

    ProjectWindow();

    virtual ~ProjectWindow();

};

class  UserWindow : public LoginWindow
{
private:
    Button* logout, * name, * age, * gender, * country, * save, * projects, * payment;
    std::string u_name, u_gender, u_country;
    TextBox* b_name, * b_age, * b_gender, * b_country;
    ComboBox* cb_gender, * cb_country;
public:
    SDL_Texture* background;
    void Enter();
    void Update();
    void Exit();

    UserWindow();

    virtual ~UserWindow();
};


class  FaqWindow : public Window
{
private:
    Button* returnmain;


public:
    void Enter();
    void Update();
    void Exit();

    FaqWindow();

    virtual ~FaqWindow();
};


class RegisterWindow : public Window
{
private:
    Button* Return_button, * Password, * Username, * Create;
    std::string u_Username, u_Password;
    User* p = new User();
    TextBox* b_username, * b_password;
public:
    void Enter();
    void Update();
    void Exit();

    RegisterWindow();
    virtual ~RegisterWindow();
};


class  ExistedWindow : public Window
{
private:
    Button* ok;


public:
    void Enter();
    void Update();
    void Exit();

    ExistedWindow();

    virtual ~ExistedWindow();
};


class  DoneCreateWindow : public Window
{
private:
    Button* ok;


public:
    void Enter();
    void Update();
    void Exit();

    DoneCreateWindow();

    virtual ~DoneCreateWindow();
};





