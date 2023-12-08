#include "SearchProject.h"
#include "Project.h"  

#include <iostream>
#include <fstream>
#include <sstream>

void SearchProject::SearchByName(const std::string& filename, const std::string& projectName) {
    std::ifstream csvFile(filename);

    if (!csvFile.is_open()) {
        std::cerr << "Cannot open file " << filename << " for reading." << std::endl;
        return;
    }

    Project* projects = nullptr; //mang dong(khoi tao)
    int numProjects = 0;

    std::string line;
    while (getline(csvFile, line)) {
        std::stringstream ss(line);
        std::string token;
        std::string* tokens = nullptr; 

        int tokenCount = 0;
        while (getline(ss, token, ',')) {
           
            std::string* temp = new std::string[tokenCount + 1];
            for (int i = 0; i < tokenCount; ++i) {
                temp[i] = tokens[i];
            }
            temp[tokenCount] = token;

            delete[] tokens; 
            tokens = temp;

            ++tokenCount;
        }

        if (tokenCount == 3) {
            Project project;
            project.name = tokens[0];
            project.goal = tokens[1];
            project.money = stod(tokens[2]);

            
            Project* tempProjects = new Project[numProjects + 1];
            for (int i = 0; i < numProjects; ++i) {
                tempProjects[i] = projects[i];
            }

            tempProjects[numProjects] = project;

            delete[] projects; 
            projects = tempProjects;

            ++numProjects;
        }

        
        delete[] tokens;
    }

    //tim kieam bang ten 
    bool found = false;

    for (int i = 0; i < numProjects; i++)

     {
        
        if (projects[i].name.find(projectName) != std::string::npos)//thay cu phap neu muon tim kiem chinh xac ten 

        {
            found = true;

            //std::cout << "Search result:\n" << projects[i].GetInfo() << std::endl;

            std::cout << "Search result:\n" << projects[i].ReadInfo() << std::endl;
            // Break; neu muon tim kiem doi tuong xuat hien dau tien
        }
    }

    if (!found) 
    {
        std::cout << "Data not found for '" << projectName << "'." << std::endl;//khong tim thay
    }

    // Release memory of the dynamic array projects
    delete[] projects;
}


int main() {
  

    //Thực hiện tìm kiếm và hiển thị thông tin dự án theo tên
    string projectNameToSearch;
    cout << "Enter the name of the project to search: ";
    getline(cin, projectNameToSearch);
    SearchProject::SearchByName("example.csv", projectNameToSearch);

    return 0;
}
