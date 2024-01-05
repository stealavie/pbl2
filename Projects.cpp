#include "Projects.h"

Project::Project(std::string name, std::string description, std::string imagePath)
{
    this->name = name;
    this->description = description;
    this->imagePath = imagePath;
    this->next = nullptr;
}
