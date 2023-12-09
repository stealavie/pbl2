#pragma once

#include"Button.h"
#include"TextBox.h"
#include"ComboBox.h"
// #include"Text.h"
// #include"IMG_Tex.h"
#include"User.h"

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
    // static Window* projectWindow;
    static Window* discoverWindow;
    static Window* userWindow;
    static Window* faqWindow;
    static Window* registerWindow;
    static Window* existedWindow;
    static Window* donecreateWindow;
};

class MainWindow : public Window
{
private:
    Button* Login_button, * Explore_button, *Faq_button, * Register_button;
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
    User* p = new User();
    TextBox* b_username, * b_password;
public:
    void Enter();
    void Update();

    LoginWindow();
    virtual ~LoginWindow();
};


// class  ProjectWindow : public Window
// {
// private:
//     Button* return_main, * Trending_button, * Nearly_button,
//         * JustLaunch_button, * Everything_button;
// public:
//     void Enter();
//     void Update();

//     ProjectWindow();

//     virtual ~ProjectWindow();
// };


class  DiscoverWindow : public Window
{
private:
    Button* return_main, * show_me, * on,
        * sorted;
    ComboBox* show, *on_where,*sorted_by;
    // Text* test;
public:
    void Enter();
    void Update();

    DiscoverWindow();

    virtual ~DiscoverWindow();
};


class  UserWindow : public Window
{
private:
    Button* logout, * name, * age, * gender, * country, * save, * projects, * payment;
    std::string u_name, u_age, u_gender, u_country;
    TextBox* b_name, * b_age, * b_gender, * b_country;
    ComboBox* cb_gender, *cb_country;
public:
    void Enter();
    void Update();

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

    DoneCreateWindow();

    virtual ~DoneCreateWindow();
};









