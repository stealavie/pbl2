#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
class Project 
{
    public:
    string name;//ten du an
    string goal;//muc tieu
    double money;

    public:
    Project();
    ~Project();
    //float getMoney() const { return money; }
    //string getName() const { return name;}
    
    string GetInfo() const;
    string ReadInfo() const;
    //void Field();
    void Input();
    void Output();
};
