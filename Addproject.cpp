#include "AddProject.h"

AddProject::AddProject()

{}

AddProject::~AddProject() 

{}

void AddProject::Add() 
{

    project.Input();

}

void AddProject::WriteToCSV(const string& filename) const 
{
    ofstream csvFile(filename, ios::app);

    if (!csvFile.is_open()) 
    {

        cerr << "khong the mo file " << filename << " de ghi." << endl;

        return;

    }

    csvFile << project.GetInfo();

    csvFile.close();

    cout << "Du lieu da duoc nhap vao file: " << filename << endl;
}
int main()
{ 
    AddProject addProject;

    addProject.Add();

    addProject.WriteToCSV("example.csv");

    return 0;
}
