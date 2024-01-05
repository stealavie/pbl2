#include"ProjectManagement.h"

ProjectManagement::ProjectManagement()
{
    head = nullptr;
    tail = nullptr;
    currentPage = nullptr;
}

ProjectManagement::~ProjectManagement() 
{
    Project* temp = head;
    Project* next;
    while (temp != nullptr) 
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
}



void ProjectManagement::loadProjects(std::string filename)
{
    std::ifstream file(filename);
    std::string name, description, imagePath;

    while (std::getline(file, name, ',') &&
        std::getline(file, description, ',') && std::getline(file, imagePath, '\n'))
    {
        addProject(name, description, imagePath);
        name.clear();
        description.clear();
        imagePath.clear();
    }

    file.close();
}

void ProjectManagement::addProject(std::string name, std::string description, std::string imagePath)
{
    Project* newProject = new Project(name, description, imagePath);
    if (head == nullptr)
    {
        head = newProject;
        tail = newProject;
        currentPage = newProject;
    }
    else
    {
        tail->next = newProject;
        tail = newProject;
    }
}


void ProjectManagement::updateFile(std::string filename) 
{
    std::ofstream file(filename);
    Project* temp = head;

    while (temp != nullptr) 
    {
        file << temp->name << "," << temp->description << "," << temp->imagePath << "," << "\n";
        temp = temp->next;
    }

    file.close();
}

void ProjectManagement::nextPage() 
{
    if (currentPage != nullptr && currentPage->next != nullptr && currentPage->next->next != nullptr) 
    {
        currentPage = currentPage->next->next->next;
    }
}

void ProjectManagement::previousPage()
{
    if (currentPage != head)
    {
        Project* temp = head;
        while (temp != nullptr && temp->next != currentPage && temp->next->next != currentPage && temp->next->next->next != currentPage) 
        {
            temp = temp->next;
        }
        currentPage = temp;
    }
}


Project* ProjectManagement::getProjectByNumber(int number)
{
    // Check if the current page is empty
    if (currentPage == nullptr) 
    {
        std::cout << "There are no projects on this page." << std::endl;
        return nullptr;
    }

    // Check if the project number is valid
    if (number < 1 || number > 6) 
    {
        std::cout << "Invalid project number. Please enter a number between 1 and 3." << std::endl;
        return nullptr;
    }

    // Find the project
    Project* temp = currentPage;
    for (int i = 1; i < number && temp != nullptr; i++) 
    {
        temp = temp->next;
    }

    return temp;
}



void ProjectManagement::displayProjectsGrid(SDL_Renderer* renderer, int x, int y, int width, int height) 
{
    // Get the current page projects
    Project* projects[6];
    for (int i = 0; i < 6; i++)
    {
        projects[i] = getProjectByNumber(i + 1);
    }

    // Calculate sub-rectangle dimensions
    const int gap = 20;
    int subRectWidth = (width - 2 * gap) / 3;
    int subRectHeight = (height - 2 * gap) / 2;

    // Create and render the main rectangle
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    int index = 0;

    // Create and render the sub-rectangles
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (index < 6 && projects[index] != nullptr)
            {
                SDL_Rect subRect;
                subRect.x = rect.x + j * (subRectWidth + gap);
                subRect.y = rect.y + i * (subRectHeight + gap);
                subRect.w = subRectWidth;
                subRect.h = subRectHeight;

                std::string temp = projects[index]->imagePath.c_str();
                // Render the image onto the sub-rectangle
                SDL_Texture* imageTexture = TextureManager::Texture(projects[index]->imagePath.c_str(), renderer);
                SDL_RenderCopy(renderer, imageTexture, NULL, &subRect);
                SDL_DestroyTexture(imageTexture);
            }

            index++;
        }
    }
}

void ProjectManagement::HandleEvent(SDL_Event* e)
{
    if(e->type == SDL_KEYDOWN)
    {
        switch (e->key.keysym.sym) 
        {
        case SDLK_RIGHT:
            nextPage();
            break;
        case SDLK_LEFT:
            previousPage();
            break;
        }
    }
}

Project* ProjectManagement::getProjectByImage(SDL_Renderer* renderer)
{
    isclicked = false;
    Project* projects[6];
    for (int i = 0; i < 6; i++)
    {
        projects[i] = getProjectByNumber(i + 1);
    }
    int mouseX, mouseY;
    Uint8 mouseButtons = SDL_GetMouseState(&mouseX, &mouseY);

    // Check for left button click within grid bounds
    if ((mouseButtons & SDL_BUTTON(SDL_BUTTON_LEFT)) &&
        mouseX >= 82 && mouseX <= 1082 &&
        mouseY >= 280 && mouseY <= 680)
    {
        // Calculate subrectangle dimensions
        const int gap = 20;
        int subRectWidth = (1000 - 2 * gap) / 3;
        int subRectHeight = (400 - 2 * gap) / 2;

        // Calculate clicked subrectangle index
        int clickedRow = (mouseY - 280) / (subRectHeight + gap);
        int clickedCol = (mouseX - 82) / (subRectWidth + gap);
        int clickedIndex = clickedRow * 3 + clickedCol;

        // Check if valid index and project exists
        if (clickedIndex >= 0 && clickedIndex < 6 && projects[clickedIndex] != nullptr) 
        {
            isclicked = true;
            return projects[clickedIndex];
        }
    }

    return nullptr;
}
