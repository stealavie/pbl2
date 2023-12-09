#pragma once
#include"IMG_Tex.h"
#include<iostream>
#include<string>
#include<fstream>
class Project {
public:
    std::string name;
    std::string description;
    std::string imagePath;
    std::string pledged;
    
    Project* next;

    Project(std::string name="", std::string description = "", std::string imagePath = "", std::string pledged = "");

    //Project* operator = (Project* p);

};
