#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
class Project 
{
    protected:
    string name;//ten du an
    string goal;//muc tieu
    float money;

    public:
    Project();
    ~Project();
    float getMoney() const { return money; }
    string getName() const { return name;}
    
    string GetInfo() const;
    void Field();
    void Input();
    void Output();
};
