#include"Person.h"
#include<iostream>
using namespace std;
Person::Person()
{
       this-> name = "";
       this-> gender = "";
       this-> nationality = ""; 
       this-> age = 0;
}
Person::Person(string name,string gender,int age,string nationality)
    {
       this-> name = name;
       this-> gender = gender;
       this-> nationality = nationality; 
       this-> age = age;
    }
Person::~Person()
{}
/*void Person::Input()
{  
    cout << "Name:";
    getline(cin,this->name);
    cout << "Gender:";
    getline(cin,this->gender);
    cout << "Age:";
    cin >> this->age; 
    cin.ignore();
    cout << "Nationality:";
    getline(cin,this->nationality);  
    cin.ignore(); 
}*/
void Person::Input()
{  
    cout << "Name:";
    cin >> this->name;
    cout << "Gender:";
    cin >> this->gender;
    cout << "Age:";
    cin >> this->age; 
    cout << "Nationality:";
    cin >> this->nationality;  
} 


string Person::GetInfo() const 
{
    stringstream ss;
    ss << "Name: " << this->name << ", Gender: " << this->gender << ", Age: " << to_string(this->age) << ", Nationality: " << this->nationality;
    return ss.str();
}

void Person::Output()
{
    cout<< "Name:" << name << endl;
    cout<< "Gender:" << gender << endl;
    cout<< "Age:" << age << endl;
    cout<< "Nationality:" << nationality;
}

