#include "Projects.h"

Project::Project(std::string name, std::string description, std::string imagePath, std::string pledged)
{
    this->name = name;
    this->description = description;
    this->imagePath = imagePath;
    this->pledged = pledged;
    this->next = nullptr;
}

/*Project* Project::operator = (Project* p)
{
    this->name = p->name;
    this->description = p->description;
    this->imagePath = p->imagePath;
    this->pledged = p->pledged;
    this->next = p->next;
    return (this);
}*/