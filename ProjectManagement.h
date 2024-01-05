#pragma once
#include"Projects.h"
#include<SDL_ttf.h>

class ProjectManagement {
private:
    Project* head;
    Project* tail;
    Project* currentPage;
    
public:
    bool isclicked = false;

    ProjectManagement();

    ~ProjectManagement();

    void loadProjects(std::string filename);

    void addProject(std::string name, std::string description, std::string imagePath);

    void nextPage();

    void previousPage();

    void updateFile(std::string filename);

    Project* getProjectByNumber(int number);

    void displayProjectsGrid(SDL_Renderer* renderer, int x, int y, int width, int height);

    void HandleEvent(SDL_Event* e);

    Project* getProjectByImage(SDL_Renderer* renderer);
};

