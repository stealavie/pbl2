#pragma once
#include"Projects.h"


class ProjectManagement {
private:
    Project* head;
    Project* tail;
    Project* currentPage;
    
public:
    bool isclicked = false;

    void insertProject(std::string name, std::string description, std::string imagePath, std::string pledged, int position = -1);


    ProjectManagement();

    ~ProjectManagement();

    void addProject(std::string name, std::string description, std::string imagePath, std::string pledged);

    void loadProjects(std::string filename);

    void nextPage();

    void previousPage();

    void removeProject(std::string name);



    void updateFile(std::string filename);

    Project* getMiddle(Project* head);

    Project* mergeLists(Project* a, Project* b);

    void mergeSort(Project** headRef);

    Project* getProjectByNumber(int number);

    void displayProjectsGrid(SDL_Renderer* renderer, int x, int y, int width, int height);

    void HandleEvent(SDL_Event* e);

    Project* getProjectByImage(SDL_Renderer* renderer);
};

