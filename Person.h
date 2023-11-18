#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
class Person
{
    protected:
        string name,gender,nationality;//ten,gioi tinh,quoc tich;
        int age;
    public:
        Person();
        Person(string name,string gender,int age,string nationality);
        ~Person();
        void Input();
        
        string GetInfo() const;
        void Output(); 
};